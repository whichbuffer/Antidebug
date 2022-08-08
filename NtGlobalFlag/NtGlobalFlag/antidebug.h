#pragma once
#include <cinttypes>
#include <Windows.h>
#include <Winternl.h>
#include <stdio.h>
#include <Tlhelp32.h>
// Error Codes
enum DBG_CATCH
{
	DBG_NONE = 0x0000,

	// Memory Codes (0x1000 range)
	DBG_BEINGEBUGGEDPEB = 0x1000,
	DBG_CHECKREMOTEDEBUGGERPRESENT = 0x1001,
	DBG_ISDEBUGGERPRESENT = 0x1002,
	DBG_NTGLOBALFLAGPEB = 0x1003,
	DBG_NTQUERYINFORMATIONPROCESS = 0x1004,
	DBG_FINDWINDOW = 0x1005,
	DBG_OUTPUTDEBUGSTRING = 0x1006,
	DBG_NTSETINFORMATIONTHREAD = 0x1007,
	DBG_DEBUGACTIVEPROCESS = 0x1008,
	DBG_PROCESSFILENAME = 0x1009,

	// CPU Codes (0x2000 range)
	DBG_HARDWAREDEBUGREGISTERS = 0x2000,
	DBG_MOVSS = 0x2001,

	// Timing Codes (0x3000 range)
	DBG_RDTSC = 0x3000,
	DBG_QUERYPERFORMANCECOUNTER = 0x3001,
	DBG_GETTICKCOUNT = 0x3002,

	// Exception Codes (0x4000 range)
	DBG_CLOSEHANDLEEXCEPTION = 0x4000,
	DBG_SINGLESTEPEXCEPTION = 0x4001,
	DBG_INT3CC = 0x4002,
	DBG_PREFIXHOP = 0x4003,
};

// Debugging messages
void DBG_MSG(WORD dbg_code, char* message);


#ifdef _WIN64
extern "C"
{
	int NtGlobalFlagx64(void);
};
#endif

// Memory

void NtGlobalFlag(void);
