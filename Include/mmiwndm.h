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
/   $Workfile: mmiwndm.h $
/
/ Version:
/   $Revision: 2 $
/
/ Purpose
/	Macintosh window & event services callback interface definitions.
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/mmiwndm.h $
/   
/   2     6/23/99 11:55 AM Greggy
/   Checkin to synchronize revision numbers.
/   
/   3     10/19/98 11:26 AM Mroeder
/   Changed header from "Confidential" to "You may use..." because these
/   files are in the XDK. Updated copyright notice to cover 1998. 
/   
/   2     1/30/98 10:51a Greggy
/   Unified header format. Based the guard tag directly on the filename.
/   
/	30oct96 dws initial defn of IMoaMmWndMac, split from mmiservc.h
****************************************************************************/

#ifndef	MMIWNDM_H
#define	MMIWNDM_H


#include "moaxtra.h"	 	/* MOA shell */
#include "moastdif.h"		/* MOA standard interfaces */
#include "mmtypes.h"		/* multimedia types */
#include "mmiservc.h"		/* other mmi interfaces we rely on */


#ifdef	__cplusplus
extern "C" {
#endif


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma push
	#pragma pointers_in_D0
#endif /* MACINTOSH && MWERKS && !powerc */


/* ----------------------------------------------------------------------------
/
/	IMoaMmWndMac - Macintosh window & event services
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaMmWndMac: D9088160-32BF-11d0-8151-00AA005F3C08 */
DEFINE_GUID(IID_IMoaMmWndMac, 0xd9088160, 0x32bf, 0x11d0, 0x81, 0x51, 0x0, 
								0xaa, 0x0, 0x5f, 0x3c, 0x8);

#undef INTERFACE
#define INTERFACE IMoaMmWndMac

DECLARE_INTERFACE_(IMoaMmWndMac, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	
	STDMETHOD(MacHandleEvent) 			(THIS_ 
			PMoaVoid 					pEventRecord) 
			PURE;
			
	STDMETHOD(MacPrepareModalDialog)	(THIS_ 
			PMoaMmDialogCookie 			pDialogCookie) 
			PURE;
			
	STDMETHOD(MacModalDialog)			(THIS_ 
			MoaMmDialogCookie 			dialogCookie, 
			PMoaVoid 					filterProcUPP, 
			MoaShort FAR * 				itemHit) 
			PURE;
			
	STDMETHOD(MacUnprepareModalDialog)	(THIS_ 
			MoaMmDialogCookie 			dialogCookie) 
			PURE;
			
	STDMETHOD_(MoaLong, MacAlert)		(THIS_ 
			MoaLong 					alertID, 
			PMoaVoid 					filterProcUPP) 
			PURE;
			
	STDMETHOD(MacRegisterWindow)		(THIS_ 
			PIMoaMmMacEventHandler 		pEventHandler,
			PMoaMmMacWindow 			pWindow, 
			MoaMmRegWindowFlags 		flags, 
			PMoaVoid 					refCon) 
			PURE; 
			
	STDMETHOD(MacUnregisterWindow)		(THIS_
			 PIMoaMmMacEventHandler 	pEventHandler) 
			 PURE; 
			 
	STDMETHOD(MacDragWindow)			(THIS_ 
			PMoaMmMacWindow 			pWindow, 
			PMoaPoint 					pStartPoint, 
			PMoaRect 					pLimitRect) 
			PURE; 
			
	STDMETHOD(MacSelectWindow)			(THIS_ 
			PMoaMmMacWindow 			pWindow) 
			PURE; 
			
	STDMETHOD(MacShowWindow)			(THIS_ 
			PMoaMmMacWindow 			pWindow) 
			PURE; 
			
	STDMETHOD(MacHideWindow)			(THIS_ 
			PMoaMmMacWindow 			pWindow) 
			PURE; 
};

typedef IMoaMmWndMac FAR * PIMoaMmWndMac;


/* ---------------------------------------------------------------------------- */

#undef INTERFACE


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#ifdef	__cplusplus
}
#endif


#endif	/* MMIWNDM_H */
