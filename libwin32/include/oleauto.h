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
// not part of standard WIN32 API - is this file still being used somewhere?

#ifndef OLEAUTO_H_
#define OLEAUTO_H_

static BSTR SysAllocString(const char * copyThis);

static VOID SysFreeString( BSTR bstr );

static BSTR SysAllocStringByteLen( LPCSTR psz, unsigned int len  );

static UINT SysStringByteLen( BSTR bstr  );

static UINT SysStringLen( BSTR bstr  );

#endif
