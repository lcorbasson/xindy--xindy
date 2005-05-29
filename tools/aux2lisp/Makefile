# $Id$
#------------------------------------------------------------
#
# This is the Makefile for utilities that transform LaTeX idx
# files into xindy raw index format.
#

# Adjust the following lines if necessary

LEX    = flex -t
LEXLIB = -lfl

#
# Usual stuff
#
RM     = /bin/rm -f
CFLAGS = -O2

# here we go

all:: tex2xindy

tex2xindy.c: tex2xindy.l
	$(LEX) tex2xindy.l > tex2xindy.c

tex2xindy: tex2xindy.c
	$(CC) $(CFLAGS) tex2xindy.c -o tex2xindy $(LEXLIB)

clean::
	$(RM) tex2xindy tex2xindy.c


# makeindex4 is depreciated and not part of the source distribution.
# Make sure that the install targets also works in its absence.

install:: all
	cp tex2xindy `ls makeindex4 2>/dev/null` /opt/xindy*/bin

