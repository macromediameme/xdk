
#ifndef _H_XWinUI
#define _H_XWinUI

/* ================================================================================

	XWinUI.h    $Revision: 2 $

	Copyright (c) 1994, 1995, 1996, 1997 Macromedia, Inc.  All Rights Reserved
	
	You may utilize this source file to create and compile object code for use
	within products you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
	WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
	INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
	PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
	FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
	USE OR INABILITY TO USE THIS CODE.
	
	Purpose:
	
	Provides some useful utilities for drawing mui compliant windows ui.
	
	History:

	24sep98	LLB created based on XMacUI 

=================================================================================== */

///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////

#ifdef _WINDOWS

#ifndef _H_XMuiUI
#include "XMuiUI.h"
#endif

///////////////////////////////////////////////////////////////////////////////////
//
// CWinUI Declaration
//
///////////////////////////////////////////////////////////////////////////////////

// DO NOT INSTATIATE THIS CLASS -- contains some drawing routines
class CWinUI
{
// --------------------------------------------------------------------------------
// Construction and Destruction
// --------------------------------------------------------------------------------
	private:
		CWinUI( void )	{}
		~CWinUI( void ) {}

// --------------------------------------------------------------------------------
// Drawing routines
// --------------------------------------------------------------------------------
	public:
		static void 	DrawFrame(HDC hDC, const RECT&, CMuiUI::FrameStyle frameStyle);
};


#endif  // _WINDOWS
#endif	// _H_XWinUI

// EOF
