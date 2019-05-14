/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lab9.y" /* yacc.c:337  */

/*
	Ivan Nieto
	CS370
	5-3-19
	Lab9
 

	This program declares a grammar that takes ALGOL code and 
	checks it for syntax errors. This program also requires a lex
	program to return tokens that will be checked against the program. 
	
	The lex program returns tokens to this yacc program and then the tokens are 
	checked to be syntacticly correct. 

	The program then creates nodes in the semantic action linking them together to arrive at a  single node returned in the pointer program. 
*/






	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "symtable.h"
#include "ast.h"
#include <stdlib.h>
#include "emit.h"

int yylex();

int GTEMP = 0, goffset = 0, offset = 0, maxoffset = 2, level = 0;
int debugg = 0;
int display = 0;
struct SymbTab *p = NULL;

extern FILE *f;
extern int linecount;//counts lines in lex
enum OPERATORS Cur_Type;

int base, debugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s %d\n", s,linecount);
}
int count = 0; 

#line 124 "y.tab.c" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MYNUM = 258,
    MYID = 259,
    STRING = 260,
    MYINT = 261,
    MYVOID = 262,
    MYBOOLEAN = 263,
    MYTRUE = 264,
    MYFALSE = 265,
    MYBEG = 266,
    MYEND = 267,
    MYIF = 268,
    MYTHEN = 269,
    MYELSE = 270,
    MYWHILE = 271,
    MYDO = 272,
    MYRETURN = 273,
    MYREAD = 274,
    MYWRITE = 275,
    MYAND = 276,
    MYOR = 277,
    MYNOT = 278,
    EQ = 279,
    LT = 280,
    QT = 281,
    NE = 282
  };
#endif
/* Tokens.  */
#define MYNUM 258
#define MYID 259
#define STRING 260
#define MYINT 261
#define MYVOID 262
#define MYBOOLEAN 263
#define MYTRUE 264
#define MYFALSE 265
#define MYBEG 266
#define MYEND 267
#define MYIF 268
#define MYTHEN 269
#define MYELSE 270
#define MYWHILE 271
#define MYDO 272
#define MYRETURN 273
#define MYREAD 274
#define MYWRITE 275
#define MYAND 276
#define MYOR 277
#define MYNOT 278
#define EQ 279
#define LT 280
#define QT 281
#define NE 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 60 "lab9.y" /* yacc.c:352  */

int value;
char *string;
struct ASTnodetype *node;
enum ASTtype op;
enum OPERATORS operator;

#line 229 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

#define YYUNDEFTOK  2
#define YYMAXUTOK   282

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    39,    37,    31,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      35,    34,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    85,    86,    91,    92,    95,   114,   130,
     145,   160,   179,   180,   181,   186,   202,   186,   230,   231,
     235,   236,   240,   259,   280,   280,   302,   303,   308,   309,
     313,   314,   315,   316,   317,   318,   319,   320,   324,   327,
     333,   340,   349,   357,   358,   361,   364,   365,   373,   395,
     399,   424,   453,   456,   479,   480,   481,   482,   483,   484,
     488,   490,   513,   514,   518,   520,   543,   544,   545,   546,
     549,   551,   555,   557,   559,   562,   565,   575,   609,   610,
     613,   621
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MYNUM", "MYID", "STRING", "MYINT",
  "MYVOID", "MYBOOLEAN", "MYTRUE", "MYFALSE", "MYBEG", "MYEND", "MYIF",
  "MYTHEN", "MYELSE", "MYWHILE", "MYDO", "MYRETURN", "MYREAD", "MYWRITE",
  "MYAND", "MYOR", "MYNOT", "EQ", "LT", "QT", "NE", "';'", "'['", "']'",
  "','", "'('", "')'", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "$accept", "P", "DECLIST", "DEC", "VARDEC", "VARLIST", "TYPESPEC",
  "FUNDEC", "$@1", "$@2", "PARAMS", "PARAMLIST", "PARAM", "COMPSTMT",
  "$@3", "LOCALDEC", "STATELIST", "STATE", "EXPSTMT", "SELSTMT",
  "ITERSTMT", "RETURNSTMT", "READSTMT", "WRITESTMT", "ASSSTMT", "EXP",
  "VAR", "SIMEXP", "RELOP", "ADDEXP", "ADDOP", "TERM", "MULTOP", "FACTOR",
  "CALL", "ARGS", "ARGLIST", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    59,    91,
      93,    44,    40,    41,    61,    60,    62,    43,    45,    42,
      47
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      63,   -53,   -53,   -53,    34,   -53,    63,   -53,    37,   -53,
     -53,   -53,    62,    20,    49,    76,   -53,   -53,    36,   -10,
     -53,    89,    53,    48,    79,    59,   -53,    55,    76,    69,
     -53,    63,   -53,    70,    88,   -53,   -53,   -53,   -53,    63,
      63,    76,    19,   -53,   -53,   -19,   -53,   -53,    50,    50,
       8,    97,    40,    50,   -53,    50,   -53,    90,    19,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,    75,    71,   -53,    52,
     -15,   -53,   -53,    50,    50,    92,   -53,    87,   -53,    80,
      78,    81,    82,    83,   -53,    84,   -53,   -53,   -53,    50,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,    50,    50,
     -53,   -53,   -53,   -53,    50,    85,    91,    86,   -53,    19,
      19,   -53,   -53,   -53,   -53,   -53,    93,   -23,   -15,   -53,
     -53,    50,   -53,    98,   -53,   -53,   -53,    19,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    14,     0,     2,     3,     5,     0,     6,
       1,     4,     8,     0,     0,     0,    15,     7,     0,     8,
      10,     0,     9,    13,     0,     0,    19,    21,     0,    22,
      16,     0,    11,     0,     0,    20,    23,    24,    17,    27,
      27,     0,    29,    26,    71,    50,    74,    75,     0,     0,
       0,     0,     0,     0,    39,     0,    31,     0,    29,    30,
      32,    33,    35,    36,    37,    34,     0,    72,    49,    52,
      60,    64,    73,     0,    79,     0,    72,     0,    43,     0,
      50,     0,     0,     0,    76,     0,    25,    28,    38,     0,
      58,    57,    54,    59,    55,    56,    62,    63,     0,     0,
      68,    69,    66,    67,     0,     0,    80,     0,    78,     0,
       0,    44,    45,    47,    46,    70,     0,    53,    61,    65,
      51,     0,    77,    40,    42,    48,    81,     0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   106,   -53,    22,     5,    25,   -53,   -53,   -53,
     -53,    94,   -53,    95,   -53,    74,    58,   -52,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -47,   -42,    29,   -53,    26,
     -53,    21,   -53,   -49,   -53,   -53,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    21,    34,
      25,    26,    27,    56,    39,    42,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    76,    68,    98,    69,
      99,    70,   104,    71,    72,   107,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    75,    77,    79,    84,    83,   100,   101,    85,    81,
      73,    44,    45,    74,    96,    97,    67,    46,    47,    14,
      20,    15,    44,    45,   102,   103,   105,   106,    46,    47,
      37,    53,    48,    32,    10,    49,    78,    50,    51,    52,
      55,    12,    53,    44,    45,    82,    24,    54,    17,    46,
      47,    55,    18,    44,    45,   119,    24,   123,   124,    46,
      47,    40,    40,    53,    41,    41,    22,    67,    67,     1,
       2,     3,    55,    53,   106,   128,    90,    91,    92,    93,
      19,   -18,    55,    29,    28,    67,    31,    94,    95,    96,
      97,    14,    30,    15,    16,     1,    23,     3,    33,    37,
      36,    80,    86,    88,   110,    89,   109,    73,   111,   112,
     113,   114,    11,   127,    43,   120,    87,   115,   116,   122,
     118,   125,   121,   126,   117,    35,     0,     0,     0,    38
};

