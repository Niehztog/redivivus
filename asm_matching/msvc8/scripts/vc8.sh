#!/usr/bin/env bash
# vc8.sh - run one VC8 tool under wine with the oracle's environment.
#
#   vc8.sh cl   /c /O2 ... R:\path\file.cpp
#   vc8.sh link ...
#   ORACLE_VC=rtm vc8.sh cl ...        # the RTM compiler instead of SP1
#
# INCLUDE and LIB are the compiler's own directories followed by the Platform
# SDK's, exactly the order a VS2005 Professional install puts them in.
# The repository is reachable as drive $ORACLE_DRIVE (default R:); see
# map_drive in env.sh. Exit status is the tool's.
set -euo pipefail
. "$(dirname "$0")/env.sh"

tool="${1:?usage: vc8.sh <cl|link|lib|dumpbin|undname|ml> args...}"; shift
case "$ORACLE_VC" in rtm|sp1) ;; *) echo "ORACLE_VC must be rtm or sp1" >&2; exit 2 ;; esac
map_drive
exe="$WINEPREFIX/drive_c/vc8/$ORACLE_VC/bin/$tool.exe"
[ -f "$exe" ] || { echo "no $exe - run setup_toolchain.sh" >&2; exit 2; }

export INCLUDE="C:\\vc8\\$ORACLE_VC\\include;C:\\vc8\\psdk\\include"
export LIB="C:\\vc8\\$ORACLE_VC\\lib;C:\\vc8\\psdk\\lib"
exec wine "$exe" "$@"
