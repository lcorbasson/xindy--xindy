#!/usr/bin/perl
# $Id$
#------------------------------------------------------------
# (history at end)

=head1 NAME

xindy  -  XXX

=head1 SYNOPSIS

XXX

=head1 DESCRIPTION

XXX

=cut


use strict;

BEGIN {
    use vars qw($Revision $VERSION);
    q$Revision$ =~ /: (\d+)\.(\d+)/ ;	# q wg. Emacs indent!
    my ($major, $minor) = ($1, $2);
    $VERSION = "$major." . ($minor<10 ? '0' : '') . $minor;
}


# Some common variables.
# Determine environment. Where is our library directory, and our modules?

use File::Basename;
our ($cmd_dir, $cmd, $lib_dir, $modules_dir);
BEGIN {
    $cmd_dir = dirname($0);
    $cmd = basename($0);

    # library directory
    if ( $ENV{XINDY_LIBDIR} ) {
	$lib_dir = $ENV{XINDY_LIBDIR};
    } elsif ( -f "$cmd_dir/../lib/xindy.run" ) { # /opt style
	$lib_dir = "$cmd_dir/../lib";
    } elsif ( -d "$cmd_dir/../lib/xindy" ) { # /usr or /usr/local style
	$lib_dir = "$cmd_dir/../lib/xindy";
    } else {
	die "Cannot locate xindy library directory";
    }

    # modules directory
    if ( -d "$cmd_dir/../modules" ) {	# /opt style
	$modules_dir = "$cmd_dir/../modules";
    } elsif ( -d "$lib_dir/modules" ) {	# /usr or /usr/local style
	$modules_dir = "$lib_dir/modules";
    } else {
	die "Cannot locate xindy modules directory";
    }
}


# Used modules.

use Getopt::Long qw(:config bundling);
use File::Temp qw(tempfile tmpnam);
use File::Spec;


# Check arguments, store them in proper variables.
#
# Do also something for backward compatibility: Check if this is an
# old-style call. If it is, we have two arguments at the end, and the
# second-to-last has the extension ".xdy". Then, call the old driver
# script with the original arguments...

sub usage ()
{
    print STDERR <<_EOT_
usage: $cmd [-V?h] [-qv] [-d magic] [-o outfile.ind] [-t log] \\
            [-L lang] [-C codepage] [-M module] [-I input] \\
            [--interactive] [--mem-file=xindy.mem] \\
	    [idx0 idx1 ...]

GNU-STYLE LONG OPTIONS FOR SHORT OPTIONS:

 -V / --version
 -? / -h / --help
 -q / --quiet
 -v / --verbose
 -d / --debug          (multiple times)
 -o / --out-file
 -t / --log-file
 -L / --language
 -C / --codepage
 -M / --module         (multiple times)
 -I / --input-markup   (supported: latex, xindy)

_EOT_
  ;
    exit 1;
}

our ($output_version, $quiet, $verbose, %debug,
     $outfile, $logfile, $language, @codepages, @modules, $input_markup,
     $interactive, $mem_file);
$input_markup = 'latex';

my @orig_argv = @ARGV;
parse_options();
output_version()  if $output_version;	# will not return

if ( @ARGV == 2 ) {
    if ( $ARGV[0] =~ /\.xdy$/ ) {
	exec "$cmd_dir/xindy.v2", @orig_argv;
    }
}


# This script creates temporary files. Whenever a file is created, its
# name is added to @temp_files. In an END handler, the temporary files
# are deleted. Signal handlers are set up to get proper program
# termination on user-induced signals. During program calls with
# system, SIGINT and

our @temp_files = ();
handle_signals();
END {
    unlink (@temp_files)  if ( @temp_files  &&  ! $debug{keep_tmpfiles} );
}


# Raw index handling: xindy is not able (yet?) to handle arguments
# Perl-style, so we do it instead. We gather the raw index in a
# temporary file. We also process it by the filter program it if
# wanted. Signal handlers will discard temporary files if necessary.

our $raw_index = File::Spec->devnull;
unless ( $interactive ) {
    $raw_index = create_raw_index();	# processes @ARGV
    $raw_index = filter_index ("$cmd_dir/tex2xindy", $raw_index)
      if ( $input_markup eq 'latex' );
}


# Execution: Obey environment variables, create xindy start
# expression, and eventually call it.

my $xindy_expression = xindy_expression(); # accesses global option vars
my $exit_code = call_xindy ($mem_file, $xindy_expression);


# Finished: exit, clean up in END handler.

exit ($exit_code);


# ------------------------------------------------------------


sub parse_options() {

    my (@debug);
    GetOptions(
		'version|V'          => \$output_version,
		'help|h|?'           => \&usage,
		'quiet|q'            => \$quiet,
		'verbose|v'          => \$verbose,
		'debug|d=s'          => \@debug,
		'out-file|o=s'       => \$outfile,
		'log-file|t=s'       => \$logfile,
		'language|L=s'       => \$language,
		'codepage|C=s'       => \@codepages,
		'module|M=s'         => \@modules,
		'input-markup|I=s'   => \$input_markup,
		'interactive'        => \$interactive,
		'mem-file=s'         => \$mem_file,
	      );

    # Debug option values are easier to test in a hash. Clean up trace
    # level options, too.

    %debug = map { $_ => 1 } @debug;
    my @trace_level = grep /^level=/, @debug;
    if ( @trace_level > 1 ) {
	print STDERR "You can only specify one trace level.\n\n";
	exit (1);
    }
    delete $debug{$trace_level[0]};
    $trace_level[0] =~ s/^level=// ;
    $debug{trace_level} = $trace_level[0];


    # Default for the output file: first argument, with extension replaced
    # by ".ind".

    unless ( $outfile  ||  $output_version || $interactive ) {
	if ( @ARGV == 0 ) {
	    print STDERR
"You need to specify --out-file if the raw index is read from standard input.\n\n";
	    usage();
	}
	my ($name, $path, $suffix) = fileparse ($ARGV[0], '\.[^\.]+');
	$outfile = "$path$name.ind";
    }


    # FIXME: xindy wants a log file. Really?

    $logfile = File::Spec->devnull  unless $logfile;


    # Modules fixup: If they have no .xdy suffix, they get one.
    @modules = map { /\.xdy$/ ? $_ : "$_.xdy" } @modules;


    # FIXME: Must cleanup the *-markup and filter option mess. These are
    # currently fake options, and must be evolved into real multi-markup
    # support.

    if ( $input_markup  &&
	 $input_markup ne 'latex' && $input_markup ne 'xindy' ) {
	print STDERR "Unsupported input markup $input_markup.\n\n";
	usage();
    }


    # Default memory file is xindy.mem, of course.

    $mem_file = "$lib_dir/xindy.mem"  unless $mem_file;
}



#
# SIGNAL HANDLING
#
# FIXME: This is not good enough. We also need to kill subprocesses,
# i.e., filter or xindy, if they are running.

# Our signal handler function just exits. Temporary files are deleted
# by the END section above. Actually, the exit code looses the
# information about the received signal, that's not good but shouldn't
# hurt either...

sub signal_exit() {
    exit (2);
}

sub handle_signals () {
    $SIG{'HUP'}  = \&signal_exit; # 1
    $SIG{'INT'}  = \&signal_exit; # 2
    $SIG{'QUIT'} = \&signal_exit; # 3
    $SIG{'TERM'} = \&signal_exit; # 15
}



#
# CREATION OF RAW XINDY INDEX
#

# Handle input files Perl-style. Returns file name that contains
# concatenated input file contents.

sub create_raw_index () {
    my ($output, $outfile) = tempfile();
    push (@temp_files, $outfile);
    while ( <> ) {
	print $output $_;
    }
    close ($output);
    print "concatenated xindy input file: $outfile\n"  if $debug{script};
    return $outfile;
}


# Run a filter over raw index. Returns file name with filtered raw
# index, supposed to be in xindy input format.
#
# We assume the file names to be safe from shell meta characters since
# they were computed by File::Temp.

sub filter_index ( $$ ) {
    my ($filter, $input) = @_;
    my $output = tmpnam();
    push (@temp_files, $output);
    print "Running filter: $filter <$input >$output\n"  if $verbose;
    system "$filter <$input >$output";
    print "filtered xindy input file: $output\n"  if $debug{script};
    return $output;
}



#
# XINDY EXECUTION
#

# Construct final xindy expression, from options.

