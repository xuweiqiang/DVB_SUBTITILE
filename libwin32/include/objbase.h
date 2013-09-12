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

#ifndef _OBJBASE_H
#define _OBJBASE_H

#ifdef __cplusplus
BOOL  IsEqualGUID(REFGUID rguid1, REFGUID rguid2);

BOOL operator==(const GUID& guidOne, const GUID& guidOther);


BOOL operator!=(const GUID& guidOne, const GUID& guidOther);

#endif

typedef enum tagCOINIT
{
	COINIT_MULTITHREADED = 0x0
}COINIT;
/****** STD Object API Prototypes *****************************************/
HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
HRESULT CoInitialize(LPVOID pvReserved);
HRESULT CoUninitialize();

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv);

/****** Default Memory Allocation ******************************************/
static void *CoTaskMemAlloc(ULONG cb) ;
static void  CoTaskMemFree(void* pv)  ;

#endif /* _OBJBASE_H */
