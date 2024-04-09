%{ 
  #include<stdio.h> 
  #include "y.tab.h" 
  void yyerror(char *);
%} 

%option noyywrap
/* Unicamente leera un archivo de entrada*/

DIGIT   [0-9]
NUM     {DIGIT}+("."{DIGIT}+)?

/* Rule Section */
%% 
{NUM}               { yylval=atoi(yytext); return NUMBER; } 
[-()+*/;]            { return *yytext; }
"evaluar"            { return EVALUAR; }
[[:blank:]] ;
.                     yyerror("Unknown character");
%%