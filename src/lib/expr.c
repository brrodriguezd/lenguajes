#include "expr.h"

void create_int(expr *expresion, void *ptr) {
  expresion->ptr = ptr;
  expresion->tipo = 1;
}

void create_float(expr *expresion, void *ptr) {
  expresion->ptr = ptr;
  expresion->tipo = 2;
}

void create_string(expr *expresion, void *ptr) {
  expresion->ptr = ptr;
  expresion->tipo = 3;
}