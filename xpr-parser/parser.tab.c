/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <bits/stdc++.h>
	using namespace std;

	// #include "ast.h"
	#include "visitable_nodes.h"

	extern "C" int yylex();
	extern "C" int yyparse();
	extern "C" int yyerror(char *s);

	ProgramNode *strt = NULL;

  	class IRfactory* irf = new IRfactory();
  	extern Module *module;

	extern FILE *yyin;
	#define YYDEBUG 1

	

#line 90 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOLEAN = 258,
    BREAK = 259,
    CALLOUT = 260,
    CLASS = 261,
    CONTINUE = 262,
    ELSE = 263,
    FALSE = 264,
    FOR = 265,
    INT = 266,
    IF = 267,
    RETURN = 268,
    TRUE = 269,
    VOID = 270,
    EOL = 271,
    PROGRAM = 272,
    PLUSEQ = 273,
    MINUSEQ = 274,
    AND = 275,
    OR = 276,
    EE = 277,
    NE = 278,
    LE = 279,
    GE = 280,
    DOUBLEQ = 281,
    SINGLEQ = 282,
    STRINGLIT = 283,
    CHARLIT = 284,
    DECLIT = 285,
    HEXLIT = 286,
    ID = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "parser.y" /* yacc.c:355  */

	int ival;
	char* sval;
	char cval;

	ProgramNode* 		     	prgnodetype;

	vector<FieldDeclNode*>*  	fieldDecType;

	MethodDeclNode* 	     	methodDecType;
	vector<MethodDeclNode*>* 	methodDecListType;

	Identifier*			     	idType;
	vector<Identifier*>*	 	idListType;


	IntNode* 					intlitType;
	MethodArgsNode* 			methodArgType;
	vector<MethodArgsNode*>* 	methodArgsType;


	VarDeclNode* 				varDeclSingleType;
	vector<VarDeclNode*>* 		varDeclType;

	LiteralNode*				literalType;
	BoolNode* 					boollitType;

	MethodNode* 			methodcallType;


	BlockNode*					blockType;
	LocationNode* 				locationType;

	UnaryNode* 					unrType;
	BinaryNode* 				bnrType;

	ExpressionNode* 			exprType;
	vector<ExpressionNode*>* 	argumentsType;

	StringNode* 				stringlitType;
	CharNode* 					charlitType;


	CalloutArgsNode* 			calloutArgsType;
	vector<CalloutArgsNode*>* 	calloutArgsListType;

	StatementNode* 				statementContentsType;
	vector<StatementNode*>*		statementType;

#line 213 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 244 "parser.tab.c" /* yacc.c:358  */

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
# elif ! defined YYSIZE_T
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   492

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,     2,     2,    33,     2,     2,
      42,    43,    31,    29,    48,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
      25,    18,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      15,    16,    17,    19,    20,    21,    22,    23,    24,    27,
      28,    35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   183,   183,   184,   185,   186,   189,   191,   195,   199,
     203,   207,   215,   216,   217,   218,   220,   223,   227,   230,
     233,   237,   238,   239,   240,   243,   247,   252,   256,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   277,   282,   290,   291,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   317,   318,   322,   325,   326,   327,
     328,   331,   336,   341,   347,   357,   362,   368,   369,   370,
     373,   374,   377,   378,   381,   384
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLEAN", "BREAK", "CALLOUT", "CLASS",
  "CONTINUE", "ELSE", "FALSE", "FOR", "INT", "IF", "RETURN", "TRUE",
  "VOID", "EOL", "PROGRAM", "'='", "PLUSEQ", "MINUSEQ", "AND", "OR", "EE",
  "NE", "'<'", "'>'", "LE", "GE", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'",
  "DOUBLEQ", "SINGLEQ", "STRINGLIT", "CHARLIT", "DECLIT", "HEXLIT", "ID",
  "'('", "')'", "'['", "']'", "'{'", "'}'", "','", "';'", "$accept",
  "classBegin", "fieldDec", "fieldArgs", "methodDec", "methodDecList",
  "methodArg", "methodArgs", "block", "varDecl", "blockVars",
  "statementContents", "statement", "type", "expr", "location",
  "methodname", "methodcall", "calloutArgsList", "arguments", "literal",
  "intlit", "boollit", "stringlit", "charlit", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    61,   273,
     274,   275,   276,   277,   278,    60,    62,   279,   280,    43,
      45,    42,    47,    37,    33,   281,   282,   283,   284,   285,
     286,   287,    40,    41,    91,    93,   123,   125,    44,    59
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    21,    54,    10,  -123,    38,  -123,  -123,    30,  -123,
      73,  -123,    75,    52,    37,  -123,    86,    52,  -123,  -123,
      61,   -35,    43,    44,  -123,    56,    64,    93,    -8,    68,
    -123,    66,    62,    71,    74,  -123,    66,    78,  -123,  -123,
      81,   -11,  -123,    70,  -123,     8,    66,  -123,  -123,    66,
      84,    69,    85,    88,    94,    92,    89,   -28,  -123,  -123,
     140,  -123,   144,   105,   121,   113,   111,  -123,  -123,  -123,
      68,  -123,   127,  -123,   145,   215,  -123,  -123,   215,   215,
     135,   215,  -123,   237,  -123,  -123,  -123,  -123,  -123,  -123,
     215,  -123,   154,  -123,  -123,  -123,    51,   215,   215,   215,
     163,  -123,  -123,   128,   -13,   215,   426,   138,  -123,   139,
     449,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,  -123,   401,  -123,   133,     8,   250,
     279,   292,  -123,   321,   136,   141,  -123,   202,   334,    66,
    -123,  -123,   264,   264,   304,   304,   341,   341,   341,   341,
     138,   138,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,   215,  -123,  -123,   362,   137,   130,   215,   174,  -123,
     202,  -123,   202,   375,    66,  -123,  -123,  -123,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    44,    43,     0,     2,
       0,    16,     0,     0,     0,     5,     0,     0,     4,    17,
       0,     8,     0,     0,     3,     0,     0,     0,     0,     0,
       6,     0,    19,     0,     0,     7,     0,     0,    80,    81,
       0,     8,     9,     0,    15,     0,     0,    18,    13,     0,
      10,     0,     0,     0,     0,     0,     0,    64,    21,    40,
       0,    41,     0,     0,     0,     0,     0,    20,    14,    12,
       0,    38,     0,    39,     0,     0,    83,    82,     0,     0,
       0,     0,    36,     0,    45,    46,    47,    77,    78,    79,
       0,    22,     0,    23,    42,    27,     0,     0,     0,     0,
       0,    32,    11,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,    24,     0,    25,     0,
       0,     0,    67,    75,     0,     0,    70,     0,     0,     0,
      85,    63,    61,    62,    59,    60,    55,    56,    57,    58,
      53,    54,    50,    51,    52,    65,    28,    26,    29,    30,
      31,     0,    68,    84,    71,     0,    72,     0,    33,    76,
       0,    69,     0,     0,     0,    73,    74,    35,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,     0,    79,   173,  -123,   -17,   -31,    60,
    -123,   -58,   124,    -4,   -54,   -40,  -123,   -20,  -122,    28,
    -123,   164,  -123,   122,  -123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    22,    11,    12,    32,    33,    59,    60,
      96,    61,    62,    34,   164,    84,    65,    85,   165,   134,
      86,    87,    88,   166,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    13,    83,    64,    94,    48,    17,    27,    20,    28,
      37,     6,    20,    29,   -66,    68,    90,    25,    69,     7,
      64,   106,    64,    66,   107,   108,     1,   110,    67,    42,
     136,    38,    39,    28,    94,   137,   125,    29,     3,    63,
      66,     6,    66,   129,   130,   131,   133,     6,   175,     7,
     176,   138,    64,     8,     4,     7,     5,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     102,    14,    66,     6,    51,    52,     6,    53,     6,    23,
      54,     7,    55,    56,     7,     9,     7,    31,     8,     6,
       8,    19,    30,    21,    52,    19,     6,     7,    76,   127,
     128,     8,    26,    77,     7,    35,    27,   133,   168,    41,
      45,    57,    43,   173,    46,    47,    43,    58,    71,    78,
      15,    49,    18,    79,    63,    80,    50,    72,    38,    39,
      57,    81,    70,    24,    75,    74,    36,    73,    82,    97,
      98,    99,   177,   178,    51,    52,    95,    53,    51,    52,
      54,    53,    55,    56,    54,   100,    55,    56,    51,    52,
     101,    53,   103,   105,    54,   135,    55,    56,    52,   121,
     122,   123,    76,   109,   156,   140,   163,    77,   172,   162,
     171,    57,   174,    16,    92,    57,    43,    91,   157,   169,
      43,    93,    40,    78,   104,    57,     0,    79,     0,    80,
      43,   126,    38,    39,    57,    81,   132,    52,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
      52,     0,     0,     0,    76,     0,     0,     0,     0,    77,
       0,     0,    78,     0,     0,     0,    79,   103,    80,     0,
       0,    38,    39,    57,    81,    78,     0,     0,     0,    79,
       0,    80,     0,     0,    38,    39,    57,    81,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,   124,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,     0,   158,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,     0,     0,   159,   115,
     116,   117,   118,   119,   120,   121,   122,   123,     0,     0,
       0,   160,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,     0,   161,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
       0,     0,   167,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141
};

static const yytype_int16 yycheck[] =
{
      31,     5,    56,    43,    62,    36,    10,    42,    12,    44,
      27,     3,    16,    48,    42,    46,    44,    17,    49,    11,
      60,    75,    62,    43,    78,    79,     6,    81,    45,    29,
      43,    39,    40,    44,    92,    48,    90,    48,    17,    43,
      60,     3,    62,    97,    98,    99,   100,     3,   170,    11,
     172,   105,    92,    15,     0,    11,    46,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      70,    41,    92,     3,     4,     5,     3,     7,     3,    42,
      10,    11,    12,    13,    11,    47,    11,    43,    15,     3,
      15,    12,    49,    41,     5,    16,     3,    11,     9,    48,
      49,    15,    41,    14,    11,    49,    42,   161,   139,    41,
      48,    41,    46,   167,    43,    41,    46,    47,    49,    30,
      47,    43,    47,    34,   128,    36,    45,    42,    39,    40,
      41,    42,    48,    47,    42,    41,    43,    49,    49,    18,
      19,    20,   173,   174,     4,     5,    41,     7,     4,     5,
      10,     7,    12,    13,    10,    42,    12,    13,     4,     5,
      49,     7,    35,    18,    10,    37,    12,    13,     5,    31,
      32,    33,     9,    38,    41,    36,    35,    14,    48,    43,
      43,    41,     8,    10,    60,    41,    46,    47,   128,   161,
      46,    47,    28,    30,    72,    41,    -1,    34,    -1,    36,
      46,    47,    39,    40,    41,    42,    43,     5,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
       5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,    -1,
      -1,    39,    40,    41,    42,    30,    -1,    -1,    -1,    34,
      -1,    36,    -1,    -1,    39,    40,    41,    42,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    49,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    49,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    49,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    49,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    48,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    51,    17,     0,    46,     3,    11,    15,    47,
      52,    54,    55,    63,    41,    47,    55,    63,    47,    54,
      63,    41,    53,    42,    47,    53,    41,    42,    44,    48,
      49,    43,    56,    57,    63,    49,    43,    57,    39,    40,
      71,    41,    53,    46,    58,    48,    43,    41,    58,    43,
      45,     4,     5,     7,    10,    12,    13,    41,    47,    58,
      59,    61,    62,    63,    65,    66,    67,    57,    58,    58,
      48,    49,    42,    49,    41,    42,     9,    14,    30,    34,
      36,    42,    49,    64,    65,    67,    70,    71,    72,    74,
      44,    47,    62,    47,    61,    41,    60,    18,    19,    20,
      42,    49,    53,    35,    73,    18,    64,    64,    64,    38,
      64,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    49,    64,    47,    48,    49,    64,
      64,    64,    43,    64,    69,    37,    43,    48,    64,    43,
      36,    43,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    45,    41,    59,    49,    49,
      49,    48,    43,    35,    64,    68,    73,    48,    58,    69,
      48,    43,    48,    64,     8,    68,    68,    58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    51,    51,    52,    52,    53,    53,
      53,    53,    54,    54,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    65,    66,    67,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    70,
      71,    71,    72,    72,    73,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     6,     5,     5,     3,     4,     1,     3,
       4,     6,     6,     5,     6,     5,     1,     2,     2,     1,
       3,     2,     3,     3,     4,     3,     4,     1,     3,     4,
       4,     4,     2,     5,     7,     7,     2,     3,     2,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     4,     1,     3,     4,     6,
       4,     1,     1,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 183 "parser.y" /* yacc.c:1646  */
    {	strt = new ProgramNode(NULL,NULL);	}
#line 1597 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 184 "parser.y" /* yacc.c:1646  */
    {	strt = new ProgramNode((yyvsp[-2].fieldDecType),(yyvsp[-1].methodDecListType)); 		}
#line 1603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 185 "parser.y" /* yacc.c:1646  */
    {	strt = new ProgramNode(NULL,(yyvsp[-1].methodDecListType));	}
#line 1609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 186 "parser.y" /* yacc.c:1646  */
    {	strt = new ProgramNode((yyvsp[-1].fieldDecType),NULL);	}
#line 1615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 189 "parser.y" /* yacc.c:1646  */
    {	(yyval.fieldDecType) = new vector<FieldDeclNode*>;
																(yyval.fieldDecType)->push_back(new FieldDeclNode((yyvsp[-2].sval),(yyvsp[-1].idListType)));	}
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 191 "parser.y" /* yacc.c:1646  */
    {	(yyval.fieldDecType) = (yyvsp[-3].fieldDecType);
																(yyval.fieldDecType)->push_back(new FieldDeclNode((yyvsp[-2].sval),(yyvsp[-1].idListType)));	}
#line 1629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 195 "parser.y" /* yacc.c:1646  */
    {	Identifier* idfr = new Identifier((yyvsp[0].sval));
																(yyval.idListType) = new vector<Identifier*>;
																(yyval.idListType)->push_back(idfr);						}
#line 1637 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 199 "parser.y" /* yacc.c:1646  */
    {	Identifier* idfr = new Identifier((yyvsp[-2].sval));
																(yyval.idListType) = (yyvsp[0].idListType);
																(yyval.idListType)->push_back(idfr);						}
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 203 "parser.y" /* yacc.c:1646  */
    {	Identifier* idfr = new Identifier((yyvsp[-3].sval),(yyvsp[-1].intlitType));
																(yyval.idListType) = new vector<Identifier*>; 
																(yyval.idListType)->push_back(idfr);						}
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 207 "parser.y" /* yacc.c:1646  */
    {	Identifier* idfr = new Identifier((yyvsp[-5].sval),(yyvsp[-3].intlitType));
																(yyval.idListType) = (yyvsp[0].idListType);
																(yyval.idListType)->push_back(idfr);						}
#line 1661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 215 "parser.y" /* yacc.c:1646  */
    {	(yyval.methodDecType) = new MethodDeclNode((yyvsp[-5].sval),(yyvsp[-4].sval),(yyvsp[-2].methodArgsType),(yyvsp[0].blockType));	}
#line 1667 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 216 "parser.y" /* yacc.c:1646  */
    {	(yyval.methodDecType) = new MethodDeclNode((yyvsp[-4].sval),(yyvsp[-3].sval),NULL,(yyvsp[0].blockType));	}
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 217 "parser.y" /* yacc.c:1646  */
    {	(yyval.methodDecType) = new MethodDeclNode((yyvsp[-5].sval),(yyvsp[-4].sval),(yyvsp[-2].methodArgsType),(yyvsp[0].blockType));	}
#line 1679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 218 "parser.y" /* yacc.c:1646  */
    {	(yyval.methodDecType) = new MethodDeclNode((yyvsp[-4].sval),(yyvsp[-3].sval),NULL,(yyvsp[0].blockType));	}
#line 1685 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 220 "parser.y" /* yacc.c:1646  */
    {	(yyval.methodDecListType) = new vector<MethodDeclNode*>;
												 	(yyval.methodDecListType)->push_back((yyvsp[0].methodDecType));					}
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 223 "parser.y" /* yacc.c:1646  */
    {	(yyval.methodDecListType) = (yyvsp[-1].methodDecListType);
												  	(yyval.methodDecListType)->push_back((yyvsp[0].methodDecType));					}
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 227 "parser.y" /* yacc.c:1646  */
    {	(yyval.methodArgType) = new MethodArgsNode((yyvsp[-1].sval),(yyvsp[0].sval));		}
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 230 "parser.y" /* yacc.c:1646  */
    { 	(yyval.methodArgsType) = new vector<MethodArgsNode*>;		
												   	(yyval.methodArgsType)->push_back((yyvsp[0].methodArgType)); 					}
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 233 "parser.y" /* yacc.c:1646  */
    { 	(yyval.methodArgsType) = (yyvsp[0].methodArgsType);
												  	(yyval.methodArgsType)->push_back((yyvsp[-2].methodArgType));					}
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 237 "parser.y" /* yacc.c:1646  */
    { 	(yyval.blockType) = new BlockNode(NULL,NULL);	}
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 238 "parser.y" /* yacc.c:1646  */
    {	(yyval.blockType) = new BlockNode((yyvsp[-1].varDeclType),NULL);	}
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 239 "parser.y" /* yacc.c:1646  */
    {	(yyval.blockType) = new BlockNode(NULL,(yyvsp[-1].statementType));	}
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 240 "parser.y" /* yacc.c:1646  */
    {	(yyval.blockType) = new BlockNode((yyvsp[-2].varDeclType),(yyvsp[-1].statementType));		}
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 243 "parser.y" /* yacc.c:1646  */
    {	VarDeclNode* temp = new VarDeclNode((yyvsp[-2].sval),(yyvsp[-1].idListType));
													 	(yyval.varDeclType) = new vector<VarDeclNode*>;
													 	(yyval.varDeclType)->push_back(temp);						}
#line 1751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 247 "parser.y" /* yacc.c:1646  */
    {	(yyval.varDeclType) = (yyvsp[0].varDeclType);
													 	VarDeclNode* temp = new VarDeclNode((yyvsp[-3].sval),(yyvsp[-2].idListType));
													 	(yyval.varDeclType)->push_back(temp);						}
#line 1759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 252 "parser.y" /* yacc.c:1646  */
    {	(yyval.idListType) = new vector<Identifier*>;
														Identifier* temp = new Identifier((yyvsp[0].sval));
												 		(yyval.idListType)->push_back(temp);					}
#line 1767 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 256 "parser.y" /* yacc.c:1646  */
    {	(yyval.idListType) = (yyvsp[-2].idListType);
														Identifier* temp = new Identifier((yyvsp[0].sval));
														(yyval.idListType)->push_back(temp);					}
#line 1775 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 263 "parser.y" /* yacc.c:1646  */
    {	(yyval.statementContentsType) = new AssignmentNode((yyvsp[-3].locationType),(yyvsp[-2].sval),(yyvsp[-1].exprType));	}
#line 1781 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 264 "parser.y" /* yacc.c:1646  */
    {	(yyval.statementContentsType) = new AssignmentNode((yyvsp[-3].locationType),(yyvsp[-2].sval),(yyvsp[-1].exprType));	}
#line 1787 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 265 "parser.y" /* yacc.c:1646  */
    {	(yyval.statementContentsType) = new AssignmentNode((yyvsp[-3].locationType),(yyvsp[-2].sval),(yyvsp[-1].exprType));	}
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 266 "parser.y" /* yacc.c:1646  */
    {	(yyval.statementContentsType) = new MethodNode(); (yyval.statementContentsType) = (yyvsp[-1].methodcallType);		}
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 267 "parser.y" /* yacc.c:1646  */
    {	(yyval.statementContentsType) = new IfNode((yyvsp[-2].exprType),(yyvsp[0].blockType),NULL);}
#line 1805 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 268 "parser.y" /* yacc.c:1646  */
    {	(yyval.statementContentsType) = new IfNode((yyvsp[-4].exprType),(yyvsp[-2].blockType),(yyvsp[0].blockType));}
#line 1811 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.statementContentsType) = new ForNode((yyvsp[-5].sval),(yyvsp[-3].exprType),(yyvsp[-1].exprType),(yyvsp[0].blockType));}
#line 1817 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 270 "parser.y" /* yacc.c:1646  */
    {	(yyval.statementContentsType) = new ReturnNode(NULL);}
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 271 "parser.y" /* yacc.c:1646  */
    {	(yyval.statementContentsType) = new ReturnNode((yyvsp[-1].exprType));}
#line 1829 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 272 "parser.y" /* yacc.c:1646  */
    { 	(yyval.statementContentsType) = new BreakNode();}
#line 1835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 273 "parser.y" /* yacc.c:1646  */
    {	(yyval.statementContentsType) = new ContinueNode();}
#line 1841 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 274 "parser.y" /* yacc.c:1646  */
    {	(yyval.statementContentsType) = new BlockNode(); (yyval.statementContentsType) = (yyvsp[0].blockType);}
#line 1847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 277 "parser.y" /* yacc.c:1646  */
    { (yyval.statementType) = new vector<StatementNode*>;
													StatementNode* temp = new StatementNode();
													temp=(yyvsp[0].statementContentsType);
													(yyval.statementType)->push_back(temp);	}
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 282 "parser.y" /* yacc.c:1646  */
    {	
													StatementNode* temp = new StatementNode();
													temp = (yyvsp[0].statementContentsType);
													(yyval.statementType) = (yyvsp[-1].statementType);
													(yyval.statementType)->push_back(temp);	}
#line 1866 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 295 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new LocationNode(); (yyval.exprType)=(yyvsp[0].locationType);	   }
#line 1872 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new MethodNode();	 (yyval.exprType)=(yyvsp[0].methodcallType);  }
#line 1878 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new LiteralNode(); (yyval.exprType) = (yyvsp[0].literalType);	   }
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new UnaryNode((yyvsp[-1].sval),(yyvsp[0].exprType));   }
#line 1890 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 299 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new UnaryNode((yyvsp[-1].sval),(yyvsp[0].exprType));   }
#line 1896 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 300 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 301 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1914 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 303 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1920 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 304 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1926 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 305 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1932 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 306 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1938 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 307 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1944 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 308 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1950 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1956 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 310 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1962 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 311 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1968 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 312 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new BinaryNode((yyvsp[-2].exprType),(yyvsp[-1].sval),(yyvsp[0].exprType));}
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 313 "parser.y" /* yacc.c:1646  */
    {(yyval.exprType) = new ExpressionNode(); (yyval.exprType) = (yyvsp[-1].exprType);}
