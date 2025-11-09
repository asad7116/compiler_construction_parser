/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "parser.h"
#include "token.h"
#include "lexer.h"

// Forward declarations
void yyerror(const char* msg);
int yylex();

// Declare as extern - definition is in parser.cpp
extern std::shared_ptr<ProgramNode> program_root;


#line 89 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_IDENTIFIER = 3,               /* T_IDENTIFIER  */
  YYSYMBOL_T_INT_LITERAL = 4,              /* T_INT_LITERAL  */
  YYSYMBOL_T_FLOAT_LITERAL = 5,            /* T_FLOAT_LITERAL  */
  YYSYMBOL_T_STRING_LITERAL = 6,           /* T_STRING_LITERAL  */
  YYSYMBOL_T_CHAR_LITERAL = 7,             /* T_CHAR_LITERAL  */
  YYSYMBOL_T_BOOL_LITERAL = 8,             /* T_BOOL_LITERAL  */
  YYSYMBOL_T_NULL_LITERAL = 9,             /* T_NULL_LITERAL  */
  YYSYMBOL_T_HEX_LITERAL = 10,             /* T_HEX_LITERAL  */
  YYSYMBOL_T_OCTAL_LITERAL = 11,           /* T_OCTAL_LITERAL  */
  YYSYMBOL_T_BINARY_LITERAL = 12,          /* T_BINARY_LITERAL  */
  YYSYMBOL_T_FUNCTION = 13,                /* T_FUNCTION  */
  YYSYMBOL_T_INT = 14,                     /* T_INT  */
  YYSYMBOL_T_FLOAT = 15,                   /* T_FLOAT  */
  YYSYMBOL_T_STRING = 16,                  /* T_STRING  */
  YYSYMBOL_T_BOOL = 17,                    /* T_BOOL  */
  YYSYMBOL_T_CHAR = 18,                    /* T_CHAR  */
  YYSYMBOL_T_VOID = 19,                    /* T_VOID  */
  YYSYMBOL_T_IF = 20,                      /* T_IF  */
  YYSYMBOL_T_ELSE = 21,                    /* T_ELSE  */
  YYSYMBOL_T_ELIF = 22,                    /* T_ELIF  */
  YYSYMBOL_T_WHILE = 23,                   /* T_WHILE  */
  YYSYMBOL_T_FOR = 24,                     /* T_FOR  */
  YYSYMBOL_T_DO = 25,                      /* T_DO  */
  YYSYMBOL_T_SWITCH = 26,                  /* T_SWITCH  */
  YYSYMBOL_T_CASE = 27,                    /* T_CASE  */
  YYSYMBOL_T_DEFAULT = 28,                 /* T_DEFAULT  */
  YYSYMBOL_T_RETURN = 29,                  /* T_RETURN  */
  YYSYMBOL_T_BREAK = 30,                   /* T_BREAK  */
  YYSYMBOL_T_CONTINUE = 31,                /* T_CONTINUE  */
  YYSYMBOL_T_PRINT = 32,                   /* T_PRINT  */
  YYSYMBOL_T_READ = 33,                    /* T_READ  */
  YYSYMBOL_T_TRUE = 34,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 35,                   /* T_FALSE  */
  YYSYMBOL_T_NULL = 36,                    /* T_NULL  */
  YYSYMBOL_T_INCLUDE = 37,                 /* T_INCLUDE  */
  YYSYMBOL_T_PLUS = 38,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 39,                   /* T_MINUS  */
  YYSYMBOL_T_MULTIPLY = 40,                /* T_MULTIPLY  */
  YYSYMBOL_T_DIVIDE = 41,                  /* T_DIVIDE  */
  YYSYMBOL_T_MODULO = 42,                  /* T_MODULO  */
  YYSYMBOL_T_EQUAL = 43,                   /* T_EQUAL  */
  YYSYMBOL_T_NOT_EQUAL = 44,               /* T_NOT_EQUAL  */
  YYSYMBOL_T_GREATER_THAN = 45,            /* T_GREATER_THAN  */
  YYSYMBOL_T_LESS_THAN = 46,               /* T_LESS_THAN  */
  YYSYMBOL_T_GREATER_THAN_EQUAL = 47,      /* T_GREATER_THAN_EQUAL  */
  YYSYMBOL_T_LESS_THAN_EQUAL = 48,         /* T_LESS_THAN_EQUAL  */
  YYSYMBOL_T_AND = 49,                     /* T_AND  */
  YYSYMBOL_T_OR = 50,                      /* T_OR  */
  YYSYMBOL_T_NOT = 51,                     /* T_NOT  */
  YYSYMBOL_T_BIT_AND = 52,                 /* T_BIT_AND  */
  YYSYMBOL_T_BIT_OR = 53,                  /* T_BIT_OR  */
  YYSYMBOL_T_BIT_XOR = 54,                 /* T_BIT_XOR  */
  YYSYMBOL_T_BIT_NOT = 55,                 /* T_BIT_NOT  */
  YYSYMBOL_T_LEFT_SHIFT = 56,              /* T_LEFT_SHIFT  */
  YYSYMBOL_T_RIGHT_SHIFT = 57,             /* T_RIGHT_SHIFT  */
  YYSYMBOL_T_ASSIGN = 58,                  /* T_ASSIGN  */
  YYSYMBOL_T_PLUS_ASSIGN = 59,             /* T_PLUS_ASSIGN  */
  YYSYMBOL_T_MINUS_ASSIGN = 60,            /* T_MINUS_ASSIGN  */
  YYSYMBOL_T_MULT_ASSIGN = 61,             /* T_MULT_ASSIGN  */
  YYSYMBOL_T_DIV_ASSIGN = 62,              /* T_DIV_ASSIGN  */
  YYSYMBOL_T_MOD_ASSIGN = 63,              /* T_MOD_ASSIGN  */
  YYSYMBOL_T_AND_ASSIGN = 64,              /* T_AND_ASSIGN  */
  YYSYMBOL_T_OR_ASSIGN = 65,               /* T_OR_ASSIGN  */
  YYSYMBOL_T_XOR_ASSIGN = 66,              /* T_XOR_ASSIGN  */
  YYSYMBOL_T_LSHIFT_ASSIGN = 67,           /* T_LSHIFT_ASSIGN  */
  YYSYMBOL_T_RSHIFT_ASSIGN = 68,           /* T_RSHIFT_ASSIGN  */
  YYSYMBOL_T_INCREMENT = 69,               /* T_INCREMENT  */
  YYSYMBOL_T_DECREMENT = 70,               /* T_DECREMENT  */
  YYSYMBOL_T_COMMA = 71,                   /* T_COMMA  */
  YYSYMBOL_T_SEMICOLON = 72,               /* T_SEMICOLON  */
  YYSYMBOL_T_COLON = 73,                   /* T_COLON  */
  YYSYMBOL_T_DOT = 74,                     /* T_DOT  */
  YYSYMBOL_T_LPAREN = 75,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 76,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACE = 77,                  /* T_LBRACE  */
  YYSYMBOL_T_RBRACE = 78,                  /* T_RBRACE  */
  YYSYMBOL_T_LBRACKET = 79,                /* T_LBRACKET  */
  YYSYMBOL_T_RBRACKET = 80,                /* T_RBRACKET  */
  YYSYMBOL_T_QUESTION = 81,                /* T_QUESTION  */
  YYSYMBOL_T_QUOTES = 82,                  /* T_QUOTES  */
  YYSYMBOL_UNARY = 83,                     /* UNARY  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_program = 85,                   /* program  */
  YYSYMBOL_global_declaration_list = 86,   /* global_declaration_list  */
  YYSYMBOL_global_declaration = 87,        /* global_declaration  */
  YYSYMBOL_function_declaration = 88,      /* function_declaration  */
  YYSYMBOL_parameter_list = 89,            /* parameter_list  */
  YYSYMBOL_parameter = 90,                 /* parameter  */
  YYSYMBOL_type = 91,                      /* type  */
  YYSYMBOL_base_type = 92,                 /* base_type  */
  YYSYMBOL_block = 93,                     /* block  */
  YYSYMBOL_statement_list = 94,            /* statement_list  */
  YYSYMBOL_statement = 95,                 /* statement  */
  YYSYMBOL_variable_declaration = 96,      /* variable_declaration  */
  YYSYMBOL_array_declaration = 97,         /* array_declaration  */
  YYSYMBOL_array_initializer = 98,         /* array_initializer  */
  YYSYMBOL_expression_list = 99,           /* expression_list  */
  YYSYMBOL_pointer_declaration = 100,      /* pointer_declaration  */
  YYSYMBOL_assignment_statement = 101,     /* assignment_statement  */
  YYSYMBOL_assignment_operator = 102,      /* assignment_operator  */
  YYSYMBOL_if_statement = 103,             /* if_statement  */
  YYSYMBOL_while_statement = 104,          /* while_statement  */
  YYSYMBOL_for_statement = 105,            /* for_statement  */
  YYSYMBOL_for_init = 106,                 /* for_init  */
  YYSYMBOL_for_update = 107,               /* for_update  */
  YYSYMBOL_do_while_statement = 108,       /* do_while_statement  */
  YYSYMBOL_switch_statement = 109,         /* switch_statement  */
  YYSYMBOL_case_list = 110,                /* case_list  */
  YYSYMBOL_case_statement = 111,           /* case_statement  */
  YYSYMBOL_default_case = 112,             /* default_case  */
  YYSYMBOL_return_statement = 113,         /* return_statement  */
  YYSYMBOL_break_statement = 114,          /* break_statement  */
  YYSYMBOL_continue_statement = 115,       /* continue_statement  */
  YYSYMBOL_print_statement = 116,          /* print_statement  */
  YYSYMBOL_expression_statement = 117,     /* expression_statement  */
  YYSYMBOL_expression = 118,               /* expression  */
  YYSYMBOL_assignment_expression = 119,    /* assignment_expression  */
  YYSYMBOL_ternary_expression = 120,       /* ternary_expression  */
  YYSYMBOL_logical_or_expression = 121,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 122,   /* logical_and_expression  */
  YYSYMBOL_bitwise_or_expression = 123,    /* bitwise_or_expression  */
  YYSYMBOL_bitwise_xor_expression = 124,   /* bitwise_xor_expression  */
  YYSYMBOL_bitwise_and_expression = 125,   /* bitwise_and_expression  */
  YYSYMBOL_equality_expression = 126,      /* equality_expression  */
  YYSYMBOL_relational_expression = 127,    /* relational_expression  */
  YYSYMBOL_shift_expression = 128,         /* shift_expression  */
  YYSYMBOL_additive_expression = 129,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 130, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 131,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 132,       /* postfix_expression  */
  YYSYMBOL_primary_expression = 133,       /* primary_expression  */
  YYSYMBOL_literal = 134,                  /* literal  */
  YYSYMBOL_argument_list = 135             /* argument_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   590

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  264

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   179,   183,   191,   195,   199,   203,   210,
     223,   238,   239,   243,   251,   260,   272,   273,   274,   275,
     279,   280,   281,   282,   283,   284,   288,   300,   301,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   327,   336,   349,   359,   369,   382,
     391,   398,   402,   410,   419,   432,   441,   454,   455,   456,
     457,   458,   459,   463,   472,   487,   499,   513,   514,   515,
     523,   524,   532,   544,   558,   559,   567,   580,   581,   593,
     597,   606,   610,   614,   623,   632,   636,   640,   641,   652,
     653,   664,   665,   676,   677,   688,   689,   700,   701,   712,
     713,   721,   732,   733,   741,   749,   757,   768,   769,   777,
     788,   789,   797,   808,   809,   817,   825,   836,   837,   844,
     851,   858,   865,   872,   878,   887,   888,   895,   902,   912,
     928,   929,   936,   940,   948,   956,   964,   972,   979,   986,
     994,  1002,  1010,  1021,  1022,  1027
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_IDENTIFIER",
  "T_INT_LITERAL", "T_FLOAT_LITERAL", "T_STRING_LITERAL", "T_CHAR_LITERAL",
  "T_BOOL_LITERAL", "T_NULL_LITERAL", "T_HEX_LITERAL", "T_OCTAL_LITERAL",
  "T_BINARY_LITERAL", "T_FUNCTION", "T_INT", "T_FLOAT", "T_STRING",
  "T_BOOL", "T_CHAR", "T_VOID", "T_IF", "T_ELSE", "T_ELIF", "T_WHILE",
  "T_FOR", "T_DO", "T_SWITCH", "T_CASE", "T_DEFAULT", "T_RETURN",
  "T_BREAK", "T_CONTINUE", "T_PRINT", "T_READ", "T_TRUE", "T_FALSE",
  "T_NULL", "T_INCLUDE", "T_PLUS", "T_MINUS", "T_MULTIPLY", "T_DIVIDE",
  "T_MODULO", "T_EQUAL", "T_NOT_EQUAL", "T_GREATER_THAN", "T_LESS_THAN",
  "T_GREATER_THAN_EQUAL", "T_LESS_THAN_EQUAL", "T_AND", "T_OR", "T_NOT",
  "T_BIT_AND", "T_BIT_OR", "T_BIT_XOR", "T_BIT_NOT", "T_LEFT_SHIFT",
  "T_RIGHT_SHIFT", "T_ASSIGN", "T_PLUS_ASSIGN", "T_MINUS_ASSIGN",
  "T_MULT_ASSIGN", "T_DIV_ASSIGN", "T_MOD_ASSIGN", "T_AND_ASSIGN",
  "T_OR_ASSIGN", "T_XOR_ASSIGN", "T_LSHIFT_ASSIGN", "T_RSHIFT_ASSIGN",
  "T_INCREMENT", "T_DECREMENT", "T_COMMA", "T_SEMICOLON", "T_COLON",
  "T_DOT", "T_LPAREN", "T_RPAREN", "T_LBRACE", "T_RBRACE", "T_LBRACKET",
  "T_RBRACKET", "T_QUESTION", "T_QUOTES", "UNARY", "$accept", "program",
  "global_declaration_list", "global_declaration", "function_declaration",
  "parameter_list", "parameter", "type", "base_type", "block",
  "statement_list", "statement", "variable_declaration",
  "array_declaration", "array_initializer", "expression_list",
  "pointer_declaration", "assignment_statement", "assignment_operator",
  "if_statement", "while_statement", "for_statement", "for_init",
  "for_update", "do_while_statement", "switch_statement", "case_list",
  "case_statement", "default_case", "return_statement", "break_statement",
  "continue_statement", "print_statement", "expression_statement",
  "expression", "assignment_expression", "ternary_expression",
  "logical_or_expression", "logical_and_expression",
  "bitwise_or_expression", "bitwise_xor_expression",
  "bitwise_and_expression", "equality_expression", "relational_expression",
  "shift_expression", "additive_expression", "multiplicative_expression",
  "unary_expression", "postfix_expression", "primary_expression",
  "literal", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-211)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -211,     9,   119,  -211,   104,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,     4,     0,  -211,  -211,  -211,   -60,    22,
     -26,  -211,     7,   -23,    54,   173,   -14,    90,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,   515,
     515,   515,   515,   515,   515,   515,   515,  -211,   -17,  -211,
    -211,   -42,    23,    45,    35,    51,    -6,   101,    13,    36,
     121,  -211,    11,  -211,  -211,   515,  -211,   515,   -36,   -50,
    -211,    25,   123,   173,    70,    71,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,    76,  -211,   515,   515,   515,   515,   515,
     515,   515,   515,   515,   515,   515,   515,   515,   515,   515,
     515,   515,   515,   515,  -211,  -211,   515,   515,    86,    84,
     515,  -211,   173,    89,  -211,  -211,   -16,    91,    95,  -211,
      23,    96,    45,    35,    51,    -6,   101,   101,    13,    13,
      13,    13,    36,    36,   121,   121,  -211,  -211,  -211,  -211,
       2,    97,  -211,    99,   106,  -211,  -211,  -211,    89,   275,
     107,  -211,   515,   515,  -211,  -211,  -211,  -211,   222,  -211,
    -211,   -51,  -211,  -211,  -211,  -211,   -29,   110,   124,   125,
     351,   126,   462,   130,   131,   515,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,   134,   515,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,   515,   515,   515,   515,   424,   153,   515,  -211,
     136,  -211,  -211,   137,  -211,  -211,   127,   138,   139,   140,
     210,  -211,   145,  -211,   143,   144,  -211,  -211,   135,  -211,
     351,   351,    -4,   515,   515,   142,   515,   200,  -211,   151,
     148,  -211,   163,   351,   515,   171,    78,  -211,  -211,   168,
    -211,  -211,   515,   176,  -211,   172,   351,   182,  -211,  -211,
    -211,  -211,   351,   351
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,    20,    21,    22,    24,    23,
      25,     4,     5,     0,    16,     6,     7,     8,     0,     0,
       0,    17,     0,     0,     0,    11,     0,     0,   131,   133,
     134,   135,   136,   139,   140,   141,   142,   137,   138,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,    85,
      86,    87,    89,    91,    93,    95,    97,    99,   102,   107,
     110,   113,   117,   125,   130,     0,    44,     0,     0,     0,
      12,     0,    16,    11,     0,     0,   119,   123,   118,   124,
     120,   121,   122,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,   127,   143,     0,     0,     0,
       0,    53,     0,     0,    15,    14,     0,     0,     0,   132,
      90,     0,    92,    94,    96,    98,   100,   101,   103,   104,
     105,   106,   108,   109,   111,   112,   114,   115,   116,   144,
       0,     0,    45,     0,     0,    13,    27,    10,     0,     0,
       0,    46,     0,     0,   129,   128,    48,    54,     0,     9,
      50,     0,    51,    47,    88,   145,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    26,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     0,     0,    49,    57,    58,    59,    60,
      61,    62,     0,     0,     0,     0,    67,     0,     0,    79,
       0,    81,    82,     0,    84,    52,     0,     0,     0,     0,
       0,    68,     0,    69,     0,     0,    80,    83,     0,    55,
       0,     0,     0,     0,     0,     0,     0,    63,    65,     0,
       0,    74,     0,     0,    70,     0,    77,    56,    64,     0,
      71,    72,     0,     0,    75,     0,     0,     0,    27,    73,
      66,    27,    78,    76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,  -211,  -211,  -211,   185,   147,   -21,    -2,   112,
    -210,  -164,    -1,   261,  -211,  -211,   262,  -211,    37,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,   -22,  -211,   114,  -211,   183,   180,
     181,   186,   193,    17,    61,    42,    44,    72,  -211,  -211,
    -211,  -211
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    11,    12,    69,    70,    13,    14,   147,
     158,   178,   179,   180,   150,   161,   181,   182,   203,   183,
     184,   185,   222,   249,   186,   187,   246,   254,   255,   188,
     189,   190,   191,   192,   193,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   140
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    15,    19,    23,    71,    75,   207,    20,    85,     3,
      28,    29,    30,    31,    32,    25,    33,    34,    35,    36,
     194,   112,   110,    72,    83,    26,   113,   195,   114,   196,
     197,   198,   199,   200,   201,    65,   111,    91,    92,    86,
      24,    37,    38,   108,    21,   109,    39,    40,   262,    66,
     202,   263,    71,    27,    65,   112,    67,    68,    41,    42,
     148,    73,    43,    84,   121,    21,   237,   238,    66,    97,
      98,    72,    87,   153,    99,   100,    44,    45,   154,   248,
     104,   105,    46,    22,   139,   141,   106,    47,   144,    89,
     107,    71,   260,    28,    29,    30,    31,    32,    88,    33,
      34,    35,    36,    90,    22,   252,   253,    18,   126,   127,
      72,    76,    77,    78,    79,    80,    81,    82,     5,     6,
       7,     8,     9,    10,    37,    38,   115,   162,   117,    39,
      40,   165,     4,     5,     6,     7,     8,     9,    10,   132,
     133,    41,    42,   134,   135,    43,    93,    94,    95,    96,
     210,   118,   119,   213,   128,   129,   130,   131,   142,    44,
      45,   101,   102,   103,   143,    46,   146,   151,   149,   152,
      74,   156,   215,   136,   137,   138,   224,   155,   157,   163,
     216,   217,   218,   219,   223,   204,   225,     5,     6,     7,
       8,     9,    10,   196,   197,   198,   199,   200,   201,   205,
     206,   208,   211,   212,   220,   221,   214,   228,   226,   227,
     229,   239,   240,   232,   242,   230,   231,   233,   234,   241,
     235,   243,   250,   244,   245,   166,    29,    30,    31,    32,
     257,    33,    34,    35,    36,   247,     5,     6,     7,     8,
       9,    10,   167,   251,   256,   168,   169,   170,   171,   258,
     259,   172,   173,   174,   175,   261,    37,    38,   116,   145,
     159,    39,    40,    16,    17,   236,   164,   122,   120,   123,
       0,     0,     0,    41,    42,   124,     0,    43,    28,    29,
      30,    31,    32,   125,    33,    34,    35,    36,     0,     0,
       0,    44,    45,     0,   176,     0,     0,    46,     0,     0,
     177,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,     0,     0,     0,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,     0,
      46,     0,     0,   160,   166,    29,    30,    31,    32,     0,
      33,    34,    35,    36,     0,     5,     6,     7,     8,     9,
      10,   167,     0,     0,   168,   169,   170,   171,     0,     0,
     172,   173,   174,   175,     0,    37,    38,     0,     0,     0,
      39,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    42,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,     0,   176,     0,     0,    46,    28,    29,    30,
      31,    32,     0,    33,    34,    35,    36,     0,     5,     6,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,    38,
       0,     0,     0,    39,    40,    28,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    41,    42,     0,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,    37,    38,     0,    46,
       0,    39,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,    42,     0,     0,    43,    28,    29,
      30,    31,    32,     0,    33,    34,    35,    36,     0,     0,
       0,    44,    45,     0,   209,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,     0,     0,     0,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,     0,
      46
};

static const yytype_int16 yycheck[] =
{
      22,     2,     4,     3,    25,    27,   170,     3,    50,     0,
       3,     4,     5,     6,     7,    75,     9,    10,    11,    12,
      71,    71,    58,    25,    46,     3,    76,    78,     3,    58,
      59,    60,    61,    62,    63,    58,    72,    43,    44,    81,
      40,    34,    35,    65,    40,    67,    39,    40,   258,    72,
      79,   261,    73,    79,    58,    71,    79,     3,    51,    52,
      76,    75,    55,    80,    86,    40,   230,   231,    72,    56,
      57,    73,    49,    71,    38,    39,    69,    70,    76,   243,
      69,    70,    75,    79,   106,   107,    75,    80,   110,    54,
      79,   112,   256,     3,     4,     5,     6,     7,    53,     9,
      10,    11,    12,    52,    79,    27,    28,     3,    91,    92,
     112,    39,    40,    41,    42,    43,    44,    45,    14,    15,
      16,    17,    18,    19,    34,    35,     3,   149,    58,    39,
      40,   153,    13,    14,    15,    16,    17,    18,    19,    97,
      98,    51,    52,    99,   100,    55,    45,    46,    47,    48,
     172,    80,    76,   175,    93,    94,    95,    96,    72,    69,
      70,    40,    41,    42,    80,    75,    77,    72,    77,    73,
      80,    72,   194,   101,   102,   103,    23,    80,    72,    72,
     202,   203,   204,   205,   206,    75,   208,    14,    15,    16,
      17,    18,    19,    58,    59,    60,    61,    62,    63,    75,
      75,    75,    72,    72,   206,   206,    72,    80,    72,    72,
      72,   233,   234,     3,   236,    76,    76,    72,    75,    77,
      76,    21,   244,    72,    76,     3,     4,     5,     6,     7,
     252,     9,    10,    11,    12,    72,    14,    15,    16,    17,
      18,    19,    20,    72,    76,    23,    24,    25,    26,    73,
      78,    29,    30,    31,    32,    73,    34,    35,    73,   112,
     148,    39,    40,     2,     2,   228,   152,    87,    85,    88,
      -1,    -1,    -1,    51,    52,    89,    -1,    55,     3,     4,
       5,     6,     7,    90,     9,    10,    11,    12,    -1,    -1,
      -1,    69,    70,    -1,    72,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    -1,    34,    35,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    -1,    72,    -1,    -1,    75,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    -1,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    -1,    39,    40,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    12,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    34,    35,    -1,    75,
      -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    55,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    -1,    -1,
      -1,    69,    70,    -1,    72,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,
      75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    85,    86,     0,    13,    14,    15,    16,    17,    18,
      19,    87,    88,    91,    92,    96,    97,   100,     3,    92,
       3,    40,    79,     3,    40,    75,     3,    79,     3,     4,
       5,     6,     7,     9,    10,    11,    12,    34,    35,    39,
      40,    51,    52,    55,    69,    70,    75,    80,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    58,    72,    79,     3,    89,
      90,    91,    92,    75,    80,   118,   131,   131,   131,   131,
     131,   131,   131,   118,    80,    50,    81,    49,    53,    54,
      52,    43,    44,    45,    46,    47,    48,    56,    57,    38,
      39,    40,    41,    42,    69,    70,    75,    79,   118,   118,
      58,    72,    71,    76,     3,     3,    89,    58,    80,    76,
     122,   118,   123,   124,   125,   126,   127,   127,   128,   128,
     128,   128,   129,   129,   130,   130,   131,   131,   131,   118,
     135,   118,    72,    80,   118,    90,    77,    93,    76,    77,
      98,    72,    73,    71,    76,    80,    72,    72,    94,    93,
      78,    99,   118,    72,   120,   118,     3,    20,    23,    24,
      25,    26,    29,    30,    31,    32,    72,    78,    95,    96,
      97,   100,   101,   103,   104,   105,   108,   109,   113,   114,
     115,   116,   117,   118,    71,    78,    58,    59,    60,    61,
      62,    63,    79,   102,    75,    75,    75,    95,    75,    72,
     118,    72,    72,   118,    72,   118,   118,   118,   118,   118,
      92,    96,   106,   118,    23,   118,    72,    72,    80,    72,
      76,    76,     3,    72,    75,    76,   102,    95,    95,   118,
     118,    77,   118,    21,    72,    76,   110,    72,    95,   107,
     118,    72,    27,    28,   111,   112,    76,   118,    73,    78,
      95,    73,    94,    94
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    87,    87,    87,    87,    88,
      88,    89,    89,    89,    90,    90,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    93,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   102,
     102,   102,   102,   103,   103,   104,   105,   106,   106,   106,
     107,   107,   108,   109,   110,   110,   111,   112,   112,   113,
     113,   114,   115,   116,   117,   118,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   126,
     126,   126,   127,   127,   127,   127,   127,   128,   128,   128,
     129,   129,   129,   130,   130,   130,   130,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   132,   132,   132,   132,
     133,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   135,   135,   135
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     7,
       6,     0,     1,     3,     2,     2,     1,     2,     3,     4,
       1,     1,     1,     1,     1,     1,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     6,     7,     6,     3,
       2,     1,     3,     4,     6,     4,     7,     1,     1,     1,
       1,     1,     1,     5,     7,     5,     9,     0,     1,     1,
       0,     1,     7,     8,     0,     2,     4,     0,     3,     2,
       3,     2,     2,     3,     2,     1,     1,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     4,     4,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: global_declaration_list  */
