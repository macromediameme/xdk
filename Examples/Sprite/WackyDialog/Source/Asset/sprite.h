
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
 *	Name: sprite.h
 *
 ****************************************************************************/ 

#ifndef _H_Sprite
#define _H_Sprite

///////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////

#include "moaxtra.h"
#include "mmixasst.h"

#include "Asset.h"


///////////////////////////////////////////////////////////////////////////////
//
// Declares
//
///////////////////////////////////////////////////////////////////////////////

// {664C4543-1AD8-11d3-8635-00104B27A1A1}
DEFINE_GUID( CLSID(CWackyDlgSprite), 0x664c4543, 0x1ad8, 0x11d3, 0x86, 0x35, 0x0, 0x10, 0x4b, 0x27, 0xa1, 0xa1);

///////////////////////////////////////////////////////////////////////////////
//
// Object Instance variables
//
///////////////////////////////////////////////////////////////////////////////

EXTERN_BEGIN_DEFINE_CLASS_INSTANCE_VARS( CWackyDlgSprite )
	// direct access to Asset that were are linked to
	CWackyDlgAsset_IMoaMmXAsset FAR *	mAsset;				
	
	// this provides access to common sprite services
	PIMoaMmSpriteCallback	mSpriteCallback;
EXTERN_END_DEFINE_CLASS_INSTANCE_VARS

///////////////////////////////////////////////////////////////////////////////
//
// Interface method implementation declaration
//
///////////////////////////////////////////////////////////////////////////////

EXTERN_BEGIN_DEFINE_CLASS_INTERFACE( CWackyDlgSprite, IMoaMmXSpriteActor )
	EXTERN_DEFINE_METHOD( MoaError, GetProp, 		(MoaMmSymbol, PMoaMmValue) )		
	EXTERN_DEFINE_METHOD( MoaError, SetProp, 		(MoaMmSymbol, ConstPMoaMmValue) )		
	EXTERN_DEFINE_METHOD( MoaError, CallFunction, 	(MoaMmSymbol, MoaLong, ConstPMoaMmValue,PMoaMmValue) )		
	EXTERN_DEFINE_METHOD( MoaError, SetCallback, 	(PIMoaMmSpriteCallback) )		
	EXTERN_DEFINE_METHOD( MoaError, Notify, 		(MoaLong, PMoaVoid) )		
	EXTERN_DEFINE_METHOD( MoaError, GetCaps, 		(PMoaMmXSpriteCaps) )		
	EXTERN_DEFINE_METHOD( MoaError, CollectChanges,	(ConstPMoaMmXSpriteInfo, PIMoaMmChangeCollector) )		
	EXTERN_DEFINE_METHOD( MoaError, ContainsPoint,	(ConstPMoaMmXSpriteInfo, ConstPMoaPoint,	MoaBoolParam *) )		
	EXTERN_DEFINE_METHOD( MoaError, Image, 			(ConstPMoaMmXSpriteInfo, ConstPMoaMmPlayerStateInfo, PIMoaMmGC) )		
	EXTERN_DEFINE_METHOD( MoaError, Event,			(ConstPMoaMmEventInfo, ConstPMoaMmPlayerStateInfo, MoaBoolParam *) )		
EXTERN_END_DEFINE_CLASS_INTERFACE


#endif // !_H_Sprite
