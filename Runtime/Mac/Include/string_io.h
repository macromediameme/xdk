/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	string_io.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */

#ifndef __string_io__
#define __string_io__

#include <stdio.h>
#include <ansi_parms.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

__extern_c

int		__open_string_file(FILE * file, char * str, size_t n, int io_state);

int		__read_string		 (__file_handle handle, unsigned char * buffer, size_t * count, __idle_proc idle_proc);
int		__write_string	 (__file_handle handle, unsigned char * buffer, size_t * count, __idle_proc idle_proc);
int		__close_string	 (__file_handle handle);

__end_extern_c

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif
/*     Change record
*/
