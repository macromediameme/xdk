/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	stdio.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */
 
#ifndef __cstdio__
#define __cstdio__

#include <ansi_parms.h>

__namespace(__stdc_space(stdio))

#include <size_t.h>
#include <null.h>
#include <va_list.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

enum __file_kinds {
	__closed_file,
	__disk_file,
	__console_file,
	__string_file,
	__unavailable_file
};

enum __open_modes {
	__must_exist,
	__create_if_necessary,
	__create_or_truncate
};

enum __io_modes {
	__read				= 1,
	__write				= 2,
	__read_write		= 3,
	__append			= 4
};

typedef struct {
	unsigned int	open_mode		: 2;
	unsigned int	io_mode			: 3;
	unsigned int	buffer_mode		: 2;
	unsigned int	file_kind		: 2;
	unsigned int	binary_io		: 1;
} __file_modes;

enum __io_states {
	__neutral,
	__writing,
	__reading,
	__rereading
};

typedef struct {
	unsigned int	io_state	: 3;
	unsigned int	free_buffer	: 1;
	unsigned char	eof;
	unsigned char	error;
} __file_state;

typedef unsigned long	__file_handle;
#if __dest_os == __be_os          /* mm 970708 */
typedef long long	fpos_t;   /* we have 64 bit file sizes & positions */     /* mm 970708 */
#else                             /* mm 970708 */
typedef unsigned long	fpos_t;
#endif                            /* mm 970708 */

typedef struct _FILE FILE;

enum __io_results {
     __no_io_error,
     __io_error,
     __io_EOF         /* mm 961031 */
};

typedef void (* __idle_proc)  (void);
typedef int  (* __pos_proc)   (__file_handle file, fpos_t * position, int mode, __idle_proc idle_proc);     /* mm 970708 */
typedef int  (* __io_proc)    (__file_handle file, unsigned char * buff, size_t * count, __idle_proc idle_proc);
typedef int	 (* __close_proc) (__file_handle file);

#define __ungetc_buffer_size	2

struct _FILE {
	__file_handle		handle;
	__file_modes		mode;
	__file_state		state;
	unsigned char		char_buffer;
	unsigned char		char_buffer_overflow;
	unsigned char		ungetc_buffer[__ungetc_buffer_size];
	unsigned long		position;
	unsigned char *		buffer;
	unsigned long		buffer_size;
	unsigned char *		buffer_ptr;
	unsigned long		buffer_len;
	unsigned long		buffer_alignment;
	unsigned long		saved_buffer_len;
	unsigned long		buffer_pos;
	__pos_proc			position_proc;
	__io_proc			read_proc;
	__io_proc			write_proc;
	__close_proc		close_proc;
	__idle_proc			idle_proc;
};

#define _IONBF	0
#define _IOLBF	1
#define _IOFBF	2

#define BUFSIZ			 4096
#define EOF				   -1
#define FOPEN_MAX		   35
#define FILENAME_MAX	  256

#if __dest_os == __mac_os
#define L_tmpnam		 32
#else
#define	L_tmpnam		 512
#endif

#define TMP_MAX		32767

#define SEEK_SET	0
#define SEEK_CUR	1
#define SEEK_END	2

__extern_c               /* mm 970708 */

#if __dest_os == __be_os

#define L_ctermid  32
#define L_cuserid  32
#define STREAM_MAX FOPEN_MAX

FILE   *popen(const char *cmd, const char *type);/* mm 970708 */
int     pclose(FILE *fp);                        /* mm 970708 */

#endif /* __be_os */

#define stdin  	(&__files[0])   /* mm 961031 */    /*MW-mm 961203 */
#define stdout	(&__files[1])   /* mm 961031 */    /*MW-mm 961203 */
#define stderr	(&__files[2])   /* mm 961031 */    /*MW-mm 961203 */
extern FILE		__files[];      /* mm 961031 */    /*MW-mm 961203 */

int			remove(const char * name);
int			rename(const char * old_name, const char * new_name);

char *	tmpnam(char * name);
FILE *	tmpfile(void);

void		setbuf (FILE * file, char * buff);
int			setvbuf(FILE * file, char * buff, int mode, size_t size);

