%{
#include <stdio.h>
#include "parser.tab.h"
#include "lib/expr.h"
int c;
char *string;
%}
/*Las cadenas deberian ser en minuscula y en mayuscula el alfabeto*/
COMENTARIO  "//".*\n
BLOQUEC     "/*"(.*\n)*"*/"\n
MINUSCULAS  [a-z]
ALFABETO    [A-Z]
ESPACIOS    (\t|" ")*
DIGITO      [0-9]
ENTERO      {DIGITO}+
FLOTANTE    {DIGITO}+"."{DIGITO}+
CADENA      \"{MINUSCULAS}+\"
NOMBRE      {MINUSCULAS}+
ARRAY_INT   \[{ENTERO}(,{ENTERO})*,?\]
ARRAY_FLOAT \[{FLOTANTE}(,{FLOTANTE})*,?\]
/**/
%%
{COMENTARIO}  ;
{ESPACIOS}    ;
{BLOQUEC}     ;
\n            ;
\:int         { 
                yylval.i = 1;
                return(TIPO); 
              }
\:float       { 
                yylval.i = 2;
                return(TIPO);
              }
\:string      { 
                yylval.i = 3;
                return(TIPO); 
              }
\:\[int\]     { 
                yylval.i = 1;
                return(TIPO); 
              }
\:\[float\]   { 
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
                char *string = yytext+1;
                for (char *iter = string; *iter != ']'; iter++){
                  if(*iter == ','){
                    contador++;
                  }
                }
                //int array[contador];
                int *array = malloc(contador * sizeof(int));
                char *token =strtok(string, ",");
                array[0] = atoi(token);
                for (int i = 1; i < contador; i++){
                  token = strtok(NULL,",");
                  if(token == NULL){
                    token = strtok(NULL,"]");
                  }
                  array[i] = atoi(token);
                }
                expr *expr = malloc(sizeof(expr));
                create_int_array(expr,array,contador);
                yylval.p = expr;
                return(ARRAY_INT);
              }
{ARRAY_FLOAT} {
                int contador=1;
                char *string = yytext+1;
                for (char *iter = string; *iter != ']'; iter++){
                  if(*iter == ','){
                    contador++;
                  }
                }
                float *array = malloc(contador * sizeof(float));
                char *token =strtok(string, ",");
                array[0] = atof(token);
                for (int i = 1; i < contador; i++){
                  token = strtok(NULL,",");
                  if(token == NULL){
                    token = strtok(NULL,"]");
                  }
                  array[i] = atof(token);
                }
                expr expr;
                create_float_array(&expr,array,contador);
                yylval.p = &expr;
                return(ARRAY_FLOAT);
              }
{ALFABETO}    {
                int A = yytext[0];
                yylval.a = A;
                return (ALFABETO);
              }
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
