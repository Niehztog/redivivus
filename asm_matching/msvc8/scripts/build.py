#!/usr/bin/env python3
"""build.py - compile the reconstruction with Visual C++ 2005, one object per TU.

    build.py [-j N] [--force] [--with-data] [PATTERN ...]

Mirrors the tree through vc8_translate.py into build/src, then compiles every
translation unit (or those whose path contains one of the PATTERNs) to
build/obj/<path>.obj under wine, N at a time. Incremental: a TU is recompiled
only when its source, a header it included last time (recorded from
/showIncludes in <path>.d), the flags, or the compat layer changed.

Per TU it leaves <path>.log (the compiler's own output) and appends a row to
build/compile_status.tsv: path, status (ok / FAIL), error count, first error.

globals/*.cpp define data only - no function - and are the largest units in
the tree, so they are skipped unless --with-data asks for them (a whole-image
link would need them; the per-function comparison does not).
Exit status is 0 when every requested TU compiled.

Flags come from ORACLE_CFLAGS (env.sh default). Anything but the default marks
the build as an experiment, and status rows say so.

The shared prefix every TU parses - vc8_compat.h, d2_platform.h and
globals/globals.h - is compiled once into a precompiled header (build/pch/),
cutting each TU's compile time about threefold. A precompiled header is parse
state, not code: objdiff.py over 19 objects from nine modules found all 741
functions identical with and without it. ORACLE_PCH=0 turns it off.
"""
import argparse
import glob
import concurrent.futures as cf
import os
import re
import subprocess
import sys
import threading
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import coffobj        # noqa: E402
import vc8_translate  # noqa: E402

from oracle_config import ORACLE, REPO, BUILD, CFLAGS, DEFAULT_CFLAGS, EXPERIMENT, VC, TOOL_CFLAGS  # noqa: E402
SRC = os.path.join(BUILD, 'src')
OBJ = os.path.join(BUILD, 'obj')
USE_PCH = os.environ.get('ORACLE_PCH', '1') == '1'
PCHDIR = os.path.join(BUILD, 'pch')
PCH_HEADER = 'oracle_pch.h'
PCH_FILE = os.path.join(PCHDIR, 'oracle.pch')
DRIVE = os.environ.get('ORACLE_DRIVE', 'r').upper() + ':'
COMPAT = [os.path.join(ORACLE, 'vc8_compat.h')] + \
    [os.path.join(ORACLE, 'shim_include', f) for f in os.listdir(os.path.join(ORACLE, 'shim_include'))]
INCLUDING = re.compile(r'^Note: including file:\s*(.*?)\s*$')
ERROR = re.compile(r'\b(error|fatal error) C\d{4}\b')
FLAGS_TSV = os.path.join(ORACLE, 'flags.tsv')
ERROR_AT = re.compile(r'^(?P<file>.+?)\((?P<line>\d+)\) : (?:fatal )?error (?P<code>C\d{4}): (?P<msg>.*)$')
QUARANTINE_TSV = os.path.join(BUILD, 'quarantine.tsv')
MAX_QUARANTINE_ROUNDS = 40   # an ICE is fatal, so each round finds one; every round adds one
COMPILE_TIMEOUT = 300       # seconds; the largest TU takes well under a minute
_qlock = threading.Lock()


def win(path):
    rel = os.path.relpath(os.path.realpath(path), os.path.realpath(REPO))
    if rel.startswith('..'):
        raise ValueError('%s is outside the repository' % path)
    return DRIVE + '\\' + rel.replace('/', '\\')


def linux(winpath):
    """A path from /showIncludes back to the host: only repo paths matter for
    dependencies; toolchain headers never change between builds."""
    p = winpath.replace('\\', '/')
    if p[:2].upper() == DRIVE:
        return os.path.normpath(os.path.join(REPO, p[3:]))
    return None


def load_flags_table():
    rows = []
    if os.path.exists(FLAGS_TSV):
        for line in open(FLAGS_TSV):
            if line.startswith('#') or not line.strip():
                continue
            parts = line.rstrip('\n').split('\t')
            rows.append((parts[0], parts[1] if len(parts) > 1 else ''))
    return sorted(rows, key=lambda r: -len(r[0]))


FLAGS_TABLE = load_flags_table()


def extra_flags(tu):
    """The flags.tsv row with the longest prefix of `tu`, or ''."""
    for prefix, flags in FLAGS_TABLE:
        if tu.startswith(prefix):
            return flags
    return ''


def write_if_changed(path, text):
    old = open(path).read() if os.path.exists(path) else None
    if old != text:
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, 'w') as f:
            f.write(text)


def write_rsp():
    dirs = set()
    for dirpath, _dirs, files in os.walk(SRC):
        if any(f.endswith('.h') for f in files):
            dirs.add(dirpath)
    lines = ['/nologo /c ' + CFLAGS + ' ' + TOOL_CFLAGS,
             '/FI' + win(os.path.join(ORACLE, 'vc8_compat.h'))]
    if USE_PCH:
        write_if_changed(os.path.join(PCHDIR, PCH_HEADER),
                         '// The prefix every TU parses, precompiled once (build.py, ORACLE_PCH=1).\n'
                         '#include "d2_platform.h"\n#include "globals/globals.h"\n')
        write_if_changed(os.path.join(PCHDIR, 'oracle_pch.cpp'), '// precompiled-header creation unit\n')
        lines += ['/FI' + PCH_HEADER, '/I' + win(PCHDIR), '/Fp' + win(PCH_FILE)]
    else:
        lines += ['/FI' + win(os.path.join(SRC, 'd2_platform.h'))]
    lines += ['/I' + win(os.path.join(ORACLE, 'shim_include')),
              '/I' + win(SRC)]
    lines += ['/I' + win(d) for d in sorted(dirs) if d != SRC]
    rsp = os.path.join(BUILD, 'cl.rsp')
    write_if_changed(rsp, '\n'.join(lines) + '\n')
    return rsp


def build_pch(rsp):
    """(Re)create the precompiled header when it is older than anything it
    was made from. Returns an error string, or None."""
    dep = os.path.join(PCHDIR, 'oracle.d')
    if os.path.exists(PCH_FILE) and os.path.exists(dep):
        t = os.path.getmtime(PCH_FILE)
        deps = [rsp] + COMPAT + [l.rstrip('\n') for l in open(dep)]
        if all(os.path.exists(d) and os.path.getmtime(d) <= t for d in deps):
            return None
    for f in (PCH_FILE, dep):
        if os.path.exists(f):
            os.remove(f)
    cmd = [os.path.join(HERE, 'vc8.sh'), 'cl', '@' + win(rsp), '/showIncludes', '/Yc' + PCH_HEADER,
           '/Fo' + win(os.path.join(PCHDIR, 'oracle_pch.obj')), win(os.path.join(PCHDIR, 'oracle_pch.cpp'))]
    p = subprocess.run(cmd, capture_output=True, text=True, encoding='latin1')
    deps = [linux(m.group(1)) for m in map(INCLUDING.match, (p.stdout + p.stderr).splitlines()) if m]
    errors = [l for l in (p.stdout + p.stderr).splitlines() if ERROR.search(l)]
    if errors or not os.path.exists(PCH_FILE):
        return errors[0] if errors else 'no precompiled header produced'
    with open(dep, 'w') as f:
        f.write('\n'.join(sorted(set(d for d in deps if d))) + '\n')
    return None


def stale(tu, rsp):
    obj = os.path.join(OBJ, tu[:-4] + '.obj')
    dep = os.path.join(OBJ, tu[:-4] + '.d')
    if not os.path.exists(obj) or not os.path.exists(dep):
        return True
    fl = os.path.join(OBJ, tu[:-4] + '.flags')
    if (open(fl).read() if os.path.exists(fl) else '') != extra_flags(tu):
        return True
    t = os.path.getmtime(obj)
    # The tree's own file too, not only its translation: with a function
    # quarantined, the translation blanks its body, so an edit inside that
    # body leaves the translation as it was - and only a recompile tries the
    # real body again (unquarantine).
    deps = [os.path.join(REPO, tu), os.path.join(SRC, tu), rsp] + COMPAT + ([PCH_FILE] if USE_PCH else [])
    deps += [l.rstrip('\n') for l in open(dep)]
    return any(not os.path.exists(d) or os.path.getmtime(d) > t for d in deps)


def valid_object(path):
    """True if `path` is a complete i386 COFF object: every section's data and
    relocations, the symbol table and the string table lie inside the file."""
    if not os.path.exists(path):
        return False
    try:
        o = coffobj.CoffObject(open(path, 'rb').read(), path)
        return o.comp_id() is not None
    except Exception:
        return False


