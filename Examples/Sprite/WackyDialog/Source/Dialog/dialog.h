
///////////////////////////////////////////////////////////////////////////////
//
// Dialog.h
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

#ifndef _H_Dialog
#define _H_Dialog

///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////

#include "Asset.h"

// XSupport
#ifndef _H_MuiItem
#include "MuiItem.h"
#endif

// XDK
#ifndef _H_MoaFile2_
#include "MoaFile2.h"
#endif
#ifndef _H_ACClsid
#include "acclsid.h"
#endif

#ifdef MACINTOSH
#ifndef __QUICKDRAW__
#include <Quickdraw.h>
#endif
#endif // MACINTOSH


///////////////////////////////////////////////////////////////////////////////////
//
// Constants
//
///////////////////////////////////////////////////////////////////////////////////

enum
{
	kWindowBegin = 0,
		k3ColumnHGroupBegin,
			kPreviewHGroupBegin,
				kPreviewActor,
			kPreviewHGroupEnd,

			kButtonDivider,
			
			kMainControlsHGroupBegin,
				kVGroupLabelBegin,
					kNewSpriteTextLabel,			// Right aligned
					kPopupMenuLabel,  
					kExtraSpaceLabel,
					kHorizRadioGroupLabel,
					kVertRadioGroupLabel,
				kVGroupLabelEnd,

				kVGroupBegin,
					kNewSpriteTextEdit,
					kPopupMenu,
					kSlider,

					kHorizRadioVGroupBegin,				
						kHorizGroupRadioNone,
						kHorizSubHGroupBegin,
							kHorizSubRadio,
							kHorizSubEdit,
						kHorizSubHGroupEnd,

						kCheckboxHGroupBegin,
							kCheckboxSpacer,
							kCheckbox1,
							kCheckbox2,
						kCheckboxHGroupEnd,
						kCheckboxSpacer2,
					kHorizRadioVGroupEnd,

					kVertRadioVGroupBegin,				
						kVertGroupRadioNone,
						kVertRadioActivate,
						// we make an H group with a spacer to indent the other items and then a V group for the checkboxes.
						kVertCheckboxHGroupBegin,
							kVertCheckboxSpacer,
							kVertSubSetVGroupBegin,
								kVertCheckbox1,
								kVertCheckbox2,
								kVertCheckbox3,
								kMoreTextHGroupBegin,
									kMoreTextCheckbox,
									kMoreTextEdit,
								kMoreTextHGroupEnd,
							kVertSubSetVGroupEnd,
						kVertCheckboxHGroupEnd,
						kExtraSpaceLabel2,
					kVertRadioVGroupEnd,
				kVGroupEnd,
			kMainControlsHGroupEnd,
			
			kButtonDivider2,
			
			// import, cancel and help buttons
			kButtonVGroupBegin,
				kDefaultButton,
				kCancelButton,
				kHelpButton,
			kButtonVGroupEnd,
		k3ColumnHGroupEnd,
	kWindowEnd,	
	kNumItems
};

#ifndef UNUSED
	#define UNUSED(x) x
#endif


///////////////////////////////////////////////////////////////////////////////////
//
// MOA Stuff
//
///////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define	INTERFACE IMoaPropsDialog

// here is where we declare our own interface
DECLARE_INTERFACE_(IMoaPropsDialog, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS

	/* display the dialog */
	STDMETHOD(InvokePropsDialog) (THIS_ PMoaVoid asset, PIMoaDrAssetCallback, PIMoaMmAssetCallback)	PURE;
};

#undef INTERFACE

typedef IMoaPropsDialog FAR * PIMoaPropsDialog;

// you MUST define your own GUID here!  These ones are invalid!
DEFINE_GUID( CLSID( CMoaPropsDialog ), 0xF1FF3EFFL, 0x295E, 0x1FD1, 0xEC, 0xBA, 0x0F, 0x0E, 0xE2, 0x88, 0x9D, 0xEF );
DEFINE_GUID( IID( IMoaPropsDialog ), 0xFFAE3EFCL, 0x2A5A, 0xA2D1, 0xAF, 0xB3, 0x30, 0x45, 0x09, 0x84, 0xF8, 0x44 );

EXTERN_BEGIN_DEFINE_CLASS_INSTANCE_VARS( CMoaPropsDialog )
EXTERN_END_DEFINE_CLASS_INSTANCE_VARS

EXTERN_BEGIN_DEFINE_CLASS_INTERFACE( CMoaPropsDialog, IMoaPropsDialog )
	EXTERN_DEFINE_METHOD( MoaError, InvokePropsDialog, ( PMoaVoid asset, PIMoaDrAssetCallback, PIMoaMmAssetCallback ) )
EXTERN_END_DEFINE_CLASS_INTERFACE


///////////////////////////////////////////////////////////////////////////////////
//
// WackyPropsDialog
//
///////////////////////////////////////////////////////////////////////////////////
  
class WackyPropsDialog
{
	public:
		WackyPropsDialog( CWackyDlgAsset_IMoaMmXAsset FAR *, PIMoaDrAssetCallback, PIMoaMmAssetCallback );
		~WackyPropsDialog();
		
		// accessors
		MoaLong				DoPropsDialog( void );			// returns whether or not to stop process.
	
	protected:
		void 				FixMuiItemSize( PMuiItemWrapper pItemWrapper, MoaUlong width, MoaUlong height );

		void 	 			CheckForLivePreview();
		void 	 			BuildLivePreview( PMuiItemWrapper* myItemArray, PTMuiItem cItemArray, ConstPMoaChar missingString );
		
	private:
		bool				 mUsePreview;
		bool 				 mHideStuff;
		PIMoaMmAssetCallback mMmAssetCallback;
		
		CWackyDlgAsset_IMoaMmXAsset * mAsset;
};

#endif	// !_H_Dialog

// EOF
