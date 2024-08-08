#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ASTNode *createNode(enum types type, ASTNode *left, ASTNode *right) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = type;
  node->left = left;
  node->right = right;
  return node;
}

ASTNode *createIdentifierNode(char *identifier) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _IDENTIFIER;
  node->value.identifier = strdup(identifier);
  node->left = NULL;
  node->right = NULL;
  return node;
}

ASTNode *createIntNode(int *ival, int size) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _INT;
  node->value.ival.array = ival;
  node->value.ival.size = size;
  node->left = NULL;
  node->right = NULL;
  return node;
}

ASTNode *createFloatNode(float *fval, int size) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _FLOAT;
  node->value.fval.array = fval;
  node->value.fval.size = size;
  node->left = NULL;
  node->right = NULL;
  return node;
}

ASTNode *createStringNode(char *sval) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _CADENA;
  node->value.sval = strdup(sval);
  node->left = NULL;
  node->right = NULL;
  return node;
}

void printAST(ASTNode *node, int level) {
  if (node == NULL)
    return;
  for (int i = 0; i < level; i++)
    printf("  ");
  if (node->type == _IDENTIFIER) {
    printf("IDENTIFIER: %s\n", node->value.identifier);
  } else if (node->type == _INT) {
    if (node->value.ival.size == 1) {
      printf("%s: %d\n", get_enum_name(node->type), node->value.ival.array[0]);
    } else {
      printf("%s[%d]: [%d", get_enum_name(node->type), node->value.ival.size,
             node->value.ival.array[0]);
      for (int i = 1; i < node->value.ival.size; i++) {
        printf(", %d", node->value.ival.array[i]);
      }
      printf("]\n");
    }
  } else if (node->type == _FLOAT) {
    if (node->value.fval.size == 1) {
      printf("%s: %f\n", get_enum_name(node->type), node->value.fval.array[0]);
    } else {
      printf("%s[%d]: [%f", get_enum_name(node->type), node->value.fval.size,
             node->value.fval.array[0]);
      for (int i = 1; i < node->value.fval.size; i++) {
        printf(", %f", node->value.fval.array[i]);
      }
      printf("]\n");
    }
  } else if (node->type == _CADENA) {
    printf("%s: %s\n", get_enum_name(node->type), node->value.sval);
  } else {
    printf("%s\n", get_enum_name(node->type));
  }
  printAST(node->left, level + 1);
  printAST(node->right, level + 1);
}

ASTNode *executeAST(ASTNode *node) {
  if (node == NULL) {
    return NULL;
  }
  switch (node->type) {
  case _IDENTIFIER:
    return NULL;
  case _INT:
    return NULL;
  case _FLOAT:
    return NULL;
  case _CADENA:
    return NULL;
  case _PLUS:
    return NULL;
  case _MINUS:
    return NULL;
  case _MUL:
    return NULL;
  case _DIV:
    return NULL;
  case _MOD:
    return NULL;
  case _GT:
    return NULL;
  case _LT:
    return NULL;
  case _GE:
    return NULL;
  case _LE:
    return NULL;
  case _NE:
    return NULL;
  case _EQ:
    return NULL;
  case _BLOCK:
    return NULL;
  case _WHILE:
    return NULL;
  case _IF:
    return NULL;
  case _ELSE:
    return NULL;
  case _aINT:
    return NULL;
  case _aFLOAT:
    return NULL;
  case _aCADENA:
    return NULL;
  case _PRINT:
    return NULL;
  default:
    return NULL;
  }
  if (node->type == _INT) {
    printf("%d\n", node->value.ival.array[0]);
  } else if (node->type == _FLOAT) {
    printf("%f\n", node->value.fval.array[0]);
  } else if (node->type == _IDENTIFIER) {
    printf("%s\n", node->value.identifier);
  } else if (node->type == _PLUS) {
  } else if (node->type == _MINUS) {
  } else if (node->type == _MUL) {
  } else if (node->type == _DIV) {
  } else if (node->type == _MOD) {
  } else if (node->type == _WHILE) {
  } else if (node->type == _IF) {
  } else if (node->type == _aINT) {
  } else if (node->type == _aFLOAT) {
  } else if (node->type == _aCADENA) {
  } else if (node->type == _PRINT) {
  }
}

char *get_enum_name(enum types type) {
  switch (type) {
  case _IDENTIFIER:
    return "IDENTIFIER";
  case _INT:
    return "INT";
  case _FLOAT:
    return "FLOAT";
  case _CADENA:
    return "CADENA";
  case _PLUS:
    return "+";
  case _MINUS:
    return "-";
  case _MUL:
    return "*";
  case _DIV:
    return "/";
  case _MOD:
    return "%";
  case _GT:
    return ">";
  case _LT:
    return "<";
  case _GE:
    return ">=";
  case _LE:
    return "<=";
  case _NE:
    return "!=";
  case _EQ:
    return "==";
  case _BLOCK:
    return "BLOQUE";
  case _WHILE:
    return "WHILE";
  case _IF:
    return "IF";
  case _ELSE:
    return "ELSE";
  case _aINT:
    return "Asignacion int";
  case _aFLOAT:
    return "Asignacion float";
  case _aCADENA:
    return "Asignacion cadena";
  case _PRINT:
    return "PRINT";
  default:
    return "enum_error";
  }
}
