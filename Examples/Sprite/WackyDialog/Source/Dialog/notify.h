
///////////////////////////////////////////////////////////////////////////////
//
// Notify.h
//
// Copyright © 1994-2000 Macromedia, Inc.  All Rights Reserved
//
// You may utilize this source file to create and compile object code for use 
// within products you create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
// WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
// INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
// PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
// FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
// USE OR INABILITY TO USE THIS CODE.
//
///////////////////////////////////////////////////////////////////////////////


#ifndef _H_Notify
#define _H_Notify


#ifndef _H_MuiNotif
#include "MuiNotif.h"
#endif

#include "Dialog.h"


class DialogNotify : public MuiNotify
{
	public:
		DialogNotify( PMuiDialogWrapper, PIMoaMmSpriteCallback&, PIMoaMmAssetCallback&, TWackyDlgProperties& );
		~DialogNotify();
	
		// for live preview
		void ToggleCheckboxGroup( PMuiDialogWrapper pDialog, bool on );
		
		// Implemented
		virtual MoaBool 	HandleClick( PMuiDialogWrapper, MoaLong );
		virtual MoaBool 	HandleChanged( PMuiDialogWrapper, MoaLong );
		virtual MoaBool 	HandleShowHide( PMuiDialogWrapper, MoaBool show );
		virtual MoaBool 	HandleZoom( PMuiDialogWrapper, MoaBool zoomIn );
		virtual MoaBool 	HandleResize( PMuiDialogWrapper, PMoaRect newSize );
		virtual MoaBool 	HandleFocus( PMuiDialogWrapper, MoaLong, MoaBool enteringFocus );
		
	protected:
		virtual void		DoHelp();
		bool 				TestDialogState();
		void				UpdatePreview();
		
		PIMoaMmSpriteCallback& 		mSpriteCallback;	// this needs to stay live
		PIMoaMmAssetCallback& 		mMmAssetCallback;	// this needs to stay live
		TWackyDlgProperties&			mProps;
};
typedef DialogNotify FAR * PDialogNotify;

#endif	// !_H_Notify

// EOF
