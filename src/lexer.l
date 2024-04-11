%{
#include <stdio.h>
#include "parser.tab.h"
int c;
%}
/*Las cadenas deberian ser en minuscula y en mayuscula el alfabeto*/
MINUSCULAS [a-z]
MAYUSCULAS [A-Z]
DIGITO [0-9]
NUMERO {DIGITO}+["."{DIGITO}+]?
CADENA {MINUSCULAS}+
CONDICION [{MINUSCULAS}|{DIGITO} (">"|"<"|"="|) {MINUSCULAS}|{DIGITO}]
/*CADENA {MINUSCULAS}*/
%%
" "       ; 
{MINUSCULAS}  {
                c = yytext[0];
                yylval.a = c;
                return(CADENA);
              }
[^a-z0-9\b]   {
                c = yytext[0];
                return(c);
              }
%%