;; $Id$
;;
;; Module for the ordrules-library
;;

(in-package "ORDRULES")

(export '(add-keyword-sort-rule add-keyword-merge-rule
	  gen-keyword-sortkey   gen-keyword-mergekey))

(use-package "FFI")


; Common OS definitions:
(def-c-type size_t uint)

(def-c-var *string-buffer*
    (:name "ordrules_string_buffer")
    (:type (c-array char 1024))
    (:alloc :NONE))

(def-c-var *string-buffer-used-bytes*
    (:name "ordrules_string_buffer_used_bytes")
    (:type int)
    (:alloc :NONE))

(def-c-var *message-logging*
    (:name "ordrules_msg_logging")
    (:type int)
    (:alloc :NONE))

(def-c-var *message-buffer*
    (:name "ordrules_msg_buffer")
    (:type c-string)
    (:alloc :NONE))

(def-c-var *message-buffer-ptr*
    (:name "ordrules_msg_buffer_ptr")
    (:type int)
    (:alloc :NONE))

(def-c-call-out add-keyword-sort-rule
    (:name "add_sort_rule")
    (:arguments (left c-string)
		(right c-string)
		(isreject int)
		(ruletype int))
    (:return-type int))

(def-c-call-out add-keyword-merge-rule
    (:name "add_merge_rule")
    (:arguments (left c-string)
		(right c-string)
		(isreject int)
		(ruletype int))
    (:return-type int))

(def-c-call-out gen-keyword-sortkey
    (:name "gen_sortkey")
    (:arguments (key c-string))
    (:return-type c-string :malloc-free))

(def-c-call-out gen-keyword-mergekey
    (:name "gen_mergekey")
    (:arguments (key c-string))
    (:return-type c-string :malloc-free))

#|

  $Log$
  Revision 1.3  1997/01/17 16:43:38  kehr
  Several changes for new version 1.1.

  Revision 1.2  1996/04/30  15:56:38  kehr
  Renamed some of the functions to avoid conflicts with other functions
  in other packages (only for the sake of convenience).

  Revision 1.1  1996/03/27  20:29:07  kehr
  It works. Today I had my first success in getting the FFI running with
  the ordrules-library. The interface is defined in `ordrulei.lsp' and
  allows direct access to the functions in `ordrules.c'.

|#
