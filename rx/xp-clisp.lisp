;; $Id$
;;------------------------------------------------------------

;;;
;;; Integrate XP Pretty Printer into CLISP
;;;
;;; (history at end)


(let ((*load-paths* (cons '#"./ordrules/" *load-paths*)))
  (compile-file "xp-code.lisp")
  (load "xp-code"))

(in-package "XP")

(defvar *xp-shadowing-symbols*
  '(write print prin1 princ pprint format write-to-string princ-to-string
    prin1-to-string write-line write-string write-char terpri fresh-line
    defstruct finish-output force-output clear-output
    formatter copy-pprint-dispatch pprint-dispatch
    set-pprint-dispatch pprint-fill pprint-linear pprint-tabular
    pprint-logical-block pprint-pop pprint-exit-if-list-exhausted
    pprint-newline pprint-indent pprint-tab
    *print-pprint-dispatch* *print-right-margin* *default-right-margin*
    *print-miser-width* *print-lines* *print-shared*
    *last-abbreviated-printing*)
  "Symbols which will be shadowing imported into package LISP.")

(shadowing-import *xp-shadowing-symbols* "COMMON-LISP")
(shadowing-import *xp-shadowing-symbols* "LISP")
(export *xp-shadowing-symbols* "COMMON-LISP")
(export *xp-shadowing-symbols* "LISP")


;;;======================================================================
;;
;; $Log$
;; Revision 1.1  2005/05/02 21:39:53  jschrod
;;     xindy run time engine 3.0; as used for CLISP 2.33.2.
;;
;;
;; PRE-CVS VERSION HISTORY
;;
;; 28 Jul 95 js  Must import & export in package COMMON-LISP, too.
;; 		 This must happen before it's imported into package LISP.
;; 14 Nov 94 gh  Initial revision