#line 1980 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 317 "parser.y" /* yacc.c:1646  */
    {(yyval.locationType) = new LocationNode((yyvsp[0].sval));		}
#line 1986 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyval.locationType) = new LocationNode((yyvsp[-3].sval),(yyvsp[-1].exprType));	}
#line 1992 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 325 "parser.y" /* yacc.c:1646  */
    {(yyval.methodcallType) = new MethodCallNode((yyvsp[-2].sval),NULL);		}
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 326 "parser.y" /* yacc.c:1646  */
    {(yyval.methodcallType) = new MethodCallNode((yyvsp[-3].sval),(yyvsp[-1].argumentsType));	}
#line 2004 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 327 "parser.y" /* yacc.c:1646  */
    {(yyval.methodcallType) = new CalloutNode((yyvsp[-3].stringlitType),(yyvsp[-1].calloutArgsListType));		}
#line 2010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 328 "parser.y" /* yacc.c:1646  */
    {(yyval.methodcallType) = new CalloutNode((yyvsp[-1].stringlitType),NULL);	}
#line 2016 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 331 "parser.y" /* yacc.c:1646  */
    {(yyval.calloutArgsListType) = new vector<CalloutArgsNode*>;
														 CalloutArgsNode* temp = new CalloutArgsNode();
														 temp = (yyvsp[0].exprType);
														 (yyval.calloutArgsListType)->push_back(temp);}
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 336 "parser.y" /* yacc.c:1646  */
    {(yyval.calloutArgsListType) = new vector<CalloutArgsNode*>;
														 CalloutArgsNode* temp = new CalloutArgsNode();
														 temp = (yyvsp[0].stringlitType);
														 (yyval.calloutArgsListType)->push_back(temp);}
