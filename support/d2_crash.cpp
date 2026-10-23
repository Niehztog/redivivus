// Crash report: on a fatal exception, write d2crash-YYYYMMDD-HHMMSS.txt next to the
// executable, with the stack symbolised to function and file:line from the DWARF
// this build carries. Every build is compiled with -g, so the report names source
// lines for whoever compiled it, without the person reading it needing that exe.
//
// The DWARF is read by libbacktrace (thirdparty/libbacktrace) straight out of the
// running image. Parsing it happens only on a crash, on a worker thread with its
// own stack, so a stack overflow or a damaged stack still gets symbolised; if that
// thread cannot finish, the report falls back to module+offset per frame.

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>

#include "thirdparty/libbacktrace/backtrace.h"

#ifndef REDIVIVUS_BUILD_ID
#define REDIVIVUS_BUILD_ID "unknown"
#endif

#ifdef REDIVIVUS_DEV
static const char* const BUILD_KIND = "DEV";
#else
static const char* const BUILD_KIND = "release";
#endif

namespace {

// ---------------------------------------------------------------------------
// Startup state.
// ---------------------------------------------------------------------------
char g_szExePath[MAX_PATH];
backtrace_state* g_pBtState = 0;

// libbacktrace reports problems through a callback; they are collected here and
// printed in the report, never acted on.
char g_szBtErrors[1024];

void BtError(void*, const char* pszMsg, int nErr) {
    size_t n = strlen(g_szBtErrors);
    if (n + 200 >= sizeof(g_szBtErrors)) return;
    if (nErr == -1)
        wsprintfA(g_szBtErrors + n, "  no debug info: %s\r\n", pszMsg);
    else
        wsprintfA(g_szBtErrors + n, "  %s (error %d)\r\n", pszMsg, nErr);
}

// ---------------------------------------------------------------------------
// Which exceptions are crashes. Anything not listed (debug-print, thread-name,
// C++ throws, breakpoints, single-step, guard pages) is left alone.
// ---------------------------------------------------------------------------
const char* FatalName(DWORD dwCode) {
    switch (dwCode) {
    case 0xC0000005: return "ACCESS_VIOLATION";
    case 0xC000001D: return "ILLEGAL_INSTRUCTION (ud2: a compiler trap or an assert)";
    case 0xC0000096: return "PRIVILEGED_INSTRUCTION";
    case 0xC0000094: return "INTEGER_DIVIDE_BY_ZERO";
    case 0xC0000095: return "INTEGER_OVERFLOW";
    case 0xC000008E: return "FLOAT_DIVIDE_BY_ZERO";
    case 0xC00000FD: return "STACK_OVERFLOW";
    case 0xC0000006: return "IN_PAGE_ERROR";
    case 0xC000008C: return "ARRAY_BOUNDS_EXCEEDED";
    case 0xC0000025: return "NONCONTINUABLE_EXCEPTION";
    case 0xC0000374: return "HEAP_CORRUPTION";
    }
    return 0;
}

// ---------------------------------------------------------------------------
// The frames, gathered in the faulting thread without touching the heap.
// ---------------------------------------------------------------------------
enum FrameKind { FRAME_FAULT, FRAME_CHAIN, FRAME_SCAN };
struct Frame {
    DWORD dwAddr;
    DWORD dwStackOff;   // FRAME_SCAN: offset from ESP the slot was found at
    FrameKind eKind;
};
const int MAX_FRAMES = 64;
Frame g_aFrames[MAX_FRAMES];
int g_nFrames = 0;

DWORD g_dwExeLo = 0, g_dwExeHi = 0;

void AddFrame(DWORD dwAddr, DWORD dwStackOff, FrameKind eKind) {
    if (g_nFrames < MAX_FRAMES) {
        g_aFrames[g_nFrames].dwAddr = dwAddr;
        g_aFrames[g_nFrames].dwStackOff = dwStackOff;
        g_aFrames[g_nFrames].eKind = eKind;
        ++g_nFrames;
    }
}

bool InExecutableSectionOfExe(DWORD dwAddr) {
    if (dwAddr < g_dwExeLo || dwAddr >= g_dwExeHi) return false;
    const char* pBase = (const char*)(UINT_PTR)g_dwExeLo;
    const IMAGE_NT_HEADERS* pNt =
        (const IMAGE_NT_HEADERS*)(pBase + ((const IMAGE_DOS_HEADER*)pBase)->e_lfanew);
    const IMAGE_SECTION_HEADER* pSec = IMAGE_FIRST_SECTION(pNt);
    DWORD dwRva = dwAddr - g_dwExeLo;
    for (WORD i = 0; i < pNt->FileHeader.NumberOfSections; ++i, ++pSec) {
        if (!(pSec->Characteristics & IMAGE_SCN_MEM_EXECUTE)) continue;
        if (dwRva >= pSec->VirtualAddress && dwRva < pSec->VirtualAddress + pSec->Misc.VirtualSize)
            return true;
    }
    return false;
}

// A stack slot is a plausible return address when it points into our code just
// after a CALL: E8 rel32, or FF /2 in its register and memory forms.
bool LooksLikeReturnAddress(DWORD dwAddr) {
    if (!InExecutableSectionOfExe(dwAddr) || !InExecutableSectionOfExe(dwAddr - 7)) return false;
    const unsigned char* p = (const unsigned char*)(UINT_PTR)dwAddr;
    if (p[-5] == 0xE8) return true;
    static const int s_anLen[] = { 2, 3, 6, 7 };
    for (int n : s_anLen)
        if (p[-n] == 0xFF && ((p[-n + 1] >> 3) & 7) == 2) return true;
    return false;
}

void CollectFrames(const CONTEXT* pCtx) {
    g_nFrames = 0;
    AddFrame(pCtx->Eip, 0, FRAME_FAULT);

    // The thread's own stack bounds, from the TEB. Everything between ESP and the
    // stack base is committed, so reads inside it cannot fault.
    NT_TIB* pTib = (NT_TIB*)NtCurrentTeb();
    DWORD dwBase = (DWORD)(UINT_PTR)pTib->StackBase;
    DWORD dwLimit = (DWORD)(UINT_PTR)pTib->StackLimit;
    DWORD dwLo = pCtx->Esp > dwLimit ? pCtx->Esp : dwLimit;

    bool bEbpGood = pCtx->Ebp >= dwLo && pCtx->Ebp + 8 <= dwBase && !(pCtx->Ebp & 3);
    if (bEbpGood) {
        DWORD dwFrame = pCtx->Ebp;
        for (int i = 0; i < 48; ++i) {
            const DWORD* p = (const DWORD*)(UINT_PTR)dwFrame;
            DWORD dwRet = p[1];
            if (!dwRet) break;
            AddFrame(dwRet, 0, FRAME_CHAIN);
            DWORD dwNext = p[0];
            if (dwNext <= dwFrame || dwNext + 8 > dwBase || (dwNext & 3)) break;
            dwFrame = dwNext;
        }
    }

    // A call through a null or wild pointer, a fault inside a frame-pointer-less
    // system DLL, or a broken EBP chain: the chain above says too little, so read
    // the stack itself for return addresses into our code.
    bool bEipOurs = pCtx->Eip >= g_dwExeLo && pCtx->Eip < g_dwExeHi;
    if (!bEipOurs || !bEbpGood) {
        int nFound = 0;
        for (DWORD dwSlot = dwLo; dwSlot + 4 <= dwBase && nFound < 24; dwSlot += 4) {
            if (dwSlot - dwLo > 0x4000) break;
            DWORD dwVal = *(const DWORD*)(UINT_PTR)dwSlot;
            if (!LooksLikeReturnAddress(dwVal)) continue;
            AddFrame(dwVal, dwSlot - pCtx->Esp, FRAME_SCAN);
            ++nFound;
        }
    }
}

// ---------------------------------------------------------------------------
// Report output. wsprintfA rather than the CRT: it needs no CRT state and keeps
// working when the heap is what broke. Lines stay under its 1024-byte limit.
// ---------------------------------------------------------------------------
HANDLE g_hFile = INVALID_HANDLE_VALUE;

void Out(const char* pszFormat, ...) {
    static char s_szLine[1100];
    va_list args;
    va_start(args, pszFormat);
    int n = wvsprintfA(s_szLine, pszFormat, args);
    va_end(args);
    DWORD dwWritten;
    if (n > 0 && g_hFile != INVALID_HANDLE_VALUE)
        WriteFile(g_hFile, s_szLine, (DWORD)n, &dwWritten, 0);
}

const char* BaseName(const char* pszPath) {
    const char* p = pszPath;
    for (const char* q = pszPath; *q; ++q)
        if (*q == '\\' || *q == '/') p = q + 1;
    return p;
}

// "module+0xOFFSET" for any address, or the bare address when no module holds it.
void ModuleOffset(DWORD dwAddr, char* pszOut) {
    HMODULE hMod = 0;
    char szPath[MAX_PATH];
    if (dwAddr && GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                                     GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                                     (LPCSTR)(UINT_PTR)dwAddr, &hMod) &&
        GetModuleFileNameA(hMod, szPath, MAX_PATH)) {
        wsprintfA(pszOut, "%s+0x%06lX", BaseName(szPath),
                  (unsigned long)(dwAddr - (DWORD)(UINT_PTR)hMod));
    } else {
        wsprintfA(pszOut, "0x%08lX (no module)", (unsigned long)dwAddr);
    }
}

