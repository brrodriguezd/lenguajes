#include "expr.h"

void create_int(expr *expresion, void *ptr) {
  expresion->ptr = ptr;
  expresion->tipo = 1;
  expresion->size = 1;
}

void create_float(expr *expresion, void *ptr) {
  expresion->ptr = ptr;
  expresion->tipo = 2;
  expresion->size = 1;
}

void create_string(expr *expresion, void *ptr) {
  expresion->ptr = ptr;
  expresion->tipo = 3;
  expresion->size = 1;
}

void create_int_array(expr *expresion, void *ptr, int size) {
  expresion->ptr = ptr;
  expresion->tipo = 1;
  expresion->size = size;
}

void create_float_array(expr *expresion, void *ptr, int size) {
  expresion->ptr = ptr;
  expresion->tipo = 2;
  expresion->size = size;
}

void create_modelo(expr *expresion, void *ptr, int size) {
  expresion->ptr = ptr;
  expresion->tipo = 4;
  expresion->size = 3;
}
