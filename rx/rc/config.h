/* $Id$
 *----------------------------------------------------------------------
 */

/*
 * config.def --- configuration header which may be used very often
 *
 * (history at end)
 */

/*

This version of config.h reads configuration header files of specific
systems according to preprocessor symbols. Hopefully one does not need
a specific config.h in most cases then.

*/



/*
 * system specific configuration header files
 */

/* AIX 3.2 on IBM RS/6000 */
#if defined(_AIX) && defined(_IBMR2) || defined(___AIX) && defined(___IBMR2)
#   include "rc/aix3.cnf"
#   define  CONF_INCLUDED
#endif

/* HP-UX 8.05 */
#if defined(__hpux)
#   include "rc/hpux.cnf"
#   define  CONF_INCLUDED
#endif

/* Linux 1.0.8 */
#if defined(__linux__)
#   include "rc/linux.cnf"
#   define  CONF_INCLUDED
#endif

/* SunOS 4.1.1 (with gcc?!) */
#if defined(sun) || defined(__sun__)
#   include "rc/sun.cnf"
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
 * Revision 1.1  1996/07/18 15:59:46  kehr
 * This file is necessary to complile the libordrules.
 *
 * Revision 1.8  1995/01/19  02:43:14  schrod
 *     Use prefix `rc/' for librc header files that are not part of this
 * module. In header files use this prefix always.
 *
 * Revision 1.7  1994/07/19  14:29:28  herr
 * Extended AIX config to recognise gcc -ansi.
 *
 * Revision 1.6  1994/05/13  14:41:27  fries
 *     Added configuration file for Linux.
 *
 * Revision 1.5  1992/12/20  20:43:46  schrod
 *     Gives compiler error on unkown system.
 *
 * Revision 1.4  1992/12/20  20:42:20  schrod
 *     Added AIX 3.x support.
 *
 * Revision 1.3  1992/06/23  14:39:13  seiffert
 *     gcc -ansi identifies SunOS with __sun__, not only with sun.
 *     Typo in sun include file name.
 *
 * Revision 1.2  1992/06/18  16:42:09  schrod
 *     HP-UX configuration file is also usable with cc. Therefore it was
 * renamed from hp-c89.ch to hpux.ch.
 *
 * Revision 1.1  1992/06/18  14:20:42  schrod
 *     Imakefile now standard module Imakefile.
 *     Renamed config.{hp.c89,sun.gcc}.cf to {hp-c89,sun}.ch, names are
 * more portable. sun.ch now specifies sun.h as the `POSIX/Standard
 * include repair file' for SunOS 4.1.1.
 *     config.def is a config.h for UNIX systems which tries to detect
 * which *.cnf file should be read in. Most systems can use it.
 *
 */
