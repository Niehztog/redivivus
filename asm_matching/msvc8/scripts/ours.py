"""ours.py - every function in the compiled objects, with what it refers to.

Loading decodes each object once and caches the result next to it
(<obj>.fn.pkl), invalidated by the object's mtime and by DECODER, which a
change to how objects are decoded must bump.
"""
import os
import pickle

import objfuncs

DECODER = 2     # 2: switch tables found through the relocation on the displacement


class OurFunc:
    """The parts of objfuncs.Function the matcher and the audit need, picklable."""
    __slots__ = ('tu', 'symbol', 'name', 'order', 'size', 'insns', 'strings', 'imports', 'calls',
                 'datarefs', 'static', 'decoded', 'refs', 'lines')

    def __init__(self, tu, order, f):
        self.tu = tu                    # 'D2Common/Environment' (object path without .obj)
        self.symbol = f.symbol          # mangled
        self.name = f.name              # qualified, readable
        self.order = order              # position of its COMDAT in the object
        self.size = len(f.code)
        self.insns = len(f.decoded.insns)
        self.static = f.static
        self.refs = f.refs              # (offset, kind, target)
        self.decoded = f.decoded
        self.strings = [t for _o, k, t in f.refs if k == 'string']
        self.imports = [t for _o, k, t in f.refs if k == 'import']
        self.calls = [t for _o, k, t in f.refs if k == 'call']
        self.datarefs = [t for _o, k, t in f.refs if k == 'data']
        self.lines = f.lines            # (offset, source file, line) from /Z7

    def line_at(self, off):
        """(source file, line) of the instruction at `off`, or None."""
        best = None
        for o, fn, ln in self.lines:
            if o <= off:
                best = (fn, ln)
            else:
                break
        return best

    @property
    def source_line(self):
        """The first line of its own .cpp it was compiled from: where it is
        defined. None for code from headers only (inline functions, templates)."""
        own = self.tu.lower() + '.cpp'
        lines = [ln for _o, fn, ln in self.lines if fn.lower().replace('\\', '/').endswith(own)]
        return min(lines) if lines else None

    @property
    def layout_key(self):
        """Sort key for the order of the TU's functions in the original. The
        generator writes a file's functions in address order, so the source
        line predicts the original layout; the object's COMDAT order does not:
        VC8 compiles a caller only after the same-TU functions it calls, and
        emits a function calling one defined further down (or an inline
        helper) at the end of the object. Functions with no line of their own
        go last, in object order."""
        ln = self.source_line
        return (0, ln, self.order) if ln is not None else (1, 0, self.order)

    @property
    def key(self):
        return self.tu + '|' + self.symbol


def load_object(objdir, rel):
    path = os.path.join(objdir, rel)
    cache = path[:-4] + '.fn.pkl'
    mt = os.path.getmtime(path)
    if os.path.exists(cache):
        try:
            with open(cache, 'rb') as fh:
                stamp, fns = pickle.load(fh)
            if stamp == (mt, DECODER):
                return fns
        except Exception:
            pass                        # half-written by a process killed mid-write: decode again
    tu = rel[:-4]
    fns = [OurFunc(tu, k, f) for k, f in enumerate(objfuncs.functions(path))]
    # Written aside and renamed, so a reader sees the old cache or the new one.
    tmp = '%s.%d.tmp' % (cache, os.getpid())
    with open(tmp, 'wb') as fh:
        pickle.dump(((mt, DECODER), fns), fh, protocol=pickle.HIGHEST_PROTOCOL)
    os.replace(tmp, cache)
    return fns


def load_all(objdir):
    """Every function of every completed object. build.py removes an object
    and its .d before compiling and writes the .d only on success, so an
    object without one is half-written or failed, and is skipped."""
    out = []
    for dirpath, _dirs, files in os.walk(objdir):
        for f in sorted(files):
            if f.endswith('.obj') and f[:-4] + '.d' in files:
                rel = os.path.relpath(os.path.join(dirpath, f), objdir)
                out.extend(load_object(objdir, rel))
    return out
