/*==========================================================================\
|                                                                           |
|                   Copyright (c) 1998, Macromedia, Inc.					|
|                                                                           |
|      This material is the confidential trade secret and proprietary       |
|      information of Macromedia, Inc.  It may not be reproduced, used,     |
|      sold or transferred to any third party without the prior written     |
|      consent of Macromedia, Inc.  All rights reserved.                    |
|                                                                           |
\==========================================================================*/

#ifndef	NO_PRAGMA_ONCE
#pragma	once
#endif

/****************************************************************************
/ Filename
/   $Workfile: moaplat.h $
/
/ Version:
/   $Revision: 2 $
/
/ Purpose
/   Include appropriate moatyedg file for the platform.
/
/ Notes
/   (Put any other relevant notes about dependencies or side
/   effects here).
/
/ Modification History
****************************************************************************/


#ifndef _H_moaplat
#define	_H_moaplat


/*--------------------------------------------------------------------------*/
/* For Metrowerks CoreWarrior for Windows  
/  Strictly speaking, this ought to go further down in the headers.
/  However, the fiddly tweaks needed to set up the proper ifdef conditions
/  make the whole thing more complicated than it's worth. */ 
#if defined(__INTEL__)  /* CW's symbol for compiling under Windows */
	#define _WINDOWS	/* symbols the rest of the system expects */
	#define _WIN32
	#define NO_STRICT 1 /* otherwise, CW defines STRICT, which makes us barf. */ 
#endif



/*--------------------------------------------------------------------------*/
#if (defined(WINDOWS) || defined(_WINDOWS)|| defined(WINVER))
	#if (defined(WIN32) || defined(_WIN32))
		#if (defined(__INTEL__))
			#include "moatyedg.h" /* CW Mac does not understand windows paths; 
								  /  you must define this path explicitly in project settings. */
		#else
			#include "win32/moatyedg.h"
		#endif
	#else
		#include "win16/moatyedg.h"
	#endif
#endif /* WINDOWS || _WINDOWS */


#if (defined(MACINTOSH) || defined(_MACINTOSH) || defined(macintosh))						   
	#include "moatyedg.h"
#endif




/*-------------------------------------------------------------------------*/

#endif	/* _H_moaplat */
