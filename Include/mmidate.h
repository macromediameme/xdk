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
/   $Workfile: mmiDate.h $
/
/ Version:
/   $Revision: 2 $
/
/ Purpose
/	Interface definition for converting between MoaMmValues of 
/	 ValueType() == kMoaMmValueType_Date and MoaWide values, as
/	 well routines to convert SumTotalOfDays values to Year/Month/Day
/	 triplets and visa versa.
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/mmiDate.h $
/   
/   2     6/23/99 11:55 AM Greggy
/   Checkin to synchronize revision numbers.
/   
/   2     10/20/98 12:01 PM Mroeder
/   Updated copyright date and changed headers to "you may use..."
/   
/   1     7/17/98 11:36a Cnuuja
/   
/   1     7/12/98 5:44p Cnuuja
/   initial definition
/   
****************************************************************************/

#ifndef	MMIDATE_H
#define	MMIDATE_H


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
/	IID_IMoaMmDate - MoaMmValue date manipulation functions.
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaMmDate: f67eacf0-11e7-11d2-9D18-00104b2797f3  */
DEFINE_GUID(IID_IMoaDrDate, 0xf67eacf0, 0x11e7, 0x11d2, 0x9D, 0x18, 0x00, 
							0x10, 0x4b, 0x27, 0x97, 0xf3);

#undef INTERFACE
#define INTERFACE IMoaDrDate

DECLARE_INTERFACE_(IMoaDrDate, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
				
	STDMETHOD(TotalSecondsToDateValue) 	(THIS_
			MoaWide				 		 TotalSecondsSince1970,
			PMoaMmValue 				 pValue)
			PURE;

	STDMETHOD(DateValueToTotalSeconds)	(THIS_ 
			ConstPMoaMmValue 			 pValue, 
			MoaWide			 			 *pTotalSecondsSince1970) 
			PURE; 
};

typedef IMoaDrDate FAR * PIMoaDrDate;

#if 0 /* Not ready yet.  Perhaps a MoaDrDate structure is neater? */
	STDMETHOD(DateValueToYearMonthDaySeconds)	(THIS_ 
			ConstPMoaMmValue 			 pValue, 
			PMoaLong					 pYear,
			PMoaLong					 pMonth,
			PMoaLong					 pDay,
			PMoaLong					 pSeconds)
			PURE;

	STDMETHOD(YearMonthDaySecondsToDateValue)	(THIS_ 
			MoaLong						 Year,
			MoaLong						 Month,
			MoaLong						 Day,
			MoaLong						 Seconds,
			PMoaMmValue 				 pValue) 
			PURE;
#endif
/* ---------------------------------------------------------------------------- */

#undef INTERFACE


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#ifdef	__cplusplus
}
#endif


#endif	/* MMIDATE_H */
