# $Id$
#----------------------------------------------------------------------
#
# The following targets are supported:
#
#  testsuite   : runs the complete testsuite
#

RM = /bin/rm -f

XINDY_PLATFORM = test-arch
ALLTESTS       = startup mappings
TESTS 	       = mappings
XINDY_DIR      = ../binaries/$(XINDY_PLATFORM)

testsuite: banner tests compare

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
             $(XINDY_DIR)/xindy -o $$tst.out $$tst.xdy $$tst.raw ;\
	  done

compare: force
	@- $(RM) test.failed
	@ echo ;\
	  echo "--------------";\
	  echo "Checking tests";\
	  echo "--------------";\
	  echo
	@ for tst in $(TESTS); do \
             cmp -s $$tst.out $$tst.cmp || \
		(echo "Test \"$$tst\" failed!" ; touch test.failed) \
	  done
	@ if [ ! -f test.failed ] ; then echo "All tests passed !"; echo; fi

clean: force
	$(RM) *.out test.failed

force:
