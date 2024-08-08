#ifndef AST_H
#define AST_H

enum types {
  _IDENTIFIER,
  _INT,
  _INT_ARR,
  _FLOAT,
  _FLOAT_ARR,
  _CADENA,
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
  _aCADENA,
  _PRINT,
};

char *get_enum_name(enum types type);

typedef struct ASTNode {
  enum types type;
  union {
    char *identifier;
    int ival;
    float fval;
    struct iarr {
      int *array;
      int size;
    } iarr;
    struct farr {
      float *array;
      int size;
    } farr;
    char *sval;
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
ASTNode *createStringNode(char *sval);
void printAST(ASTNode *node, int level);
ASTNode *executeAST(ASTNode *node);

#endif // AST_H