
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 52 "parser.y"
 	int num; 
		char ch[10];
		struct node *ptr;
	


/* Line 1676 of yacc.c  */
#line 117 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


