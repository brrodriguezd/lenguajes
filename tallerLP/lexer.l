%{
#include "parser.tab.h"
char *quitar_comillas(char *str);
%}

MINUSCULAS  [a-z]
DIGITO      [0-9]
ALFABETO    [A-Z]
COMENTARIO  "//".*
BLOQUEC     "/*"(.*\n)*"*/"\n
ESPACIOS    [ \t\r\n]+
ENTERO      -?{DIGITO}+
FLOTANTE    -?{DIGITO}+"."{DIGITO}+
CADENA      \"{MINUSCULAS}+\"
NOMBRE      {MINUSCULAS}+

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
"int"       { return TYPE_INT; }
"float"     { return TYPE_FLOAT;}
"str"       { return TYPE_CADENA; }
"modelo"    { return TYPE_MODELO; }
"print"     { return PRINT; }
"["         { return LS; }
"]"         { return RS; }
";"         { return SEMICOLON; }
"size"      { return SIZE; }
"beta"      { return B; }
"alpha"     { return A; }
"tau"       { return TAU; }
"n"         { return N; }
"m"         { return M; }
"matriz"    { return MATRIZ;}
"categoria" { return CAT; }
"str_mult"  { return TYPE_CAD_MULT; }

{ALFABETO}  { yylval.cval = strdup(yytext); return ALFABETO; }
{FLOTANTE}  { yylval.fval = atof(yytext); return FLOAT; }
{ENTERO}    { yylval.ival = atoi(yytext); return INT; }
{CADENA}    { yylval.sval = quitar_comillas(yytext); return CADENA; }
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

char * quitar_comillas(char *str){
    int len = strlen(str);
    char *new_str = str+1;
    new_str[len-2] = '\0';
    return strdup(new_str);
}