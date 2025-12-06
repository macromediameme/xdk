
///////////////////////////////////////////////////////////////////////////////
//
// ByteSwap.h    $Revision: 2 $
//
// Copyright 1997 Macromedia, Inc.  All rights reserved.
//      This material is the confidential trade secret and proprietary
//      information of Macromedia, Inc.  It may not be reproduced, used,
//      sold or transferred to any third party without the prior written
//      consent of Macromedia, Inc.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////////

/*	History:

20jul98	alx	Made safe for windows
31aug97	alx	Added SwapPoint -- removed short2shorts from SwapRect
06may97	alx	Created
	
*/


#ifndef _H_ByteSwap
#define _H_ByteSwap

#ifndef _H_moatypes
#include "moatypes.h"
#endif

#ifdef MACINTOSH
#include <Types.h>
#endif // MACINTOSH


// inline swapping routines

inline void SwapShort( MoaShort& s )
{
	MoaUshort temp = (s >> 8) & 0xFF;
	s = temp | ((s & 0xFF) << 8);
}

inline void SwapShort( MoaUshort& s )
{
	MoaUshort temp = (s >> 8) & 0xFF;
	s = temp | ((s & 0xFF) << 8);
}

inline void Swap2Shorts( MoaShort& s1, MoaShort& s2 )
{
	MoaShort temp = s1;
	s1 = s2;
	s2 = temp;
}


inline void SwapLong( MoaLong& l )
{
	// first swap bytes within word
	MoaShort* sh = (MoaShort*)&l;
	::SwapShort( sh[0] );
	::SwapShort( sh[1] );
	
	// Swap the words within the long
	::Swap2Shorts( sh[0], sh[1] );
}

// do the usigned one too, this stops warnings...
inline void SwapLong( MoaUlong& l )
{
	// first swap bytes within word
	MoaShort* sh = (MoaShort*)&l;
	::SwapShort( sh[0] );
	::SwapShort( sh[1] );
	
	// Swap the words within the long
	::Swap2Shorts( sh[0], sh[1] );
}

#if defined( MACINTOSH ) || defined( USING_MACTYPES )
inline void SwapRect( Rect& r )
{
	::SwapShort( r.top );
	::SwapShort( r.left );
	::SwapShort( r.bottom );
	::SwapShort( r.right );
}

inline void SwapPoint( Point& p )
{
	::SwapShort( p.v );
	::SwapShort( p.h );
}
#else
inline void SwapRect( RECT& r )
{
	::SwapLong( r.top );
	::SwapLong( r.left );
	::SwapLong( r.bottom );
	::SwapLong( r.right );
}

inline void SwapPoint( POINT& p )
{
	::SwapLong( p.x );
	::SwapLong( p.y );
}
#endif
#endif	// _H_ByteSwap

// EOF