#if __dest_os == __be_os                                        /* mm 970708 */
int         setbuffer(FILE *stream, char *buf, size_t size);    /* mm 970708 */
int         setlinebuf(FILE *stream);                           /* mm 970708 */
#endif                                                          /* mm 970708 */

int			fclose(FILE * file);
int			fflush(FILE * file);

FILE *	fopen  (const char * name, const char * mode);
FILE *	freopen(const char * name, const char * mode, FILE * file);

#if __dest_os == __be_os

FILE *  fdopen(int fd, const char *type);
int     fileno(FILE *fd);

#endif

void		setbuf (FILE * file, char * buff);
int			setvbuf(FILE * file, char * buff, int mode, size_t size);

int			fprintf(FILE * file, const char * format, ...);
int			fscanf (FILE * file, const char * format, ...);

int			printf(const char * format, ...);
int			scanf (const char * format, ...);

int			sprintf(      char * s, const char * format, ...);
int			sscanf (const char * s, const char * format, ...);
#if __INTEL__
int         swprintf(wchar_t * s, const wchar_t * format, ...);
#endif


int			__vfscanf(FILE * file,    const char * format, va_list arg);
int			__vsscanf(const char * s, const char * format, va_list arg);

int			vfprintf(FILE * file, const char * format, va_list arg);
int			vprintf(const char * format, va_list arg);
int			vsprintf(char * s, const char * format, va_list arg);

int			fgetc(FILE * file);
char *	fgets(char * s, int n, FILE * file);

int			fputc(int c, FILE * file);
int			fputs(const char * s, FILE * file);

char *	gets(char * s);

int			puts(const char * s);

int			ungetc(int c, FILE * file);

size_t	fread (      void * ptr, size_t memb_size, size_t num_memb, FILE * file);
size_t	fwrite(const void * ptr, size_t memb_size, size_t num_memb, FILE * file);

int			fgetpos(FILE * file, fpos_t * pos);
long		ftell  (FILE * file);
fpos_t     _ftell(FILE *);                    /* mm 970708 */

int			fsetpos(FILE * file, const fpos_t * pos);
int			fseek  (FILE * file, long offset, int mode);
int         _fseek(FILE *, fpos_t, int);     /* mm 970708 */

void		rewind(FILE * file);

void		clearerr(FILE * file);

void		perror(const char * s);

int			__get_char(FILE * file);
int			__put_char(int c,FILE * file);

FILE *	__handle_open  (__file_handle handle, const char * mode);
FILE *	__handle_reopen(__file_handle handle, const char * mode, FILE * file);

void		__set_idle_proc(FILE * file, __idle_proc idle_proc);

#if (__dest_os	== __win32_os)

	/*
	 * I'm putting this declaration here because it is in Visual C++'s stdio.h
	 * I copied this declaration from unix.win32.h. They should match.
	 */
	 FILE *fdopen(int fildes, char *type);

#endif


__end_extern_c

#ifdef __cplusplus

inline int getc(FILE * file)
	{ return file->buffer_len-- ? *file->buffer_ptr++ : __get_char(file); }

inline int putc(int c, FILE *file)
	{ return file->buffer_len-- ? (*file->buffer_ptr++ = c) : __put_char(c, file); }

inline int getchar()
	{ return getc(stdin); }

inline int putchar(int c)
	{ return putc(c, stdout); }

inline int feof(FILE * file)
	{ return file->state.eof; }

inline int ferror(FILE * file)
	{ return file->state.error; }

#else

int			getc(FILE * file);
int			putc(int c, FILE * file);

#define getc(file)		((file)->buffer_len-- ? (int)  *(file)->buffer_ptr++      : __std(__get_char)(file))
#define putc(c, file)	((file)->buffer_len-- ? (int) (*(file)->buffer_ptr++ = c) : __std(__put_char)(c, file))

int			getchar(void);
int			putchar(int c);

#define getchar()			__std(getc)(stdin)
#define putchar(c)		__std(putc)(c, stdout)

int			feof  (FILE * file);
int			ferror(FILE * file);

#define feof(file)		((file)->state.eof)
#define ferror(file)	((file)->state.error)

#endif

__end_namespace(stdc_space(stdio))

__import_stdc_into_std_space(stdio)

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif /* __cstdio__ */

/*     Change record
 * mm 961031  Changes for Pascal
 * mm 961203  Changed files to __files
 * mm 970708  Inserted Be changes
 */
