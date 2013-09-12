// ***************************************************************
//  version.h   version:  1.0   ¡¤  date: 04/14/2008
//  -------------------------------------------------------------
//  This file records the version number of this module.
//
//  The format is as 1.1.r31.b64
//  1.1    is the project version, the major version increases when 
//         the product have important upgrade, the minor version 
//         increases when the product have new features.
//  R31    is the Source code reversion on subversion, whenever the 
//         code of the project changes it increases.
//  B64    is the build number of release build on the build server 
//         for the release package of this project, it always increases.

//  -------------------------------------------------------------
//  Copyright (C) Cidana 2008 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************

#ifndef _VERSION_H
#define _VERSION_H

#ifdef __linux__
#define _T(a) a
#define TCHAR char
#endif

#define CI_MAJOR_VERSION_NUMBER_	_T("1")
#define CI_MINOR_VERSION_NUMBER_	_T("0")
#define CI_RELEASE_VERSION_NUMBER_	_T("0")
#define CI_BUILD_VERSION_NUMBER_	_T("1")
#define CI_VERSION_STRING_	CI_MAJOR_VERSION_NUMBER_ _T(".") CI_MINOR_VERSION_NUMBER_ _T(".")\
	CI_RELEASE_VERSION_NUMBER_ _T(".") CI_BUILD_VERSION_NUMBER_ 

#define CI_VERSION_INT_ 1,0,0,1

#endif //_VERSION_H

