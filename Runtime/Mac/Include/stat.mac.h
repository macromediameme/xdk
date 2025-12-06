/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	File:		stat.h
 *				©1993-1996 metrowerks Inc. All rights reserved
 *	Author:		Berardino E. Baratta
 *
 *	Content:	Interface file to standard UNIX-style entry points ...
 *
 *	NB:			This file implements some UNIX low level support.  These functions
 *				are not guaranteed to be 100% conformant.
 */

#ifndef	_STAT
#define	_STAT

#ifndef _TIME
#include <time.h>
#endif
/*
 *	Local typedefs for stat struct
 */
typedef unsigned long	mode_t;
typedef unsigned long	ino_t;
typedef unsigned long	dev_t;
typedef short			nlink_t;
typedef unsigned long	uid_t;
typedef unsigned long	gid_t;
typedef long			off_t;

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif


/*
 *	(stat) st_mode bit values (only ones relevant for the Mac)
 *	NB: all modes marked as (GUSI) mean that the mode is used only by GUSI
 *		(Grand Unified Sockets Interface).
 */
#define S_IFMT		0x0F00		/* type of file */
#define   S_IFIFO	0x0100		/*	 fifo queue */                 /*mm 970730 */
#define   S_IFCHR	0x0200		/*   character special (GUSI) */
#define   S_IFDIR	0x0400		/*   directory */
#define   S_IFBLK	0x0600		/*	 blocking stream */            /*mm 970730 */
#define   S_IFREG	0x0800		/*   regular */
#define   S_IFLNK	0x0A00		/*   symbolic link */
#define   S_IFSOCK	0x0E00		/*   socket (GUSI) */

/*
 *	File type macros
 */
#define S_ISFIFO(m)	(((m)&(S_IFMT)) == (S_IFIFO))
#define S_ISDIR(m)	(((m)&(S_IFMT)) == (S_IFDIR))
#define S_ISCHR(m)	(((m)&(S_IFMT)) == (S_IFCHR))
#define S_ISBLK(m)	(((m)&(S_IFMT)) == (S_IFBLK))
#define S_ISREG(m)	(((m)&(S_IFMT)) == (S_IFREG))

struct stat
{
	mode_t		st_mode;		/* File mode; see #define's below */
	ino_t		st_ino;			/* File serial number */
	dev_t		st_dev;			/* ID of device containing this file */
	nlink_t		st_nlink;		/* Number of links */
	uid_t		st_uid;			/* User ID of the file's owner */
	gid_t		st_gid;			/* Group ID of the file's group */
	dev_t		st_rdev;		/* Device type */
	off_t		st_size;		/* File size in bytes */
	time_t		st_atime;		/* Time of last access */
	time_t		st_mtime;		/* Time of last data modification */
	time_t		st_ctime;		/* Time of last file status change */
	long		st_blksize;		/* Optimal blocksize */
	long		st_blocks;		/* blocks allocated for file */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 *	Get state information on a file.
 */
int stat(const char *path, struct stat *buf);

/*
 *	Get state information on an open file.
 */
int fstat(int fildes, struct stat *buf);

/*
 *	Create a directory (mode is ignored on the mac).
 */
int mkdir(const char *path, int mode);

#ifdef __cplusplus
}
#endif


#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif
/*     Change record
 *    mm 970730     Restored some file modes apparently omitted in move from ANSI/Plauger stat.h
*/
