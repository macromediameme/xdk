/*****************************************************************************
 * Copyright © 1994-1996 Macromedia, Inc.  All Rights Reserved
 *
 * You may utilize this source file to create and compile object code for use 
 * within products you create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
 * WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
 * INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
 * FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
 * USE OR INABILITY TO USE THIS CODE.
 *
 *	Name: GInterro.cpp
 *	
 * 	Purpose: Definitions of Interrogator class interface(s) and methods for
 *           the Greeting Xtra project.
 *
 *
 ****************************************************************************/ 

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .cpp file should automatically include all the support files needed
 *	for this particular class. In addition, this file may include other .h
 *	files defining additional callback interfaces for use by a third party.   
 ****************************************************************************/ 
#ifndef _H_cinterro
	#include "GInterro.h"
#endif


/*****************************************************************************
 *  INTERNAL PROTOTYPES(S)
 *  ----------------------
 *  Declarations for functions used specifically in this file.
 ****************************************************************************/

/*****************************************************************************
 *  INTERNAL ROUTINE(S)
 *  -------------------
 *  Definition of file-specific functions
 ****************************************************************************/

/*****************************************************************************
 *  CLASS INTERFACE(S)
 *  ------------------
 *  The interface(s) implemented by your MOA class are specified here.  Note
 *	that at least one class in your Xtra should implement the IMoaRegister
 *	interface.
 *  NOTE: Because C++ does not use a lpVtbl to reference an interface's
 *	methods, the actual method declaration is done in the .h file.
 *
 *  Syntax:
 *  BEGIN_DEFINE_CLASS_INTERFACE(<class-name>, <interface-name>) 
 ****************************************************************************/ 
BEGIN_DEFINE_CLASS_INTERFACE(CInterrogator, IMoaMmInterrogator)
END_DEFINE_CLASS_INTERFACE

BEGIN_DEFINE_CLASS_INTERFACE(CInterrogator, IMoaMmTerminator)
END_DEFINE_CLASS_INTERFACE

#ifdef USING_INIT_FROM_DICT
BEGIN_DEFINE_CLASS_INTERFACE(CInterrogator, IMoaInitFromDict)
END_DEFINE_CLASS_INTERFACE
#endif

#ifdef USING_NOTIFICATION_CLIENT
BEGIN_DEFINE_CLASS_INTERFACE(CInterrogator, IMoaNotificationClient)
END_DEFINE_CLASS_INTERFACE
#endif


/*****************************************************************************
 *  CREATE AND DESTROY METHODS
 *  --------------------------
 *  Every interface and class has an associated 'Create' and 'Destroy' pair.
 *  'Create' methods are typically used to acquire interface(s), allocate 
 *  memory, and intialize variables. 'Destroy' methods are typically used to 
 *  release interfaces and free memory.
 *
 * NOTE:  In C++, the local variable 'This' is provided implicitly within 
 * a method implementation.  Thus, there is no need explicitly declare 'This' 
 * as a function parameter. However, this implementation detail doesn’t apply 
 * to the MOA class creator and destructor functions, which are standard C 
 * functions, coded exactly as in like they are in C examples.  
 *
 * Class Syntax:
 * STDMETHODIMP MoaCreate_<class-name>(<class-name> FAR * This)
 * STDMETHODIMP MoaDestroy_<class-name>(<class-name> FAR * This)
 *
 * Interface Syntax:
 * <class_name>_<if_name>::<class_name>_<if_name>(MoaError FAR * pErr)
 * <class_name>_<if_name>::~<class_name>_<if_name>()
 ****************************************************************************/ 

/* ------------------------------------------------ MoaCreate_CInterrogator */
STDMETHODIMP MoaCreate_CInterrogator(CInterrogator FAR * This)
{
	UNUSED(This);
	X_ENTER

	/* variable declarations */
	MoaError err = kMoaErr_NoErr;

	X_RETURN(MoaError, err);
	X_EXIT
}

/* ----------------------------------------------- MoaDestroy_CInterrogator */
STDMETHODIMP_(void) MoaDestroy_CInterrogator(CInterrogator FAR * This)
{
	UNUSED(This);
	X_ENTER

	X_EXIT
}

/* ------------------------ CInterrogator_IMoaMmInterrogator Create/Destroy */
CInterrogator_IMoaMmInterrogator::CInterrogator_IMoaMmInterrogator(MoaError FAR * pErr)
	{ *pErr = (kMoaErr_NoErr); }
CInterrogator_IMoaMmInterrogator::~CInterrogator_IMoaMmInterrogator() {}

