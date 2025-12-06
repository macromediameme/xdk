///////////////////////////////////////////////////////////////////////////////
//
// XMoaHelp.h    $Revision: 2 $
//
// Copyright 1996-97 Macromedia, Inc.  All rights reserved.
//      This material is the confidential trade secret and proprietary
//      information of Macromedia, Inc.  It may not be reproduced, used,
//      sold or transferred to any third party without the prior written
//      consent of Macromedia, Inc.  All rights reserved.
//
///////////////////////////////////////////////////////////////////////////////

/*	History:

21may98 alx added get size to handle locker
08dec97 alx Windows warnings
07aug97 alx Added MoaReleaser
13jun97 alx Created

*/

#ifndef _H_XMoaHelp
#define _H_XMoaHelp

#ifndef _H_MuiHelpr
#include "MuiHelpr.h"
#endif

template <class Tpointer> class MoaHandleLocker
{
	public:
		MoaHandleLocker( MoaHandle& handleToLock ) :
			mHandle( handleToLock ),
			mMemory( NULL )
		{
			// lock handle
			if( mHandle )
				mMemory = (Tpointer)IMoaHandleHelper().Use()->Lock( mHandle );
			
			if( !mMemory )
				kThrowMoaException( CMoaInvalidArgument );
		}
			
		~MoaHandleLocker( void )
		{
			if( mHandle )
			{
				IMoaHandleHelper().Use()->Unlock( mHandle );
				mMemory = NULL;
			}
		}
		

#ifdef WINDOWS
	#pragma warning( disable : 4284 )
#endif
		Tpointer operator->( void )			{ return mMemory; }
 		operator Tpointer ( void )			{ return mMemory; }
		MoaByte* GetBytePtr( void )			{ return (MoaByte*)mMemory; }
		MoaLong	 GetSize( void )			{ return IMoaHandleHelper().Use()->GetSize( mHandle ); }
		
	protected:
		MoaHandle&	mHandle;
		Tpointer	mMemory;
};
typedef MoaHandleLocker<MoaByte*> MoaHandleLock;
typedef MoaHandleLocker<PMoaChar> CharLocker;

class MoaReleaser
{
	public:
		MoaReleaser( PIMoaUnknown& ptr ) : mInterface( ptr ) {}
		~MoaReleaser( void )
		{
			if( mInterface )
				mInterface->Release();
		}
	
	private:
		PIMoaUnknown& mInterface;
};

#ifdef WINDOWS
#pragma warning( default: 4284 )
#endif

#endif // _H_XMoaHelp

// EOF
