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
                float value_f = atof(yytext);
                yylval.f = value_f;
                return (FLOTANTE);
              }
{ENTERO}      {
                int value_i = atoi(yytext);
                yylval.i = value_i;
                return (ENTERO);
              }
{ALFABETO}    {
                int value_a = yytext[0];
                yylval.a = value_a;
                return (ALFABETO);
              }
{CADENA}      {
                int size = strlen(yytext);
                char value_s [size];
                int i = 0;
                for (char *iter = yytext; *iter != '\0'; iter++){
                  value_s[i] = *iter;
                  i++;
                }
                yylval.s = value_s;
                return(CADENA);
              }
[^a-z0-9\b]   {
                c = yytext[0];
                return(c);
              }
%%