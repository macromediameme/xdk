/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	strtoul.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */
 
#ifndef __strtoul__
#define __strtoul__

#include <ansi_parms.h>
#include <stdio.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

__extern_c

extern unsigned long __strtoul(int		base, 
															 int		max_width,
															 FILE	* input_stream,
															 int	* chars_scanned,
															 int	* negative,
															 int	* overflow);

#ifdef __MSL_LONGLONG_SUPPORT__              /*mm 970110*/
extern unsigned long long __strtoull(int		base, 
															 int		max_width,
															 FILE	* input_stream,
															 int	* chars_scanned,
															 int	* negative,
															 int	* overflow);
#endif   /*__MSL_LONGLONG_SUPPORT__*/        /*mm 970110*/

__end_extern_c

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif
/*     Change record
mm 970110  Changed wrappers for long long support
*/
