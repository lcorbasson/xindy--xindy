/* $Id$
 *----------------------------------------------------------------------
 */

/*
 * clisp.h
 *
 * (history at end)
 */

/*

This is simply a wrapper for including the actual clisp.h depending on
the platform.

*/


/*
 * system specific configuration header files
 */

/* AIX 3.2 on IBM RS/6000 */
#if defined(_AIX) && defined(_IBMR2) || defined(___AIX) && defined(___IBMR2)
#   include "clisp.h-files/rs6000-aix.clisp.h"
#   define  CONF_INCLUDED
#endif

/* HP-UX 8.05 */
#if defined(__hpux)
#   include "clisp.h-files/hppa-hpux.clisp.h"
#   define  CONF_INCLUDED
#endif

/* Linux 1.0.8 */
#if defined(__linux__)
#   include "clisp.h-files/linux.clisp.h"
#   define  CONF_INCLUDED
#endif

/* SunOS 4.1.1 (with gcc?!) */
#if defined(sun) || defined(__sun__)
#   include "clisp.h-files/sun4-solaris.clisp.h"
#   define  CONF_INCLUDED
#endif


/*
 * configuration header files for classes of systems,
 * should only be included when no system specific file was available.
 */

#ifndef CONF_INCLUDED

    #error Sorry, no default configuration available for this system.

#else /* CONF_INCLUDED */
#   undef CONF_INCLUDED		/* don't pollute namespace unnecessarily */
#endif



/*======================================================================
 *
 * $Log$
 * Revision 1.1  1996/07/18 15:56:36  kehr
 * Checkin after all changes that resulted from the define-letter-group
 * modification were finished. Additionally I found an ugly bug in the
 * ordrules.c file that was discovered when running the system under
 * Solaris (which seems to have signed chars..Whee!). This is fixed now
 * and the Imakefiles and that stuff was improved, too.
 *
 */
