// XPrgress.h

#ifndef _H_XPrgress
#define _H_XPrgress

#ifndef _H_MuiHelpr
#include "MuiHelpr.h"
#endif

// declare our base class -- also useful if you don't what to use wrapper.
typedef IMoaHelper< &IID(IMoaProgressBox), PIMoaProgressBox > IMoaProgressHelper;

class XProgressHelper : IMoaProgressHelper
{
	public:
		XProgressHelper( void ) :
			mShowStop( FALSE ),
			mOpen( FALSE )
		{
		}

		XProgressHelper( MoaBool showStopButton, MoaBool show = FALSE ) : 
			mShowStop( showStopButton ),
			mOpen( FALSE )
		{
			if( show )
			{
				Use()->OpenProgress( mShowStop );
				mOpen = TRUE;
			}
		}
		
		virtual ~XProgressHelper( void )	// ensures calling baseclass
		{
			if( mOpen )		
				Use()->CloseProgress();
		}
		
		// methods
		void Open( void )
		{
			if( !mOpen )
				Use()->OpenProgress( mShowStop );
		}

		void Close( void )
		{
			if( mOpen )
				Use()->CloseProgress();
		}

		void SetCaption( ConstPMoaChar s )	
		{
			// call through
			if( mOpen )
				Use()->SetCaption( s );
		}

		void SetMessage( ConstPMoaChar s )	
		{
			// call through
			if( mOpen )
				Use()->SetUserMessage( s );
		}

		void SetProgress( MoaUlong done, MoaUlong total )	
		{
			// call through
			if( mOpen )
				Use()->SetUserProgress( done, total );
		}
		
		MoaBool TestUserCanceled( void )
		{
			if( mOpen )
				return (MoaBool)Use()->TestUserCanceled();
			
			return FALSE;
		}
	
	private:
		MoaBool	 mOpen, mShowStop;
};
typedef XProgressHelper FAR * PXProgressHelper;


#endif // _H_XPrgress

		
// EOF
