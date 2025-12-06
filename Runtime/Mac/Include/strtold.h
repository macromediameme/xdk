/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	strtod.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */
 
#ifndef __strtod__
#define __strtod__

#include <ansi_parms.h>
#include <stdio.h>               /* mm 970905 */

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

__extern_c

extern long double __strtold(int		max_width,
														 FILE	* input_stream,
														 int	* chars_scanned,
														 int	* overflow);

__end_extern_c

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif
/*     Change record
 * mm 970905  added include of stdio.h to allow this header to be included first.
 */
