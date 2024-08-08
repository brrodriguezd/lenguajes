#include "ast.h"
#include "symtab.h"
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

ASTNode *createIntNode(int ival) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _INT;
  node->value.ival = ival;
  node->left = NULL;
  node->right = NULL;
  return node;
}

ASTNode *createFloatNode(float fval) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _FLOAT;
  node->value.fval = fval;
  node->left = NULL;
  node->right = NULL;
  return node;
}

ASTNode *createIntArrNode(int *ival, int size) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _INT_ARR;
  node->value.iarr.array = ival;
  node->value.iarr.size = size;
  node->left = NULL;
  node->right = NULL;
  return node;
}

ASTNode *createFloatArrNode(float *fval, int size) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _FLOAT_ARR;
  node->value.farr.array = fval;
  node->value.farr.size = size;
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
    printf("%s: %d\n", get_enum_name(node->type), node->value.ival);
  } else if (node->type == _INT_ARR) {
    printf("%s[%d]: [%d", get_enum_name(node->type), node->value.iarr.size,
           node->value.iarr.array[0]);
    for (int i = 1; i < node->value.iarr.size; i++) {
      printf(", %d", node->value.iarr.array[i]);
    }
    printf("]\n");

  } else if (node->type == _FLOAT) {
    printf("%s: %f\n", get_enum_name(node->type), node->value.fval);
  } else if (node->type == _FLOAT_ARR) {
    printf("%s[%d]: [%f", get_enum_name(node->type), node->value.farr.size,
           node->value.farr.array[0]);
    for (int i = 1; i < node->value.farr.size; i++) {
      printf(", %f", node->value.farr.array[i]);
    }
    printf("]\n");
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
  case _IDENTIFIER: {
    int *success;
    ASTNode *result = malloc(sizeof(ASTNode));
    *result = get(node->value.identifier, success);
    if (*success == 1) {
      return result;
    }
    printf("ERROR: No se encontro la variable %s", node->value.identifier);
    return NULL;
  }
  case _INT:
    return node;
  case _INT_ARR:
    return node;
  case _FLOAT:
    return node;
  case _FLOAT_ARR:
    return node;
  case _CADENA:
    return node;
  case _PLUS: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type != _INT && operando2->type != _INT &&
        operando1->type != _FLOAT && operando2->type != _FLOAT) {
      printf("tipo no aceptado para la operacion +");
      return NULL;
    }
    if (operando1->type == _INT && operando2->type == _INT) {
      return createIntNode(operando1->value.ival + operando2->value.ival);
    }
    if (operando1->type == _INT && operando2->type == _FLOAT) {
      return createFloatNode(operando1->value.ival + operando2->value.fval);
    }
    if (operando1->type == _FLOAT && operando2->type == _INT) {
      return createFloatNode(operando1->value.fval + operando2->value.ival);
    }
    return createFloatNode(operando1->value.fval + operando2->value.fval);
  }
  case _MINUS: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type != _INT && operando2->type != _INT &&
        operando1->type != _FLOAT && operando2->type != _FLOAT) {
      printf("tipo no aceptado para la operacion -");
      return NULL;
    }
    if (operando1->type == _INT && operando2->type == _INT) {
      return createIntNode(operando1->value.ival - operando2->value.ival);
    }
    if (operando1->type == _INT && operando2->type == _FLOAT) {
      return createFloatNode(operando1->value.ival - operando2->value.fval);
    }
    if (operando1->type == _FLOAT && operando2->type == _INT) {
      return createFloatNode(operando1->value.fval - operando2->value.ival);
    }
    return createFloatNode(operando1->value.fval - operando2->value.fval);
  }
  case _MUL: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type == _CADENA && operando2->type == _CADENA) {
      char *respuesta = strdup(operando1->value.sval);
      strcat(respuesta, operando2->value.sval);
      return createStringNode(respuesta);
    }
    if (operando1->type != _INT && operando2->type != _INT &&
        operando1->type != _FLOAT && operando2->type != _FLOAT) {
      printf("tipo no aceptado para la operacion *");
      return NULL;
    }
    if (operando1->type == _INT && operando2->type == _INT) {
      return createIntNode(operando1->value.ival * operando2->value.ival);
    }
    if (operando1->type == _INT && operando2->type == _FLOAT) {
      return createFloatNode(operando1->value.ival * operando2->value.fval);
    }
    if (operando1->type == _FLOAT && operando2->type == _INT) {
      return createFloatNode(operando1->value.fval * operando2->value.ival);
    }
    return createFloatNode(operando1->value.fval * operando2->value.fval);
  }
  case _DIV: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type != _INT && operando2->type != _INT &&
        operando1->type != _FLOAT && operando2->type != _FLOAT) {
      printf("tipo no aceptado para la operacion /");
      return NULL;
    }
    if (operando1->type == _INT && operando2->type == _INT) {
      return createIntNode(operando1->value.ival / operando2->value.ival);
    }
    if (operando1->type == _INT && operando2->type == _FLOAT) {
      return createFloatNode(operando1->value.ival / operando2->value.fval);
    }
    if (operando1->type == _FLOAT && operando2->type == _INT) {
      return createFloatNode(operando1->value.fval / operando2->value.ival);
    }
    return createFloatNode(operando1->value.fval / operando2->value.fval);
  }
  case _MOD: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type != _INT && operando2->type != _INT) {
      printf("tipo no aceptado para la operacion módulo");
      return NULL;
    }
    return createIntNode(operando1->value.ival % operando2->value.ival);
  }
  case _GT: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type != _INT && operando2->type != _INT &&
        operando1->type != _FLOAT && operando2->type != _FLOAT) {
      printf("tipo no aceptado para la operacion >");
      return NULL;
    }
    if (operando1->type == _INT && operando2->type == _INT) {
      return createIntNode((operando1->value.ival > operando2->value.ival) ? 1
                                                                           : 0);
    }
    if (operando1->type == _INT && operando2->type == _FLOAT) {
      return createIntNode((operando1->value.ival > operando2->value.fval) ? 1
                                                                           : 0);
    }
    if (operando1->type == _FLOAT && operando2->type == _INT) {
      return createIntNode((operando1->value.fval > operando2->value.ival) ? 1
                                                                           : 0);
    }
    return createIntNode((operando1->value.fval > operando2->value.fval) ? 1
                                                                         : 0);
  }
  case _LT: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type != _INT && operando2->type != _INT &&
        operando1->type != _FLOAT && operando2->type != _FLOAT) {
      printf("tipo no aceptado para la operacion <");
      return NULL;
    }
    if (operando1->type == _INT && operando2->type == _INT) {
      return createIntNode((operando1->value.ival < operando2->value.ival) ? 1
                                                                           : 0);
    }
    if (operando1->type == _INT && operando2->type == _FLOAT) {
      return createIntNode((operando1->value.ival < operando2->value.fval) ? 1
                                                                           : 0);
    }
    if (operando1->type == _FLOAT && operando2->type == _INT) {
      return createIntNode((operando1->value.fval < operando2->value.ival) ? 1
                                                                           : 0);
    }
    return createIntNode((operando1->value.fval < operando2->value.fval) ? 1
                                                                         : 0);
  }
  case _GE: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type != _INT && operando2->type != _INT &&
        operando1->type != _FLOAT && operando2->type != _FLOAT) {
      printf("tipo no aceptado para la operacion >=");
      return NULL;
    }
    if (operando1->type == _INT && operando2->type == _INT) {
      return createIntNode(
          (operando1->value.ival >= operando2->value.ival) ? 1 : 0);
    }
    if (operando1->type == _INT && operando2->type == _FLOAT) {
      return createIntNode(
          (operando1->value.ival >= operando2->value.fval) ? 1 : 0);
    }
    if (operando1->type == _FLOAT && operando2->type == _INT) {
      return createIntNode(
          (operando1->value.fval >= operando2->value.ival) ? 1 : 0);
    }
    return createIntNode((operando1->value.fval >= operando2->value.fval) ? 1
                                                                          : 0);
  }
  case _LE: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type != _INT && operando2->type != _INT &&
        operando1->type != _FLOAT && operando2->type != _FLOAT) {
      printf("tipo no aceptado para la operacion <=");
      return NULL;
    }
    if (operando1->type == _INT && operando2->type == _INT) {
      return createIntNode(
          (operando1->value.ival <= operando2->value.ival) ? 1 : 0);
    }
    if (operando1->type == _INT && operando2->type == _FLOAT) {
      return createIntNode(
          (operando1->value.ival <= operando2->value.fval) ? 1 : 0);
    }
    if (operando1->type == _FLOAT && operando2->type == _INT) {
      return createIntNode(
          (operando1->value.fval <= operando2->value.ival) ? 1 : 0);
    }
    return createIntNode((operando1->value.fval <= operando2->value.fval) ? 1
                                                                          : 0);
  }
  case _NE: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type == _CADENA && operando2->type == _CADENA) {
      return (createIntNode(
          (operando1->value.sval != operando2->value.sval) ? 1 : 0));
    }
    if (operando1->type != _INT && operando2->type != _INT &&
        operando1->type != _FLOAT && operando2->type != _FLOAT) {
      printf("tipo no aceptado para la operacion !=");
      return NULL;
    }
    if (operando1->type == _INT && operando2->type == _INT) {
      return createIntNode(
          (operando1->value.ival != operando2->value.ival) ? 1 : 0);
    }
    if (operando1->type == _INT && operando2->type == _FLOAT) {
      return createIntNode(
          (operando1->value.ival != operando2->value.fval) ? 1 : 0);
    }
    if (operando1->type == _FLOAT && operando2->type == _INT) {
      return createIntNode(
          (operando1->value.fval != operando2->value.ival) ? 1 : 0);
    }
    return createIntNode((operando1->value.fval != operando2->value.fval) ? 1
                                                                          : 0);
  }
  case _EQ: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1->type == _CADENA && operando2->type == _CADENA) {
      return (createIntNode(
          (operando1->value.sval == operando2->value.sval) ? 1 : 0));
    }
    if (operando1->type != _INT && operando2->type != _INT &&
        operando1->type != _FLOAT && operando2->type != _FLOAT) {
      printf("tipo no aceptado para la operacion !=");
      return NULL;
    }
    if (operando1->type == _INT && operando2->type == _INT) {
      return createIntNode(
          (operando1->value.ival == operando2->value.ival) ? 1 : 0);
    }
    if (operando1->type == _INT && operando2->type == _FLOAT) {
      return createIntNode(
          (operando1->value.ival == operando2->value.fval) ? 1 : 0);
    }
    if (operando1->type == _FLOAT && operando2->type == _INT) {
      return createIntNode(
          (operando1->value.fval == operando2->value.ival) ? 1 : 0);
    }
    return createIntNode((operando1->value.fval == operando2->value.fval) ? 1
                                                                          : 0);
  }
  case _BLOCK:
    executeAST(node->left);
    executeAST(node->right);
    return NULL;
  case _WHILE: {
    while (executeAST(node->left)->value.ival) {
      executeAST(node->right);
    }
    return NULL;
  }
  case _IF:
    if (executeAST(node->left)->value.ival == 1) {
      if (node->right->type == _ELSE) {
        executeAST(node->right->left);
      }
      executeAST((node->left)->left);
    } else if (node->right->type == _ELSE) {
      executeAST(node->right->right);
    }
    return NULL;
  case _aINT: {
    ASTNode *rs = executeAST(node->right);
    if (rs->type != _INT) {
      printf("ERROR: Asignacion de tipo %s en INT", get_enum_name(rs->type));
    }
    insert(node->left->value.identifier, *(rs));
    return NULL;
  }
  case _aFLOAT: {
    ASTNode *rs = executeAST(node->right);
    if (rs->type != _FLOAT) {
      printf("ERROR: Asignacion de tipo %s en INT", get_enum_name(rs->type));
    }
    insert(node->left->value.identifier, *(rs));
    return NULL;
  }
  case _aCADENA: {
    ASTNode *rs = executeAST(node->right);
    if (rs->type != _CADENA) {
      printf("ERROR: Asignacion de tipo %s en INT", get_enum_name(rs->type));
    }
    insert(node->left->value.identifier, *(rs));
    return NULL;
  }
  case _PRINT: {
    ASTNode *rs = executeAST(node->left);
    if (rs->type == _INT) {
      printf("%d", rs->value.ival);
    } else if (rs->type == _FLOAT) {
      printf("%f", rs->value.fval);
    } else if (rs->type == _CADENA) {
      printf("%s", rs->value.sval);
    } else if (rs->type == _INT_ARR) {
      for (int i = 0; i < rs->value.iarr.size; i++) {
        printf("%d", rs->value.iarr.array[i]);
      }
    } else if (rs->type == _FLOAT_ARR) {
      for (int i = 0; i < rs->value.farr.size; i++) {
        printf("%f", rs->value.farr.array[i]);
      }
    }
    return NULL;
  }
  default:
    printf("ERROR: Nodo AST no reconocido %s", get_enum_name(node->type));
    return NULL;
  }
}

char *get_enum_name(enum types type) {
  switch (type) {
  case _IDENTIFIER:
    return "IDENTIFIER";
  case _INT:
    return "INT";
  case _INT_ARR:
    return "ARREGLO INT";
  case _FLOAT:
    return "FLOAT";
  case _FLOAT_ARR:
    return "ARREGLO FLOAT";
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
  case _aINT_ARR:
    return "Asignacion arreglo int";
  case _aFLOAT:
    return "Asignacion float";
  case _aFLOAT_ARR:
    return "Asignacion arreglo float";
  case _aCADENA:
    return "Asignacion cadena";
  case _PRINT:
    return "PRINT";
  default:
    return "enum_error";
  }
}
