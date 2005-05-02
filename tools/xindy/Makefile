# $Id$
#----------------------------------------------------------------------

#
# Makefile for generating the old, depreciated shell wrapper
#

all:: xindy.v2

xindy.v2: xindy.in
	sed 's:@XINDY_PERL@:/usr/bin/perl:' xindy.in >xindy.v2
	-chmod a+x xindy.v2


install::
	cp xindy.v2 /opt/xindy*/bin