#line 2034 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 341 "parser.y" /* yacc.c:1646  */
    {(yyval.calloutArgsListType) = (yyvsp[0].calloutArgsListType);
														CalloutArgsNode* temp = new CalloutArgsNode();
														temp=(yyvsp[-2].exprType);
														 (yyval.calloutArgsListType)->push_back(temp);}
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 347 "parser.y" /* yacc.c:1646  */
    {(yyval.calloutArgsListType) = (yyvsp[0].calloutArgsListType);
														CalloutArgsNode* temp = new CalloutArgsNode();
														temp=(yyvsp[-2].stringlitType);
														 (yyval.calloutArgsListType)->push_back(temp);}
#line 2052 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 357 "parser.y" /* yacc.c:1646  */
    {	(yyval.argumentsType) = new vector<ExpressionNode*>;
												ExpressionNode* temp = new ExpressionNode();
												temp = (yyvsp[0].exprType);
											 	(yyval.argumentsType)->push_back(temp);					}
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 362 "parser.y" /* yacc.c:1646  */
    {	(yyval.argumentsType) = (yyvsp[0].argumentsType);
												ExpressionNode* temp = new ExpressionNode();
												temp = (yyvsp[-2].exprType);
											 	(yyval.argumentsType)->push_back(temp);					}
