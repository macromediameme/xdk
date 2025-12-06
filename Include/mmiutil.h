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
/   $Workfile: mmiutil.h $
/
/ Version:
/   $Revision: 2 $
/
/ Purpose
/	Multimedia utilities callback interface definitions.
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/mmiutil.h $
/   
/   2     6/23/99 11:55 AM Greggy
/   Checkin to synchronize revision numbers.
/   
/   3     10/19/98 11:26 AM Mroeder
/   Changed header from "Confidential" to "You may use..." because these
/   files are in the XDK. Updated copyright notice to cover 1998. 
/   
/   2     1/30/98 10:51a Greggy
/   Unified header format. Based the guard tag directly on the filename.
/   
/	30oct96 dws initial defn of IMoaMmUtils2, split from mmiservc.h
****************************************************************************/

#ifndef	MMIUTIL_H
#define	MMIUTIL_H


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
/	IMoaMmUtils2 - shared utility functions
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaMmUtils2: 3F698780-32BE-11d0-8151-00AA005F3C08 */
DEFINE_GUID(IID_IMoaMmUtils2, 0x3f698780, 0x32be, 0x11d0, 0x81, 0x51, 0x0, 
								0xaa, 0x0, 0x5f, 0x3c, 0x8);

#undef INTERFACE
#define INTERFACE IMoaMmUtils2

DECLARE_INTERFACE_(IMoaMmUtils2, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	
	/* Print to debug (message) window */
	
	STDMETHOD(PrintMessage)				(THIS_ 
			ConstPMoaChar 				pMsg) 
			PURE;
			
	STDMETHOD(PrintMessage1)			(THIS_ 
			ConstPMoaChar 				pMsg, 
			MoaLong 					arg1) 
			PURE;
			
	STDMETHOD(PrintMessage2)			(THIS_ 
			ConstPMoaChar 				pMsg, 
			MoaLong 					arg1, 
			MoaLong 					arg2) 
			PURE;
			
	STDMETHOD(PrintMessage3)			(THIS_ 
			ConstPMoaChar 				pMsg, 
			MoaLong 					arg1, 
			MoaLong 					arg2, 
			MoaLong 					arg3) 
			PURE;
			
	STDMETHOD(PrintMessage4)			(THIS_ 
			ConstPMoaChar 				pMsg, 
			MoaLong 					arg1, 
			MoaLong 					arg2, 
			MoaLong 					arg3, 
			MoaLong 					arg4) 
			PURE;
			

	/* Graphics context */
	
	STDMETHOD(NewGC)					(THIS_ 
			ConstPMoaMmNativeGCInfo 	pNativeGCInfo, 
			PIMoaMmGC FAR * 			ppGC) 
			PURE;
	
	/* Misc */
	
	STDMETHOD(RGBToIndex)				(THIS_ 
			ConstPMoaMmRGBTriple 		pRGBColor, 
			PMoaMmColorIndex 			pIndex) 
			PURE; 
			
	STDMETHOD(IndexToRGB)				(THIS_ 
			MoaMmColorIndex 			index, 
			PMoaMmRGBTriple 			pRGBColor) 
			PURE; 
};

typedef IMoaMmUtils2 FAR * PIMoaMmUtils2;


/* ---------------------------------------------------------------------------- */

#undef INTERFACE


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#ifdef	__cplusplus
}
#endif


#endif	/* MMIUTIL_H */
