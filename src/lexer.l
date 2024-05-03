%{
#include <stdio.h>
#include "parser.tab.h"
#include "lib/expr.h"
int c;
char *string;
%}
/*Las cadenas deberian ser en minuscula y en mayuscula el alfabeto*/
COMENTARIO  "//".*
MINUSCULAS  [a-z]
ALFABETO    [A-Z]
ESPACIOS    [\t|" "]*
DIGITO      [0-9]
ENTERO      {DIGITO}+
FLOTANTE    {DIGITO}+"."{DIGITO}+
CADENA      \"{MINUSCULAS}+\"
NOMBRE      {MINUSCULAS}+
ARRAY_INT   \[{ENTERO}(,{ENTERO})*\]
ARRAY_FLOAT \[{FLOTANTE}[,{FLOTANTE}]*\]
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

if            { return(IF); }
else          { return(ELSE); }
for           { return(FOR); }
while         { return(WHILE); }

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
{ARRAY_INT}   {
                int contador=1;
                char *string = yytext;
                for (char *iter = string+1; *iter != ']'; iter++){
                  if(*iter == ','){
                    contador++;
                  }
                }
                int array[contador];
                char *token =strtok(string, ",");
                array[0] = atoi(token);
                for (int i = 1; i < contador; i++){
                  token = strtok(NULL,",");
                  if(token == NULL){
                    token = strtok(NULL,"]");
                  }
                  array[i] = atoi(token);
                }
                expr expr;
                create_int_array(&expr,array,contador);
                yylval.e = expr;
                return(ARRAY_INT);
              }
{ARRAY_FLOAT} {
                int contador=1;
                for (char *iter = yytext+1; *iter != ']'; iter++){
                  if(*iter == ','){
                    contador++;
                  }
                }
                float array[contador];
                char *string = yytext+1;
                char *token =strtok(string, ",");
                array[0] = atof(token);
                for (int i = 0; i < contador; i++){
                  token = strtok(NULL,",");
                  if(token == NULL){
                    token = strtok(NULL,"]");
                  }
                  array[i+1] = atof(token);
                }
                expr expr;
                create_float_array(&expr,array,contador);
                yylval.e = expr;
                return(ARRAY_FLOAT);
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
"=="          { return(EQ); }
"!="          { return(NE); }
"<="          { return(LE); }
">="          { return(GE); }

[^a-z0-9\b]   {
                c = yytext[0];
                return(c);
              }
%%