bool OpenReport(const SYSTEMTIME& st) {
    char szDir[MAX_PATH];
    lstrcpyA(szDir, g_szExePath);
    DWORD n = lstrlenA(szDir);
    while (n > 0 && szDir[n - 1] != '\\' && szDir[n - 1] != '/') --n;
    szDir[n] = 0;
    for (int nTry = 0; nTry < 2; ++nTry) {
        if (nTry == 1) {
            // The game folder may not be writable (Program Files); %TEMP% then.
            DWORD m = GetTempPathA(MAX_PATH, szDir);
            if (m == 0 || m >= MAX_PATH - 40) return false;
        }
        for (int nSuffix = 1; nSuffix < 10; ++nSuffix) {
            char szPath[MAX_PATH + 40];
            if (nSuffix == 1)
                wsprintfA(szPath, "%sd2crash-%04u%02u%02u-%02u%02u%02u.txt", szDir,
                          st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
            else
                wsprintfA(szPath, "%sd2crash-%04u%02u%02u-%02u%02u%02u-%d.txt", szDir,
                          st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond,
                          nSuffix);
            g_hFile = CreateFileA(szPath, GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_NEW,
                                  FILE_ATTRIBUTE_NORMAL, 0);
            if (g_hFile != INVALID_HANDLE_VALUE) {
                OutputDebugStringA("Redivivus crash report: ");
                OutputDebugStringA(szPath);
                OutputDebugStringA("\n");
                return true;
            }
            if (GetLastError() != ERROR_FILE_EXISTS) break;
        }
    }
    return false;
}

// ---------------------------------------------------------------------------
// Symbolisation, on the worker thread. It formats into its own buffer; the
// faulting thread copies that into the report only if the worker finished.
// ---------------------------------------------------------------------------
char g_szSym[48 * 1024];
size_t g_nSym = 0;

void SymAppend(const char* pszFormat, ...) {
    if (g_nSym >= sizeof(g_szSym) - 1) return;
    va_list args;
    va_start(args, pszFormat);
    int n = vsnprintf(g_szSym + g_nSym, sizeof(g_szSym) - g_nSym, pszFormat, args);
    va_end(args);
    if (n > 0) g_nSym += (size_t)n < sizeof(g_szSym) - g_nSym ? (size_t)n : sizeof(g_szSym) - g_nSym - 1;
}

// Demangled into a static buffer, or the name as given.
const char* Demangle(const char* pszName) {
    static char* s_pszDemangled = 0;
    if (!pszName) return "?";
    if (pszName[0] != '_' || pszName[1] != 'Z') return pszName;
    int nStatus = 0;
    char* p = abi::__cxa_demangle(pszName, 0, 0, &nStatus);
    if (nStatus != 0 || !p) return pszName;
    free(s_pszDemangled);
    s_pszDemangled = p;
    return p;
}

struct PcInfo {
    int nHits;
};

int OnPcInfo(void* pData, uintptr_t, const char* pszFile, int nLine, const char* pszFunc) {
    PcInfo* pInfo = (PcInfo*)pData;
    if (!pszFunc && !pszFile) return 0;
    // libbacktrace reports the innermost inlined function first, then its callers.
    SymAppend(pInfo->nHits ? "\r\n        inlined in %s" : "  %s", Demangle(pszFunc));
    if (pszFile) SymAppend("  %s:%d", pszFile, nLine);
    ++pInfo->nHits;
    return pInfo->nHits >= 4;
}

void OnSymInfo(void* pData, uintptr_t uPc, const char* pszName, uintptr_t uVal, uintptr_t) {
    if (!pszName) return;
    SymAppend("  %s+0x%lX", Demangle(pszName), (unsigned long)(uPc - uVal));
    ++((PcInfo*)pData)->nHits;
}

void OnBtErrorQuiet(void*, const char* pszMsg, int nErr) { BtError(0, pszMsg, nErr); }

DWORD WINAPI SymbolizeThread(LPVOID) {
    static const char* const s_aKindLabel[] = { "fault", "frame", "scan " };
    for (int i = 0; i < g_nFrames; ++i) {
        const Frame& f = g_aFrames[i];
        // Deep recursion (a stack overflow) repeats one frame; show it twice.
        if (i >= 2 && f.dwAddr == g_aFrames[i - 1].dwAddr && f.dwAddr == g_aFrames[i - 2].dwAddr) {
            int nRun = 0;
            while (i < g_nFrames && g_aFrames[i].dwAddr == f.dwAddr) { ++nRun; ++i; }
            SymAppend("  ... the same frame %d more times\r\n", nRun);
            --i;
            continue;
        }
        char szMod[MAX_PATH + 40];
        ModuleOffset(f.dwAddr, szMod);
        if (f.eKind == FRAME_SCAN)
            SymAppend("  #%-2d %s  %s [esp+0x%lX]", i, s_aKindLabel[f.eKind], szMod,
                      (unsigned long)f.dwStackOff);
        else
            SymAppend("  #%-2d %s  %s", i, s_aKindLabel[f.eKind], szMod);
        // A return address points after the CALL; step back into it so the line
        // reported is the call's own.
        DWORD dwPc = f.eKind == FRAME_FAULT ? f.dwAddr : f.dwAddr - 1;
        PcInfo info = { 0 };
        if (g_pBtState && f.dwAddr >= g_dwExeLo && f.dwAddr < g_dwExeHi) {
            backtrace_pcinfo(g_pBtState, dwPc, OnPcInfo, OnBtErrorQuiet, &info);
            if (!info.nHits)
                backtrace_syminfo(g_pBtState, dwPc, OnSymInfo, OnBtErrorQuiet, &info);
        }
        SymAppend("\r\n");
    }
    return 0;
}

void WriteModules() {
    Out("\r\nModules:\r\n");
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0);
    if (hSnap == INVALID_HANDLE_VALUE) {
        Out("  (module snapshot failed, error %lu)\r\n", (unsigned long)GetLastError());
        return;
    }
    MODULEENTRY32 me;
    me.dwSize = sizeof(me);
    for (BOOL bOk = Module32First(hSnap, &me); bOk; bOk = Module32Next(hSnap, &me)) {
        Out("  %08lX %08lX  %s\r\n", (unsigned long)(UINT_PTR)me.modBaseAddr,
            (unsigned long)me.modBaseSize, me.szExePath);
    }
    CloseHandle(hSnap);
}

