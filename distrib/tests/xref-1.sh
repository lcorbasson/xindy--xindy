#!/bin/sh
#
# checks if the outfile matches the comparison file and checks if
# exactly three errors were reported.
#

cmp -s xref-1.out xref-1.cmp && [ 3 = `egrep "^ERROR:" xref-1.log | wc -l` ]
