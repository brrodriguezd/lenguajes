%{
#include <stdio.h>
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
%token <s> ESPACIOS
%token <a> ALFABETO
%token <s> SHOW 
%token <i> ENTERO 
%token <f> FLOTANTE 


%left '|' /*%left es el orden de operación -> izq a derecha*/
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS  /*supplies precedence for unary minus */

%type<f> exprf
%type<s> racha
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
stat:   racha ESPACIOS SHOW
         {
          while (lista.head != NULL){
            int c = PopFront(&lista);
            int d = PopFront(&lista);
            printf("%c: %d\n", c, d);
          }
         }
         |
         exprf 
         {
          printf("%f", $1);
         }
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
        {
          $$ = $1;
        }
racha:  CADENA
        {
          create_list(&lista);
          $$ = $1;
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
