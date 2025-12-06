/*
	File: mixpal.h (core)

	Copyright (c) 1994, 1995, 1996, 1997 Macromedia, Inc.  All Rights Reserved

	You may utilize this source file to create and compile object code for use within products
	you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, AND
	MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE
	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR
	USE OR INABILITY TO USE THIS CODE.

	Abstract:

  	Revision history:
	12nov96	greggy	Shamelessly stolen from "mixpix.h"
*/

#ifndef _H_mixpal
#define _H_mixpal

#ifndef _H_mixagent
	#include "mixagent.h"
#endif

#ifndef	_H_mixpix
	#include "mixpix.h"
#endif

#if defined(__MWERKS__) && defined(__MC68K__)
#pragma push
#pragma pointers_in_D0
#endif

typedef	RenderPixelColorSpace FAR *PRenderPixelColorSpace;
typedef	const RenderPixelColorSpace FAR *ConstPRenderPixelColorSpace;

#undef INTERFACE
#define INTERFACE IMoaReceptorPalette
DECLARE_INTERFACE_(IMoaReceptorPalette, IMoaReceptor)
{
	STD_IUNKNOWN_METHODS
	
	STDMETHOD(SetRefCon)(THIS_
		moa_in PMoaVoid refCon
	) PURE;

	STDMETHOD(SetStatus)(THIS_
		moa_in MoaError status
	) PURE;

	STDMETHOD(SetPalette)(THIS_
		moa_in ConstPRenderPixelColorSpace pRenderPixelColorSpace
	) PURE;

	STDMETHOD(EndPalette)(THIS) PURE;
};
typedef IMoaReceptorPalette FAR * PIMoaReceptorPalette;
DEFINE_GUID(IID_IMoaReceptorPalette, 0xbedde900, 0x3cac, 0x11d0, 0xa1, 0x83, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00);

#if defined(__MWERKS__) && defined(__MC68K__)
#pragma pop
#endif

#endif

