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
// DirectX SDK

#ifndef AMFILTER_H_
#define AMFILTER_H_
#include <windows.h>

class IMediaSample
{};
class IMemAllocator
{};

#define ALLOCATOR_PROPERTIES DWORD
#define UNITS 1000000

class IAsyncReader
{
public:
HRESULT Length(  LONGLONG *pTotal, LONGLONG *pAvailable               );
    HRESULT BeginFlush(void);
    HRESULT EndFlush(void);
HRESULT SyncReadAligned(  IMediaSample *pSample                 );
HRESULT WaitForNext(
DWORD dwTimeout,
IMediaSample **ppSample,
DWORD *pdwUser
                    );
HRESULT Request(
IMediaSample *pSample,
DWORD dwUser
                );
HRESULT RequestAllocator(
IMemAllocator *pPreferred,
ALLOCATOR_PROPERTIES *pProps,
IMemAllocator **ppActual
                         );
HRESULT SyncRead(
LONGLONG llPosition,
LONG lLength,
BYTE *pBuffer
                 );

};

#define TDMX_SYNC 1

#endif

