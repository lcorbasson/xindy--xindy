#
# $Id$
#
# This is the Makefile for the utilities delivered with `xindy'.
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

all: tex2xindy

tex2xindy.c: tex2xindy.l
	$(LEX) tex2xindy.l > tex2xindy.c

tex2xindy: tex2xindy.c
	$(CC) $(CFLAGS) tex2xindy.c -o tex2xindy $(LEXLIB)

clean: force
	$(RM) tex2xindy tex2xindy.c

force:

