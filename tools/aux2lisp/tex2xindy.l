%{
  /*

   $Id$

   This is the source of `tex2xindy'.

   It tries to parse an TeX-auxiliary-file `.aux' or index-file
   `.idx' into a raw-index-form readable by xindy.

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
   xindy. Please send us your preprocessors. We are likely to include
   them into the distribution. */

#include <stdio.h>

static FILE* stat = NULL;

static int lineno    = 1;
static int braces    = 0;
static int xref_mode = 0;

#define err( msg ) fprintf(stderr, "line %d: %s\n", lineno, msg)

#define NO_RANGE     0
#define OPEN_RANGE   1
#define CLOSE_RANGE  2

static int range = NO_RANGE;

/* This function quotes a character, if necessary. */

void qc( char ch ) {
  switch (ch) {
    case '\\' : putchar( '\\' ); break;
    case '"'  : putchar( '\\' ); break;
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
ENCAP    \|
ACTUAL   @
ESCAPE   \\
LEVEL    !
QUOTE    \"
ROPEN    \(
RCLOSE   \)
ARGOPEN  \{
ARGCLOSE \}

%s key print skip2location location encap xref skiplocation

%%

^{KEYWORD}[ \t]*{ARGOPEN} { printf("(indexentry :tkey ((\"");
                            xref_mode = 0;
                            BEGIN(key); }

<key,print>{ESCAPE}    { qc('\\'); qc(input()); }
<key,print>{QUOTE}     { qc(input()); }
<key,print>{ENCAP}     { printf("\")) :attr \"");
                         range = NO_RANGE; BEGIN(encap); }
<key>{LEVEL}           { printf("\") (\""); }
<print>{LEVEL}         { printf("\") (\""); BEGIN(key); }
<key,print>{ARGOPEN}   { ECHO; braces++; }
<key,print>{ARGCLOSE}  { if ( braces > 0 )
                           {ECHO; braces--;}
                         else
			   {printf("\"))");
		         BEGIN(skip2location);}
                       }

<key>{ACTUAL}          { printf("\" \""); BEGIN(print); }
<print>{ACTUAL}        { err( "multiple @'s" ); }

<key,print>.           { qc(*yytext);}

<encap>{ENCAP}         { err( "multiple |'s" ); }
<encap>{ESCAPE}        { qc('\\'); ECHO; }
<encap>{ROPEN}         { range = OPEN_RANGE; }
<encap>{RCLOSE}        { range = CLOSE_RANGE; }
<encap>{ARGOPEN}       { /* close :attr "... */
                         printf("\" :xref (\"");
			 if (stat) { fprintf(stat, "\txref\n"); }
		         braces++;
		         BEGIN(xref);
                       }
<encap>{ARGCLOSE}      { if ( braces > 0 )
                           {ECHO; braces--;}
                         else {
			   putchar('"');
			   if (stat) { fprintf(stat, "\tlocref\n"); }
			   switch (range) {
			     case OPEN_RANGE : printf(" :open-range");
			       break;
			     case CLOSE_RANGE: printf(" :close-range");
			       break;
			   }
			   BEGIN(skip2location);
			 }
                       }
<encap>.              { ECHO;
                        if (stat) { fwrite(yytext, sizeof(char), 1, stat); }
	              }



<xref>{ESCAPE}         { qc('\\'); qc(input()); }
<xref>{ARGOPEN}        { ECHO; braces++; }
<xref>{ARGCLOSE}       { if     ( braces >   1 )
                           {ECHO; braces--;}
                         else if ( braces == 1 )
		           { braces--; }
                         else {
		           printf("\")");
			   xref_mode = 1;
		           BEGIN(skip2location);
		         }
                       }
<xref>.               { qc(*yytext); }

<skip2location>[ \t]*{ARGOPEN} {
                        if (xref_mode)
			  { BEGIN(skiplocation); }
			else
			  { printf(" :locref \"");
			    BEGIN(location);
			  }
                       }

<location>{ARGCLOSE}  { printf("\")\n"); BEGIN(0); }
<location>.           {ECHO;}

<skiplocation>{ARGCLOSE} { printf(")\n"); BEGIN(0); }
<skiplocation>.       { ; }

\n                    { lineno++; }
.                     { ; }

%%


main(int argc, char* argv[])
{
  fprintf(stderr, "This is `tex2xindy' $Revision$.\n");
  if ( argc > 1 ) {
    fprintf(stderr, "Running in makeindex compatibility mode.\n");
    fprintf(stderr, "Writing attribute names to file \"%s\".\n\n", argv[1]);
    stat = fopen(argv[1], "w");
  }
  yylex();
  if (stat) { fclose(stat); }
}

/*
  $Log$
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
