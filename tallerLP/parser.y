%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern FILE *yyin;
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int yylex(void);
%}

%code requires{
    #include "ast.h"
}

%union {
    int ival;
    float fval;
    char *sval;
    ASTNode *ast;
}

%token <sval> IDENTIFIER CADENA
%token <ival> INT
%token <fval> FLOAT
%token ASSIGN TYPE_INT TYPE_INT_ARRAY TYPE_FLOAT TYPE_FLOAT_ARRAY TYPE_CADENA TYPE_MODELO
%token WHILE IF ELSE THEN
%token LB RB LP RP LS RS
%token EQ NE LE GE LT GT
%token PLUS MINUS MUL DIV MOD
%token COMMA

%left EQ NE LE GE LT GT
%right PLUS MINUS
%left MUL DIV MOD
%token PRINT


%type <ast> program stmt block expr declaracion array array_float array_int

%%

program:
    block { 
        printAST($1, 0); 
        executeAST($1);
    }
    ;

block:
    block stmt { $$ = createNode(_BLOCK, $1, $2); }
    | /* empty */ { $$ = NULL; }
    ;

stmt:
    WHILE expr LB block RB { $$ = createNode(_WHILE, $2, $4); }
    | IF expr LB block RB { $$ = createNode(_IF, $2, $4); }
    | IF expr LB block RB ELSE LB block RB { $$ = createNode(_IF, $2, createNode(_ELSE, $4, $8)); }
    | expr
    | declaracion
    ;

expr:
    LP expr RP { $$ = $2; }
    | LS array RS { $$ = $2; }
    | CADENA { $$ = createStringNode($1); }
    | IDENTIFIER { createIdentifierNode($1); }
    | expr PLUS expr { $$ = createNode(_PLUS, $1, $3); }
    | expr MINUS expr { $$ = createNode(_MINUS, $1, $3); }
    | expr MUL expr { $$ = createNode(_MUL, $1, $3); }
    | expr DIV expr { $$ = createNode(_DIV, $1, $3); }
    | expr MOD expr { $$ = createNode(_MOD, $1, $3); }
    | expr EQ expr { $$ = createNode(_EQ, $1, $3); }
    | expr NE expr { $$ = createNode(_NE, $1, $3); }
    | expr LE expr { $$ = createNode(_LE, $1, $3); }
    | expr GE expr { $$ = createNode(_GE, $1, $3); }
    | expr LT expr { $$ = createNode(_LT, $1, $3); }
    | expr GT expr { $$ = createNode(_GT, $1, $3); }
    ;

array:
    array_int
    | array_float
    ;

array_int:
    array_int COMMA INT
    {
        ASTNode *val = $1;
        void *result = realloc(val->value.ival.array, (++val->value.ival.size)* sizeof(int));
        if (result == NULL){
            printf("Espacio lleno");
            exit(EXIT_FAILURE);
        }
        val->value.ival.array[val->value.ival.size - 1] = $3;
        $$ = val;
    }
    | INT
    { 
        int *val = malloc(sizeof(int));
        *val = $1;
        $$ = createIntNode(val, 1); 
    }
    ;

array_float:
    array_float COMMA FLOAT
    {
        ASTNode *val = $1;
        void *result = realloc(val->value.fval.array, (++val->value.fval.size)* sizeof(float));
        if (result == NULL){
            printf("Espacio lleno");
            exit(EXIT_FAILURE);
        }
        val->value.fval.array[val->value.fval.size - 1] = $3;
        $$ = val;
    }
    | FLOAT
    { 
        float *val = malloc(sizeof(float));
        *val = $1;
        $$ = createFloatNode(val, 1); 
    }
    ;
declaracion:
    TYPE_INT IDENTIFIER ASSIGN expr { $$ = createNode(_aINT, createIdentifierNode($2), $4); }
    | TYPE_FLOAT IDENTIFIER ASSIGN expr { $$ = createNode(_aFLOAT, createIdentifierNode($2), $4); }
    | TYPE_CADENA IDENTIFIER ASSIGN expr { $$ = createNode(_aCADENA, createIdentifierNode($2), $4); }
    ;

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    }
    yyparse();
    return 0;
}
