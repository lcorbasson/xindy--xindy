%{
  /*

   $Id$

   This is the source of `tex2xindy'.

   It tries to parse an TeX-auxiliary-file `.aux' or index-file
   `.idx' into a raw-index-form readable by xindy.

   This can also be used as a template for writing other frontends
   for  xindy. Please send us your preprocessors. We are likely
   to include them into the distribution.

   This program was written since it was not possible to extract
   the parser from the old makeindex system. It is also a hack
   but its easy maintainable.

   */

int lineno = 1;
int braces = 0;

#define err( msg ) fprintf(stderr, "%d: %s\n", lineno, msg)

#define NO_RANGE     0
#define OPEN_RANGE   1
#define CLOSE_RANGE  2

int range = NO_RANGE;

void qc( char ch ) {
  switch (ch) {
    case '\\' : putchar( '\\' ); break;
    case '"'  : putchar( '\\' ); break;
  }
  putchar(ch);
}

void qs( char* str ) {
  while ( *str ) {
    qc( *str++ );
  }
}

%}

INDEXENTRY   \\indexentry

%s key print skip2location location encap

%%

^{INDEXENTRY}[ \t]*\{   printf("(indexentry :tkey ((\""); BEGIN(key);

<key,print>[^\"\|@\}\{!\\]*   ECHO; /* until the meta-chars */
<key,print>\\       qc('\\'); qc(input());
<key,print>\"       qc(input());
<key,print>\|     { printf("\")) :attr \"");
                    range = NO_RANGE; BEGIN(encap); }
<key,print>!        printf("\") (\"");
<key,print>\{       ECHO; braces++;
<key,print>\}     { if ( braces > 0 )
                         {ECHO; braces--;}
                      else
			 {printf("\"))");
		          BEGIN(skip2location);}
                  }

<key>@              printf("\" \""); BEGIN(print);
<print>@            err( "multiple @'s" );

<encap>\|           err( "multiple |'s" );
<encap>\\           qc('\\'); qc(input());
<encap>\(           range = OPEN_RANGE;
<encap>\)           range = CLOSE_RANGE;
<encap>\{           ECHO; braces++;
<encap>\}         { if ( braces > 0 )
                       {ECHO; braces--;}
                    else {
		       putchar('"');
		       switch (range) {
                         case OPEN_RANGE : printf(" :open-range");
			                   break;
                         case CLOSE_RANGE: printf(" :close-range");
			                   break;
		       }
		       BEGIN(skip2location);
		    }
                  }
<encap>.            ECHO;

<skip2location>[ \t]*\{   printf(" :locref \""); BEGIN(location);

<location>\}        printf("\")\n"); BEGIN(0);
<location>.         ECHO;

\n                  lineno++;
.

%%

main()
{
  fprintf(stderr, "This is `tex2xindy' version 0.9 July 1996.\n");
  fprintf(stderr, "Copyright (c) 1996  Roger Kehr\n\n");
  yylex();
}

/*
  $Log$
  Revision 1.2  1996/07/11 14:16:55  kehr
  Complete Major checkin before changing the letter-groups.

  Revision 1.1  1996/06/24  08:53:57  kehr
  Initial checkin of the Makefile, README and tex2xindy.


*/
