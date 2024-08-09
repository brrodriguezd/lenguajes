#ifndef AST_H
#define AST_H

enum types {
  _IDENTIFIER,
  _INT,
  _INT_ARR,
  _FLOAT,
  _FLOAT_ARR,
  _FLOAT_MAT,
  _CADENA,
  _ALFABETO,
  _PLUS,
  _MINUS,
  _MUL,
  _DIV,
  _MOD,
  _GT,
  _LT,
  _GE,
  _LE,
  _NE,
  _EQ,
  _BLOCK,
  _WHILE,
  _IF,
  _ELSE,
  _aINT,
  _aINT_ARR,
  _aFLOAT,
  _aFLOAT_ARR,
  _aFLOAT_MAT,
  _aCADENA,
  _aALFABETO,
  _PRINT,
  /*SINGLE VALUE FROM ARRAY*/
  _SVARR,
  _RELOC,
  _RELOC_ARR,
  _RELOC_ARR_AUX,
  _MODELO,
  _aMODELO,
  _SIZE,
  _CAT,
  _CADE_MULTI,
  _aCADE_MULTI,
};

char *get_enum_name(enum types type);
typedef struct farray {
  float *array;
  int size;
} farray;

typedef struct ASTNode {
  enum types type;
  union {
    char *identifier;
    int ival;
    float fval;
    char *sval;
    struct iarr {
      int *array;
      int size;
    } iarr;
    struct farr {
      float *array;
      int size;
    } farr;
    struct fmat {
      farray **array;
      int n;
      int m;
    } fmat;
    struct modelo {
      float alpha;
      int n;
      float *beta;
      int m;
      float *tau;
      farray **matriz;
    } modelo;
    struct cadena_m {
      char *cadena;
      int *counts;
      int size;
    } cadena_m;
  } value;
  struct ASTNode *left;
  struct ASTNode *right;
} ASTNode;

ASTNode *createNode(enum types type, ASTNode *left, ASTNode *right);
ASTNode *createIdentifierNode(char *identifier);
ASTNode *createIntNode(int ival);
ASTNode *createFloatNode(float fval);
ASTNode *createIntArrNode(int *ival, int size);
ASTNode *createFloatArrNode(float *fval, int size);
ASTNode *createFloatMatNode(farray **fval, int n, int m);
ASTNode *createStringNode(char *sval);
ASTNode *createAlfabetoNode(char *sval);
ASTNode *createCadenaMultiNode(char *cadena, int *counts, int size);
ASTNode *createModeloNode(float alpha, int n, float *beta, int m, float *tau,
                          farray **matriz);
void printAST(ASTNode *node, int level);
ASTNode *executeAST(ASTNode *node);

#endif // AST_H