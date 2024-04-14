%{
#include <stdio.h>
#include "parser.tab.h"
int c;
char *string;
%}
/*Las cadenas deberian ser en minuscula y en mayuscula el alfabeto*/
MINUSCULAS [a-z]
ALFABETO [A-Z]
ESPACIOS [\t|" "]*
DIGITO [0-9]
ENTERO {DIGITO}+
FLOTANTE {DIGITO}+"."{DIGITO}+
CADENA {MINUSCULAS}+
COMENTARIO ["//".*\n]
IF      IF
ELSE ELSE
FOR FOR
WHILE WHILE
SHOW SHOW
/**/
%%
{FLOTANTE}    {
                yylval.f = atof(yytext);
                return (FLOTANTE);
              }
{ENTERO}      {
                yylval.f = atoi(yytext);
                return (ENTERO);
              }
{ESPACIOS}    {
                return (ESPACIOS);
              } 
{ALFABETO}    {
                yylval.a = yytext[0];
                return (ALFABETO);
              }
{SHOW}        {
                return(SHOW);
              }
{COMENTARIO}  {
                return;
              }
{CADENA}      {
                yylval.s = yytext;
                return(CADENA);
              }
[^a-z0-9\b]   {
                c = yytext[0];
                return(c);
              }
%%