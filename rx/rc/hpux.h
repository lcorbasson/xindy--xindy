/* $Id$
 *----------------------------------------------------------------------
 */

/*
 * hpux.h --- repair header file for HP-UX
 * [a sub header file for hpux.cnf]
 *
 * (history at end)
 */

/*

This file must only be read in by portable.h and is therefore not
protected against multiple reads.

*/


/*
 * <signal.h> is erroneous, supply a replacement.
 * This replacement is read always, regardless if it's used or not.
 * Well, work-arounds cost resources -- but better CPU time than human work...
 */
#include "rc/hpux-signal.h"




/*======================================================================
 *
 * $Log$
 * Revision 1.1  1996/07/18 15:59:50  kehr
 * This file is necessary to complile the libordrules.
 *
 * Revision 1.2  1995/01/19  02:43:14  schrod
 *     Use prefix `rc/' for librc header files that are not part of this
 * module. In header files use this prefix always.
 *
 * Revision 1.1  1993/01/29  18:33:02  schrod
 *     Added work-around for bug in <signal.h> on HP-UX.
 *
 */
