#include <stdio.h> 
#include "src/parser.tab.h"
void parse(FILE *file);

void main(){
    FILE *file = fopen("entrada.txt", "r");
    parse(file);   
}