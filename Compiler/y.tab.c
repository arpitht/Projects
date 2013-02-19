
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int t,rc=0,l=0,in=1,sf,s,v;
char fname[10];
struct node
{	int val;
	char op;
	char name[10];
	int flag;
	int type; //0 int 1 bool 2 void
	struct node * left,*center,* right;
	struct symtbl *sym;
}*temp;
struct symtbl
{	char name[10];
	int type;
	int *binding;
	int size;
	int index;
	struct symtbl *next;
	struct argstruct *arglist;
}*gbegin=NULL,*gend=NULL,*gtmp,*lbegin=NULL,*lend=NULL,*ltmp;
struct argstruct
{	char name[10];
	int type;
	struct node *arg;
	struct argstruct *next,*prev;
}*abegin,*aend,*atmp;
struct symtbl* insertgsymtbl(char *name,int type,int s);
struct symtbl*  gsymtbllookup(char *name);
void  traversegsymtbl();
struct symtbl* insertlsymtbl(char *name,int type,int s);
struct symtbl*  lsymtbllookup(char *name);
void  traverselsymtbl();
struct argstruct * insertargstruct(char *name,int type);
struct argstruct * argstructlookup(char *name);
struct node* createnodeid(char *name,struct node *n1,struct node *n2);
struct node* createnodenum(int val,struct node *n1,struct node *n2);	
struct node* createnodebool(int val,struct node *n1,struct node *n2);
struct node* createnodevoid(struct node* n1,struct node* n2);
struct node* createnodeop(char op,struct node *n1,struct node *n2);
struct node* createnodearrid(char *name,struct node *n1,struct node *n2,struct node *n3);
struct node* createnodecond(char op,struct node *n1,struct node *n2,struct node *n3);
struct node* createnodefunc(char *name,struct node *n1,struct node *n2);
void inorder(struct node *n);
void icg(struct node *n);
FILE *fp;


/* Line 189 of yacc.c  */
#line 125 "y.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NE = 258,
     GE = 259,
     LE = 260,
     EQ = 261,
     NUM = 262,
     DECL = 263,
     ENDDECL = 264,
     BEGN = 265,
     END = 266,
     ID = 267,
     INTEGER = 268,
     BOOLEAN = 269,
     READ = 270,
     WRITE = 271,
     TRUE = 272,
     FALSE = 273,
     AND = 274,
     NOT = 275,
     OR = 276,
     IF = 277,
     THEN = 278,
     ELSE = 279,
     ENDIF = 280,
     WHILE = 281,
     ENDWHILE = 282,
     MAIN = 283,
     RETN = 284
   };
#endif
/* Tokens.  */
#define NE 258
#define GE 259
#define LE 260
#define EQ 261
#define NUM 262
#define DECL 263
#define ENDDECL 264
#define BEGN 265
#define END 266
#define ID 267
#define INTEGER 268
#define BOOLEAN 269
#define READ 270
#define WRITE 271
#define TRUE 272
#define FALSE 273
#define AND 274
#define NOT 275
#define OR 276
#define IF 277
#define THEN 278
#define ELSE 279
#define ENDIF 280
#define WHILE 281
#define ENDWHILE 282
#define MAIN 283
#define RETN 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 52 "parser.y"
 	int num; 
		char ch[10];
		struct node *ptr;
	


