/* $Id$
 *----------------------------------------------------------------------
 *
 * Ordering Rules for Strings
 *
 * [history at end]
 */

#include "ordrules.h"
#include "rxsub.h"

#define debug
#undef debug
#include "debug.h"


RULE_TABLE SortRules;	/* rules for generating sortkeys */
RULE_TABLE MergeRules;	/* rules for generating mergekeys */
GROUP_LIST GroupList;	/* list of character groups */
GROUP_LIST HeadingList;	/* list of group headings */

static RULE_TYPE get_ruletype PROTO(( char *lside, char *rside ));
static int       is_regexp PROTO(( char *s ));
static void      unescape PROTO(( register char *s ));


/* insert rule 'left --> right' into ruletable 'table' */
void
add_rule( table, left, right, isreject)
RULE_TABLE table;
char *left;
char *right;
int isreject;
{
  RULE *r;
  RULE_LIST *list;
  char buffer[STRING_MAX];
  char *bptr = buffer;
  unsigned int pos;

  /* new stuff */
  int errcode;
  int cflags = 0; /* regcomp-flags */
  char errmsg[STRING_MAX];

  dispstart( add_rule );
  r = (RULE *) fmalloc( sizeof(RULE) );

  switch (r->type = get_ruletype( left, right )) {

    case REG_RULE:

      dispstart( REG_RULE );
      dispmsg( bptr copy );
      /* insert '^' in regular expression to match string prefix only */
      *bptr++ = '^'; strcpy( bptr, left );
      dispmsg( fmalloc );
      r->r.reg.lside = (regex_t*) fmalloc (sizeof(regex_t));
      displong( r->r.reg.lside );
      dispstart( regcomp );
      if ( 0 != (errcode = regcomp( r->r.reg.lside, buffer, cflags )) ) {
	regerror( errcode, r->r.reg.lside, errmsg, STRING_MAX );
	fprintf( stderr, "add_rule: %s\n", errmsg );
	return;
      }
      dispend( regcomp );
      r->r.reg.rside = (char *) fmalloc( strlen(right) + 1);
      strcpy( r->r.reg.rside, right );
      dispstr( r->r.reg.rside );
      displong( r->type );

      /*
       * calculate table index as the first character of 'left'
       * or FORALL_POS if the rule does not start with a fixed charater.
       * A rule starts with a fixed character if this char is escaped.
       * Otherwise the first character might be variable (ie, a character
       * class) or it might be optional.
       */

      if ( left[0] == BSH )  pos = (unsigned char)(left[1]); /* quoted */
      else
        if ( strchr(".([",left[0])==NULL || strchr("*?",left[1])==NULL )
	  pos = FORALL_POS; /* character class or optional */
        else
	  pos = (unsigned char)(left[0]); /* fixed */

      dispend( REG_RULE );
      break;

    case CHR_RULE:
      r->r.chr  = *right;
      pos = *left;
      break;

    case STR_RULE:
      r->r.str.llen = strlen(left);
      r->r.str.lside = (char *) fmalloc(r->r.str.llen + 1);
      strcpy(r->r.str.lside,left);
      r->r.str.rlen = strlen(right);
      r->r.str.rside = (char *) fmalloc(r->r.str.rlen + 1);
      strcpy(r->r.str.rside,right);
      pos = *left;
      break;
  }

  if (isreject) r->type |= REJECT;

  /* insert new rule into table */
  list = &table[pos];
  if (list->first == NULL) list->first = r;
                 else list->last->next = r;
  list->last = r;
  r->next = NULL;

#ifdef DEBUG
  fprintf(stderr,"\nordrules: added %s%s-rule at position %d ",
	         (r->type&REJECT)?"*":"",table == MergeRules ? "merge" : "sort",pos);
  fprintf(stderr,"type %o.",r->type);
  switch ( r->type & ~REJECT ) {
    case CHR_RULE:
      fprintf(stderr,"(CHR,'%c' --> '%c').",*left,r->r.chr); break;
    case STR_RULE:
      fprintf(stderr,"(STR,'%s' --> '%s').",r->r.str.lside,r->r.str.rside); break;
    case REG_RULE:
      fprintf(stderr,"(REG,'%s' --> '%s').",buffer,r->r.reg.rside); break;
  }
#endif
  dispend( add_rule );
}

/* get the type of the rule 'lside --> rside', and delete escape sequences '\.'
   in both strings if they are not regular expressions. */
static
RULE_TYPE get_ruletype( lside, rside )
char *lside;
char *rside;
{
  if ( is_regexp( lside ) || is_regexp( rside ) ) return REG_RULE;

  unescape(lside);
  unescape(rside);

  if ( lside[0] != NUL && lside[1] == NUL &&
       rside[0] != NUL && rside[1] == NUL ) return CHR_RULE;

  return STR_RULE;
}

/* return TRUE, if 's' is a regular expression. */
static
int is_regexp( s )
char *s;
{
  for (;*s ; s++ )
    if (*s == BSH) {
      s++;
      if ('0' <= *s && *s <= '9') return TRUE;
    }
    else if (strchr("[]().*+$^?&",*s)) return TRUE;
  return FALSE;
}

/* replace all '\x' sequences with the character they represent */
static void
unescape( s )
register char *s;
{
  register char *d;
  for (d = s; *d = *s; d++)
    if (*s++ == BSH) *d = *s++;
}

/* apply the rules from 'table' to 'source' and place the substituted result
   in 'dest' */
void apply_rules( table, source, dest, buflen )
RULE_TABLE table;
register char *source;
register char *dest;
register size_t buflen;
{
  register RULE *r;
  register RULE_TYPE rtype;
  register char *newdest;
  char newsource[STRING_MAX];

  /* new stuff */
#define NMATCH 10
  regmatch_t regmatch [NMATCH];
  int eflags = 0;

#ifdef DEBUG
  char *in = source, *out = dest;
#endif

  dispstart( apply_rules );
  while ( *source ) {

    /* first check the rules beginning with character '*source' */
    for ( r = table[(unsigned) *source].first; r; r = r->next ) {

      rtype = (r->type & ~REJECT);

      if ( rtype == CHR_RULE ) {
	dispstart( CHR_RULE );
      	if ((r->type & REJECT)) newdest = dest;
      	*dest++ = r->r.chr;
	source++;
	dispend( CHR_RULE );
      	break;
      }

      else if ( rtype == STR_RULE &&
		!strncmp(source, r->r.str.lside, (size_t)r->r.str.llen)) {
	dispstart( STR_RULE );
	displong( dest );
	strcpy(dest, r->r.str.rside);
      	if ((r->type & REJECT)) newdest = dest;
	displong( newdest );
	dest   += r->r.str.rlen;
	displong( dest );
	source += r->r.str.llen;
	displong( source );
	dispend( STR_RULE );
      	break;
      }

      else {
	if ( rtype == REG_RULE ) {
	  dispstart( REG_RULE );
	  if ( 0 == regexec( r->r.reg.lside, source,
			     NMATCH, regmatch, eflags ) ) {
	    nrxsub( r->r.reg.rside, regmatch, source, dest, buflen );
	    if ((r->type & REJECT))
	      newdest = dest;
	    dest   = strchr(dest,0);
	    source += regmatch[0].rm_eo;
	    dispend( REG_RULE );
	    break;
	  }
	  dispend( REG_RULE );
	}
      }

    }

    if ( r == NULL ) {

      /* check regular expression rules, that could match all prefixes */
      for ( r = table[FORALL_POS].first; r; r = r->next ) {
	dispstart( NULL );
	displong( r->r.reg.lside );
	dispstr(r->r.reg.rside );
	displong( r->type );
	if ( 0 == regexec( r->r.reg.lside, source,
			   NMATCH, regmatch, eflags ) ) {
	  dispstart( regexec match! );
	  nrxsub( r->r.reg.rside, regmatch, source, dest, buflen );
      	  if ((r->type & REJECT)) newdest = dest;
	  displong( dest );
	  displong( newdest );
	  source += regmatch[0].rm_eo;
	  displong( source );
	  dest   = strchr(dest,0);
	  displong( dest );
	  dispend( regexec match! );
      	  break;
        }
	dispend( NULL );
      }
      /* no rule matched, copy character */
      if ( r == NULL ){
	dispstart( NULL2 );
	displong( dest );
	displong( source );
	*dest++ = *source++;
	displong( dest );
	displong( source );
	dispend( NULL2 );
      }
    }

    /* should we reject? */
    if ( r != NULL && (r->type & REJECT)) {
      dispstart( REJECT );
      strcpy(dest,source);
      strcpy(newsource,newdest);
#ifdef DEBUG
      fprintf(stderr,"\nordrules: reject in '%s': '%s'.",in,newsource);
#endif
      apply_rules( table, newsource, newdest, STRING_MAX );
      dispend( REJECT );
      return;
    }

  }

  displong( dest );
  *dest = 0;

#ifdef DEBUG
  if ( strcmp(in,out) )
    fprintf(stderr,"\nordrules: %s '%s' generated for '%s'.", table == MergeRules ? "mergekey" : "sortkey", out, in );
#endif

  dispend( apply_rules );
}

