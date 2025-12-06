/*****************************************************************************
 * Copyright © 1994-1999 Macromedia, Inc.  All Rights Reserved
 *
 * You may utilize this source file to create and compile object code for use 
 * within products you create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
 * WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
 * INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
 * FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
 * USE OR INABILITY TO USE THIS CODE.
 *
 *	Name: xtra.cpp
 *
 ****************************************************************************/ 

///////////////////////////////////////////////////////////////////////////////
//
// Notes on project settings:
//
// - Turn on Enable C++ exceptions.
// * Make sure to set the CFM initialization entry point to __initialize
// * Make sure to set the CFM termination entry point to __terminate
//
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////

// Important!  This define controls the GUID definitions.  Turning this define 
// on causes the GUID to be declared.  Without this define turned on in this
// file you will get link errors against the GUID for the interfaces you are using.
// You need to add the headers to this file to get those linker errors to go away.
#define INITGUID

#include "Asset.h"
#include "Sprite.h"
#include "Dialog.h"
#undef INITGUID
// see that wasn't so hard now was it...

// this is for the version macros below.
#include "xclassver.h"

///////////////////////////////////////////////////////////////////////////////
//
// Xtra Version defines -- define your class version, start with 1 0 0 as below
//
///////////////////////////////////////////////////////////////////////////////
#define XTRA_MAJOR_VERSION    1
#define XTRA_MINOR_VERSION    0
#define XTRA_SUB_VERSION      1	
#define XTRA_RELEASE          VERSION_DEVELOPMENT
#define XTRA_RELEASE_VERSION  1
 
#define XTRA_VERSION_NUMBER MAKE_VERSION(XTRA_MAJOR_VERSION, \
                                         XTRA_MINOR_VERSION, \
                                         XTRA_SUB_VERSION, \
                                         XTRA_RELEASE_VERSION, \
                                         XTRA_RELEASE)


///////////////////////////////////////////////////////////////////////////////
//
// Xtra definition -- any classes you bundle in this Xtra are declared here!
//
///////////////////////////////////////////////////////////////////////////////

 BEGIN_XTRA
 	BEGIN_XTRA_DEFINES_CLASS(CWackyDlgAsset, XTRA_CLASS_VERSION)
 		CLASS_DEFINES_INTERFACE(CWackyDlgAsset, IMoaMmXAsset, XTRA_VERSION_NUMBER)
	END_XTRA_DEFINES_CLASS

	BEGIN_XTRA_DEFINES_CLASS(CWackyDlgSprite, XTRA_CLASS_VERSION)
 		CLASS_DEFINES_INTERFACE(CWackyDlgSprite, IMoaMmXSpriteActor, XTRA_VERSION_NUMBER)
	END_XTRA_DEFINES_CLASS

	BEGIN_XTRA_DEFINES_CLASS(CWackyDlgRegister, XTRA_CLASS_VERSION)
 		CLASS_DEFINES_INTERFACE(CWackyDlgRegister, IMoaRegister, XTRA_VERSION_NUMBER)
	END_XTRA_DEFINES_CLASS
 END_XTRA

// EOF
