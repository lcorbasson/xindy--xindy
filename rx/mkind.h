/*
  $Id$

  This is the minimum excerpt form the original `mkind.h' of the
  makeindex-3 system making the modified version of ordrules compile.

  */

#include <stdio.h>
#include <stdlib.h>

#ifndef _MKIND_H
#define _MKIND_H

#if    ANSI_PROTOTYPES
#define ARGS(arg_list)	arg_list
#define VOIDP		void*
#else
#define ARGS(arg_list)	()
#define const
#define VOIDP		char*
#endif

#define SIZE_T  unsigned

#undef TRUE
#define TRUE 1

#undef FALSE
#define FALSE 0

#ifndef LONG_MAX
#define LONG_MAX      1024
#endif
#ifndef STRING_MAX
#define STRING_MAX    128
#endif

#define BSH '\\'

#undef NUL
#define NUL '\0'

extern VOIDP fmalloc ARGS((SIZE_T size));

#endif /* _MKIND_H */

#ifdef __STDC__
#include    <stddef.h>                 /* for function declarations */
#ifndef __GNUC__
#include    <stdlib.h>                 /* for function declarations */
#endif
#include    <string.h>                 /* for function declarations */
#undef ANSI_PROTOTYPES
#define ANSI_PROTOTYPES    1           /* so we get full argument
                                          type checking */
#undef SIZE_T
#define SIZE_T  size_t
#endif                                  /* __STDC__ */

/*
  $Log$
  Revision 1.1  1996/03/27 20:29:05  kehr
  It works. Today I had my first success in getting the FFI running with
  the ordrules-library. The interface is defined in `ordrulei.lsp' and
  allows direct access to the functions in `ordrules.c'.


  */
