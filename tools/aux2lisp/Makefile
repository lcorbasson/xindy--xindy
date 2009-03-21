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

PROJECT = xindy
DATE = `ident $< | grep '\$$Id' | sed -e 's/^.*,v [^ ]* //' -e 's/ .*//' -e s:/:-:g`
VERSION = `ident $< | grep '\$$Id' | sed -e 's/^.*,v //' -e 's/ .*//'`


# here we go

all:: tex2xindy tex2xindy.1

tex2xindy.c: tex2xindy.l
	$(LEX) tex2xindy.l > tex2xindy.c

tex2xindy: tex2xindy.c
	$(CC) $(CFLAGS) tex2xindy.c -o tex2xindy $(LEXLIB)

tex2xindy.1: tex2xindy.l
	/usr/bin/pod2man --name tex2xindy --center '$(PROJECT)' \
		--date "$(DATE)" \
		--release "Version $(VERSION)" \
		$< >$@

tex2xindy.pdf: tex2xindy.1
	groff -man -P-g $< | ps2pdf - $@


clean::
	$(RM) tex2xindy tex2xindy.c tex2xindy.1 tex2xindy.pdf


# makeindex4 is depreciated and not part of the source distribution.
# Make sure that the install targets also works in its absence.

install:: all
	cp tex2xindy `ls makeindex4 2>/dev/null` /opt/xindy*/bin

