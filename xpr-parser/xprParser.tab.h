/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_XPRPARSER_TAB_H_INCLUDED
# define YY_YY_XPRPARSER_TAB_H_INCLUDED
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
    COMMENT = 272,
    ADD = 273,
    SUB = 274,
    MUL = 275,
    DIV = 276,
    MOD = 277,
    LT = 278,
    GT = 279,
    LE = 280,
    GE = 281,
    EE = 282,
    NE = 283,
    AND = 284,
    OR = 285,
    ALNUM = 286,
    ALPHA = 287,
    DIGIT = 288,
    HEXDGT = 289,
    DECLIT = 290,
    HEXLIT = 291,
    STRINGLIT = 292,
    CHARLIT = 293,
    ID = 294,
    NOT = 295,
    OPENCIRC = 296,
    CLOSECIRC = 297,
    OPENSQR = 298,
    CLOSESQR = 299,
    OPENFLWR = 300,
    CLOSEFLWR = 301,
    COMMA = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_XPRPARSER_TAB_H_INCLUDED  */
