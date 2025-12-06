
#ifndef _H_MuiNotif
#define _H_MuiNotif

/* ================================================================================

	MuiNotif.h    $Revision: 2 $

	Copyright (c) 1994, 1995, 1996 Macromedia, Inc.  All Rights Reserved
	
	You may utilize this source file to create and compile object code for use
	within products you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
	WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
	INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
	PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
	FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
	USE OR INABILITY TO USE THIS CODE.
	
	Purpose:
	
	MuiNotif provides a c++ wrapper for the standard interface clients using 
	MuiDialog must provide in order to be notified of changes/events occuring
	within their dialog.
	
	History:

	24apr97	alx	Added brief descriptions
	08mar97	jcw	new header file format, documentation for external consumption.
	13feb97	alx	Created - C++ Wrappers for an Abstract IMoaNotification

=================================================================================== */

///////////////////////////////////////////////////////////////////////////////////
//
// Description  
//
///////////////////////////////////////////////////////////////////////////////////

/*

	This file provides wrappers for the notification object.  To use this simply
	override this class and the 6 pure virtual functions and pass that object to
	MuiDialogWrapper as the callback.
	
	Please see example in XDK for usage.
	
*/


///////////////////////////////////////////////////////////////////////////////////
//
// Includes  
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef _H_MuiItem
#include "MuiItem.h"
#endif


#ifndef _H_MuiDlg
#include "MuiDlg.h"
#endif

#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma push
	#pragma pointers_in_D0
#endif 


///////////////////////////////////////////////////////////////////////////////////
//
// MuiNotify Declaration  
//
///////////////////////////////////////////////////////////////////////////////////

class MuiNotify
{
	public:
		MuiNotify( PMuiDialogWrapper refCon );
		virtual ~MuiNotify( void );
		
		// PURE VIRTUALS - You must override these
		virtual MoaBool HandleClick( PMuiDialogWrapper, MoaLong ) = 0;
		virtual MoaBool HandleChanged( PMuiDialogWrapper, MoaLong ) = 0;
		virtual MoaBool HandleShowHide( PMuiDialogWrapper, MoaBool show ) = 0;
		virtual MoaBool HandleZoom( PMuiDialogWrapper, MoaBool zoomIn ) = 0;
		virtual MoaBool HandleResize( PMuiDialogWrapper, PMoaRect newSize ) = 0;
		virtual MoaBool HandleFocus( PMuiDialogWrapper, MoaLong, MoaBool enteringFocus ) = 0;
		
		// accessors
		virtual PMuiDialogWrapper GetDialogRef( void ) const;
		
	private:
		// this is so that MuiDialogWrapper can call GetCallback();
		friend class MuiDialogWrapper;

		PIMoaNotificationClient GetCallback( void ) const;
		
		PIMoaNotificationClient	mCallback;
		PMuiDialogWrapper		mDialogRef;
};

typedef MuiNotify FAR * PMuiNotify;
typedef const MuiNotify ConstPMuiNotify;



///////////////////////////////////////////////////////////////////////////////////
//
// CMuiWedge Declaration  
//
///////////////////////////////////////////////////////////////////////////////////

// CMuiWedge 0xEBE0808885E611D0813A000502482E5F
DEFINE_GUID(CLSID( CMuiNotifyWedge ), 0xEBE08088L, 0x85E6, 0x11D0, 0x81, 0x3A, 0x00, 0x05, 0x02, 0x48, 0x2E, 0x5F);


//---------------------------------------------------------------------------------
//  CLASS INSTANCE VARIABLES
//---------------------------------------------------------------------------------

EXTERN_BEGIN_DEFINE_CLASS_INSTANCE_VARS( CMuiNotifyWedge )
EXTERN_END_DEFINE_CLASS_INSTANCE_VARS


//---------------------------------------------------------------------------------
//  CLASS INTERFACE(S)
//---------------------------------------------------------------------------------

EXTERN_BEGIN_DEFINE_CLASS_INTERFACE( CMuiNotifyWedge, IMoaNotificationClient )
	EXTERN_DEFINE_METHOD( MoaError, Notify,  (THIS_ ConstPMoaNotifyID, PMoaVoid, PMoaVoid) )
EXTERN_END_DEFINE_CLASS_INTERFACE



#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma pop
#endif 

#endif 	// _H_MuiNotif

// EOF
