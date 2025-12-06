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
/   $Workfile: mmivalue.h $
/
/ Version:
/   $Revision: 2 $
/
/ Purpose
/	MoaMmValue services interface definitions.
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/mmivalue.h $
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
/	30oct96 dws split from IMoaMmUtils & mmiservc.h
****************************************************************************/


#ifndef	MMIVALUE_H
#define	MMIVALUE_H


#include "moaxtra.h"	 	/* MOA shell */
#include "moastdif.h"		/* MOA standard interfaces */
#include "mmtypes.h"		/* multimedia types */


#ifdef	__cplusplus
extern "C" {
#endif


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma push
	#pragma pointers_in_D0
#endif /* MACINTOSH && MWERKS && !powerc */



/* ----------------------------------------------------------------------------
/
/	IMoaMmValue - MoaMmValue services interface
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaMmValue: 151A5780-32BD-11d0-8151-00AA005F3C08 */
DEFINE_GUID(IID_IMoaMmValue, 0x151a5780, 0x32bd, 0x11d0, 0x81, 0x51, 0x0, 
								0xaa, 0x0, 0x5f, 0x3c, 0x8);

#undef INTERFACE
#define INTERFACE IMoaMmValue

DECLARE_INTERFACE_(IMoaMmValue, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
		
	/* Symbol dictionary access */
	
	STDMETHOD(StringToSymbol)			(THIS_ 
			ConstPMoaChar 				pString, 
			PMoaMmSymbol 				pSymbol) 
			PURE;
			
	STDMETHOD(SymbolToString)			(THIS_ 
			MoaMmSymbol 				symbol, 
			PMoaChar 					pStringBuf, 
			MoaLong 					bufLen) 
			PURE;
	
	/* Value access */
	
	STDMETHOD(ValueType)				(THIS_ 
			ConstPMoaMmValue 			pValue, 
			MoaMmValueType FAR *		pResult) 
			PURE;
	STDMETHOD(ValueAddRef)				(THIS_ 
			PMoaMmValue 				pValue) 
			PURE;
	STDMETHOD(ValueRelease)				(THIS_ 
			PMoaMmValue 				pValue) 
			PURE;
	
	/* Convert from value */
	
	STDMETHOD(ValueToInteger)			(THIS_ 
			ConstPMoaMmValue 			pValue, 
			MoaLong FAR *				pResult) 
			PURE;
			
	STDMETHOD(ValueToSymbol)			(THIS_ 
			ConstPMoaMmValue 			pValue, 
			PMoaMmSymbol	 			pResult) 
			PURE;
			
	STDMETHOD(ValueToFloat) 			(THIS_ 
			ConstPMoaMmValue 			pValue, 
			MoaDouble FAR *				pResult) 
			PURE;
			
	STDMETHOD(ValueStringLength)		(THIS_ 
			ConstPMoaMmValue 			pValue, 
			MoaLong FAR *				pResult) 
			PURE;
			
	STDMETHOD(ValueToString) 			(THIS_ 
			ConstPMoaMmValue 			pValue, 
			PMoaChar 					pStringBuf, 
			MoaLong 					bufLen) 
			PURE;
			
	STDMETHOD(ValueToStringPtr)			(THIS_ 
			ConstPMoaMmValue 			pValue, 
			ConstPMoaChar FAR *			pResult)
			PURE;
			
	STDMETHOD(ValueReleaseStringPtr)	(THIS_ 
			ConstPMoaMmValue			pValue) 
			PURE;
			
	STDMETHOD(ValueToPoint) 			(THIS_
			 ConstPMoaMmValue 			pValue, 
			 PMoaPoint 					pResult) 
			 PURE;
			 
	STDMETHOD(ValueToRect) 				(THIS_ 
			ConstPMoaMmValue 			pValue, 
			PMoaRect 					pResult) 
			PURE;

	/* Convert to value */
	
	STDMETHOD(IntegerToValue) 			(THIS_ 
			MoaLong 					num, 
			PMoaMmValue 				pValue) 
			PURE;
			
	STDMETHOD(SymbolToValue) 			(THIS_ 
			MoaMmSymbol 				symbol, 
			PMoaMmValue 				pValue) 
			PURE;
			
	STDMETHOD(FloatToValue) 			(THIS_ 
			MoaDouble 					fnum, 
			PMoaMmValue 				pValue) 
			PURE;
			
	STDMETHOD(StringToValue) 			(THIS_ 
			ConstPMoaChar 				pString, 
			PMoaMmValue 				pValue) 
			PURE;
			
	STDMETHOD(StringHandleToValue)		(THIS_ 
			MoaHandle 					hString, 
			PMoaMmValue 				pValue) 
			PURE;
			
	STDMETHOD(PointToValue) 			(THIS_ 
			ConstPMoaPoint 				pPoint, 
			PMoaMmValue 				pValue) 
			PURE;
			
	STDMETHOD(RectToValue) 				(THIS_ 
			ConstPMoaRect 				pRect, 
			PMoaMmValue 				pValue) 
			PURE;
};

typedef IMoaMmValue FAR * PIMoaMmValue;

/* ---------------------------------------------------------------------------- */

#undef INTERFACE


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#ifdef	__cplusplus
}
#endif


#endif	/* MMIVALUE_H */
