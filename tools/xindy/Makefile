# $Id$
#----------------------------------------------------------------------

#
# Makefile for generating the shell-wrapper
#

XINDY_LIBDIR=/usr/local/lib/xindy

xindy : xindy.in
	-sed -e "s|@XINDY_LIBDIR@|$(XINDY_LIBDIR)|" \
	     < xindy.in > xindy
	-chmod a+x xindy

test : force
	$(MAKE) XINDY_LIBDIR=$(CLISP_LIBDIR) xindy

force:
