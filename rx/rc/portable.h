/* $Id$
 *----------------------------------------------------------------------
 * Written by Joachim Schrod <schrod@iti.informatik.th-darmstadt.de>.
 * This file is distributed without any copyright restriction.
 */

/*
 * Define macros to help the coding of portable programs.
 * Does also declare a bunch of functions which will be used in almost
 * every serious application.
 *    The aim is (almost) always Standard C plus POSIX, we try to stay as
 * near as possible (within limits of rationality...).
 *
 * This file uses a another file named config.h to configure the level
 * of compliance to the standard. Ie, if __STDC__ and INC_STDC is
 * defined by config.h, then it's a full standard compliant system.
 * Otherwise only the standard syntax or the standard libraries might
 * be available. Especially in the latter case we roll up our own
 * declarations.
 *
 * (history at end)
 */

#ifndef	PORTABLE_H
#define	PORTABLE_H


/* tell specifics about this system */

#include "rc/config.h"



/*----------------------------------------------------------------------
 *
 *	COMPILATION ENVIRONMENT
 */

/*
 * If we are on a POSIX system, we want to produce a POSIX-conformant
 * source as default. If this is not possible to certain circumstances
 * the symbol NO_POSIX should be define'ed in an application specific file.
 * Of course, the reason for non-conformance should be explained
 * there.
 */

#ifdef	NO_POSIX


/*
 * We don't want to write a POSIX system -- that's because we need
 * more declarations and more functions than is available there. Well,
 * if we use the `c89' compiler, only ANSI definitions will be
 * available; often we have to define a symbol to tell the compiler
 * that we want the complete run-time environment. Below we do it for
 * all systems that we currently support.
 */

#ifdef	__hpux
#   undef  _HPUX_SOURCE
#   define _HPUX_SOURCE 1
#endif
#ifdef	_AIX
#   undef  _ALL_SOURCE
#   define _ALL_SOURCE 1
#endif
#ifdef __linux__
#   undef  _GNU_SOURCE
#   define _GNU_SOURCE 1
#endif


#else

/*
 * We supply both the old (June 1990) and the new (September 1991) macros.
 *
 * The definitions below are often to late if we program in lex. Usual
 * lex sceletons (eg, on HP-UX and AIX) include <stdio.h> at the very
 * top of their created programs; the included user codes comes much
 * later. There we don't have the chance to set the symbol early enough.
 *     The problem: Many systems which are compliant to different
 * guides (eg, ANSI, POSIX, X/OPEN, SVID, etc.) include with all
 * system include files a specific file which sets different a lot of
 * symbols. These symbols trigger the appropriate behaviour in the
 * system include files. Of course, this specific file is protected
 * from multiple readins. If we use a Standard C compiler, this compiler
 * usually defines _ANSI_C_SOURCE and we have set up all include files
 * for ISO compliance but not for the superset POSIX resembles.
 * Therefore we undef the multiple read protection symbol here --
 * let's check out the definition anew again.
 *     Of course, it must be checked for each system anew if we don't
 * have introduced any conflicts here. Oh yes, and using the POSIX
 * part of <stdio.h> in lex programs seems to be impossible without
 * setting _POSIX_SOURCE externally. Sigh.
 */
#if defined(_AIX)  &&  defined(_H_STANDARDS)
#   undef	_H_STANDARDS
#   if defined(_ANSI_C_SOURCE) && !defined(_POSIX_SOURCE)
			/* take care that <unistd.h> may be read in */
#	undef	_H_TYPES	/* may be read in twice, has inner protection */
#	undef	_H_LIMITS	/* only macro definitions */
#   endif
#endif
#if defined(__hpux)  &&  defined(_SYS_STDSYMS_INCLUDED)
#   undef	_SYS_STDSYMS_INCLUDED
#endif


/*
 * _POSIX_SOURCE might be set to an illegal value already (in
 * particular, with an empty replacement text). If that's the case,
 * #undef & #define it again with `1', as specified by POSIX standard.
 *     Actually, that happens when any system include file is read in
 * first on AIX. Then <standards.h> is read and issues
 * `#define _POSIX_SOURCE' when it switches on _ALL_SOURCE. (And that
 * when we don't want _ALL_SOURCE at all...)
 */