sub xindy_expression () {
    my ($logging, $tracing, $trace_level);

    # Determine language module of make-rules framework. Part of the
    # complexity below is from compatibility with the TLC2
    # description. We need to support the language names listed there,
    # even though they are not current. In addition, the codepage
    # option was introduced later and we need to guess it. This
    # guesswork will often be wrong, sadly.
    #
    # FIXME: I didn't see all languages. What's on with gypsy and
    # hausa?
    if ( $language ) {
	my $ld = "$modules_dir/lang";
	my $variant;
	# If there is no language directory, this might be a variant.
	# Language names and variants are separated by hyphens. The
	# variant name "din" is an abbreviation for "din5007". The
	# variant name "iso" is ignored, that is actually a codepage
	# name.
	#
	# FIXME: Or is "iso" the variant "translit"?!
	if ( ! -d "$ld/$language" ) {
	    $language =~ /(.*)-(.*)/ ;	# there is only one hyphen allowed
	    if ( $2 && -d "$ld/$1" ) { # $2 is not set if the regex didn't match
		$language = $1;
		$variant = "$2-"  unless ( $2 eq 'iso' );
		$variant =~ s/din/din5007/ ;
	    }
	}
	# Let's guess the codepage. We take any that starts with
	# "latin", "cp", "iso8859", or "ascii".
	@codepages = qw(latin cp iso8859 ascii)  unless @codepages;
	my @styles;
	foreach my $cp ( @codepages ) {
	    @styles = glob("$ld/$language/$variant$cp*-lang.xdy");
	    last  if @styles;
	}
	unless ( @styles ) {
	    print STDERR "Cannot locate xindy module for language $language";
	    print STDERR " in codepage $codepages[0]"  if ( @codepages == 1 );
	    print STDERR ".\n";
	    exit (1);
	}
	# Extract language module name: It's the relative part after
	# the module directory. Put it at the front of the list of
	# needed modules. It's important that the language module is
	# loaded first, it defines the sort rulesets, and subsequent
	# modules shall be able to add sort rules.
	unshift (@modules, substr($styles[0], length("$modules_dir/")));
	print "Found language module $styles[0]\n"  if $debug{script};
    }

    # If there is more than one xindy module, construct a style file.
    # This is bad, of course; xindy should handle a list of style
    # files itself.
    my $style_file = $modules[0];	# will be undef if @modules is not set
    if ( @modules > 1 ) {
	my $sf;
	($sf, $style_file) = tempfile();
	push (@temp_files, $style_file);
	foreach my $module ( @modules ) {
	    print $sf "(require \"$module\")\n";
	}
	close ($sf);
    }

    $style_file = quotify($style_file);
    $outfile = quotify($outfile);
    $logging = ':logfile ' . quotify($logfile)  if $logfile;
    $tracing = ':markup-trace :on'  if $debug{markup};
    $trace_level = ":trace-level $debug{trace_level}"  if $debug{trace_level};

    my $exp = <<_EOT_
(progn
  (searchpath ".:$modules_dir:$modules_dir/base")
  (xindy:startup
    :idxstyle $style_file
    :rawindex "$raw_index"
    :output $outfile
    $logging
    $tracing
    $trace_level)
  (exit))
_EOT_
  ;

    return $exp;
}


# Actual xindy call. Returns exit code.

sub call_xindy ( $$ ) {
    my ($mem_file, $xindy_exp) = @_;

    my @command = ("$lib_dir/xindy.run", '-q', '-B', $lib_dir, '-M', $mem_file);
    if ( $interactive ) {
	print "Proposed xindy expression:\n\n$xindy_exp\n"  unless $quiet;
    } else {
	push (@command, '-x', $xindy_exp);
    }

    if ( $debug{script} ) {
	print "modules directory: $modules_dir.\n";
	print "command: @command\n";
    }

    if ( $quiet && ! $interactive ) {
	open (STDOUT, '>', File::Spec->devnull);
    }
    system @command;
    if ( $? & 127 ) {
	return 4;
    } else {
	return $? >> 8;
    }
}

sub output_version () {
    print "Script version: $VERSION\n";
    my $exit_code = call_xindy($mem_file,
			   "(progn (xindy:startup :show-version t) (exit))");
    exit ($exit_code);
}


# Helper function: Make a proper quoted Lisp string.

sub quotify ( $ ) {
    my $s = shift;
    $s =~ s:[\\\"]:\\&1:g ;		# quote double-quote and backslash
    return "\"$s\"";
}



#======================================================================
#
# $Log$
# Revision 1.1  2004/05/24 19:47:13  jschrod
#     Introduce new driver script, as part of the "Companion Release".
#