/* Line 214 of yacc.c  */
#line 226 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 238 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   280

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,    11,     9,    39,    10,     2,    12,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       4,    44,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
       7,     8,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    10,    11,    16,    19,    21,    25,
      26,    27,    36,    37,    38,    46,    48,    50,    52,    56,
      61,    68,    71,    76,    79,    81,    82,    83,    94,    95,
     104,   105,   114,   121,   127,   130,   132,   136,   138,   142,
     145,   147,   153,   159,   164,   168,   176,   186,   193,   195,
     199,   200,   207,   209,   210,   212,   216,   221,   228,   233,
     240,   242,   246,   250,   254,   258,   262,   266,   270,   274,
     278,   282,   286,   290,   292,   294,   296,   299,   301,   303,
     308
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    -1,    14,    49,    15,    47,    58,    -1,
      -1,    14,    15,    48,    58,    -1,    49,    50,    -1,    50,
      -1,    55,    56,    36,    -1,    -1,    -1,    55,    51,    18,
      37,    52,    57,    38,    36,    -1,    -1,    -1,    55,    53,
      18,    37,    54,    38,    36,    -1,    19,    -1,    20,    -1,
      18,    -1,    56,    39,    18,    -1,    18,    40,    13,    41,
      -1,    56,    39,    18,    40,    13,    41,    -1,    55,    18,
      -1,    57,    39,    55,    18,    -1,    58,    59,    -1,    59,
      -1,    -1,    -1,    55,    18,    37,    60,    57,    61,    38,
      42,    64,    43,    -1,    -1,    55,    18,    37,    62,    38,
      42,    64,    43,    -1,    -1,    19,    34,    37,    38,    42,
      63,    64,    43,    -1,    14,    65,    15,    16,    68,    17,
      -1,    14,    15,    16,    68,    17,    -1,    65,    66,    -1,
      66,    -1,    55,    67,    36,    -1,    18,    -1,    67,    39,
      18,    -1,    68,    69,    -1,    69,    -1,    21,    37,    75,
      38,    36,    -1,    22,    37,    74,    38,    36,    -1,    75,
      44,    74,    36,    -1,    75,    44,    70,    -1,    28,    37,
      74,    38,    29,    68,    31,    -1,    28,    37,    74,    38,
      29,    68,    30,    68,    31,    -1,    32,    37,    74,    38,
      68,    33,    -1,    70,    -1,    35,    74,    36,    -1,    -1,
      18,    37,    71,    72,    38,    36,    -1,    73,    -1,    -1,
      18,    -1,    72,    39,    18,    -1,    18,    40,    13,    41,
      -1,    72,    39,    18,    40,    13,    41,    -1,    18,    40,
      18,    41,    -1,    72,    39,    18,    40,    18,    41,    -1,
      13,    -1,    72,    39,    13,    -1,    74,     9,    74,    -1,
      74,    10,    74,    -1,    74,    11,    74,    -1,    74,    12,
      74,    -1,    37,    74,    38,    -1,    74,     3,    74,    -1,
      74,     4,    74,    -1,    74,     8,    74,    -1,    74,     7,
      74,    -1,    74,     6,    74,    -1,    74,     5,    74,    -1,
      23,    -1,    24,    -1,    13,    -1,    10,    13,    -1,    75,
      -1,    18,    -1,    18,    40,    13,    41,    -1,    18,    40,
      18,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    63,    64,    64,    65,    66,    67,    68,
      68,    68,    71,    71,    71,    74,    75,    76,    78,    81,
      83,    87,    89,    93,    94,    95,    98,    95,   139,   139,
     158,   158,   159,   160,   161,   162,   163,   164,   166,   170,
     171,   172,   173,   176,   183,   190,   191,   192,   193,   194,
     195,   195,   196,   197,   201,   219,   237,   256,   275,   294,
     313,   320,   328,   335,   342,   349,   356,   357,   364,   371,
     378,   385,   392,   400,   401,   402,   403,   407,   409,   410,
     413
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'>'", "'<'", "NE", "GE", "LE", "EQ",
  "'+'", "'-'", "'*'", "'/'", "NUM", "DECL", "ENDDECL", "BEGN", "END",
  "ID", "INTEGER", "BOOLEAN", "READ", "WRITE", "TRUE", "FALSE", "AND",
  "NOT", "OR", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "ENDWHILE", "MAIN",
  "RETN", "';'", "'('", "')'", "','", "'['", "']'", "'{'", "'}'", "'='",
  "$accept", "pgm", "$@1", "$@2", "gdlist", "gdecl", "$@3", "$@4", "$@5",
  "$@6", "type", "gIDlist", "pdlist", "flist", "func", "$@7", "$@8", "$@9",
  "$@10", "body", "dlist", "decl", "IDlist", "slist", "stmt", "fcall",
  "$@11", "arglist", "arg", "expr", "IDS", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    62,    60,   258,   259,   260,   261,    43,
      45,    42,    47,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,    59,    40,    41,    44,
      91,    93,   123,   125,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    47,    46,    48,    46,    49,    49,    50,    51,
      52,    50,    53,    54,    50,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    58,    60,    61,    59,    62,    59,
      63,    59,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      71,    70,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     0,     4,     2,     1,     3,     0,
       0,     8,     0,     0,     7,     1,     1,     1,     3,     4,
       6,     2,     4,     2,     1,     0,     0,    10,     0,     8,
       0,     8,     6,     5,     2,     1,     3,     1,     3,     2,
       1,     5,     5,     4,     3,     7,     9,     6,     1,     3,
       0,     6,     1,     0,     1,     3,     4,     6,     4,     6,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     2,     1,     1,     4,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,    15,    16,     0,     7,     0,     1,
       0,     2,     6,    17,     0,     0,     0,    15,     0,     5,
      24,     0,     0,     0,     0,     8,     0,     0,     0,    23,
       3,     0,    10,    13,    18,     0,    25,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    26,
       0,    21,     0,     0,    14,    20,     0,     0,     0,    11,
       0,     0,     0,     0,     0,    22,     0,     0,     0,    35,
      31,     0,    29,     0,    37,     0,     0,    34,     0,    78,
       0,     0,     0,     0,     0,     0,    40,    48,     0,    36,
       0,     0,    27,    50,     0,     0,     0,     0,     0,     0,
      75,    78,    73,    74,     0,     0,    77,    33,    39,     0,
      38,     0,    53,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    44,     0,    32,    60,    54,     0,    52,    79,
      80,     0,     0,     0,     0,    66,    67,    68,    72,    71,
      70,    69,    62,    63,    64,    65,    43,     0,     0,     0,
      41,    42,     0,     0,     0,     0,    51,    61,    55,     0,
      47,    56,    58,     0,     0,    45,     0,     0,     0,    57,
      59,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    21,    10,     6,     7,    14,    38,    15,    39,
      18,    16,    45,    19,    20,    42,    57,    43,    56,    62,
      68,    69,    75,    85,    86,    87,   112,   137,   138,   105,
     106
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const yytype_int16 yypact[] =
{
      -1,     6,    15,   -89,   -89,   -89,    61,   -89,    24,   -89,
      21,   -89,   -89,   -16,    34,    57,   -25,    68,    86,    21,
     -89,    21,   127,    99,   105,   -89,   126,   111,   117,   -89,
      21,   152,   -89,   -89,   161,   178,   183,   -89,   139,   188,
     214,   186,   139,   191,   213,   160,   194,   192,   -89,   193,
     195,   -89,   198,   139,   -89,   -89,   221,   200,   221,   -89,
     218,    72,   196,   199,   197,   -89,   226,   225,    80,   -89,
     -89,   221,   -89,   190,   -89,   158,   228,   -89,   202,   112,
     209,   210,   211,   215,    35,   -12,   -89,   -89,   205,   -89,
     232,   190,   -89,   -89,    31,   233,    35,    35,    35,   240,
     -89,   216,   -89,   -89,    35,   169,   -89,   -89,   -89,    60,
     -89,    29,    42,   217,   219,   223,    25,   103,   113,   -89,
     123,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,   -89,   -89,   179,   -89,   -89,   222,   181,   -89,   -89,
     -89,   227,   229,   230,   190,   -89,    56,    56,    56,    56,
      56,    56,   212,   212,   -89,   -89,   -89,    64,   231,    75,
     -89,   -89,   190,   174,   234,   235,   -89,   -89,   224,   125,
     -89,   -89,   -89,    85,   190,   -89,   236,   237,   182,   -89,
     -89,   -89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   -89,   -89,   -89,   248,   -89,   -89,   -89,   -89,
       1,   -89,   238,   245,   -11,   -89,   -89,   -89,   -89,   -54,
     -89,   187,   -89,   -88,   -84,   148,   -89,   -89,   -89,    41,
     -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -29
static const yytype_int16 yytable[] =
{
      88,   108,     8,   111,    64,   107,    79,     8,    29,    80,
      81,    25,    88,     1,    26,     9,    82,    78,    88,    29,
      83,     3,   115,    84,    22,     4,     5,   108,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    88,    44,
      17,     5,    13,    44,   113,    99,   134,    79,   100,   114,
      80,    81,    23,   101,    60,   135,   163,    82,   102,   103,
     136,    83,    67,   142,    84,   127,   128,   129,   130,    67,
      99,    88,   104,   100,   169,    24,    11,   164,    79,   108,
       4,     5,   165,   102,   103,   108,   178,    66,   167,    88,
      88,     4,     5,   168,   108,    76,    88,   104,   176,     4,
       5,    88,    27,   177,    28,    88,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    32,   116,   117,   118,
      31,   143,    33,    79,    34,   120,    80,    81,    35,    93,
     133,   144,    94,    82,    36,   174,   175,    83,     4,     5,
      84,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    79,    37,    89,    80,    81,    90,    52,    53,
      79,    40,    82,    80,    81,   131,    83,   170,    79,    84,
      82,    80,    81,   181,    83,   156,    41,    84,    82,   158,
     159,   -28,    83,   129,   130,    84,    46,    47,    48,    50,
      54,    51,    53,    55,    59,    61,    65,    58,    63,    70,
      72,    71,    73,    74,    91,    92,    95,    96,    97,   109,
     110,   101,    98,   119,    12,    77,    94,   132,   139,   162,
     140,   141,   157,   160,   173,   161,    30,   166,     0,     0,
       0,     0,     0,     0,     0,   171,   172,   179,   180,     0,
      49
};

static const yytype_int16 yycheck[] =
{
      73,    85,     1,    91,    58,    17,    18,     6,    19,    21,
      22,    36,    85,    14,    39,     0,    28,    71,    91,    30,
      32,    15,    95,    35,    40,    19,    20,   111,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   111,    38,
      19,    20,    18,    42,    13,    10,    17,    18,    13,    18,
      21,    22,    18,    18,    53,    13,   144,    28,    23,    24,
      18,    32,    61,    38,    35,     9,    10,    11,    12,    68,
      10,   144,    37,    13,   162,    18,    15,    13,    18,   163,
      19,    20,    18,    23,    24,   169,   174,    15,    13,   162,
     163,    19,    20,    18,   178,    15,   169,    37,    13,    19,
      20,   174,    34,    18,    18,   178,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    37,    96,    97,    98,
      13,    38,    37,    18,    18,   104,    21,    22,    37,    37,
     109,    38,    40,    28,    37,    30,    31,    32,    19,    20,
      35,    38,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    18,    41,    36,    21,    22,    39,    38,    39,
      18,    40,    28,    21,    22,    36,    32,    33,    18,    35,
      28,    21,    22,    31,    32,    36,    38,    35,    28,    38,
      39,    38,    32,    11,    12,    35,    38,    13,    42,    38,
      36,    18,    39,    41,    36,    14,    18,    42,    38,    43,
      43,    42,    16,    18,    16,    43,    37,    37,    37,    44,
      18,    18,    37,    13,     6,    68,    40,   109,    41,    29,
      41,    38,    40,    36,    40,    36,    21,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    41,    41,    41,    -1,
      42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    46,    15,    19,    20,    49,    50,    55,     0,
      48,    15,    50,    18,    51,    53,    56,    19,    55,    58,
      59,    47,    40,    18,    18,    36,    39,    34,    18,    59,
      58,    13,    37,    37,    18,    37,    37,    41,    52,    54,
      40,    38,    60,    62,    55,    57,    38,    13,    42,    57,
      38,    18,    38,    39,    36,    41,    63,    61,    42,    36,
      55,    14,    64,    38,    64,    18,    15,    55,    65,    66,
      43,    42,    43,    16,    18,    67,    15,    66,    64,    18,
      21,    22,    28,    32,    35,    68,    69,    70,    75,    36,
      39,    16,    43,    37,    40,    37,    37,    37,    37,    10,
      13,    18,    23,    24,    37,    74,    75,    17,    69,    44,
      18,    68,    71,    13,    18,    75,    74,    74,    74,    13,
      74,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    36,    70,    74,    17,    13,    18,    72,    73,    41,
      41,    38,    38,    38,    38,    38,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    36,    40,    38,    39,
      36,    36,    29,    68,    13,    18,    36,    13,    18,    68,
      33,    41,    41,    40,    30,    31,    13,    18,    68,    41,
      41,    31
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 63 "parser.y"
    {traversegsymtbl();}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 63 "parser.y"
    {traverselsymtbl();}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 64 "parser.y"
    {traversegsymtbl();}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    {if(t=0) v=0; else v=1; }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    { abegin=NULL; aend=NULL; sf=0; }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    { gtmp=insertgsymtbl((yyvsp[(3) - (8)].ch),v,1);
					gtmp->arglist=abegin; gtmp->size=sf;
				}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    {if(t=0) v=0; else v=1; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    { abegin=NULL; aend=NULL; }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    { gtmp=insertgsymtbl((yyvsp[(3) - (7)].ch),v,1);
					gtmp->arglist=NULL; gtmp->size=0;
				}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {t=0;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    {t=1;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { insertgsymtbl(yylval.ch,t,1); 
				}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    { insertgsymtbl(yylval.ch,t,1); 
			
				}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {insertgsymtbl((yyvsp[(1) - (4)].ch),t,yylval.num); 
				}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    { insertgsymtbl((yyvsp[(3) - (6)].ch),t,yylval.num); 
				
				}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 87 "parser.y"
    { insertargstruct(yylval.ch,t); 		
				sf++;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    { 	
					insertargstruct(yylval.ch,t); sf++;
				}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {	strcpy(fname,(yyvsp[(2) - (3)].ch));
			abegin=aend=NULL; 
			lbegin=lend=NULL; 	rc=0;	
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {gtmp=gsymtbllookup((yyvsp[(2) - (5)].ch));
			if(gtmp==NULL)
			{printf("Error:Function %s not declared",(yyvsp[(2) - (5)].ch));
			exit(0);
			}
			if(gtmp->type!=t)
			{printf("Error:Return type don't match",(yyvsp[(2) - (5)].ch));
			exit(0);
			}
			atmp=gtmp->arglist;
			struct argstruct *t;
			t=abegin;
			int index=-1;
 			while(atmp!=NULL)
			{if(t!=NULL)
			{	if(t->type==atmp->type&&!strcmp(atmp->name,t->name))
				{	atmp=atmp->next;
					insertlsymtbl(t->name,t->type,index);
					index--;
					t=t->next;						
				}
				else
				{	printf("Error:Function paramters don't match"); 
					exit(0);
				}
			}
			else
			{	printf("Number of parameters don't match"); exit(0);}
			}
			if(t!=NULL)
			{printf("\nNumber of parameters don't match"); exit(0);}
			
			}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    { 
					fprintf(fp,"%s:\n",(yyvsp[(2) - (10)].ch));
					
					icg((yyvsp[(9) - (10)].ptr));
					fprintf(fp,"MOV R%d,BP\n",0);
					fprintf(fp,"MOV SP,R%d\n",0);
					fprintf(fp,"RET\n",0);
					}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {abegin=aend=NULL; lbegin=lend=NULL; gtmp=gsymtbllookup((yyvsp[(2) - (3)].ch));
					if(gtmp==NULL)
					{printf("Error:Function %s not declared",(yyvsp[(2) - (3)].ch));
					exit(0);
					}
					if(gtmp->type!=t)
					{printf("Error:Return type don't match",(yyvsp[(2) - (3)].ch));
					exit(0);
					}
					atmp=gtmp->arglist;
 					if(atmp!=NULL)
					{ printf("Parameters donot match"); exit(0);
					}}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { 
					fprintf(fp,"%s:\n",gtmp->name);
					icg((yyvsp[(7) - (8)].ptr));
					fprintf(fp,"MOV R%d,BP\n",0);
					fprintf(fp,"MOV SP,R%d\n",0);
					fprintf(fp,"RET\n",0);
					}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {lbegin=lend=NULL;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {fprintf(fp,"START\n"); fprintf(fp,"MOV SP,%d\n",in); fprintf(fp,"MOV BP,%d\n",in); icg((yyvsp[(7) - (8)].ptr)); fprintf(fp,"HALT\n");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {inorder((yyvsp[(5) - (6)].ptr));  (yyval.ptr)=(yyvsp[(5) - (6)].ptr);}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {inorder((yyvsp[(4) - (5)].ptr));  (yyval.ptr)=(yyvsp[(4) - (5)].ptr);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { s=1; insertlsymtbl(yylval.ch,t,s); s++;
		}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    { insertlsymtbl(yylval.ch,t,s); 
				s++;
				}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {(yyval.ptr)=createnodevoid((yyvsp[(1) - (2)].ptr),(yyvsp[(2) - (2)].ptr));}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {(yyval.ptr)=(yyvsp[(1) - (1)].ptr);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {(yyval.ptr)=createnodeop('r',NULL,(yyvsp[(3) - (5)].ptr)); (yyval.ptr)->type=(yyvsp[(3) - (5)].ptr)->type;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {if((yyvsp[(3) - (5)].ptr)->type!=0)
				{printf("Error:Write does not support boolean operators\n"); exit(0);}
				(yyval.ptr)=createnodeop('w',NULL,(yyvsp[(3) - (5)].ptr)); (yyval.ptr)->type=(yyvsp[(3) - (5)].ptr)->type;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    { if((yyvsp[(1) - (4)].ptr)->type!=(yyvsp[(3) - (4)].ptr)->type) 
					{	printf("Type Error");
						exit(0);
					}
					(yyval.ptr)=createnodeop('=',(yyvsp[(1) - (4)].ptr),(yyvsp[(3) - (4)].ptr)); 
					(yyval.ptr)->type=(yyvsp[(1) - (4)].ptr)->type;
					}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    { if((yyvsp[(1) - (3)].ptr)->type!=(yyvsp[(3) - (3)].ptr)->type) 
				{	printf("Type Error");
					exit(0);
				}
				(yyval.ptr)=createnodeop('=',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
				(yyval.ptr)->type=(yyvsp[(1) - (3)].ptr)->type;
			}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {(yyval.ptr)=createnodeop('c',(yyvsp[(3) - (7)].ptr),(yyvsp[(6) - (7)].ptr));}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {(yyval.ptr)=createnodecond('d',(yyvsp[(3) - (9)].ptr),(yyvsp[(6) - (9)].ptr),(yyvsp[(8) - (9)].ptr));}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {(yyval.ptr)=createnodeop('i',(yyvsp[(3) - (6)].ptr),(yyvsp[(5) - (6)].ptr));}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {(yyval.ptr)=(yyvsp[(1) - (1)].ptr);}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {temp=createnodefunc(fname,NULL,NULL); (yyval.ptr)=createnodeop('v',temp,(yyvsp[(2) - (3)].ptr)); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    { gtmp=gsymtbllookup((yyvsp[(1) - (2)].ch)); if(gtmp==NULL){printf("\nFunction does not exist"); exit(0);}atmp=gtmp->arglist;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {	(yyval.ptr)=createnodefunc((yyvsp[(1) - (6)].ch),NULL,NULL);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {if(atmp!=NULL)
		{	printf("Function call expects parameters"); 
			exit(0);
		} }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    { 	if(atmp==NULL)
		{	printf("Too many parameters in function call"); 
			exit(0);
		} 
		ltmp=lsymtbllookup((yyvsp[(1) - (1)].ch));
		if(ltmp==NULL)
		ltmp=gsymtbllookup((yyvsp[(1) - (1)].ch));
		if(ltmp==NULL)
		{	printf("Variable used without declaration\n"); 
			exit(0);
		}
		if(ltmp->type!=atmp->type)
		{	printf("Function paramter list type mismatch\n"); 
			exit(0);
		}
		atmp->arg=createnodeid((yyvsp[(1) - (1)].ch),NULL,NULL);
		atmp=atmp->next;			
	    }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    { 	if(atmp==NULL)
				{	printf("Too many parameters in function call"); 
					exit(0);
				} 
				ltmp=lsymtbllookup((yyvsp[(3) - (3)].ch));
				if(ltmp==NULL)
				ltmp=gsymtbllookup((yyvsp[(3) - (3)].ch));
				if(ltmp==NULL)
				{	printf("Variable used without declaration\n"); 
					exit(0);
				}
				if(ltmp->type!=atmp->type)
				{	printf("Function paramter list type mismatch\n"); 
					exit(0);
				}
				atmp->arg=createnodeid((yyvsp[(3) - (3)].ch),NULL,NULL);
				atmp=atmp->next;	        
				}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    { 	if(atmp==NULL)
		{	printf("Too many parameters in function call"); 
			exit(0);
		} 
		ltmp=lsymtbllookup((yyvsp[(1) - (4)].ch));
		if(ltmp==NULL)
		ltmp=gsymtbllookup((yyvsp[(1) - (4)].ch));
		if(ltmp==NULL)
		{	printf("Variable used without declaration\n"); 
			exit(0);
		}
		if(ltmp->type!=atmp->type)
		{	printf("Function paramter list type mismatch\n"); 
			exit(0);
		}
		temp=createnodenum(yylval.num,NULL,NULL);
		atmp->arg=createnodearrid((yyvsp[(1) - (4)].ch),NULL,NULL,temp);
		atmp=atmp->next;			
	    }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    { 	if(atmp==NULL)
				{	printf("Too many parameters in function call"); 
					exit(0);
				} 
				ltmp=lsymtbllookup((yyvsp[(3) - (6)].ch));
				if(ltmp==NULL)
				ltmp=gsymtbllookup((yyvsp[(3) - (6)].ch));
				if(ltmp==NULL)
				{	printf("Variable used without declaration\n"); 
					exit(0);
				}
				if(ltmp->type!=atmp->type)
				{	printf("Function paramter list type mismatch\n"); 
					exit(0);
				}
				temp=createnodenum(yylval.num,NULL,NULL);
				atmp->arg=createnodearrid((yyvsp[(3) - (6)].ch),NULL,NULL,temp);
				atmp=atmp->next;	        
				}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    { 	if(atmp==NULL)
		{	printf("Too many parameters in function call"); 
			exit(0);
		} 
		ltmp=lsymtbllookup((yyvsp[(1) - (4)].ch));
		if(ltmp==NULL)
		ltmp=gsymtbllookup((yyvsp[(1) - (4)].ch));
		if(ltmp==NULL)
		{	printf("Variable used without declaration\n"); 
			exit(0);
		}
		if(ltmp->type!=atmp->type)
		{	printf("Function paramter list type mismatch\n"); 
			exit(0);
		}
		temp=createnodeid((yyvsp[(3) - (4)].ch),NULL,NULL);
		atmp->arg=createnodearrid((yyvsp[(1) - (4)].ch),NULL,NULL,temp);
		atmp=atmp->next;			
	    }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 294 "parser.y"
    { 	if(atmp==NULL)
				{	printf("Too many parameters in function call"); 
					exit(0);
				} 
				ltmp=lsymtbllookup((yyvsp[(3) - (6)].ch));
				if(ltmp==NULL)
				ltmp=gsymtbllookup((yyvsp[(3) - (6)].ch));
				if(ltmp==NULL)
				{	printf("Variable used without declaration\n"); 
					exit(0);
				}
				if(ltmp->type!=atmp->type)
				{	printf("Function paramter list type mismatch\n"); 
					exit(0);
				}
				temp=createnodeid((yyvsp[(5) - (6)].ch),NULL,NULL);
				atmp->arg=createnodearrid((yyvsp[(3) - (6)].ch),NULL,NULL,temp);
				atmp=atmp->next;	        
				}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 313 "parser.y"
    { 	if(atmp==NULL)
		{	printf("Too many parameters in function call"); 
			exit(0);
		}
		atmp->arg=createnodenum(yylval.num,NULL,NULL); 
		atmp=atmp->next;
		}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    { 	if(atmp==NULL)
				{	printf("Too many parameters in function call"); 
					exit(0);
				}
				atmp->arg=createnodenum(yylval.num,NULL,NULL); 
				atmp=atmp->next;
			}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 328 "parser.y"
    {
				if((yyvsp[(1) - (3)].ptr)->type!=0 && (yyvsp[(3) - (3)].ptr)->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						(yyval.ptr)=createnodeop('+',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
						(yyval.ptr)->type=(yyvsp[(1) - (3)].ptr)->type;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    {	if((yyvsp[(1) - (3)].ptr)->type!=0 && (yyvsp[(3) - (3)].ptr)->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						(yyval.ptr)=createnodeop('-',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
						(yyval.ptr)->type=(yyvsp[(1) - (3)].ptr)->type;
					}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 342 "parser.y"
    {		if((yyvsp[(1) - (3)].ptr)->type!=0 && (yyvsp[(3) - (3)].ptr)->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						(yyval.ptr)=createnodeop('*',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
						(yyval.ptr)->type=(yyvsp[(1) - (3)].ptr)->type;
				}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 349 "parser.y"
    {	if((yyvsp[(1) - (3)].ptr)->type!=0 && (yyvsp[(3) - (3)].ptr)->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						(yyval.ptr)=createnodeop('/',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
						(yyval.ptr)->type=(yyvsp[(1) - (3)].ptr)->type;
			}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
    {	(yyval.ptr)=(yyvsp[(2) - (3)].ptr) ;		}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 357 "parser.y"
    { if((yyvsp[(1) - (3)].ptr)->type!=0 && (yyvsp[(3) - (3)].ptr)->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						(yyval.ptr)=createnodeop('>',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
						(yyval.ptr)->type=1;
						}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 364 "parser.y"
    { if((yyvsp[(1) - (3)].ptr)->type!=0 && (yyvsp[(3) - (3)].ptr)->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						(yyval.ptr)=createnodeop('<',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
						(yyval.ptr)->type=1;
						}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 371 "parser.y"
    { if((yyvsp[(1) - (3)].ptr)->type!=0 && (yyvsp[(3) - (3)].ptr)->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						(yyval.ptr)=createnodeop('e',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
						(yyval.ptr)->type=1;
						}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 378 "parser.y"
    { if((yyvsp[(1) - (3)].ptr)->type!=0 && (yyvsp[(3) - (3)].ptr)->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						(yyval.ptr)=createnodeop('l',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
						(yyval.ptr)->type=1;
						}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 385 "parser.y"
    { if((yyvsp[(1) - (3)].ptr)->type!=0 && (yyvsp[(3) - (3)].ptr)->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						(yyval.ptr)=createnodeop('g',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
						(yyval.ptr)->type=1;
						}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 392 "parser.y"
    { if((yyvsp[(1) - (3)].ptr)->type!=0 && (yyvsp[(3) - (3)].ptr)->type!=0)
						{	printf("Type Error");
							exit(0);
						}
						(yyval.ptr)=createnodeop('f',(yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr)); 
						(yyval.ptr)->type=1;
						}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 400 "parser.y"
    {	(yyval.ptr)=createnodebool(1,NULL,NULL);	}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 401 "parser.y"
    {	(yyval.ptr)=createnodebool(0,NULL,NULL);	}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 402 "parser.y"
    {	(yyval.ptr)=createnodenum(yylval.num,NULL,NULL);		}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 403 "parser.y"
    { int a; 
		a=yylval.num-2*yylval.num;
		(yyval.ptr)=createnodenum(a,NULL,NULL);
		}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 409 "parser.y"
    {	(yyval.ptr)=createnodeid((yyvsp[(1) - (1)].ch),NULL,NULL); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 410 "parser.y"
    {	temp=createnodenum(yylval.num,NULL,NULL);
				(yyval.ptr)=createnodearrid((yyvsp[(1) - (4)].ch),NULL,NULL,temp);
					}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 413 "parser.y"
    {	temp=createnodeid((yyvsp[(3) - (4)].ch),NULL,NULL);
				(yyval.ptr)=createnodearrid((yyvsp[(1) - (4)].ch),NULL,NULL,temp);
					}
    break;



/* Line 1455 of yacc.c  */
#line 2362 "y.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 416 "parser.y"

int main()
{extern FILE* yyin;
fp=fopen("output.sim","w+"); 
yyin=fopen("input.txt","r+");
yyparse();
}
yyerror(char *s)
{	 printf("%s",s);
}



void icg(struct node *n)
{		int l1,l2; 
	if(n==NULL)
	return ;
	if(n->flag==0)
	{ 	fprintf(fp,"MOV R%d,%d\n",rc,n->val);
		rc++;
		return ;
	}
	if(n->flag==2)
	{	gtmp=gsymtbllookup(n->name);
		if(gtmp==NULL) 	
		{	fprintf(fp,"MOV R%d,%d\n",rc,n->sym->index);
			fprintf(fp,"MOV R%d,BP\n",rc+1);
			fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
			fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
			rc++;
		}
		else	
		{fprintf(fp,"MOV R%d,[%d]\n",rc,n->sym->index);
		rc++;
		}
		return;	
	}
	if(n->flag==3)
	{
	icg(n->left);
	icg(n->right);
	return ;
	}
	if(n->flag==5)
	{	//INITIALIZE SP
		fprintf(fp,"MOV R%d,SP\n",rc);
		fprintf(fp,"MOV R%d,%d\n",rc+1,s-1);
		fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
		fprintf(fp,"MOV SP,R%d\n",rc);
		int i;
		for(i=0;i<rc;i++)
		{	fprintf(fp,"PUSH R%d\n",i);
		}
		atmp=n->sym->arglist;
		fprintf(fp,"MOV R%d,BP\n",rc);
		fprintf(fp,"PUSH R%d\n",rc);
		if(atmp!=NULL)
		while(atmp->next!=NULL)
		{	atmp=atmp->next;
		}
		while(atmp!=NULL)
		{	if(atmp->arg->flag==2)		
			{	gtmp=gsymtbllookup(atmp->arg->name);
				if(gtmp!=NULL)
				 {	fprintf(fp,"MOV R%d,[%d]\n",rc,atmp->arg->sym->index);
				}
				else
				{	fprintf(fp,"MOV R%d,%d\n",rc,atmp->arg->sym->index);
					fprintf(fp,"MOV R%d,BP\n",rc+1);
					fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
					fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
				}
			}
			if(atmp->arg->flag==4)
			{	if(atmp->arg->center->flag==0) 
				{
					fprintf(fp,"MOV R%d,[%d]\n",rc,atmp->arg->sym->index+atmp->arg->center->val);
					
				}
				else
				{	gtmp=gsymtbllookup(atmp->arg->center->name);
					if(gtmp!=NULL)
					{	fprintf(fp,"MOV R%d,[%d]\n",rc,atmp->arg->center->sym->index);
				
						fprintf(fp,"MOV R%d,%d\n",rc+1,atmp->arg->sym->index);
				
  						fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
				
						fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
					}
					else
					{	fprintf(fp,"MOV R%d,%d\n",rc,atmp->arg->center->sym->index);
						fprintf(fp,"MOV R%d,BP\n",rc+1);
						fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
						fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
						fprintf(fp,"MOV R%d,%d\n",rc+1,atmp->arg->sym->index);
				
  						fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
				
						fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
					}
				}
			}
		
			if(atmp->arg->flag==0)
			fprintf(fp,"MOV R%d,%d\n",rc,atmp->arg->val);
			fprintf(fp,"PUSH R%d\n",rc);
			atmp=atmp->prev;
		}
		
		fprintf(fp,"MOV R%d,SP\n",rc);
		fprintf(fp,"MOV R%d,1\n",rc+1);
		fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
		fprintf(fp,"MOV BP,R%d\n",rc);		  
		fprintf(fp,"CALL %s\n",n->sym->name);
		fprintf(fp,"POP R%d\n",rc);
		fprintf(fp,"MOV R%d,SP\n",rc);
		fprintf(fp,"MOV R%d,%d\n",rc+1,n->sym->size);
		fprintf(fp,"SUB R%d,R%d\n",rc,rc+1);	
		fprintf(fp,"MOV R%d,SP\n",rc);
		fprintf(fp,"MOV BP,[R%d]\n",rc);
		fprintf(fp,"POP R%d\n",rc);
		for(i=rc-1;i>=0;i--)
		fprintf(fp,"POP R%d\n",i);
	}
	if(n->flag==4)
	{	if(n->center->flag==0) 
		{
		fprintf(fp,"MOV R%d,[%d]\n",rc,n->sym->index+n->center->val);
		rc++;
		}
		else
		{	gtmp=gsymtbllookup(n->center->name);
			if(gtmp!=NULL)
			{	fprintf(fp,"MOV R%d,[%d]\n",rc,n->center->sym->index);
				rc++;
				fprintf(fp,"MOV R%d,%d\n",rc,n->sym->index);
				rc++;
  				fprintf(fp,"ADD R%d,R%d\n",rc-2,rc-1);
				rc--;
				fprintf(fp,"MOV R%d,[R%d]\n",rc-1,rc-1);
			}
			else
			{	fprintf(fp,"MOV R%d,%d\n",rc,n->center->sym->index);
				fprintf(fp,"MOV R%d,BP\n",rc+1);
				fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
				fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
				fprintf(fp,"MOV R%d,%d\n",rc+1,n->sym->index);
				
  				fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
				
				fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
				rc++;
			}
		}
	}
	if(n->flag==1)
	{ 	switch(n->op)
		{	case '+': 	icg(n->left);
						icg(n->right);
						fprintf(fp,"ADD R%d,R%d\n",rc-2,rc-1);
						rc--;
						break ;
			case '-': 	icg(n->left);
						icg(n->right);
						fprintf(fp,"SUB R%d,R%d\n",rc-2,rc-1);
						rc--;
						break ;
			case '*': 	icg(n->left);
						icg(n->right);
						fprintf(fp,"MUL R%d,R%d\n",rc-2,rc-1);
						rc--;
						break ;
			case '/': 	icg(n->left);
						icg(n->right);
						fprintf(fp,"DIV R%d,R%d\n",rc-2,rc-1);
						rc--;
						break ;
			case '=': 		
					icg(n->right);	
						gtmp=gsymtbllookup(n->left->name);
						if(gtmp==NULL)
						{		fprintf(fp,"MOV R%d,%d\n",rc,n->left->sym->index);
								fprintf(fp,"MOV R%d,BP\n",rc+1);
								fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
								if(n->right->flag==5)
								{gtmp=gsymtbllookup(n->right->name);
								fprintf(fp,"MOV [R%d],[%d]\n",rc,gtmp->index);
								}
								else
								{fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1); rc--;}
						}			
						else
						{		
								if(n->right->flag==5)
								{gtmp=gsymtbllookup(n->right->name);
								fprintf(fp,"MOV [%d],[%d]\n",n->left->sym->index,gtmp->index);
								}
								else if(n->left->flag==4)
								{	if(n->left->center->flag==0) 
									{
								fprintf(fp,"MOV [%d],R%d\n",n->left->sym->index+n->left->center->val,rc-1);
								
									rc--;
									}
									else
									{	gtmp=gsymtbllookup(n->left->center->name);
										if(gtmp!=NULL)
										{fprintf(fp,"MOV R%d,[%d]\n",rc,n->left->center->sym->index);
							
										fprintf(fp,"MOV R%d,%d\n",rc+1,n->left->sym->index);
							
  										fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
								
										fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1);
								
										rc--;
										}
										else
										{	fprintf(fp,"MOV R%d,%d\n",rc,n->left->center->sym->index);
											fprintf(fp,"MOV R%d,BP\n",rc+1);
											fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
											fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
											fprintf(fp,"MOV R%d,%d\n",rc+1,n->left->sym->index);
							
  											fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
							
											fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1);
											rc--;
										}
							
									}
								}
								else
								{fprintf(fp,"MOV [%d],R%d\n",n->left->sym->index,rc-1); rc--;}

						}
						
						break;
			case 'r': 	
						fprintf(fp,"IN R%d\n",rc);
						rc++;
						if(n->right->flag==2)
						{	gtmp=gsymtbllookup(n->name);
							if(gtmp==NULL)
							{	fprintf(fp,"MOV R%d,%d\n",rc,n->right->sym->index);
								fprintf(fp,"MOV R%d,BP\n",rc+1);
								fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
								fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1);
								rc--;
							}
							else
							{fprintf(fp,"MOV [%d],R%d\n",n->right->sym->index,rc-1);
							rc-=1;}
						}	
						if(n->right->flag==4)
						{	if(n->right->center->flag==0) 
							{
								fprintf(fp,"MOV [%d],R%d\n",n->right->sym->index+n->right->center->val,rc-1);
								rc--;
							}
							else
							{	gtmp=gsymtbllookup(n->right->center->name);
								if(gtmp!=NULL)
								{fprintf(fp,"MOV R%d,[%d]\n",rc,n->right->center->sym->index);
							
								fprintf(fp,"MOV R%d,%d\n",rc+1,n->right->sym->index);
							
  								fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
							
								fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1);
								rc--;
								}
								else
								{fprintf(fp,"MOV R%d,%d\n",rc,n->right->center->sym->index);
								fprintf(fp,"MOV R%d,BP\n",rc+1);
								fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
								fprintf(fp,"MOV R%d,[R%d]\n",rc,rc);
								fprintf(fp,"MOV R%d,%d\n",rc+1,n->right->sym->index);
							
  								fprintf(fp,"ADD R%d,R%d\n",rc,rc+1);
							
								fprintf(fp,"MOV [R%d],R%d\n",rc,rc-1);
								rc--;
								}
							}
						}
											
						break;
			case 'w': 		icg(n->right);
						fprintf(fp,"OUT R%d\n",rc-1);
						rc--;
						break;

			case 'e': 		icg(n->left); icg(n->right);
						fprintf(fp,"EQ R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;
			case 'l':		icg(n->left); icg(n->right);
						fprintf(fp,"LE R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;
			case 'g':		icg(n->left); icg(n->right);
						fprintf(fp,"GE R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;
			case '>':		icg(n->left); icg(n->right);
						fprintf(fp,"GT R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;
			case '<':		icg(n->left); icg(n->right);
						fprintf(fp,"LT R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;
			case 'f':		icg(n->left); icg(n->right);
						fprintf(fp,"NE R%d,R%d\n",rc-2,rc-1);
						rc--;
						break;

			case 'c': 		l1=l; l++;
						icg(n->left);
						fprintf(fp,"JZ R%d,L%d\n",rc-1,l1);
						rc--;						
						icg(n->right);
						fprintf(fp,"L%d:\n",l1);
						break;
			case 'd': 		l1=l; l2=l+1; l+=2;
						icg(n->left);
						fprintf(fp,"JZ R%d,L%d\n",rc-1,l1);
						rc--;
						icg(n->center);
						fprintf(fp,"JMP L%d\n",l2);
						fprintf(fp,"L%d:\n",l1);
						l++;
						icg(n->right);
						fprintf(fp,"L%d:\n",l2);
						l++;
						break;
			case 'i':   	
					
						l1=l;
						l2=l+1;
						l=l+2;
						fprintf(fp,"L%d:\n",l1);
						icg(n->left);
						fprintf(fp,"JZ R%d,L%d\n",rc-1,l2);
						rc--;
						icg(n->right);
						fprintf(fp,"JMP L%d\n",l1);
						fprintf(fp,"L%d:\n",l2);
						l++;
						break;
			case 'v': 		icg(n->right);				
						gtmp=gsymtbllookup(n->left->name);
						fprintf(fp,"MOV [%d],R%d\n",gtmp->index,rc-1);
						fprintf(fp,"MOV R%d,BP\n",rc);
						fprintf(fp,"MOV SP,R%d\n",rc);
						fprintf(fp,"RET\n");
						rc--;
						break;
		}
	}
}


struct node* createnodeid(char *name,struct node *n1,struct node *n2)
{	
	temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->name,name);
	struct symtbl *t;
	t=lsymtbllookup(name);
	if(t==NULL)
	t=gsymtbllookup(name);
	if(t==NULL)
	{	printf("Variable %s used without declaration",name);
		exit(0);
	}
	if(t->size!=1)
	{ printf("Error:Variable %s is an array",name);
	exit(0);
	}
	printf("Matched entry %s",t->name);
	temp->sym=t;
	temp->type=t->type;
	temp->flag=2;
	temp->left=n1;
	temp->right=n2;
	return temp;
}

struct node* createnodefunc(char *name,struct node *n1,struct node *n2)
{	
	temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->name,name);
	struct symtbl *t;
	t=gsymtbllookup(name);
	if(t==NULL)
	{	printf("Function %s used without declaration",name);
		exit(0);
	}
	printf("Matched entry %s",t->name);
	temp->sym=t;
	temp->type=t->type;
	temp->flag=5;
	temp->left=n1;
	temp->right=n2;
	return temp;
}
struct node* createnodenum(int val,struct node *n1,struct node *n2)	
{	temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->op='\0';
	temp->type=0;
	temp->flag=0;
	temp->left=n1;
	temp->right=n2;
	return temp;
}
struct node* createnodeop(char op,struct node *n1,struct node *n2)	
{	temp=(struct node*)malloc(sizeof(struct node));
	temp->op=op;
	temp->type=2;
	temp->flag=1;
	temp->left=n1;
	temp->right=n2;
}
struct node* createnodecond(char op,struct node *n1,struct node *n2,struct node *n3)	
{	temp=(struct node*)malloc(sizeof(struct node));
	temp->op=op;
	temp->type=2;
	temp->flag=1;
	temp->left=n1;
	temp->center=n2;
	temp->right=n3;
}
struct node* createnodebool(int val,struct node *n1,struct node *n2)	
{	temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->op='\0';
	temp->type=1;
	temp->flag=0;
	temp->left=n1;
	temp->right=n2;
	return temp;
}
struct node* createnodevoid(struct node* n1,struct node* n2)
{	temp=(struct node*)malloc(sizeof(struct node));
	temp->type=2;
	temp->flag=3;
	temp->left=n1;
	temp->right=n2;
	return temp;
}

struct node* createnodearrid(char *name,struct node *n1,struct node *n2,struct node*n3)
{	temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->name,name);
	struct symtbl *t;
	t=gsymtbllookup(name);
	if(t==NULL)
	{	printf("Variable %s used without declaration",name);
		exit(0);
	}
	printf("Matched entry %s",t->name);
	temp->sym=t;
	temp->type=t->type;
	temp->flag=4;
	temp->left=n1;
	temp->right=n2;
	temp->center=n3;
	return temp;
}
void inorder(struct node *n)
{ if(n==NULL)
	return ;
 inorder(n->left);
 printf("node: %d\n%c\n%d\n",n->val,n->op,n->flag);
 inorder(n->right);
}

struct symtbl * insertgsymtbl(char *name,int type,int s)
{ 	gtmp=gsymtbllookup(name);
	if(gtmp!=NULL)
	{printf("ERROR:MULTIPLE DECLARATION");
	exit(0);
	}
	gtmp=(struct symtbl*)malloc(sizeof(struct symtbl));
	strcpy(gtmp->name,name);
	gtmp->type=type;
	gtmp->size=s;
	gtmp->next=NULL;
	gtmp->index=in;
	in+=s;
	if(gbegin==NULL)
	{gbegin=gend=gtmp;
	}
	else
	{gend->next=gtmp;
	gend=gtmp;
	}
	return gtmp;
}

struct symtbl *  gsymtbllookup(char *name)
{	gtmp=gbegin;
	while(gtmp!=NULL)
	{	if(!strcmp(gtmp->name,name))
		return gtmp;
		gtmp=gtmp->next;		
	}
	return NULL;
}
void traversegsymtbl()
{	gtmp=gbegin;
	while(gtmp!=NULL)
	{	printf("%s\t",gtmp->name);
		printf("%d\n",gtmp->type);
		printf("%d",gtmp->size);
		gtmp=gtmp->next;		
	}
	
}
struct symtbl * insertlsymtbl(char *name,int type,int index)
{ 	ltmp=lsymtbllookup(name);
	if(ltmp!=NULL)
	{printf("ERROR:MULTIPLE DECLARATION");
	exit(0);
	}
	ltmp=(struct symtbl*)malloc(sizeof(struct symtbl));
	strcpy(ltmp->name,name);
	ltmp->type=type;
	ltmp->next=NULL;
	ltmp->size=1;
	ltmp->index=index;
	if(lbegin==NULL)
	{lbegin=lend=ltmp;
	}
	else
	{lend->next=ltmp;
	lend=ltmp;
	}
	return ltmp;
}

struct symtbl *  lsymtbllookup(char *name)
{	ltmp=lbegin;
	while(ltmp!=NULL)
	{	if(!strcmp(ltmp->name,name))
		return ltmp;
		ltmp=ltmp->next;		
	}
	return NULL;
}
void traverselsymtbl()
{	
	ltmp=lbegin;
	while(ltmp!=NULL)
	{	printf("%s\t",ltmp->name);
		printf("%d\n",ltmp->type);
		ltmp=ltmp->next;		
	}
	
}
struct argstruct * insertargstruct(char *name,int type)
{ 	atmp=argstructlookup(name);
	if(atmp!=NULL)
	{printf("ERROR:MULTIPLE ARGUMENT DECLARATION");
	exit(0);
	}
	atmp=(struct argstruct*)malloc(sizeof(struct argstruct));
	strcpy(atmp->name,name);
	atmp->type=type;
	atmp->next=NULL;
	atmp->prev=NULL;
	if(abegin==NULL)
	{abegin=aend=atmp; 
	}
	else
	{aend->next=atmp;
	atmp->prev=aend;
	aend=atmp;
	}
	return atmp;
}

struct argstruct * argstructlookup(char *name)
{	atmp=abegin;
	while(atmp!=NULL)
	{	if(!strcmp(atmp->name,name))
		return atmp;
		atmp=atmp->next;		
	}
	return NULL;
}

