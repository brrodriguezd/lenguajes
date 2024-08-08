#ifndef SYMTAB_H
#define SYMTAB_H

#define MAX_SIZE 100 // Maximum number of elements in the map
#include "ast.h"

int getIndex(char *key);
void insert(char key[], ASTNode *value);
ASTNode *get(char key[]);

#endif