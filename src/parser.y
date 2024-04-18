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

%union { int a; char* s; int i; float f;} /*Definición de tipos*/


%token <s> CADENA
%token <a> ASIGNACION
%token <a> EXPRESION
%token <a> CONDICION /*Lo que recibe del lexer*/ 
%token <a> ALFABETO
%token <i> ENTERO 
%token <f> FLOTANTE 

%left '?'
%left '+' '-'
%left '*' '/' '%'

%type<i> racha
%type<s> expr
%type<i> expre
%type<f> exprf
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
          printf("expr: %s\n", $1);
         }
         |
         expre{
          printf("expre: %d\n", $1);
         }
         |
         exprf 
         {
          printf("exprf: %f\n", $1);
         }
         |
         racha 
         {
          printf("numero de rachas: %d\n", $1);
         }
         ;

expr:   '(' expr ')'
        {
          $$ = $2;
        }
        |
        expr '*' expr 
        {
          int size = strlen($1) + strlen($3);
          printf("s1: %s, s2: %s\n", $1,$3);
          printf("size: %d\n", size);
          char *  new_str = malloc(size*sizeof(char));
          int i = 0;
          for (char *iter = $1; *iter != '\0'; iter++ ){
            printf("char %d: %c\n", i, *iter);
            new_str[i] = *iter;
            i++;
          }
          for (char *iter = $3; *iter !='\0'; iter++ ){
            printf("char %d: %c\n", i, *iter);
            new_str[i] = *iter;
            i++;
          }
          printf("%s\n",new_str);
          $$ = new_str;
          printf("%s\n",$$);
        }
        |
        CADENA
        ;
expre:  '(' expre ')'
        {
          $$ = $2;
        }
        |
        expre '*' expre 
        {
          $$ = $1 * $3;
        }
        |
        expre '/' expre 
        {
          $$ = $1 / $3;
        }
        |
        expre '+' expre 
        {
          $$ = $1 + $3;
        }
        |
        expre '-' expre 
        {
          $$ = $1 - $3;
        }
        |
        ENTERO
        ;
exprf:  '(' exprf ')'
        {
          $$ = $2;
        }
        |
        exprf '*' exprf 
        {
          $$ = $1 * $3;
        }
        |
        exprf '/' exprf 
        {
          $$ = $1 / $3;
        }
        |
        exprf '+' exprf 
        {
          $$ = $1 + $3;
        }
        |
        exprf '-' exprf 
        {
          $$ = $1 - $3;
        }
        |
        FLOTANTE
        ;
racha:  CADENA '?'{
          create_list(&lista);
          $$ = 1;
          caracter = $1[0];
          PushBack(&lista, caracter);
          PushBack(&lista, 0);
          for (char *iter = $1; *iter != '\0'; iter++){
            if(*iter == caracter){
              lista.tail->dato +=1;
            }else{
              $$++;
              caracter = *iter;
              PushBack(&lista, caracter);
              PushBack(&lista, 1);
            }
          }
          while (lista.head != NULL){
            int c = PopFront(&lista);
            int d = PopFront(&lista);
            printf("%c: %d\n", c, d);
          }
        }
        ;

%%
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