/* insert a new group entry ('group','letter') into 'list' */
#if 0
void
add_group( list, group, letter )
GROUP_LIST *list;
int group;
char *letter;
{
  GROUP_RULE *new;
  new = (GROUP_RULE *) fmalloc(sizeof(GROUP_RULE));
  new->id = (group >= 0 ? group + USORTGROUP : group - USORTGROUP);
  new->len = strlen(letter);
  new->let = (char *) fmalloc(new->len + 1);
  strcpy(new->let,letter);

  /* insert rule into list */
  if (list->first == NULL) list->first = new;
                 else list->last->next = new;
  list->last = new;
  new->next = NULL;

#ifdef DEBUG
  fprintf(stderr,"\nordrules: added group into list '%s' '%s' -> group: %d.",list == &GroupList ? "GroupList" : "HeadingList", new->let,new->id);
#endif
}

/* find the user defined group id for 'sortkey' */
int get_group( sortkey )
char *sortkey;
{
  register GROUP_RULE *r;
  for (r = GroupList.first; r && strncmp(sortkey,r->let,r->len); r = r->next);
#ifdef DEBUG
  if (r != NULL)
    fprintf(stderr,"\nordrules: sortkey '%s' is in group: %d.",sortkey,r->id);
#endif
  return ( r ? r->id : *sortkey );
}

/* find the user defined group heading for id 'group' */
char *get_heading( group )
int group;
{
  register GROUP_RULE *r;
  for ( r = HeadingList.first; r && r->id != group; r = r->next);
#ifdef DEBUG
  if (r != NULL)
    fprintf(stderr,"\nordrules: group: %d has heading '%s'.",r->id,r->let);
#endif
  return ( r ? r->let : NULL );
}
#endif

/*
 * $Log$
 * Revision 1.1  1996/03/26 17:30:58  kehr
 * First check-in of the rx-support for clisp.
 *
 * Revision 1.9  1992/01/03  13:22:10  schrod
 * "unsigned" is not a type. Computation of table index was wrong.
 *
 * Revision 1.8  1991/12/16  14:44:54  schrod
 * fmalloc() statt allocate()
 *
 * Revision 1.7  1991/12/10  20:25:50  schrod
 * Changed all function declarations to ANSI prototypes using ARGS().
 *
 * Revision 1.6  1991/12/10  20:09:58  schrod
 * Reject-rules (*merge_rule and *sort_rule) implemented.
 *
 * Revision 1.5  1991/12/10  19:59:53  schrod
 * Fixed bug in ordrules. Inserting a new group rule at the beginning of
 * a rule list works not with groups, that have the same prefix:
 *
 * 	group_rule "ae" 1
 * 	group_rule "a"  2
 *
 * would put 'aexxx' in group 2.
 *
 * Revision 1.4  1991/12/10  19:49:59  schrod
 * Optimized group-rule handling.
 *
 * Revision 1.3  1991/12/10  19:43:38  schrod
 * Optimized module 'ordrules':
 * - all three types of rules (chr,str,regexp) now allowed for both sort
 *   and merge keys
 *
 * Revision 1.2  1991/12/10  19:20:31  schrod
 * Changed the group merging algorithm to create the group-id of an index key
 * using user defined rules (specified in the style file with commands:
 * `sort_group' and `group_head') instead of the sortkey's first character.
 *
 * Revision 1.1  1991/12/10  17:15:54  schrod
 * Initial revision
 *
 */
