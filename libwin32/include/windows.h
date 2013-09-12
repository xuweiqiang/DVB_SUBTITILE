//=============================================================================
//	THIS SOURCE CODE IS PROPRIETARY INFORMATION BELONGING TO INTERVIDEO, INC.
// 	ANY USE INCLUDING BUT NOT LIMITED TO COPYING OF CODE, CONCEPTS, AND/OR
//	ALGORITHMS IS PROHIBITED EXCEPT WITH EXPRESS WRITTEN PERMISSION BY THE
//	COMPANY.
//
// 	THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// 	KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// 	IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
// 	PURPOSE.
//
// 	Copyright (c) 2004 - 2005  InterVideo Corporation.  All Rights Reserved.
//
//-----------------------------------------------------------------------------
// Emacs -*- mode: C++ -*-

#ifndef _WINDOWS_H
#define _WINDOWS_H

#include "wincompat.h" // defines Microsoft compiler builtins

#ifdef __cplusplus
extern "C" {
#endif

#ifdef RH_70
#define __restrict
#define _G_fpos64_t _G_off64_t
#endif // RH_70

#include <unistd.h>       // for open, close, read, lseek
#include <stdio.h>
#include <string.h>
#include <stdlib.h>   // for getenv, setenv
#include <errno.h>    // for error enumerations
#include <fcntl.h>    // for O_RDONLY
#include <time.h>     // for nanosleep
#include <sys/time.h> // for struct timeval
#include <sys/stat.h> // for stat
#include <sys/types.h>
#include <dirent.h>


#ifndef __SYMBIAN32__
#include <pthread.h>
#ifdef __linux__
#include <linux/unistd.h> // for llseek
#include <malloc.h>       // for memalign, valloc
#endif
#ifdef __APPLE__
#include <unistd.h>
#include <malloc/malloc.h>
#endif
#endif

#include "windef.h"    // windows header for basic Windows type definitions
#include "winbase.h"   // windows header for Win32 Base APIs
#include "winuser.h"   // windows header for USER proc declarations and macros
#include "winreg.h"    // windows 32-bit registry API
#include "winerror.h"  // windows header for COM and Windows errors
#include "basetyps.h"  // windows header for GUID stuff
#include "tchar.h"     // windows header for UNICODE
#include "wtypes.h"    // windows header for basic Windows data types
#include "crtdbg.h"    // windows header for assert macros
#include "unknwn.h"    // windows header for IUnknown interfaces
#include "mmsystem.h"  // windows header for multimedia APIs
#include "ole2.h"      // windows header for OLE2 (IsEqualGUID, CoInitialize)
#include "winnls.h"    // windows header for i18n/wide characters
#include "wingdi.h"    // windows header for graphics device/bitmap definitions

// Misc

#ifndef stricmp
#define stricmp strcasecmp
#define strnicmp strncasecmp
#endif
#define _strdup strdup
#define _strnicmp strnicmp

#ifndef Window
typedef unsigned long Window;
#endif

#if 0
#if !defined(USE_TAKARA) && !defined(USE_DVR) && !defined(__SYMBIAN32__)
static inline size_t wcslen(const wchar_t* string)
{
	return strlen((const char*)string);
}
#endif
#endif

static char* _strupr(char* string);
static char* _strlwr(char* string);
    

// From winbase.h

UINT GetSystemDirectory(LPSTR lpBuffer, UINT uSize);
static DWORD GetEnvironmentVariable(
                                 LPCTSTR lpName,  // address of environment variable name
                                 LPTSTR lpBuffer, // address of buffer for variable value
                                 DWORD nSize      // size of buffer, in characters
                                 );
BOOL SetEnvironmentVariable(
                                LPCTSTR lpName,  // address of environment variable name
                                LPCTSTR lpValue  // address of new value for variable
                                );

    
#define INVALID_FILE_ATTRIBUTES ((DWORD)-1)
    
DWORD GetFileAttributes(LPCTSTR lpFileName);

// CRT library

char* _strdate(char* datestr);
char* _strtime(char* timestr);

//
// the following five functions should be defined by the user application.
// they should not be defined in LIBWIN32.
//

int     MessageBox (HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType);
BOOL    PostMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT SendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL    GetClientRect (HWND hWnd, LPRECT lpRect);
BOOL    ClientToScreen(HWND hWnd, LPPOINT lpPoint);


#ifdef __GNUG__
void OutputDebugString(char *szBuffer)  __attribute__((weak));  /* overridable by app */
#else
void OutputDebugString(char *szBuffer);
#endif //__GNUG__

static void DBP(char *szFormat, ...);

#if  defined(__x86_64__) || defined(ANDROID) || defined(__linux__)
#define _lseeki64 lseek64
#else
#if !defined(MSASM) && !defined(__APPLE__) // we can remove this checking after porting _lseeki64 compiled by ICC with msasm option
#ifndef __SYMBIAN32__
static _syscall5(int,  _llseek,  uint,  fd, ulong, hi, ulong, lo,
						loff_t *, res, uint, wh);

static long long _lseeki64(int handle, unsigned long long offset,
                        int origin);

#endif
#endif
#endif

#if __GNUC__ < 5
#define _mm_malloc(size, alignment)      _aligned_malloc(size,alignment)
#define _mm_free(ptr)                    _aligned_free(ptr)
#define _aligned_malloc(size, alignment) memalign(alignment, size)
#define _aligned_free(ptr)               free(ptr)
#else
#include <mm_malloc.h>
#endif

// Critical sections, implemented using mutex

#ifndef __SYMBIAN32__
typedef struct tagCRITICAL_SECTION {
  pthread_mutex_t     _mutex;
  pthread_mutexattr_t _mutexattr;
} CRITICAL_SECTION, *LPCRITICAL_SECTION;


VOID InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection) ;

