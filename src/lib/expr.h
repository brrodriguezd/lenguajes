#ifndef EXPR_H
#define EXPR_H
typedef struct Expr {
  void *ptr;
  int tipo;
} expr;

void create_int(expr *expresion, void *ptr);
void create_float(expr *expresion, void *ptr);
void create_string(expr *expresion, void *ptr);
#endif