static const yytype_int8 yycheck[] =
{
      42,    48,    49,    50,    53,    52,    21,    22,    55,    51,
      29,     3,     4,    32,    37,    38,    58,     9,    10,    29,
      15,    31,     3,     4,    39,    40,    73,    74,     9,    10,
      11,    23,    13,    28,     0,    16,    28,    18,    19,    20,
      32,     4,    23,     3,     4,     5,    21,    28,    28,     9,
      10,    32,     3,     3,     4,   104,    31,   109,   110,     9,
      10,    39,    40,    23,    39,    40,    30,   109,   110,     6,
       7,     8,    32,    23,   121,   127,    24,    25,    26,    27,
       4,    33,    32,     4,    31,   127,    31,    35,    36,    37,
      38,    29,    33,    31,    32,     6,     7,     8,    29,    11,
      30,     4,    12,    28,    17,    34,    14,    29,    28,    28,
      28,    28,     6,    15,    40,    30,    58,    33,    89,    33,
      99,    28,    31,   121,    98,    31,    -1,    -1,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,    42,    43,    44,    45,    47,    48,
       0,    43,     4,    46,    29,    31,    32,    28,     3,     4,
      46,    49,    30,     7,    47,    51,    52,    53,    31,     4,
      33,    31,    46,    29,    50,    52,    30,    11,    54,    55,
      45,    47,    56,    56,     3,     4,     9,    10,    13,    16,
      18,    19,    20,    23,    28,    32,    54,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    70,
      72,    74,    75,    29,    32,    66,    67,    66,    28,    66,
       4,    67,     5,    66,    74,    66,    12,    57,    28,    34,
      24,    25,    26,    27,    35,    36,    37,    38,    69,    71,
      21,    22,    39,    40,    73,    66,    66,    76,    77,    14,
      17,    28,    28,    28,    28,    33,    68,    70,    72,    74,
      30,    31,    33,    58,    58,    28,    77,    15,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      46,    46,    47,    47,    47,    49,    50,    48,    51,    51,
      52,    52,    53,    53,    55,    54,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    62,    62,    63,    64,    64,    65,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    75,    76,    76,
      77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     0,     8,     1,     1,
       3,     1,     2,     4,     0,     5,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       4,     6,     4,     2,     3,     3,     3,     3,     4,     1,
       1,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     4,     1,     0,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 82 "lab9.y" /* yacc.c:1652  */
    {program = (yyvsp[0].node);}
#line 1415 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 85 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1421 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 87 "lab9.y" /* yacc.c:1652  */
    {(yyvsp[-1].node)->next = (yyvsp[0].node);
				(yyval.node) = (yyvsp[-1].node);}
#line 1428 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 91 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1434 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 92 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node); }
#line 1440 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 95 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In VARDEC\n");
                               (yyval.node) = (yyvsp[-1].node);
                               struct ASTnodetype *p = (yyvsp[-1].node);
                               
                               //iterating through the varlist and 
                               //setting the type of the variables
                               //now that we have seen the type.
                               while(p != NULL){
                                    p->operator=(yyvsp[-2].operator);
                                    p->symbol->Type=(yyvsp[-2].operator);
                                    p->symType=(yyvsp[-2].operator);
                                    
                                    p = p->s1;
                               }//end while
                               
                               }
