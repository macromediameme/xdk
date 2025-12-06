/*
   $Revision: 2 $
*/

#ifndef _H_muiservc
#define _H_muiservc

/* --------------------------------------------------------------------------------

	Copyright (c) 1997, Macromedia, Inc.  All rights reserved.
	
	You may utilize this source file to create and compile object code for use
	within products you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
	WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
	INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
	PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
	FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
	USE OR INABILITY TO USE THIS CODE.
	
	Purpose:
	
	MUI services interface definitions.
	
	History:
	
	21jun98 tgs Removed unused argument from InstallMouseTracker method.
	22sep97	LLB	Added InstallMouseTracker method to IMuiCallback.
	08sep97	LLB	Added IMuiCallback.
	04sep97	LLB	Added IMuiControlState.
	04sep97	GWR	created.

----------------------------------------------------------------------------------- */


/* on WINDOWS, include windows.h before any moa files */
#ifdef _WINDOWS
	#ifndef _WINDOWS_
	#include <windows.h>
	#endif
#endif

#ifndef _H_moaxtra
#include "moaxtra.h"	 	/* MOA shell */
#endif

#ifndef _H_moastdif
#include "moastdif.h"		/* MOA standard interfaces */
#endif

#ifndef _H_mmtypes
#include "mmtypes.h"		/* multimedia types */
#endif

#ifndef _H_mmiservc
#include "mmiservc.h"
#endif

#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma push
	#pragma pointers_in_D0
#endif /* MACINTOSH && MWERKS && !powerc */


/* ----------------------------------------------------------------------------
/
/	IMuiDragInstance - Mui drag instance
/
/ --------------------------------------------------------------------------- */

DEFINE_GUID(IID_IMuiDragInstance, 0xAB05B018L, 0x2534, 0x11D1, 0xA1, 0xD1, 0x00, 
								0x05, 0x9A, 0x20, 0x6D, 0x9E);
																
#undef INTERFACE
#define INTERFACE IMuiDragInstance

DECLARE_INTERFACE_(IMuiDragInstance, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	
	STDMETHOD_(MoaBool, HasType) 		(THIS_
			MoaMmSymbol					itemType) 
			PURE;
			
	STDMETHOD(GetItemCount)				(THIS_
			MoaLong FAR *				pItemCountOut) 
			PURE;
	
	STDMETHOD(DoesItemHaveType)			(THIS_
			MoaLong						nItemIndex,
			MoaMmSymbol					itemType,
			MoaBool FAR *				pHasTypeOut)
			PURE;
	
	STDMETHOD(GetItemTypeCount)			(THIS_
			MoaLong						itemIndex,
			MoaLong FAR *				pTypeCountOut)
			PURE;
	
	STDMETHOD(GetItemType)				(THIS_
			MoaLong						itemIndex,
			MoaLong						typeIndex,
			PMoaMmSymbol				pTypeOut)
			PURE;
	
	STDMETHOD(GetItemSize)				(THIS_
			MoaLong						itemIndex,
			MoaMmSymbol					itemType,
			MoaLong FAR *				pItemSizeOut)
			PURE;
	
	STDMETHOD(GetItemData)				(THIS_
			MoaLong						itemIndex,
			MoaMmSymbol					itemType,
			PMoaVoid					pDataOut,
			MoaLong FAR *				pSizeInOut)
			PURE;
	
	STDMETHOD(AddItem)					(THIS_
			MoaMmSymbol					itemType,
			ConstPMoaVoid				pItemDataIn,
			MoaLong						itemSize)
			PURE;
};

typedef IMuiDragInstance FAR * PIMuiDragInstance;

/* ---------------------------------------------------------------------------- */

#undef INTERFACE

/* ----------------------------------------------------------------------------
/
/	IMuiControlState - Mui control state
/
/ --------------------------------------------------------------------------- */

/* IID_IMuiControlState: 6A06A3FC-247A-11d1-B989-00059A20195A */
DEFINE_GUID(IID_IMuiControlState, 0x6A06A3FCL, 0x247A, 0x11D1, 0xB9, 0x89,
			0x00, 0x05, 0x9A, 0x20, 0x19, 0x5A);

#undef	INTERFACE
#define INTERFACE IMuiControlState

DECLARE_INTERFACE_(IMuiControlState, IMoaMmPropOwner)
{
	STD_IUNKNOWN_METHODS


	/*
	** Property owner methods
	*/
	STDMETHOD(GetProp)		(THIS_ 				
							MoaMmSymbol 		symbol,
							PMoaMmValue			pPropValue
							)
							PURE;
	
	STDMETHOD(SetProp)		(THIS_ 
							MoaMmSymbol 		symbol,
							ConstPMoaMmValue	pPropValue
							)
							PURE;
	
	
	/*
	** Control State methods
	*/
	STDMETHOD(MergePropList)
							(THIS_
							PMoaMmValue			pAttributeList
							)
							PURE;
	
	STDMETHOD(GetPropList)
							(THIS_
							PMoaMmValue			pAttributeList
							)
							PURE;
	
	STDMETHOD(SetPropList)
							(THIS_
							ConstPMoaMmValue	pAttributeList
							)
							PURE;
	
};

typedef IMuiControlState FAR * PIMuiControlState;

/* ---------------------------------------------------------------------------- */

#undef INTERFACE


/* ----------------------------------------------------------------------------
/
/	IMuiCallback - Mui callback services
/
/ --------------------------------------------------------------------------- */

/* IID_IMuiCallback: 85FCA054-286A-11d1-8D42-00059A20195A */
DEFINE_GUID(IID_IMuiCallback, 0x85FCA054L, 0x286A, 0x11D1, 0x8D, 0x42,
			0x00, 0x05, 0x9A, 0x20, 0x19, 0x5A);

#undef	INTERFACE
#define INTERFACE IMuiCallback

DECLARE_INTERFACE_(IMuiCallback, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS


	STDMETHOD(GetNativeGC) (THIS_
							PMoaMmNativeGCInfo	pGCInfo
							)
							PURE;
			
	STDMETHOD(Invalidate)	(THIS_
							ConstPMoaRect pInvalRect
							)
							PURE;
	
	STDMETHOD(GetBounds)	(THIS_
							PMoaRect	pBoundsRect
							)
							PURE;
	
	STDMETHOD(CreateDragInstance)	(THIS)
									PURE;
									
	STDMETHOD(InstallMouseTracker)	(THIS)
									PURE;
									
};

typedef IMuiCallback FAR * PIMuiCallback;

/* ---------------------------------------------------------------------------- */

#undef INTERFACE


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#endif /* _H_muiservc */
