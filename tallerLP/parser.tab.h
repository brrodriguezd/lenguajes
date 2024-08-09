/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "parser.y"

    #include "ast.h"

#line 53 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    CADENA = 259,                  /* CADENA  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    ALFABETO = 262,                /* ALFABETO  */
    ASSIGN = 263,                  /* ASSIGN  */
    TYPE_INT = 264,                /* TYPE_INT  */
    TYPE_FLOAT = 265,              /* TYPE_FLOAT  */
    TYPE_CADENA = 266,             /* TYPE_CADENA  */
    TYPE_MODELO = 267,             /* TYPE_MODELO  */
    TYPE_CAD_MULT = 268,           /* TYPE_CAD_MULT  */
    WHILE = 269,                   /* WHILE  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    THEN = 272,                    /* THEN  */
    LB = 273,                      /* LB  */
    RB = 274,                      /* RB  */
    LP = 275,                      /* LP  */
    RP = 276,                      /* RP  */
    LS = 277,                      /* LS  */
    RS = 278,                      /* RS  */
    EQ = 279,                      /* EQ  */
    NE = 280,                      /* NE  */
    LE = 281,                      /* LE  */
    GE = 282,                      /* GE  */
    LT = 283,                      /* LT  */
    GT = 284,                      /* GT  */
    PLUS = 285,                    /* PLUS  */
    MINUS = 286,                   /* MINUS  */
    MUL = 287,                     /* MUL  */
    DIV = 288,                     /* DIV  */
    MOD = 289,                     /* MOD  */
    SIZE = 290,                    /* SIZE  */
    CAT = 291,                     /* CAT  */
    COMMA = 292,                   /* COMMA  */
    SEMICOLON = 293,               /* SEMICOLON  */
    PRINT = 294                    /* PRINT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.y"

    int ival;
    float fval;
    char *sval;
    ASTNode *ast;
    char *cval; //este es de un solo caracter

#line 117 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */