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
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_NUM = 258,
     T_FNUM = 259,
     T_IMPORT = 260,
     T_CLASS = 261,
     T_PUBLIC = 262,
     T_PRIVATE = 263,
     T_PROTECTED = 264,
     T_STATIC = 265,
     T_VOID = 266,
     T_MAIN = 267,
     T_NEW = 268,
     T_RETURN = 269,
     T_BREAK = 270,
     T_BOOL = 271,
     T_SHORT = 272,
     T_BYTE = 273,
     T_CHAR = 274,
     T_INT = 275,
     T_FLOAT = 276,
     T_LONG = 277,
     T_DOUBLE = 278,
     T_ID = 279,
     T_STRVAL = 280,
     T_LOR = 281,
     T_LAND = 282,
     T_NOT = 283,
     T_STR_ARG = 284,
     T_STR = 285,
     T_STDOUT = 286,
     T_IF = 287,
     T_ELSE = 288,
     T_WHILE = 289,
     T_FOR = 290,
     T_DO = 291,
     T_TRUE = 292,
     T_FALSE = 293,
     T_U_INCR = 294,
     T_U_DECR = 295,
     T_OFB = 296,
     T_CFB = 297,
     T_S_PLUSEQ = 298,
     T_S_MINUSEQ = 299,
     T_S_MULTEQ = 300,
     T_S_DIVEQ = 301,
     T_S_DIV = 302,
     T_S_EQ = 303,
     S_DIV = 304,
     T_ = 305,
     T_S_MULT = 306,
     T_S_MINUS = 307,
     T_S_PLUS = 308,
     T_NE = 309,
     T_ASSG = 310,
     T_GE = 311,
     T_LE = 312,
     T_LEQ = 313,
     T_GEQ = 314
   };
#endif
/* Tokens.  */
#define T_NUM 258
#define T_FNUM 259
#define T_IMPORT 260
#define T_CLASS 261
#define T_PUBLIC 262
#define T_PRIVATE 263
#define T_PROTECTED 264
#define T_STATIC 265
#define T_VOID 266
#define T_MAIN 267
#define T_NEW 268
#define T_RETURN 269
#define T_BREAK 270
#define T_BOOL 271
#define T_SHORT 272
#define T_BYTE 273
#define T_CHAR 274
#define T_INT 275
#define T_FLOAT 276
#define T_LONG 277
#define T_DOUBLE 278
#define T_ID 279
#define T_STRVAL 280
#define T_LOR 281
#define T_LAND 282
#define T_NOT 283
#define T_STR_ARG 284
#define T_STR 285
#define T_STDOUT 286
#define T_IF 287
#define T_ELSE 288
#define T_WHILE 289
#define T_FOR 290
#define T_DO 291
#define T_TRUE 292
#define T_FALSE 293
#define T_U_INCR 294
#define T_U_DECR 295
#define T_OFB 296
#define T_CFB 297
#define T_S_PLUSEQ 298
#define T_S_MINUSEQ 299
#define T_S_MULTEQ 300
#define T_S_DIVEQ 301
#define T_S_DIV 302
#define T_S_EQ 303
#define S_DIV 304
#define T_ 305
#define T_S_MULT 306
#define T_S_MINUS 307
#define T_S_PLUS 308
#define T_NE 309
#define T_ASSG 310
#define T_GE 311
#define T_LE 312
#define T_LEQ 313
#define T_GEQ 314




/* Copy the first part of user declarations.  */
#line 1 "java-yacc.y"

#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*---- linked list for symbol table -----*/

struct list{
  	char name[30];
  	char type[40];
  	int s;
    union Value {
        int val;
        char* vale;
        float valu;
    }value;
    struct list * next;
};
/* ----- writing data to the parent($$) ----- */

typedef struct Node{
      union Value2 {
        int val2;
        float f_val2;
        char* vale2;
    }value2;
}node;

/*------- keep track of the scope -------- */

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
};

struct Stack* createStack() ;
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int peek(struct Stack* stack); 

typedef struct list d_list;
d_list* head=NULL;
int scope;
int yylex(void);
void yyerror(char *);

int fill(char* name,int value,char* type,int scope);
int  fill_str(char* name,char* value,char* type,int scope);
int  fill_float(char* name,float value,char* type,int scope);
int find_val(char *id);
void display();
int update(char* id,int value,int scope);
int temp_scope=0;
int scope;
struct Stack* stack_arr;
extern int line  ;
int res=0;

node* data(int value);
node* fdata(float value);
node* StrValue(char value[20]);



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
#line 69 "java-yacc.y"
{
    	int number;
      float fnumber;
    	char *string;
      struct Node *block;
}
/* Line 193 of yacc.c.  */
#line 288 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 301 "y.tab.c"

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      62,    63,     2,     2,    64,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
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
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    16,    23,    26,    29,    30,
      33,    41,    49,    57,    59,    62,    67,    68,    71,    73,
      76,    77,    79,    81,    83,    85,    87,    89,    91,    93,
      95,    98,   103,   105,   111,   123,   129,   130,   138,   139,
     145,   151,   155,   156,   160,   164,   166,   170,   174,   176,
     178,   180,   182,   184,   188,   192,   196,   200,   204,   208,
     212,   216,   218,   220
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    67,    66,    -1,    68,    -1,     5,    24,
      60,    24,    60,    51,    61,    -1,    74,     6,    24,    87,
      69,    88,    -1,    70,    69,    -1,    71,    69,    -1,    -1,
      74,    79,    -1,    74,    11,    12,    62,    29,    63,    89,
      -1,    74,    76,    24,    62,    72,    63,    89,    -1,    74,
      11,    24,    62,    72,    63,    89,    -1,    73,    -1,    76,
      24,    -1,    76,    24,    64,    72,    -1,    -1,     7,    75,
      -1,    75,    -1,    10,    75,    -1,    -1,    16,    -1,    18,
      -1,    19,    -1,    17,    -1,    20,    -1,    22,    -1,    21,
      -1,    23,    -1,    78,    -1,    77,    78,    -1,    24,    55,
      83,    61,    -1,    79,    -1,    32,    62,    86,    63,    89,
      -1,    32,    62,    86,    63,    87,    77,    88,    33,    87,
      77,    88,    -1,    34,    62,    86,    63,    89,    -1,    -1,
      76,    24,    55,    83,    80,    82,    61,    -1,    -1,    76,
      24,    81,    82,    61,    -1,    64,    24,    55,    83,    82,
      -1,    64,    24,    82,    -1,    -1,    83,    53,    84,    -1,
      83,    52,    84,    -1,    84,    -1,    84,    51,    85,    -1,
      84,    47,    85,    -1,    85,    -1,    24,    -1,     3,    -1,
      25,    -1,     4,    -1,    83,    26,    83,    -1,    83,    27,
      83,    -1,    83,    56,    83,    -1,    83,    57,    83,    -1,
      83,    59,    83,    -1,    83,    58,    83,    -1,    83,    54,
      83,    -1,    83,    48,    83,    -1,    41,    -1,    42,    -1,
      87,    77,    88,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   104,   108,   111,   114,   115,   116,   119,
     122,   123,   124,   128,   132,   133,   134,   138,   139,   142,
     143,   147,   147,   147,   147,   147,   147,   147,   147,   150,
     151,   155,   162,   163,   164,   165,   171,   171,   188,   188,
     196,   201,   205,   208,   214,   220,   223,   229,   235,   238,
     243,   244,   245,   249,   250,   251,   252,   253,   254,   255,
     256,   260,   264,   268
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_NUM", "T_FNUM", "T_IMPORT", "T_CLASS",
  "T_PUBLIC", "T_PRIVATE", "T_PROTECTED", "T_STATIC", "T_VOID", "T_MAIN",
  "T_NEW", "T_RETURN", "T_BREAK", "T_BOOL", "T_SHORT", "T_BYTE", "T_CHAR",
  "T_INT", "T_FLOAT", "T_LONG", "T_DOUBLE", "T_ID", "T_STRVAL", "T_LOR",
  "T_LAND", "T_NOT", "T_STR_ARG", "T_STR", "T_STDOUT", "T_IF", "T_ELSE",
  "T_WHILE", "T_FOR", "T_DO", "T_TRUE", "T_FALSE", "T_U_INCR", "T_U_DECR",
  "T_OFB", "T_CFB", "T_S_PLUSEQ", "T_S_MINUSEQ", "T_S_MULTEQ", "T_S_DIVEQ",
  "T_S_DIV", "T_S_EQ", "S_DIV", "T_", "T_S_MULT", "T_S_MINUS", "T_S_PLUS",
  "T_NE", "T_ASSG", "T_GE", "T_LE", "T_LEQ", "T_GEQ", "'.'", "';'", "'('",
  "')'", "','", "$accept", "CompilationStart", "ImportDec", "Class_def",
  "ClassBody", "GlobVarDec", "MethodDec", "Params", "ParamList",
  "Modifier", "Modifier1", "TYPE", "STATEMENTS", "STATEMENT", "VAR_DEC",
  "@1", "@2", "DecIdenList", "E", "T", "F", "BOOL", "open", "close",
  "HANDLE", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
      46,    59,    40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    68,    69,    69,    69,    70,
      71,    71,    71,    72,    73,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    80,    79,    81,    79,
      82,    82,    82,    83,    83,    83,    84,    84,    84,    85,
      85,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    87,    88,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     7,     6,     2,     2,     0,     2,
       7,     7,     7,     1,     2,     4,     0,     2,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     5,    11,     5,     0,     7,     0,     5,
       5,     3,     0,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      20,     0,    20,    20,     0,    20,     3,     0,    18,     0,
      17,    19,     1,     2,     0,     0,     0,     0,    61,    20,
       0,     0,    20,    20,     0,     0,    62,     5,     6,     7,
       0,    21,    24,    22,    23,    25,    27,    26,    28,     0,
       9,     4,     0,     0,    38,     0,    16,     0,    16,    42,
       0,     0,    13,     0,    50,    52,    49,    51,    36,    45,
      48,     0,     0,     0,     0,     0,    14,     0,     0,    42,
       0,     0,     0,    42,    39,     0,    10,    12,    16,    44,
      43,     0,    47,    46,    11,     0,    41,     0,     0,     0,
       0,     0,    29,    32,    15,    37,    42,     0,     0,     0,
      38,    30,    63,    40,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      54,    60,    59,    55,    56,    58,    57,     0,    33,    35,
       0,    63,     0,     0,     0,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    21,    22,    23,    51,    52,    24,
       8,    90,    91,    92,    93,    69,    49,    63,   105,    59,
      60,   106,    75,    27,    76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int8 yypact[] =
{
      75,    16,    -2,    -2,    45,    75,  -101,    77,  -101,    21,
    -101,  -101,  -101,  -101,    62,    72,    57,    40,  -101,    -1,
      48,    69,    -1,    -1,   106,    51,  -101,  -101,  -101,  -101,
       6,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,    89,
    -101,  -101,    52,    53,   -30,    90,   114,    10,   114,    74,
      58,    76,  -101,   116,  -101,  -101,  -101,  -101,     7,    37,
    -101,    78,   118,    82,    57,    57,    80,    10,    10,    74,
      10,    10,    57,   -45,  -101,    86,  -101,  -101,   114,    37,
      37,    84,  -101,  -101,  -101,    10,  -101,    91,    85,    87,
     124,    55,  -101,  -101,  -101,  -101,   -36,    10,    10,    10,
      95,  -101,  -101,  -101,   -32,    -4,    92,    93,  -101,    10,
      10,    10,    10,    10,    10,    10,    10,    57,    57,     7,
       7,     7,     7,     7,     7,     7,     7,    86,  -101,  -101,
      55,   119,    57,    86,    55,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,   146,  -101,  -101,    39,  -101,  -101,   -41,  -101,    31,
      88,   -22,  -100,   -88,   129,  -101,  -101,   -58,   -46,    25,
      24,    59,   -16,   -87,   -60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -9
static const yytype_int16 yytable[] =
{
      19,    58,    39,   101,   102,    77,     2,    61,     3,     3,
      85,    81,    84,    54,    55,    86,    67,    68,    42,    62,
      67,    68,   109,   110,    53,    47,    53,   130,    62,   108,
      43,     7,    48,   134,    56,    57,     7,    94,   103,    96,
       9,    -8,   101,   131,   111,    12,   101,   135,    67,    68,
     112,   104,   113,   114,   115,   116,    53,   128,   129,    67,
      68,    28,    29,   119,   120,   121,   122,   123,   124,   125,
     126,    31,    32,    33,    34,    35,    36,    37,    38,    87,
       1,    15,     2,    14,    70,     3,    16,    88,    71,    89,
      10,    11,    79,    80,    82,    83,    17,    26,    18,    25,
      20,   127,    31,    32,    33,    34,    35,    36,    37,    38,
      87,    26,    41,    44,    45,    46,   133,    30,    88,    50,
      89,    64,    31,    32,    33,    34,    35,    36,    37,    38,
      31,    32,    33,    34,    35,    36,    37,    38,    62,    65,
      66,    72,    73,    74,    78,    95,    97,    98,   100,    99,
      47,    13,   132,    40,     0,   117,   118,     0,   107
};

static const yytype_int16 yycheck[] =
{
      16,    47,    24,    91,    91,    65,     7,    48,    10,    10,
      55,    69,    72,     3,     4,    73,    52,    53,    12,    64,
      52,    53,    26,    27,    46,    55,    48,   127,    64,    61,
      24,     0,    62,   133,    24,    25,     5,    78,    96,    85,
      24,    42,   130,   130,    48,     0,   134,   134,    52,    53,
      54,    97,    56,    57,    58,    59,    78,   117,   118,    52,
      53,    22,    23,   109,   110,   111,   112,   113,   114,   115,
     116,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       5,    60,     7,     6,    47,    10,    24,    32,    51,    34,
       2,     3,    67,    68,    70,    71,    24,    42,    41,    51,
      60,   117,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    42,    61,    24,    62,    62,   132,    11,    32,    29,
      34,    63,    16,    17,    18,    19,    20,    21,    22,    23,
      16,    17,    18,    19,    20,    21,    22,    23,    64,    63,
      24,    63,    24,    61,    64,    61,    55,    62,    24,    62,
      55,     5,    33,    24,    -1,    63,    63,    -1,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     7,    10,    66,    67,    68,    74,    75,    24,
      75,    75,     0,    66,     6,    60,    24,    24,    41,    87,
      60,    69,    70,    71,    74,    51,    42,    88,    69,    69,
      11,    16,    17,    18,    19,    20,    21,    22,    23,    76,
      79,    61,    12,    24,    24,    62,    62,    55,    62,    81,
      29,    72,    73,    76,     3,     4,    24,    25,    83,    84,
      85,    72,    64,    82,    63,    63,    24,    52,    53,    80,
      47,    51,    63,    24,    61,    87,    89,    89,    64,    84,
      84,    82,    85,    85,    89,    55,    82,    24,    32,    34,
      76,    77,    78,    79,    72,    61,    83,    55,    62,    62,
      24,    78,    88,    82,    83,    83,    86,    86,    61,    26,
      27,    48,    54,    56,    57,    58,    59,    63,    63,    83,
      83,    83,    83,    83,    83,    83,    83,    87,    89,    89,
      77,    88,    33,    87,    77,    88
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
      yyerror (YY_("syntax error: cannot back up")); \
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
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
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
        case 4:
#line 108 "java-yacc.y"
    {/*printf("matched\n");*/}
    break;

  case 5:
#line 111 "java-yacc.y"
    {display();}
    break;

  case 21:
#line 147 "java-yacc.y"
    {(yyval.string)="boolean";}
    break;

  case 22:
#line 147 "java-yacc.y"
    {(yyval.string)="byte";}
    break;

  case 23:
#line 147 "java-yacc.y"
    {(yyval.string)="char";}
    break;

  case 24:
#line 147 "java-yacc.y"
    {(yyval.string)="short";}
    break;

  case 25:
#line 147 "java-yacc.y"
    {(yyval.string)="int";}
    break;

  case 26:
#line 147 "java-yacc.y"
    {(yyval.string)="long";}
    break;

  case 27:
#line 147 "java-yacc.y"
    {(yyval.string)="float";}
    break;

  case 28:
#line 147 "java-yacc.y"
    {(yyval.string)="double";}
    break;

  case 31:
#line 155 "java-yacc.y"
    {
              //printf("Assigned\n");
              node *tem = (yyvsp[(3) - (4)].block);
              int v1=tem->value2.val2;
              int i = update((yyvsp[(1) - (4)].string),v1,scope); //updating symbol table
              
            }
    break;

  case 36:
#line 171 "java-yacc.y"
    {
            
            //printf("%s\n",$1);
            int i;
            if(strcmp((yyvsp[(1) - (4)].string),"int")==0){
              i=fill((yyvsp[(2) - (4)].string),(yyvsp[(4) - (4)].block)->value2.val2,(yyvsp[(1) - (4)].string),scope); //adding symbol table
            }
            else if(strcmp((yyvsp[(1) - (4)].string),"char")==0){
              //printf("%s\n",$4->value2.vale2);
              i=fill_str((yyvsp[(2) - (4)].string),(yyvsp[(4) - (4)].block)->value2.vale2,(yyvsp[(1) - (4)].string),scope);
            }
            else if(strcmp((yyvsp[(1) - (4)].string),"float")==0){
              
              i=fill_float((yyvsp[(2) - (4)].string),(yyvsp[(4) - (4)].block)->value2.f_val2,(yyvsp[(1) - (4)].string),scope);
            }
            //$$ = data(i);
          }
    break;

  case 38:
#line 188 "java-yacc.y"
    {
              //printf("declaration\n");
              int i=fill((yyvsp[(2) - (2)].string),0,(yyvsp[(1) - (2)].string),scope);
              //$$ = data(i);
            }
    break;

  case 40:
#line 196 "java-yacc.y"
    {
            int i;
            i=fill((yyvsp[(2) - (5)].string),(yyvsp[(4) - (5)].block)->value2.val2,"int",scope);

            }
    break;

  case 41:
#line 201 "java-yacc.y"
    {
            int i;
            i=fill((yyvsp[(2) - (3)].string),0,"int",scope);
            }
    break;

  case 43:
#line 208 "java-yacc.y"
    {
    int v1=(yyvsp[(1) - (3)].block)->value2.val2;
    int v2=(yyvsp[(3) - (3)].block)->value2.val2;
    int res = v1+v2;
    (yyval.block) = data(res);
}
    break;

  case 44:
#line 214 "java-yacc.y"
    {
      int v1=(yyvsp[(1) - (3)].block)->value2.val2;
      int v2=(yyvsp[(3) - (3)].block)->value2.val2;
      int res = v1-v2;
      (yyval.block) = data(res);
  }
    break;

  case 45:
#line 220 "java-yacc.y"
    {(yyval.block) = (yyvsp[(1) - (1)].block);}
    break;

  case 46:
#line 223 "java-yacc.y"
    {
            int v1=(yyvsp[(1) - (3)].block)->value2.val2;
            int v2=(yyvsp[(3) - (3)].block)->value2.val2;
            int res = v1*v2;
            (yyval.block) = data(res);
             }
    break;

  case 47:
#line 229 "java-yacc.y"
    {
      int v1=(yyvsp[(1) - (3)].block)->value2.val2;
      int v2=(yyvsp[(3) - (3)].block)->value2.val2;
      int res = v1/v2;
      (yyval.block) = data(res);
      }
    break;

  case 48:
#line 235 "java-yacc.y"
    {(yyval.block) = (yyvsp[(1) - (1)].block);}
    break;

  case 49:
#line 238 "java-yacc.y"
    {
      //printf("getting value\n");
      int d=find_val((yyvsp[(1) - (1)].string)); //get the value from sym_table
      (yyval.block)=data(d);
    }
    break;

  case 50:
#line 243 "java-yacc.y"
    {(yyval.block)=data((yyvsp[(1) - (1)].number));}
    break;

  case 51:
#line 244 "java-yacc.y"
    {(yyval.block)=StrValue((yyvsp[(1) - (1)].string));}
    break;

  case 52:
#line 245 "java-yacc.y"
    {(yyval.block) = fdata((yyvsp[(1) - (1)].fnumber)); }
    break;

  case 61:
#line 260 "java-yacc.y"
    {temp_scope++;push(stack_arr,temp_scope);scope=peek(stack_arr);}
    break;

  case 62:
#line 264 "java-yacc.y"
    {pop(stack_arr);scope=peek(stack_arr);}
    break;


/* Line 1267 of yacc.c.  */
#line 1815 "y.tab.c"
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
      yyerror (YY_("syntax error"));
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
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
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
		      yytoken, &yylval);
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
		  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 270 "java-yacc.y"



/*------------ data to send back to the $$ -------------*/

node* data(int value){
    node* p;
    p =malloc(sizeof(node));
    p->value2.val2=value;
    return p;
}
node* fdata(float value){
    node* p;
    p =malloc(sizeof(node));
    p->value2.f_val2=value;
    return p;
}

node* StrValue(char* value){
  //printf("string in fun:%s\n",value);
    node* p;
    p =malloc(sizeof(node));
    p->value2.vale2=value;
    return p;
}


/* -----------------  symbol table  --------------- */

int update(char*name,int value,int scope){
  d_list *node=head;
  while(node!=NULL){
    if(strcmp(name,node->name)==0){
      node->s=scope;
      node->value.val=value;
      return 1; 
    }
    node=node->next;
  }  
  yyerror("variable not declared");
  return 0;
  exit(1);
}

int  fill(char* name,int value,char* type,int scope){
  d_list *temp=head;
  while(temp!=NULL){
    if(strcmp(name,temp->name)==0){
      if(temp->s != scope){
        temp=temp->next;
        continue;
      }  
      yyerror("variable already declared");
      exit(1);
      return  -1;
    }
    temp=temp->next;
  }
  //create new node
  d_list* newnode=(d_list*)malloc(sizeof(d_list));
  strcpy(newnode->name,name);
  strcpy(newnode->type,type);     
  newnode->value.val=value;
  newnode->s=scope;
  newnode->next=head;
  head=newnode;  
  return 1;
}

//str storing
int  fill_str(char* name,char* value,char* type,int scope){
  d_list *temp=head;
  while(temp!=NULL){
    if(strcmp(name,temp->name) == 0){
      yyerror("variable already declared");
      //exit(1);
      return  -1;
    }
    temp=temp->next;
  }
  d_list* newnode=(d_list*) malloc(sizeof(d_list));
  strcpy(newnode->name,name);
  strcpy(newnode->type,type);
  //printf("copying..%s\n",value);
  
  newnode->value.vale=value;
  newnode->s=scope;
  newnode->next=head;
  head=newnode; 
  return 1;
}

int  fill_float(char* name,float value,char* type,int scope){
  d_list *temp=head;
  while(temp!=NULL){
    if(strcmp(name,temp->name) == 0){
      yyerror("variable already declared");
      //exit(1);
      return  -1;
    }
    temp=temp->next;
  }
  d_list* newnode=(d_list*) malloc(sizeof(d_list));
  strcpy(newnode->name,name);
  strcpy(newnode->type,type);
  //printf("copying..%s\n",value);
  
  newnode->value.valu=value;
  newnode->s=scope;
  newnode->next=head;
  head=newnode; 
  return 1;
}


int find_val(char *id){
  d_list* temp;
  temp=head;
  if(head==NULL){
    yyerror("Variable Not declared");
    return -1;
    exit(1);
  }
  while(temp!=NULL){
    if(strcmp(id,temp->name)==0)
      return temp->value.val;
    temp=temp->next;
  }
  yyerror("Variable Not declared");
  return -1;
  exit(1); 
}

/* ------- scope of the variable --------- */

struct Stack* createStack() { 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = 100; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
}

int isEmpty(struct Stack* stack) { 
    return stack->top == -1; 
} 

void push(struct Stack* stack, int item) { 
    if (stack->top == (stack->capacity)-1) 
        return; 
    stack->array[++stack->top] = item; 
    //printf("%d pushed to stack\n", item); 
}

int pop(struct Stack* stack) { 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
}

int peek(struct Stack* stack) { 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
}

/* ------------- Display the symbol table ---------- */

void display(){
  d_list* node;
  node=head;
  printf("------------------- HASH TABLE ------------------\n\n");
  printf("\tType\tName\tValue\t\tScope\n");
  while(node!=NULL){
      if(strcmp(node->type,"int")==0){
        printf("\t%s\t%s\t%d\t\t%d\n",node->type,node->name,node->value.val,node->s);
      }
      else if(strcmp(node->type,"char")==0){
        printf("\t%s\t%s\t%s\t\t%d\n",node->type,node->name,node->value.vale,node->s);
      }
      else if(strcmp(node->type,"float")==0){
        printf("\t%s\t%s\t%f\t%d\n",node->type,node->name,node->value.valu,node->s);
      }
      node=node->next;
  }
  printf("\n");
}

void yyerror(char *s) {
fprintf(stderr, "%d : %s\n", line,s);
}

/* ------- main function --------- */

int main()
{
  stack_arr = createStack();
  yyparse();

  return 0;
}




