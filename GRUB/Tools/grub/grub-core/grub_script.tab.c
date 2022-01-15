/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse grub_script_yyparse
#define yylex   grub_script_yylex
#define yyerror grub_script_yyerror
#define yylval  grub_script_yylval
#define yychar  grub_script_yychar
#define yydebug grub_script_yydebug
#define yynerrs grub_script_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     GRUB_PARSER_TOKEN_EOF = 0,
     GRUB_PARSER_TOKEN_BAD = 258,
     GRUB_PARSER_TOKEN_NEWLINE = 259,
     GRUB_PARSER_TOKEN_AND = 260,
     GRUB_PARSER_TOKEN_OR = 261,
     GRUB_PARSER_TOKEN_SEMI2 = 262,
     GRUB_PARSER_TOKEN_PIPE = 263,
     GRUB_PARSER_TOKEN_AMP = 264,
     GRUB_PARSER_TOKEN_SEMI = 265,
     GRUB_PARSER_TOKEN_LBR = 266,
     GRUB_PARSER_TOKEN_RBR = 267,
     GRUB_PARSER_TOKEN_NOT = 268,
     GRUB_PARSER_TOKEN_LSQBR2 = 269,
     GRUB_PARSER_TOKEN_RSQBR2 = 270,
     GRUB_PARSER_TOKEN_LT = 271,
     GRUB_PARSER_TOKEN_GT = 272,
     GRUB_PARSER_TOKEN_CASE = 273,
     GRUB_PARSER_TOKEN_DO = 274,
     GRUB_PARSER_TOKEN_DONE = 275,
     GRUB_PARSER_TOKEN_ELIF = 276,
     GRUB_PARSER_TOKEN_ELSE = 277,
     GRUB_PARSER_TOKEN_ESAC = 278,
     GRUB_PARSER_TOKEN_FI = 279,
     GRUB_PARSER_TOKEN_FOR = 280,
     GRUB_PARSER_TOKEN_IF = 281,
     GRUB_PARSER_TOKEN_IN = 282,
     GRUB_PARSER_TOKEN_SELECT = 283,
     GRUB_PARSER_TOKEN_THEN = 284,
     GRUB_PARSER_TOKEN_UNTIL = 285,
     GRUB_PARSER_TOKEN_WHILE = 286,
     GRUB_PARSER_TOKEN_FUNCTION = 287,
     GRUB_PARSER_TOKEN_NAME = 288,
     GRUB_PARSER_TOKEN_WORD = 289
   };
#endif
/* Tokens.  */
#define GRUB_PARSER_TOKEN_EOF 0
#define GRUB_PARSER_TOKEN_BAD 258
#define GRUB_PARSER_TOKEN_NEWLINE 259
#define GRUB_PARSER_TOKEN_AND 260
#define GRUB_PARSER_TOKEN_OR 261
#define GRUB_PARSER_TOKEN_SEMI2 262
#define GRUB_PARSER_TOKEN_PIPE 263
#define GRUB_PARSER_TOKEN_AMP 264
#define GRUB_PARSER_TOKEN_SEMI 265
#define GRUB_PARSER_TOKEN_LBR 266
#define GRUB_PARSER_TOKEN_RBR 267
#define GRUB_PARSER_TOKEN_NOT 268
#define GRUB_PARSER_TOKEN_LSQBR2 269
#define GRUB_PARSER_TOKEN_RSQBR2 270
#define GRUB_PARSER_TOKEN_LT 271
#define GRUB_PARSER_TOKEN_GT 272
#define GRUB_PARSER_TOKEN_CASE 273
#define GRUB_PARSER_TOKEN_DO 274
#define GRUB_PARSER_TOKEN_DONE 275
#define GRUB_PARSER_TOKEN_ELIF 276
#define GRUB_PARSER_TOKEN_ELSE 277
#define GRUB_PARSER_TOKEN_ESAC 278
#define GRUB_PARSER_TOKEN_FI 279
#define GRUB_PARSER_TOKEN_FOR 280
#define GRUB_PARSER_TOKEN_IF 281
#define GRUB_PARSER_TOKEN_IN 282
#define GRUB_PARSER_TOKEN_SELECT 283
#define GRUB_PARSER_TOKEN_THEN 284
#define GRUB_PARSER_TOKEN_UNTIL 285
#define GRUB_PARSER_TOKEN_WHILE 286
#define GRUB_PARSER_TOKEN_FUNCTION 287
#define GRUB_PARSER_TOKEN_NAME 288
#define GRUB_PARSER_TOKEN_WORD 289




