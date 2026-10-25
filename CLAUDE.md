# CLAUDE.md

Redivivus is Diablo II 1.14d's `Game.exe`, recovered as C++ source that builds
(README.md). Most of the tree is generator output (ghidra-reconstruct); a fix
that belongs in the reverse-engineering database is reported, not hand-edited.

## Two ways to judge a change

* **It builds and runs**: `tools/check-build.sh` (mingw, what CI runs) and the
  game itself. Necessary, and weak: most code paths are never exercised.
* **It is the original code**: the ASM-matching oracle in
  `asm_matching/msvc8/` recompiles the tree with the compiler that built
  1.14d - Visual C++ 2005 SP1, identified from the binary in
  `asm_matching/msvc8/evidence/toolchain.md` - and compares every function
  byte for byte with the shipped `Game.exe`. Read
  `asm_matching/msvc8/README.md` before using it.

```sh
asm_matching/msvc8/oracle setup          # once
asm_matching/msvc8/oracle build <TU>     # after an edit (incremental)
asm_matching/msvc8/oracle diff <function>
asm_matching/msvc8/oracle all            # whole tree: build, map, audit
```

## Rules for the oracle

* **Numbers live in the evidence files** (`asm_matching/msvc8/evidence/`),
  never in prose: a count in a README or a commit message is stale by the next
  fix. Cite the file.
* **Flags are measured, not assumed.** A hypothesis (another compiler build,
  `/Oy-`, `/GL`, ...) is an experiment: `ORACLE_VC` / `ORACLE_CFLAGS` build
  in `build/experiment-*` and are audited with the baseline's function map.
  Evidence from an experiment is never committed.
* **No Blizzard bytes in git.** `Game.exe` is fetched into the ignored
  `asm_matching/msvc8/reference/`; its disassembly and anything else carrying
  its code stay under the ignored `build/`. Addresses, names and counts are
  fine.
* **A function that matched and stops matching is a regression**, whatever
  the game does. `oracle diff` it before committing.
* **One oracle build per checkout at a time**; they share `build/`. Two
  checkouts on one wine prefix use different `ORACLE_DRIVE` letters.
* The oracle's own source handling (`vc8_translate.py`, `vc8_compat.h`,
  `shim_include/`) must stay codegen-neutral: a rewrite that changes what a
  construct compiles to is a defect in the oracle, not a fix to the tree.
  `scripts/objdiff.py` checks two builds for identical code.
* A difference the generator makes everywhere is fixed everywhere, by a
  fixer (`scripts/fix_*.py`) that keeps an edit only where the oracle
  confirms it; its rule also goes upstream (generator or Ghidra database),
  with the evidence, so a regeneration does not undo it.

## Commits

The oracle lives on its own branch, and its history keeps two kinds of
change apart:

* Everything belonging to the ASM-matching tooling - `asm_matching/`, this
  file, the `CMakeLists.txt` line that keeps the oracle out of the game's
  build - is amended into the branch's first commit, the oracle commit.
* Changes to the Diablo II source go into new commits on top of it, one
  per piece of work - never into the oracle commit.

`asm_matching/msvc8/scripts/commit.py -m "..."` does both from a working tree
with changes of either kind.

## Sibling projects

The method comes from three Quake II reconstructions with VC6 and gcc
oracles - the Gladiator bot library, Rocket Arena 2, OSP Tourney - which on
this machine live in `~/q2-dev/`. Their tooling and notes are the precedent
for anything not yet settled here; their flags and results are not: every
flag is per project and per target, and was measured there.