void WriteReport(EXCEPTION_POINTERS* pExc, bool bForeign, DWORD dwThreadId) {
    SYSTEMTIME st;
    GetLocalTime(&st);
    if (!OpenReport(st)) return;

    const EXCEPTION_RECORD* pRec = pExc->ExceptionRecord;
    const CONTEXT* pCtx = pExc->ContextRecord;

    Out("Redivivus crash report\r\n");
    Out("Send this whole file with your bug report.\r\n\r\n");
    Out("Build:     %s (%s), %s\r\n", REDIVIVUS_BUILD_ID, BUILD_KIND, "gcc " __VERSION__);
    typedef LONG (WINAPI *RtlGetVersionFn)(OSVERSIONINFOW*);
    RtlGetVersionFn pfnGetVersion =
        (RtlGetVersionFn)(void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "RtlGetVersion");
    OSVERSIONINFOW ovi;
    memset(&ovi, 0, sizeof(ovi));
    ovi.dwOSVersionInfoSize = sizeof(ovi);
    if (pfnGetVersion && pfnGetVersion(&ovi) == 0)
        Out("Windows:   %lu.%lu.%lu\r\n", (unsigned long)ovi.dwMajorVersion,
            (unsigned long)ovi.dwMinorVersion, (unsigned long)ovi.dwBuildNumber);
    // Wine announces itself through an ntdll export real Windows does not have.
    typedef const char* (CDECL *WineVersionFn)(void);
    WineVersionFn pfnWine =
        (WineVersionFn)(void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "wine_get_version");
    if (pfnWine) Out("Wine:      %s\r\n", pfnWine());
    Out("Exe:       %s\r\n", g_szExePath);
    Out("Time:      %04u-%02u-%02u %02u:%02u:%02u  thread %lu\r\n", st.wYear, st.wMonth,
        st.wDay, st.wHour, st.wMinute, st.wSecond, (unsigned long)dwThreadId);

    char szWhere[MAX_PATH + 40];
    ModuleOffset((DWORD)(UINT_PTR)pRec->ExceptionAddress, szWhere);
    Out("\r\nException: %08lX %s\r\n", (unsigned long)pRec->ExceptionCode,
        FatalName(pRec->ExceptionCode));
    Out("At:        %s  (%08lX)\r\n", szWhere, (unsigned long)(UINT_PTR)pRec->ExceptionAddress);
    if ((pRec->ExceptionCode == 0xC0000005 || pRec->ExceptionCode == 0xC0000006) &&
        pRec->NumberParameters >= 2) {
        ULONG_PTR uOp = pRec->ExceptionInformation[0];
        const char* pszOp = uOp == 0 ? "read of" : uOp == 1 ? "write to" : uOp == 8 ? "execute at" : "access to";
        Out("Access:    %s %08lX\r\n", pszOp, (unsigned long)pRec->ExceptionInformation[1]);
    }
    if (bForeign)
        Out("Note:      the fault is inside another module, reported at first chance; "
            "if the game kept running, that module handled it.\r\n");

    Out("\r\nRegisters:\r\n");
    Out("  EAX=%08lX EBX=%08lX ECX=%08lX EDX=%08lX\r\n", (unsigned long)pCtx->Eax,
        (unsigned long)pCtx->Ebx, (unsigned long)pCtx->Ecx, (unsigned long)pCtx->Edx);
    Out("  ESI=%08lX EDI=%08lX EBP=%08lX ESP=%08lX\r\n", (unsigned long)pCtx->Esi,
        (unsigned long)pCtx->Edi, (unsigned long)pCtx->Ebp, (unsigned long)pCtx->Esp);
    Out("  EIP=%08lX EFL=%08lX\r\n", (unsigned long)pCtx->Eip, (unsigned long)pCtx->EFlags);

    Out("\r\nStack (fault, then the EBP chain; \"scan\" = return address found on the stack):\r\n");
    // Flush what is known so far: the worker can hang on a lock the crash left held.
    FlushFileBuffers(g_hFile);
    g_nSym = 0;
    g_szSym[0] = 0;
    HANDLE hThread = CreateThread(0, 4 << 20, SymbolizeThread, 0, 0, 0);
    bool bDone = hThread && WaitForSingleObject(hThread, 60000) == WAIT_OBJECT_0;
    if (hThread) CloseHandle(hThread);
    if (bDone) {
        DWORD dwWritten;
        WriteFile(g_hFile, g_szSym, (DWORD)g_nSym, &dwWritten, 0);
    } else {
        Out("  (symbolisation did not finish; addresses only)\r\n");
        for (int i = 0; i < g_nFrames; ++i) {
            char szMod[MAX_PATH + 40];
            ModuleOffset(g_aFrames[i].dwAddr, szMod);
            Out("  #%-2d %s\r\n", i, szMod);
        }
    }
    if (g_szBtErrors[0]) Out("\r\nSymbol lookup problems:\r\n%s", g_szBtErrors);
    if (!g_pBtState) Out("\r\nSymbol lookup unavailable: no libbacktrace state.\r\n");

    WriteModules();
    FlushFileBuffers(g_hFile);
    CloseHandle(g_hFile);
    g_hFile = INVALID_HANDLE_VALUE;
}

