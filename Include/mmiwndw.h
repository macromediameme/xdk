/*==========================================================================\
|                                                                           |
|                   Copyright (c) 1994-1998, Macromedia, Inc.               |
|                                                                           |
|	You may utilize this source file to create and compile object code for 	|
|	use within products you may create.  THIS CODE IS PROVIDED "AS IS", 	|
|	WITHOUT WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED 		|
|	WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A|
|	PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE |
|	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES 	|
|	ARISING OUT OF YOUR USE OR INABILITY TO USE THIS CODE.					|
|                                                                           |
\==========================================================================*/

#ifndef	NO_PRAGMA_ONCE
#pragma	once
#endif

/****************************************************************************
/ Filename
/   $Workfile: mmiwndw.h $
/
/ Version:
/   $Revision: 2 $
/
/ Purpose
/	Windows window & event services callback interface definitions.
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/mmiwndw.h $
/   
/   2     6/23/99 11:55 AM Greggy
/   Checkin to synchronize revision numbers.
/   
/   3     10/19/98 11:27 AM Mroeder
/   Changed header from "Confidential" to "You may use..." because these
/   files are in the XDK. Updated copyright notice to cover 1998. 
/   
/   2     1/30/98 10:51a Greggy
/   Unified header format. Based the guard tag directly on the filename.
/   
/	30oct96 dws initial defn of IMoaMmWndWin, split from mmiservc.h
****************************************************************************/

#ifndef	MMIWNDW_H
#define	MMIWNDW_H


#include "moaxtra.h"	 	/* MOA shell */
#include "moastdif.h"		/* MOA standard interfaces */
#include "mmtypes.h"		/* multimedia types */


#ifdef	__cplusplus
extern "C" {
#endif


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma push
	#pragma pointers_in_D0
#endif /* MACINTOSH && MWERKS && !powerc */


/* ----------------------------------------------------------------------------
/
/	IMoaMmWndWin - Windows window & event services
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaMmWndWin: D9088161-32BF-11d0-8151-00AA005F3C08 */
DEFINE_GUID(IID_IMoaMmWndWin, 0xd9088161, 0x32bf, 0x11d0, 0x81, 0x51, 0x0, 
								0xaa, 0x0, 0x5f, 0x3c, 0x8);

#undef INTERFACE
#define INTERFACE IMoaMmWndWin

DECLARE_INTERFACE_(IMoaMmWndWin, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	
	STDMETHOD_(MoaLong, WinDialogBox)	(THIS_ 
			XtraResourceCookie 			resCookie,
			 ConstPMoaChar 				lpszTemplate, 
			 PMoaVoid 					dlgprc) 
			 PURE;

	STDMETHOD(WinGetParent)				(THIS_ 
			MoaMmHInst FAR * 			phInst, 
			MoaMmHWnd FAR * 			phWnd) 
			PURE; 
		
	STDMETHOD_(MoaLong, WinDialogBoxParam)	(THIS_ 
			XtraResourceCookie 			resCookie, 
			ConstPMoaChar 				lpszTemplate, 
			PMoaVoid 					dlgprc, 
			MoaLong 					lparamInit) 
			PURE;

	/* Win: Use these to surround other Windows API calls
		invoking modal dialogs.  Not needed if using
		WinDialogBox() or WinDialogBoxParam().
	*/
	
	STDMETHOD(WinPrepareDialogBox)		(THIS_ 
			PMoaMmDialogCookie 			pDialogCookie) 
			PURE;
			
	STDMETHOD(WinUnprepareDialogBox)	(THIS_ 
			MoaMmDialogCookie 			dialogCookie) 
			PURE;

};

typedef IMoaMmWndWin FAR * PIMoaMmWndWin;

/* ---------------------------------------------------------------------------- */

#undef INTERFACE

#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#ifdef	__cplusplus
}
#endif


#endif	/* MMIWNDW_H */