#line 126 "parser.y"
    {
        program_root = std::make_shared<ProgramNode>();
        
        if ((yyvsp[0].decl_list)) {
            for (auto wrapper : *(yyvsp[0].decl_list)) {
                switch (wrapper->type) {
                    case DeclarationWrapper::FUNCTION: {
                        auto func = static_cast<FunctionNode*>(wrapper->ptr);
                        program_root->functions.push_back(std::shared_ptr<FunctionNode>(func));
                        std::cout << "DEBUG: Added function: " << func->name << std::endl;
                        break;
                    }
                    case DeclarationWrapper::VARIABLE: {
                        auto var = static_cast<VariableDeclarationNode*>(wrapper->ptr);
                        program_root->globalVariables.push_back(std::shared_ptr<VariableDeclarationNode>(var));
                        std::cout << "DEBUG: Added variable: " << var->name << std::endl;
                        break;
                    }
                    case DeclarationWrapper::ARRAY: {
                        auto arr = static_cast<ArrayDeclarationNode*>(wrapper->ptr);
                        auto var = std::make_shared<VariableDeclarationNode>();
                        var->name = arr->name;
                        var->type = arr->type;
                        program_root->globalVariables.push_back(var);
                        std::cout << "DEBUG: Added array: " << arr->name << std::endl;
                        delete arr;
                        break;
                    }
                    case DeclarationWrapper::POINTER: {
                        auto ptr = static_cast<PointerDeclarationNode*>(wrapper->ptr);
                        auto var = std::make_shared<VariableDeclarationNode>();
                        var->name = ptr->name;
                        var->type = ptr->baseType + "*";
                        program_root->globalVariables.push_back(var);
                        std::cout << "DEBUG: Added pointer: " << ptr->name << std::endl;
                        delete ptr;
                        break;
                    }
                }
                delete wrapper;
            }
            delete (yyvsp[0].decl_list);
        }
        
        std::cout << "DEBUG: Program created with " 
                  << program_root->functions.size() << " functions and "
                  << program_root->globalVariables.size() << " global variables" << std::endl;
        
        (yyval.program_node) = program_root.get();
    }
#line 1533 "parser.tab.c"
    break;

  case 3: /* global_declaration_list: %empty  */
#line 180 "parser.y"
    { 
        (yyval.decl_list) = new std::vector<DeclarationWrapper*>(); 
    }
#line 1541 "parser.tab.c"
    break;

  case 4: /* global_declaration_list: global_declaration_list global_declaration  */
#line 184 "parser.y"
    {
        if ((yyvsp[0].decl_wrapper)) (yyvsp[-1].decl_list)->push_back((yyvsp[0].decl_wrapper));
        (yyval.decl_list) = (yyvsp[-1].decl_list);
    }
#line 1550 "parser.tab.c"
    break;

  case 5: /* global_declaration: function_declaration  */
#line 192 "parser.y"
    { 
        (yyval.decl_wrapper) = new DeclarationWrapper(DeclarationWrapper::FUNCTION, (yyvsp[0].function_node));
    }
#line 1558 "parser.tab.c"
    break;

  case 6: /* global_declaration: variable_declaration  */
#line 196 "parser.y"
    { 
        (yyval.decl_wrapper) = new DeclarationWrapper(DeclarationWrapper::VARIABLE, (yyvsp[0].var_decl_node));
    }
#line 1566 "parser.tab.c"
    break;

  case 7: /* global_declaration: array_declaration  */
