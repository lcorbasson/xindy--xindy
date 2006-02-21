%{
  /* $Id$

   This is the source of `tex2xindy'.

   It transforms a LaTeX auxiliary file `.aux' or index file
   `.idx' into a xindy raw index file.

   This program was written since it was not easily possible to
   extract the parser from the old makeindex system. Therefore it does
   not find all errors in the input as the makeindex version.
   Additionally it uses only the default input specifiers of
   makeindex. If other input specifiers (cf. manual page of makeindex)
   are needed, the input specifiers below (starting from the pattern
   KEYWORD, see below) must be changed and the program must be
   recompiled. See the Migration Manual that comes with this
   distribution for further details.

   It can also be used as a template for writing other frontends for
   xindy. Please send us your preprocessors. We want to include
   them into the distribution. */

#include <stdio.h>

#define QUOTE_ECHO qs(yytext)
FILE* attrfd = NULL;

static int lineno    = 1;
static int braces    = 0;
static int xref_mode = 0;
static int glos_mode = 0;
static int errors    = 0;

#define multiple_err \
    { \
        fprintf(stderr, "line %d: multiple %s's\n", lineno, yytext); \
	errors++; \
    }

#define NO_RANGE     0
#define OPEN_RANGE   1
#define CLOSE_RANGE  2

int range = NO_RANGE;

/* This function quotes a character, if necessary. */

void qc( char ch ) {
  switch (ch) {
    case '\\' :
    case '"'  :
	putchar( '\\' );
	break;
  }
  putchar(ch);
}

/* Quote an entire string. */

void qs( char* str ) {
  while ( *str ) {
    qc( *str++ );
  }
}

%}

KEYWORD  \\indexentry
KEYWORDG \\glossaryentry
ENCAP    \|
ACTUAL   @
ESCAPE   \\
LEVEL    !
IS       :
QUOTE    \"
ROPEN    \(
RCLOSE   \)
ARGOPEN  \{
ARGCLOSE \}

%s key print skip2location location encap xref is skiplocation

%%

<INITIAL>{KEYWORD}[ \t]*{ARGOPEN} {
			  printf("(indexentry :tkey ((\"");
			  xref_mode = 0;
			  glos_mode = 0;
			  BEGIN(key);
			}

<INITIAL>{KEYWORDG}[ \t]*{ARGOPEN} {
			  printf("(indexentry :tkey ((\"");
			  xref_mode = 0;
			  glos_mode = 1;
			  BEGIN(key);
			}

{ESCAPE}{QUOTE}        { QUOTE_ECHO; }
{QUOTE}\n              { QUOTE_ECHO; lineno++; }
{QUOTE}.               { QUOTE_ECHO; }
<key,print>{ENCAP}     { printf("\")) :attr \"");
                         range = NO_RANGE; BEGIN(encap); }
<key,print>{IS}        { if (glos_mode == 1)
                           {
                             printf("\")) :attr \"is\" :xref (\"");
                             range = NO_RANGE;
			     if (attrfd) fprintf(attrfd, "\txref\n");
		           BEGIN(is);
			   }
                         else
			   QUOTE_ECHO; }
<key>{LEVEL}           { printf("\") (\""); }
<print>{LEVEL}         { printf("\") (\""); BEGIN(key); }
<key,print>{ARGOPEN}   { QUOTE_ECHO; braces++; }
<key,print>{ARGCLOSE}  { if ( braces > 0 )
                           {QUOTE_ECHO; braces--;}
                         else
			   {printf("\"))");
		         BEGIN(skip2location);}
                       }

<key>{ACTUAL}          { printf("\" \""); BEGIN(print); }
<print>{ACTUAL}        { multiple_err; }

<encap>{ENCAP}         { multiple_err; }
<encap>{ROPEN}         { range = OPEN_RANGE; }
<encap>{RCLOSE}        { range = CLOSE_RANGE; }
<encap>{ARGOPEN}       { /* close :attr "... */
                         printf("\" :xref (\"");
			 if (attrfd) fprintf(attrfd, "\txref\n");
		         braces++;
		         BEGIN(xref);
                       }
<encap>{ARGCLOSE}      { if ( braces > 0 )
                           {QUOTE_ECHO; braces--;}
                         else {
			   putchar('"');
			   if (attrfd) fprintf(attrfd, "\tlocref\n");
			   switch (range) {
			     case OPEN_RANGE : printf(" :open-range");
			       break;
			     case CLOSE_RANGE: printf(" :close-range");
			       break;
			   }
			   BEGIN(skip2location);
			 }
                       }
<encap>.|\n            {
			 QUOTE_ECHO;
                         if (attrfd)  fwrite(yytext, sizeof(char), 1, attrfd);
			 if (*yytext == '\n')  lineno++;
	               }



<xref>{LEVEL}          { printf("\" \""); }
<xref,is>{ARGOPEN}     { QUOTE_ECHO; braces++; }
<xref>{ARGCLOSE}       { if     ( braces >   1 )
                           {QUOTE_ECHO; braces--;}
                         else if ( braces == 1 )
		           { braces--; }
                         else {
		           printf("\")");
			   xref_mode = 1;
		           BEGIN(skip2location);
		         }
                       }
<is>{ARGCLOSE}         { if     ( braces > 0 )
                           {QUOTE_ECHO; braces--;}
                         else {
		           printf("\")");
			   xref_mode = 1;
		           BEGIN(skip2location);
		         }
                       }

<skip2location>[ \t]*{ARGOPEN} {
                        if (xref_mode)
			  { BEGIN(skiplocation); }
			else
			  { printf(" :locref \"");
			    BEGIN(location);
			  }
                       }
<location>{ARGCLOSE}  { printf("\")\n"); BEGIN(0); }

<skiplocation>{ARGCLOSE} { printf(")\n"); BEGIN(0); }
<skiplocation>.		 { ; }

<key,print,xref,is,location>\n	      { QUOTE_ECHO; lineno++; }
<key,print,xref,is,location>.	      { QUOTE_ECHO; }

\n                    { lineno++; }
[ \t]		      { ; }
.                     {
			fprintf(stderr,
				"Encountered unexpected char '%c' on line %d\n",
				yytext[0], lineno);
		      }

%%


main(int argc, char* argv[])
{
  if ( argc > 1 ) {
    fprintf(stderr, "This is `tex2xindy' $Revision$.\n");
    fprintf(stderr, "Writing attribute names to file \"%s\".\n\n", argv[1]);
    attrfd = fopen(argv[1], "w");
  }
  yylex();
  if (attrfd) fclose(attrfd);
  if (errors > 0) {
      exit( 1 );
  } else {
      exit( 0 );
  }
}


/* ============================================================

  $Log$
  Revision 1.17  2006/02/21 02:05:00  jschrod
      Quote really quotes the next char, now.

  Revision 1.16  2005/06/27 20:49:06  jschrod
      Keywords may be inmidst a line, as Jörg Sommer showed.
      "." rule merging did not work for attributes, and for skiplocation.
      Output error message if we come across chars outside our FSA.

  Revision 1.15  2005/06/14 16:22:08  jschrod
      Fold in changes from Thomas Henlich, as of 2000-02-14:
  Paranoia fix: recognize KEYWORD only in INITIAL start condition.
  Recognize \n and count lines (multiline entries do exist!).
  Merged "." rules.
  Fixed error messages (multiple ...).

  Revision 1.14  2004/10/05 21:10:48  jschrod
      Handles quote character correctly (bug ticket 1006128).
  Test case: german-sty.

  Revision 1.13  2002/01/29 13:32:58  thenlich
  Fixed bug in crossref-to-subitem bugfix. The original one proposed by Roger Kehr
  was right, only I copied it wrongly (shame on me). Thanks to Torsten Bronger
  for pointing it out to me.

  Revision 1.12  1999/10/13 08:06:44  kehr
  Changed revision number message back to RCS-tag. No functional changes.

  Revision 1.11  1999/10/13 08:05:10  kehr
  Merged bugfix from Thomas Henlich with my own modifications.

   1.8 Fixed minor quoting bugs (for increased makeindex compatibility).
        1999-07-28 Thomas Henlich <henlich@mmers1.mw.tu-dresden.de>
       Fixed crossref to subitem.
        1999-09-23 Thomas Henlich <henlich@mmers1.mw.tu-dresden.de>

   1.7 Fixed a bug concerning writing to and closing non-existing file (stat)
       Fixed a bug concerning quoting the " character.
       Enhancement for processing glossary files.
        1999-06-14 Thomas Henlich <henlich@mmers1.mw.tu-dresden.de>

  Revision 1.10  1999/09/23 06:53:32  kehr
  Fixed wrong raw index generation for cross-ref keywords.

  Revision 1.9  1999/04/27 09:01:17  kehr
  Defined a clean exit code as suggested by Klaus Guntermann
  <guntermann@iti.informatik.tu-darmstadt.de>.

  Revision 1.8  1999/04/27 08:57:48  kehr
  Added quoting patch sent by Thomas Henlich <thenlich@Rcs1.urz.tu-dresden.de>

  Revision 1.7  1999/04/27 08:56:59  kehr
  Another checkin.

  Revision 1.6  1997/02/13 14:42:50  kehr
  Minor changes.

  Revision 1.5  1997/01/21 16:44:36  kehr
  Bugfix: State <print> was not changed back to <key> if {LEVEL} was found.

  Revision 1.4  1997/01/17 16:30:37  kehr
  Rewrote makeindex4 and heavily modified tex2xindy.

  Revision 1.3  1996/07/19  17:15:18  kehr
  Made this program comaptible with lex by correctly enclosing all
  actions--stupid bug, 'cause lex didn't complain and flex did some
  wonderful matching of all the actions such that no error was
  discovered.

  Revision 1.2  1996/07/11  14:16:55  kehr
  Complete Major checkin before changing the letter-groups.

  Revision 1.1  1996/06/24  08:53:57  kehr
  Initial checkin of the Makefile, README and tex2xindy.
*/
