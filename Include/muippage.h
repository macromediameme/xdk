/*//////////////////////////////////////////////////////////////////////////////
//
// Copyright 1999 Macromedia, Inc.	All rights reserved.
//		This material is the confidential trade secret and proprietary
//		information of Macromedia, Inc.  It may not be reproduced, used,
//		sold or transferred to any third party without the prior written
//		consent of Macromedia, Inc.  All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////*/

/* *********************************************************************
/ Filename
/	$Workfile: muippage.h $
/
/ Version:
/	$Revision: 3 $
/
/ Purpose
	Macromedia Open Architecture - Property Page Interfaces
/
/ Notes
	
/
/ Modification History
/	$Log: /xtras/include/muippage.h $
/   
/   3     11/23/99 10:08 AM Egreenfield
/   added function call to get access to target elements
/   
/   2     9/23/99 4:58p Egreenfield2
/   fixed guids
/   
/   1     9/20/99 2:54 PM Egreenfield
/   interfaces for the prop inspector
/   
/   
/   
**********************************************************************/


/*/////////////////////////////////////////////////////////////////////////////////
//
// Description
//
/////////////////////////////////////////////////////////////////////////////////*/



#ifndef	MUIPROPPAGE_H
#define	MUIPROPPAGE_H

/*----------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------*/
#include "moaxtra.h"
#include "moatypes.h"
#include "moastdif.h"
#include "mmipref.h"
#include "mmiservc.h"


#ifdef	__cplusplus
extern "C" {
#endif


#if defined(__MWERKS__) && defined(__MC68K__)
#pragma push
#pragma pointers_in_D0
#endif

/*----------------------------------------------------------------------------
// types
//--------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
// Registry settings
//--------------------------------------------------------------------------*/
#define kMuiDictKey_PropPageEntry "VDLPath"
/*----------------------------------------------------------------------------
// Interfaces
//--------------------------------------------------------------------------*/





// {35F34993-6FB8-11d3-B85E-00902754C68C}
DEFINE_GUID(IID_IMuiPropertyPage,
0x35f34993, 0x6fb8, 0x11d3, 0xb8, 0x5e, 0x0, 0x90, 0x27, 0x54, 0xc6, 0x8c);
// {35F34995-6FB8-11d3-B85E-00902754C68C}
DEFINE_GUID(IID_IMuiPropertyPageTarget,
0x35f34995, 0x6fb8, 0x11d3, 0xb8, 0x5e, 0x0, 0x90, 0x27, 0x54, 0xc6, 0x8c);
// {35F34996-6FB8-11d3-B85E-00902754C68C}
DEFINE_GUID(IID_IMuiPropertyPageInstance,
0x35f34996, 0x6fb8, 0x11d3, 0xb8, 0x5e, 0x0, 0x90, 0x27, 0x54, 0xc6, 0x8c);


#undef INTERFACE
#define INTERFACE IMuiPropertyPageTarget

DECLARE_INTERFACE_(IMuiPropertyPageTarget, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	
	STDMETHOD(GetTargetCount)			(THIS_
			PMoaLong					pCount)
			PURE;
		
	STDMETHOD(GetNthTarget)				(THIS_
			MoaLong						index,
			PIMoaUnknown*				ppTarget)
			PURE;
	

	STDMETHOD(GetProp)			(THIS_
			MoaMmSymbol					property,
			PMoaMmValue					pResult)
			PURE;

	STDMETHOD(SetProp)			(THIS_
			MoaMmSymbol					property,
			ConstPMoaMmValue			pValue)
			PURE;

};

typedef IMuiPropertyPageTarget FAR * PIMuiPropertyPageTarget;


DECLARE_INTERFACE_(IMuiPropertyPageInstance, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	
	STDMETHOD(GetControlProp)			(THIS_
			MoaMmSymbol					controlID,
			MoaMmSymbol					property,
			PMoaMmValue					pResult)
			PURE;

	STDMETHOD(SetControlProp)			(THIS_
			MoaMmSymbol					controlID,
			MoaMmSymbol					property,
			ConstPMoaMmValue			pValue)
			PURE;

};

typedef IMuiPropertyPageInstance FAR * PIMuiPropertyPageInstance;




#undef INTERFACE
#define INTERFACE IMuiPropertyPage

DECLARE_INTERFACE_(IMuiPropertyPage, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	
	

	STDMETHOD(GetDescriptor)			(THIS_
			MoaMmValue*					pResult)
			PURE;

	STDMETHOD_(void,SetTarget)			(THIS_
			PIMuiPropertyPageInstance 	pPageInstance,
			PIMuiPropertyPageTarget 	pTarget)
			PURE;

	STDMETHOD_(MoaBool,ItemClicked)		(THIS_
			MoaMmSymbol 				itemID,
			ConstPMoaMmValue			pItemValue,
			PIMuiPropertyPageInstance 	pPageInstance,
			PIMuiPropertyPageTarget 	pTarget)
			PURE;

	STDMETHOD_(void,UpdateItems)			(THIS_
			PIMuiPropertyPageInstance 	pPageInstance,
			PIMuiPropertyPageTarget 	pTarget)
			PURE;

	STDMETHOD_(void,Idle)			(THIS_
			PIMuiPropertyPageInstance 	pPageInstance,
			PIMuiPropertyPageTarget 	pTarget)
			PURE;
};

typedef IMuiPropertyPage FAR * PIMuiPropertyPage;





#if defined(__MWERKS__) && defined(__MC68K__)
#pragma pop
#endif


#ifdef	__cplusplus
}
#endif

#endif