#ifdef	INC_POSIX
#   undef  _POSIX_SOURCE
#   define _POSIX_SOURCE 1
#endif
#if	INC_POSIX == 2
#   undef  _POSIX2_SOURCE
#   define _POSIX2_SOURCE 1
#endif

#define _POSIX_C_SOURCE INC_POSIX


#endif /* ! NO_POSIX */


/*
 * If we use an old C++ compiler we add the identifying symbol
 */

#if defined(c_plusplus) && !defined(__cplusplus)
#   define __cplusplus
#   define CPLUSPLUS_1
#endif


/*
 * STD_C means that this compiler may digest a Standard C source.
 * This does not necessarily mean that it's a Std C compiler, use
 * __STDC__ to check this.
 */
#if defined(__STDC__)  ||  defined(__cplusplus)
#   define STD_C
#endif



/*----------------------------------------------------------------------
 *
 *	PORTABILITY DEFINITIONS
 */


/* missing keywords */

#ifndef STD_C
#   define const
#   define signed
#   define volatile
#endif


/*
 * PROTO gives the ability to use prototypes both with and without
 * Standard C compilers. To declare a function foo, just say
 *
 * Return_type foo PROTO(( Param_type_1 , Param_type_2 ));
 *
 * Note: Also I would prefer the name PARAMS as the more `logical'
 * 	 choice for this macro, PROTO is used because it is
 * 	 recommended in the Indian-Hill style guide -- more people
 * 	 seems to use it resp. to be used to it. Sigh.
 */

#ifdef STD_C
#   define PROTO(param_list)	param_list
#else
#   define PROTO(param_list)	()
#endif


/*
 * EXTERN_C should be prepended to C function declarations in header
 * files which might be read in by C++ compilers. It shall be used
 * like extern.
 */
#ifdef __cplusplus
#   define EXTERN_C extern "C"
#else
#   define EXTERN_C extern
#endif


/*
 * And some macros we get used to. They are used with definitions
 * and function or C++ class declarations.
 *
 * 	PUBLIC	means that the following definition is visible externally
 * 	PRIVATE	means that the following definition/declaration is
 *		only visible in this file. We use PRIVATE instead of
 * 		static because the keyword static is too overloaded in
 *              C or C++, anyhow.
 * 	REPTYPE	is used as `REPTYPE *REP', for the representation type
 *              of a C++ class. May be only used for one class per
 *              implementation unit.
 * 	ITERTYPE Same as REPTYPE, for iterator classes.
 * 	ABSTRACT marks abstract C++ classes, to enhance readibility.
 *              All classes that can or must not be instantiated are
 *              tagged this way, not only those with abstract methods.
 *              (A class may have only protected & private constructors,
 *              then it's abstract, too.)
 *
 * REPTYPE and ITERTYPE are not defined if they are defined already.
 * That may happen during a template instantiation with compilers that
 * use template repositories. Then we don't have control over order of
 * inclusion, and portable.h may be included after the first code
 * piece with a REPTYPE definition has been processed already.
 */
#define PUBLIC
#define PRIVATE static
#define ABSTRACT

#ifndef REPTYPE
#define REPTYPE void
#endif

#ifndef ITERTYPE
#define ITERTYPE void
#endif

/*
 * Use CPP_CONCAT & CPP_STRINGIFY to do portable identifier
 * concatenation and string creation.
 *
 * The section ``Separate Expansion of Macro Arguments'' in the GNU
 * cpp Texinfo manual explains why we need CPP_SHALLOW_STRINGIFY:
 * Otherwise the argument could not be a macro that expands in a
 * string. (CPP_SHALLOW_STRINGIFY turns a macro name into a string
 * with that macro name.)
 */
#ifdef STD_C
#   define CPP_CONCAT(a,b) a##b
#   define CPP_STRINGIFY(str) CPP_SHALLOW_STRINGIFY(str)
#   define CPP_SHALLOW_STRINGIFY(str) #str
#else
#   define CPP_CONCAT(a,b) a/**/b
#   define CPP_STRINGIFY(str) "str"
#   define CPP_SHALLOW_STRINGIFY(str) "str"
#endif


