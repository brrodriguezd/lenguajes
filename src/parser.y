%{
#include <stdio.h>
#include <string.h>
#include "./lib/linked_list.c"

int yylex(void);
int yyerror(char* s);
int regs[26] = {0}; //26 del alfabeto
char* str;
int caracter;
linked_list lista;
%}

%start list

%code requires {
  #include "./lib/expr.h"
}

%union { int a; char* s; int i; float f; expr e;} /*Definición de tipos*/


%token <s> CADENA
%token <a> ALFABETO
%token <i> ENTERO 
%token <f> FLOTANTE

%token IF
%token ELSE
%token FOR
%token WHILE

%token EQ
%token NE
%token LE
%token GE

%left '?'
%left '+' '-'
%left '*' '/' '%'

%type<s> racha
%type<e> expr
%type<e> for_expr
%type<e> while_expr
%type<e> if_expr
%type<i> condition
%%                   /* beginning of rules section */

list:                       /*empty */
         |
        list stat '\n'
         |
        list error '\n'
         {
           yyerrok;
         }
         ;
stat:    expr 
         {
          if($1.tipo == 1){
            int *ptr = $1.ptr;
            printf("expr: %d\n", *ptr);
          }else if($1.tipo == 2){
            float *ptr = $1.ptr;
            printf("expr: %f\n", *ptr);
          }else if($1.tipo == 3){
            printf("expr: %s\n", $1);
          }
         }
         |
         racha
         {
          while (lista.head != NULL){
            int c = PopFront(&lista);
            int d = PopFront(&lista);
            printf("%c: %d\n", c, d);
          }
         }
         ;
expr:   expr '*' expr 
        {
          expr new_expr;
          if ($1.tipo == 3 && $3.tipo == 3){
            char *expr1 = $1.ptr;
            char *expr2 = $3.ptr;
            int size = strlen(expr1) + strlen(expr2);
            printf("size: %d\n", size);
            char *new_str = malloc(size*sizeof(char));
            int i = 0;
            for (char *iter = expr1; *iter != '\0'; iter++) {
              printf("char %d: %c\n", i, *iter);
              new_str[i] = *iter;
              i++;
            }
            for (char *iter = expr2; *iter != '\0'; iter++) {
              printf("char %d: %c\n", i, *iter);
              new_str[i] = *iter;
              i++;
            }
            create_string(&new_expr, new_str);
            $$ = new_expr;
          }else if ($1.tipo == 1 && $3.tipo == 1){
            int *expr1 = $1.ptr;
            int *expr2 = $3.ptr;
            printf("%d, %d\n", *expr1, *expr2);
            int *new_int = malloc(sizeof(int));
            *new_int = (*expr1) * (*expr2);
            printf("%d", *new_int);
            create_int(&new_expr, new_int);
            $$ = new_expr;
          }
        }
        |
        expr '/' expr 
        {
            expr new_expr;
            if ($1.tipo == 1 && $3.tipo == 1) {
                int *expr1 = $1.ptr;
                int *expr2 = $3.ptr;
                if (*expr2 == 0) {
                    printf("Error: división por cero\n");
                    exit(1);
                }
                int *new_int = malloc(sizeof(int));
                *new_int = (*expr1) / (*expr2);
                create_int(&new_expr, new_int);
            } else if ($1.tipo == 2 && $3.tipo == 2) {
                float *expr1 = $1.ptr;
                float *expr2 = $3.ptr;
                if (*expr2 == 0.0) {
                    printf("Error: división por cero\n");
                    exit(1);
                }
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) / (*expr2);
                create_float(&new_expr, new_float);
            } else {
                printf("Error: Tipos de operandos no válidos para la división\n");
                exit(1);
            }
            $$ = new_expr;
        }
        |
        expr '+' expr 
        {
            expr new_expr;
            if ($1.tipo == 1 && $3.tipo == 1) {
                int *expr1 = $1.ptr;
                int *expr2 = $3.ptr;
                int *new_int = malloc(sizeof(int));
                *new_int = (*expr1) + (*expr2);
                create_int(&new_expr, new_int);
            } else if ($1.tipo == 2 && $3.tipo == 2) {
                float *expr1 = $1.ptr;
                float *expr2 = $3.ptr;
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) + (*expr2);
                create_float(&new_expr, new_float);
            } else if ($1.tipo == 3 && $3.tipo == 3) {
                char *expr1 = $1.ptr;
                char *expr2 = $3.ptr;
                int size = strlen(expr1) + strlen(expr2) + 1; 
                char *new_str = malloc(size * sizeof(char));
                strcpy(new_str, expr1);
                strcat(new_str, expr2);
                create_string(&new_expr, new_str);
            } else {
                printf("Error: Tipos de operandos no válidos para la suma\n");
                exit(1);
            }
            $$ = new_expr;
        }
        |
        expr '-' expr 
        {
            expr new_expr;
            if ($1.tipo == 1 && $3.tipo == 1) {
                int *expr1 = $1.ptr;
                int *expr2 = $3.ptr;
                int *new_int = malloc(sizeof(int));
                *new_int = (*expr1) - (*expr2);
                create_int(&new_expr, new_int);
            } else if ($1.tipo == 2 && $3.tipo == 2) {
                float *expr1 = $1.ptr;
                float *expr2 = $3.ptr;
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) - (*expr2);
                create_float(&new_expr, new_float);
            } else {
                printf("Error: Tipos de operandos no válidos para la resta\n");
                exit(1);
            }
            $$ = new_expr;
        }
        |
        CADENA {
          expr new_expr;
          create_string(&new_expr, $1);
          $$ = new_expr;
        }
        |
        ENTERO {
          expr new_expr;
          int *new_int = malloc(sizeof(int));
          *new_int = $1;
          create_int(&new_expr, new_int);
          $$ = new_expr;
        }
        |
        for_expr
        |
        while_expr
        |
        if_expr
        ;
