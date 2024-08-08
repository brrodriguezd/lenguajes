%{
#include "parser.tab.h"
%}

MINUSCULAS  [a-z]
DIGITO      [0-9]
ALFABETO    [A-Z]
COMENTARIO  "//".*\n
BLOQUEC     "/*"(.*\n)*"*/"\n
ESPACIOS    [ \t\r\n]+
ENTERO      {DIGITO}+
FLOTANTE    {DIGITO}+"."{DIGITO}+
CADENA      \".+\"
NOMBRE      {MINUSCULAS}+
ARR_INT   \[{ENTERO}(,{ENTERO})*\]
ARR_FLOAT \[{FLOTANTE}(,{FLOTANTE})*\]

%%
{COMENTARIO} {/* NO HACER NADA */}
{ESPACIOS}    ;
{BLOQUEC}     ;

"while"     { return WHILE; }
"{"         { return LB; }
"}"         { return RB; }
"("         { return LP; }
")"         { return RP; }
"if"        { return IF; }
"else"      { return ELSE; }
"int[]"     { return TYPE_INT_ARRAY; }
"int"       { return TYPE_INT; }
"float[]"   { return TYPE_FLOAT_ARRAY; }
"float"     { return TYPE_FLOAT;}
"string"    { return TYPE_CADENA; }
"modelo"    { return TYPE_MODELO; }
"print"     { return PRINT; }
"["         { return LS; }
"]"         { return RS; }

{FLOTANTE}  { yylval.fval = atof(yytext); return FLOAT; }
{ENTERO}    { yylval.ival = atoi(yytext); return INT; }
{CADENA}    { yylval.sval = strdup(yytext); return CADENA; }
{NOMBRE}    { yylval.sval = strdup(yytext); return IDENTIFIER; }

","         { return COMMA; }
"="         { return ASSIGN; }
"=="        { return EQ; }
"!="        { return NE; }
"<="        { return LE; }
">="        { return GE; }
"<"         { return LT; }
">"         { return GT; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"%"         { return MOD; }
.           { printf("carácter no reconocido: %c", yytext[0]); exit(EXIT_FAILURE);} 
%%

int yywrap() {
    return 1;
}
