# $Id$
#----------------------------------------------------------------------

#
# Makefile
#

XINDY_BINDIR=/usr/local/lib/xindy/bin
XINDY_LIBDIR=/usr/local/lib/xindy

xindy.sh : force
	-sed -e "s|@XINDY_BINDIR@|$(XINDY_BINDIR)|" \
	     -e "s|@XINDY_LIBDIR@|$(XINDY_LIBDIR)|" \
	     < xindy.sh.in > xindy.sh
	-chmod a+x xindy.sh

force:
