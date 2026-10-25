#!/usr/bin/env python3
"""fix_static.py - make file-local functions static where the original was.

    fix_static.py [--apply] [PATTERN ...]

VC8 gives a static function a calling convention of its own choosing - an
argument in EAX, ESI, EDI, ..., the rest on the stack - when every call to it
is in the same translation unit. The original is full of them; the tree
declares every function extern, so VC8 cannot, and both the function and its
callers differ. Making such a function static is enough for VC8 to choose
again, and when the source is right it chooses as the original did
(IsOtherAct, 00548a80: pUnit2 in EAX, `ret 4`).

A candidate is a mapped function whose original has registers live on entry
that its declared convention does not pass arguments in (classify.live_in) -
a different `ret N` alone is no evidence: a static function the original
does not pass anything in registers is what --demote undoes - and whose name
appears in no file but its own TU and its own header's declaration (comments
ignored), and in the TU more than once: a static function nothing calls is
dropped by VC8, so a function the original calls from code the tree lacks
must stay extern. The edit: `static` on the definition, the header's
declaration (and the comment block above it, which the .cpp repeats)
removed, and a static forward declaration added to the .cpp only when it
uses the function before defining it.

--demote goes the other way: a static function to which VC8 now gives a
register convention the original does not show (the original's live-in
registers are only what the declared convention passes, ours are others) is
made extern again - its header declaration, with the comment block above it,
restored from the generator's tree (BEFORE_PROMOTIONS). A promotion can be
right under one flag and wrong under another: a function with a char buffer
keeps its convention under /GS (it gets a cookie), not under /GS-
(CHATDLG_RunChatLobbyScreen, called from 00442150).

Without --apply it lists candidates. With --apply the promotions go through
fixlib's batch loop: all TUs edited and rebuilt at once, every function of
each TU re-judged; a promotion is dropped when the function or one of its
callers stops matching, or the function gets less similar while none of
the functions naming it comes to match (a caller that matches shows the
convention is the original's: GFX_FreeUnusedCofEntries, 0046f370, whose
body has other differences), and the rest is tried again. Kept results are written into the audit rows. These are edits
to generated files: the generator's static promotion is the durable home for
the rule.
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import classify         # noqa: E402
import fixlib           # noqa: E402
import ours as ourslib  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

COMMENTS = re.compile(r'//[^\n]*|/\*.*?\*/', re.S)
CONV_ARGS = {'YA': set(), 'YG': set(), 'YI': {'ecx', 'edx'}}   # __cdecl, __stdcall, __fastcall
BEFORE_PROMOTIONS = '6a3c8c4'      # the generator's tree, before any function was made static here


def strip_comments(text):
    return COMMENTS.sub(lambda m: ' ' if m.group(0).startswith('/*') else '', text)


def tree_files():
    out = []
    for dirpath, dirnames, files in os.walk(REPO):
        rel = os.path.relpath(dirpath, REPO)
        if rel == '.':
            dirnames[:] = [d for d in dirnames if d not in ('.git', 'asm_matching', 'build', 'thirdparty', 'tools')]
        for f in files:
            if f.endswith(('.cpp', '.h')):
                out.append(os.path.join(dirpath, f))
    return out


class Tree:
    """Comment-stripped text of every source file, and where each identifier occurs."""

    def __init__(self):
        self.files = tree_files()
        self.where = collections.defaultdict(set)
        self.counts = {}
        ident = re.compile(r'[A-Za-z_]\w*')
        for p in self.files:
            found = collections.Counter(ident.findall(strip_comments(open(p, encoding='utf-8', errors='replace').read())))
            self.counts[p] = found
            for name in found:
                self.where[name].add(p)

    def uses(self, path, name):
        """How often `name` occurs in `path`, comments aside (the definition counts)."""
        return self.counts.get(path, {}).get(name, 0)


def candidates(rows, model, fns, tree, pats):
    out = collections.defaultdict(list)
    for s, _e, name, tu, sym, _m, _d in rows:
        if pats and not any(p in tu for p in pats):
            continue
        f = fns.get(tu + '|' + sym)
        if f is None or f.static or not sym.startswith('?') or '@@' not in sym:
            continue
        conv = sym[sym.index('@@') + 2:sym.index('@@') + 4]
        if conv not in CONV_ARGS:
            continue                     # members, and anything not a plain namespace function
        extra = classify.live_in(model[s][0]) - CONV_ARGS[conv]
        if not extra:
            continue                     # no register the declaration does not pass: no evidence
        leaf = name.rsplit('::', 1)[-1]
        cpp = os.path.join(REPO, tu + '.cpp')
        hdr = os.path.join(REPO, tu + '.h')
        if tree.where.get(leaf, set()) - {cpp, hdr}:
            continue                     # named somewhere else: not file-local
        if tree.uses(cpp, leaf) < 2:
            continue                     # never called in the tree: static, VC8 would drop it
        out[tu].append((s, leaf, sorted(extra)))
    return out


def demotions(rows, model, fns, pats):
    """tu -> [(original start, leaf, our live-in)] for static functions whose
    register convention the original does not have."""
    out = collections.defaultdict(list)
    for s, _e, name, tu, sym, _m, _d in rows:
        if pats and not any(p in tu for p in pats):
            continue
        f = fns.get(tu + '|' + sym)
        if f is None or not f.static or not sym.startswith('?') or '@@' not in sym:
            continue
        conv = sym[sym.index('@@') + 2:sym.index('@@') + 4]
        if conv not in CONV_ARGS:
            continue
        theirs = classify.live_in(model[s][0])
        ours = classify.live_in(f.decoded)
        if theirs - CONV_ARGS[conv] or ours == theirs:
            continue                     # the original has a convention of its own, or ours agrees
        out[tu].append((s, name.rsplit('::', 1)[-1], sorted(ours)))
    return out


def git_show(rev, path):
    import subprocess
    r = subprocess.run(['git', '-C', REPO, 'show', '%s:%s' % (rev, os.path.relpath(path, REPO))],
                       capture_output=True, text=True, encoding='utf-8', errors='surrogateescape')
    return r.stdout if r.returncode == 0 else None


def demote(texts, cpp, hdr, leaf, old_hdr):
    """The texts with `leaf` extern again, or None if it cannot be done."""
    src = texts[cpp]
    m = re.search(def_pattern(leaf), src, re.M)
    if not m or not m.group('head').startswith('static '):
        return None
    head = m.group('head')
    new = src[:m.start()] + head[len('static '):] + src[m.start() + len(head):]
    fwd = '\nstatic ' + head[len('static '):].rstrip() + ';'
    new = new.replace(fwd, '', 1)
    out = {cpp: new}
    if hdr in texts and old_hdr is not None:
        h = texts[hdr]
        decl = re.compile(r'(?P<comments>(?:^//[^\n]*\n)*)^[^\n]*\b%s\s*\([^;{}]*\);[ \t]*\n' % re.escape(leaf), re.M)
        hm = list(decl.finditer(old_hdr))
        if len(hm) > 1:
            return None                  # declared twice: which one is not clear
        if not hm or decl.search(h):
            return out                   # never declared there, or still is
        block = hm[0].group(0)
        # Back where it was: after the nearest line above it that the header
        # still has, exactly once.
        above = old_hdr[:hm[0].start()].split('\n')[:-1]
        lines = h.split('\n')
        for anchor in reversed(above):
            if anchor.strip() and lines.count(anchor) == 1:
                k = lines.index(anchor)
                out[hdr] = '\n'.join(lines[:k + 1]) + '\n' + block + '\n'.join(lines[k + 1:])
                break
        else:
            return None
    return out


def demotion(cpp, hdr, leaf, old_hdr):
    return lambda texts: demote(texts, cpp, hdr, leaf, old_hdr)


def def_pattern(name):
    """The definition of `name` at the start of a line: head (everything up to
    the parameter list's close), then the opening brace."""
    return (r'^(?P<head>[A-Za-z_][^;{}()\n]*?\b' + re.escape(name) +
            r'\s*\((?P<params>[^;{}]*)\)[ \t]*)\{')


def promote(texts, cpp, hdr, leaf):
    """The texts with `leaf` made static, or None if it cannot be done."""
    src = texts[cpp]
    m = re.search(def_pattern(leaf), src, re.M)
    if not m or m.group('head').startswith('static '):
        return None
    head = m.group('head').rstrip()
    new = src[:m.start()] + 'static ' + src[m.start():]
    # A use before the definition - a call, or its address - needs a
    # declaration ahead of it.
    before = strip_comments(src[:m.start()])
    if re.search(r'\b%s\b' % re.escape(leaf), before):
        ns = list(re.finditer(r'^namespace [^\n]*\{[ \t]*$', new[:m.start() + 7], re.M))
        at = ns[0].end() if ns else 0
        new = new[:at] + '\nstatic ' + head + ';' + new[at:]
    out = {cpp: new}
    if hdr in texts:
        h = texts[hdr]
        decl = re.compile(r'(?P<comments>(?:^//[^\n]*\n)*)^[^\n]*\b%s\s*\([^;{}]*\);[ \t]*\n' % re.escape(leaf), re.M)
        hm = list(decl.finditer(h))
        if len(hm) > 1:
            return None
        if hm:
            a, b = hm[0].start(), hm[0].end()
            # The comment block above the declaration goes only if the .cpp
            # repeats it above the definition (the generator writes both);
            # annotations such as // @sourcefile must never be lost.
            block = hm[0].group('comments')
            if block and block not in src[:m.start()]:
                a += len(block)
            out[hdr] = h[:a] + h[b:]
    return out


def promotion(cpp, hdr, leaf):
    return lambda texts: promote(texts, cpp, hdr, leaf)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--demote', action='store_true', help='make static functions extern where the original shows no convention of their own')
    ap.add_argument('-j', '--jobs', type=int, default=4)
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    _ref, model = audit.load_context()
    fns = {f.key: f for f in ourslib.load_all(os.path.join(BUILD, 'obj'))}
    if args.demote:
        return demote_main(args, rows, model, fns)
    tree = Tree()
    cands = candidates(rows, model, fns, tree, args.patterns)
    total = sum(len(v) for v in cands.values())
    print('%d candidates in %d TUs' % (total, len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            print(tu, ', '.join('%s(%s)' % (leaf, '+'.join(x) or 'cleanup') for _s, leaf, x in cands[tu]))
        return 0
    syms = audit.sym_map(rows)
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    start_of = {(r[3], r[4]): r[0] for r in rows}
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        hdr = os.path.join(REPO, tu + '.h')
        # A promotion changes the function and every function naming it -
        # a call, or its address taken: those are affected too.
        lines = fixlib.read(cpp).split('\n')
        spans = []
        for f in fns.values():
            if f.tu == tu and (tu, f.symbol) in start_of and f.source_line:
                own = [ln for _o, fn, ln in f.lines if fn.lower().replace('\\', '/').endswith(tu.lower() + '.cpp')]
                spans.append((min(own), max(own), start_of[(tu, f.symbol)]))
        edits = []
        for s, leaf, _x in cands[tu]:
            word = re.compile(r'\b%s\b' % re.escape(leaf))
            users = {u for lo, hi, u in spans if any(word.search(l) for l in lines[lo - 1:hi])}
            edits.append(fixlib.Edit(leaf, [s], users, promotion(cpp, hdr, leaf), excused_by_match=True))
        groups[tu] = (edits, [cpp, hdr])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d promotions, MATCH %+d' % (kept, gained))
    fixlib.record('fix_static', total, kept, gained)
    return 0


def demote_main(args, rows, model, fns):
    cands = demotions(rows, model, fns, args.patterns)
    total = sum(len(v) for v in cands.values())
    print('%d static functions with a convention the original does not have, in %d TUs' % (total, len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            print(tu, ', '.join('%s(%s)' % (leaf, '+'.join(x)) for _s, leaf, x in cands[tu]))
        return 0
    syms = audit.sym_map(rows)
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    start_of = {(r[3], r[4]): r[0] for r in rows}
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        hdr = os.path.join(REPO, tu + '.h')
        old_hdr = git_show(BEFORE_PROMOTIONS, hdr)
        lines = fixlib.read(cpp).split('\n')
        spans = []
        for f in fns.values():
            if f.tu == tu and (tu, f.symbol) in start_of and f.source_line:
                own = [ln for _o, fn, ln in f.lines if fn.lower().replace('\\', '/').endswith(tu.lower() + '.cpp')]
                spans.append((min(own), max(own), start_of[(tu, f.symbol)]))
        edits = []
        for s, leaf, _x in cands[tu]:
            word = re.compile(r'\b%s\b' % re.escape(leaf))
            users = {u for lo, hi, u in spans if any(word.search(l) for l in lines[lo - 1:hi])}
            edits.append(fixlib.Edit(leaf, [s], users, demotion(cpp, hdr, leaf, old_hdr)))
        groups[tu] = (edits, [cpp, hdr])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d demotions, MATCH %+d' % (kept, gained))
    fixlib.record('fix_static --demote', total, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
