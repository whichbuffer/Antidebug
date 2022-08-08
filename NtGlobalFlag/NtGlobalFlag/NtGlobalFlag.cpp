#include <cinttypes>
#include <Windows.h>
#include "antidebug.h"

#define SHOW_DEBUG_MESSAGES

void DBG_MSG(WORD dbg_code, const char* message)
{
#ifdef SHOW_DEBUG_MESSAGES
    printf("[MSG-0x%X]: %s\n", dbg_code, message);
    MessageBoxA(NULL, message, "GAME OVER!", 0);
#endif
}


/*
 * Want to inspect the value of something in the PEB? Launch WinDBG,
 * Attach to, or launch a process and run this command:
 * dt ntdll!_PEB @$peb -r
 * Want more info on NtGlobalFlag? See these resources:
 * https://www.aldeid.com/wiki/PEB-Process-Environment-Block/NtGlobalFlag
 * https://www.geoffchappell.com/studies/windows/win32/ntdll/api/rtl/regutil/getntglobalflags.htm
 */
void NtGlobalFlag(void)
{
    BOOL found = FALSE;

#ifdef _WIN64
    found = NtGlobalFlagx64();
#else
    _asm
    {
        xor eax, eax;			// clear eax
        mov eax, fs: [0x30] ;	// Reference start of the PEB
        mov eax, [eax + 0x68];	// PEB+0x68 points to NtGlobalFlag
        and eax, 0x00000070;	// check three flags:
                                //   FLG_HEAP_ENABLE_TAIL_CHECK   (0x10)
                                //   FLG_HEAP_ENABLE_FREE_CHECK   (0x20)
                                //   FLG_HEAP_VALIDATE_PARAMETERS (0x40)
        mov found, eax;			// Copy result into 'found'
    }
#endif

    if (found)
    {
        DBG_MSG(DBG_NTGLOBALFLAGPEB, "Caught by NtGlobalFlag check!");
        exit(DBG_NTGLOBALFLAGPEB);
    }
}

