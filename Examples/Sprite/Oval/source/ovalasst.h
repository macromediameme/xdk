#ifndef _H_ovalasst
#define _H_ovalasst

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
 *	Name: ovalasst.h
 *	
 * 	Purpose: Declarations of the CLSID, class instance variables, and  
 *           class interface(s) for the Sprite Oval Xtra example Asset class.
 *
 **********************************************************************************/ 

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .h file should automatically include all the support files needed for this 
 *  particular class. In addition, this file may include other .h files defining 
 *  additional callback interfaces for use by a third party.   
 *****************************************************************************/ 
#ifndef _H_MOAXTRA
#include "moaxtra.h"
#endif

#ifndef _H_MMIXASST
#include "mmixasst.h"
#endif

#include "ovalactr.h"

#include "AwiServc.h"

/*****************************************************************************
 *  FILE SPECIFIC DEFINE(S)
 *  -----------------------
 *	Any #define's specific to this file  
 *****************************************************************************/ 
#ifndef COvalSpriteAsset
#define USING_INIT_FROM_DICT
#endif /* COvalSpriteAsset */

/*****************************************************************************
 *  CLSID
 *  -----
 *  The CLSID is a GUID that unquely identifies your MOA class.  To generate a
 *  GUID, use the genUID.app utility (Mac) or the GUIDGEN.EXE utility (Win).
 *****************************************************************************/ 
DEFINE_GUID(CLSID(COvalSpriteAsset), 0xAC404223L, 0x000A, 0x102F, 0x00, 0x00,
	 0x08, 0x00, 0x07, 0x2C, 0x63, 0x26);
	
/*****************************************************************************
 *  CLASS INSTANCE VARIABLES
 *  ------------------------
 *  Class instance variable are variables whose scope is exclusive to the
 *  methods implemented by your MOA class.  Variables necessary for the
 *  implementation of your MOA class should be placed here.
 *****************************************************************************/ 
EXTERN_BEGIN_DEFINE_CLASS_INSTANCE_VARS(COvalSpriteAsset)

EXTERN_END_DEFINE_CLASS_INSTANCE_VARS

/*****************************************************************************
 *  CLASS INTERFACE(S)
 *  ------------------
 *  The interface(s) implemented by your MOA class are specified here.  Note that
 *  at least one class in your Xtra should implement the IMoaRegister interface.
 *  NOTE: Because C++ does not use a lpVtbl to reference an interface's methods, 
 *  the actual method declaration is done here.
 *
 *  Syntax:
 *  EXTERN_BEGIN_DEFINE_CLASS_INTERFACE(<class-name>, <interface-name>) 
 *	EXTERN_DEFINE_METHOD(<return-type>, <method-name>,(<argument-list>)) 
 *****************************************************************************/ 
EXTERN_BEGIN_DEFINE_CLASS_INTERFACE(COvalSpriteAsset, IMoaInitFromDict)
	EXTERN_DEFINE_METHOD(MoaError, InitFromDict, (PIMoaRegistryEntryDict))
EXTERN_END_DEFINE_CLASS_INTERFACE

EXTERN_BEGIN_DEFINE_CLASS_INTERFACE(COvalSpriteAsset, IMoaMmXAsset)
	/* IMoaMmPropOwner methods */
		EXTERN_DEFINE_METHOD(MoaError, GetProp, (MoaMmSymbol, PMoaMmValue))		
		EXTERN_DEFINE_METHOD(MoaError, SetProp, (MoaMmSymbol, ConstPMoaMmValue))	

	/* IMoaMmXAsset methods */
		EXTERN_DEFINE_METHOD(MoaError, CallFunction, (MoaMmSymbol, MoaLong, 
		    	ConstPMoaMmValue, PMoaMmValue))		
		EXTERN_DEFINE_METHOD(MoaError, SetCallback, (PIMoaMmAssetCallback))		
   		EXTERN_DEFINE_METHOD(MoaError, Notify, (MoaLong, PMoaVoid))		
  		EXTERN_DEFINE_METHOD(MoaError, GetDefaultRect, (PMoaRect))		
		EXTERN_DEFINE_METHOD(MoaError, PrepareNewContent, (MoaMmNewFlags))		
		EXTERN_DEFINE_METHOD(MoaError, StreamOutMedia, (PIMoaStream))		
		EXTERN_DEFINE_METHOD(MoaError, StreamInMedia, (PIMoaStream))		
		EXTERN_DEFINE_METHOD(MoaError, FreeMedia, ())		
		EXTERN_DEFINE_METHOD(MoaError, GetInMemMediaSize, (MoaUlong *))		
		EXTERN_DEFINE_METHOD(MoaError, GetStreamOutMediaSize, (MoaUlong *))		
		EXTERN_DEFINE_METHOD(MoaError, StreamOutProps, (PIMoaStream))		
		EXTERN_DEFINE_METHOD(MoaError, StreamInProps, (PIMoaStream))		
		EXTERN_DEFINE_METHOD(MoaError, FreeProps, ())		
		EXTERN_DEFINE_METHOD(MoaError, GetInMemPropsSize, (MoaUlong *))		
		EXTERN_DEFINE_METHOD(MoaError, GetStreamOutPropsSize, (MoaUlong *))		
		EXTERN_DEFINE_METHOD(MoaError, NewXActor, (PMoaVoid *))  
		EXTERN_DEFINE_METHOD(MoaError, InvokeMediaEditor, (PMoaMmModifyFlags))
		EXTERN_DEFINE_METHOD(MoaError, InvokePropsEditor, ())
		EXTERN_DEFINE_METHOD(MoaError, FinishPropsEditor, (MoaBoolParam, 
				PMoaMmModifyFlags))
		EXTERN_DEFINE_METHOD(MoaError, InvokeAboutBox, ())
		EXTERN_DEFINE_METHOD(MoaError, ImageStaticThumb, (PIMoaMmGC, ConstPMoaRect))		
		EXTERN_DEFINE_METHOD(MoaError, BeginImageAnimThumb, (PIMoaMmGC, ConstPMoaRect))		
		EXTERN_DEFINE_METHOD(MoaError, ServiceImageAnimThumb, (PIMoaMmGC, ConstPMoaRect))		
		EXTERN_DEFINE_METHOD(MoaError, EndImageAnimThumb, (PIMoaMmGC, ConstPMoaRect))		
EXTERN_END_DEFINE_CLASS_INTERFACE

EXTERN_BEGIN_DEFINE_CLASS_INTERFACE(COvalSpriteAsset, IMoaAwEventSender)
		EXTERN_DEFINE_METHOD(MoaError, GetXtraEventDescriptions, (PMoaChar pDescriptions, MoaLong maxLen))
		EXTERN_DEFINE_METHOD(MoaError, GetInstanceEventDescriptions, (PMoaChar pDescriptions, MoaLong maxLen))
		EXTERN_DEFINE_METHOD(MoaError, GetSenderXtraName, (PMoaChar pName, MoaLong maxLen))
		EXTERN_DEFINE_METHOD(MoaError, HandleReply, (MoaMmSymbol eventName, PMoaMmValue pReply,	PMoaVoid replyRefcon))
EXTERN_END_DEFINE_CLASS_INTERFACE

#endif /* _H_ovalasst */