/*
 * Often we want to add a string to an object that identifies the
 * source revision. Use `REVISION("string");' or
 * `IDENT(variable,"string");' for that, the former uses `version' as
 * variable name.
 *
 * Many compilers warn about unused identifiers, one cannot stop them
 * by adding volatile or similar. The AIX linker throws away variables
 * with no references to it. The following trick is due to the gcc
 * manual: We use the variable and we use the using variable.
 */
#define USE(var) \
	PRIVATE void * CPP_CONCAT(use_,var) = \
		(&CPP_CONCAT(use_,var), (void *) &var)
#define IDENT(var,string) PRIVATE char var[] = string; USE(var)
#define REVISION(string) IDENT(version,string)



/*----------------------------------------------------------------------
 *
 *	BASIC TYPE DEFINITIONS
 */

/*
 * We supply a common base of declarations which we think are needed
 * for all applications. In fact, we define a few new typenames and
 * read in a number of system header files (or declare their contents
 * if they are not available). This sets up a `virtual base platform',
 * refer to the specification for more information.
 *
 * The problem with our declarations is that they may be in conflict
 * with some declarations of our application. (The declarations from
 * the system files should not be in conflict, otherwise we're in
 * trouble anyhow.)
 *     Especially, the typenames Boolean and String are often supplied
 * in (other) C header files. We therefore look at the macros
 * HAS_BOOLEAN_TYPE and HAS_STRING_TYPE first.
 *
 * A special case is made for Xt Intrinsics based application (because
 * we write them often ;-): The include file <X11/Intrinsics.h> (used by
 * all such programs) defines String and Boolean, too. The user may now
 * define the macro XT_APPLICATION; this will trigger the inclusion of
 * exactly this file. In addition, these two macros will be defined
 * implicitely. X application poses other problems, too. The X include
 * files rely on definitions in the system include files which are not
 * conformant to the standard (eg, they may want a typedef for caddr_t).
 * Therefore, on many systems we have to repair a few symbols which may
 * be false specified in "config.h".
 *     This is, of course, system dependent.
 * 	 HP/UX:	We need the full (non-POSIX) namespace. Then _toupper(),
 * 		strdup(), and vfork() are declared as well, we must
 * 		signal this.
 */

#ifdef	X_APPLICATION	/* an old name, in the sake of compatibility */
#define	XT_APPLICATION
#endif

#ifdef	XT_APPLICATION

#   ifdef __hpux
#	undef	_HPUX_SOURCE	/* be careful with redefinition */
#	define	_HPUX_SOURCE 1
#	define	HAS__TOUPPER
#	define	HAS_STRDUP_DECL
#	define	HAS_VFORK_DECL
#   endif

#   include	<X11/Intrinsic.h>
#   define	HAS_BOOLEAN_TYPE
#   define	NEED_BOOLEAN_INT	/* FALSE and TRUE is already defined */
#   define	HAS_STRING_TYPE

#endif /* XT_APPLICATION ? */


/*
 * A type Boolean is missing in C. In reality, we name it C_Boolean
 * but provide an alias Boolean as well.
 *     Often it's better to define it as an enumeration type since
 * enum values are available in common debuggers. But sometimes
 * compilers complain about the (valid) intermixing between enums and
 * ints, then we check the symbol NEED_BOOLEAN_INT and provide Boolean
 * as int's with appropriate FALSE and TRUE macros. This symbol should
 * also be defined if you have other headers which define macros FALSE
 * and TRUE already.
 *
 * If we are using C++, we don't provide the alias Boolean as default
 * -- this name is often used by class libraries. If an alias is
 * wanted then it should be done in a global project definition file.
 * Preventing this alias definition is easy: we're cheating that it's
 * already there...
 *     Of course, one has to be careful then with the creation of C
 * spefications which might be used also from C++.
 *     Since C++ knows types and not only type names, we set
 * NEED_BOOLEAN_INT unconditionally then.
 *
 * Sometimes a type Boolean is defined already by the application and
 * cannot be changed there (eg, in X include files). Then the macro
 * HAS_BOOLEAN_TYPE is defined, we do not declare Boolean.
 */