def quarantine(tu, errors_log):
    """Record the functions holding the TU's own compile errors in
    quarantine.tsv and re-translate the TU with their bodies blanked. Returns
    the number of functions newly quarantined (0: nothing that can be)."""
    src = os.path.join(SRC, tu)
    own = []
    for line in errors_log:
        m = ERROR_AT.match(line.strip())
        if m and linux(m.group('file')) and os.path.normcase(linux(m.group('file'))).lower() == src.lower():
            own.append((int(m.group('line')), m.group('code') + ' ' + m.group('msg')))
    if not own:
        return 0
    text = open(src, encoding='utf-8', errors='surrogateescape').read()
    rows = []
    for ln, msg in own:
        b = vc8_translate.function_body_at(text, ln)
        if b is None:
            return 0                      # an error outside any function: cannot quarantine
        head_line = text.count('\n', 0, b[0]) + 1
        _, done = vc8_translate.quarantine_bodies(text, [ln])
        name = done[0][1] if done else '?'
        rows.append((tu, ln, head_line, name, msg))
    with _qlock:
        known = set()
        if os.path.exists(QUARANTINE_TSV):
            known = {tuple(l.split('\t')[:2]) for l in open(QUARANTINE_TSV)}
        new = [r for r in rows if (r[0], str(r[1])) not in known]
        with open(QUARANTINE_TSV, 'a') as f:
            if not known:
                f.write('file\tline\tfunction_line\tfunction\terror\n')
            for r in new:
                f.write('%s\t%d\t%d\t%s\t%s\n' % r)
        vc8_translate.load_quarantine(QUARANTINE_TSV)
        orig = open(os.path.join(REPO, tu), encoding='utf-8', errors='surrogateescape').read()
        out = vc8_translate.translate(orig, tu)
        with open(src, 'w', encoding='utf-8', errors='surrogateescape') as f:
            f.write(out)
    return len(new)


def unquarantine(tu):
    """Forget the TU's quarantined functions and re-translate it without them:
    every recompile first tries the real bodies, so a quarantine whose cause
    has since been fixed (in the tree or in the oracle) lifts itself."""
    with _qlock:
        if not os.path.exists(QUARANTINE_TSV):
            return
        lines = open(QUARANTINE_TSV).readlines()
        keep = [l for l in lines if l.split('\t', 1)[0] != tu]
        if len(keep) == len(lines):
            return
        with open(QUARANTINE_TSV, 'w') as f:
            f.writelines(keep)
        vc8_translate.load_quarantine(QUARANTINE_TSV)
        orig = open(os.path.join(REPO, tu), encoding='utf-8', errors='surrogateescape').read()
        with open(os.path.join(SRC, tu), 'w', encoding='utf-8', errors='surrogateescape') as f:
            f.write(vc8_translate.translate(orig, tu))


def compile_one(tu, rsp):
    unquarantine(tu)
    for _round in range(MAX_QUARANTINE_ROUNDS + 1):
        tu, ok, errors, secs, log = compile_once(tu, rsp)
        if ok or not quarantine(tu, log):
            return tu, ok, errors, secs
    return tu, ok, errors, secs


def compile_once(tu, rsp):
    base = os.path.join(OBJ, tu[:-4])
    os.makedirs(os.path.dirname(base), exist_ok=True)
    for ext in ('.obj', '.d'):
        if os.path.exists(base + ext):
            os.remove(base + ext)
    cmd = [os.path.join(HERE, 'vc8.sh'), 'cl', '@' + win(rsp), '/showIncludes'] + \
        extra_flags(tu).split() + \
        (['/Yu' + PCH_HEADER] if USE_PCH else []) + \
        ['/Fo' + win(base + '.obj'), win(os.path.join(SRC, tu))]
    t0 = time.time()
    for attempt in (1, 2):
        try:
            p = subprocess.run(cmd, capture_output=True, text=True, encoding='latin1', timeout=COMPILE_TIMEOUT)
            break
        except subprocess.TimeoutExpired:
            # A compile under wine can block indefinitely (seen on the first
            # processes of a fresh wineserver); one retry, then give up.
            if attempt == 2:
                return tu, False, ['timed out twice after %ds' % COMPILE_TIMEOUT], time.time() - t0, []
    out = p.stdout + p.stderr
    deps, log = [], []
    for line in out.splitlines():
        m = INCLUDING.match(line)
        if m:
            path = linux(m.group(1))
            if path:
                deps.append(path)
        else:
            log.append(line)
    with open(base + '.log', 'w') as f:
        f.write('\n'.join(log) + '\n')
    errors = [l for l in log if ERROR.search(l)]
    # The exit status is not trusted: under wine on box64 a compile that has
    # written its object can still be SIGKILLed on its way out (-9 here, 137
    # in a shell) when the wineserver tears the process down before its threads
    # finish exiting. cl.exe deletes the object on any real error, so success
    # is: an object that parses completely as COFF, and no error in the log.
    ok = not errors and valid_object(base + '.obj')
    if p.returncode not in (0, 137, -9) and ok:
        ok = False
        errors = ['cl.exe exit status %d' % p.returncode]
    if ok:
        with open(base + '.d', 'w') as f:
            f.write('\n'.join(sorted(set(deps))) + '\n')
        with open(base + '.flags', 'w') as f:
            f.write(extra_flags(tu))
    return tu, ok, errors, time.time() - t0, log


