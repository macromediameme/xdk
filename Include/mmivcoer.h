/*
   $Revision: 2 $
*/

#ifndef _H_mmivcoer
#define _H_mmivcoer

/* ================================================================================

	Copyright (c) 1994-1997, Macromedia, Inc.  All rights reserved.
	
	You may utilize this source file to create and compile object code for use
	within products you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
	WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
	INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
	PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
	FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
	USE OR INABILITY TO USE THIS CODE.
	
	Purpose:
	
	MM Value coercion services callback interface definitions.
	
	This interface allows clients to coerce values from one type to another.
	The range of supported types and coercions between them will vary among Moa host apps.

	However any implementation of IMoaMmValueCoercion is guaranteed to support the following
	types and conversions between them:
		kMoaMmValueType_Integer
		kMoaMmValueType_String
		kMoaMmValueType_Float
		kMoaMmValueType_Any
		
	kMoaMmValueType_Any is a special destination type for value conversions from strings.
	
	History:

	02jul97	LLB	Created.

=================================================================================== */



#include "moaxtra.h"	 	/* MOA shell */
#include "moastdif.h"		/* MOA standard interfaces */
#include "mmtypes.h"		/* multimedia types */

#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma push
	#pragma pointers_in_D0
#endif /* MACINTOSH && MWERKS && !powerc */


/* ----------------------------------------------------------------------------
/
/	IMoaMmValueCoercion - value coercion functions
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaMmValueCoercion:  */
DEFINE_GUID(IID_IMoaMmValueCoercion, 0x638A3D90L, 0xF6DF, 0x11D0, 0xB4, 0xFA, 0x00, 0x05, 0x9A, 0x20, 0x19, 0x5A);

#undef INTERFACE
#define INTERFACE IMoaMmValueCoercion

DECLARE_INTERFACE_(IMoaMmValueCoercion, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS

/* CoerceValue:
   IN:  ConstPMoaMmValue 	pSrcValue
   IN:  MoaMmValueType 	 	desiredType
   OUT:	PMoaMmValue			pCoercedValue
   
   Attempts to convert the given value to a value of the given type.
   Clients must release the coerced value.
*/		
	STDMETHOD(CoerceValue)				(THIS_ 
			ConstPMoaMmValue			pSrcValue,
			MoaMmValueType				desiredType,
			PMoaMmValue	 				pCoercedValue) 
			PURE;

};

typedef IMoaMmValueCoercion FAR * PIMoaMmValueCoercion;

#undef INTERFACE

#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#endif /* _H_mmivcoer */