#ifdef __cplusplus
#   define HAS_BOOLEAN_TYPE
#   define NEED_BOOLEAN_INT
#endif


#ifdef NEED_BOOLEAN_INT

    typedef int C_Boolean;
#   ifndef FALSE
#   define FALSE 0
#   endif
#   ifndef TRUE
#   define TRUE 1
#   endif

#else
    typedef enum { FALSE=0 , TRUE } C_Boolean;
#endif /* NEED_BOOLEAN_INT */


#ifndef HAS_BOOLEAN_TYPE
    typedef C_Boolean Boolean;
#endif /* HAS_BOOLEAN_TYPE */


/*
 * It's often better to write "String" than "char *". The latter is a
 * pointer to a memory area with characters, not necessarily
 * terminated by '\0'. The former is a C string where it is safe to
 * pass it as an argument to all string functions. In addition we
 * supply the type definition "Const_string" when the character string
 * pointed to must not be changed.
 *
 * In addition, we define a function which is missing in the standard
 * specification (IMO): STREQ() to check the equality of two strings.
 * It's often better to use this function instead of strcmp() due to
 * better readability. [Uppercase is used because the prefix `str' is
 * reserved.]
 *
 * If we are using C++, a type "String" is often introduced by class
 * libraries. Therefore we do also provide the type C_String, which
 * might be used in C++ modules (or in C modules who might be used
 * from C++) instead of "String".
 */
#ifndef __cplusplus
#   ifndef HAS_STRING_TYPE
	typedef char * String;
#   endif
#endif	/* C++ */

typedef char * C_String;
typedef char const * Const_string;
#define STREQ(s1, s2)  (strcmp(s1, s2) == 0)


/*
 * The state of the void handling is told by config.h.
 */

#ifndef HAS_VOID
    typedef int void;
#endif

#ifdef	HAS_VOIDP
    typedef void * Address;
#else
    typedef char * Address;
#endif



/*----------------------------------------------------------------------
 *
 * 	COMMON HEADER FILES resp.
 *      COMMON DECLARATIONS FOR A BASE SYSTEM
 */


#ifdef INC_STDC


/* Standard C include files are available */

#include <stddef.h>		/* type definitions, eg, size_t */
#include <stdlib.h>		/* ANSI std functions		*/
#include <stdio.h>		/* std high-level I/O		*/

#include <errno.h>		/* error numbers of syscalls	*/
extern int errno;		/* sometimes this was forgotten	*/

#include <string.h>		/* string functions		*/


/* POSIX include files */
#ifdef INC_POSIX
#   include <unistd.h>		/* POSIX std declarations	*/
#endif


/* C++ specific include files */
#ifdef __cplusplus
#   include <iostream.h>	/* C++ I/O			*/
#endif


/*
 * Sometimes we have systems which are nearly compliant. Then we may
 * add a few missing declarations in a special file and do not need to
 * roll up our own environment. In these cases config.h defines the
 * macro INCLFILE_STD_REPAIR for us, a file which we shall include after
 * all other system header files.
 */
#ifdef	INCLFILE_STD_REPAIR
#   include INCLFILE_STD_REPAIR
#endif




#else /* ! INC_STDC */




/*
 * We don't support C++ compilers without standard include files. Even
 * if one uses g++, one may (and shall) supply them in g++-includes.
 *
 * Take care that a K&R cpp doesn't chock on #error...
 */

#ifdef	__cplusplus
	#error	"No support for C++ compilers without standard include files"
#endif


/* What's a program without i/o ? */

#include <stdio.h>

/*
 * From <stddef.h> we need size_t.
 * NULL is defined in all <stdio.h>s I know.
 *
 * Well, config.h defines INCLFILE_SIZE_T for us: the file where size_t is
 * defined. Otherwise we use unsigned int.
 */

#ifdef INCLFILE_SIZE_T
#   include INCLFILE_SIZE_T
#else
    typedef unsigned int size_t;
