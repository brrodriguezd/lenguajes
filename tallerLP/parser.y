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
    char *cval; //este es de un solo caracter
}

%token <sval> IDENTIFIER CADENA
%token <ival> INT
%token <fval> FLOAT
%token <cval> ALFABETO
%token ASSIGN TYPE_INT TYPE_FLOAT TYPE_CADENA TYPE_MODELO  TYPE_CAD_MULT
%token WHILE IF ELSE THEN
%token LB RB LP RP LS RS
%token EQ NE LE GE LT GT
%token PLUS MINUS MUL DIV MOD SIZE CAT
%token COMMA SEMICOLON

%right LS
%left EQ NE LE GE LT GT
%right PLUS MINUS CAT
%left MUL DIV MOD SIZE 
%token PRINT


%type <ast> program stmt block expr declaracion array print condicion reassign

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
    WHILE condicion LB block RB { $$ = createNode(_WHILE, $2, $4); }
    | IF condicion LB block RB { $$ = createNode(_IF, $2, $4); }
    | IF condicion LB block RB ELSE LB block RB { $$ = createNode(_ELSE, createNode(_IF, $2, $4), $8); }
    | expr SEMICOLON
    | declaracion SEMICOLON
    | reassign SEMICOLON
    | print SEMICOLON
    ;

expr:
    CADENA { $$ = createStringNode($1); }
    | IDENTIFIER { $$ = createIdentifierNode($1); }
    | FLOAT { $$ = createFloatNode($1); }
    | INT { $$ = createIntNode($1); }
    | ALFABETO { $$ = createIdentifierNode($1); }
    | LP expr RP { $$ = $2; }
    | LS array RS { $$ = $2; }
    | expr LS expr RS { $$ = createNode(_SVARR, $1, $3); }
    | expr PLUS expr { $$ = createNode(_PLUS, $1, $3); }
    | expr MINUS expr { $$ = createNode(_MINUS, $1, $3); }
    | expr MUL expr { $$ = createNode(_MUL, $1, $3); }
    | expr DIV expr { $$ = createNode(_DIV, $1, $3); }
    | expr MOD expr { $$ = createNode(_MOD, $1, $3); }
    | expr SIZE { $$ = createNode(_SIZE, $1, NULL); }
    | expr CAT { $$ = createNode(_CAT, $1, NULL); }
    ;

condicion:
    LP condicion RP { $$ = $2; }
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
        }else if ($1->type == _FLOAT_ARR){
            farray *var = malloc(sizeof(farray));
            *var.array = $1->value.farray;
            $$ = createFloatArrNode(var,1);

        }else{
            printf("No se permiten arreglos del tipo %s", get_enum_name($1->type));
            exit(EXIT_FAILURE);
        }
    }
    ;

reassign:
    IDENTIFIER ASSIGN expr { $$ = createNode(_RELOC, createIdentifierNode($1), $3); }
    | expr LS expr RS ASSIGN expr { $$ = createNode(_RELOC_ARR, $1, createNode(_RELOC_ARR_AUX, $3, $6)); }
    ;

declaracion:
    TYPE_INT IDENTIFIER ASSIGN expr { $$ = createNode(_aINT, createIdentifierNode($2), $4); }
    | TYPE_FLOAT IDENTIFIER ASSIGN expr { $$ = createNode(_aFLOAT, createIdentifierNode($2), $4); }
    | TYPE_CADENA IDENTIFIER ASSIGN expr { $$ = createNode(_aCADENA, createIdentifierNode($2), $4); }
    | TYPE_INT MUL IDENTIFIER ASSIGN expr { $$ = createNode(_aINT_ARR, createIdentifierNode($3), $5); }
    | TYPE_FLOAT MUL IDENTIFIER ASSIGN expr { $$ = createNode(_aFLOAT_ARR,createIdentifierNode($3), $5); }
    | TYPE_CAD_MULT IDENTIFIER ASSIGN LB expr COMMA expr COMMA expr RB 
    { $$ = createNode(_aCADE_MULTI,createIdentifierNode($2), createNode(_aCADE_MULTI, $5, createNode(_aCADE_MULTI, $7, $9))); }
    | TYPE_FLOAT MUL MUL IDENTIFIER ASSIGN expr { $$ = createNode(_aFLOAT_MAT,createIdentifierNode($4), $6); }
    | TYPE_MODELO IDENTIFIER ASSIGN LB expr COMMA expr COMMA expr COMMA expr COMMA expr COMMA expr RB 
    { $$ = createNode(_aMODELO,createIdentifierNode($2), createNode(_aMODELO, $5, createNode(_aMODELO, $7, createNode(_aMODELO, $9, createNode(_aMODELO, $11, 
        createNode(_aMODELO, $13, $15)))))); }
    | ALFABETO ASSIGN expr { $$ = createNode(_aALFABETO, createIdentifierNode($1), $3); }
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
