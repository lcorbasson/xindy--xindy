#ifndef _CLISP_H
#define _CLISP_H

#define UNIXCONF
#ifndef _ALL_SOURCE
#endif
#ifndef _POSIX_SOURCE
#endif
#ifndef _POSIX_SOURCE
#endif
#ifndef _POSIX_1_SOURCE
#endif
#define inline __inline
#define __nowarn__ 
#define return_void
#define HAVE_LONGLONG 1
#define STDC_HEADERS 1
#define HAVE_STDLIB_H 1
#define HAVE_OFFSETOF 1
#define HAVE_LOCALE_H 1
#define HAVE_UNISTD_H 1
#define DIRENT 1   /* use <dirent.h> */
#define DIRENT_WITHOUT_NAMLEN 1
#define HAVE_SYS_UTSNAME_H 1
#define HAVE_NETDB_H 1
#define HAVE_TERMIOS_H 1
#define HAVE_TCGETATTR 1
#define HAVE_TCSAFLUSH 1
#define HAVE_TERMIO_H 1
#define HAVE_SYS_TERMIO_H 1
#define HAVE_SGTTY_H 1
#define HAVE_X11 1
#ifndef size_t
#endif
#ifndef pid_t
#endif
#ifndef uid_t
#endif
#ifndef off_t
#endif
#define CADDR_T caddr_t
#define CLOCK_T clock_t
#define TM_IN_SYS_TIME 1
#define RETSTRLENTYPE size_t
#define STRLEN_CONST const
#define HAVE_MEMSET 1
#define HAVE_MEMMOVE 1
#define RETMALLOCTYPE void*
#define MALLOC_SIZE_T unsigned int
#define RETFREETYPE void
#define HAVE_ALLOCA_H 1
#define HAVE__JMP 1
#define LONGJMP_RETURNS 1
#define RETSIGTYPE void
#define SIGNAL_NEED_REINSTALL 1
#define SIGNALBLOCK_SYSV 1
#define SIGNALBLOCK_POSIX 1
#define SIGNALBLOCK_BSD 1
#define SIGPROCMASK_CONST const
#define HAVE_SIGACTION 1
#define RETABORTTYPE void
#define ABORT_VOLATILE 
#define SYS_ERRLIST_CONST 
#define GETENV_CONST const
#define SETENV_CONST 
#define HAVE_PUTENV 1
#define PUTENV_CONST 
#define SETLOCALE_CONST const
#define vfork fork
#define RETVFORKTYPE pid_t
#define HAVE_SETSID 1
#define HAVE_SETPGID 1
#define EXECV_CONST const
#define EXECV1_CONST 
#define EXECV2_CONST const
#define EXECL_DOTS 1
#define EXECL_CONST const
#define HAVE_WAITPID 1
#define PID_T pid_t
#define HAVE_SYS_RESOURCE_H 1
#define HAVE_GETRUSAGE 1
#define HAVE_SYS_TIMES_H 1
#define HAVE_GETWD 1
#define HAVE_GETCWD 1
#define CHDIR_CONST const
#define MKDIR_CONST const
#define MODE_T mode_t
#define RMDIR_CONST const
#define STAT_CONST const
#define HAVE_LSTAT 1
#define LSTAT_CONST const
#define HAVE_READLINK 1
#define READLINK_CONST const
#define READLINK_BUF_T void*
#define READLINK_SIZE_T size_t
#define ELOOP_VALUE ELOOP
#define OPENDIR_CONST const
#define OPEN_CONST const
#define OPEN_DOTS 1
#define RETRWTYPE int
#define RW_BUF_T void*
#define RW_SIZE_T size_t
#define WRITE_CONST const
#define HAVE_RENAME 1
#define RENAME_CONST const
#define UNLINK_CONST const
#define HAVE_FSYNC 1
#define IOCTL_REQUEST_T int
#define IOCTL_DOTS 1
#define HAVE_FIONREAD 1
#define HAVE_RELIABLE_FIONREAD 1
#define FCNTL_DOTS 1
#define HAVE_SELECT 1
#define HAVE_SYS_SELECT_H 1
#define SELECT_WIDTH_T int
#define SELECT_SET_T fd_set
#define SELECT_CONST 
#define HAVE_UALARM 1
#define HAVE_SETITIMER 1
#define SETITIMER_CONST 
#define LOCALTIME_CONST const
#define HAVE_GETTIMEOFDAY 1
#define GETTIMEOFDAY_TIMEZONE_T void *
#define GETPWNAM_CONST const
#define GETPWUID_UID_T uid_t
#define HAVE_GETHOSTNAME 1
#define GETHOSTNAME_SIZE_T int
#define HAVE_GETHOSTBYNAME 1
#define GETHOSTBYNAME_CONST const
#define CONNECT_NAME_T void*
#define CONNECT_CONST const
#define HAVE_SYS_UN_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_ARPA_INET_H 1
#define RET_INET_ADDR_TYPE unsigned long
#define INET_ADDR_SUFFIX 
#define INET_ADDR_CONST const
#define HAVE_NETINET_TCP_H 1
#define CODE_ADDRESS_RANGE 0x00000000UL
#define MALLOC_ADDRESS_RANGE 0x10000000UL
#define SHLIB_ADDRESS_RANGE UL
#define HAVE_GETPAGESIZE 1
#define RETGETPAGESIZETYPE int
#define HAVE_MMAP 1
#define RETMMAPTYPE void*
#define MMAP_ADDR_T void*
#define MMAP_SIZE_T size_t
#define HAVE_MMAP_DEVZERO 1
#define HAVE_MUNMAP 1
#define HAVE_MPROTECT 1
#define HAVE_WORKING_MPROTECT 1
#define MPROTECT_CONST 
#define SHMGET_SIZE_T int
#define RETSHMATTYPE void*
#define SHMAT_CONST 
#define SHMCTL_DOTS 1
#define HAVE_GETRLIMIT 1
#define HAVE_SETRLIMIT 1
#define VALID_FILENAME_CHAR (ch >= 1) && (ch != 47) /* 8-bit */
#ifndef __CHAR_UNSIGNED__
#define __CHAR_UNSIGNED__ 1
#endif
#ifdef __cplusplus
#define BEGIN_DECLS  extern "C" {
#define END_DECLS    }
#else
#define BEGIN_DECLS
#define END_DECLS
#endif
#define CONCAT_(xxx,yyy)  xxx##yyy
#define CONCAT3_(aaa,bbb,ccc)  aaa##bbb##ccc
#define CONCAT(xxx,yyy)  CONCAT_(xxx,yyy)
#define CONCAT3(aaa,bbb,ccc)  CONCAT3_(aaa,bbb,ccc)
#define STRING(token) #token
#define STRINGIFY(token) STRING(token)
#define global
#define nonreturning
#define maygc
#define _ARGS(x) x
#define nonreturning_function(storclass,funname,arguments)  \
  storclass void funname arguments