#line 1461 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 114 "lab9.y" /* yacc.c:1652  */
    { if(debugg)printf("In VARLIST 1\n");
                
                               //var cannot already be in the symtable
                               if(Search((yyvsp[0].string), level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", (yyvsp[0].string));
                               exit(1);
                               }//end if

                               (yyval.node) = ASTCreateNode(VARDEC);
                               (yyval.node)->name=(yyvsp[0].string);
                               //Inseting the var into the symtable and setting the 
                               //SymbTab pointer in the ASTnodetype to the returned 
                               //SymbTab from insert.
                               (yyval.node)->symbol = Insert((yyval.node)->name, 0, 0, level, 1, offset, (yyval.node));
                               offset++;}
#line 1481 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 130 "lab9.y" /* yacc.c:1652  */
    { if(debugg)printf("In VARLIST 2\n");

                               if(Search((yyvsp[-3].string), level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", (yyvsp[-3].string));
                               exit(1);
                               }//end if
                               
                               (yyval.node) = ASTCreateNode(VARDEC);
                               (yyval.node)->name=(yyvsp[-3].string);
                               (yyval.node)->value=(yyvsp[-1].value);
                               
                               (yyval.node)->symbol =Insert((yyvsp[-3].string), 0, 0, level, (yyval.node)->value, offset, (yyval.node));
                               //offset incremented by size of array.
                               offset+=(yyvsp[-1].value);}
#line 1500 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 145 "lab9.y" /* yacc.c:1652  */
    { if(debugg)printf("In VARLIST 3\n");
		
                
                               if(Search((yyvsp[-2].string), level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", (yyvsp[-2].string));
                               exit(1);
                               }//end if
                               
                               (yyval.node) = ASTCreateNode(VARDEC);
                               (yyval.node)->name=(yyvsp[-2].string);
                               (yyval.node)->s1=(yyvsp[0].node);
                               
                               (yyval.node)->symbol =Insert((yyval.node)->name, 0, 0, level, 1, offset, (yyval.node));
                               offset++;}
#line 1519 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 161 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In VARLIST 4\n");


                               if(Search((yyvsp[-5].string), level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", (yyvsp[-5].string));
                               exit(1);
                               }//end if
                               (yyval.node) = ASTCreateNode(VARDEC);
                               (yyval.node)->name=(yyvsp[-5].string); 
                               (yyval.node)->value=(yyvsp[-3].value); 
                               (yyval.node)->s1=(yyvsp[0].node);
                               
                               (yyval.node)->symbol =Insert((yyvsp[-5].string), 0, 0, level, (yyval.node)->value, offset, (yyval.node));
                               offset+=(yyvsp[-3].value);}
#line 1538 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 179 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=INTTYPE; Cur_Type=(yyval.operator);}
#line 1544 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 180 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=VOIDTYPE; Cur_Type=(yyval.operator);}
#line 1550 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 181 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=BOOLTYPE; Cur_Type=(yyval.operator);}
#line 1556 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 186 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In FUNDEC\n");
                               //Saving offset before we go in a level.
                               goffset = offset;
                               offset=2;
                               maxoffset = offset;
                               
                               //error check; a function cannot be declared more than once. 
                               if(Search((yyvsp[-1].string), level, 1) != NULL){
                                   printf("Error, %s already in the symbol table.\n", (yyvsp[-1].string));
                                   exit(1);
                               }//end if
                               
                               //Parameters will be part of the increased level.
                               level++;
                               }
#line 1576 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 202 "lab9.y" /* yacc.c:1652  */
    {level--;Insert((yyvsp[-4].string), (yyvsp[-5].operator), 1 , level, 0, 0, (yyvsp[-1].node));}
#line 1582 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 205 "lab9.y" /* yacc.c:1652  */
    {(yyval.node)=ASTCreateNode(FUNCTIONDEC);
                               (yyval.node)->name=(yyvsp[-6].string);
                               (yyval.node)->operator=(yyvsp[-7].operator);
                               (yyval.node)->s1=(yyvsp[-3].node);
                               (yyval.node)->s2=(yyvsp[0].node);
                               
                               (yyval.node)->symType = (yyvsp[-7].operator);
                               
                               //setting fundecs symbol to the SymbTab of the functions name.
                               (yyval.node)->symbol = Search((yyvsp[-6].string), level, 1);
                               
                               //Saving the params list in the SymbTab so we can check them in function call.
                               (yyval.node)->symbol->fparms = (yyvsp[-3].node);
                               offset-=Delete(1);
                               level=0;
                               offset=goffset;
                               
                                
                               (yyval.node)->value = maxoffset;
                               (yyval.node)->symbol->maxoffset = maxoffset;
                               
                
                               }
#line 1610 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 230 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In PARAMS\n");(yyval.node) = NULL;}
#line 1616 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 231 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In PARAMS\n");(yyval.node) = (yyvsp[0].node); }
#line 1622 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 235 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In PARAMLIST\n");(yyval.node) = (yyvsp[-2].node); (yyval.node)->next=(yyvsp[0].node);}
#line 1628 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 236 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In PARAMLIST\n");(yyval.node) = (yyvsp[0].node);}
#line 1634 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 241 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In PARAM\n");

                               //error check; parameter cant be declared more than once.
                               if(Search((yyvsp[0].string), level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", (yyvsp[0].string));
                               exit(1);
                               }//end if

                               (yyval.node)=ASTCreateNode(PARAM);
                               (yyval.node)->name=(yyvsp[0].string); 
                               (yyval.node)->symType=(yyvsp[-1].operator);

                               //inserting the param in the symtable and setting the SymbTab
                               //pointer in the ASTnodetype to the returned SymbTab from insert.
                               (yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[-1].operator), 0, level, 1, offset, (yyval.node));
                               offset++;
                               
                               }
#line 1657 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 260 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In PARAM\n");
                                  

                               if(Search((yyvsp[-2].string), level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", (yyvsp[-2].string));
                               exit(1);
                               }//end if
				 
				               (yyval.node)=ASTCreateNode(PARAM);
                               (yyval.node)->name=(yyvsp[-2].string); 
                               (yyval.node)->symType=(yyvsp[-3].operator);
                               (yyval.node)->value=-1;
                               
                               (yyval.node)->symbol =Insert((yyval.node)->name, (yyvsp[-3].operator), 0, level ,1, offset, (yyval.node));
                               offset++;}
#line 1677 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 280 "lab9.y" /* yacc.c:1652  */
    {level++;}
#line 1683 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 281 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In COMPSTMT\n");
                               (yyval.node)=ASTCreateNode(BLOCK);
                               (yyval.node)->s1=(yyvsp[-2].node);
                               (yyval.node)->s2=(yyvsp[-1].node);
                               //Printing the symtable after we finish adding all the 
                               //nessasary elements from the COMPSTMT.
                               if(display)Display();

                               //Deleting all the variables that we added to the symtable 
                               //while in the COMPSTMT. Level goes back to what it previously was.
                               if(offset > maxoffset)
                                 maxoffset = offset;
                               
                               
                               offset-=Delete(level);
                               level--;
                                
                               }
#line 1706 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 302 "lab9.y" /* yacc.c:1652  */
    {(yyvsp[-1].node)->next=(yyvsp[0].node); (yyval.node)=(yyvsp[-1].node);}
#line 1712 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 303 "lab9.y" /* yacc.c:1652  */
    {(yyval.node)=NULL;}
#line 1718 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 308 "lab9.y" /* yacc.c:1652  */
    {(yyval.node)=(yyvsp[-1].node); (yyval.node)->next=(yyvsp[0].node);}
#line 1724 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 309 "lab9.y" /* yacc.c:1652  */
    {(yyval.node)=NULL;}
#line 1730 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 313 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1736 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 314 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1742 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 315 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1748 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 316 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1754 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 317 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1760 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 318 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1766 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 319 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1772 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 320 "lab9.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1778 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 324 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In EXPSTMT\n");
                                (yyval.node)=ASTCreateNode(EXPR);(yyval.node)->s1=(yyvsp[-1].node);}
#line 1785 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 327 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In EXPSTMT\n");(yyval.node)=ASTCreateNode(EXPR);(yyval.node)->s1=NULL;}
#line 1791 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 334 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In SELSTMT\n");
                               (yyval.node)=ASTCreateNode(IFSTMT);
                               (yyval.node)->s1=(yyvsp[-2].node);
                               (yyval.node)->s2=ASTCreateNode(IFSTMT1);
                               (yyval.node)->s2->s1=(yyvsp[0].node);}
#line 1801 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 341 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In SELSTMT\n");
                               (yyval.node)=ASTCreateNode(IFSTMT);(yyval.node)->s1=(yyvsp[-4].node);
                               (yyval.node)->s2=ASTCreateNode(IFSTMT1);
                               (yyval.node)->s2->s1=(yyvsp[-2].node);
                               (yyval.node)->s2->s2=(yyvsp[0].node);}
#line 1811 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 350 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In ITERSTMT\n");
                               (yyval.node)=ASTCreateNode(WHILESTMT);
                               (yyval.node)->s1=(yyvsp[-2].node);
                               (yyval.node)->s2=(yyvsp[0].node);}
#line 1820 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 357 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In RETURNSTMT\n");(yyval.node)=ASTCreateNode(myRETURN);}
#line 1826 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 358 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In RETURNSTMT\n");(yyval.node)=ASTCreateNode(myRETURN);(yyval.node)->s1=(yyvsp[-1].node);}
#line 1832 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 361 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In READSTMT\n");(yyval.node)=ASTCreateNode(READ);(yyval.node)->s1=(yyvsp[-1].node);}
#line 1838 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 364 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In WRITESTMT\n");(yyval.node)=ASTCreateNode(WRITE);(yyval.node)->s1=(yyvsp[-1].node);}
#line 1844 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 365 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In WRITESTMT\n");
                                (yyval.node)=ASTCreateNode(WRITE);
                                (yyval.node)->name = (yyvsp[-1].string);
                                
                                }
#line 1854 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 373 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In ASSSTMT\n");
                               
                                
                               //error checking; Both types must match.
                              
                               if((yyvsp[-3].node)->symType != (yyvsp[-1].node)->symType)
                               {
                               printf("Operators for %s and %s do not match line %d\n", (yyvsp[-3].node),(yyvsp[-1].node)->symbol->name, linecount);
                               exit(1);
                               }//end if
                               
                               (yyval.node)=ASTCreateNode(ASST);
                               (yyval.node)->s1=(yyvsp[-3].node);
                               (yyval.node)->s2=(yyvsp[-1].node);
                               
                               (yyval.node)->symbol=Insert(CreateTemp(),(yyvsp[-1].node)->symType, 0,level,1,offset,NULL);
                               offset++;
                               
                               }
#line 1878 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 395 "lab9.y" /* yacc.c:1652  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1884 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 399 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In VAR\n");
                               
                               //checking if the var was already declared. 
                               p = Search((yyvsp[0].string),level, 1);

                               if(p == NULL){
                               printf("ID %s not found.\n", (yyvsp[0].string));
                               exit(1);
                               }//end if
                               
                               
                               if(p->mysize != 1)
                                {
                                   printf("VAR %s is not a scalar.", (yyvsp[0].string));
                                   exit(1);
                                }//end if
                               
                               
                               (yyval.node)=ASTCreateNode(IDENT);
                               (yyval.node)->name=(yyvsp[0].string);
                               //setting VAR's type to id's type.
                               (yyval.node)->symType = p->Type;
                               (yyval.node)->symbol = p;
                                }
#line 1913 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 424 "lab9.y" /* yacc.c:1652  */
    {   if(debugg)printf("In VAR\n");
                               
                    
                               p = Search((yyvsp[-3].string),level, 1);
                               
                               if(p == NULL || p->mysize <= 0){
                               printf("ID %s not found.\n", (yyvsp[-3].string));
                               exit(1);
                               }//end if
                               
                               
                               if(p->mysize < 1)
                                {
                                   printf("VAR %s is not an array.", (yyvsp[-3].string));
                                   exit(1);
                                }//end if
                               
                               
                               
                               (yyval.node)=ASTCreateNode(IDENT);
                               (yyval.node)->name=(yyvsp[-3].string);
                               (yyval.node)->s1=(yyvsp[-1].node);
                               (yyval.node)->symType = p->Type;
                               (yyval.node)->symbol = p;
                               }
#line 1943 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 453 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In SIMEXP\n");(yyval.node)=(yyvsp[0].node);
				}
#line 1950 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 456 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In SIMEXP\n");
                               (yyval.node)=ASTCreateNode(EXPR);//do type checking
                               (yyval.node)->s1=(yyvsp[-2].node);
                               (yyval.node)->s2=(yyvsp[0].node);
                               (yyval.node)->name = CreateTemp();
                               (yyval.node)->operator=(yyvsp[-1].operator);
                               
                               
                               (yyval.node)->symbol = Insert((yyval.node)->name,(yyvsp[-2].node)->symType, 0,level,1,offset,0);
                              offset++;
                               
                               //Both types must match
                               if((yyvsp[-2].node)->symType != (yyvsp[0].node)->symType)				
                               {
                               printf("Operators for %s and %s do not match line %d\n", (yyvsp[-2].node)->symbol->name,(yyvsp[0].node)->symbol->name, linecount);
                               exit(1);
                               }//end if
                               //Set SIMEXP's type to the type of both $1 and $3.
                               (yyval.node)->symType = (yyvsp[-2].node)->symType;
                               }
#line 1975 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 479 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=qt;}
#line 1981 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 480 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=lessthan;}
#line 1987 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 481 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=greaterthan;}
#line 1993 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 482 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=lessq;}
#line 1999 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 483 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=eq;}
#line 2005 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 484 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=notq;}
#line 2011 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 488 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In ADDEXP\n");(yyval.node)=(yyvsp[0].node);
				}
#line 2018 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 491 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In ADDEXP\n");
                               (yyval.node)=ASTCreateNode(EXPR);
                               (yyval.node)->s1=(yyvsp[-2].node);
                               (yyval.node)->s2=(yyvsp[0].node);
                               (yyval.node)->operator=(yyvsp[-1].operator);
                               (yyval.node)->symType = (yyvsp[0].node)->operator;
                               (yyval.node)->name = CreateTemp();
                               
                               
                               (yyval.node)->symbol = Insert((yyval.node)->name,(yyvsp[0].node)->symType, 0,level,1,offset,0);
                               offset++;
                               
                               if((yyvsp[-2].node)->symType != (yyvsp[0].node)->symType)
                               {printf("Operators for %s and %s do not match line %d\n", (yyvsp[-2].node)->symbol->name,(yyvsp[0].node)->symbol->name, linecount);
                               exit(1);}//end if
			
                               (yyval.node)->symType = (yyvsp[0].node)->symType;
                             
                               }
#line 2042 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 513 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=PLUS;}
#line 2048 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 514 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=MINUS;}
#line 2054 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 518 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In TERM\n");(yyval.node)=(yyvsp[0].node);
				}
#line 2061 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 521 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In TERM\n");
                               (yyval.node)=ASTCreateNode(EXPR);
                               (yyval.node)->s1=(yyvsp[-2].node);
                               (yyval.node)->operator=(yyvsp[-1].operator);
                               (yyval.node)->s2=(yyvsp[0].node);
                               (yyval.node)->name = CreateTemp();
                               
                              
                               
                               (yyval.node)->symbol = Insert((yyval.node)->name,(yyvsp[-2].node)->symType, 0,level,1,offset,0);
                               offset++;
                               
                               if((yyvsp[-2].node)->symType != (yyvsp[0].node)->symType)
                               {printf("Operators for %s and %s do not match line %d\n",(yyvsp[-2].node)->symbol->name,(yyvsp[0].node)->symbol->name, linecount);
                               exit(1);}//end if
                                
                               (yyval.node)->symType = (yyvsp[0].node)->symType;			
                              
                               }
#line 2085 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 543 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=MULT;}
#line 2091 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 544 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=DIV;}
#line 2097 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 545 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=AND;}
#line 2103 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 546 "lab9.y" /* yacc.c:1652  */
    {(yyval.operator)=OR;}
#line 2109 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 549 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In FACTOR\n");(yyval.node)=(yyvsp[-1].node);}
#line 2115 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 551 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In FACTOR\n");
                               (yyval.node)=ASTCreateNode(NUMBER);(yyval.node)->value=(yyvsp[0].value);(yyval.node)->operator=INTTYPE;(yyval.node)->symType=INTTYPE;
                               }
#line 2123 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 555 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In FACTOR\n");(yyval.node)=(yyvsp[0].node);}
#line 2129 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 557 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In FACTOR\n");(yyval.node)=(yyvsp[0].node);}
#line 2135 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 559 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In FACTOR\n");(yyval.node)=ASTCreateNode(NUMBER);
                               (yyval.node)->value=1;(yyval.node)->symType=BOOLTYPE;}
#line 2142 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 562 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In FACTOR\n");(yyval.node)=ASTCreateNode(NUMBER);
                               (yyval.node)->value=0;(yyval.node)->symType=BOOLTYPE;}
#line 2149 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 566 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In FACTOR\n");
                               (yyval.node)=ASTCreateNode(EXPR);/*Creating expr node with operator MYNOT*/
                               (yyval.node)->operator=myNOT;
                               (yyval.node)->s1=(yyvsp[0].node);
                               (yyval.node)->symbol = Insert(CreateTemp(),(yyvsp[0].node)->symType, 0,level,1,offset,0);
                              offset++;
                               (yyval.node)->symType=VOIDTYPE;}
#line 2161 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 576 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In CALL\n");
                               
                               struct SymbTab *p = Search((yyvsp[-3].string),level, 1);
                               
                               //Type checking 
                               if(p == NULL){
                               printf("ID %s not found.\n", (yyvsp[-3].string));
                               exit(1);
                               }//end if
				
                               if(p->IsAFunc == 0){
                               printf("Function %s not found.\n",(yyvsp[-3].string));
                               exit(1);
                               }//end if
                                
                               //comparing $3 to the original declaration of $1.
                               if(!compare(p->fparms,(yyvsp[-1].node)))
                                    {
                                    printf("Function call using wrong params.\n");
                                    exit(1);
                                    }//end if
                                
                               (yyval.node)=ASTCreateNode(Call);
                               (yyval.node)->s1=(yyvsp[-1].node);
                               (yyval.node)->name=(yyvsp[-3].string);
                               (yyval.node)->symbol= p;
                               (yyval.node)->symType = p->Type;
                
                
                               }
#line 2196 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 609 "lab9.y" /* yacc.c:1652  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2202 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 610 "lab9.y" /* yacc.c:1652  */
    {(yyval.node)=NULL;}
#line 2208 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 613 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In ARGLIST\n");
                               (yyval.node)=ASTCreateNode(ARG);
                               (yyval.node)->s1=(yyvsp[0].node);
                               (yyval.node)->symType = (yyval.node)->s1->symType;
                               (yyval.node)->symbol = Insert(CreateTemp(),(yyvsp[0].node)->symType, 0,level,1,offset,0);
                              offset++;
                               }
#line 2220 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 621 "lab9.y" /* yacc.c:1652  */
    {if(debugg)printf("In ARGLIST\n");
                                (yyval.node)=ASTCreateNode(ARG);
                                (yyval.node)->s1=(yyvsp[-2].node);
                                (yyval.node)->s2=(yyvsp[0].node);
                                (yyval.node)->symType = (yyval.node)->s1->symType;
                                (yyval.node)->next=(yyvsp[0].node);
                                (yyval.node)->symbol = Insert(CreateTemp(),(yyvsp[-2].node)->symType, 0,level,1,offset,0);
                              offset++;}
#line 2233 "y.tab.c" /* yacc.c:1652  */
    break;


#line 2237 "y.tab.c" /* yacc.c:1652  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
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
  return yyresult;
}
#line 632 "lab9.y" /* yacc.c:1918  */
	/* end of rules, start of program */



int main(int argc, char *argv[])
{ 


    for(int j = 0; j < argc; j++){
    
        if(strcmp(argv[j],"-o") == 0){
        
            printf("%s\n", argv[j+1]); 
            f = fopen(argv[j+1],"w");
            
            
        }//end if
            
        if(strcmp(argv[j], "-d") == 0)
            debugg = 1;
            
    
    }//end for

    if(f == NULL)
      f = fopen("emitOutput.asm", "w");
    
    
    yyparse();
    emitAST(program);
    //Display();
    
    if(debugg)
       ASTprint(1,program);
    
    if(display){
        printf("\n        Final Print");
        Display();
    }//end if 
    
    
    
}