racha:  CADENA '?'
        {
          create_list(&lista);
          caracter = $1[0];
          PushBack(&lista, caracter);
          PushBack(&lista, 0);
          for (char *iter = $1; *iter != '\0'; iter++){
            if(*iter == caracter){
              lista.tail->dato +=1;
            }else{
              caracter = *iter;
              PushBack(&lista, caracter);
              PushBack(&lista, 1);
            }
          }
        }
        ;
for_expr: FOR '(' expr ';' condition ';' expr ')' '{' expr '}'
         {
          $3;
          while ($5) {
            $$ = $10;
            $7;
          }
         }
         ;
while_expr: WHILE '(' condition ')' '{' expr '}'
           {
            while ($3){
              $$ = $6;
            }
           }
           ;
if_expr: IF '(' condition ')' '{' expr '}'
         {
          if ($3 == 1){
            $$ = $6;
          }
         }
         |
         IF '(' condition ')' '{' expr '}' ELSE '{' expr '}'
         {
         if ($3 == 1){
            $$ = $6;
          }else{
            $$ = $10;
          }
         }
         
condition: expr EQ expr
           {
             int result;
             if ($1.tipo == 1 && $3.tipo == 1) {
               result = ($1.ptr == $3.ptr) ? 1 : 0;
             } else if ($1.tipo == 2 && $3.tipo == 2) {
               result = ($1.ptr == $3.ptr) ? 1 : 0;
             } else if ($1.tipo == 3 && $3.tipo == 3) {
               result = (strcmp($1.ptr, $3.ptr) == 0) ? 1 : 0;
             }
             $$ = result;
           }
           |
           expr NE expr
           {
             int result;
             if ($1.tipo == 1 && $3.tipo == 1) {
               result = ($1.ptr != $3.ptr) ? 1 : 0;
             } else if ($1.tipo == 2 && $3.tipo == 2) {
               result = ($1.ptr != $3.ptr) ? 1 : 0;
             } else if ($1.tipo == 3 && $3.tipo == 3) {
               result = (strcmp($1.ptr, $3.ptr) != 0) ? 1 : 0;
             }
             $$ = result;
           }
           |
           expr LE expr
           {
            if ($1.tipo == 1 && $3.tipo == 1) {
                int value1 = *((int*)$1.ptr);  
                int value2 = *((int*)$3.ptr);  
                $$ = (value1 <= value2) ? 1 : 0;
            } else if ($1.tipo == 2 && $3.tipo == 2) {
                float value1 = *((float*)$1.ptr);  
                float value2 = *((float*)$3.ptr);  
                $$ = (value1 <= value2) ? 1 : 0;
            } else {
                // Manejo de error si los tipos no son compatibles o no están definidos
                fprintf(stderr, "Tipos de datos incompatibles para la comparación <=\n");
                exit(EXIT_FAILURE);
            }
           }
           |
           expr GE expr
           {
            if ($1.tipo == 1 && $3.tipo == 1) {
                int value1 = *((int*)$1.ptr);  
                int value2 = *((int*)$3.ptr);  
                $$ = (value1 >= value2) ? 1 : 0;
            } else if ($1.tipo == 2 && $3.tipo == 2) {
                float value1 = *((float*)$1.ptr);  
                float value2 = *((float*)$3.ptr);  
                $$ = (value1 >= value2) ? 1 : 0;
            } else {
                // Manejo de error si los tipos no son compatibles o no están definidos
                fprintf(stderr, "Tipos de datos incompatibles para la comparación >=\n");
                exit(EXIT_FAILURE);
            }
           }
           |
           expr '<' expr
           {
            if ($1.tipo == 1 && $3.tipo == 1) {
                int value1 = *((int*)$1.ptr);  
                int value2 = *((int*)$3.ptr);  
                $$ = (value1 < value2) ? 1 : 0;
            } else if ($1.tipo == 2 && $3.tipo == 2) {
                float value1 = *((float*)$1.ptr);  
                float value2 = *((float*)$3.ptr);  
                $$ = (value1 < value2) ? 1 : 0;
            } else {
                // Manejo de error si los tipos no son compatibles o no están definidos
                fprintf(stderr, "Tipos de datos incompatibles para la comparación <\n");
                exit(EXIT_FAILURE);
            }
           }
           |
           expr '>' expr
           {
            if ($1.tipo == 1 && $3.tipo == 1) {
                int value1 = *((int*)$1.ptr);  
                int value2 = *((int*)$3.ptr);  
                $$ = (value1 > value2) ? 1 : 0;
            } else if ($1.tipo == 2 && $3.tipo == 2) {
                float value1 = *((float*)$1.ptr);  
                float value2 = *((float*)$3.ptr);  
                $$ = (value1 > value2) ? 1 : 0;
            } else {
                // Manejo de error si los tipos no son compatibles o no están definidos
                fprintf(stderr, "Tipos de datos incompatibles para la comparación >\n");
                exit(EXIT_FAILURE);
            }
           }
           ; 

%%

void create_int(expr *expresion, void *ptr) {
  expresion->ptr = ptr;
  expresion->tipo = 1;
}

void create_float(expr *expresion, void *ptr) {
  expresion->ptr = ptr;
  expresion->tipo = 2;
}

void create_string(expr *expresion, void *ptr) {
  expresion->ptr = ptr;
  expresion->tipo = 3;
}
int main()
{
  return(yyparse());
}

int yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

int yywrap()
{
  return(1);
}
