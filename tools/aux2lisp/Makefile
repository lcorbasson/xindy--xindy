#
# $Id$
#
# This is the Makefile for the utilities delivered with `xindy'.
#

# Adjust the following lines if necessary

#
# tex2xindy cannot be compiled using standard lex. Use flex instead.
# Modify the libraries according to your site.
#

FLEX    = flex -t
FLEXLIB = -L/usr/local/lib -L/usr/local/lib/lib -lfl

#
# Usual stuff
#
RM     = /bin/rm -f
CFLAGS = -O2

# here we go

all: tex2xindy

tex2xindy.c: tex2xindy.l
	$(FLEX) tex2xindy.l > tex2xindy.c

tex2xindy: tex2xindy.c
	$(CC) $(CFLAGS) tex2xindy.c -o tex2xindy $(FLEXLIB)

clean: force
	$(RM) tex2xindy tex2xindy.c

force:

