/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	ansi_files.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 *	
 */

#ifndef __ansi_files__
#define __ansi_files__

#include <stdio.h>
#include <ansi_parms.h>

#define set_eof(file)										\
	do																		\
	{																			\
		(file)->state.io_state = __neutral;	\
		(file)->state.eof = 1;							\
		(file)->buffer_len = 0;							\
	}																			\
	while (0)

#define set_error(file)				\
	do													\
	{														\
		(file)->state.error = 1;	\
		(file)->buffer_len = 0;		\
	}														\
	while (0)

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

__extern_c

FILE *	__find_unopened_file(void);
void		__init_file(FILE * file, __file_modes mode, char * buff, size_t size);
void		__close_all(void);
int			__flush_all(void);
int			__file_to_num(FILE * file);
FILE *	__num_to_file(int file_num);
int __flush_line_buffered_output_files(void);
__end_extern_c

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset


#endif
/*     Change record
*/
