#include "symtab.h"
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;             // Current number of elements in the map
char keys[MAX_SIZE][100]; // Array to store the keys
ASTNode *values[MAX_SIZE]; // Array to store the values

// Function to get the index of a key in the keys array
int getIndex(char *key) {
  for (int i = 0; i < size; i++) {
    if (strcmp(keys[i], key) == 0) {
      return i;
    }
  }
  return -1; // Key not found
}

// Insertar o actualizar
void insert(char key[], ASTNode *value) {
  int index = getIndex(key);

  if (index == -1) { // Key not found
    strcpy(keys[size], key);
    values[size] = value;
    size++;
  } else { // Key found
    values[index] = value;
  }
}

// Function to get the value of a key in the map
// with a flag to indicate something wrong
ASTNode *get(char key[]) {
  int index = getIndex(key);

  if (index == -1) { // Key not found
    return NULL;
  } else { // Key found
    if (values[index] == NULL) {
      printf("ERROR: variable vacía\n");
    }
    return values[index];
  }
}
