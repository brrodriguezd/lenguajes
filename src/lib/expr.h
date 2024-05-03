#ifndef EXPR_H
#define EXPR_H
typedef struct Expr {
  void *ptr;
  int tipo;
  int size;
} expr;

void create_int(expr *expresion, void *ptr);
void create_float(expr *expresion, void *ptr);
void create_string(expr *expresion, void *ptr);
void create_int_array(expr *expresion, void *ptr, int size);
void create_float_array(expr *expresion, void *ptr, int size);
#endif