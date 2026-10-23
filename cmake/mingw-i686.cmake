# Cross-compile Redivivus for 32-bit Windows with mingw-w64 (i686).
#
#   cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=cmake/mingw-i686.cmake
#
# Needs i686-w64-mingw32-{gcc,g++,windres,dlltool} on PATH (Homebrew: mingw-w64,
# Debian/Ubuntu: g++-mingw-w64-i686). Override the prefix with -DD2_TOOL_PREFIX=.

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86)

if(NOT D2_TOOL_PREFIX)
    set(D2_TOOL_PREFIX i686-w64-mingw32-)
endif()

set(CMAKE_C_COMPILER   ${D2_TOOL_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${D2_TOOL_PREFIX}g++)
set(CMAKE_ASM_COMPILER ${D2_TOOL_PREFIX}gcc)
set(CMAKE_RC_COMPILER  ${D2_TOOL_PREFIX}windres)
find_program(CMAKE_DLLTOOL NAMES ${D2_TOOL_PREFIX}dlltool)

# Search the host for programs, the target sysroot for everything else.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
