# $Id$
#----------------------------------------------------------------------
#
#
# This makefile is intended to be used only in a <platform>-directory.
#
# The following targets are supported:
#
#   compile    :  compiles the xindy-system
#   xindy.mem  :  creates the dumped version of xindy
#   xindy      :  created the defaults startup-script
#   clean      :  cleans unnecessary stuff
#   testsuite  :  executes a testsuite
#

BINDIR = /usr/local/lib/xindy
LIBDIR = /usr/local/lib/xindy/modules

SRC_DIR   = ../../src
FAS       = base.fas locref.fas idxstyle.fas index.fas markup.fas
DEFAULTS  = defaults.xdy
MEMFILE   = xindy.mem
XINDY_IN  = ../../bin/xindy.in
XINDY_RUN = ./xindy.run -q -M ./base.mem
TEST_DIR  = ../../tests

all: compile xindy.mem

base.fas: $(SRC_DIR)/base.lsp
	$(XINDY_RUN) -c $(SRC_DIR)/base.lsp -o base.fas
locref.fas: $(SRC_DIR)/locref.lsp
	$(XINDY_RUN) -c $(SRC_DIR)/locref.lsp -o locref.fas
idxstyle.fas: $(SRC_DIR)/idxstyle.lsp
	$(XINDY_RUN) -c $(SRC_DIR)/idxstyle.lsp -o idxstyle.fas
index.fas: $(SRC_DIR)/index.lsp
	$(XINDY_RUN) -c $(SRC_DIR)/index.lsp -o index.fas
markup.fas: $(SRC_DIR)/markup.lsp
	$(XINDY_RUN) -c $(SRC_DIR)/markup.lsp -o markup.fas

compile: $(FAS)

xindy.mem: $(DEFAULTS) compile
	$(RM) $(MEMFILE)
	$(XINDY_RUN) -x '(load "dump-xindy.xdy")'

gzipped: xindy.mem
	gzip xindy.mem
	mv xindy.mem.gz xindy.mem

$(DEFAULTS): PLATFORM force
	@$(RM) $(DEFAULTS)
	@echo "Creating file $(DEFAULTS)..."
	@echo "(setq *load-paths* (list "     > $(DEFAULTS)
	@echo "  (pathname \".\")"           >> $(DEFAULTS)
	@echo "  (pathname \"$(LIBDIR)\")"   >> $(DEFAULTS)
	@echo "))"                           >> $(DEFAULTS)
	@echo "(setq xindy:*xindy-platform*" >> $(DEFAULTS)
	@echo " \"`cat PLATFORM`\" )"        >> $(DEFAULTS)
	@echo "Finished $(DEFAULTS)."

xindy: force
	-sed -e "s|@XINDY_BINDIR@|$(BINDIR)|" \
	     -e "s|@XINDY_LIBDIR@|$(LIBDIR)|" \
	     < $(XINDY_IN) > xindy
	-chmod a+x xindy

testsuite: PLATFORM
	@ (XINDY_PLATFORM=`cat PLATFORM`; export XINDY_PLATFORM; \
	   cd $(TEST_DIR); make testsuite)

PLATFORM:
	@! if [ ! -f PLATFORM ] ; then \
		echo "Missing PLATFORM file ! (aborting)" 1>&2 ;\
	   fi

clean: force
	$(RM) *.fas *.lib
	$(RM) $(DEFAULTS) $(MEMFILE)

force:

