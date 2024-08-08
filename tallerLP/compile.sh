flex lexer.l
bison -d parser.y -Wcounterexamples
gcc -o parser parser.tab.c lex.yy.c ast.c symtab.c
