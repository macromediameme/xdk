/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	abort_exit.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */

#ifndef __abort_exit__
#define __abort_exit__

#include <ansi_parms.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

__extern_c

extern void (* __stdio_exit)  (void);
extern void (* __console_exit)(void);

extern int	__aborting;

int		__atexit(void (* func)(void));
void	__exit(int status);

#if __dest_os == __be_os
	void	__setup_exit(void);
#else
	#define __setup_exit()
#endif

#if __dest_os == __win32_os
void _CleanUpMSL();
#endif

__end_extern_c

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif
/*     Change record
*/
