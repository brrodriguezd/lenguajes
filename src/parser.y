%{
#include <stdio.h>
#include "./lib/linked_list.c"

int regs[26] = {0}; //26 del alfabeto
char* string;
int caracter;
linked_list lista;
%}

%start list

%union { int a;} /*Definición de tipos*/


%token CADENA /*Lo que recibe del lexer*/ 

%left '|' /*%left es el orden de operación -> izq a derecha*/
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS  /*supplies precedence for unary minus */

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
stat:   racha
         {
          while (lista.head != NULL){
            int c = PopFront(&lista);
            int d = PopFront(&lista);
            printf("%c: %d\n", c, d);
          }
         }
         ;
racha:  CADENA
        {
          create_list(&lista);
          caracter = $1.a;
          PushBack(&lista, ($1.a));
          PushBack(&lista, 1);
        }
        |
        racha CADENA
        {
          if (caracter == $2.a){
            lista.tail->dato += 1;
          }else{ 
            caracter = $2.a;
            PushBack(&lista, ($2.a));
            PushBack(&lista, 1);
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