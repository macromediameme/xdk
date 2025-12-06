/*
   $Revision: 2 $
*/

#ifndef _H_mmillist
#define _H_mmillist

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
	
	MM List services callback interface definitions.
	
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
/	IMoaMmLinearList - Linear list value functions
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaMmLinearList: 1399C84C-43E6-11D1-95-19-00-05-9A-20-19-5A */
DEFINE_GUID(IID_IMoaMmLinearList, 0x1399C84CL, 0x43E6, 0x11D1, 0x95, 0x19, 0x00, 0x05, 0x9A, 0x20, 0x19, 0x5A);

#undef INTERFACE
#define INTERFACE IMoaMmLinearList

DECLARE_INTERFACE_(IMoaMmLinearList, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS

	STDMETHOD(NewListValue) 			(THIS_ 
			PMoaMmValue 				pListValue) 
			PURE;

	STDMETHOD_(MoaLong, CountElements) 	(THIS_ 
			ConstPMoaMmValue 			pListValue) 
			PURE;

	STDMETHOD(GetValueByIndex)			(THIS_ 
			ConstPMoaMmValue 			pListValue,
			MoaLong 					index, 
			PMoaMmValue 				pResultValue) 
			PURE;
			
	STDMETHOD(SetValueByIndex)			(THIS_ 
			PMoaMmValue 				pListValue, 
			MoaLong 					index, 
			PMoaMmValue 				pNewValue)
			PURE;

	STDMETHOD(AppendValueToList)		(THIS_ 
			PMoaMmValue 				pListValue, 
			PMoaMmValue 				pElementValue) 
			PURE;
			
/* GetIndexByValue is the equivalent of the lingo function getPos. Walks
   the list, sets pResultIndex to a 1 based index into the first list
   position which contains an equivalent value. Sets to 0 if value isn’t
   found in list. */		
	STDMETHOD(GetIndexByValue)			(THIS_ 
			ConstPMoaMmValue 			pListValue,
			ConstPMoaMmValue 			pSearchValue,
			MoaLong FAR * 				pResultIndex) 
			PURE;
			
/* InsertValueIntoListByIndex inserts a value into a linear list at the specified
   index (1-based).  Existing values are moved down the list.*/
	STDMETHOD(InsertValueIntoListByIndex)	(THIS_ 
			PMoaMmValue					pListValue,
			MoaLong 					index, 
			ConstPMoaMmValue			pNewValue) 
			PURE;
			
/* DeleteValueByIndex is the equivalent of the lingo function deleteAt.
   use it to delete values in linear or property lists given their
   index. Returns out of range error if index is greater then size of 
   list. Index is 1 based index into list.*/
	STDMETHOD(DeleteValueByIndex)		(THIS_ 
			PMoaMmValue 				pListValue, 
			MoaLong 					index)
			PURE;

};

typedef IMoaMmLinearList FAR * PIMoaMmLinearList;

#undef INTERFACE

#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#endif /* _H_mmillist */