#endif

/*
 * Perhaps we should supply a <stdlib.h>, but anyhow: here is the part
 * I would consider minimal. I admit that it is a very personal
 * selection -- might be that it would be best to create an own
 * <stdlib.h> if none is available.
 *
 * Especially the alloc functions are a crux.
 */

/* end of programs */

extern void exit PROTO((int));


/*
 * For most systems we need access to environment variables -- but
 * almost never we must set some. Therefore we declare only getenv().
 */

#ifdef HAS_GETENV
    extern Const_string getenv PROTO((const Const_string env_name));
#else
#   define getenv(env_name)	NULL
#endif


/* And we often have to call other programs */

extern int system PROTO((const Const_string command));


/* the alloc group */

#ifdef INC_MALLOC
#   include <malloc.h>
#else
    extern MALLOCPTRTYPE	calloc	PROTO((size_t, size_t));
    extern void			free	PROTO((Address));
    extern MALLOCPTRTYPE	malloc	PROTO((size_t));
    extern MALLOCPTRTYPE	realloc	PROTO((Address, size_t));
#endif


/*
 * There were some cultural differences in the C world, where the standard
 * committee has decided to use the SysV versions. Well, this concerns
 * memory and string handling functions, let's declare them here.
 */

#ifndef HAS_STD_STRINGS
#   include <string.h>
#else
#   include <strings.h>
#   define strchr	index
#   define strrchr	rindex
#endif

#ifdef HAS_MEMORY
#   include <memory.h>
#else
#ifdef HAS_BCOPY
    extern void bcopy PROTO((Address from, Address to, size_t size));
    extern int bcmp PROTO((Address, Address, size_t));
    extern void bzero PROTO((Address, size_t));
#   define memcpy(to, from, size) bcopy((from), (to), (size))
#   define memcmp	bcmp
#   define memset	memset_is_unavailable
#else
#   define memcpy	memcpy_is_unavailable
#   define memcmp	memcmp_is_unavailable
#   define memset	memset_is_unavailable
#endif /* HAS_BCOPY */
#endif /* HAS_MEMORY */

#ifndef	HAS_MEMMOVE
#   ifdef HAS_BCOPY
#	define memmove(to, from, size)	bcopy((from), (to), (size))
#   else
#	define memmove	memmove_is_unavailable
#   endif
#endif


/* Furthermore we need the error numbers of the system calls */

#include <errno.h>
extern int errno;	/* is often not defined in <errno.h> */


#endif	/* INC_STDC */


#endif	/* PORTABLE_H */