/* Copy the first part of user declarations.  */
#line 20 "script/parser.y"

#include <grub/script_sh.h>
#include <grub/mm.h>
#include <grub/misc.h>
#include <grub/i18n.h>

#define YYFREE          grub_free
#define YYMALLOC        grub_malloc
#define YYLTYPE_IS_TRIVIAL      0
#define YYENABLE_NLS    0

#include "grub_script.tab.h"

#pragma GCC diagnostic ignored "-Wmissing-declarations"



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "script/parser.y"
{
  struct grub_script_cmd *cmd;
  struct grub_script_arglist *arglist;
  struct grub_script_arg *arg;
  char *string;
  struct {
    unsigned offset;
    struct grub_script_mem *memory;
    struct grub_script *scripts;
  };
}
/* Line 193 of yacc.c.  */
#line 203 "grub_script.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 216 "grub_script.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  105

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    14,    16,    17,    19,
      22,    24,    26,    27,    29,    31,    34,    36,    38,    40,
      42,    44,    46,    48,    50,    52,    54,    56,    58,    60,
      62,    64,    66,    68,    70,    72,    74,    75,    81,    82,
      84,    85,    87,    90,    94,    96,    98,   100,   102,   104,
     107,   111,   112,   121,   122,   127,   133,   142,   150,   151,
     162,   163,   172,   173
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    -1,    37,    38,    -1,    39,    -1,    38,
      45,    41,    39,    -1,     1,    -1,    -1,    40,    -1,    39,
       4,    -1,    10,    -1,     4,    -1,    -1,    43,    -1,    41,
      -1,    43,     4,    -1,    33,    -1,    34,    -1,    53,    -1,
      55,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,
      32,    -1,    44,    -1,    -1,    11,    48,    54,    42,    12,
      -1,    -1,    47,    -1,    -1,    51,    -1,    46,    50,    -1,
      44,    50,    49,    -1,    52,    -1,    57,    -1,    60,    -1,
      62,    -1,    64,    -1,    39,    53,    -1,    54,    43,    53,
      -1,    -1,    32,    33,    56,    39,    11,    54,    43,    12,
      -1,    -1,    26,    58,    59,    24,    -1,    54,    43,    29,
      54,    43,    -1,    54,    43,    29,    54,    43,    22,    54,
      43,    -1,    54,    43,    29,    54,    43,    21,    59,    -1,
      -1,    25,    33,    61,    27,    50,    43,    19,    54,    43,
      20,    -1,    -1,    31,    63,    54,    43,    19,    54,    43,
      20,    -1,    -1,    30,    65,    54,    43,    19,    54,    43,
      20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   100,   103,   107,   111,   119,   119,   120,
     122,   123,   125,   125,   126,   127,   130,   131,   134,   135,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   181,   180,   220,   221,
     224,   225,   227,   239,   256,   257,   258,   259,   260,   264,
     268,   275,   274,   302,   301,   311,   315,   319,   326,   325,
     337,   336,   348,   347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end-of-input\"", "error", "$undefined", "GRUB_PARSER_TOKEN_BAD",
  "\"\\n\"", "\"&&\"", "\"||\"", "\";;\"", "\"|\"", "\"&\"", "\";\"",
  "\"{\"", "\"}\"", "\"!\"", "\"[\"", "\"]\"", "\"<\"", "\">\"",
  "\"case\"", "\"do\"", "\"done\"", "\"elif\"", "\"else\"", "\"esac\"",
  "\"fi\"", "\"for\"", "\"if\"", "\"in\"", "\"select\"", "\"then\"",
  "\"until\"", "\"while\"", "\"function\"", "\"name\"", "\"word\"",
  "$accept", "script_init", "@1", "script", "newlines0", "newlines1",
  "delimiter", "delimiters0", "delimiters1", "word", "statement",
  "argument", "block", "@2", "block0", "arguments0", "arguments1",
  "grubcmd", "command", "commands1", "function", "@3", "ifcmd", "@4",
  "ifclause", "forcmd", "@5", "whilecmd", "@6", "untilcmd", "@7", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    37,    36,    38,    38,    38,    39,    39,    40,
      41,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    48,    47,    49,    49,
      50,    50,    51,    52,    53,    53,    53,    53,    53,    54,
      54,    56,    55,    58,    57,    59,    59,    59,    61,    60,
      63,    62,    65,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     4,     1,     0,     1,     2,
       1,     1,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     0,     1,
       0,     1,     2,     3,     1,     1,     1,     1,     1,     2,
       3,     0,     8,     0,     4,     5,     8,     7,     0,    10,
       0,     8,     0,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     6,     3,     4,     8,     0,    53,
      62,    60,     0,    16,    17,    40,     0,    44,    18,    19,
      45,    46,    47,    48,     9,    58,     7,     7,     7,    51,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    40,    38,    41,    11,
      10,     7,     0,     0,     0,     0,     0,     0,     7,    42,
      36,    39,    43,     5,    40,    49,    14,     0,    54,     0,
       0,     0,     7,     0,    15,     7,    50,     7,     7,     7,
      12,     0,     0,     0,     0,     0,     0,    13,     7,    55,
       0,     0,     0,    37,     0,     7,     7,    63,    61,    52,
       0,    57,     0,    59,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,    53,     7,    66,    86,    67,    15,
      16,    46,    61,    72,    62,    47,    48,    17,    76,    54,
      19,    58,    20,    26,    55,    21,    52,    22,    28,    23,
      27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
     -73,     7,    42,   -73,   -73,   182,     9,   -73,   -19,   -73,
     -73,   -73,   -15,   -73,   -73,   172,     6,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   172,    -5,   -73,   -73,
     -73,   -73,    -8,   145,     6,    10,     6,     6,   -73,   -73,
     -73,   -73,   -73,     9,   172,   -73,   -73,    54,   -73,    67,
      77,    11,   -73,     6,   -73,   -73,   -73,   -73,   -73,   -73,
       6,    -2,     6,     6,     6,     6,    14,   155,   -73,    -1,
      95,   110,   120,   -73,     6,   -73,   -73,   -73,   -73,   -73,
     135,   -73,     6,   -73,   155
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   -73,   -73,     2,   -73,    15,   -73,   -45,   -10,
     -73,   -73,   -73,   -73,   -73,   -37,   -73,   -73,     3,   -27,
     -73,   -73,   -73,   -73,   -72,   -73,   -73,   -73,   -73,   -73,
     -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -8
static const yytype_int8 yytable[] =
{
      56,    57,    74,    74,     6,    45,    60,     3,    18,    59,
      49,    69,    70,    24,    25,    24,    50,    88,    29,    64,
      95,    96,    79,   101,     8,     9,    93,    73,    81,    10,
      11,    51,    13,    14,    68,    87,    45,    89,    90,    91,
      92,     0,    -7,     4,     0,    80,    -7,     0,    82,   100,
      83,    84,    85,    63,    45,     0,    65,   104,    74,     0,
      71,    94,     0,     0,     0,     0,     0,    -7,    -7,   102,
       0,    74,    -7,    -7,    -7,    -7,    -7,     0,     0,     8,
       9,    74,     0,    75,    10,    11,    77,    13,    14,     0,
       0,     0,     8,     9,     0,     0,    78,    10,    11,    74,
      13,    14,     8,     9,     0,     0,     0,    10,    11,     0,
      13,    14,     0,     0,    74,    97,     0,     0,     0,     0,
       8,     9,     0,     0,    74,    10,    11,     0,    13,    14,
      98,     0,    99,     0,     0,     8,     9,     0,     0,    74,
      10,    11,     0,    13,    14,     8,     9,     0,     0,    24,
      10,    11,     0,    13,    14,   103,     0,     0,     0,    74,
       8,     9,     0,     0,     0,    10,    11,     0,    13,    14,
       8,     9,     0,     0,     0,    10,    11,     0,    13,    14,
       8,     9,     0,     0,     0,    10,    11,     0,    13,    14,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    13,    14,     8,     9,     0,
       0,     0,    10,    11,    12,    13,    14
};

static const yytype_int8 yycheck[] =
{
      27,    28,     4,     4,     2,    15,    11,     0,     5,    46,
       4,    56,    57,     4,    33,     4,    10,    19,    33,    27,
      21,    22,    11,    95,    25,    26,    12,    64,    73,    30,
      31,    16,    33,    34,    24,    80,    46,    82,    83,    84,
      85,    -1,     0,     1,    -1,    72,     4,    -1,    75,    94,
      77,    78,    79,    51,    64,    -1,    53,   102,     4,    -1,
      58,    88,    -1,    -1,    -1,    -1,    -1,    25,    26,    96,
      -1,     4,    30,    31,    32,    33,    34,    -1,    -1,    25,
      26,     4,    -1,    29,    30,    31,    19,    33,    34,    -1,
      -1,    -1,    25,    26,    -1,    -1,    19,    30,    31,     4,
      33,    34,    25,    26,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    -1,    -1,     4,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    -1,     4,    30,    31,    -1,    33,    34,
      20,    -1,    12,    -1,    -1,    25,    26,    -1,    -1,     4,
      30,    31,    -1,    33,    34,    25,    26,    -1,    -1,     4,
      30,    31,    -1,    33,    34,    20,    -1,    -1,    -1,     4,
      25,    26,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      25,    26,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      25,    26,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    25,    26,    -1,
      -1,    -1,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    37,     0,     1,    38,    39,    40,    25,    26,
      30,    31,    32,    33,    34,    44,    45,    52,    53,    55,
      57,    60,    62,    64,     4,    33,    58,    65,    63,    33,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    44,    46,    50,    51,     4,
      10,    41,    61,    39,    54,    59,    54,    54,    56,    50,
      11,    47,    49,    39,    27,    53,    41,    43,    24,    43,
      43,    39,    48,    50,     4,    29,    53,    19,    19,    11,
      54,    43,    54,    54,    54,    54,    42,    43,    19,    43,
      43,    43,    43,    12,    54,    21,    22,    20,    20,    12,
      43,    59,    54,    20,    43
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (state, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, state)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, state); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct grub_parser_param *state)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, state)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    struct grub_parser_param *state;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (state);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct grub_parser_param *state)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, state)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    struct grub_parser_param *state;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, state);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, struct grub_parser_param *state)
#else
static void
yy_reduce_print (yyvsp, yyrule, state)
    YYSTYPE *yyvsp;
    int yyrule;
    struct grub_parser_param *state;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , state);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, state); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, struct grub_parser_param *state)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, state)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    struct grub_parser_param *state;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (state);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (struct grub_parser_param *state);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (struct grub_parser_param *state)
#else
int
yyparse (state)
    struct grub_parser_param *state;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 100 "script/parser.y"
    { state->err = 0; ;}
    break;

  case 3:
#line 100 "script/parser.y"
    { state->parsed = (yyvsp[(2) - (2)].cmd); state->err = 0; ;}
    break;

  case 4:
#line 104 "script/parser.y"
    {
          (yyval.cmd) = 0;
        ;}
    break;

  case 5:
#line 108 "script/parser.y"
    {
          (yyval.cmd) = grub_script_append_cmd (state, (yyvsp[(1) - (4)].cmd), (yyvsp[(2) - (4)].cmd));
        ;}
    break;

  case 6:
#line 112 "script/parser.y"
    {
          (yyval.cmd) = 0;
          yyerror (state, N_("Incorrect command"));
          yyerrok;
        ;}
    break;

  case 16:
#line 130 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 17:
#line 131 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 18:
#line 134 "script/parser.y"
    { (yyval.cmd) = (yyvsp[(1) - (1)].cmd); ;}
    break;

  case 19:
#line 135 "script/parser.y"
    { (yyval.cmd) = 0;  ;}
    break;

  case 20:
#line 138 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 21:
#line 139 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 22:
#line 140 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 23:
#line 141 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 24:
#line 142 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 25:
#line 143 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 26:
#line 144 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 27:
#line 145 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 28:
#line 146 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 29:
#line 147 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 30:
#line 148 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 31:
#line 149 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 32:
#line 150 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 33:
#line 151 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 34:
#line 152 "script/parser.y"
    { (yyval.arglist) = grub_script_add_arglist (state, 0, (yyvsp[(1) - (1)].arg)); ;}
    break;

  case 35:
#line 153 "script/parser.y"
    { (yyval.arglist) = (yyvsp[(1) - (1)].arglist); ;}
    break;

  case 36:
#line 181 "script/parser.y"
    {
         grub_script_lexer_ref (state->lexerstate);
         (yyval.offset) = grub_script_lexer_record_start (state);
	 (yyval.memory) = grub_script_mem_record (state);

	 /* save currently known scripts.  */
	 (yyval.scripts) = state->scripts;
	 state->scripts = 0;
       ;}
    break;

  case 37:
#line 191 "script/parser.y"
    {
         char *p;
	 struct grub_script_mem *memory;
	 struct grub_script *s = (yyvsp[(2) - (5)].scripts);

	 memory = grub_script_mem_record_stop (state, (yyvsp[(2) - (5)].memory));
         if ((p = grub_script_lexer_record_stop (state, (yyvsp[(2) - (5)].offset))))
	   *grub_strrchr (p, '}') = '\0';

	 (yyval.arg) = grub_script_arg_add (state, 0, GRUB_SCRIPT_ARG_TYPE_BLOCK, p);
	 if (! (yyval.arg) || ! ((yyval.arg)->script = grub_script_create ((yyvsp[(3) - (5)].cmd), memory)))
	   grub_script_mem_free (memory);

	 else {
	   /* attach nested scripts to $$->script as children */
	   (yyval.arg)->script->children = state->scripts;

	   /* restore old scripts; append $$->script to siblings. */
	   state->scripts = (yyvsp[(2) - (5)].scripts) ?: (yyval.arg)->script;
	   if (s) {
	     while (s->next_siblings)
	       s = s->next_siblings;
	     s->next_siblings = (yyval.arg)->script;
	   }
	 }

         grub_script_lexer_deref (state->lexerstate);
       ;}
    break;

  case 38:
#line 220 "script/parser.y"
    { (yyval.arg) = 0; ;}
    break;

  case 39:
#line 221 "script/parser.y"
    { (yyval.arg) = (yyvsp[(1) - (1)].arg); ;}
    break;

  case 40:
#line 224 "script/parser.y"
    { (yyval.arglist) = 0; ;}
    break;

  case 41:
#line 225 "script/parser.y"
    { (yyval.arglist) = (yyvsp[(1) - (1)].arglist); ;}
    break;

  case 42:
#line 228 "script/parser.y"
    {
	      if ((yyvsp[(1) - (2)].arglist) && (yyvsp[(2) - (2)].arglist))
		{
		  (yyvsp[(1) - (2)].arglist)->next = (yyvsp[(2) - (2)].arglist);
		  (yyvsp[(1) - (2)].arglist)->argcount += (yyvsp[(2) - (2)].arglist)->argcount;
		  (yyvsp[(2) - (2)].arglist)->argcount = 0;
		}
	      (yyval.arglist) = (yyvsp[(1) - (2)].arglist);
            ;}
    break;

  case 43:
#line 240 "script/parser.y"
    {
	   struct grub_script_arglist *x = (yyvsp[(2) - (3)].arglist);

	   if ((yyvsp[(3) - (3)].arg))
	     x = grub_script_add_arglist (state, (yyvsp[(2) - (3)].arglist), (yyvsp[(3) - (3)].arg));

           if ((yyvsp[(1) - (3)].arglist) && x) {
             (yyvsp[(1) - (3)].arglist)->next = x;
             (yyvsp[(1) - (3)].arglist)->argcount += x->argcount;
             x->argcount = 0;
           }
           (yyval.cmd) = grub_script_create_cmdline (state, (yyvsp[(1) - (3)].arglist));
         ;}
    break;

  case 44:
#line 256 "script/parser.y"
    { (yyval.cmd) = (yyvsp[(1) - (1)].cmd); ;}
    break;

  case 45:
#line 257 "script/parser.y"
    { (yyval.cmd) = (yyvsp[(1) - (1)].cmd); ;}
    break;

  case 46:
#line 258 "script/parser.y"
    { (yyval.cmd) = (yyvsp[(1) - (1)].cmd); ;}
    break;

  case 47:
#line 259 "script/parser.y"
    { (yyval.cmd) = (yyvsp[(1) - (1)].cmd); ;}
    break;

  case 48:
#line 260 "script/parser.y"
    { (yyval.cmd) = (yyvsp[(1) - (1)].cmd); ;}
    break;

  case 49:
#line 265 "script/parser.y"
    {
             (yyval.cmd) = grub_script_append_cmd (state, 0, (yyvsp[(2) - (2)].cmd));
           ;}
    break;

  case 50:
#line 269 "script/parser.y"
    {
	     (yyval.cmd) = grub_script_append_cmd (state, (yyvsp[(1) - (3)].cmd), (yyvsp[(3) - (3)].cmd));
           ;}
    break;

  case 51:
#line 275 "script/parser.y"
    {
            grub_script_lexer_ref (state->lexerstate);
            state->func_mem = grub_script_mem_record (state);

	    (yyval.scripts) = state->scripts;
	    state->scripts = 0;
          ;}
    break;

  case 52:
#line 283 "script/parser.y"
    {
            struct grub_script *script;
            state->func_mem = grub_script_mem_record_stop (state,
                                                           state->func_mem);
            script = grub_script_create ((yyvsp[(6) - (8)].cmd), state->func_mem);
            if (! script)
	      grub_script_mem_free (state->func_mem);
	    else {
	      script->children = state->scripts;
	      if (!grub_script_function_create ((yyvsp[(2) - (8)].arg), script))
		grub_script_free (script);
	    }

	    state->scripts = (yyvsp[(3) - (8)].scripts);
            grub_script_lexer_deref (state->lexerstate);
          ;}
    break;

  case 53:
#line 302 "script/parser.y"
    {
	  grub_script_lexer_ref (state->lexerstate);
	;}
    break;

  case 54:
#line 306 "script/parser.y"
    {
	  (yyval.cmd) = (yyvsp[(3) - (4)].cmd);
	  grub_script_lexer_deref (state->lexerstate);
	;}
    break;

  case 55:
#line 312 "script/parser.y"
    {
	    (yyval.cmd) = grub_script_create_cmdif (state, (yyvsp[(1) - (5)].cmd), (yyvsp[(4) - (5)].cmd), 0);
	  ;}
    break;

  case 56:
#line 316 "script/parser.y"
    {
	    (yyval.cmd) = grub_script_create_cmdif (state, (yyvsp[(1) - (8)].cmd), (yyvsp[(4) - (8)].cmd), (yyvsp[(7) - (8)].cmd));
	  ;}
    break;

  case 57:
#line 320 "script/parser.y"
    {
	    (yyval.cmd) = grub_script_create_cmdif (state, (yyvsp[(1) - (7)].cmd), (yyvsp[(4) - (7)].cmd), (yyvsp[(7) - (7)].cmd));
	  ;}
    break;

  case 58:
#line 326 "script/parser.y"
    {
	  grub_script_lexer_ref (state->lexerstate);
        ;}
    break;

  case 59:
#line 330 "script/parser.y"
    {
	  (yyval.cmd) = grub_script_create_cmdfor (state, (yyvsp[(2) - (10)].arg), (yyvsp[(5) - (10)].arglist), (yyvsp[(8) - (10)].cmd));
	  grub_script_lexer_deref (state->lexerstate);
	;}
    break;

  case 60:
#line 337 "script/parser.y"
    {
	    grub_script_lexer_ref (state->lexerstate);
          ;}
    break;

  case 61:
#line 341 "script/parser.y"
    {
	    (yyval.cmd) = grub_script_create_cmdwhile (state, (yyvsp[(3) - (8)].cmd), (yyvsp[(6) - (8)].cmd), 0);
	    grub_script_lexer_deref (state->lexerstate);
	  ;}
    break;

  case 62:
#line 348 "script/parser.y"
    {
	    grub_script_lexer_ref (state->lexerstate);
          ;}
    break;

  case 63:
#line 352 "script/parser.y"
    {
	    (yyval.cmd) = grub_script_create_cmdwhile (state, (yyvsp[(3) - (8)].cmd), (yyvsp[(6) - (8)].cmd), 1);
	    grub_script_lexer_deref (state->lexerstate);
	  ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1915 "grub_script.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (state, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (state, yymsg);
	  }
	else
	  {
	    yyerror (state, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, state);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp, state);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (state, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, state);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, state);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



