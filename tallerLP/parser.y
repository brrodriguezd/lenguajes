%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "symtab.h"

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
%token ASSIGN TYPE_INT TYPE_FLOAT TYPE_CADENA TYPE_MODELO
%token WHILE IF ELSE THEN
%token LB RB LP RP LS RS
%token EQ NE LE GE LT GT
%token PLUS MINUS MUL DIV MOD
%token COMMA

%left EQ NE LE GE LT GT
%right PLUS MINUS
%left MUL DIV MOD
%token PRINT


%type <ast> program stmt block expr declaracion array print

%%

program:
    block { 
        printf("ARBOL:\n");
        printAST($1, 0); 
        printf("RESULTADOS:\n");
        executeAST($1);
    }
    ;

block:
    stmt block { $$ = createNode(_BLOCK, $1, $2); }
    | /* empty */ { $$ = NULL; }
    ;

stmt:
    WHILE expr LB block RB { $$ = createNode(_WHILE, $2, $4); }
    | IF expr LB block RB { $$ = createNode(_IF, $2, $4); }
    | IF expr LB block RB ELSE LB block RB { $$ = createNode(_IF, $2, createNode(_ELSE, $4, $8)); }
    | expr
    | declaracion
    | print
    ;

expr:
    CADENA { $$ = createStringNode($1); }
    | IDENTIFIER { $$ = createIdentifierNode($1); }
    | FLOAT { $$ = createFloatNode($1); }
    | INT { $$ = createIntNode($1); }
    | LP expr RP { $$ = $2; }
    | LS array RS { $$ = $2; }
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
    array COMMA expr
    {
        if($1->type == _INT_ARR && $3->type == _INT){
            ASTNode *val = $1;
            void *result = realloc(val->value.iarr.array, (++val->value.iarr.size)* sizeof(int));
            if (result == NULL){
                printf("Espacio lleno");
                exit(EXIT_FAILURE);
            }
            val->value.iarr.array[val->value.iarr.size - 1] = $3->value.ival;
            $$ = val;
        }
        else if($1->type == _FLOAT_ARR && $3->type == _FLOAT){
            ASTNode *val = $1;
            void *result = realloc(val->value.farr.array, (++val->value.farr.size)* sizeof(float));
            if (result == NULL){
                printf("Espacio lleno");
                exit(EXIT_FAILURE);
            }
            val->value.farr.array[val->value.farr.size - 1] = $3->value.fval;
            $$ = val;
        }else{
            printf("Los arreglos deben ser del mismo tipo");
            exit(EXIT_FAILURE);
        }
    }
    | expr 
    {
        if ($1->type == _INT){
            int *var = malloc(sizeof(int));
            *var = $1->value.ival;
            $$ = createIntArrNode(var,1);
        }else if ($1->type == _FLOAT){
            float *var = malloc(sizeof(float));
            *var = $1->value.fval;
            $$ = createFloatArrNode(var,1);
        }else{
            printf("No se permiten arreglos del tipo %s", get_enum_name($1->type));
            exit(EXIT_FAILURE);
        }
    }
    ;

declaracion:
    TYPE_INT IDENTIFIER ASSIGN expr { $$ = createNode(_aINT, createIdentifierNode($2), $4); }
    | TYPE_FLOAT IDENTIFIER ASSIGN expr { $$ = createNode(_aFLOAT, createIdentifierNode($2), $4); }
    | TYPE_CADENA IDENTIFIER ASSIGN expr { $$ = createNode(_aCADENA, createIdentifierNode($2), $4); }
    | TYPE_INT IDENTIFIER LS expr RS ASSIGN array { $$ = createNode(_aINT_ARR, createIdentifierNode($2), $4); }
    | TYPE_FLOAT IDENTIFIER LS expr RS ASSIGN array { $$ = createNode(_aFLOAT_ARR, createIdentifierNode($2), $4); }
    
    ;

print:
    PRINT LP expr RP {
        $$ = createNode(_PRINT, $3, NULL); 
    };
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
