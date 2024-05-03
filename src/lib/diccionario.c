#include "expr.h"
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum number of elements in the map

int size = 0;             // Current number of elements in the map
char keys[MAX_SIZE][100]; // Array to store the keys
expr values[MAX_SIZE];    // Array to store the values

// Function to get the index of a key in the keys array
int getIndex(char key[]) {
  for (int i = 0; i < size; i++) {
    if (strcmp(keys[i], key) == 0) {
      return i;
    }
  }
  return -1; // Key not found
}

// Function to insert a key-value pair into the map
void insert(char key[], expr value) {
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
expr get(char key[], int *success) {
  int index = getIndex(key);
  if (index == -1) { // Key not found
    printf("variable no encontrada");
    expr new_expr;
    *success = 0;
    return new_expr;
  } else { // Key found
    *success = 1;
    printf("estoy aqui?");
    return values[index];
  }
}