// A stack overflow leaves the faulting thread only the reserved guarantee, too
// little for file and module APIs, so the report is written from a fresh thread.
struct ReportJob {
    EXCEPTION_POINTERS* pExc;
    bool bForeign;
    DWORD dwThreadId;
};

DWORD WINAPI ReportThread(LPVOID pParam) {
    ReportJob* pJob = (ReportJob*)pParam;
    WriteReport(pJob->pExc, pJob->bForeign, pJob->dwThreadId);
    return 0;
}

// One report per process for a fault in our own code, and separately at most one
// for a fault inside another module, so a DLL that faults and recovers on its own
// cannot use up the report a later real crash needs.
volatile LONG g_nOwnReported = 0;
volatile LONG g_nForeignReported = 0;
volatile LONG g_nBusy = 0;

LONG CALLBACK CrashVectoredHandler(EXCEPTION_POINTERS* pExc) {
    DWORD dwCode = pExc->ExceptionRecord->ExceptionCode;
    if (!FatalName(dwCode)) return EXCEPTION_CONTINUE_SEARCH;
    // A fault while a report is being written (on any thread) is left alone.
    if (InterlockedCompareExchange(&g_nBusy, 1, 0) != 0) return EXCEPTION_CONTINUE_SEARCH;

    DWORD dwAddr = (DWORD)(UINT_PTR)pExc->ExceptionRecord->ExceptionAddress;
    HMODULE hMod = 0;
    bool bInModule = GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                                        GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                                        (LPCSTR)(UINT_PTR)dwAddr, &hMod) != 0;
    bool bForeign = bInModule && (DWORD)(UINT_PTR)hMod != g_dwExeLo;

    CollectFrames(pExc->ContextRecord);
    bool bReport;
    if (!bForeign) {
        bReport = InterlockedExchange(&g_nOwnReported, 1) == 0;
    } else {
        // A fault in another module counts only when our code is on the stack:
        // a driver or overlay thread faulting on its own is not our crash.
        bool bOursOnStack = false;
        for (int i = 1; i < g_nFrames; ++i)
            if (g_aFrames[i].dwAddr >= g_dwExeLo && g_aFrames[i].dwAddr < g_dwExeHi)
                bOursOnStack = true;
        bReport = bOursOnStack && InterlockedExchange(&g_nForeignReported, 1) == 0;
    }
    if (bReport) {
        static ReportJob s_job;
        s_job.pExc = pExc;
        s_job.bForeign = bForeign;
        s_job.dwThreadId = GetCurrentThreadId();
        HANDLE hThread = 0;
        if (dwCode == 0xC00000FD)
            hThread = CreateThread(0, 1 << 20, ReportThread, &s_job, 0, 0);
        if (hThread) {
            WaitForSingleObject(hThread, 90000);
            CloseHandle(hThread);
        } else {
            ReportThread(&s_job);
        }
    }
    InterlockedExchange(&g_nBusy, 0);
    // The game's own handling (Fog's crash dialog) still runs.
    return EXCEPTION_CONTINUE_SEARCH;
}

