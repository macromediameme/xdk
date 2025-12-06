/*==========================================================================\
|                                                                           |
|                   Copyright (c) 1994-1998, Macromedia, Inc.               |
|                                                                           |
|	You may utilize this source file to create and compile object code for 	|
|	use within products you may create.  THIS CODE IS PROVIDED "AS IS", 	|
|	WITHOUT WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED 		|
|	WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A|
|	PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE |
|	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES 	|
|	ARISING OUT OF YOUR USE OR INABILITY TO USE THIS CODE.					|
|                                                                           |
\==========================================================================*/

#ifndef	NO_PRAGMA_ONCE
#pragma	once
#endif

/****************************************************************************
/ Filename
/   $Workfile: mmixasst.h $
/
/ Version:
/   $Revision: 2 $
/
/ Purpose
/	Common media asset interfaces.
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/mmixasst.h $
/   
/   2     6/23/99 11:55 AM Greggy
/   Checkin to synchronize revision numbers.
/   
/   10    10/19/98 11:27 AM Mroeder
/   Changed header from "Confidential" to "You may use..." because these
/   files are in the XDK. Updated copyright notice to cover 1998. 
/   
/   9     7/15/98 12:52p Greggy
/   Removed GetOptions and SetOptions. Instead, the dicts are passed back
/   and forth right in the Read calls.
/   
/   8     7/14/98 3:03p Greggy
/   Added IMoaMmXImport for importing directly into first-class Xtras.
/   
/   7     2/10/98 11:15a Kday
/   Replaced one bogus IUnknown use with IMoaUnknown
/   
/   6     1/30/98 10:51a Greggy
/   Unified header format. Based the guard tag directly on the filename.
/   
04feb98 krd One interface used IUnknown, changed to IMoaUnknown (cw pro 2 compile)
11jan95 dac Remove pGC, pActorInfo from SpriteActor::Event(), reformat.
 6nov95 dac add Asset::Init(), ::Notify; SpriteActor::Notify()
 4oct95 dws Major name munge. Common types moved here from dxicmem.h.
28aug95 dws New names. Add const types.
24aug95	ejs	Change IMoaDrInStream, IMoaDrOutStream to IMoaStream 
 5aug95 drs change Cue method usage
 2aug95 drs revamped transition interface
24jul95 drs added method to create new transition
11jun95	dac created: split out cast member interfaces from dxcmn.h
****************************************************************************/


#ifndef	MMIXASST_H
#define	MMIXASST_H


#include "moaxtra.h"
#include "moastdif.h"
#include "moastr2.h"
#include "mmiservc.h"


