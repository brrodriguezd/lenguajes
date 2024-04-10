%{
#include<stdio.h>

int regs[26] = {0}; //26 del alfabeto
int caracter;
%}

%start list

%union { int a; int c;} /*Definición de tipos*/


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
            for (char i = 0; i < 26; i++){
              if(regs[i] > 0){
                printf("%c: %d\n", i + 'a', regs[i]);
                regs[i] = 0;
              }
            }
         }
         ;
racha:  CADENA
        {
          $$.c = 1;
          caracter = $1.c;
          regs[caracter] = 1;
        }
        |
        racha CADENA
        {
          $$.c += 1;
          if (caracter == $2.c){
            regs[caracter] += 1;
          }else{ 
            caracter = $2.c;
            regs[caracter] = 1;
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