#line 200 "parser.y"
    { 
        (yyval.decl_wrapper) = new DeclarationWrapper(DeclarationWrapper::ARRAY, (yyvsp[0].array_decl_node));
    }
#line 1574 "parser.tab.c"
    break;

  case 8: /* global_declaration: pointer_declaration  */
#line 204 "parser.y"
    { 
        (yyval.decl_wrapper) = new DeclarationWrapper(DeclarationWrapper::POINTER, (yyvsp[0].pointer_decl_node));
    }
#line 1582 "parser.tab.c"
    break;

  case 9: /* function_declaration: T_FUNCTION base_type T_IDENTIFIER T_LPAREN parameter_list T_RPAREN block  */
#line 211 "parser.y"
    {
        auto func = new FunctionNode();
        func->returnType = *(yyvsp[-5].str_val);
        func->name = *(yyvsp[-4].str_val);
        if ((yyvsp[-2].param_list)) func->parameters = *(yyvsp[-2].param_list);
        func->body = std::shared_ptr<BlockNode>((yyvsp[0].block_node));
        std::cout << "DEBUG: Created function '" << func->name << "' with return type '" << func->returnType << "'" << std::endl;
        (yyval.function_node) = func;
        delete (yyvsp[-5].str_val);
        delete (yyvsp[-4].str_val);
        if ((yyvsp[-2].param_list)) delete (yyvsp[-2].param_list);
    }
#line 1599 "parser.tab.c"
    break;

  case 10: /* function_declaration: T_FUNCTION T_IDENTIFIER T_LPAREN parameter_list T_RPAREN block  */
#line 224 "parser.y"
    {
        auto func = new FunctionNode();
        func->name = *(yyvsp[-4].str_val);
        func->returnType = "void";
        if ((yyvsp[-2].param_list)) func->parameters = *(yyvsp[-2].param_list);
        func->body = std::shared_ptr<BlockNode>((yyvsp[0].block_node));
        std::cout << "DEBUG: Created function '" << func->name << "' (void)" << std::endl;
        (yyval.function_node) = func;
        delete (yyvsp[-4].str_val);
        if ((yyvsp[-2].param_list)) delete (yyvsp[-2].param_list);
    }
#line 1615 "parser.tab.c"
    break;

  case 11: /* parameter_list: %empty  */
#line 238 "parser.y"
           { (yyval.param_list) = new std::vector<std::shared_ptr<ParameterNode>>(); }
#line 1621 "parser.tab.c"
    break;

  case 12: /* parameter_list: parameter  */
#line 239 "parser.y"
                { 
        (yyval.param_list) = new std::vector<std::shared_ptr<ParameterNode>>();
        (yyval.param_list)->push_back(std::shared_ptr<ParameterNode>((yyvsp[0].parameter_node)));
    }
#line 1630 "parser.tab.c"
    break;

  case 13: /* parameter_list: parameter_list T_COMMA parameter  */
#line 244 "parser.y"
    {
        (yyvsp[-2].param_list)->push_back(std::shared_ptr<ParameterNode>((yyvsp[0].parameter_node)));
        (yyval.param_list) = (yyvsp[-2].param_list);
    }
#line 1639 "parser.tab.c"
    break;

  case 14: /* parameter: base_type T_IDENTIFIER  */
#line 252 "parser.y"
    {
        auto param = new ParameterNode();
        param->type = *(yyvsp[-1].str_val);
        param->name = *(yyvsp[0].str_val);
        (yyval.parameter_node) = param;
        delete (yyvsp[-1].str_val);
        delete (yyvsp[0].str_val);
    }
#line 1652 "parser.tab.c"
    break;

  case 15: /* parameter: type T_IDENTIFIER  */
#line 261 "parser.y"
    {
        auto param = new ParameterNode();
        param->type = *(yyvsp[-1].str_val);
        param->name = *(yyvsp[0].str_val);
        (yyval.parameter_node) = param;
        delete (yyvsp[-1].str_val);
        delete (yyvsp[0].str_val);
    }
#line 1665 "parser.tab.c"
    break;

  case 16: /* type: base_type  */
#line 272 "parser.y"
              { (yyval.str_val) = (yyvsp[0].str_val); }
#line 1671 "parser.tab.c"
    break;

  case 17: /* type: type T_MULTIPLY  */
#line 273 "parser.y"
                      { (yyval.str_val) = new std::string(*(yyvsp[-1].str_val) + "*"); delete (yyvsp[-1].str_val); }
#line 1677 "parser.tab.c"
    break;

  case 18: /* type: type T_LBRACKET T_RBRACKET  */
#line 274 "parser.y"
                                 { (yyval.str_val) = new std::string(*(yyvsp[-2].str_val) + "[]"); delete (yyvsp[-2].str_val); }
#line 1683 "parser.tab.c"
    break;

  case 19: /* type: type T_LBRACKET expression T_RBRACKET  */
#line 275 "parser.y"
                                            { (yyval.str_val) = new std::string(*(yyvsp[-3].str_val) + "[]"); delete (yyvsp[-3].str_val); }
#line 1689 "parser.tab.c"
    break;

  case 20: /* base_type: T_INT  */
#line 279 "parser.y"
          { (yyval.str_val) = new std::string("int"); }
#line 1695 "parser.tab.c"
    break;

  case 21: /* base_type: T_FLOAT  */
#line 280 "parser.y"
              { (yyval.str_val) = new std::string("float"); }
#line 1701 "parser.tab.c"
    break;

  case 22: /* base_type: T_STRING  */
#line 281 "parser.y"
               { (yyval.str_val) = new std::string("string"); }
#line 1707 "parser.tab.c"
    break;

  case 23: /* base_type: T_CHAR  */
#line 282 "parser.y"
             { (yyval.str_val) = new std::string("char"); }
#line 1713 "parser.tab.c"
    break;

  case 24: /* base_type: T_BOOL  */
#line 283 "parser.y"
             { (yyval.str_val) = new std::string("bool"); }
#line 1719 "parser.tab.c"
    break;

  case 25: /* base_type: T_VOID  */
#line 284 "parser.y"
             { (yyval.str_val) = new std::string("void"); }
#line 1725 "parser.tab.c"
    break;

  case 26: /* block: T_LBRACE statement_list T_RBRACE  */
#line 289 "parser.y"
    {
        auto block_node = new BlockNode();
        if ((yyvsp[-1].stmt_list)) {
            block_node->statements = *(yyvsp[-1].stmt_list);
            delete (yyvsp[-1].stmt_list);
        }
        (yyval.block_node) = block_node;
    }
#line 1738 "parser.tab.c"
    break;

  case 27: /* statement_list: %empty  */
#line 300 "parser.y"
           { (yyval.stmt_list) = new std::vector<std::shared_ptr<StatementNode>>(); }
#line 1744 "parser.tab.c"
    break;

  case 28: /* statement_list: statement_list statement  */
#line 302 "parser.y"
    {
        if ((yyvsp[0].statement_node)) (yyvsp[-1].stmt_list)->push_back(std::shared_ptr<StatementNode>((yyvsp[0].statement_node)));
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
    }
#line 1753 "parser.tab.c"
    break;

  case 29: /* statement: variable_declaration  */
#line 309 "parser.y"
                         { (yyval.statement_node) = (yyvsp[0].var_decl_node); }
#line 1759 "parser.tab.c"
    break;

  case 30: /* statement: array_declaration  */
#line 310 "parser.y"
                        { (yyval.statement_node) = (yyvsp[0].array_decl_node); }
#line 1765 "parser.tab.c"
    break;

  case 31: /* statement: pointer_declaration  */
#line 311 "parser.y"
                          { (yyval.statement_node) = (yyvsp[0].pointer_decl_node); }
#line 1771 "parser.tab.c"
    break;

  case 32: /* statement: assignment_statement  */
