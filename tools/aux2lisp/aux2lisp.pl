#!/usr/local/bin/perl
# $Id$
#----------------------------------------------------------------------

#
# aux2lisp
#
# (history at end)


# standard setup

$\ = "\n";
$0 =~ s#.*/##;                          # basename of command
chop( $date = `date` );                 # a handy constant


######################################################################

# check arguments
# store them in variables for better naming

if ( $#ARGV >= 0 ) {
    print "usage: $0";
    print <<EOMSG;

    This program reads a TeX .aux file from <stdin> and tries to parse
    all \\indexentry-expressions. For each expr a raw-index expression
    is written to <stdout> that can be read in by the xindy-system.

    The program is far from being perfect and uses some heuristics for
    parsing that may result in erroneous output.

EOMSG
    exit 1;
}

# $debug1 = 1;
# $debug2 = 1;
$quote    = "\"";
$layersep = "!";
$act_sep  = "@";

while (<>) {
    chop;
    if (/^\\indexentry\s*\{(.*)$/) {
	print "parsing $_" if $debug1;
	$original = $1;
	# The next statement replaces all quote-symbols with the
	# associated quoted symbol with a pair of blanks leaving the
	# string-length unchanged.
	($unquoted = $1) =~ s/$quote./  /g;
	print "unquoted = |$unquoted|" if $debug2;

 	# We can now parse the resulting string without any care for
 	# quoted symbols. Here we use a simple heuristic to find the
 	# end of the key-field: We start from the right and match for
 	# the "...}{location}" regexp. This may lead to erroneus
 	# situations but without this kludge there is no easy way of
 	# parsing the expression. Additionally this regexps yields the
 	# location in formal parameter $2.
	($allkey = $unquoted) =~ s/(.*)\}\{([^\{]+)\}$/\1/;
	$location = $2;
 	print "allkey = |$allkey|" if $debug2;
 	print "location = |$location|" if $debug2;

	# The next step is to remove the optional part of the keyword
	# that holds the attributes:
	($attr  = $allkey) =~ s/.*\|([^\|]+)$/\1/;
	if ($attr eq $allkey) {
	    $attr = "";
	}
	($qlkey = $allkey) =~ s/(.*)\|([^\|]+)$/\1/;
 	print "qlkey = |$qlkey|" if $debug2;
	print "attr  = |$attr|" if $debug1;

 	# Now we got the total length of the key and use it to extract
 	# the substring from the original.
 	$qkey = substr( $original, 0, length($qlkey) );
 	print "qkey = |$qkey|" if $debug2;
	# The remaining part of the string will now be:
	$rest = substr( $original, length($qlkey) );

	# Now parse the key. Note @keys, @act_key are passed by reference.
	&parse_keys( $qkey, $qlkey, @keys, @act_keys );
	print "keys = |@keys|, act_keys = |@act_keys|" if $debug1;

	$key = "";
	foreach $keylayer (@keys) {
	    print "keylayer = |$keylayer|" if $debug1;
	    ($keylayer = $keylayer) =~ s/\"(.)/\1/;
	    ($keylayer = $keylayer) =~ s/\"/\\\"/;
	    print "keylayer = |$keylayer|" if $debug1;
	    $key = $key . "\"" . $keylayer . "\" ";
	}
	$act_key = "";
	foreach $keylayer (@act_keys) {
	    print "keylayer = |$keylayer|" if $debug1;
	    ($keylayer = $keylayer) =~ s/\"(.)/\1/;
	    ($keylayer = $keylayer) =~ s/\"/\\\"/;
	    print "keylayer = |$keylayer|" if $debug1;
	    $act_key = $act_key . "\"" . $keylayer . "\" ";
	}
	($attr = $attr) =~ s/\"(.)/\1/;
	print "(indexentry :key ($key) :print ($act_key) :attr \"$attr\" :location \"$location\")";
 	print "";
    }
}

#
#

sub parse_keys {
    local($quoted_str,
	  $unquoted_str) = @_;
    local(@key_list, $layer, $unquoted_layer, $key,$act_key );

    @key_list = &split_string( $qkey, $qlkey, "!" );
    @keys = ();
    @act_keys = ();
    foreach $layer (@key_list) {
	($unquoted_layer = $layer) =~ s/$quote./  /g;
	($key,$act_key) = &split_string($layer, $unquoted_layer,
					$act_sep );
	print "key = |$key|, act_key = |$act_key|" if $debug2;
	push( @keys, $key );
	if ( $act_key eq "" ) {
	    push( @act_keys, $key );
	} else {
	    push( @act_keys, $act_key );
	}
    }
}

# This function should perform the following task:
# Given are two strings ($quoted_str and $unquoted) holding the
# following conidition: The unquoted string was generated from the
# quoted one by substituting *some* of its characters by blanks. Which
# actually were replaced doesn't matter at all. E.g. the following
# pair of strings satisfied the condition (quoting symbol is "\")
#   quoted_str:   "abc >\ncd jf\d"
#   unquoted_str: "abc >  cd jf  "
# whereas the follwing is not allowed
#   quoted_str:   "abc \ncd jf\d"
#   unquoted_str: "abcx  cd jf  ".
# Our task is now to separate the unquoted string by a
# separator-pattern and apply the splitting to quoted_str, i.e.
# splitting with the separator ">" yields the list of string
# ("abc " "\ncd jf\d) for the first example above.
#
# So given are the two strings and a string that matches with the
# separator.

sub split_string {
    local($quoted_str,
	  $unquoted_str,
	  $separator_str) = @_;
    local( @string_list, $piece, $pos, $terminate, $sep_len );

    print "! quoted_str   = |$quoted_str|" if $debug2;
    print "! unquoted_str = |$unquoted_str|" if $debug2;

    $sep_len = length( $separator_str );

    @string_list = (); # initialize the string-list
    do {
	# seek fo the first occurence of the separator-string.
	$pos = index( $unquoted_str, $separator_str );
	# check if it was found
	if ( $pos == -1 ) {
	    # ok, the remaining string matches completely
	    $piece = $quoted_str;
	    # correcte the position to the correct answer
	    $pos = length( $quoted_str );
	    # and we are finished
	    $terminate = 1;
	} else {
	    # take only the found substr
	    $piece = substr( $quoted_str, 0, $pos );
	}
	print "> quoted_str   = |$quoted_str|" if $debug2;
	print "> unquoted_str = |$unquoted_str|" if $debug2;
	print "> piece        = |$piece|" if $debug2;
	# shorten all strings by the length of the match plus
	# length($separator).
	$unquoted_str = substr( $unquoted_str, $pos+$sep_len );
	$quoted_str   = substr( $quoted_str, $pos+$sep_len );
	push( @string_list, $piece );
    } until ($terminate == 1);

    return @string_list;
}


#======================================================================
#
# $Log$
# Revision 1.2  1996/06/24 08:53:55  kehr
# Initial checkin of the Makefile, README and tex2xindy.
#
# Revision 1.1  1996/01/31  15:15:36  kehr
# Added the tool from converting .aux-files to Lisp-sexps.
#
