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
 *	Name: ctrans.cpp
 *	
 * 	Purpose: Definitions of Sprite class interface(s) and methods for the 
 *           Transition Xtra skeleton project.
 *
 *
 *  HOW TO CUSTOMIZE THIS FILE
 *  --------------------------
 *  1. Save this file under a different file name.
 *  2. Use a search and replace utility (case sensitive) to replace the
 *     following:
 *
 *     Replace         With	
 *     -------         ----
 *     ctrans          <this file name>
 *     CTransition     <name of the class you defined>
 *
 *  3. Add and modify source code by looking for '--> insert -->' comment
 ****************************************************************************/ 

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .cpp file should automatically include all the support files needed
 *	for this particular class. In addition, this file may include other .h
 *	files defining additional callback interfaces for use by a third party.   
 ****************************************************************************/ 
#ifndef _H_ctrans
	#include "ctrans.h"
#endif

#ifdef MACINTOSH
	#include <QuickDraw.h>
#endif

#include <String.h>
  
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
BEGIN_DEFINE_CLASS_INTERFACE(CTransition, IMoaMmXTransitionActor)
END_DEFINE_CLASS_INTERFACE

/*
 * --> insert additional interface(s) -->
 */ 

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

/* -------------------------------------------------- MoaCreate_CTransition */
STDMETHODIMP MoaCreate_CTransition(CTransition FAR * This)
{
	UNUSED(This);
	X_ENTER

	/* variable declarations */
	MoaError err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */

	X_STD_RETURN(err);	
	X_EXIT
}

/* ------------------------------------------------- MoaDestroy_CTransition */
STDMETHODIMP_(void) MoaDestroy_CTransition(CTransition FAR * This)
{
	UNUSED(This);
	X_ENTER
		
	/*
	 * --> insert additional code -->
	 */

	X_RETURN_VOID;
	X_EXIT
}

/* ---------------------- CTransition_IMoaMmXTransitionActor Create/Destroy */
CTransition_IMoaMmXTransitionActor::CTransition_IMoaMmXTransitionActor(MoaError FAR * pErr)
	{ *pErr = (kMoaErr_NoErr); }
CTransition_IMoaMmXTransitionActor::~CTransition_IMoaMmXTransitionActor() {}

/*
 * --> insert additional create/destroy method(s) -->
 */

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

/* ----------------------------- CTransition_IMoaMmXTransitionActor::Notify */
/* This method is intended for communicating between the asset and its xtras.
   The developer is free to define message codes for private use.  This may be
   called directly by an asset, or through the 
   IMoaMmAssetCallback::NotifyAllSprites() callback. */
STDMETHODIMP CTransition_IMoaMmXTransitionActor::Notify(MoaLong msgCode, PMoaVoid refCon)
{
	UNUSED(msgCode);
	UNUSED(refCon);
	X_ENTER

	/* variable declarations */
	MoaError err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}

/* -------------------------------- CTransition_IMoaMmXTransitionActor::Cue */
STDMETHODIMP CTransition_IMoaMmXTransitionActor::Cue(PIMoaMmGC pDestGC, PIMoaMmGC pSrcGC, ConstPMoaRect pRect, ConstPMoaMmTransInfo pTransInfo)
{
	UNUSED(pDestGC);
	UNUSED(pSrcGC);
	UNUSED(pRect);
	UNUSED(pTransInfo);
	X_ENTER

	/* variable declarations */
	MoaError err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */
	
	X_STD_RETURN(err);
	X_EXIT
}
	
/* --------------------------- CTransition_IMoaMmXTransitionActor::Continue */
/* Try not to implement your transition to do it all in one big step.  By
   incrementing your change over many calls to Continue(), the results of the
   transition can be exported. */
STDMETHODIMP CTransition_IMoaMmXTransitionActor::Continue(PIMoaMmGC pDestGC, PIMoaMmGC pSrcGC, ConstPMoaRect pRect, ConstPMoaMmTransInfo pTransInfo, MoaBoolParam FAR * pFinished)
{
	UNUSED(pDestGC);
	UNUSED(pSrcGC);
	UNUSED(pRect);
	UNUSED(pTransInfo);
	UNUSED(pFinished);
	X_ENTER

	/* variable declarations */
  MoaError err = kMoaErr_NoErr;
	
	/*
	 * --> insert additional code -->
	 */

	X_STD_RETURN(err);
	X_EXIT
}
	
/* ----------------------------- CTransition_IMoaMmXTransitionActor::Finish */
STDMETHODIMP CTransition_IMoaMmXTransitionActor::Finish(PIMoaMmGC pDestGC, PIMoaMmGC pSrcGC, ConstPMoaRect pRect, ConstPMoaMmTransInfo pTransInfo)
{
	UNUSED(pDestGC);
	UNUSED(pSrcGC);
	UNUSED(pRect);
	UNUSED(pTransInfo);
	X_ENTER

	/* variable declarations */
	MoaError	err = kMoaErr_NoErr;

	/*
	 * --> insert additional code -->
	 */

	X_STD_RETURN(err);
	X_EXIT
}