/* -------------------------- CInterrogator_IMoaMmTerminator Create/Destroy */
CInterrogator_IMoaMmTerminator::CInterrogator_IMoaMmTerminator(MoaError FAR * pErr)
	{ *pErr = (kMoaErr_NoErr); }
CInterrogator_IMoaMmTerminator::~CInterrogator_IMoaMmTerminator() {}

#ifdef USING_INIT_FROM_DICT
/* -------------------------- CInterrogator_IMoaInitFromDict Create/Destroy */
CInterrogator_IMoaInitFromDict::CInterrogator_IMoaInitFromDict(MoaError FAR * pErr)
	{ *pErr = (kMoaErr_NoErr); }
CInterrogator_IMoaInitFromDict::~CInterrogator_IMoaInitFromDict() {}
#endif

#ifdef USING_NOTIFICATION_CLIENT
/* -------------------- CInterrogator_IMoaNotificationClient Create/Destroy */
CInterrogator_IMoaNotificationClient::CInterrogator_IMoaNotificationClient(MoaError FAR * pErr)
	{ *pErr = (kMoaErr_NoErr); }
CInterrogator_IMoaNotificationClient::~CInterrogator_IMoaNotificationClient() {}
#endif


/*****************************************************************************
 *  METHOD IMPLEMENTATION(S)
 *  ------------------------
 *  This is where the methods to be defined by your MOA class are implemented.
 *  The bulk of the work in implementing Xtras is done here.  NOTE: 'This' is 
 *  implemented implicitly in C++, therefore it isn't used in the argument-
 *	list.
 *
 *  Syntax:
 *  STDMETHODIMP <class-name>_<interface-name>::<method-name>(<argument-list>)
 ****************************************************************************/ 

/* -------------------------- CInterrogator_IMoaMmInterrogator::Interrogate */
STDMETHODIMP_(void) CInterrogator_IMoaMmInterrogator::Interrogate()
{
	X_ENTER

		char				message[256], name[32], app[32], version[32];

		PIMuiAlert			pMuiAlert = NULL;
		PIMoaAppInfo		pAppInfo = NULL;
		
		// Get all interfaces and bail if they're not available
		pObj->pCallback->MoaCreateInstance(&CLSID(CMuiAlert), &IID(IMuiAlert), (PPMoaVoid)&pMuiAlert);
		if (!pMuiAlert) 
			goto exit_gracefully;
		pObj->pCallback->QueryInterface(&IID_IMoaAppInfo, (PPMoaVoid)&pAppInfo);
		if (!pAppInfo) 		
			goto exit_gracefully;

		// Assemble our greeting message
		pAppInfo->GetInfo(kMoaAppInfo_UserName, name, 32);
		pAppInfo->GetInfo(kMoaAppInfo_ProductName, app, 32);
		pAppInfo->GetInfo(kMoaAppInfo_ProductVersion, version, 32);
		sprintf(message, "Hello, %s!%s", name, NL);
		sprintf(message, "%sWelcome to %s %s.%s", message, app, version, NL);
		strcat(message, "We hope you enjoy your stay.");
		
		pMuiAlert->Alert(message, "Greetings", kMuiAlertButtons_Ok, 1, kMuiAlertIcon_None);
		
exit_gracefully:

		if (pMuiAlert) pMuiAlert->Release();
		if (pAppInfo) pAppInfo->Release();
		
	X_RETURN_VOID;
	X_EXIT
}

/* ------------------------------ CInterrogator_IMoaMmTerminator::Terminate */
STDMETHODIMP_(void) CInterrogator_IMoaMmTerminator::Terminate()
{
	X_ENTER

	X_RETURN_VOID;
	X_EXIT
}

#ifdef USING_INIT_FROM_DICT
/* --------------------------- CInterrogator_IMoaInitFromDict::InitFromDict */
STDMETHODIMP CInterrogator_IMoaInitFromDict::InitFromDict(PIMoaRegistryEntryDict pRegistryDict)
{
	UNUSED(pRegistryDict);
	X_ENTER
	
	/* variable declarations */
	MoaError err = kMoaErr_NoErr;

						   	
	X_STD_RETURN(err);
	X_EXIT
}
#endif

#ifdef USING_NOTIFICATION_CLIENT
/* --------------------------- CInterrogator_IMoaNotificationClient::Notify */
STDMETHODIMP CInterrogator_IMoaNotificationClient::Notify(ConstPMoaNotifyID nid, PMoaVoid pNData, PMoaVoid pRefCon)
{
	UNUSED(pRefCon);
	X_ENTER
	
	MoaError	err = kMoaErr_NoErr;

	X_STD_RETURN(kMoaErr_NoErr);
	X_EXIT
}

#endif

