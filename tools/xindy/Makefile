# $Id$
#----------------------------------------------------------------------

#
# Makefile
#

XINDY_LIBDIR=/usr/local/lib/xindy
XINDY_BINDIR=/usr/local/lib/xindy

xindy : xindy.in
	-sed -e "s|@XINDY_BINDIR@|$(XINDY_BINDIR)|" \
	     -e "s|@XINDY_LIBDIR@|$(XINDY_LIBDIR)|" \
	     < xindy.in > xindy
	-chmod a+x xindy

test : force
	$(MAKE) XINDY_BINDIR=$(CLISP_LIBDIR) \
	        XINDY_LIBDIR=$(CLISP_LIBDIR) xindy

force:
