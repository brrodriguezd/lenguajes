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
    A = 263,                       /* A  */
    B = 264,                       /* B  */
    N = 265,                       /* N  */
    M = 266,                       /* M  */
    MATRIZ = 267,                  /* MATRIZ  */
    TAU = 268,                     /* TAU  */
    ASSIGN = 269,                  /* ASSIGN  */
    TYPE_INT = 270,                /* TYPE_INT  */
    TYPE_FLOAT = 271,              /* TYPE_FLOAT  */
    TYPE_CADENA = 272,             /* TYPE_CADENA  */
    TYPE_MODELO = 273,             /* TYPE_MODELO  */
    TYPE_CAD_MULT = 274,           /* TYPE_CAD_MULT  */
    WHILE = 275,                   /* WHILE  */
    IF = 276,                      /* IF  */
    ELSE = 277,                    /* ELSE  */
    THEN = 278,                    /* THEN  */
    LB = 279,                      /* LB  */
    RB = 280,                      /* RB  */
    LP = 281,                      /* LP  */
    RP = 282,                      /* RP  */
    LS = 283,                      /* LS  */
    RS = 284,                      /* RS  */
    EQ = 285,                      /* EQ  */
    NE = 286,                      /* NE  */
    LE = 287,                      /* LE  */
    GE = 288,                      /* GE  */
    LT = 289,                      /* LT  */
    GT = 290,                      /* GT  */
    PLUS = 291,                    /* PLUS  */
    MINUS = 292,                   /* MINUS  */
    MUL = 293,                     /* MUL  */
    DIV = 294,                     /* DIV  */
    MOD = 295,                     /* MOD  */
    SIZE = 296,                    /* SIZE  */
    CAT = 297,                     /* CAT  */
    COMMA = 298,                   /* COMMA  */
    SEMICOLON = 299,               /* SEMICOLON  */
    PRINT = 300                    /* PRINT  */
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

#line 123 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
