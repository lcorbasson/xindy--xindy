# $Id$
#----------------------------------------------------------------------
#
# The following targets are supported:
#
#  testsuite   : runs the complete testsuite
#

RM = /bin/rm -f

XINDY_PLATFORM = test-arch
ALLTESTS       = startup mappings infII xref-1 ex1 ex2 deep
TESTS 	       = $(ALLTESTS)
XINDY_DIR      = ../binaries/$(XINDY_PLATFORM)
LOGFILE	       = -l $$tst.xlg
TRACE	       = # -t

testsuite: banner clean tests compare

banner: force
	@echo
	@echo "Running tests on platform \"$(XINDY_PLATFORM)\"..."

tests: force
	@if [ ! -x $(XINDY_DIR)/xindy ]; then \
	  echo;\
	  echo "!!! You must run \`make' in directory $(XINDY_DIR) before running any tests !!!";\
	  echo; exit 1;\
	 fi
	@ XINDY_LIBDIR=$(XINDY_DIR);\
	  export XINDY_LIBDIR; \
	  for tst in $(TESTS); do \
	     echo ;\
	     echo "------------------------------";\
	     echo "Running test \"$$tst\".";\
	     echo "------------------------------";\
	     echo ;\
             $(XINDY_DIR)/xindy $(TRACE) $(LOGFILE) $$tst.xdy $$tst.raw ;\
	  done

compare: force
	@- $(RM) test.failed
	@ echo ;\
	  echo "--------------";\
	  echo "Checking tests";\
	  echo "--------------";\
	  echo
	@-for tst in $(TESTS); do \
	     if [ -x $$tst.sh ] ; then \
	        $$tst.sh ; \
	     else \
		cmp -s $$tst.ind $$tst.cmp ;\
	     fi ;\
	     if [ 0 != $$? ] ; then \
		echo "Test \"$$tst\" failed!" ; touch test.failed ;\
	     fi ;\
	  done
	@ if [ ! -f test.failed ] ; then echo "All tests passed !"; echo; fi

clean: force
	$(RM) *.ind *.log *.xlg test.failed

force:
