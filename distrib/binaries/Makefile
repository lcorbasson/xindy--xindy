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
#   gzipped    :  created a gzipped version of the mem-file
#   clean      :  cleans unnecessary stuff
#   testsuite  :  executes a testsuite
#   tex2xindy  :  compiles the TeX-parser
#

# Do not change the following section!

TOPDIR     = ../..

SRC_DIR    = $(TOPDIR)/src
FAS        = base.fas locref.fas idxstyle.fas index.fas markup.fas
DEFAULTS   = defaults.xdy
MEMFILE    = xindy.mem
XINDY_IN   = $(TOPDIR)/bin/xindy.in
XINDY_RUN  = ./xindy.run -q -M ./base.mem
TEST_DIR   = $(TOPDIR)/tests
TEX2XINDYL = $(TOPDIR)/bin/tex2xindy.l

# End of section

RM 	   = /bin/rm -f
LIBDIR     = /usr/local/lib/xindy/
CFLAGS 	   = -O2
LEX       = lex -t
LEXLIB    = -ll


# Target section

all: xindy compile xindy.mem tex2xindy finish

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

gzipped: force
	@ if gzip -t xindy.mem 2>/dev/null; \
	     then echo "!!! xindy.mem is already gzipped !!!"; exit 1\
	     else make xindy.mem; fi
	gzip xindy.mem
	mv xindy.mem.gz xindy.mem

$(DEFAULTS): PLATFORM force
	@$(RM) $(DEFAULTS)
	@echo "Creating file $(DEFAULTS)..."
	@echo "(setq *load-paths* (list "     > $(DEFAULTS)
	@echo "  (pathname \".\")"           >> $(DEFAULTS)
	@echo "  (pathname \"$(LIBDIR)\")))" >> $(DEFAULTS)
	@echo "(setq xindy:*xindy-platform*" >> $(DEFAULTS)
	@echo " \"`cat PLATFORM`\" )"        >> $(DEFAULTS)
	@echo "Finished $(DEFAULTS)."

xindy: $(XINDY_IN)
	-sed -e "s|@XINDY_LIBDIR@|$(LIBDIR)|" \
	     < $(XINDY_IN) > xindy
	-chmod a+x xindy

testsuite: PLATFORM
	@ (PLATFORM=`cat PLATFORM`; cd $(TEST_DIR); \
	   make XINDY_PLATFORM=$$PLATFORM testsuite)

PLATFORM:
	@! if [ ! -f PLATFORM ] ; then \
		echo "Missing PLATFORM file ! (aborting)" 1>&2 ;\
	   fi

tex2xindy.c: $(TEX2XINDYL)
	$(LEX) $(TEX2XINDYL) > tex2xindy.c

tex2xindy: tex2xindy.c
	$(CC) $(CFLAGS) tex2xindy.c -o tex2xindy $(LEXLIB)

clean: force
	$(RM) *.fas *.lib
	$(RM) $(DEFAULTS) $(MEMFILE)
	$(RM) xindy
	$(RM) tex2xindy tex2xindy.c

finish: force
	@echo ""
	@echo "Compilation finished!"
	@echo ""
	@echo "You can run the testsuite by typing \`make testsuite'."
	@echo ""

force:

