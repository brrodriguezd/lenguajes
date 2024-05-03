%{
#include <stdio.h>
#include "parser.tab.h"
int c;
char *string;
%}
/*Las cadenas deberian ser en minuscula y en mayuscula el alfabeto*/
COMENTARIO "//".*
MINUSCULAS [a-z]
ALFABETO   [A-Z]
ESPACIOS   [\t|" "]*
DIGITO     [0-9]
ENTERO     {DIGITO}+
FLOTANTE   {DIGITO}+"."{DIGITO}+
CADENA     \"{MINUSCULAS}+\"
NOMBRE     {MINUSCULAS}+
/**/
%%
\:int           { 
                yylval.i = 1;
                return(TIPO); 
              }
\:string        { 
                yylval.i = 3;
                return(TIPO); 
              }
\:float         { 
                yylval.i = 2;
                return(TIPO);
              }
\:racha         { 
                yylval.i = 4;
                return(TIPO);
              }
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
{ESPACIOS}    ;
{ALFABETO}    {
                int A = yytext[0];
                yylval.a = A;
                return (ALFABETO);
              }
{COMENTARIO}  ;
{CADENA}      {
                int size = strlen(yytext);
                char *value_s = malloc(size*sizeof(char));
                int i = 0;
                for (char *iter = yytext+1; *iter != '"'; iter++) {
                  value_s[i] = *iter;
                  i++;
                }
                yylval.s = value_s;
                return(CADENA);
              }
{NOMBRE}      {
                int size = strlen(yytext);
                char *value_s = malloc(size*sizeof(char));
                int i = 0;
                for (char *iter = yytext; *iter != '\0'; iter++) {
                  value_s[i] = *iter;
                  i++;
                }
                yylval.s = value_s;
                return(NOMBRE);
              }

IF            { return(IF); }
ELSE          { return(ELSE); }
FOR           { return(FOR); }
WHILE         { return(WHILE); }

"=="          { return(EQ); }
"!="          { return(NE); }
"<="          { return(LE); }
">="          { return(GE); }

[^a-z0-9\b]   {
                c = yytext[0];
                return(c);
              }
%%
