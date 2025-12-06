/*  Metrowerks Standard Library  */

/*  $Date: 7/26/99 9:01 PM $ 
 *  $Revision: 3 $ 
 *  $NoKeywords: $ 
 *
 *		Copyright © 1995-1999 Metrowerks, Inc.
 *		All rights reserved.
 */
 
/*
 *	time.mac.h
 *
 *		Notes
 *		-----
 *  There are two distinct epochs in use: the Macintosh 1904 Jan 1 and the MSL Mac Epoch, 
 *  1900 Jan 1.  This header defines the number of seconds between the two epochs for
 *  use where a conversion is required.    mm 990203 
 */
 
#ifndef __time_mac__
#define __time_mac__

#include <ansi_parms.h>                 /* mm 970905*/

/* mm 990203 */
#define _mac_msl_epoch_offset_  (365L * 4L) * 24L * 60L * 60L  
#endif
/*     Change record
 * mm 970521  Header created
 * mm 970905  added include of ansi_parms.h to avoid need for prefix file
 * mm 990203  Corrected comment and name of epoch conversion comment.
 */
