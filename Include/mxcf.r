/*
	File: mxcf.r		(mac)

	Copyright (c) 1996-1998, Macromedia, Inc.  All rights reserved.
	
	You may utilize this source file to create and compile object code for 
	use within products you may create.  THIS CODE IS PROVIDED "AS IS", 
	WITHOUT WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED 
	WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A
	PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE 
	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES 
	ARISING OUT OF YOUR USE OR INABILITY TO USE THIS CODE.

	Rez template for the standard MXcf resource.

	This file should be rezzed into every fat Macintosh Xtra.
	It is not necessary for an application.

	951128	Release 1.39: No changes. (srj)
	950929	Corrected for MW Rez. (srj)
	950805	Original. (srj)
*/

type 'TMPL' {
	wide array {
		pstring;
		literal longint;
	};
};

resource 'TMPL' (128, "MXcf") {
	{
		"Pad for long count", 			'FWRD',
		"MemberArray", 					'OCNT',
		"-----", 						'LSTC',
		"Arch Type", 					'TNAM',
		"Offset (0 = default)", 		'DLNG',
		"Length (0 = default)", 		'DLNG',
		"-----", 						'LSTE',
	}
};

type 'MXcf' {
	longint = $$CountOf(memberArray);
	wide array memberArray {
		literal longint archType, kPowerPC = 'pwpc', k68kCodeResource = 'cr68';
		longint offset, kZeroOffset = 0;
		longint length, kWholeFork = 0;
	};
};

resource 'MXcf' (128) {
	{
		kPowerPC, kZeroOffset, kWholeFork,
		k68kCodeResource, kZeroOffset, kWholeFork,
	}
};