VOID DeleteCriticalSection    (LPCRITICAL_SECTION lpCriticalSection) ;

VOID EnterCriticalSection     (LPCRITICAL_SECTION lpCriticalSection);
    
BOOL TryEnterCriticalSection     (LPCRITICAL_SECTION lpCriticalSection) ;

VOID LeaveCriticalSection     (LPCRITICAL_SECTION lpCriticalSection) ;
#else
/* SYMBIANOS */
#ifdef __cplusplus
typedef struct tagCRITICAL_SECTION {
  RCriticalSection _cs;
  RCriticalSection _cslck;
  TThreadId  _id;
  int _lockcount;
} CRITICAL_SECTION, *LPCRITICAL_SECTION;

VOID InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
VOID DeleteCriticalSection    (LPCRITICAL_SECTION lpCriticalSection);
VOID EnterCriticalSection     (LPCRITICAL_SECTION lpCriticalSection);
VOID LeaveCriticalSection     (LPCRITICAL_SECTION lpCriticalSection);

#endif  /* __cplusplus */
#endif  /* __SYMBIAN32__ */

// VirtualAlloc/VirtualFree - used to allocate page-aligned buffers
// to reduce unnecessary copying

#define MEM_COMMIT           0x1000
#define MEM_RESERVE          0x2000
#define MEM_RELEASE          0x8000

static void CopyMemory(PVOID Destination, CONST VOID *Source, SIZE_T Length);

static LPVOID VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize,
                    DWORD flAllocationType, DWORD flProtect) ;

static LPVOID VirtualFree (LPVOID lpAddress, SIZE_T dwSize,
                    DWORD dwFreeType) ;

#define _sleep sleep

#ifdef __SYMBIAN32__
#ifdef __cplusplus
static VOID Sleep(DWORD dwMilliseconds);
#endif
#else
VOID Sleep(DWORD dwMilliseconds);
#endif

VOID ZeroMemory(LPVOID Destination, SIZE_T Length);
    

static BOOL SetRect(
  LPRECT lprc, // rectangle
  int xLeft,   // left side
  int yTop,    // top side
  int xRight,  // right side
  int yBottom  // bottom side
             );


static BOOL IntersectRect(
  LPRECT lprcDst,        // intersection buffer
  CONST RECT *lprcSrc1,  // first rectangle
  CONST RECT *lprcSrc2   // second rectangle
                   );


static BOOL UnionRect(
  LPRECT lprcDst,        // destination rectangle
  CONST RECT *lprcSrc1,  // first rectangle
  CONST RECT *lprcSrc2   // second rectangle
               );


static BOOL EqualRect(
  CONST RECT *lprc1,  // first rectangle
  CONST RECT *lprc2   // second rectangle
               );


static BOOL OffsetRect(
  LPRECT lprc,  // rectangle
  int dx,       // horizontal offset
  int dy        // vertical offset
                              );


static BOOL IsRectEmpty(CONST RECT *lprc);
	

static BOOL PtInRect(CONST RECT *lprc, POINT pt);


#define CLR_INVALID -1


// these ones are really lame!
#define _open   open
#define _read   read
#define _close  close
#define _lseek  lseek
#define _stat   stat
#define _stati64  stat
#define _fstati64 fstat
#define _O_RDONLY O_RDONLY
#define _O_BINARY O_BINARY
#define _O_RDWR   O_RDWR
#define _O_CREAT  O_CREAT
#define _O_TRUNC  O_TRUNC
#define _S_IREAD  S_IRUSR|S_IRGRP|S_IROTH
#define _S_IWRITE S_IWUSR|S_IWGRP|S_IWOTH

static int _fileno(FILE *f) ;

DWORD GetTickCount(void) ;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID);

    
BOOL WINAPI GetDiskFreeSpaceEx(
                                     LPCTSTR lpDirectoryName,
                                    PULARGE_INTEGER lpFreeBytesAvailable,
                                    PULARGE_INTEGER lpTotalNumberOfBytes,
                                    PULARGE_INTEGER lpTotalNumberOfFreeBytes
                                );
    
#define ERROR_INVALID -1

#ifdef __cplusplus
}  /* end extern "C" */
#endif

#endif /* _WINDOWS_H */
