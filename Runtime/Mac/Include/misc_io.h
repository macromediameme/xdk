/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	misc_io.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */

#ifndef __stdio_atexit__
#define __stdio_atexit__

#include <ansi_parms.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

__extern_c

void	__stdio_atexit(void);

__end_extern_c

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif
/*     Change record
*/