// Priority 140: ahead of the static-init runner at 200 and the trace handler at
// 150, so a fault in one of the game's own constructors is reported.
struct CrashInit {
    CrashInit() {
        DWORD n = GetModuleFileNameA(0, g_szExePath, MAX_PATH);
        if (n == 0 || n >= MAX_PATH) g_szExePath[0] = 0;
        HMODULE hExe = GetModuleHandleA(0);
        g_dwExeLo = (DWORD)(UINT_PTR)hExe;
        const IMAGE_NT_HEADERS* pNt =
            (const IMAGE_NT_HEADERS*)((const char*)hExe + ((const IMAGE_DOS_HEADER*)hExe)->e_lfanew);
        g_dwExeHi = g_dwExeLo + pNt->OptionalHeader.SizeOfImage;
        // Cheap: the DWARF itself is parsed on the first lookup, which is a crash.
        if (g_szExePath[0]) g_pBtState = backtrace_create_state(g_szExePath, 0, BtError, 0);
        AddVectoredExceptionHandler(1, CrashVectoredHandler);
        // A stack overflow leaves no room for a handler, so the process dies with no
        // report and the fault looks uncatchable. Reserving a slice keeps the handler
        // runnable; the symbolisation itself runs on a thread with its own stack.
        ULONG ulGuarantee = 64 * 1024;
        SetThreadStackGuarantee(&ulGuarantee);
    }
};
CrashInit g_crashInit __attribute__((init_priority(140)));

}  // namespace