#line 312 "parser.y"
                           { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1777 "parser.tab.c"
    break;

  case 33: /* statement: if_statement  */
#line 313 "parser.y"
                   { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1783 "parser.tab.c"
    break;

  case 34: /* statement: while_statement  */
#line 314 "parser.y"
                      { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1789 "parser.tab.c"
    break;

  case 35: /* statement: for_statement  */
#line 315 "parser.y"
                    { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1795 "parser.tab.c"
    break;

  case 36: /* statement: do_while_statement  */
#line 316 "parser.y"
                         { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1801 "parser.tab.c"
    break;

  case 37: /* statement: switch_statement  */
#line 317 "parser.y"
                       { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1807 "parser.tab.c"
    break;

  case 38: /* statement: return_statement  */
#line 318 "parser.y"
                       { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1813 "parser.tab.c"
    break;

  case 39: /* statement: break_statement  */
#line 319 "parser.y"
                      { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1819 "parser.tab.c"
    break;

  case 40: /* statement: continue_statement  */
#line 320 "parser.y"
                         { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1825 "parser.tab.c"
    break;

  case 41: /* statement: print_statement  */
#line 321 "parser.y"
                      { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1831 "parser.tab.c"
    break;

  case 42: /* statement: expression_statement  */
#line 322 "parser.y"
                           { (yyval.statement_node) = (yyvsp[0].statement_node); }
#line 1837 "parser.tab.c"
    break;

  case 43: /* statement: T_SEMICOLON  */
#line 323 "parser.y"
                  { (yyval.statement_node) = nullptr; }
#line 1843 "parser.tab.c"
    break;

  case 44: /* variable_declaration: base_type T_IDENTIFIER T_SEMICOLON  */
#line 328 "parser.y"
    {
        auto var = new VariableDeclarationNode();
        var->type = *(yyvsp[-2].str_val);
        var->name = *(yyvsp[-1].str_val);
        (yyval.var_decl_node) = var;
        delete (yyvsp[-2].str_val);
        delete (yyvsp[-1].str_val);
    }
#line 1856 "parser.tab.c"
    break;

  case 45: /* variable_declaration: base_type T_IDENTIFIER T_ASSIGN expression T_SEMICOLON  */
#line 337 "parser.y"
    {
        auto var = new VariableDeclarationNode();
        var->type = *(yyvsp[-4].str_val);
        var->name = *(yyvsp[-3].str_val);
        var->initializer = std::shared_ptr<ExpressionNode>((yyvsp[-1].expression_node));
        (yyval.var_decl_node) = var;
        delete (yyvsp[-4].str_val);
        delete (yyvsp[-3].str_val);
    }
#line 1870 "parser.tab.c"
    break;

  case 46: /* array_declaration: type T_IDENTIFIER T_LBRACKET expression T_RBRACKET T_SEMICOLON  */
#line 350 "parser.y"
    {
        auto arr = new ArrayDeclarationNode();
        arr->type = *(yyvsp[-5].str_val);
        arr->name = *(yyvsp[-4].str_val);
        arr->size = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        (yyval.array_decl_node) = arr;
        delete (yyvsp[-5].str_val);
        delete (yyvsp[-4].str_val);
    }
#line 1884 "parser.tab.c"
    break;

  case 47: /* array_declaration: type T_IDENTIFIER T_LBRACKET T_RBRACKET T_ASSIGN array_initializer T_SEMICOLON  */
#line 360 "parser.y"
    {
        auto arr = new ArrayDeclarationNode();
        arr->type = *(yyvsp[-6].str_val);
        arr->name = *(yyvsp[-5].str_val);
        arr->initializer = std::shared_ptr<ArrayInitializationNode>((yyvsp[-1].array_init_node));
        (yyval.array_decl_node) = arr;
        delete (yyvsp[-6].str_val);
        delete (yyvsp[-5].str_val);
    }
#line 1898 "parser.tab.c"
    break;

  case 48: /* array_declaration: base_type T_IDENTIFIER T_LBRACKET expression T_RBRACKET T_SEMICOLON  */
#line 370 "parser.y"
    {
        auto arr = new ArrayDeclarationNode();
        arr->type = *(yyvsp[-5].str_val);
        arr->name = *(yyvsp[-4].str_val);
        arr->size = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        (yyval.array_decl_node) = arr;
        delete (yyvsp[-5].str_val);
        delete (yyvsp[-4].str_val);
    }
#line 1912 "parser.tab.c"
    break;

  case 49: /* array_initializer: T_LBRACE expression_list T_RBRACE  */
#line 383 "parser.y"
    {
        auto init = new ArrayInitializationNode();
        if ((yyvsp[-1].expr_list)) {
            init->elements = *(yyvsp[-1].expr_list);
            delete (yyvsp[-1].expr_list);
        }
        (yyval.array_init_node) = init;
    }
#line 1925 "parser.tab.c"
    break;

  case 50: /* array_initializer: T_LBRACE T_RBRACE  */
#line 392 "parser.y"
    {
        (yyval.array_init_node) = new ArrayInitializationNode();
    }
#line 1933 "parser.tab.c"
    break;

  case 51: /* expression_list: expression  */
#line 398 "parser.y"
               { 
        (yyval.expr_list) = new std::vector<std::shared_ptr<ExpressionNode>>();
        (yyval.expr_list)->push_back(std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node)));
    }
#line 1942 "parser.tab.c"
    break;

  case 52: /* expression_list: expression_list T_COMMA expression  */
#line 403 "parser.y"
    {
        (yyvsp[-2].expr_list)->push_back(std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node)));
        (yyval.expr_list) = (yyvsp[-2].expr_list);
    }
#line 1951 "parser.tab.c"
    break;

  case 53: /* pointer_declaration: base_type T_MULTIPLY T_IDENTIFIER T_SEMICOLON  */
#line 411 "parser.y"
    {
        auto ptr = new PointerDeclarationNode();
        ptr->baseType = *(yyvsp[-3].str_val);
        ptr->name = *(yyvsp[-1].str_val);
        (yyval.pointer_decl_node) = ptr;
        delete (yyvsp[-3].str_val);
        delete (yyvsp[-1].str_val);
    }
#line 1964 "parser.tab.c"
    break;

  case 54: /* pointer_declaration: base_type T_MULTIPLY T_IDENTIFIER T_ASSIGN expression T_SEMICOLON  */
#line 420 "parser.y"
    {
        auto ptr = new PointerDeclarationNode();
        ptr->baseType = *(yyvsp[-5].str_val);
        ptr->name = *(yyvsp[-3].str_val);
        ptr->initializer = std::shared_ptr<ExpressionNode>((yyvsp[-1].expression_node));
        (yyval.pointer_decl_node) = ptr;
        delete (yyvsp[-5].str_val);
        delete (yyvsp[-3].str_val);
    }
#line 1978 "parser.tab.c"
    break;

  case 55: /* assignment_statement: T_IDENTIFIER assignment_operator expression T_SEMICOLON  */
#line 433 "parser.y"
    {
        auto assign = new AssignmentNode();
        assign->variable = *(yyvsp[-3].str_val);
        assign->value = std::shared_ptr<ExpressionNode>((yyvsp[-1].expression_node));
        (yyval.statement_node) = assign;
        delete (yyvsp[-3].str_val);
        delete (yyvsp[-2].str_val);
    }
#line 1991 "parser.tab.c"
    break;

  case 56: /* assignment_statement: T_IDENTIFIER T_LBRACKET expression T_RBRACKET assignment_operator expression T_SEMICOLON  */
#line 442 "parser.y"
    {
        // Array element assignment: arr[index] = value
        auto assign = new AssignmentNode();
        assign->variable = *(yyvsp[-6].str_val) + "[...]";  // Mark as array access
        assign->value = std::shared_ptr<ExpressionNode>((yyvsp[-1].expression_node));
        (yyval.statement_node) = assign;
        delete (yyvsp[-6].str_val);
        delete (yyvsp[-2].str_val);
    }
#line 2005 "parser.tab.c"
    break;

  case 57: /* assignment_operator: T_ASSIGN  */
#line 454 "parser.y"
             { (yyval.str_val) = new std::string("="); }
#line 2011 "parser.tab.c"
    break;

  case 58: /* assignment_operator: T_PLUS_ASSIGN  */
#line 455 "parser.y"
                    { (yyval.str_val) = new std::string("+="); }
#line 2017 "parser.tab.c"
    break;

  case 59: /* assignment_operator: T_MINUS_ASSIGN  */
#line 456 "parser.y"
                     { (yyval.str_val) = new std::string("-="); }
#line 2023 "parser.tab.c"
    break;

  case 60: /* assignment_operator: T_MULT_ASSIGN  */
#line 457 "parser.y"
                    { (yyval.str_val) = new std::string("*="); }
#line 2029 "parser.tab.c"
    break;

  case 61: /* assignment_operator: T_DIV_ASSIGN  */
#line 458 "parser.y"
                   { (yyval.str_val) = new std::string("/="); }
#line 2035 "parser.tab.c"
    break;

  case 62: /* assignment_operator: T_MOD_ASSIGN  */
#line 459 "parser.y"
                   { (yyval.str_val) = new std::string("%="); }
#line 2041 "parser.tab.c"
    break;

  case 63: /* if_statement: T_IF T_LPAREN expression T_RPAREN statement  */
#line 464 "parser.y"
    {
        auto if_stmt = new IfStatementNode();
        if_stmt->condition = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        auto then_block = std::make_shared<BlockNode>();
        if ((yyvsp[0].statement_node)) then_block->statements.push_back(std::shared_ptr<StatementNode>((yyvsp[0].statement_node)));
        if_stmt->thenBlock = then_block;
        (yyval.statement_node) = if_stmt;
    }
#line 2054 "parser.tab.c"
    break;

  case 64: /* if_statement: T_IF T_LPAREN expression T_RPAREN statement T_ELSE statement  */
#line 473 "parser.y"
    {
        auto if_stmt = new IfStatementNode();
        if_stmt->condition = std::shared_ptr<ExpressionNode>((yyvsp[-4].expression_node));
        auto then_block = std::make_shared<BlockNode>();
        if ((yyvsp[-2].statement_node)) then_block->statements.push_back(std::shared_ptr<StatementNode>((yyvsp[-2].statement_node)));
        if_stmt->thenBlock = then_block;
        auto else_block = std::make_shared<BlockNode>();
        if ((yyvsp[0].statement_node)) else_block->statements.push_back(std::shared_ptr<StatementNode>((yyvsp[0].statement_node)));
        if_stmt->elseBlock = else_block;
        (yyval.statement_node) = if_stmt;
    }
#line 2070 "parser.tab.c"
    break;

  case 65: /* while_statement: T_WHILE T_LPAREN expression T_RPAREN statement  */
#line 488 "parser.y"
    {
        auto while_stmt = new WhileStatementNode();
        while_stmt->condition = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        auto body = std::make_shared<BlockNode>();
        if ((yyvsp[0].statement_node)) body->statements.push_back(std::shared_ptr<StatementNode>((yyvsp[0].statement_node)));
        while_stmt->body = body;
        (yyval.statement_node) = while_stmt;
    }
#line 2083 "parser.tab.c"
    break;

  case 66: /* for_statement: T_FOR T_LPAREN for_init T_SEMICOLON expression T_SEMICOLON for_update T_RPAREN statement  */
#line 500 "parser.y"
    {
        auto for_stmt = new ForStatementNode();
        for_stmt->initialization = std::shared_ptr<StatementNode>((yyvsp[-6].statement_node));
        for_stmt->condition = std::shared_ptr<ExpressionNode>((yyvsp[-4].expression_node));
        for_stmt->update = std::shared_ptr<StatementNode>((yyvsp[-2].statement_node));
        auto body = std::make_shared<BlockNode>();
        if ((yyvsp[0].statement_node)) body->statements.push_back(std::shared_ptr<StatementNode>((yyvsp[0].statement_node)));
        for_stmt->body = body;
        (yyval.statement_node) = for_stmt;
    }
#line 2098 "parser.tab.c"
    break;

  case 67: /* for_init: %empty  */
#line 513 "parser.y"
           { (yyval.statement_node) = nullptr; }
#line 2104 "parser.tab.c"
    break;

  case 68: /* for_init: variable_declaration  */
#line 514 "parser.y"
                           { (yyval.statement_node) = (yyvsp[0].var_decl_node); }
#line 2110 "parser.tab.c"
    break;

  case 69: /* for_init: expression  */
#line 515 "parser.y"
                 { 
        auto assign = new AssignmentNode();
        assign->value = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.statement_node) = assign;
    }
#line 2120 "parser.tab.c"
    break;

  case 70: /* for_update: %empty  */
#line 523 "parser.y"
           { (yyval.statement_node) = nullptr; }
#line 2126 "parser.tab.c"
    break;

  case 71: /* for_update: expression  */
#line 524 "parser.y"
                 { 
        auto assign = new AssignmentNode();
        assign->value = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.statement_node) = assign;
    }
#line 2136 "parser.tab.c"
    break;

  case 72: /* do_while_statement: T_DO statement T_WHILE T_LPAREN expression T_RPAREN T_SEMICOLON  */
#line 533 "parser.y"
    {
        auto do_while = new DoWhileStatementNode();
        auto body = std::make_shared<BlockNode>();
        if ((yyvsp[-5].statement_node)) body->statements.push_back(std::shared_ptr<StatementNode>((yyvsp[-5].statement_node)));
        do_while->body = body;
        do_while->condition = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        (yyval.statement_node) = do_while;
    }
#line 2149 "parser.tab.c"
    break;

  case 73: /* switch_statement: T_SWITCH T_LPAREN expression T_RPAREN T_LBRACE case_list default_case T_RBRACE  */
#line 545 "parser.y"
    {
        auto switch_stmt = new SwitchStatementNode();
        switch_stmt->expression = std::shared_ptr<ExpressionNode>((yyvsp[-5].expression_node));
        if ((yyvsp[-2].case_list)) {
            switch_stmt->cases = *(yyvsp[-2].case_list);
            delete (yyvsp[-2].case_list);
        }
        if ((yyvsp[-1].default_node)) switch_stmt->defaultCase = std::shared_ptr<DefaultStatementNode>((yyvsp[-1].default_node));
        (yyval.statement_node) = switch_stmt;
    }
#line 2164 "parser.tab.c"
    break;

  case 74: /* case_list: %empty  */
#line 558 "parser.y"
           { (yyval.case_list) = new std::vector<std::shared_ptr<CaseStatementNode>>(); }
#line 2170 "parser.tab.c"
    break;

  case 75: /* case_list: case_list case_statement  */
#line 560 "parser.y"
    {
        (yyvsp[-1].case_list)->push_back(std::shared_ptr<CaseStatementNode>((yyvsp[0].case_node)));
        (yyval.case_list) = (yyvsp[-1].case_list);
    }
#line 2179 "parser.tab.c"
    break;

  case 76: /* case_statement: T_CASE expression T_COLON statement_list  */
#line 568 "parser.y"
    {
        auto case_stmt = new CaseStatementNode();
        case_stmt->value = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        if ((yyvsp[0].stmt_list)) {
            case_stmt->statements = *(yyvsp[0].stmt_list);
            delete (yyvsp[0].stmt_list);
        }
        (yyval.case_node) = case_stmt;
    }
#line 2193 "parser.tab.c"
    break;

  case 77: /* default_case: %empty  */
#line 580 "parser.y"
           { (yyval.default_node) = nullptr; }
#line 2199 "parser.tab.c"
    break;

  case 78: /* default_case: T_DEFAULT T_COLON statement_list  */
#line 582 "parser.y"
    {
        auto default_stmt = new DefaultStatementNode();
        if ((yyvsp[0].stmt_list)) {
            default_stmt->statements = *(yyvsp[0].stmt_list);
            delete (yyvsp[0].stmt_list);
        }
        (yyval.default_node) = default_stmt;
    }
#line 2212 "parser.tab.c"
    break;

  case 79: /* return_statement: T_RETURN T_SEMICOLON  */
#line 594 "parser.y"
    {
        (yyval.statement_node) = new ReturnStatementNode();
    }
#line 2220 "parser.tab.c"
    break;

  case 80: /* return_statement: T_RETURN expression T_SEMICOLON  */
#line 598 "parser.y"
    {
        auto return_stmt = new ReturnStatementNode();
        return_stmt->expression = std::shared_ptr<ExpressionNode>((yyvsp[-1].expression_node));
        (yyval.statement_node) = return_stmt;
    }
#line 2230 "parser.tab.c"
    break;

  case 81: /* break_statement: T_BREAK T_SEMICOLON  */
#line 606 "parser.y"
                        { (yyval.statement_node) = new BreakStatementNode(); }
#line 2236 "parser.tab.c"
    break;

  case 82: /* continue_statement: T_CONTINUE T_SEMICOLON  */
#line 610 "parser.y"
                           { (yyval.statement_node) = new ContinueStatementNode(); }
#line 2242 "parser.tab.c"
    break;

  case 83: /* print_statement: T_PRINT expression T_SEMICOLON  */
#line 615 "parser.y"
    {
        auto print_stmt = new PrintStatementNode();
        print_stmt->expression = std::shared_ptr<ExpressionNode>((yyvsp[-1].expression_node));
        (yyval.statement_node) = print_stmt;
    }
#line 2252 "parser.tab.c"
    break;

  case 84: /* expression_statement: expression T_SEMICOLON  */
#line 624 "parser.y"
    {
        auto assign = new AssignmentNode();
        assign->value = std::shared_ptr<ExpressionNode>((yyvsp[-1].expression_node));
        (yyval.statement_node) = assign;
    }
#line 2262 "parser.tab.c"
    break;

  case 85: /* expression: assignment_expression  */
#line 632 "parser.y"
                          { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2268 "parser.tab.c"
    break;

  case 86: /* assignment_expression: ternary_expression  */
#line 636 "parser.y"
                       { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2274 "parser.tab.c"
    break;

  case 87: /* ternary_expression: logical_or_expression  */
#line 640 "parser.y"
                          { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2280 "parser.tab.c"
    break;

  case 88: /* ternary_expression: logical_or_expression T_QUESTION expression T_COLON ternary_expression  */
#line 642 "parser.y"
    {
        auto ternary = new TernaryNode();
        ternary->condition = std::shared_ptr<ExpressionNode>((yyvsp[-4].expression_node));
        ternary->trueValue = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        ternary->falseValue = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = ternary;
    }
#line 2292 "parser.tab.c"
    break;

  case 89: /* logical_or_expression: logical_and_expression  */
#line 652 "parser.y"
                           { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2298 "parser.tab.c"
    break;

  case 90: /* logical_or_expression: logical_or_expression T_OR logical_and_expression  */
#line 654 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "||";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2310 "parser.tab.c"
    break;

  case 91: /* logical_and_expression: bitwise_or_expression  */
#line 664 "parser.y"
                          { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2316 "parser.tab.c"
    break;

  case 92: /* logical_and_expression: logical_and_expression T_AND bitwise_or_expression  */
#line 666 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "&&";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2328 "parser.tab.c"
    break;

  case 93: /* bitwise_or_expression: bitwise_xor_expression  */
#line 676 "parser.y"
                           { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2334 "parser.tab.c"
    break;

  case 94: /* bitwise_or_expression: bitwise_or_expression T_BIT_OR bitwise_xor_expression  */
#line 678 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "|";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2346 "parser.tab.c"
    break;

  case 95: /* bitwise_xor_expression: bitwise_and_expression  */
#line 688 "parser.y"
                           { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2352 "parser.tab.c"
    break;

  case 96: /* bitwise_xor_expression: bitwise_xor_expression T_BIT_XOR bitwise_and_expression  */
#line 690 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "^";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2364 "parser.tab.c"
    break;

  case 97: /* bitwise_and_expression: equality_expression  */
#line 700 "parser.y"
                        { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2370 "parser.tab.c"
    break;

  case 98: /* bitwise_and_expression: bitwise_and_expression T_BIT_AND equality_expression  */
#line 702 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "&";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2382 "parser.tab.c"
    break;

  case 99: /* equality_expression: relational_expression  */
#line 712 "parser.y"
                          { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2388 "parser.tab.c"
    break;

  case 100: /* equality_expression: equality_expression T_EQUAL relational_expression  */
#line 714 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "==";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2400 "parser.tab.c"
    break;

  case 101: /* equality_expression: equality_expression T_NOT_EQUAL relational_expression  */
#line 722 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "!=";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2412 "parser.tab.c"
    break;

  case 102: /* relational_expression: shift_expression  */
#line 732 "parser.y"
                     { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2418 "parser.tab.c"
    break;

  case 103: /* relational_expression: relational_expression T_GREATER_THAN shift_expression  */
#line 734 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = ">";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2430 "parser.tab.c"
    break;

  case 104: /* relational_expression: relational_expression T_LESS_THAN shift_expression  */
#line 742 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "<";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2442 "parser.tab.c"
    break;

  case 105: /* relational_expression: relational_expression T_GREATER_THAN_EQUAL shift_expression  */
#line 750 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = ">=";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2454 "parser.tab.c"
    break;

  case 106: /* relational_expression: relational_expression T_LESS_THAN_EQUAL shift_expression  */
#line 758 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "<=";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2466 "parser.tab.c"
    break;

  case 107: /* shift_expression: additive_expression  */
#line 768 "parser.y"
                        { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2472 "parser.tab.c"
    break;

  case 108: /* shift_expression: shift_expression T_LEFT_SHIFT additive_expression  */
#line 770 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "<<";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2484 "parser.tab.c"
    break;

  case 109: /* shift_expression: shift_expression T_RIGHT_SHIFT additive_expression  */
#line 778 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = ">>";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2496 "parser.tab.c"
    break;

  case 110: /* additive_expression: multiplicative_expression  */
#line 788 "parser.y"
                              { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2502 "parser.tab.c"
    break;

  case 111: /* additive_expression: additive_expression T_PLUS multiplicative_expression  */
#line 790 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "+";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2514 "parser.tab.c"
    break;

  case 112: /* additive_expression: additive_expression T_MINUS multiplicative_expression  */
#line 798 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "-";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2526 "parser.tab.c"
    break;

  case 113: /* multiplicative_expression: unary_expression  */
#line 808 "parser.y"
                     { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2532 "parser.tab.c"
    break;

  case 114: /* multiplicative_expression: multiplicative_expression T_MULTIPLY unary_expression  */
#line 810 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "*";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2544 "parser.tab.c"
    break;

  case 115: /* multiplicative_expression: multiplicative_expression T_DIVIDE unary_expression  */
#line 818 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "/";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2556 "parser.tab.c"
    break;

  case 116: /* multiplicative_expression: multiplicative_expression T_MODULO unary_expression  */
#line 826 "parser.y"
    {
        auto binary = new BinaryOpNode();
        binary->op = "%";
        binary->left = std::shared_ptr<ExpressionNode>((yyvsp[-2].expression_node));
        binary->right = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = binary;
    }
#line 2568 "parser.tab.c"
    break;

  case 117: /* unary_expression: postfix_expression  */
#line 836 "parser.y"
                       { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2574 "parser.tab.c"
    break;

  case 118: /* unary_expression: T_NOT unary_expression  */
#line 838 "parser.y"
    {
        auto unary = new UnaryOpNode();
        unary->op = "!";
        unary->operand = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = unary;
    }
#line 2585 "parser.tab.c"
    break;

  case 119: /* unary_expression: T_MINUS unary_expression  */
#line 845 "parser.y"
    {
        auto unary = new UnaryOpNode();
        unary->op = "-";
        unary->operand = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = unary;
    }
#line 2596 "parser.tab.c"
    break;

  case 120: /* unary_expression: T_BIT_NOT unary_expression  */
#line 852 "parser.y"
    {
        auto unary = new UnaryOpNode();
        unary->op = "~";
        unary->operand = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = unary;
    }
#line 2607 "parser.tab.c"
    break;

  case 121: /* unary_expression: T_INCREMENT unary_expression  */
#line 859 "parser.y"
    {
        auto unary = new UnaryOpNode();
        unary->op = "++";
        unary->operand = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = unary;
    }
#line 2618 "parser.tab.c"
    break;

  case 122: /* unary_expression: T_DECREMENT unary_expression  */
#line 866 "parser.y"
    {
        auto unary = new UnaryOpNode();
        unary->op = "--";
        unary->operand = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = unary;
    }
#line 2629 "parser.tab.c"
    break;

  case 123: /* unary_expression: T_MULTIPLY unary_expression  */
#line 873 "parser.y"
    {
        auto deref = new DereferenceNode();
        deref->operand = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = deref;
    }
#line 2639 "parser.tab.c"
    break;

  case 124: /* unary_expression: T_BIT_AND unary_expression  */
#line 879 "parser.y"
    {
        auto addr = new AddressOfNode();
        addr->operand = std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node));
        (yyval.expression_node) = addr;
    }
#line 2649 "parser.tab.c"
    break;

  case 125: /* postfix_expression: primary_expression  */
#line 887 "parser.y"
                       { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2655 "parser.tab.c"
    break;

  case 126: /* postfix_expression: postfix_expression T_INCREMENT  */
#line 889 "parser.y"
    {
        auto unary = new UnaryOpNode();
        unary->op = "++";
        unary->operand = std::shared_ptr<ExpressionNode>((yyvsp[-1].expression_node));
        (yyval.expression_node) = unary;
    }
#line 2666 "parser.tab.c"
    break;

  case 127: /* postfix_expression: postfix_expression T_DECREMENT  */
#line 896 "parser.y"
    {
        auto unary = new UnaryOpNode();
        unary->op = "--";
        unary->operand = std::shared_ptr<ExpressionNode>((yyvsp[-1].expression_node));
        (yyval.expression_node) = unary;
    }
#line 2677 "parser.tab.c"
    break;

  case 128: /* postfix_expression: postfix_expression T_LBRACKET expression T_RBRACKET  */
#line 903 "parser.y"
    {
        auto access = new ArrayAccessNode();
        if (auto id = dynamic_cast<IdentifierNode*>((yyvsp[-3].expression_node))) {
            access->arrayName = id->name;
            delete (yyvsp[-3].expression_node);
        }
        access->index = std::shared_ptr<ExpressionNode>((yyvsp[-1].expression_node));
        (yyval.expression_node) = access;
    }
#line 2691 "parser.tab.c"
    break;

  case 129: /* postfix_expression: postfix_expression T_LPAREN argument_list T_RPAREN  */
#line 913 "parser.y"
    {
        auto call = new FunctionCallNode();
        if (auto id = dynamic_cast<IdentifierNode*>((yyvsp[-3].expression_node))) {
            call->functionName = id->name;
            delete (yyvsp[-3].expression_node);
        }
        if ((yyvsp[-1].expr_list)) {
            call->arguments = *(yyvsp[-1].expr_list);
            delete (yyvsp[-1].expr_list);
        }
        (yyval.expression_node) = call;
    }
#line 2708 "parser.tab.c"
    break;

  case 130: /* primary_expression: literal  */
#line 928 "parser.y"
            { (yyval.expression_node) = (yyvsp[0].expression_node); }
#line 2714 "parser.tab.c"
    break;

  case 131: /* primary_expression: T_IDENTIFIER  */
#line 930 "parser.y"
    {
        auto id = new IdentifierNode();
        id->name = *(yyvsp[0].str_val);
        delete (yyvsp[0].str_val);
        (yyval.expression_node) = id;
    }
#line 2725 "parser.tab.c"
    break;

  case 132: /* primary_expression: T_LPAREN expression T_RPAREN  */
#line 936 "parser.y"
                                   { (yyval.expression_node) = (yyvsp[-1].expression_node); }
#line 2731 "parser.tab.c"
    break;

  case 133: /* literal: T_INT_LITERAL  */
#line 941 "parser.y"
    {
        auto lit = new LiteralNode();
        lit->value = *(yyvsp[0].str_val);
        lit->type = "int";
        delete (yyvsp[0].str_val);
        (yyval.expression_node) = lit;
    }
#line 2743 "parser.tab.c"
    break;

  case 134: /* literal: T_FLOAT_LITERAL  */
#line 949 "parser.y"
    {
        auto lit = new LiteralNode();
        lit->value = *(yyvsp[0].str_val);
        lit->type = "float";
        delete (yyvsp[0].str_val);
        (yyval.expression_node) = lit;
    }
#line 2755 "parser.tab.c"
    break;

  case 135: /* literal: T_STRING_LITERAL  */
#line 957 "parser.y"
    {
        auto lit = new LiteralNode();
        lit->value = *(yyvsp[0].str_val);
        lit->type = "string";
        delete (yyvsp[0].str_val);
        (yyval.expression_node) = lit;
    }
#line 2767 "parser.tab.c"
    break;

  case 136: /* literal: T_CHAR_LITERAL  */
#line 965 "parser.y"
    {
        auto lit = new LiteralNode();
        lit->value = *(yyvsp[0].str_val);
        lit->type = "char";
        delete (yyvsp[0].str_val);
        (yyval.expression_node) = lit;
    }
#line 2779 "parser.tab.c"
    break;

  case 137: /* literal: T_TRUE  */
#line 973 "parser.y"
    {
        auto lit = new LiteralNode();
        lit->value = "true";
        lit->type = "bool";
        (yyval.expression_node) = lit;
    }
#line 2790 "parser.tab.c"
    break;

  case 138: /* literal: T_FALSE  */
#line 980 "parser.y"
    {
        auto lit = new LiteralNode();
        lit->value = "false";
        lit->type = "bool";
        (yyval.expression_node) = lit;
    }
#line 2801 "parser.tab.c"
    break;

  case 139: /* literal: T_NULL_LITERAL  */
#line 987 "parser.y"
    {
        auto lit = new LiteralNode();
        lit->value = "null";
        lit->type = "null";
        delete (yyvsp[0].str_val);
        (yyval.expression_node) = lit;
    }
#line 2813 "parser.tab.c"
    break;

  case 140: /* literal: T_HEX_LITERAL  */
#line 995 "parser.y"
    {
        auto lit = new LiteralNode();
        lit->value = *(yyvsp[0].str_val);
        lit->type = "hex";
        delete (yyvsp[0].str_val);
        (yyval.expression_node) = lit;
    }
#line 2825 "parser.tab.c"
    break;

  case 141: /* literal: T_OCTAL_LITERAL  */
#line 1003 "parser.y"
    {
        auto lit = new LiteralNode();
        lit->value = *(yyvsp[0].str_val);
        lit->type = "octal";
        delete (yyvsp[0].str_val);
        (yyval.expression_node) = lit;
    }
#line 2837 "parser.tab.c"
    break;

  case 142: /* literal: T_BINARY_LITERAL  */
#line 1011 "parser.y"
    {
        auto lit = new LiteralNode();
        lit->value = *(yyvsp[0].str_val);
        lit->type = "binary";
        delete (yyvsp[0].str_val);
        (yyval.expression_node) = lit;
    }
#line 2849 "parser.tab.c"
    break;

  case 143: /* argument_list: %empty  */
#line 1021 "parser.y"
           { (yyval.expr_list) = new std::vector<std::shared_ptr<ExpressionNode>>(); }
#line 2855 "parser.tab.c"
    break;

  case 144: /* argument_list: expression  */
#line 1023 "parser.y"
    {
        (yyval.expr_list) = new std::vector<std::shared_ptr<ExpressionNode>>();
        (yyval.expr_list)->push_back(std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node)));
    }
#line 2864 "parser.tab.c"
    break;

  case 145: /* argument_list: argument_list T_COMMA expression  */
#line 1028 "parser.y"
    {
        (yyvsp[-2].expr_list)->push_back(std::shared_ptr<ExpressionNode>((yyvsp[0].expression_node)));
        (yyval.expr_list) = (yyvsp[-2].expr_list);
    }
#line 2873 "parser.tab.c"
    break;


#line 2877 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1034 "parser.y"



void yyerror(const char* msg) {
    extern Lexer* global_lexer;
    std::cerr << "Parse error: " << msg << std::endl;
    if (global_lexer) {
        std::cerr << "At line " << global_lexer->getLineNumber() 
                  << ", column " << global_lexer->getColumnNumber() << std::endl;
    }
}