#define var
#define reg1  register
#define reg2  register
#define reg3  register
#define reg4  register
#define reg5  register
#define reg6  register
#define reg7  register
#define reg8  register
#define reg9  register
#define reg10  register
typedef signed char  CLISP_BYTE;
typedef unsigned char  CLISP_UBYTE;
typedef short          CLISP_WORD;
typedef unsigned short CLISP_UWORD;
typedef long           CLISP_LONG;
typedef unsigned long  CLISP_ULONG;
typedef long long           CLISP_LONGLONG;
typedef unsigned long long  CLISP_ULONGLONG;
#define TRUE   1
#define FALSE  0
typedef unsigned int  boolean;
#undef NULL
#define NULL  ((void*) 0L)
#define unspecified 1
#define pointerplus(pointer,offset)  ((void*)((CLISP_ULONG)(pointer)+(offset)))
#define bit(n)  (1L<<(n))
#define bit_test(x,n)  ((x) & bit(n))
typedef CLISP_UBYTE   uint1;
typedef CLISP_BYTE    sint1;
typedef CLISP_UBYTE   uint2;
typedef CLISP_BYTE    sint2;
typedef CLISP_UBYTE   uint3;
typedef CLISP_BYTE    sint3;
typedef CLISP_UBYTE   uint4;
typedef CLISP_BYTE    sint4;
typedef CLISP_UBYTE   uint5;
typedef CLISP_BYTE    sint5;
typedef CLISP_UBYTE   uint6;
typedef CLISP_BYTE    sint6;
typedef CLISP_UBYTE   uint7;
typedef CLISP_BYTE    sint7;
typedef CLISP_UBYTE   uint8;
typedef CLISP_BYTE    sint8;
typedef CLISP_UWORD   uint9;
typedef CLISP_WORD    sint9;
typedef CLISP_UWORD   uint10;
typedef CLISP_WORD    sint10;
typedef CLISP_UWORD   uint11;
typedef CLISP_WORD    sint11;
typedef CLISP_UWORD   uint12;
typedef CLISP_WORD    sint12;
typedef CLISP_UWORD   uint13;
typedef CLISP_WORD    sint13;
typedef CLISP_UWORD   uint14;
typedef CLISP_WORD    sint14;
typedef CLISP_UWORD   uint15;
typedef CLISP_WORD    sint15;
typedef CLISP_UWORD   uint16;
typedef CLISP_WORD    sint16;
typedef CLISP_ULONG   uint17;
typedef CLISP_LONG    sint17;
typedef CLISP_ULONG   uint18;
typedef CLISP_LONG    sint18;
typedef CLISP_ULONG   uint19;
typedef CLISP_LONG    sint19;
typedef CLISP_ULONG   uint20;
typedef CLISP_LONG    sint20;
typedef CLISP_ULONG   uint21;
typedef CLISP_LONG    sint21;
typedef CLISP_ULONG   uint22;
typedef CLISP_LONG    sint22;
typedef CLISP_ULONG   uint23;
typedef CLISP_LONG    sint23;
typedef CLISP_ULONG   uint24;
typedef CLISP_LONG    sint24;
typedef CLISP_ULONG   uint25;
typedef CLISP_LONG    sint25;
typedef CLISP_ULONG   uint26;
typedef CLISP_LONG    sint26;
typedef CLISP_ULONG   uint27;
typedef CLISP_LONG    sint27;
typedef CLISP_ULONG   uint28;
typedef CLISP_LONG    sint28;
typedef CLISP_ULONG   uint29;
typedef CLISP_LONG    sint29;
typedef CLISP_ULONG   uint30;
typedef CLISP_LONG    sint30;
typedef CLISP_ULONG   uint31;
typedef CLISP_LONG    sint31;
typedef CLISP_ULONG   uint32;
typedef CLISP_LONG    sint32;
typedef CLISP_ULONGLONG  uint33;
typedef CLISP_LONGLONG   sint33;
typedef CLISP_ULONGLONG  uint48;
typedef CLISP_LONGLONG   sint48;
typedef CLISP_ULONGLONG  uint64;
typedef CLISP_LONGLONG   sint64;
typedef uint8 uintB;
typedef uint16 uintW;
typedef sint32 sintL;
typedef uint32 uintL;
typedef sint32 sintP;
typedef uint32 uintWL;
typedef uint32 uintBWL;
#define uintC uintWL
typedef uint32 uintD;
typedef  void *  object;
typedef  uintL  oint;
#define as_oint(expr)  (oint)(expr)
#define as_object(o)  (object)(o)
typedef uint8 tint;
typedef uint24 aint;
#define objectplus(obj,offset)  ((object)pointerplus(obj,offset))
#define wbit_test  bit_test
#define typecode(expr)  ((tint)(as_oint(expr) >> 24UL) & 0xEFUL)
#define type_untype_object(type,address)  as_object(pointerplus((address),(oint)(tint)(type)<<24))
#define type_data_object(type,data)  (as_object(((oint)(tint)(type) << 24) + (oint)(aint)(data)))
#define upointer  untype
#define type_pointer_object(type,address)  type_untype_object(type,address)
#define type_constpointer_object(type,address)  type_pointer_object(type,address)
#define type_zero_oint(type)  ((oint)(tint)(type) << 24)
#define VAROBJECT_HEADER  object GCself;
typedef struct { VAROBJECT_HEADER object symvalue; object symfunction; object proplist; object pname; object homepackage; } symbol_;
typedef uint16 cint;
#define int_char(int_from_int_char)  type_data_object(13,(aint)(cint)(int_from_int_char))
#define char_int(char_from_char_int)  ((cint)as_oint(char_from_char_int))
#define code_char(code_from_code_char)  int_char((cint)(code_from_code_char))
#define char_code(char_from_char_code)  ((uintB)(char_int(char_from_char_code)))
#define fixnum(x)  type_data_object(32,x)
#define posfixnum_to_L(obj)  ((uintL)((as_oint(obj)&0xFFFFFFUL)>>0UL))
#define fixnum_to_L(obj)  (((sintL)as_oint(obj) << 7) >> 7)
typedef struct { VAROBJECT_HEADER uintC length; uintD data[unspecified]; } bignum_;
typedef bignum_ *  Bignum;
typedef uint32 ffloat;
typedef union { ffloat explicit_; } ffloatjanus;
typedef struct {uint32 semhi,mlo;} dfloat;
typedef union { dfloat explicit_; } dfloatjanus;
typedef void Values;
typedef Values (*lisp_function)();
typedef struct { lisp_function function; object name; object keywords; uintW argtype; uintW req_anz; uintW opt_anz; uintB rest_flag; uintB key_flag; uintW key_anz; } subr_;
typedef enum { subr_norest, subr_rest } subr_rest_;
typedef enum { subr_nokey, subr_key, subr_key_allow } subr_key_;
#define pointable(obj)  ((void*)as_oint(obj))
#define TheBignum(obj)  ((Bignum)(((void*)(aint)as_oint(obj))))
#define eq(obj1,obj2)  ((obj1) == (obj2))
#define nullp(obj)  (eq(obj,NIL))
#define posfixnump(obj)  (typecode(obj) == 32)
#define positivep(obj)  (!wbit_test(as_oint(obj),24))
#define uint8_p(obj)  ((as_oint(obj) & ~0xFFUL) == 0x20000000UL)
#define sint8_p(obj)  (((as_oint(obj) ^ (positivep(obj) ? 0 : 0x1FFFFFFUL)) & ~0x7FUL) == 0x20000000UL)
#define uint16_p(obj)  ((as_oint(obj) & ~0xFFFFUL) == 0x20000000UL)
#define sint16_p(obj)  (((as_oint(obj) ^ (positivep(obj) ? 0 : 0x1FFFFFFUL)) & ~0x7FFFUL) == 0x20000000UL)
#define uint32_p(obj)  ((typecode(obj)==32) || ((typecode(obj)==36) && (TheBignum(obj)->length <= 2UL) && ((TheBignum(obj)->length < 2UL) || (TheBignum(obj)->data[0] < (uintD)bit(0UL)) )))
#define sint32_p(obj)  (((typecode(obj) & ~1) == 32) || (((typecode(obj) & ~1) == 36) && (TheBignum(obj)->length <= 1UL) && ((TheBignum(obj)->length < 1UL) || ((TheBignum(obj)->data[0] ^ (positivep(obj) ? (uintD)0 : ~(uintD)0)) < (uintD)bit(31UL)) )))
#define uint64_p(obj)  ((typecode(obj)==32) || ((typecode(obj)==36) && (TheBignum(obj)->length <= 3UL) && ((TheBignum(obj)->length < 3UL) || (TheBignum(obj)->data[0] < (uintD)bit(0UL)) )))
#define sint64_p(obj)  (((typecode(obj) & ~1) == 32) || (((typecode(obj) & ~1) == 36) && (TheBignum(obj)->length <= 2UL) && ((TheBignum(obj)->length < 2UL) || ((TheBignum(obj)->data[0] ^ (positivep(obj) ? (uintD)0 : ~(uintD)0)) < (uintD)bit(31UL)) )))
extern object* STACK;
#define begin_call()
#define end_call()
#define begin_callback()  end_call()
#define end_callback()  begin_call()
extern object asciz_to_string _ARGS((const char * asciz));
extern struct subr_tab_ {
  subr_ D_funtabref;
  subr_ D_subr_info;
  subr_ D_find_subr;
  subr_ D_vector;
  subr_ D_aref;
  subr_ D_store;
  subr_ D_svref;
  subr_ D_svstore;
  subr_ D_psvstore;
  subr_ D_row_major_aref;
  subr_ D_row_major_store;
  subr_ D_array_element_type;
  subr_ D_array_rank;
  subr_ D_array_dimension;
  subr_ D_array_dimensions;
  subr_ D_array_total_size;
  subr_ D_array_in_bounds_p;
  subr_ D_array_row_major_index;
  subr_ D_adjustable_array_p;
  subr_ D_bit;
  subr_ D_sbit;
  subr_ D_bit_and;
  subr_ D_bit_ior;
  subr_ D_bit_xor;
  subr_ D_bit_eqv;
  subr_ D_bit_nand;
  subr_ D_bit_nor;
  subr_ D_bit_andc1;
  subr_ D_bit_andc2;
  subr_ D_bit_orc1;
  subr_ D_bit_orc2;
  subr_ D_bit_not;
  subr_ D_array_has_fill_pointer_p;
  subr_ D_fill_pointer;
  subr_ D_set_fill_pointer;
  subr_ D_vector_push;
  subr_ D_vector_pop;
  subr_ D_vector_push_extend;
  subr_ D_initial_contents_aux;
  subr_ D_make_array;
  subr_ D_adjust_array;
  subr_ D_vector_init;
  subr_ D_vector_upd;
  subr_ D_vector_endtest;
  subr_ D_vector_fe_init;
  subr_ D_vector_fe_upd;
  subr_ D_vector_fe_endtest;
  subr_ D_vector_length;
  subr_ D_vector_init_start;
  subr_ D_vector_fe_init_end;
  subr_ D_make_bit_vector;
  subr_ D_standard_char_p;
  subr_ D_graphic_char_p;
  subr_ D_string_char_p;
  subr_ D_alpha_char_p;
  subr_ D_upper_case_p;
  subr_ D_lower_case_p;
  subr_ D_both_case_p;
  subr_ D_digit_char_p;
  subr_ D_alphanumericp;
  subr_ D_char_gleich;
  subr_ D_char_ungleich;
  subr_ D_char_kleiner;
  subr_ D_char_groesser;
  subr_ D_char_klgleich;
  subr_ D_char_grgleich;
  subr_ D_char_equal;
  subr_ D_char_not_equal;
  subr_ D_char_lessp;
  subr_ D_char_greaterp;
  subr_ D_char_not_greaterp;
  subr_ D_char_not_lessp;
  subr_ D_char_code;
  subr_ D_char_bits;
  subr_ D_char_font;
  subr_ D_code_char;
  subr_ D_make_char;
  subr_ D_character;
  subr_ D_char_upcase;
  subr_ D_char_downcase;
  subr_ D_digit_char;
  subr_ D_char_int;
  subr_ D_int_char;
  subr_ D_char_name;
  subr_ D_char_bit;
  subr_ D_set_char_bit;
  subr_ D_char;
  subr_ D_schar;
  subr_ D_store_char;
  subr_ D_store_schar;
  subr_ D_string_gleich;
  subr_ D_string_ungleich;
  subr_ D_string_kleiner;
  subr_ D_string_groesser;
  subr_ D_string_klgleich;
  subr_ D_string_grgleich;
  subr_ D_string_equal;
  subr_ D_string_not_equal;
  subr_ D_string_lessp;
  subr_ D_string_greaterp;
  subr_ D_string_not_greaterp;
  subr_ D_string_not_lessp;
  subr_ D_search_string_gleich;
  subr_ D_search_string_equal;
  subr_ D_make_string;
  subr_ D_string_both_trim;
  subr_ D_nstring_upcase;
  subr_ D_string_upcase;
  subr_ D_nstring_downcase;
  subr_ D_string_downcase;
  subr_ D_nstring_capitalize;
  subr_ D_string_capitalize;
  subr_ D_string;
  subr_ D_name_char;
  subr_ D_substring;
  subr_ D_string_concat;
  subr_ D_exit;
  subr_ D_psymbol_value;
  subr_ D_symbol_value;
  subr_ D_symbol_function;
  subr_ D_fdefinition;
  subr_ D_boundp;
  subr_ D_fboundp;
  subr_ D_special_form_p;
  subr_ D_set;
  subr_ D_makunbound;
  subr_ D_fmakunbound;
  subr_ D_apply;
  subr_ D_pfuncall;
  subr_ D_funcall;
  subr_ D_mapcar;
  subr_ D_maplist;
  subr_ D_mapc;
  subr_ D_mapl;
  subr_ D_mapcan;
  subr_ D_mapcon;
  subr_ D_values;
  subr_ D_values_list;
  subr_ D_driver;
  subr_ D_unwind_to_driver;
  subr_ D_macro_function;
  subr_ D_macroexpand;
  subr_ D_macroexpand_1;
  subr_ D_proclaim;
  subr_ D_eval;
  subr_ D_evalhook;
  subr_ D_applyhook;
  subr_ D_constantp;
  subr_ D_function_name_p;
  subr_ D_parse_body;
  subr_ D_keyword_test;
  subr_ D_read_form;
  subr_ D_read_eval_print;
  subr_ D_load;
  subr_ D_frame_up_1;
  subr_ D_frame_up;
  subr_ D_frame_down_1;
  subr_ D_frame_down;
  subr_ D_the_frame;
  subr_ D_same_env_as;
  subr_ D_eval_at;
  subr_ D_eval_frame_p;
  subr_ D_driver_frame_p;
  subr_ D_trap_eval_frame;
  subr_ D_redo_eval_frame;
  subr_ D_return_from_eval_frame;
  subr_ D_describe_frame;
  subr_ D_show_stack;
  subr_ D_debug;
  subr_ D_room;
  subr_ D_gc;
  subr_ D_error;
  subr_ D_defclcs;
  subr_ D_error_of_type;
  subr_ D_invoke_debugger;
  subr_ D_clcs_signal;
  subr_ D_make_hash_table;
  subr_ D_gethash;
  subr_ D_puthash;
  subr_ D_remhash;
  subr_ D_maphash;
  subr_ D_clrhash;
  subr_ D_hash_table_count;
  subr_ D_hash_table_rehash_size;
  subr_ D_hash_table_rehash_threshold;
  subr_ D_hash_table_size;
  subr_ D_hash_table_test;
  subr_ D_hash_table_iterator;
  subr_ D_hash_table_iterate;
  subr_ D_class_gethash;
  subr_ D_class_tuple_gethash;
  subr_ D_sxhash;
  subr_ D_copy_readtable;
  subr_ D_set_syntax_from_char;
  subr_ D_set_macro_character;
  subr_ D_get_macro_character;
  subr_ D_make_dispatch_macro_character;
  subr_ D_set_dispatch_macro_character;
  subr_ D_get_dispatch_macro_character;
  subr_ D_readtable_case;
  subr_ D_set_readtable_case;
  subr_ D_lpar_reader;
  subr_ D_rpar_reader;
  subr_ D_string_reader;
  subr_ D_quote_reader;
  subr_ D_line_comment_reader;
  subr_ D_function_reader;
  subr_ D_comment_reader;
  subr_ D_char_reader;
  subr_ D_binary_reader;
  subr_ D_octal_reader;
  subr_ D_hexadecimal_reader;
  subr_ D_radix_reader;
  subr_ D_complex_reader;
  subr_ D_uninterned_reader;
  subr_ D_bit_vector_reader;
  subr_ D_vector_reader;
  subr_ D_array_reader;
  subr_ D_read_eval_reader;
  subr_ D_load_eval_reader;
  subr_ D_label_definition_reader;
  subr_ D_label_reference_reader;
  subr_ D_not_readable_reader;
  subr_ D_syntax_error_reader;
  subr_ D_feature_reader;
  subr_ D_not_feature_reader;
  subr_ D_structure_reader;
  subr_ D_closure_reader;
  subr_ D_pathname_reader;
  subr_ D_read;
  subr_ D_read_preserving_whitespace;
  subr_ D_read_delimited_list;
  subr_ D_read_line;
  subr_ D_read_char;
  subr_ D_unread_char;
  subr_ D_peek_char;
  subr_ D_listen;
  subr_ D_read_char_no_hang;
  subr_ D_clear_input;
  subr_ D_read_from_string;
  subr_ D_parse_integer;
  subr_ D_write;
  subr_ D_prin1;
  subr_ D_print;
  subr_ D_pprint;
  subr_ D_princ;
  subr_ D_write_to_string;
  subr_ D_prin1_to_string;
  subr_ D_princ_to_string;
  subr_ D_write_char;
  subr_ D_write_string;
  subr_ D_write_line;
  subr_ D_terpri;
  subr_ D_fresh_line;
  subr_ D_finish_output;
  subr_ D_force_output;
  subr_ D_clear_output;
  subr_ D_write_unreadable;
  subr_ D_line_position;
  subr_ D_car;
  subr_ D_cdr;
  subr_ D_caar;
  subr_ D_cadr;
  subr_ D_cdar;
  subr_ D_cddr;
  subr_ D_caaar;
  subr_ D_caadr;
  subr_ D_cadar;
  subr_ D_caddr;
  subr_ D_cdaar;
  subr_ D_cdadr;
  subr_ D_cddar;
  subr_ D_cdddr;
  subr_ D_caaaar;
  subr_ D_caaadr;
  subr_ D_caadar;
  subr_ D_caaddr;
  subr_ D_cadaar;
  subr_ D_cadadr;
  subr_ D_caddar;
  subr_ D_cadddr;
  subr_ D_cdaaar;
  subr_ D_cdaadr;
  subr_ D_cdadar;
  subr_ D_cdaddr;
  subr_ D_cddaar;
  subr_ D_cddadr;
  subr_ D_cdddar;
  subr_ D_cddddr;
  subr_ D_cons;
  subr_ D_tree_equal;
  subr_ D_endp;
  subr_ D_list_length;
  subr_ D_nth;
  subr_ D_first;
  subr_ D_second;
  subr_ D_third;
  subr_ D_fourth;
  subr_ D_fifth;
  subr_ D_sixth;
  subr_ D_seventh;
  subr_ D_eighth;
  subr_ D_ninth;
  subr_ D_tenth;
  subr_ D_rest;
  subr_ D_nthcdr;
  subr_ D_last;
  subr_ D_list;
  subr_ D_liststern;
  subr_ D_make_list;
  subr_ D_append;
  subr_ D_copy_list;
  subr_ D_copy_alist;
  subr_ D_copy_tree;
  subr_ D_revappend;
  subr_ D_nconc;
  subr_ D_nreconc;
  subr_ D_list_nreverse;
  subr_ D_butlast;
  subr_ D_nbutlast;
  subr_ D_ldiff;
  subr_ D_rplaca;
  subr_ D_prplaca;
  subr_ D_rplacd;
  subr_ D_prplacd;
  subr_ D_subst;
  subr_ D_subst_if;
  subr_ D_subst_if_not;
  subr_ D_nsubst;
  subr_ D_nsubst_if;
  subr_ D_nsubst_if_not;
  subr_ D_sublis;
  subr_ D_nsublis;
  subr_ D_member;
  subr_ D_member_if;
  subr_ D_member_if_not;
  subr_ D_tailp;
  subr_ D_adjoin;
  subr_ D_acons;
  subr_ D_pairlis;
  subr_ D_assoc;
  subr_ D_assoc_if;
  subr_ D_assoc_if_not;
  subr_ D_rassoc;
  subr_ D_rassoc_if;
  subr_ D_rassoc_if_not;
  subr_ D_list_upd;
  subr_ D_list_endtest;
  subr_ D_list_fe_init;
  subr_ D_list_access;
  subr_ D_list_access_set;
  subr_ D_list_llength;
  subr_ D_list_elt;
  subr_ D_list_set_elt;
  subr_ D_list_init_start;
  subr_ D_list_fe_init_end;
  subr_ D_lisp_implementation_type;
  subr_ D_lisp_implementation_version;
  subr_ D_version;
  subr_ D_machinetype;
  subr_ D_machine_version;
  subr_ D_machine_instance;
  subr_ D_get_env;
  subr_ D_software_type;
  subr_ D_software_version;
  subr_ D_language;
  subr_ D_identity;
  subr_ D_address_of;
  subr_ D_code_address_of;
  subr_ D_program_id;
  subr_ D_get_universal_time;
  subr_ D_default_time_zone;
  subr_ D_get_internal_run_time;
  subr_ D_get_internal_real_time;
  subr_ D_sleep;
  subr_ D_time;
  subr_ D_use_package_aux;
  subr_ D_make_symbol;
  subr_ D_find_package;
  subr_ D_pfind_package;
  subr_ D_package_name;
  subr_ D_package_nicknames;
  subr_ D_rename_package;
  subr_ D_package_use_list;
  subr_ D_package_used_by_list;
  subr_ D_package_shadowing_symbols;
  subr_ D_list_all_packages;
  subr_ D_intern;
  subr_ D_find_symbol;
  subr_ D_unintern;
  subr_ D_export;
  subr_ D_unexport;
  subr_ D_import;
  subr_ D_shadowing_import;
  subr_ D_shadow;
  subr_ D_use_package;
  subr_ D_unuse_package;
  subr_ D_make_package;
  subr_ D_pin_package;
  subr_ D_in_package;
  subr_ D_delete_package;
  subr_ D_delete_package_aux;
  subr_ D_find_all_symbols;
  subr_ D_map_symbols;
  subr_ D_map_symbols_aux;
  subr_ D_map_external_symbols;
  subr_ D_map_all_symbols;
  subr_ D_package_iterator;
  subr_ D_package_iterate;
  subr_ D_parse_namestring;
  subr_ D_pathname;
  subr_ D_pathnamehost;
  subr_ D_pathnamedevice;
  subr_ D_pathnamedirectory;
  subr_ D_pathnamename;
  subr_ D_pathnametype;
  subr_ D_pathnameversion;
  subr_ D_logical_pathname;
  subr_ D_translate_logical_pathname;
  subr_ D_file_namestring;
  subr_ D_directory_namestring;
  subr_ D_host_namestring;
  subr_ D_merge_pathnames;
  subr_ D_enough_namestring;
  subr_ D_make_pathname;
  subr_ D_make_logical_pathname;
  subr_ D_user_homedir_pathname;
  subr_ D_wild_pathname_p;
  subr_ D_pathname_match_p;
  subr_ D_translate_pathname;
  subr_ D_namestring;
  subr_ D_truename;
  subr_ D_probe_file;
  subr_ D_delete_file;
  subr_ D_rename_file;
  subr_ D_open;
  subr_ D_directory;
  subr_ D_cd;
  subr_ D_make_dir;
  subr_ D_delete_dir;
  subr_ D_file_write_date;
  subr_ D_file_author;
  subr_ D_execute;
  subr_ D_shell;
  subr_ D_savemem;
  subr_ D_program_name;
  subr_ D_eq;
  subr_ D_eql;
  subr_ D_equal;
  subr_ D_equalp;
  subr_ D_consp;
  subr_ D_atom;
  subr_ D_symbolp;
  subr_ D_stringp;
  subr_ D_numberp;
  subr_ D_compiled_function_p;
  subr_ D_null;
  subr_ D_not;
  subr_ D_closurep;
  subr_ D_listp;
  subr_ D_integerp;
  subr_ D_fixnump;
  subr_ D_rationalp;
  subr_ D_floatp;
  subr_ D_short_float_p;
  subr_ D_single_float_p;
  subr_ D_double_float_p;
  subr_ D_long_float_p;
  subr_ D_realp;
  subr_ D_complexp;
  subr_ D_streamp;
  subr_ D_random_state_p;
  subr_ D_readtablep;
  subr_ D_hash_table_p;
  subr_ D_pathnamep;
  subr_ D_logical_pathname_p;
  subr_ D_characterp;
  subr_ D_functionp;
  subr_ D_generic_function_p;
  subr_ D_packagep;
  subr_ D_arrayp;
  subr_ D_simple_array_p;
  subr_ D_bit_vector_p;
  subr_ D_vectorp;
  subr_ D_simple_vector_p;
  subr_ D_simple_string_p;
  subr_ D_simple_bit_vector_p;
  subr_ D_commonp;
  subr_ D_type_of;
  subr_ D_defclos;
  subr_ D_class_p;
  subr_ D_class_of;
  subr_ D_find_class;
  subr_ D_coerce;
  subr_ D_record_ref;
  subr_ D_record_store;
  subr_ D_record_length;
  subr_ D_structure_ref;
  subr_ D_structure_store;
  subr_ D_make_structure;
  subr_ D_copy_structure;
  subr_ D_structure_type_p;
  subr_ D_closure_name;
  subr_ D_closure_codevec;
  subr_ D_closure_consts;
  subr_ D_make_code_vector;
  subr_ D_make_closure;
  subr_ D_make_load_time_eval;
  subr_ D_make_symbol_macro;
  subr_ D_symbol_macro_p;
  subr_ D_symbol_macro_expand;
  subr_ D_finalize;
  subr_ D_std_instance_p;
  subr_ D_allocate_std_instance;
  subr_ D_slot_value;
  subr_ D_set_slot_value;
  subr_ D_slot_boundp;
  subr_ D_slot_makunbound;
  subr_ D_slot_exists_p;
  subr_ D_shared_initialize;
  subr_ D_reinitialize_instance;
  subr_ D_initialize_instance;
  subr_ D_make_instance;
  subr_ D_sequencep;
  subr_ D_defseq;
  subr_ D_elt;
  subr_ D_setelt;
  subr_ D_subseq;
  subr_ D_copy_seq;
  subr_ D_length;
  subr_ D_reverse;
  subr_ D_nreverse;
  subr_ D_make_sequence;
  subr_ D_concatenate;
  subr_ D_map;
  subr_ D_map_into;
  subr_ D_some;
  subr_ D_every;
  subr_ D_notany;
  subr_ D_notevery;
  subr_ D_reduce;
  subr_ D_fill;
  subr_ D_replace;
  subr_ D_remove;
  subr_ D_remove_if;
  subr_ D_remove_if_not;
  subr_ D_delete;
  subr_ D_delete_if;
  subr_ D_delete_if_not;
  subr_ D_remove_duplicates;
  subr_ D_delete_duplicates;
  subr_ D_substitute;
  subr_ D_substitute_if;
  subr_ D_substitute_if_not;
  subr_ D_nsubstitute;
  subr_ D_nsubstitute_if;
  subr_ D_nsubstitute_if_not;
  subr_ D_find;
  subr_ D_find_if;
  subr_ D_find_if_not;
  subr_ D_position;
  subr_ D_position_if;
  subr_ D_position_if_not;
  subr_ D_count;
  subr_ D_count_if;
  subr_ D_count_if_not;
  subr_ D_mismatch;
  subr_ D_search;
  subr_ D_sort;
  subr_ D_stable_sort;
  subr_ D_merge;
  subr_ D_read_char_sequence;
  subr_ D_write_char_sequence;
  subr_ D_read_byte_sequence;
  subr_ D_write_byte_sequence;
  subr_ D_symbol_stream;
  subr_ D_terminal_raw;
  subr_ D_make_window;
  subr_ D_window_size;
  subr_ D_window_cursor_position;
  subr_ D_set_window_cursor_position;
  subr_ D_clear_window;
  subr_ D_clear_window_to_eot;
  subr_ D_clear_window_to_eol;
  subr_ D_delete_window_line;
  subr_ D_insert_window_line;
  subr_ D_highlight_on;
  subr_ D_highlight_off;
  subr_ D_window_cursor_on;
  subr_ D_window_cursor_off;
  subr_ D_file_stream_p;
  subr_ D_make_synonym_stream;
  subr_ D_synonym_stream_p;
  subr_ D_synonym_stream_symbol;
  subr_ D_make_broadcast_stream;
  subr_ D_broadcast_stream_p;
  subr_ D_broadcast_stream_streams;
  subr_ D_make_concatenated_stream;
  subr_ D_concatenated_stream_p;
  subr_ D_concatenated_stream_streams;
  subr_ D_make_two_way_stream;
  subr_ D_two_way_stream_p;
  subr_ D_two_way_stream_input_stream;
  subr_ D_two_way_stream_output_stream;
  subr_ D_make_echo_stream;
  subr_ D_echo_stream_p;
  subr_ D_echo_stream_input_stream;
  subr_ D_echo_stream_output_stream;
  subr_ D_make_string_input_stream;
  subr_ D_string_input_stream_index;
  subr_ D_make_string_output_stream;
  subr_ D_get_output_stream_string;
  subr_ D_make_string_push_stream;
  subr_ D_string_stream_p;
  subr_ D_make_buffered_input_stream;
  subr_ D_buffered_input_stream_index;
  subr_ D_make_buffered_output_stream;
  subr_ D_make_pipe_input_stream;
  subr_ D_make_pipe_output_stream;
  subr_ D_make_pipe_io_stream;
  subr_ D_make_xsocket_stream;
  subr_ D_read_n_bytes;
  subr_ D_write_n_bytes;
  subr_ D_generic_stream_controller;
  subr_ D_make_generic_stream;
  subr_ D_generic_stream_p;
  subr_ D_socket_server;
  subr_ D_socket_server_close;
  subr_ D_socket_server_port;
  subr_ D_socket_wait;
  subr_ D_socket_accept;
  subr_ D_socket_connect;
  subr_ D_socket_service_port;
  subr_ D_socket_stream_port;
  subr_ D_socket_stream_host;
  subr_ D_socket_stream_peer_host;
  subr_ D_socket_stream_handle;
  subr_ D_open_stream_p;
  subr_ D_input_stream_p;
  subr_ D_output_stream_p;
  subr_ D_stream_element_type;
  subr_ D_interactive_stream_p;
  subr_ D_close;
  subr_ D_read_byte;
  subr_ D_write_byte;
  subr_ D_file_position;
  subr_ D_file_length;
  subr_ D_line_number;
  subr_ D_putd;
  subr_ D_proclaim_constant;
  subr_ D_get;
  subr_ D_getf;
  subr_ D_get_properties;
  subr_ D_putplist;
  subr_ D_put;
  subr_ D_remprop;
  subr_ D_symbol_package;
  subr_ D_symbol_plist;
  subr_ D_symbol_name;
  subr_ D_keywordp;
  subr_ D_special_variable_p;
  subr_ D_gensym;
  subr_ D_decimal_string;
  subr_ D_zerop;
  subr_ D_plusp;
  subr_ D_minusp;
  subr_ D_oddp;
  subr_ D_evenp;
  subr_ D_gleich;
  subr_ D_ungleich;
  subr_ D_kleiner;
  subr_ D_groesser;
  subr_ D_klgleich;
  subr_ D_grgleich;
  subr_ D_max;
  subr_ D_min;
  subr_ D_plus;
  subr_ D_minus;
  subr_ D_mal;
  subr_ D_durch;
  subr_ D_einsplus;
  subr_ D_einsminus;
  subr_ D_conjugate;
  subr_ D_gcd;
  subr_ D_xgcd;
  subr_ D_lcm;
  subr_ D_exp;
  subr_ D_expt;
  subr_ D_log;
  subr_ D_sqrt;
  subr_ D_isqrt;
  subr_ D_abs;
  subr_ D_phase;
  subr_ D_signum;
  subr_ D_sin;
  subr_ D_cos;
  subr_ D_tan;
  subr_ D_cis;
  subr_ D_asin;
  subr_ D_acos;
  subr_ D_atan;
  subr_ D_sinh;
  subr_ D_cosh;
  subr_ D_tanh;
  subr_ D_asinh;
  subr_ D_acosh;
  subr_ D_atanh;
  subr_ D_float;
  subr_ D_rational;
  subr_ D_rationalize;
  subr_ D_numerator;
  subr_ D_denominator;
  subr_ D_floor;
  subr_ D_ceiling;
  subr_ D_truncate;
  subr_ D_round;
  subr_ D_mod;
  subr_ D_rem;
  subr_ D_ffloor;
  subr_ D_fceiling;
  subr_ D_ftruncate;
  subr_ D_fround;
  subr_ D_decode_float;
  subr_ D_scale_float;
  subr_ D_float_radix;
  subr_ D_float_sign;
  subr_ D_float_digits;
  subr_ D_float_precision;
  subr_ D_integer_decode_float;
  subr_ D_complex;
  subr_ D_realpart;
  subr_ D_imagpart;
  subr_ D_logior;
  subr_ D_logxor;
  subr_ D_logand;
  subr_ D_logeqv;
  subr_ D_lognand;
  subr_ D_lognor;
  subr_ D_logandc1;
  subr_ D_logandc2;
  subr_ D_logorc1;
  subr_ D_logorc2;
  subr_ D_boole;
  subr_ D_lognot;
  subr_ D_logtest;
  subr_ D_logbitp;
  subr_ D_ash;
  subr_ D_logcount;
  subr_ D_integer_length;
  subr_ D_byte;
  subr_ D_bytesize;
  subr_ D_byteposition;
  subr_ D_ldb;
  subr_ D_ldb_test;
  subr_ D_mask_field;
  subr_ D_dpb;
  subr_ D_deposit_field;
  subr_ D_random;
  subr_ D_make_random_state;
  subr_ D_fakultaet;
  subr_ D_exquo;
  subr_ D_long_float_digits;
  subr_ D_set_long_float_digits;
  subr_ D_log2;
  subr_ D_log10;
  subr_ D_validp;
  subr_ D_sizeof;
  subr_ D_bitsizeof;
  subr_ D_lookup_foreign_variable;
  subr_ D_foreign_value;
  subr_ D_set_foreign_value;
  subr_ D_foreign_type;
  subr_ D_foreign_size;
  subr_ D_element;
  subr_ D_deref;
  subr_ D_slot;
  subr_ D_cast;
  subr_ D_lookup_foreign_function;
  subr_ D_foreign_call_out;
} subr_tab_data;
extern struct symbol_tab_ {
  symbol_ S_nil;
  symbol_ S_t;
  symbol_ S_eval_when;
  symbol_ S_quote;
  symbol_ S_function;
  symbol_ S_setq;
  symbol_ S_psetq;
  symbol_ S_progn;
  symbol_ S_prog1;
  symbol_ S_prog2;
  symbol_ S_let;
  symbol_ S_letstern;
  symbol_ S_locally;
  symbol_ S_compiler_let;
  symbol_ S_progv;
  symbol_ S_flet;
  symbol_ S_labels;
  symbol_ S_macrolet;
  symbol_ S_symbol_macrolet;
  symbol_ S_if;
  symbol_ S_when;
  symbol_ S_unless;
  symbol_ S_cond;
  symbol_ S_block;
  symbol_ S_return_from;
  symbol_ S_tagbody;
  symbol_ S_go;
  symbol_ S_multiple_value_list;
  symbol_ S_multiple_value_call;
  symbol_ S_multiple_value_prog1;
  symbol_ S_multiple_value_bind;
  symbol_ S_multiple_value_setq;
  symbol_ S_catch;
  symbol_ S_unwind_protect;
  symbol_ S_throw;
  symbol_ S_declare;
  symbol_ S_the;
  symbol_ S_load_time_value;
  symbol_ S_and;
  symbol_ S_or;
  symbol_ S_funtabref;
  symbol_ S_subr_info;
  symbol_ S_find_subr;
  symbol_ S_vector;
  symbol_ S_aref;
  symbol_ S_store;
  symbol_ S_svref;
  symbol_ S_svstore;
  symbol_ S_psvstore;
  symbol_ S_row_major_aref;
  symbol_ S_row_major_store;
  symbol_ S_array_element_type;
  symbol_ S_array_rank;
  symbol_ S_array_dimension;
  symbol_ S_array_dimensions;
  symbol_ S_array_total_size;
  symbol_ S_array_in_bounds_p;
  symbol_ S_array_row_major_index;
  symbol_ S_adjustable_array_p;
  symbol_ S_bit;
  symbol_ S_sbit;
  symbol_ S_bit_and;
  symbol_ S_bit_ior;
  symbol_ S_bit_xor;
  symbol_ S_bit_eqv;
  symbol_ S_bit_nand;
  symbol_ S_bit_nor;
  symbol_ S_bit_andc1;
  symbol_ S_bit_andc2;
  symbol_ S_bit_orc1;
  symbol_ S_bit_orc2;
  symbol_ S_bit_not;
  symbol_ S_array_has_fill_pointer_p;
  symbol_ S_fill_pointer;
  symbol_ S_set_fill_pointer;
  symbol_ S_vector_push;
  symbol_ S_vector_pop;
  symbol_ S_vector_push_extend;
  symbol_ S_initial_contents_aux;
  symbol_ S_make_array;
  symbol_ S_adjust_array;
  symbol_ S_vector_init;
  symbol_ S_vector_upd;
  symbol_ S_vector_endtest;
  symbol_ S_vector_fe_init;
  symbol_ S_vector_fe_upd;
  symbol_ S_vector_fe_endtest;
  symbol_ S_vector_length;
  symbol_ S_vector_init_start;
  symbol_ S_vector_fe_init_end;
  symbol_ S_make_bit_vector;
  symbol_ S_standard_char_p;
  symbol_ S_graphic_char_p;
  symbol_ S_string_char_p;
  symbol_ S_alpha_char_p;
  symbol_ S_upper_case_p;
  symbol_ S_lower_case_p;
  symbol_ S_both_case_p;
  symbol_ S_digit_char_p;
  symbol_ S_alphanumericp;
  symbol_ S_char_gleich;
  symbol_ S_char_ungleich;
  symbol_ S_char_kleiner;
  symbol_ S_char_groesser;
  symbol_ S_char_klgleich;
  symbol_ S_char_grgleich;
  symbol_ S_char_equal;
  symbol_ S_char_not_equal;
  symbol_ S_char_lessp;
  symbol_ S_char_greaterp;
  symbol_ S_char_not_greaterp;
  symbol_ S_char_not_lessp;
  symbol_ S_char_code;
  symbol_ S_char_bits;
  symbol_ S_char_font;
  symbol_ S_code_char;
  symbol_ S_make_char;
  symbol_ S_character;
  symbol_ S_char_upcase;
  symbol_ S_char_downcase;
  symbol_ S_digit_char;
  symbol_ S_char_int;
  symbol_ S_int_char;
  symbol_ S_char_name;
  symbol_ S_char_bit;
  symbol_ S_set_char_bit;
  symbol_ S_char;
  symbol_ S_schar;
  symbol_ S_store_char;
  symbol_ S_store_schar;
  symbol_ S_string_gleich;
  symbol_ S_string_ungleich;
  symbol_ S_string_kleiner;
  symbol_ S_string_groesser;
  symbol_ S_string_klgleich;
  symbol_ S_string_grgleich;
  symbol_ S_string_equal;
  symbol_ S_string_not_equal;
  symbol_ S_string_lessp;
  symbol_ S_string_greaterp;
  symbol_ S_string_not_greaterp;
  symbol_ S_string_not_lessp;
  symbol_ S_search_string_gleich;
  symbol_ S_search_string_equal;
  symbol_ S_make_string;
  symbol_ S_string_both_trim;
  symbol_ S_nstring_upcase;
  symbol_ S_string_upcase;
  symbol_ S_nstring_downcase;
  symbol_ S_string_downcase;
  symbol_ S_nstring_capitalize;
  symbol_ S_string_capitalize;
  symbol_ S_string;
  symbol_ S_name_char;
  symbol_ S_substring;
  symbol_ S_string_concat;
  symbol_ S_exit;
  symbol_ S_psymbol_value;
  symbol_ S_symbol_value;
  symbol_ S_symbol_function;
  symbol_ S_fdefinition;
  symbol_ S_boundp;
  symbol_ S_fboundp;
  symbol_ S_special_form_p;
  symbol_ S_set;
  symbol_ S_makunbound;
  symbol_ S_fmakunbound;
  symbol_ S_apply;
  symbol_ S_pfuncall;
  symbol_ S_funcall;
  symbol_ S_mapcar;
  symbol_ S_maplist;
  symbol_ S_mapc;
  symbol_ S_mapl;
  symbol_ S_mapcan;
  symbol_ S_mapcon;
  symbol_ S_values;
  symbol_ S_values_list;
  symbol_ S_driver;
  symbol_ S_unwind_to_driver;
  symbol_ S_macro_function;
  symbol_ S_macroexpand;
  symbol_ S_macroexpand_1;
  symbol_ S_proclaim;
  symbol_ S_eval;
  symbol_ S_evalhook;
  symbol_ S_applyhook;
  symbol_ S_constantp;
  symbol_ S_function_name_p;
  symbol_ S_parse_body;
  symbol_ S_keyword_test;
  symbol_ S_read_form;
  symbol_ S_read_eval_print;
  symbol_ S_load;
  symbol_ S_frame_up_1;
  symbol_ S_frame_up;
  symbol_ S_frame_down_1;
  symbol_ S_frame_down;
  symbol_ S_the_frame;
  symbol_ S_same_env_as;
  symbol_ S_eval_at;
  symbol_ S_eval_frame_p;
  symbol_ S_driver_frame_p;
  symbol_ S_trap_eval_frame;
  symbol_ S_redo_eval_frame;
  symbol_ S_return_from_eval_frame;
  symbol_ S_describe_frame;
  symbol_ S_show_stack;
  symbol_ S_debug;
  symbol_ S_room;
  symbol_ S_gc;
  symbol_ S_error;
  symbol_ S_defclcs;
  symbol_ S_error_of_type;
  symbol_ S_invoke_debugger;
  symbol_ S_clcs_signal;
  symbol_ S_make_hash_table;
  symbol_ S_gethash;
  symbol_ S_puthash;
  symbol_ S_remhash;
  symbol_ S_maphash;
  symbol_ S_clrhash;
  symbol_ S_hash_table_count;
  symbol_ S_hash_table_rehash_size;
  symbol_ S_hash_table_rehash_threshold;
  symbol_ S_hash_table_size;
  symbol_ S_hash_table_test;
  symbol_ S_hash_table_iterator;
  symbol_ S_hash_table_iterate;
  symbol_ S_class_gethash;
  symbol_ S_class_tuple_gethash;
  symbol_ S_sxhash;
  symbol_ S_copy_readtable;
  symbol_ S_set_syntax_from_char;
  symbol_ S_set_macro_character;
  symbol_ S_get_macro_character;
  symbol_ S_make_dispatch_macro_character;
  symbol_ S_set_dispatch_macro_character;
  symbol_ S_get_dispatch_macro_character;
  symbol_ S_readtable_case;
  symbol_ S_set_readtable_case;
  symbol_ S_lpar_reader;
  symbol_ S_rpar_reader;
  symbol_ S_quote_reader;
  symbol_ S_function_reader;
  symbol_ S_string_reader;
  symbol_ S_line_comment_reader;
  symbol_ S_comment_reader;
  symbol_ S_char_reader;
  symbol_ S_binary_reader;
  symbol_ S_octal_reader;
  symbol_ S_hexadecimal_reader;
  symbol_ S_radix_reader;
  symbol_ S_complex_reader;
  symbol_ S_uninterned_reader;
  symbol_ S_bit_vector_reader;
  symbol_ S_vector_reader;
  symbol_ S_array_reader;
  symbol_ S_read_eval_reader;
  symbol_ S_load_eval_reader;
  symbol_ S_label_definition_reader;
  symbol_ S_label_reference_reader;
  symbol_ S_not_readable_reader;
  symbol_ S_syntax_error_reader;
  symbol_ S_feature_reader;
  symbol_ S_not_feature_reader;
  symbol_ S_structure_reader;
  symbol_ S_closure_reader;
  symbol_ S_pathname_reader;
  symbol_ S_read;
  symbol_ S_read_preserving_whitespace;
  symbol_ S_read_delimited_list;
  symbol_ S_read_line;
  symbol_ S_read_char;
  symbol_ S_unread_char;
  symbol_ S_peek_char;
  symbol_ S_listen;
  symbol_ S_read_char_no_hang;
  symbol_ S_clear_input;
  symbol_ S_read_from_string;
  symbol_ S_parse_integer;
  symbol_ S_write;
  symbol_ S_prin1;
  symbol_ S_print;
  symbol_ S_pprint;
  symbol_ S_princ;
  symbol_ S_write_to_string;
  symbol_ S_prin1_to_string;
  symbol_ S_princ_to_string;
  symbol_ S_write_char;
  symbol_ S_write_string;
  symbol_ S_write_line;
  symbol_ S_terpri;
  symbol_ S_fresh_line;
  symbol_ S_finish_output;
  symbol_ S_force_output;
  symbol_ S_clear_output;
  symbol_ S_write_unreadable;
  symbol_ S_line_position;
  symbol_ S_car;
  symbol_ S_cdr;
  symbol_ S_caar;
  symbol_ S_cadr;
  symbol_ S_cdar;
  symbol_ S_cddr;
  symbol_ S_caaar;
  symbol_ S_caadr;
  symbol_ S_cadar;
  symbol_ S_caddr;
  symbol_ S_cdaar;
  symbol_ S_cdadr;
  symbol_ S_cddar;
  symbol_ S_cdddr;
  symbol_ S_caaaar;
  symbol_ S_caaadr;
  symbol_ S_caadar;
  symbol_ S_caaddr;
  symbol_ S_cadaar;
  symbol_ S_cadadr;
  symbol_ S_caddar;
  symbol_ S_cadddr;
  symbol_ S_cdaaar;
  symbol_ S_cdaadr;
  symbol_ S_cdadar;
  symbol_ S_cdaddr;
  symbol_ S_cddaar;
  symbol_ S_cddadr;
  symbol_ S_cdddar;
  symbol_ S_cddddr;
  symbol_ S_cons;
  symbol_ S_tree_equal;
  symbol_ S_endp;
  symbol_ S_list_length;
  symbol_ S_nth;
  symbol_ S_first;
  symbol_ S_second;
  symbol_ S_third;
  symbol_ S_fourth;
  symbol_ S_fifth;
  symbol_ S_sixth;
  symbol_ S_seventh;
  symbol_ S_eighth;
  symbol_ S_ninth;
  symbol_ S_tenth;
  symbol_ S_rest;
  symbol_ S_nthcdr;
  symbol_ S_last;
  symbol_ S_list;
  symbol_ S_liststern;
  symbol_ S_make_list;
  symbol_ S_append;
  symbol_ S_copy_list;
  symbol_ S_copy_alist;
  symbol_ S_copy_tree;
  symbol_ S_revappend;
  symbol_ S_nconc;
  symbol_ S_nreconc;
  symbol_ S_list_nreverse;
  symbol_ S_butlast;
  symbol_ S_nbutlast;
  symbol_ S_ldiff;
  symbol_ S_rplaca;
  symbol_ S_prplaca;
  symbol_ S_rplacd;
  symbol_ S_prplacd;
  symbol_ S_subst;
  symbol_ S_subst_if;
  symbol_ S_subst_if_not;
  symbol_ S_nsubst;
  symbol_ S_nsubst_if;
  symbol_ S_nsubst_if_not;
  symbol_ S_sublis;
  symbol_ S_nsublis;
  symbol_ S_member;
  symbol_ S_member_if;
  symbol_ S_member_if_not;
  symbol_ S_tailp;
  symbol_ S_adjoin;
  symbol_ S_acons;
  symbol_ S_pairlis;
  symbol_ S_assoc;
  symbol_ S_assoc_if;
  symbol_ S_assoc_if_not;
  symbol_ S_rassoc;
  symbol_ S_rassoc_if;
  symbol_ S_rassoc_if_not;
  symbol_ S_list_upd;
  symbol_ S_list_endtest;
  symbol_ S_list_fe_init;
  symbol_ S_list_access;
  symbol_ S_list_access_set;
  symbol_ S_list_llength;
  symbol_ S_list_elt;
  symbol_ S_list_set_elt;
  symbol_ S_list_init_start;
  symbol_ S_list_fe_init_end;
  symbol_ S_lisp_implementation_type;
  symbol_ S_lisp_implementation_version;
  symbol_ S_lisp_implementation_version_string;
  symbol_ S_software_version_string;
  symbol_ S_version;
  symbol_ S_machinetype;
  symbol_ S_machine_version;
  symbol_ S_machine_instance;
  symbol_ S_get_env;
  symbol_ S_software_type;
  symbol_ S_software_version;
  symbol_ S_language;
  symbol_ S_identity;
  symbol_ S_address_of;
  symbol_ S_code_address_of;
  symbol_ S_program_id;
  symbol_ S_get_universal_time;
  symbol_ S_default_time_zone;
  symbol_ S_get_internal_run_time;
  symbol_ S_get_internal_real_time;
  symbol_ S_sleep;
  symbol_ S_time;
  symbol_ S_use_package_aux;
  symbol_ S_make_symbol;
  symbol_ S_find_package;
  symbol_ S_pfind_package;
  symbol_ S_package_name;
  symbol_ S_package_nicknames;
  symbol_ S_rename_package;
  symbol_ S_package_use_list;
  symbol_ S_package_used_by_list;
  symbol_ S_package_shadowing_symbols;
  symbol_ S_list_all_packages;
  symbol_ S_intern;
  symbol_ S_find_symbol;
  symbol_ S_unintern;
  symbol_ S_export;
  symbol_ S_unexport;
  symbol_ S_import;
  symbol_ S_shadowing_import;
  symbol_ S_shadow;
  symbol_ S_use_package;
  symbol_ S_unuse_package;
  symbol_ S_make_package;
  symbol_ S_pin_package;
  symbol_ S_in_package;
  symbol_ S_delete_package;
  symbol_ S_delete_package_aux;
  symbol_ S_find_all_symbols;
  symbol_ S_map_symbols;
  symbol_ S_map_symbols_aux;
  symbol_ S_map_external_symbols;
  symbol_ S_map_all_symbols;
  symbol_ S_package_iterator;
  symbol_ S_package_iterate;
  symbol_ S_parse_namestring;
  symbol_ S_pathname;
  symbol_ S_pathnamehost;
  symbol_ S_pathnamedevice;
  symbol_ S_pathnamedirectory;
  symbol_ S_pathnamename;
  symbol_ S_pathnametype;
  symbol_ S_pathnameversion;
  symbol_ S_logical_pathname;
  symbol_ S_translate_logical_pathname;
  symbol_ S_file_namestring;
  symbol_ S_directory_namestring;
  symbol_ S_host_namestring;
  symbol_ S_merge_pathnames;
  symbol_ S_enough_namestring;
  symbol_ S_make_pathname;
  symbol_ S_make_logical_pathname;
  symbol_ S_user_homedir_pathname;
  symbol_ S_wild_pathname_p;
  symbol_ S_pathname_match_p;
  symbol_ S_translate_pathname;
  symbol_ S_namestring;
  symbol_ S_truename;
  symbol_ S_probe_file;
  symbol_ S_delete_file;
  symbol_ S_rename_file;
  symbol_ S_open;
  symbol_ S_directory;
  symbol_ S_cd;
  symbol_ S_make_dir;
  symbol_ S_delete_dir;
  symbol_ S_file_write_date;
  symbol_ S_file_author;
  symbol_ S_execute;
  symbol_ S_shell;
  symbol_ S_savemem;
  symbol_ S_program_name;
  symbol_ S_eq;
  symbol_ S_eql;
  symbol_ S_equal;
  symbol_ S_equalp;
  symbol_ S_consp;
  symbol_ S_atom;
  symbol_ S_symbolp;
  symbol_ S_stringp;
  symbol_ S_numberp;
  symbol_ S_compiled_function_p;
  symbol_ S_null;
  symbol_ S_not;
  symbol_ S_closurep;
  symbol_ S_listp;
  symbol_ S_integerp;
  symbol_ S_fixnump;
  symbol_ S_rationalp;
  symbol_ S_floatp;
  symbol_ S_short_float_p;
  symbol_ S_single_float_p;
  symbol_ S_double_float_p;
  symbol_ S_long_float_p;
  symbol_ S_realp;
  symbol_ S_complexp;
  symbol_ S_streamp;
  symbol_ S_random_state_p;
  symbol_ S_readtablep;
  symbol_ S_hash_table_p;
  symbol_ S_pathnamep;
  symbol_ S_logical_pathname_p;
  symbol_ S_characterp;
  symbol_ S_functionp;
  symbol_ S_generic_function_p;
  symbol_ S_packagep;
  symbol_ S_arrayp;
  symbol_ S_simple_array_p;
  symbol_ S_bit_vector_p;
  symbol_ S_vectorp;
  symbol_ S_simple_vector_p;
  symbol_ S_simple_string_p;
  symbol_ S_simple_bit_vector_p;
  symbol_ S_commonp;
  symbol_ S_type_of;
  symbol_ S_defclos;
  symbol_ S_class_p;
  symbol_ S_class_of;
  symbol_ S_find_class;
  symbol_ S_coerce;
  symbol_ S_record_ref;
  symbol_ S_record_store;
  symbol_ S_record_length;
  symbol_ S_structure_ref;
  symbol_ S_structure_store;
  symbol_ S_make_structure;
  symbol_ S_copy_structure;
  symbol_ S_structure_type_p;
  symbol_ S_closure_name;
  symbol_ S_closure_codevec;
  symbol_ S_closure_consts;
  symbol_ S_make_code_vector;
  symbol_ S_make_closure;
  symbol_ S_make_load_time_eval;
  symbol_ S_make_symbol_macro;
  symbol_ S_symbol_macro_p;
  symbol_ S_symbol_macro_expand;
  symbol_ S_finalize;
  symbol_ S_std_instance_p;
  symbol_ S_allocate_std_instance;
  symbol_ S_slot_value;
  symbol_ S_set_slot_value;
  symbol_ S_slot_boundp;
  symbol_ S_slot_makunbound;
  symbol_ S_slot_exists_p;
  symbol_ S_shared_initialize;
  symbol_ S_reinitialize_instance;
  symbol_ S_initialize_instance;
  symbol_ S_make_instance;
  symbol_ S_sequencep;
  symbol_ S_defseq;
  symbol_ S_elt;
  symbol_ S_setelt;
  symbol_ S_subseq;
  symbol_ S_copy_seq;
  symbol_ S_length;
  symbol_ S_reverse;
  symbol_ S_nreverse;
  symbol_ S_make_sequence;
  symbol_ S_concatenate;
  symbol_ S_map;
  symbol_ S_map_into;
  symbol_ S_some;
  symbol_ S_every;
  symbol_ S_notany;
  symbol_ S_notevery;
  symbol_ S_reduce;
  symbol_ S_fill;
  symbol_ S_replace;
  symbol_ S_remove;
  symbol_ S_remove_if;
  symbol_ S_remove_if_not;
  symbol_ S_delete;
  symbol_ S_delete_if;
  symbol_ S_delete_if_not;
  symbol_ S_remove_duplicates;
  symbol_ S_delete_duplicates;
  symbol_ S_substitute;
  symbol_ S_substitute_if;
  symbol_ S_substitute_if_not;
  symbol_ S_nsubstitute;
  symbol_ S_nsubstitute_if;
  symbol_ S_nsubstitute_if_not;
  symbol_ S_find;
  symbol_ S_find_if;
  symbol_ S_find_if_not;
  symbol_ S_position;
  symbol_ S_position_if;
  symbol_ S_position_if_not;
  symbol_ S_count;
  symbol_ S_count_if;
  symbol_ S_count_if_not;
  symbol_ S_mismatch;
  symbol_ S_search;
  symbol_ S_sort;
  symbol_ S_stable_sort;
  symbol_ S_merge;
  symbol_ S_read_char_sequence;
  symbol_ S_write_char_sequence;
  symbol_ S_read_byte_sequence;
  symbol_ S_write_byte_sequence;
  symbol_ S_symbol_stream;
  symbol_ S_terminal_raw;
  symbol_ S_make_window;
  symbol_ S_window_size;
  symbol_ S_window_cursor_position;
  symbol_ S_set_window_cursor_position;
  symbol_ S_clear_window;
  symbol_ S_clear_window_to_eot;
  symbol_ S_clear_window_to_eol;
  symbol_ S_delete_window_line;
  symbol_ S_insert_window_line;
  symbol_ S_highlight_on;
  symbol_ S_highlight_off;
  symbol_ S_window_cursor_on;
  symbol_ S_window_cursor_off;
  symbol_ S_file_stream_p;
  symbol_ S_make_synonym_stream;
  symbol_ S_synonym_stream_p;
  symbol_ S_synonym_stream_symbol;
  symbol_ S_make_broadcast_stream;
  symbol_ S_broadcast_stream_p;
  symbol_ S_broadcast_stream_streams;
  symbol_ S_make_concatenated_stream;
  symbol_ S_concatenated_stream_p;
  symbol_ S_concatenated_stream_streams;
  symbol_ S_make_two_way_stream;
  symbol_ S_two_way_stream_p;
  symbol_ S_two_way_stream_input_stream;
  symbol_ S_two_way_stream_output_stream;
  symbol_ S_make_echo_stream;
  symbol_ S_echo_stream_p;
  symbol_ S_echo_stream_input_stream;
  symbol_ S_echo_stream_output_stream;
  symbol_ S_make_string_input_stream;
  symbol_ S_string_input_stream_index;
  symbol_ S_make_string_output_stream;
  symbol_ S_get_output_stream_string;
  symbol_ S_make_string_push_stream;
  symbol_ S_string_stream_p;
  symbol_ S_make_buffered_input_stream;
  symbol_ S_buffered_input_stream_index;
  symbol_ S_make_buffered_output_stream;
  symbol_ S_make_pipe_input_stream;
  symbol_ S_make_pipe_output_stream;
  symbol_ S_make_pipe_io_stream;
  symbol_ S_make_xsocket_stream;
  symbol_ S_read_n_bytes;
  symbol_ S_write_n_bytes;
  symbol_ S_generic_stream_controller;
  symbol_ S_make_generic_stream;
  symbol_ S_generic_stream_p;
  symbol_ S_socket_server;
  symbol_ S_socket_server_close;
  symbol_ S_socket_server_port;
  symbol_ S_socket_wait;
  symbol_ S_socket_accept;
  symbol_ S_socket_connect;
  symbol_ S_socket_stream_host;
  symbol_ S_socket_stream_port;
  symbol_ S_socket_service_port;
  symbol_ S_socket_stream_peer_host;
  symbol_ S_socket_stream_handle;
  symbol_ S_open_stream_p;
  symbol_ S_input_stream_p;
  symbol_ S_output_stream_p;
  symbol_ S_stream_element_type;
  symbol_ S_interactive_stream_p;
  symbol_ S_close;
  symbol_ S_read_byte;
  symbol_ S_write_byte;
  symbol_ S_file_position;
  symbol_ S_file_length;
  symbol_ S_line_number;
  symbol_ S_putd;
  symbol_ S_proclaim_constant;
  symbol_ S_get;
  symbol_ S_getf;
  symbol_ S_get_properties;
  symbol_ S_putplist;
  symbol_ S_put;
  symbol_ S_remprop;
  symbol_ S_symbol_package;
  symbol_ S_symbol_plist;
  symbol_ S_symbol_name;
  symbol_ S_keywordp;
  symbol_ S_special_variable_p;
  symbol_ S_gensym;
  symbol_ S_decimal_string;
  symbol_ S_zerop;
  symbol_ S_plusp;
  symbol_ S_minusp;
  symbol_ S_oddp;
  symbol_ S_evenp;
  symbol_ S_gleich;
  symbol_ S_ungleich;
  symbol_ S_kleiner;
  symbol_ S_groesser;
  symbol_ S_klgleich;
  symbol_ S_grgleich;
  symbol_ S_max;
  symbol_ S_min;
  symbol_ S_plus;
  symbol_ S_minus;
  symbol_ S_mal;
  symbol_ S_durch;
  symbol_ S_einsplus;
  symbol_ S_einsminus;
  symbol_ S_conjugate;
  symbol_ S_gcd;
  symbol_ S_xgcd;
  symbol_ S_lcm;
  symbol_ S_exp;
  symbol_ S_expt;
  symbol_ S_log;
  symbol_ S_sqrt;
  symbol_ S_isqrt;
  symbol_ S_abs;
  symbol_ S_phase;
  symbol_ S_signum;
  symbol_ S_sin;
  symbol_ S_cos;
  symbol_ S_tan;
  symbol_ S_cis;
  symbol_ S_asin;
  symbol_ S_acos;
  symbol_ S_atan;
  symbol_ S_sinh;
  symbol_ S_cosh;
  symbol_ S_tanh;
  symbol_ S_asinh;
  symbol_ S_acosh;
  symbol_ S_atanh;
  symbol_ S_float;
  symbol_ S_rational;
  symbol_ S_rationalize;
  symbol_ S_numerator;
  symbol_ S_denominator;
  symbol_ S_floor;
  symbol_ S_ceiling;
  symbol_ S_truncate;
  symbol_ S_round;
  symbol_ S_mod;
  symbol_ S_rem;
  symbol_ S_ffloor;
  symbol_ S_fceiling;
  symbol_ S_ftruncate;
  symbol_ S_fround;
  symbol_ S_decode_float;
  symbol_ S_scale_float;
  symbol_ S_float_radix;
  symbol_ S_float_sign;
  symbol_ S_float_digits;
  symbol_ S_float_precision;
  symbol_ S_integer_decode_float;
  symbol_ S_complex;
  symbol_ S_realpart;
  symbol_ S_imagpart;
  symbol_ S_logior;
  symbol_ S_logxor;
  symbol_ S_logand;
  symbol_ S_logeqv;
  symbol_ S_lognand;
  symbol_ S_lognor;
  symbol_ S_logandc1;
  symbol_ S_logandc2;
  symbol_ S_logorc1;
  symbol_ S_logorc2;
  symbol_ S_boole;
  symbol_ S_lognot;
  symbol_ S_logtest;
  symbol_ S_logbitp;
  symbol_ S_ash;
  symbol_ S_logcount;
  symbol_ S_integer_length;
  symbol_ S_byte;
  symbol_ S_bytesize;
  symbol_ S_byteposition;
  symbol_ S_ldb;
  symbol_ S_ldb_test;
  symbol_ S_mask_field;
  symbol_ S_dpb;
  symbol_ S_deposit_field;
  symbol_ S_random;
  symbol_ S_make_random_state;
  symbol_ S_fakultaet;
  symbol_ S_exquo;
  symbol_ S_long_float_digits;
  symbol_ S_set_long_float_digits;
  symbol_ S_log2;
  symbol_ S_log10;
  symbol_ S_validp;
  symbol_ S_sizeof;
  symbol_ S_bitsizeof;
  symbol_ S_lookup_foreign_variable;
  symbol_ S_foreign_value;
  symbol_ S_set_foreign_value;
  symbol_ S_foreign_type;
  symbol_ S_foreign_size;
  symbol_ S_element;
  symbol_ S_deref;
  symbol_ S_slot;
  symbol_ S_cast;
  symbol_ S_lookup_foreign_function;
  symbol_ S_foreign_call_out;
  symbol_ S_Kallow_other_keys;
  symbol_ S_Kadjustable;
  symbol_ S_Kelement_type;
  symbol_ S_Kinitial_element;
  symbol_ S_Kinitial_contents;
  symbol_ S_Kfill_pointer;
  symbol_ S_Kdisplaced_to;
  symbol_ S_Kdisplaced_index_offset;
  symbol_ S_Kstart1;
  symbol_ S_Kend1;
  symbol_ S_Kstart2;
  symbol_ S_Kend2;
  symbol_ S_Kstart;
  symbol_ S_Kend;
  symbol_ S_Kpreserve_whitespace;
  symbol_ S_Kradix;
  symbol_ S_Kjunk_allowed;
  symbol_ S_Kcase;
  symbol_ S_Klevel;
  symbol_ S_Klength;
  symbol_ S_Kgensym;
  symbol_ S_Kescape;
  symbol_ S_Kbase;
  symbol_ S_Karray;
  symbol_ S_Kcircle;
  symbol_ S_Kpretty;
  symbol_ S_Kclosure;
  symbol_ S_Kreadably;
  symbol_ S_Kstream;
  symbol_ S_Kidentity;
  symbol_ S_Ktest;
  symbol_ S_Ktest_not;
  symbol_ S_Kkey;
  symbol_ S_Knicknames;
  symbol_ S_Kuse;
  symbol_ S_Kupdate;
  symbol_ S_Kfrom_end;
  symbol_ S_Kinitial_value;
  symbol_ S_Kcount;
  symbol_ S_Ksize;
  symbol_ S_Krehash_size;
  symbol_ S_Krehash_threshold;
  symbol_ S_Kdefaults;
  symbol_ S_Kdevice;
  symbol_ S_Kdirectory;
  symbol_ S_Kname;
  symbol_ S_Ktype;
  symbol_ S_Kversion;
  symbol_ S_Khost;
  symbol_ S_Kall;
  symbol_ S_Kmerge;
  symbol_ S_Kdirection;
  symbol_ S_Kif_exists;
  symbol_ S_Kif_does_not_exist;
  symbol_ S_Kfull;
  symbol_ S_Kabort;
  symbol_ S_string_char;
  symbol_ S_array_rank_limit;
  symbol_ S_array_dimension_limit;
  symbol_ S_array_total_size_limit;
  symbol_ S_subtype_integer;
  symbol_ S_structure;
  symbol_ S_slot_missing;
  symbol_ S_slot_unbound;
  symbol_ S_reinitialize_instance_table;
  symbol_ S_make_instance_table;
  symbol_ S_initial_reinitialize_instance;
  symbol_ S_initial_initialize_instance;
  symbol_ S_initial_make_instance;
  symbol_ S_simple_vector;
  symbol_ S_simple_string;
  symbol_ S_bit_vector;
  symbol_ S_simple_bit_vector;
  symbol_ S_array;
  symbol_ S_simple_array;
  symbol_ S_sequence;
  symbol_ S_cerror;
  symbol_ S_Kinternal;
  symbol_ S_Kexternal;
  symbol_ S_Kinherited;
  symbol_ S_do_symbols;
  symbol_ S_do_external_symbols;
  symbol_ S_packagestern;
  symbol_ S_internal_time_units_per_second;
  symbol_ S_encode_universal_time;
  symbol_ S_use_clcs;
  symbol_ S_recursive_error_count;
  symbol_ S_error_handler;
  symbol_ S_simple_condition;
  symbol_ S_simple_serious_condition;
  symbol_ S_simple_error;
  symbol_ S_simple_program_error;
  symbol_ S_simple_control_error;
  symbol_ S_simple_arithmetic_error;
  symbol_ S_simple_division_by_zero;
  symbol_ S_simple_floating_point_overflow;
  symbol_ S_simple_floating_point_underflow;
  symbol_ S_simple_cell_error;
  symbol_ S_simple_unbound_variable;
  symbol_ S_simple_undefined_function;
  symbol_ S_simple_type_error;
  symbol_ S_simple_package_error;
  symbol_ S_simple_print_not_readable;
  symbol_ S_simple_stream_error;
  symbol_ S_simple_end_of_file;
  symbol_ S_simple_file_error;
  symbol_ S_simple_storage_condition;
  symbol_ S_simple_warning;
  symbol_ S_Kdatum;
  symbol_ S_Kexpected_type;
  symbol_ S_Kpackage;
  symbol_ S_Kobject;
  symbol_ S_Kpathname;
  symbol_ S_format;
  symbol_ S_debugger_hook;
  symbol_ S_coerce_to_condition;
  symbol_ S_break_on_signals;
  symbol_ S_safe_typep;
  symbol_ S_completion;
  symbol_ S_keyboard_input;
  symbol_ S_terminal_io;
  symbol_ S_key_bindings;
  symbol_ S_query_io;
  symbol_ S_debug_io;
  symbol_ S_standard_input;
  symbol_ S_standard_output;
  symbol_ S_error_output;
  symbol_ S_trace_output;
  symbol_ S_generic_stream_rdch;
  symbol_ S_generic_stream_listen;
  symbol_ S_generic_stream_clear_input;
  symbol_ S_generic_stream_wrch;
  symbol_ S_generic_stream_wrss;
  symbol_ S_generic_stream_finish_output;
  symbol_ S_generic_stream_force_output;
  symbol_ S_generic_stream_clear_output;
  symbol_ S_generic_stream_rdby;
  symbol_ S_generic_stream_wrby;
  symbol_ S_generic_stream_close;
  symbol_ S_default_pathname_defaults;
  symbol_ S_read_pathname_p;
  symbol_ S_logpathname_translations;
  symbol_ S_Kwild;
  symbol_ S_Kwild_inferiors;
  symbol_ S_Krelative;
  symbol_ S_Kabsolute;
  symbol_ S_Knewest;
  symbol_ S_Kcommon;
  symbol_ S_Kinput;
  symbol_ S_Kinput_immutable;
  symbol_ S_Koutput;
  symbol_ S_Kio;
  symbol_ S_Kprobe;
  symbol_ S_unsigned_byte;
  symbol_ S_signed_byte;
  symbol_ S_Kdefault;
  symbol_ S_Kerror;
  symbol_ S_Knew_version;
  symbol_ S_Krename;
  symbol_ S_Krename_and_delete;
  symbol_ S_Koverwrite;
  symbol_ S_Kappend;
  symbol_ S_Ksupersede;
  symbol_ S_Kcreate;
  symbol_ S_warn;
  symbol_ S_with_output_to_string;
  symbol_ S_integer;
  symbol_ S_hash_table;
  symbol_ S_random_state;
  symbol_ S_read_base;
  symbol_ S_read_suppress;
  symbol_ S_readtablestern;
  symbol_ S_features;
  symbol_ S_read_preserve_whitespace;
  symbol_ S_read_line_number;
  symbol_ S_read_recursive_p;
  symbol_ S_read_reference_table;
  symbol_ S_backquote_level;
  symbol_ S_backquote_reader;
  symbol_ S_comma_reader;
  symbol_ S_compiling;
  symbol_ S_make_byte;
  symbol_ S_Kupcase;
  symbol_ S_Kdowncase;
  symbol_ S_Kcapitalize;
  symbol_ S_print_case;
  symbol_ S_print_level;
  symbol_ S_print_length;
  symbol_ S_print_gensym;
  symbol_ S_print_escape;
  symbol_ S_print_radix;
  symbol_ S_print_base;
  symbol_ S_print_array;
  symbol_ S_print_circle;
  symbol_ S_print_pretty;
  symbol_ S_print_closure;
  symbol_ S_print_readably;
  symbol_ S_print_rpars;
  symbol_ S_print_indent_lists;
  symbol_ S_print_circle_table;
  symbol_ S_prin_level;
  symbol_ S_prin_bqlevel;
  symbol_ S_prin_stream;
  symbol_ S_prin_linelength;
  symbol_ S_prin_l1;
  symbol_ S_prin_lm;
  symbol_ S_prin_rpar;
  symbol_ S_prin_jblocks;
  symbol_ S_prin_jbstrings;
  symbol_ S_prin_jbmodus;
  symbol_ S_prin_jblpos;
  symbol_ S_backquote;
  symbol_ S_splice;
  symbol_ S_nsplice;
  symbol_ S_unquote;
  symbol_ S_structure_print;
  symbol_ S_defstruct_description;
  symbol_ S_print_object;
  symbol_ S_trace_values;
  symbol_ S_setf_function;
  symbol_ S_lambda;
  symbol_ S_LLoptional;
  symbol_ S_LLkey;
  symbol_ S_LLallow_other_keys;
  symbol_ S_LLrest;
  symbol_ S_LLaux;
  symbol_ S_macro;
  symbol_ S_special;
  symbol_ S_source;
  symbol_ S_optimize;
  symbol_ S_declaration;
  symbol_ S_compile_lambda;
  symbol_ S_expand_lambdabody_main;
  symbol_ S_compile;
  symbol_ S_evalhookstern;
  symbol_ S_applyhookstern;
  symbol_ S_macroexpand_hook;
  symbol_ S_lambda_parameters_limit;
  symbol_ S_call_arguments_limit;
  symbol_ S_multiple_values_limit;
  symbol_ S_jmpbuf_size;
  symbol_ S_big_endian;
  symbol_ S_Klambda;
  symbol_ S_keyword;
  symbol_ S_plus2;
  symbol_ S_plus3;
  symbol_ S_mal2;
  symbol_ S_mal3;
  symbol_ S_durch2;
  symbol_ S_durch3;
  symbol_ S_driverstern;
  symbol_ S_break_driver;
  symbol_ S_break_count;
  symbol_ S_recurse_count_standard_output;
  symbol_ S_frame_limit1;
  symbol_ S_frame_limit2;
  symbol_ S_load_input_stream;
  symbol_ S_setf;
  symbol_ S_psetf;
  symbol_ S_multiple_value_setf;
  symbol_ S_make_macro_expandercons;
  symbol_ S_pthe;
  symbol_ S_compile_form;
  symbol_ S_inline;
  symbol_ S_notinline;
  symbol_ S_get_funname_symbol;
  symbol_ S_inlinable;
  symbol_ S_symbol;
  symbol_ S_address;
  symbol_ S_file_stream;
  symbol_ S_synonym_stream;
  symbol_ S_broadcast_stream;
  symbol_ S_concatenated_stream;
  symbol_ S_two_way_stream;
  symbol_ S_echo_stream;
  symbol_ S_string_stream;
  symbol_ S_stream;
  symbol_ S_package;
  symbol_ S_readtable;
  symbol_ S_load_time_eval;
  symbol_ S_symbol_macro;
  symbol_ S_foreign_pointer;
  symbol_ S_foreign_address;
  symbol_ S_foreign_variable;
  symbol_ S_foreign_function;
  symbol_ S_finalizer;
  symbol_ S_compiled_function;
  symbol_ S_frame_pointer;
  symbol_ S_read_label;
  symbol_ S_system_internal;
  symbol_ S_fixnum;
  symbol_ S_bignum;
  symbol_ S_ratio;
  symbol_ S_short_float;
  symbol_ S_single_float;
  symbol_ S_double_float;
  symbol_ S_long_float;
  symbol_ S_standard_generic_function;
  symbol_ S_closclass;
  symbol_ S_typep;
  symbol_ S_deftype_expander;
  symbol_ S_gensym_counter;
  symbol_ S_inhibit_floating_point_underflow;
  symbol_ S_pi;
  symbol_ S_number;
  symbol_ S_real;
  symbol_ S_most_positive_fixnum;
  symbol_ S_most_negative_fixnum;
  symbol_ S_most_positive_short_float;
  symbol_ S_least_positive_short_float;
  symbol_ S_least_negative_short_float;
  symbol_ S_most_negative_short_float;
  symbol_ S_most_positive_single_float;
  symbol_ S_least_positive_single_float;
  symbol_ S_least_negative_single_float;
  symbol_ S_most_negative_single_float;
  symbol_ S_most_positive_double_float;
  symbol_ S_least_positive_double_float;
  symbol_ S_least_negative_double_float;
  symbol_ S_most_negative_double_float;
  symbol_ S_most_positive_long_float;
  symbol_ S_least_positive_long_float;
  symbol_ S_least_negative_long_float;
  symbol_ S_most_negative_long_float;
  symbol_ S_short_float_epsilon;
  symbol_ S_single_float_epsilon;
  symbol_ S_double_float_epsilon;
  symbol_ S_long_float_epsilon;
  symbol_ S_short_float_negative_epsilon;
  symbol_ S_single_float_negative_epsilon;
  symbol_ S_double_float_negative_epsilon;
  symbol_ S_long_float_negative_epsilon;
  symbol_ S_default_float_format;
  symbol_ S_read_default_float_format;
  symbol_ S_write_float;
  symbol_ S_random_state_stern;
  symbol_ S_init_hooks;
  symbol_ S_quiet;
  symbol_ S_Klisting;
  symbol_ S_Koutput_file;
  symbol_ S_compile_file;
  symbol_ S_batchmode_errors;
  symbol_ S_image_pathname;
  symbol_ S_boolean;
  symbol_ S_uchar;
  symbol_ S_short;
  symbol_ S_ushort;
  symbol_ S_int;
  symbol_ S_uint;
  symbol_ S_long;
  symbol_ S_ulong;
  symbol_ S_uint8;
  symbol_ S_sint8;
  symbol_ S_uint16;
  symbol_ S_sint16;
  symbol_ S_uint32;
  symbol_ S_sint32;
  symbol_ S_uint64;
  symbol_ S_sint64;
  symbol_ S_c_pointer;
  symbol_ S_c_string;
  symbol_ S_c_struct;
  symbol_ S_c_union;
  symbol_ S_c_array;
  symbol_ S_c_array_max;
  symbol_ S_c_function;
  symbol_ S_c_ptr;
  symbol_ S_c_ptr_null;
  symbol_ S_c_array_ptr;
  symbol_ S_fv_flag_readonly;
  symbol_ S_fv_flag_malloc_free;
  symbol_ S_ff_flag_alloca;
  symbol_ S_ff_flag_malloc_free;
  symbol_ S_ff_flag_out;
  symbol_ S_ff_flag_in_out;
  symbol_ S_ff_language_asm;
  symbol_ S_ff_language_c;
  symbol_ S_ff_language_ansi_c;
  symbol_ S_foreign_call_in;
} symbol_tab_data;
#define S(name)  S_help_(S_##name)
#define symbol_tab_addr ((struct symbol_tab_ *)type_zero_oint(64))
#define S_help_(name)  (as_object((oint)(&symbol_tab_addr->name)))
#define NIL  S(nil)
#define T    S(t)
extern struct object_tab_ object_tab;
extern uintC module_count;
typedef struct { char* packname; char* symname; } subr_initdata;
typedef struct { char* initstring; } object_initdata;
typedef struct module_ { char* name; subr_* stab; uintC* stab_size; object* otab; uintC* otab_size; boolean initialized; subr_initdata* stab_initdata; object_initdata* otab_initdata; void (*initfunction1) _ARGS((struct module_ *)); void (*initfunction2) _ARGS((struct module_ *)); } module_;
extern module_ modules[];
#define STACK_(n)  (STACK[-1-(sintP)(n)])
#define skipSTACKop  -=
#define pushSTACK(obj)  (STACK_(-1) = (obj), STACK skipSTACKop -1)
#define popSTACK()  (STACK skipSTACKop 1, STACK_(-1))
extern uintC mv_count;
extern object mv_space [127];
#define value1  mv_space[0]
extern object subr_self;
extern Values funcall _ARGS((object fun, uintC argcount));
#define LISPFUNN(name,req_anz)  LISPFUN(name,req_anz,0,norest,nokey,0,NIL)
#define LISPFUN_B(name,req_anz,opt_anz,rest_flag,key_flag,key_anz,keywords)  global Values C_##name subr_##rest_flag##_function_args
#define subr_norest_function_args  (void)
#define subr_rest_function_args  (reg4 uintC argcount, reg3 object* rest_args_pointer)
#define LISPFUN_F(name,req_anz,opt_anz,rest_flag,key_flag,key_anz,keywords)  { (lisp_function)(&C_##name), 0, 0, 0, req_anz, opt_anz, (uintB)subr_##rest_flag, (uintB)subr_##key_flag, key_anz, },
#define LISPFUN  LISPFUN_B
#define check_string_char(obj)  if (!string_char_p(obj)) { fehler_string_char(obj); }
#define check_uint8(obj)  if (!uint8_p(obj)) { fehler_uint8(obj); }
#define check_sint8(obj)  if (!sint8_p(obj)) { fehler_sint8(obj); }
#define check_uint16(obj)  if (!uint16_p(obj)) { fehler_uint16(obj); }
#define check_sint16(obj)  if (!sint16_p(obj)) { fehler_sint16(obj); }
#define check_uint32(obj)  if (!uint32_p(obj)) { fehler_uint32(obj); }
#define check_sint32(obj)  if (!sint32_p(obj)) { fehler_sint32(obj); }
#define check_uint64(obj)  if (!uint64_p(obj)) { fehler_uint64(obj); }
#define check_sint64(obj)  if (!sint64_p(obj)) { fehler_sint64(obj); }
#define check_uint(obj)  if (!uint_p(obj)) { fehler_uint(obj); }
#define check_sint(obj)  if (!sint_p(obj)) { fehler_sint(obj); }
#define check_ulong(obj)  if (!ulong_p(obj)) { fehler_ulong(obj); }
#define check_slong(obj)  if (!slong_p(obj)) { fehler_slong(obj); }
#define check_ffloat(obj)  if (!single_float_p(obj)) { fehler_ffloat(obj); }
#define check_dfloat(obj)  if (!double_float_p(obj)) { fehler_dfloat(obj); }
nonreturning_function(extern, fehler_uint8, (object obj));
nonreturning_function(extern, fehler_sint8, (object obj));
nonreturning_function(extern, fehler_uint16, (object obj));
nonreturning_function(extern, fehler_sint16, (object obj));
nonreturning_function(extern, fehler_uint32, (object obj));
nonreturning_function(extern, fehler_sint32, (object obj));
nonreturning_function(extern, fehler_uint64, (object obj));
nonreturning_function(extern, fehler_sint64, (object obj));
nonreturning_function(extern, fehler_uint, (object obj));
nonreturning_function(extern, fehler_sint, (object obj));
nonreturning_function(extern, fehler_ulong, (object obj));
nonreturning_function(extern, fehler_slong, (object obj));
nonreturning_function(extern, fehler_sfloat, (object obj));
nonreturning_function(extern, fehler_dfloat, (object obj));
extern object L_to_I _ARGS((sint32 wert));
extern object UL_to_I _ARGS((uintL wert));
extern object L2_to_I _ARGS((sint32 wert_hi, uint32 wert_lo));
extern object UL2_to_I _ARGS((uint32 wert_hi, uint32 wert_lo));
#define uint8_to_I(val)  fixnum((uint8)(val))
#define sint8_to_I(val)  L_to_I((sint32)(sint8)(val))
#define uint16_to_I(val)  fixnum((uint16)(val))
#define sint16_to_I(val)  L_to_I((sint32)(sint16)(val))
#define uint32_to_I(val)  UL_to_I((uint32)(val))
#define sint32_to_I(val)  L_to_I((sint32)(val))
#define uint64_to_I(val)  UL2_to_I((uint32)((val)>>32),(uint32)(val))
#define sint64_to_I(val)  L2_to_I((sint32)((val)>>32),(uint32)(val))
#define uint_to_I(val)  uint32_to_I(val)
#define sint_to_I(val)  sint32_to_I(val)
#define ulong_to_I(val)  uint32_to_I(val)
#define slong_to_I(val)  sint32_to_I(val)
extern uintL I_to_UL _ARGS((object obj));
extern sintL I_to_L _ARGS((object obj));
extern uint64 I_to_UQ _ARGS((object obj));
extern sint64 I_to_Q _ARGS((object obj));
#define I_to_uint8(obj)  (uint8)(as_oint(obj) >> 0)
#define I_to_sint8(obj)  (sint8)(as_oint(obj) >> 0)
#define I_to_uint16(obj)  (uint16)(as_oint(obj) >> 0)
#define I_to_sint16(obj)  (sint16)(as_oint(obj) >> 0)
#define I_to_uint32(obj)  I_to_UL(obj)
#define I_to_sint32(obj)  I_to_L(obj)
#define I_to_uint64(obj)  I_to_UQ(obj)
#define I_to_sint64(obj)  I_to_Q(obj)
#define I_to_uint  I_to_uint32
#define I_to_sint  I_to_sint32
#define I_to_ulong  I_to_uint32
#define I_to_slong  I_to_sint32
extern object c_float_to_FF _ARGS((ffloatjanus* val_));
extern void FF_to_c_float _ARGS((object obj, ffloatjanus* val_));
extern object c_double_to_DF _ARGS((dfloatjanus* val_));
extern void DF_to_c_double _ARGS((object obj, dfloatjanus* val_));
extern void register_foreign_variable _ARGS((void* address, const char * name, uintBWL flags, uintL size));
extern void register_foreign_function _ARGS((void* address, const char * name, uintWL flags));
extern object convert_from_foreign _ARGS((object fvd, void* data));
extern void convert_to_foreign_mallocing _ARGS((object fvd, object obj, void* data));
extern void convert_to_foreign_nomalloc _ARGS((object fvd, object obj, void* data));
#endif /* _CLISP_H */
