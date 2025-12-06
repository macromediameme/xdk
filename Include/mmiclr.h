/*==========================================================================\
|                                                                           |
|                   Copyright (c) 1994-1998, Macromedia, Inc.               |
|                                                                           |
	You may utilize this source file to create and compile object code for 
	use within products you may create.  THIS CODE IS PROVIDED "AS IS", 
	WITHOUT WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED 
	WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A
	PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE 
	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES 
	ARISING OUT OF YOUR USE OR INABILITY TO USE THIS CODE.
|                                                                           |
\==========================================================================*/

#ifndef	NO_PRAGMA_ONCE
#pragma	once
#endif

/****************************************************************************
/ Filename
/   $Workfile: mmiClr.h $
/
/ Version:
/   $Revision: 2 $
/
/ Purpose
/	Interface definition for converting between MoaMmValues of 
/	 ValueType() == kMoaMmValueType_Color and MoaMmColorSpec values
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/mmiClr.h $
/   
/   2     6/23/99 11:54 AM Greggy
/   Checkin to synchronize revision numbers.
/   
/   2     10/20/98 12:00 PM Mroeder
/   Updated copyright date and changed headers to "you may use..."
/   
/   1     7/12/98 5:44p Cnuuja
/   initial definition
/   
****************************************************************************/

#ifndef	MMICLR_H
#define	MMICLR_H


#include "moaxtra.h"	 	/* MOA shell */
#include "moastdif.h"		/* MOA standard interfaces */
#include "mmtypes.h"		/* multimedia types */
#include "mmiservc.h"


#ifdef	__cplusplus
extern "C" {
#endif


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma push
	#pragma pointers_in_D0
#endif /* MACINTOSH && MWERKS && !powerc */


/* ----------------------------------------------------------------------------
/
/	IID_IMoaMmColor - MoaMmColorSpec manipulation functions.
/
/ --------------------------------------------------------------------------- */
/* 999
	   f67eacf0-11e7-11d2-9D18-00104b2797f3 
   999
*/

/* IID_IMoaMmUtils2: f36721d0-11e7-11d2-9D18-00104b2797f3 */
DEFINE_GUID(IID_IMoaMmColor, 0xf36721d0, 0x11e7, 0x11d2, 0x9D, 0x18, 0x00, 
							 0x10, 0x4b, 0x27, 0x97, 0xf3);

#undef INTERFACE
#define INTERFACE IMoaMmColor

DECLARE_INTERFACE_(IMoaMmColor, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	
	STDMETHOD(ValueToColor)				(THIS_
			ConstPMoaMmValue 			pValue,
			PMoaMmColorSpec				pColor)
			PURE;

	STDMETHOD(ColorToValue) 			(THIS_
			ConstPMoaMmColorSpec 		pColor,
			PMoaMmValue 				pValue)
			PURE;

	STDMETHOD(RGBToIndex)				(THIS_ 
			ConstPMoaMmRGBTriple 		pRGBColor, 
			PMoaMmColorIndex 			pIndex) 
			PURE; 
			
	STDMETHOD(IndexToRGB)				(THIS_ 
			MoaMmColorIndex 			index, 
			PMoaMmRGBTriple 			pRGBColor) 
			PURE; 
};

typedef IMoaMmColor FAR * PIMoaMmColor;


/* ---------------------------------------------------------------------------- */

#undef INTERFACE


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#ifdef	__cplusplus
}
#endif


#endif	/* MMICLR_H */
