#ifndef SYMTAB_H
#define SYMTAB_H

#define MAX_SIZE 100 // Maximum number of elements in the map
#include "ast.h"

int getIndex(char *key);
void insert(char key[], ASTNode *value);
void update(char key[], ASTNode *value);
void update_arr(char key[], ASTNode *value, ASTNode *index);
ASTNode *get(char key[]);

#endif