/*======================================================================
 *
 * $Log$
 * Revision 1.1  1996/07/18 15:59:55  kehr
 * This file is necessary to complile the libordrules.
 *
 * Revision 1.20  1995/06/12  10:51:33  schrod
 *     Make sure that definition of NO_POSIX identifiers are undefined
 * first. That's better than conditionally undefining to get the
 * canonical expansion, as specified by standards or system-wide header
 * files.
 *
 * Revision 1.19  1995/05/23  10:58:15  herr
 *    REPTYPE and ITERTYPE must not be defined unconditionally, otherwise
 *    inclusion order would be significant and automatic template
 *    instantiation in C++ would probably fail.
 *
 * Revision 1.18  1995/05/18  19:15:19  schrod
 *     Linux: If NO_POSIX, define _GNU_SOURCE to be sure that we get all
 * definitions from all included header files.
 *     Make sure we don't get a redefinition warning for _POSIX_SOURCE if
 * it is defined already.
 *     Don't include <osfcn.h> for C++ sources any more. Half of the
 * header files included by this file are read in anyhow (<stdlib.h> &
 * <unistd.h>). The rest (<sys/{types,wait}.h>) is not of interest in
 * most sources and may be included by need.
 *     Add REPTYPE, ITERTYPE, and ABSTRACT.
 *     Add CPP_CONCAT() and CPP_STRINGIFY(). Add IDENT() and REVISION().
 *     Discard function templates via macros. It's of no use anyway, if
 * our software needs function templates we have to get a compiler that
 * supports it.
 *
 * Revision 1.17  1995/02/06  16:59:08  schrod
 *     Add macros to work with C++ compilers that don't support function
 * templates.
 *
 * Revision 1.16  1995/01/27  10:32:55  schrod
 *     Define POSIX identifiers to `1', as specified in the standard.
 * Doing so prevents conflicts with definitions on the command line,
 * typically stated as -D without an explicit value.
 *
 * Revision 1.15  1995/01/19  02:43:15  schrod
 *     Use prefix `rc/' for librc header files that are not part of this
 * module. In header files use this prefix always.
 *
 * Revision 1.14  1994/10/30  15:13:04  schrod
 *     If we don't want POSIX compatibility, we request the whole
 * run-time environment of the respective platform.
 *
 * Revision 1.13  1993/02/01  12:22:11  schrod
 *     Declared NEED_BOOLEAN_INT in XT_APPLICATION.
 *
 * Revision 1.12  1993/01/25  17:15:54  schrod
 *     Provided types C_Boolean and C_String in C as well as in C++.
 *
 * Revision 1.11  1993/01/04  14:31:57  schrod
 *     On HP-UX, _HPUX_SOURCE must be defined before <X11/Intrinsics.h>
 * is included in case of Xt applications.
 *
 * Revision 1.10  1992/12/22  12:36:10  schrod
 *     Added part support of generated sources which include a system
 * file before portable.h is included by the user. This might be a shoot
 * in the foot -- usually the already included system files will behave
 * different. And users are not good in remembering such fine points...
 *
 * Revision 1.9  1992/12/20  18:53:07  schrod
 *     X_APPLICATION renamed to XT_APPLICATION, X_APPLICATION is still
 * supported in this revision for upward compatibility.
 *     strdup() is not declared in Non-Standard C environments, too.
 *
 * Revision 1.8  1992/10/08  10:57:11  schrod
 *     If X application and on HP/UX: define _HPUX_SOURCE only if it's
 * not defined already. (This might be done in some {Im,M}akefile.)
 * Actually, the definition should not cause any errors, but we should
 * take care anyhow...
 *
 * Revision 1.7  1992/09/25  17:40:43  schrod
 *     When X_APPLICATION on an HP/UX, _HPUX_SOURCE and associated
 * defines are set.
 *
 * Revision 1.6  1992/09/24  19:39:10  schrod
 *     Discarded declaration of strdup(). (Is available from 'xstring'.)
 *
 * Revision 1.5  1992/06/18  16:34:57  schrod
 *     Missing `)' in Non-STDC part.
 *
 * Revision 1.4  1992/06/18  14:08:49  schrod
 *     Supports parametrization by macros the user defines before
 * including portable.h. Ie:
 * 	NO_POSIX	 -- No POSIX system wanted
 * 	X_APPLICATION	 -- X11 include files will be used
 * 			    this implies HAS_BOOLEAN_TYPE and HAS_STRING_TYPE
 * 	HAS_BOOLEAN_TYPE -- other include file defines Boolean typedef
 * 	HAS_STRING_TYPE	 -- other include file defines String typedef
 *     Now usable with C++ compilers.
 * 	Defines CPLUSPLUS_1 if an older C++ compiler is used.
 * 	<iostream.h> is included, too.
 *     PARAMS was renamed to PROTO, to conform to the Indian Hill style guide.
 *     HAS_PROTO was renamed to STD_C.
 *     No prototype for main() any more, was wrong anyhow.
 *     Obeyed more configurations, cf. config.gen change of same date.
 *
 * Revision 1.3  1992/05/12  18:33:48  schrod
 *     Address was defined as (int *) if HAS_VOIDP, must be (void *).
 *
 * Revision 1.2  1992/03/17  16:51:21  schrod
 *     bcopy() functions are not available on our generic system.
 *     strdup() declaration is asserted, even if it's not standard. (We
 * need it too often.)
 *     function declarations are prefixed with extern.
 *
 * Revision 1.1  1992/03/13  14:26:43  schrod
 * First version for lib+prog stuff.
 *
 */