def sweep_box64_cache():
    """Delete box64's orphaned dynarec cache files. box64 writes a process's
    cache to <module>.box64.tmp.<pid>.N and renames it when the process
    exits; a cl.exe SIGKILLed on its way out under wine never gets there, so
    every compile leaves its c1xx.dll cache behind (about 12 MB, never read
    again) - thousands of them filled the disk once. A file whose process is
    gone is garbage."""
    folder = os.environ.get('BOX64_DYNACACHE_FOLDER') or os.path.expanduser('~/.cache/box64')
    freed = 0
    for path in glob.glob(os.path.join(folder, '*.box64.tmp.*')):
        m = re.search(r'\.tmp\.(\d+)\.\d+$', path)
        if m and not os.path.exists('/proc/' + m.group(1)):
            try:
                freed += os.path.getsize(path)
                os.remove(path)
            except OSError:
                pass
    return freed


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('-j', '--jobs', type=int, default=os.cpu_count() or 4)
    ap.add_argument('--force', action='store_true', help='recompile even up-to-date objects')
    ap.add_argument('--with-data', action='store_true', help='also compile globals/ (data only)')
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()

    if EXPERIMENT:
        print('*** EXPERIMENT: ORACLE_VC=%s ORACLE_CFLAGS=%r -> %s' % (VC, CFLAGS, BUILD), file=sys.stderr)
        print('*** evidence from this build must not be committed', file=sys.stderr)
    w, k = vc8_translate.mirror(REPO, SRC, QUARANTINE_TSV)
    print('translate: %d written, %d unchanged' % (w, k))
    rsp = write_rsp()
    # Start the wine session before the parallel phase, with no pipes attached.
    # The first wine process of a session spawns wine's background services
    # (explorer, winedevice, ...), which inherit its stdout and stderr: a
    # compile captured through pipes would then wait for an end-of-file that
    # only comes when those services exit - at the end of the build. A
    # persistent wineserver (-p) keeps the session, and the services, up.
    env = dict(os.environ, WINEPREFIX=os.environ.get('VC8_WINEPREFIX', os.path.expanduser(
        '~/q2-dev/asm-matching-toolchain/wine-vc8')))
    quiet = dict(stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    subprocess.run(['wineserver', '-p'], env=env, **quiet)
    subprocess.run([os.path.join(HERE, 'vc8.sh'), 'cl', '/nologo'], timeout=300, **quiet)
    if USE_PCH:
        err = build_pch(rsp)
        if err:
            print('precompiled header failed: %s' % err, file=sys.stderr)
            return 1

    tus = []
    for dirpath, _dirs, files in os.walk(SRC):
        for f in files:
            if f.endswith('.cpp'):
                tus.append(os.path.relpath(os.path.join(dirpath, f), SRC))
    tus.sort()
    if not args.with_data:
        tus = [t for t in tus if not t.startswith('globals' + os.sep)]
    if args.patterns:
        tus = [t for t in tus if any(p in t for p in args.patterns)]
    todo = [t for t in tus if args.force or stale(t, rsp)]
    print('%d TUs, %d to compile, %d jobs' % (len(tus), len(todo), args.jobs))

    status = {}
    status_file = os.path.join(BUILD, 'compile_status.tsv')
    if os.path.exists(status_file):
        for line in open(status_file):
            parts = line.rstrip('\n').split('\t')
            if len(parts) >= 2 and parts[0] != 'tu':
                status[parts[0]] = parts
    failed = 0
    t0 = time.time()
    with cf.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        futs = [pool.submit(compile_one, t, rsp) for t in todo]
        for n, fut in enumerate(cf.as_completed(futs), 1):
            tu, ok, errors, secs = fut.result()
            failed += not ok
            first = errors[0].strip() if errors else ''
            status[tu] = [tu, 'ok' if ok else 'FAIL', str(len(errors)), first[:300]]
            print('[%d/%d] %-4s %5.1fs %s%s' % (n, len(todo), 'ok' if ok else 'FAIL', secs, tu,
                                                '' if ok else '  ' + first[:160]))
    for t in tus:
        if t not in status and os.path.exists(os.path.join(OBJ, t[:-4] + '.obj')):
            status[t] = [t, 'ok', '0', '']
    with open(status_file, 'w') as f:
        f.write('tu\tstatus\terrors\tfirst_error\n')
        for t in sorted(status):
            if os.path.exists(os.path.join(SRC, t)):
                f.write('\t'.join(status[t]) + '\n')
    nok = sum(1 for t in tus if status.get(t, [None, ''])[1] == 'ok')
    sweep_box64_cache()
    print('compiled %d/%d TUs OK (%d failed this run) in %.0fs' % (nok, len(tus), failed, time.time() - t0))
    return 0 if nok == len(tus) else 1


if __name__ == '__main__':
    sys.exit(main())
