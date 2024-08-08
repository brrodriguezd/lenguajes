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

// Insertar o actualizar
void update(char key[], ASTNode *value) {
  int index = getIndex(key);

  if (index == -1) { // Key not found
    printf("ERROR: Variable %s no declarada", key);
    return;
  }
  if (values[index]->type != value->type) {
    printf("ERROR: Variable %s no es del tipo %s", key,
           get_enum_name(value->type));
    return;
  }
  values[index]->value = value->value;
}
void update_arr(char key[], ASTNode *value, ASTNode *index) {
  int idx = getIndex(key);

  if (index->type != _INT) {
    printf("ERROR: El indice no es entero\n");
  }
  if (idx == -1) { // Key not found
    printf("ERROR: Variable %s no declarada\n", key);
    return;
  }
  if (values[idx]->type == _INT_ARR) {
    if (value->type != _INT) {
      printf("ERROR: el tipo asignado es diferente al arreglo %s\n", key);
      return;
    }
    if (values[idx]->value.iarr.size <= index->value.ival) {
      printf("ERROR: El arreglo %s es más pequeño que el índice\n", key);
      return;
    }
    values[idx]->value.iarr.array[index->value.ival] = value->value.ival;
  }
  if (values[idx]->type == _FLOAT_ARR) {
    if (value->type != _FLOAT) {
      printf("ERROR: el tipo asignado es diferente al arreglo %s\n", key);
    }
    if (values[idx]->value.farr.size <= index->value.ival) {
      printf("ERROR: El arreglo %s es más pequeño que el índice\n", key);
      return;
    }
    values[idx]->value.farr.array[index->value.ival] = value->value.fval;
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
