
///////////////////////////////////////////////////////////////////////////////
//
// XThrwErr.h    $Revision: 2 $
//
// Copyright 1997 Macromedia, Inc.  All rights reserved.
//      This material is the confidential trade secret and proprietary
//      information of Macromedia, Inc.  It may not be reproduced, used,
//      sold or transferred to any third party without the prior written
//      consent of Macromedia, Inc.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////////

/*	History:

15jun98 alx Fix brackets on XSupport includes.
21jan98 alx extra define to enable it (XPtrCheck_USE_MACRO)
31dec97	alx	Make XPtrCheck a macro for debugging
07aug97	alx	Messed up cookie, oops -- added new constructors to TMoaError
22jul97	alx	Added header and XPtrCheck / changed bool to MoaBool, added const, adhere to
			XSupport standard header defines, and a tiny bit of formatting (sorry ely!)
XXxxx97	ely	Created
	
*/

#ifndef _H_XThrwErr
#define _H_XThrwErr


///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef _H_XMoaExpt
#include "XMoaExpt.h"
#endif

///////////////////////////////////////////////////////////////////////////////////
//
// Declares
//
///////////////////////////////////////////////////////////////////////////////////

template<class T,int safeValue> class XThrowingErr
{
	public:
		// constructor
		XThrowingErr() { m_errVal = safeValue; }
		
		
		// Methods
		const T& operator=(const T& rhs)
		{
			m_errVal = rhs;
			if (m_errVal != safeValue)
				throw m_errVal;
			return m_errVal;
		}

		operator T() const			{ return m_errVal; }
		operator MoaBool() const 	{ return (m_errVal != safeValue); }
		T& 		 Value() 			{ return m_errVal; }
		
	protected:
		T m_errVal;
};


class TMoaError
{
	public:
		// default constructor
		TMoaError() : m_errVal(kMoaErr_NoErr) {}
		// constructor for single line use
		TMoaError( const MoaError& err ) : m_errVal(err) 
		{ 
			if(m_errVal != kMoaErr_NoErr)
				kThrowMoaExceptionErr(CMoaRuntimeError,m_errVal);
		}
		
		const MoaError& operator=(const MoaError& rhs)
		{
			m_errVal = rhs;
			if (m_errVal != kMoaErr_NoErr)
				kThrowMoaExceptionErr(CMoaRuntimeError,m_errVal);
			return m_errVal;
		}
		operator MoaError() const	{ return m_errVal; }
		operator MoaBool() const	{ return (m_errVal != kMoaErr_NoErr); }
		MoaError& Value() 			{ return m_errVal; }

	protected:
		MoaError m_errVal;
};

#if XDEBUG || defined( XPtrCheck_USE_MACRO )
// when you are debugging you want this to be a macro,
// otherwise you will have to find the right breakpoint
// somewhere in a mess of different template instanciations.
#define XPtrCheck( ptr ) if( !(ptr) ) kThrowMoaException( CMoaInvalidArgument )

#else
// ptr checker -- throws when pointer is NOT valid.
template< class T > inline void XPtrCheck( T ptr )
{
	if( !ptr ) 
		kThrowMoaException( CMoaInvalidArgument );
}
#endif

#endif	// !_H_XThrwErr

// EOF
