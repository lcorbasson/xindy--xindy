# $Id$
#----------------------------------------------------------------------

#
# Makefile for generating the shell wrapper
#

xindy.v2 : xindy.in
	cp xindy.in xindy.v2
	-chmod a+x xindy.v2

test : force
	$(MAKE) xindy.v2

force:
