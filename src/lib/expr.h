typedef struct Expr {
  void *ptr;
  int tipo;
} expr;

void create_int(expr *, void *);

void create_float(expr *, void *);

void create_string(expr *, void *);
