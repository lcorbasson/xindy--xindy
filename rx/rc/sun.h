/* $Id$
 *----------------------------------------------------------------------
 */

/*
 * sun.h --- missing std declarations in Sun header files
 *
 * (history at end)
 */

/*

This file must only be read in by portable.h and is therefore not
protected against multiple reads.

*/


/* this is missing in <stdlib.h> */
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

/* this is missing in <string.h> */
#include <memory.h>



/*======================================================================
 *
 * $Log$
 * Revision 1.1  1996/07/18 15:59:59  kehr
 * This file is necessary to complile the libordrules.
 *
 * Revision 1.1  1992/06/18  14:20:58  schrod
 *     Imakefile now standard module Imakefile.
 *     Renamed config.{hp.c89,sun.gcc}.cf to {hp-c89,sun}.ch, names are
 * more portable. sun.ch now specifies sun.h as the `POSIX/Standard
 * include repair file' for SunOS 4.1.1.
 *     config.def is a config.h for UNIX systems which tries to detect
 * which *.cnf file should be read in. Most systems can use it.
 *
 */
