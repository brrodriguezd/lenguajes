%{
#include <stdio.h>
#include <string.h>
#include "./lib/linked_list.c"
#include "./lib/expr.h"
#include "./lib/diccionario.c"

extern FILE *yyin;
extern int lineas;
int yylex(void);
int yyerror(char* s);
int regs[26] = {0}; //26 del alfabeto
expr variables [200];
char* str;
int caracter;
linked_list lista;
%}

%start list

%code requires {
  #include "./lib/expr.h"
}

%union { int a; char* s; int i; float f; expr e; expr* p; } /*Definición de tipos*/


%token <s> CADENA
%token <a> ALFABETO
%token <i> ENTERO 
%token <f> FLOTANTE
%token <s> NOMBRE
%token <i> TIPO
%token <p> ARRAY_INT
%token <p> ARRAY_FLOAT

%token IF
%token ELSE
%token FOR
%token WHILE

%token EQ
%token NE
%token LE
%token GE

%left '+' '-'
%left '*' '/' '%'
%left ':'

%type<s> racha
%type<e> expr
%type<i> condition
%type<s> declaracion
%%                   
list        :                           /*empty */
            | list stat ';'
            | list error ';'
            | list if
            | list while
            | list for
            {
              yyerrok;
            }
            ;
stat        : expr 
            {
              if($1.tipo == 1){
                if($1.size == 1){
                  int *ptr = $1.ptr;
                  printf("expr (int): %d\n", *ptr);
                }else{
                  int *ptr = $1.ptr;
                  for (int i = 0; i < $1.size; i++){
                    printf("arr[i:%d]: %d\n", i, ptr[i]);
                  }
                }
              }else if($1.tipo == 2){
                if($1.size == 1){
                  float *ptr = $1.ptr;
                  printf("expr (float): %f\n", *ptr);
                }else{
                float *ptr = $1.ptr;
                  for (int i = 0; i < $1.size; i++){
                    printf("arr[f:%d]: %f\n", i, ptr[i]);
                  }
                }
              }else if($1.tipo == 3){
                printf("expr (cadena): %s\n", $1);
              }
            }
            | racha
            {
              while (lista.head != NULL){
                int c = PopFront(&lista);
                int d = PopFront(&lista);
                printf("%c: %d\n", c, d);
              }
            }
            | declaracion
            ;

for         : FOR '(' declaracion ';' condition ';' expr ')' '{' list '}'
            {
              while ($5) {
              }
            }
            ;
while       : WHILE '(' condition ')' '{' list '}'
            {
              while ($3){
              }
            }
            ;
if          : IF '(' condition ')' '{' list '}'
            | IF '(' condition ')' '{' list '}' ELSE '{' list '}'
            ;
         
declaracion : NOMBRE TIPO '=' expr
            {
              //la expresión tiene que ser del tipo correcto
              if($4.tipo == $2){
                insert($1, $4);
                //retornar el nombre para el for
                $$ = $1;
              }else{
                fprintf(stderr, "Error, la variable %s no es compatible con el tipo asignado\n", $1);
                exit(EXIT_FAILURE);
              }
            };
expr        : '(' expr ')' {
              expr new_expr = $2;
              $$ = new_expr;
            }
            | expr '*' expr {
              expr new_expr;
              if ($1.tipo == 3 && $3.tipo == 3){
                char *expr1 = $1.ptr;
                char *expr2 = $3.ptr;
                int size = strlen(expr1) + strlen(expr2);
                char *new_str = malloc(size*sizeof(char));
                int i = 0;
                for (char *iter = expr1; *iter != '\0'; iter++) {
                  new_str[i] = *iter;
                  i++;
                }
                for (char *iter = expr2; *iter != '\0'; iter++) {
                  new_str[i] = *iter;
                  i++;
                }
                create_string(&new_expr, new_str);
                $$ = new_expr;
              }else if ($1.tipo == 1 && $3.tipo == 1){
                int *expr1 = $1.ptr;
                int *expr2 = $3.ptr;
                int *new_int = malloc(sizeof(int));
                *new_int = (*expr1) * (*expr2);
                create_int(&new_expr, new_int);
                $$ = new_expr;
              }
              else if ($1.tipo == 2 && $3.tipo == 1){
                float *expr1 = $1.ptr;
                int *expr2 = $3.ptr;
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) * (*expr2);
                create_float(&new_expr, new_float);
                $$ = new_expr;
              }
              else if ($1.tipo == 1 && $3.tipo == 2){
                int *expr1 = $1.ptr;
                float *expr2 = $3.ptr;
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) * (*expr2);
                create_float(&new_expr, new_float);
                $$ = new_expr;
              }
              else if ($1.tipo == 2 && $3.tipo == 2){
                float *expr1 = $1.ptr;
                float *expr2 = $3.ptr;
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) * (*expr2);
                create_float(&new_expr, new_float);
                $$ = new_expr;
              }
            }
            | expr '/' expr {
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
              }
              else if ($1.tipo == 2 && $3.tipo == 1){
                float *expr1 = $1.ptr;
                int *expr2 = $3.ptr;
                if (*expr2 == 0) {
                  printf("Error: división por cero\n");
                  exit(1);
                }
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) / (*expr2);
                create_float(&new_expr, new_float);
                $$ = new_expr;
              }
              else if ($1.tipo == 1 && $3.tipo == 2){
                int *expr1 = $1.ptr;
                float *expr2 = $3.ptr;
                if (*expr2 == 0) {
                  printf("Error: división por cero\n");
                  exit(1);
                }
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) / (*expr2);
                create_float(&new_expr, new_float);
                $$ = new_expr;
              }
              else if ($1.tipo == 2 && $3.tipo == 2) {
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
            | expr '+' expr {
              expr new_expr;
              if ($1.tipo == 1 && $3.tipo == 1) {
                int *expr1 = $1.ptr;
                int *expr2 = $3.ptr;
                int *new_int = malloc(sizeof(int));
                *new_int = (*expr1) + (*expr2);
                create_int(&new_expr, new_int);
              }
              else if ($1.tipo == 2 && $3.tipo == 1){
                float *expr1 = $1.ptr;
                int *expr2 = $3.ptr;
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) + (*expr2);
                create_float(&new_expr, new_float);
                $$ = new_expr;
              }
              else if ($1.tipo == 1 && $3.tipo == 2){
                int *expr1 = $1.ptr;
                float *expr2 = $3.ptr;
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) + (*expr2);
                create_float(&new_expr, new_float);
                $$ = new_expr;
              }
              else if ($1.tipo == 2 && $3.tipo == 2) {
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
            | expr '-' expr {
              expr new_expr;
              if ($1.tipo == 1 && $3.tipo == 1) {
                int *expr1 = $1.ptr;
                int *expr2 = $3.ptr;
                int *new_int = malloc(sizeof(int));
                *new_int = (*expr1) - (*expr2);
                create_int(&new_expr, new_int);
              }
              else if ($1.tipo == 2 && $3.tipo == 1){
                float *expr1 = $1.ptr;
                int *expr2 = $3.ptr;
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) - (*expr2);
                create_float(&new_expr, new_float);
                $$ = new_expr;
              }
              else if ($1.tipo == 1 && $3.tipo == 2){
                int *expr1 = $1.ptr;
                float *expr2 = $3.ptr;
                float *new_float = malloc(sizeof(float));
                *new_float = (*expr1) - (*expr2);
                create_float(&new_expr, new_float);
                $$ = new_expr;
              }
              else if ($1.tipo == 2 && $3.tipo == 2) {
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
            | expr ':' expr {
              if($3.tipo != 4 && $3.size != 1){
                fprintf(stderr, "Error, no es un índice entero\n");
                exit(EXIT_FAILURE);
              }
              int *indice = $3.ptr;
              int *success;
              if(*indice > $1.size-1){
                fprintf(stderr, "Error, el índice %d está fuera del arreglo\n", *indice);
                exit(EXIT_FAILURE);
              }
              if($1.size == 1){
                fprintf(stderr, "Error, la variable no es un arreglo\n");
                exit(EXIT_FAILURE);
              }
              switch($1.tipo){
                case 1:
                  int *new_int = $1.ptr;
                  //printf("%d", *indice);
                  create_int(&$1, &new_int[*indice]);
                  break;
                case 2:
                  float *new_float = $1.ptr;
                  create_float(&$1, &new_float[*indice]);
                break;
                default:
                  fprintf(stderr, "Error, %s no es un arreglo\n", $1);
                  exit(EXIT_FAILURE);
                break;
              }
              $$ = $1;
            }
            | CADENA {
              expr new_expr;
              int size = strlen($1);
              char * new_str = malloc(size*sizeof(char));
              strcpy(new_str, $1);
              printf("%s\n",new_str);
              create_string(&new_expr, new_str);
              $$ = new_expr;
            }
            | ENTERO {
              expr new_expr;
              int *new_int = malloc(sizeof(int));
              *new_int = $1;
              create_int(&new_expr, new_int);
              $$ = new_expr;
            }
            | FLOTANTE {
              expr new_expr;
              float *new_float = malloc(sizeof(float));
              *new_float = $1;
              create_float(&new_expr, new_float);
              $$ = new_expr;
            }
            | ARRAY_INT {
              $$ = *$1;
            }
            | ARRAY_FLOAT{
              $$ = *$1;
            }
            | NOMBRE {
              int *success;
              expr new_expr = get($1, success);
              if (*success == 0){
                fprintf(stderr, "Error, la variable %s no existe\n", $1);
                exit(EXIT_FAILURE);
              }
              $$ = new_expr;
            }
            ;
racha       : CADENA '?'
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
condition   : expr EQ expr
            {
              int result;
              if($1.tipo == 1){
                if($3.tipo == 1){
                  result = (*((int*)$1.ptr) == *((int*)$3.ptr)) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  result = (*((int*)$1.ptr) == *((float*)$3.ptr)) ? 1 : 0;
                }
              }else if ($1.tipo == 2){
                if($3.tipo == 1){
                  result = (*((float*)$1.ptr) == *((int*)$3.ptr)) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  result = (*((float*)$1.ptr) == *((float*)$3.ptr)) ? 1 : 0;
                }
              }else if ($1.tipo == 3 && $3.tipo == 3) {
                result = (strcmp($1.ptr, $3.ptr) == 0) ? 1 : 0;
              }
              $$ = result;
            }
            |
            expr NE expr
            {
              int result;
              if($1.tipo == 1){
                if($3.tipo == 1){
                  result = (*((int*)$1.ptr) != *((int*)$3.ptr)) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  result = (*((int*)$1.ptr) != *((float*)$3.ptr)) ? 1 : 0;
                }
              }else if ($1.tipo == 2){
                if($3.tipo == 1){
                  result = (*((float*)$1.ptr) != *((int*)$3.ptr)) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  result = (*((float*)$1.ptr) != *((float*)$3.ptr)) ? 1 : 0;
                }
              } else if ($1.tipo == 3 && $3.tipo == 3) {
                result = (strcmp($1.ptr, $3.ptr) != 0) ? 1 : 0;
              }
              $$ = result;
            }
            |
            expr LE expr
            {
              if($1.tipo == 1){
                if($3.tipo == 1){
                  int value1 = *((int*)$1.ptr);  
                  int value2 = *((int*)$3.ptr);  
                  $$ = (value1 <= value2) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  int value1 = *((int*)$1.ptr);  
                  float value2 = *((float*)$3.ptr);  
                  $$ = (value1 <= value2) ? 1 : 0;
                }
              }else if ($1.tipo == 2){
                if($3.tipo == 1){
                  float value1 = *((float*)$1.ptr);  
                  int value2 = *((int*)$3.ptr);  
                  $$ = (value1 <= value2) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  float value1 = *((float*)$1.ptr);  
                  float value2 = *((float*)$3.ptr);  
                  $$ = (value1 <= value2) ? 1 : 0;
                }
              } else {
                // Manejo de error si los tipos no son compatibles o no están definidos
                fprintf(stderr, "Tipos de datos incompatibles para la comparación <=\n");
                exit(EXIT_FAILURE);
              }
            }
            |
            expr GE expr
            {
              if($1.tipo == 1){
                if($3.tipo == 1){
                  int value1 = *((int*)$1.ptr);  
                  int value2 = *((int*)$3.ptr);  
                  $$ = (value1 >= value2) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  int value1 = *((int*)$1.ptr);  
                  float value2 = *((float*)$3.ptr);  
                  $$ = (value1 >= value2) ? 1 : 0;
                }
              }else if ($1.tipo == 2){
                if($3.tipo == 1){
                  float value1 = *((float*)$1.ptr);  
                  int value2 = *((int*)$3.ptr);  
                  $$ = (value1 >= value2) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  float value1 = *((float*)$1.ptr);  
                  float value2 = *((float*)$3.ptr);  
                  $$ = (value1 >= value2) ? 1 : 0;
                }
              } else {
                // Manejo de error si los tipos no son compatibles o no están definidos
                fprintf(stderr, "Tipos de datos incompatibles para la comparación <=\n");
                exit(EXIT_FAILURE);
              }
            }
            |
            expr '<' expr
            {
              if($1.tipo == 1){
                if($3.tipo == 1){
                  int value1 = *((int*)$1.ptr);  
                  int value2 = *((int*)$3.ptr);  
                  $$ = (value1 < value2) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  int value1 = *((int*)$1.ptr);  
                  float value2 = *((float*)$3.ptr);  
                  $$ = (value1 < value2) ? 1 : 0;
                }
              }else if ($1.tipo == 2){
                if($3.tipo == 1){
                  float value1 = *((float*)$1.ptr);  
                  int value2 = *((int*)$3.ptr);  
                  $$ = (value1 < value2) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  float value1 = *((float*)$1.ptr);  
                  float value2 = *((float*)$3.ptr);  
                  $$ = (value1 < value2) ? 1 : 0;
                }
              } else {
                // Manejo de error si los tipos no son compatibles o no están definidos
                fprintf(stderr, "Tipos de datos incompatibles para la comparación <\n");
                exit(EXIT_FAILURE);
              }
            }
            |
            expr '>' expr
            {
              if($1.tipo == 1){
                if($3.tipo == 1){
                  int value1 = *((int*)$1.ptr);  
                  int value2 = *((int*)$3.ptr);  
                  $$ = (value1 > value2) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  int value1 = *((int*)$1.ptr);  
                  float value2 = *((float*)$3.ptr);  
                  $$ = (value1 > value2) ? 1 : 0;
                }
              }else if ($1.tipo == 2){
                if($3.tipo == 1){
                  float value1 = *((float*)$1.ptr);  
                  int value2 = *((int*)$3.ptr);  
                  $$ = (value1 > value2) ? 1 : 0;
                }
                else if($3.tipo == 2){
                  float value1 = *((float*)$1.ptr);  
                  float value2 = *((float*)$3.ptr);  
                  $$ = (value1 > value2) ? 1 : 0;
                }
              } else {
                // Manejo de error si los tipos no son compatibles o no están definidos
                fprintf(stderr, "Tipos de datos incompatibles para la comparación >\n");
                exit(EXIT_FAILURE);
              }
            }
            ; 

%%
int main()
{
  yyin = fopen("testfile", "r");
  yyparse();
  fclose(yyin);
  return 0;
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