#line 2070 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 368 "parser.y" /* yacc.c:1646  */
    { (yyval.literalType) = new LiteralNode(); (yyval.literalType)=(yyvsp[0].intlitType);	}
#line 2076 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 369 "parser.y" /* yacc.c:1646  */
    { (yyval.literalType) = new LiteralNode(); (yyval.literalType)=(yyvsp[0].boollitType);	}
#line 2082 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 370 "parser.y" /* yacc.c:1646  */
    { (yyval.literalType) = new LiteralNode(); (yyval.literalType)=(yyvsp[0].charlitType);	}
#line 2088 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 373 "parser.y" /* yacc.c:1646  */
    {	(yyval.intlitType) = new IntNode((yyvsp[0].ival));	}
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 374 "parser.y" /* yacc.c:1646  */
    {	(yyval.intlitType) = new IntNode((yyvsp[0].ival));	}
#line 2100 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 377 "parser.y" /* yacc.c:1646  */
    {	(yyval.boollitType) = new BoolNode((yyvsp[0].sval));	}
#line 2106 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 378 "parser.y" /* yacc.c:1646  */
    { 	(yyval.boollitType) = new BoolNode((yyvsp[0].sval));	}
#line 2112 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 381 "parser.y" /* yacc.c:1646  */
    {(yyval.stringlitType) = new StringNode((yyvsp[-1].sval));}
#line 2118 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 384 "parser.y" /* yacc.c:1646  */
    {(yyval.charlitType) = new CharNode((yyvsp[-1].cval));}
#line 2124 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2128 "parser.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 388 "parser.y" /* yacc.c:1906  */


int main(int argc, char **argv)
{
	// open a file handle to a particular file:

	FILE *myfile = fopen("test.dcf", "r");
	// make sure it's valid:
	if (!myfile) {
		printf("trouble opening given file\n");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:

	yyin = myfile;
	yyparse();

	if(strt)
	{
		strt->accept(irf);
	}
	module->dump();
	return 0;
}
