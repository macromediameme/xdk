
#ifndef _H_XMuiUI
#define _H_XMuiUI

/* ================================================================================

	XMuiUi.h    $Revision: 2 $

	Copyright (c) 1994, 1995, 1996, 1997 Macromedia, Inc.  All Rights Reserved
	
	You may utilize this source file to create and compile object code for use
	within products you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
	WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
	INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
	PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
	FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
	USE OR INABILITY TO USE THIS CODE.
	
	Purpose:
	
	Provides some useful utilities for drawing mui compliant ui.
	
	History:

	13oct98	alx Make DoMuiAlert default to note instead of stop
	10oct98	alx Added DoMuiAlert
	24sep98	LLB created based on XMacUI 

=================================================================================== */

///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////

#include "mmtypes.h"
#include "Mui.h"

///////////////////////////////////////////////////////////////////////////////////
//
// CMuiUI Constants
//
///////////////////////////////////////////////////////////////////////////////////

const short k54PercentGrey		  = (short)0x8888;
const short	k27PercentGrey		  = (short)0xBABA;
const short	k14PercentGrey		  = (short)0xDCDC;	

const short	kMuiWindowBackground  = (short)0xDDDD;
const short	kWhiteColor			  = (short)0xFFFF;
const short	kBlackColor			  = (short)0x0000;

const short	kShadowDark			  = k54PercentGrey;
const short	kShadowLight		  = k27PercentGrey;

const short	kDisabledGrey		  = k54PercentGrey;

///////////////////////////////////////////////////////////////////////////////////
//
// CMuiUI Declares
//
///////////////////////////////////////////////////////////////////////////////////

// DO NOT INSTATIATE THIS CLASS -- contains some drawing routines
class CMuiUI
{
// --------------------------------------------------------------------------------
// Construction and Destruction
// --------------------------------------------------------------------------------
	private:
		CMuiUI( void )	{}
		~CMuiUI( void ) {}

// --------------------------------------------------------------------------------
// Drawing routines
// --------------------------------------------------------------------------------
	public:
		enum FrameStyle {kFlatFrame = 0, kSunkenBevel, kFlatFrameAndSunkenBevel};

		static void 	DrawFrame( ConstPMoaMmNativeGCInfo pNativeGC,
								   const MoaRect& frameRect,
								   CMuiUI::FrameStyle frameStyle);
								   
		
		static MoaLong DoMuiAlert( ConstPMoaChar alertText, ConstPMoaChar alertTitle, TMuiAlertButtonType buttons = kMuiAlertButtons_Ok, MoaLong defaultButton = 1, TMuiAlertIcon icon = kMuiAlertIcon_Note );
};


#endif	// _H_XMuiUI

// EOF