#ifdef	__cplusplus
extern "C" {
#endif


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma push
	#pragma pointers_in_D0
#endif


/* ----------------------------------------------------------------------------
/
/	IMoaRegister
/
/ --------------------------------------------------------------------------- */

/* This interface is defined in moastdif.h.  A class must be implemented
   which supports this interface; the Register() method should register
   information for each cast member type supported by this xtra.  
   Register() must add dictionary entries for:
   
   typeSymbolString	
   displayNameString
   displayCategoryString
   actorType
   caps
   
   [ optional: 
   
   colorIcon 
   BWIcon
   
   ]

*/


/* ----------------------------------------------------------------------------
/
/	IMoaMmXAsset - External media asset interface
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaMmXAsset: AC401E5C0001A85500000800072C6326 */
DEFINE_GUID(IID_IMoaMmXAsset, 0xAC401E5CL, 0x0001, 0xA855, 0x00, 0x00, 0x08,
				0x00, 0x07, 0x2C, 0x63, 0x26);

#undef INTERFACE
#define INTERFACE IMoaMmXAsset

DECLARE_INTERFACE_(IMoaMmXAsset, IMoaMmPropOwner)
{
	STD_IUNKNOWN_METHODS

	/* IMoaMmPropOwner methods */
	
	STDMETHOD(GetProp)(THIS_ 						
			MoaMmSymbol 				symbol,
			PMoaMmValue					pPropValue)
			PURE;
			
	STDMETHOD(SetProp)(THIS_ 
			MoaMmSymbol 				symbol,
			ConstPMoaMmValue			pPropValue)
			PURE;

	/* IMoaMmXAsset methods */

	STDMETHOD(CallFunction) 			(THIS_ 
			MoaMmSymbol 				methodName, 
			MoaLong 	   				nArgs, 
			ConstPMoaMmValue 			pArgs, 
			PMoaMmValue					pResult)
			PURE;
	
	STDMETHOD(SetCallback) 				(THIS_
			PIMoaMmAssetCallback		 pAssetCallback)
			PURE;

	STDMETHOD(Notify) 					(THIS_
			MoaLong						msgCode,
			PMoaVoid					refCon)
			PURE;
			
	STDMETHOD(GetDefaultRect)			(THIS_ 
			PMoaRect					pRect)
			PURE;
			
	STDMETHOD(PrepareNewContent)		(THIS_
			MoaMmNewFlags 				newFlags)
			PURE;
			
	STDMETHOD(StreamOutMedia)			(THIS_
			PIMoaStream 				pOutStream)
			PURE;
			
	STDMETHOD(StreamInMedia)			(THIS_
			PIMoaStream 				pInStream)
			PURE;
			
	STDMETHOD(FreeMedia)				(THIS) 
			PURE;
			
	STDMETHOD(GetInMemMediaSize)		(THIS_ 
			MoaUlong FAR * 				pSizeBytes)
			PURE;
			
	STDMETHOD(GetStreamOutMediaSize)	(THIS_ 
			MoaUlong FAR * 				pSizeBytes)
			PURE;
						
	STDMETHOD(StreamOutProps)			(THIS_
			PIMoaStream 				pOutStream)
			PURE;
			
	STDMETHOD(StreamInProps) 			(THIS_
			PIMoaStream 				pInStream)
			PURE;
			
	STDMETHOD(FreeProps) 				(THIS) 
			PURE;
			
	STDMETHOD(GetInMemPropsSize) 		(THIS_ 
			MoaUlong FAR * 				pSizeBytes)
			PURE;
			
	STDMETHOD(GetStreamOutPropsSize) 	(THIS_ 
			MoaUlong FAR * 				pSizeBytes)
			PURE;
						
	STDMETHOD(NewXActor) 				(THIS_ 
			PMoaVoid FAR * 				ppXActor)  	
			PURE;
			
	/* Authoring methods */
	STDMETHOD(InvokeMediaEditor) 		(THIS_						
			PMoaMmModifyFlags			pModifyFlags)					
			PURE;
			
	STDMETHOD(InvokePropsEditor) 		(THIS)						
			PURE;
			
	STDMETHOD(FinishPropsEditor) 		(THIS_	
			MoaBoolParam				commitChanges,					
			PMoaMmModifyFlags			pModifyFlags)						
			PURE;
			
	STDMETHOD(InvokeAboutBox) 			(THIS)						
			PURE;
			
	STDMETHOD(ImageStaticThumb) 		(THIS_						
			PIMoaMmGC					pGC,
			ConstPMoaRect				pImageRect)
			PURE;
			
	STDMETHOD(BeginImageAnimThumb) 		(THIS_					
			PIMoaMmGC					pGC,
			ConstPMoaRect				pImageRect)
			PURE;
			
	STDMETHOD(ServiceImageAnimThumb) 	(THIS_
			PIMoaMmGC					pGC,
			ConstPMoaRect				pImageRect)
			PURE;
			
	STDMETHOD(EndImageAnimThumb) 		(THIS_
			PIMoaMmGC					pGC,
			ConstPMoaRect				pImageRect)
			PURE;
};

typedef IMoaMmXAsset FAR * PIMoaMmXAsset;


/* IID_IMoaMmXImport: 234e2a70-1ad7-11d2-a718-00a0c98b9ff5 */
DEFINE_GUID(IID_IMoaMmXImport, 0x234e2a70, 0x1ad7, 0x11d2, 0xa7, 0x18, 0x00, 0xa0, 0xc9, 0x8b, 0x9f, 0xf5);

#undef INTERFACE
#define INTERFACE IMoaMmXImport

DECLARE_INTERFACE_(IMoaMmXImport, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS

	STDMETHOD(ReadFromStream) (THIS_
		/*IN*/	PIMoaStream2	pStream,
		/*IN*/	PIMoaDict		pOptionsDict,
		/*OUT*/	PIMoaDict FAR *	ppOptionsDict
	) PURE;

	STDMETHOD(ReadFromFile) (THIS_
		/*IN*/	PIMoaPathName	pPathToRead,
		/*IN*/	PIMoaDict		pOptionsDict,
		/*OUT*/	PIMoaDict FAR *	ppOptionsDict
	) PURE;
};

typedef IMoaMmXImport FAR * PIMoaMmXImport;


/* ----------------------------------------------------------------------------
/
/	IMoaMmXSpriteActor - sprite actor interface
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaMmXSpriteActor: AC401E760001AEA700000800072C6326 */
DEFINE_GUID(IID_IMoaMmXSpriteActor, 0xAC401E76L, 0x0001, 0xAEA7, 0x00, 0x00, 0x08, 
				0x00, 0x07, 0x2C, 0x63, 0x26);

#undef INTERFACE
#define INTERFACE IMoaMmXSpriteActor

DECLARE_INTERFACE_(IMoaMmXSpriteActor, IMoaMmPropOwner)
{
	STD_IUNKNOWN_METHODS

	/* IMoaMmPropOwner methods */
	
	STDMETHOD(GetProp) 					(THIS_ 						
			MoaMmSymbol 				symbol,
			PMoaMmValue					pPropValue)
			PURE;
			
	STDMETHOD(SetProp) 					(THIS_ 
			MoaMmSymbol 				symbol,
			ConstPMoaMmValue			pPropValue)
			PURE;
			
	/* Sprite Actor methods */
	
	STDMETHOD( CallFunction ) 			(THIS_ 
			MoaMmSymbol 				methodName, 
			MoaLong 					nArgs, 
			ConstPMoaMmValue			pArgs, 
			PMoaMmValue 				pResult)
			PURE;

	STDMETHOD(SetCallback) 				(THIS_ 
			PIMoaMmSpriteCallback 		pSpriteCallback)
			PURE;
			
	STDMETHOD(Notify) 					(THIS_
			MoaLong						msgCode,
			PMoaVoid					refCon)
			PURE;

	STDMETHOD(GetCaps) 					(THIS_
			PMoaMmXSpriteCaps			pActorCaps)
			PURE;
			
	STDMETHOD(CollectChanges) 			(THIS_ 
			ConstPMoaMmXSpriteInfo 		pActorInfo,
			PIMoaMmChangeCollector 		pChangeCollector)
			PURE;
			
	STDMETHOD(ContainsPoint) 			(THIS_
			ConstPMoaMmXSpriteInfo		pActorInfo,
			ConstPMoaPoint				pTestPoint,
			MoaBoolParam FAR *			pTestResult)
			PURE;

	STDMETHOD(Image) 					(THIS_ 
			ConstPMoaMmXSpriteInfo 		pActorInfo,
			ConstPMoaMmPlayerStateInfo	pPlayerStateInfo,
			PIMoaMmGC			  		pGC)
			PURE;

	STDMETHOD(Event) 					(THIS_ 
			ConstPMoaMmEventInfo		pEventInfo,
			ConstPMoaMmPlayerStateInfo	pPlayerStateInfo,
			MoaBoolParam FAR * 		  	pHandled)
			PURE;

};

typedef IMoaMmXSpriteActor FAR * PIMoaMmXSpriteActor;


/* ----------------------------------------------------------------------------
/
/	IMoaMmXTransitionActor - transition actor interface
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaMmXTransitionActor: AC401E9C0001B76800000800072C6326 */
DEFINE_GUID(IID_IMoaMmXTransitionActor, 0xAC401E9CL, 0x0001, 0xB768, 0x00, 0x00, 
				0x08, 0x00, 0x07, 0x2C, 0x63, 0x26);

#undef INTERFACE
#define INTERFACE IMoaMmXTransitionActor

DECLARE_INTERFACE_(IMoaMmXTransitionActor, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
				
	STDMETHOD(Notify) (THIS_
			MoaLong						msgCode,
			PMoaVoid					refCon)
			PURE;
						
	STDMETHOD(Cue) (THIS_
			PIMoaMmGC 					pDestGC,
			PIMoaMmGC 					pSrcGC,
			ConstPMoaRect				pRect,
			ConstPMoaMmTransInfo		pTransInfo)
			PURE;
			
	STDMETHOD(Continue) (THIS_
			PIMoaMmGC 					pDestGC,
			PIMoaMmGC 					pSrcGC,
			ConstPMoaRect				pRect,
			ConstPMoaMmTransInfo		pTransInfo,
			MoaBoolParam FAR * 			pFinished)
			PURE;
			
	STDMETHOD(Finish) (THIS_
			PIMoaMmGC 					pDestGC,
			PIMoaMmGC 					pSrcGC,
			ConstPMoaRect 				pRect,
			ConstPMoaMmTransInfo		pTransInfo)
			PURE;
};

typedef IMoaMmXTransitionActor FAR * PIMoaMmXTransitionActor;


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif 


#ifdef	__cplusplus
}
#endif


#endif	/* MMIXASST_H */
