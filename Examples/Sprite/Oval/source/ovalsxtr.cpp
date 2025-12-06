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
 *	Name: ovalsxtr.cpp
 *	
 * 	Purpose: The Xtra definition of the Sprite Oval Xtra example.
 *
 **********************************************************************************/ 

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .cpp file should automatically include all the support files needed for this 
 *  particular class. In addition, this file may include other .h files defining 
 *  additional callback interfaces for use by a third party.   
 *****************************************************************************/ 
 #include "ovalsreg.h"

/*****************************************************************************
 *  XTRA DEFINITION
 *  ---------------
 *  The Xtra definition specfies the classes and interfaces defined by your
 *  MOA Xtra.
 *
 *  Syntax:
 *	BEGIN_XTRA_DEFINES_CLASS(<class-name>,<version>)
 *	CLASS_DEFINES_INTERFACE(<class-name>, <interface-name>,<version>) 
 *****************************************************************************/ 
BEGIN_XTRA
	BEGIN_XTRA_DEFINES_CLASS(COvalSpriteRegister, 1) 
		CLASS_DEFINES_INTERFACE(COvalSpriteRegister, IMoaRegister, 1)
	END_XTRA_DEFINES_CLASS
	BEGIN_XTRA_DEFINES_CLASS(COvalSpriteAsset, 1)
		#ifdef USING_INIT_FROM_DICT
		CLASS_DEFINES_INTERFACE(COvalSpriteAsset, IMoaInitFromDict, 1)	
		#endif
		CLASS_DEFINES_INTERFACE(COvalSpriteAsset, IMoaMmXAsset, 1)
		
		CLASS_DEFINES_INTERFACE(COvalSpriteAsset, IMoaAwEventSender, 1)
		
	END_XTRA_DEFINES_CLASS
	BEGIN_XTRA_DEFINES_CLASS(COvalSpriteActor, 1)
		CLASS_DEFINES_INTERFACE(COvalSpriteActor, IMoaMmXSpriteActor, 1)
	END_XTRA_DEFINES_CLASS
END_XTRA

