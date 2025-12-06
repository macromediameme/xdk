#ifndef _H_XFileHlp
#define _H_XFileHlp

/* ================================================================================

	XFileHelp.h    $Revision: 2 $

	Copyright (c) 1994, 1995, 1996, 1997 Macromedia, Inc.  All Rights Reserved
	
	You may utilize this source file to create and compile object code for use
	within products you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
	WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
	INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
	PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
	FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
	USE OR INABILITY TO USE THIS CODE.
	
	Purpose:
	
	Provides utility functions that make it easier to manage and access files
	in a platform independent manner.
	
	History:

	15sep98 alx	Added back FilePositionSaver which disappeared at some point.
	24apr98 alx	Changed TempFileHelper to return a pointer to internal object
	21jul97 alx	Moved StreamHelper into here. -- Was causing too many problems in MuiHelpr.h
	07jul97 jcw	Added descriptions, standard header format. Added to SSafe.
	01jul97	alx	Created.

=================================================================================== */

///////////////////////////////////////////////////////////////////////////////////
//
// Description
//
///////////////////////////////////////////////////////////////////////////////////

/*
	This file is used create and access files.
	Provides class for temp file location.
	Provides class for saving state before doing stream manipulation.
*/

///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////

// XFileHlp.h

#ifndef _H_MoaFile2_
	#include "MoaFile2.h"
#endif

#ifndef _H_XSupport
	#include "XSupport.h"
#endif


#include "XStrmHlp.h"


#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma push
	#pragma pointers_in_D0
#endif 

class MMString;

///////////////////////////////////////////////////////////////////////////////////
//
// TempFilePathHelper
//		This class returns either an IMoaPathName that use can own
//		or simply the path as an ascii string.
//
///////////////////////////////////////////////////////////////////////////////////

class TempFilePathHelper
{
	public:
		TempFilePathHelper( void ) : mPath( NULL )
		{
			MoaError err = XSupport::GetCallback()->MoaCreateInstance( &CLSID(CMoaPath),
							&IID(IMoaPathName), (PMoaVoid*)&mPath );
			if( err )
				kThrowMoaExceptionErr( CMoaBadInterface, err );

			// now ask for temp path
			err = mPath->SetTempPath( NULL );
			if( err )
				kThrowMoaExceptionErr( CMoaRuntimeError, err );
		}

		~TempFilePathHelper( void )
		{
			// dump our path
			if( mPath )
				mPath->Release();
		}


		void GetPathString( PMoaChar pathString, MoaUlong bufSize ) const
		{
			if( !pathString || bufSize <= 0 )
				kThrowMoaException( CMoaInvalidArgument );

			MoaError err = mPath->GetPath( pathString, bufSize );
			if( err )
				kThrowMoaExceptionErr( CMoaFileException, err );
		}

		MoaUlong GetPathLength( void ) const
		{
			MoaLong size = 0;
			mPath->GetPathSize( &size );
			return (MoaUlong)size;
		}

		PIMoaPathName GetPathObject( void ) const { return mPath; }

	private:
		PIMoaPathName 	mPath;
};



///////////////////////////////////////////////////////////////////////////////////
//
// FilePositionSaver
// 		This grabs the file position and restores upon destruction
//
///////////////////////////////////////////////////////////////////////////////////
class FilePositionSaver
{
	public:
		FilePositionSaver( PIMoaStream2 file ) :
			mFile( file ),
			mPosition( 0 )
		{
			mFile->GetPosition( &mPosition );
		}

		~FilePositionSaver( void )
		{
			mFile->SetPosition( mPosition );
		}

	private:
		PIMoaStream2		mFile;
		MoaStreamPosition 	mPosition;

};


#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma pop
#endif 



#endif // _H_XFileHlp

// EOF

