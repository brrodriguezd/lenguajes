%{
#include <stdio.h>
#include "y.tab.h"
int c;
%}
/*Las cadenas deberian ser en minuscula y en mayuscula el alfabeto*/
MINUSCULAS [a-z]
MAYUSCULAS [A-Z]
DIGITO [0-9]
/*CADENA {MINUSCULAS}*/
%%
" "       ; 

{MINUSCULAS}  {
                c = yytext[0];
                yylval.c = c - 'a';
                return(CADENA);
              }
[^a-z0-9\b]   {
                c = yytext[0];
                return(c);
              }

%%