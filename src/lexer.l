%{
#include <stdio.h>
#include "parser.tab.h"
int c;
char *string;
%}
/*Las cadenas deberian ser en minuscula y en mayuscula el alfabeto*/
MINUSCULAS [a-z]
ALFABETO   [A-Z]
ESPACIOS   [\t|" "]*
DIGITO     [0-9]
ENTERO     {DIGITO}+
FLOTANTE   {DIGITO}+"."{DIGITO}+
CADENA     {MINUSCULAS}+
COMENTARIO ["//".*]

IF      IF
ELSE    ELSE
FOR     FOR
WHILE   WHILE
SHOW    SHOW

EQUAL        "=="
NOTEQUAL     "!="
LESSEQUAL    "<="
GREATEREQUAL ">="

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
                int size = strlen(yytext);
                char value_s[size];
                int i = 0;
                for (char *iter = yytext; *iter != '\0'; iter++) {
                  value_s[i] = *iter;
                  i++;
                }
                yylval.s = yytext;
                return(CADENA);
              }
{EQUAL}        { return(EQUAL); }
{NOTEQUAL}     { return(NOTEQUAL); }
{LESSEQUAL}    { return(LESSEQUAL); }
{GREATEREQUAL} { return(GREATEREQUAL); }

[^a-z0-9\b]   {
                c = yytext[0];
                return(c);
              }
%%