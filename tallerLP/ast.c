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

ASTNode *createFloatMatNode(farray **farr, int n, int m) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _FLOAT_ARR;
  node->value.fmat.array = farr;
  node->value.fmat.n = n;
  node->value.fmat.m = m;
  node->left = NULL;
  node->right = NULL;
  return node;
}

ASTNode *createModeloNode(float alpha, int n, float *beta, int m, float *tau,
                          farray **matriz) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _FLOAT_ARR;
  node->value.modelo.alpha = alpha;
  node->value.modelo.n = n;
  node->value.modelo.beta = beta;
  node->value.modelo.m = m;
  node->value.modelo.tau = tau;
  node->value.modelo.matriz = matriz;
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

int findDuplicates(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (str[i] == str[j]) {
        printf("duplicado: '%c' ", str[i]);
        return 1;
      }
    }
  }
  return 0;
}
ASTNode *createAlfabetoNode(char *sval) {
  if (findDuplicates(sval) == 1) {
    printf("ERROR: Los alfabetos no pueden tener duplicados\n");
    return NULL;
  }
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _ALFABETO;
  node->value.sval = strdup(sval);
  node->left = NULL;
  node->right = NULL;
  return node;
}
ASTNode *createCadenaMultiNode(char *cadena, int *counts, int size) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = _CADE_MULTI;
  node->value.cadena_m.cadena = strdup(cadena);
  node->value.cadena_m.counts = counts;
  node->value.cadena_m.size = size;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void printAST(ASTNode *node, int level) {
  if (node == NULL)
    return;
  for (int i = 0; i < level; i++)
    printf("\t");
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
  } else if (node->type == _ALFABETO) {
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
    ASTNode *result = get(node->value.identifier);
    if (result == NULL) {
      printf("ERROR: No se encontro la variable %s\n", node->value.identifier);
      return NULL;
    }
    return result;
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
  case _ALFABETO:
    return node;
  case _PLUS: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
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
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
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
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
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
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
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
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando1->type != _INT && operando2->type != _INT) {
      printf("tipo no aceptado para la operacion módulo");
      return NULL;
    }
    return createIntNode(operando1->value.ival % operando2->value.ival);
  }
  case _GT: {
    ASTNode *operando1 = executeAST(node->left);
    ASTNode *operando2 = executeAST(node->right);
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
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
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
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
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
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
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
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
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
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
    if (operando1 == NULL) {
      printf("ERROR: OPERANDOS");
    }
    if (operando2 == NULL) {
      printf("ERROR: OPERANDOS");
    }
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
    ASTNode *lp = executeAST(node->left);
    if (lp == NULL) {
      printf("ERROR: _IF\n");
      return NULL;
    }
    while (executeAST(node->left)->value.ival) {
      executeAST(node->right);
    }
    return NULL;
  }
  case _IF: {
    ASTNode *lp = executeAST(node->left);
    if (lp == NULL) {
      printf("ERROR: _IF\n");
      return NULL;
    }
    if (lp->value.ival == 1) {
      /*ESTO RETORNARIA NULL*/
      return executeAST(node->right);
    }
    return node;
  }
  case _ELSE: {
    ASTNode *lp = executeAST(node->left);
    /*SI NO ES NULL EL IF FUE FALSO*/
    if (lp) {
      return executeAST(node->right);
    }
    return NULL;
  }
  case _aINT: {
    ASTNode *rp = executeAST(node->right);
    if (rp == NULL) {
      printf("ERROR: _aINT\n");
      return NULL;
    }
    if (rp->type != _INT) {
      printf("ERROR: Asignacion de tipo %s en INT\n", get_enum_name(rp->type));
    }
    insert(node->left->value.identifier, rp);
    return NULL;
  }
  case _aINT_ARR: {
    ASTNode *rp = executeAST(node->right);
    if (rp == NULL) {
      printf("ERROR: _aINTARR\n");
      return NULL;
    }
    if (rp->type != _INT_ARR) {
      printf("ERROR: Asignacion de tipo %s en arreglo INT\n",
             get_enum_name(rp->type));
      return NULL;
    }
    insert(node->left->value.identifier, rp);
    return NULL;
  }
  case _aFLOAT: {
    ASTNode *rp = executeAST(node->right);
    if (rp == NULL) {
      printf("ERROR: _aFLOAT\n");
      return NULL;
    }
    if (rp->type != _FLOAT) {
      printf("ERROR: Asignacion de tipo %s en FLOAT\n",
             get_enum_name(rp->type));
    }
    insert(node->left->value.identifier, rp);
    return NULL;
  }
  case _aFLOAT_ARR: {
    ASTNode *rp = executeAST(node->right);
    if (rp == NULL) {
      printf("ERROR: _aINTARR\n");
      return NULL;
    }
    if (rp->type != _FLOAT_ARR) {
      printf("ERROR: Asignacion de tipo %s en arreglo INT\n",
             get_enum_name(rp->type));
      return NULL;
    }
    insert(node->left->value.identifier, rp);
    return NULL;
  }
  case _aCADENA: {
    ASTNode *rp = executeAST(node->right);
    if (rp == NULL) {
      printf("ERROR: _aCADENA\n");
      return NULL;
    }
    if (rp->type != _CADENA) {
      printf("ERROR: Asignacion de tipo %s en CADENA\n",
             get_enum_name(rp->type));
    }
    insert(node->left->value.identifier, rp);
    return NULL;
  }
  case _aALFABETO: {
    ASTNode *rp = executeAST(node->right);
    if (rp == NULL) {
      printf("ERROR: _aALFABETO\n");
      return NULL;
    }
    if (rp->type != _CADENA) {
      printf("ERROR: Asignacion de tipo %s en ALFABETOA\n",
             get_enum_name(rp->type));
    }
    ASTNode *new_node = createAlfabetoNode(rp->value.sval);
    if (new_node == NULL) {
      return NULL;
    }
    insert(node->left->value.identifier, new_node);
    return NULL;
  }
  case _PRINT: {
    ASTNode *lp = executeAST(node->left);
    if (lp == NULL) {
      printf("ERROR: No es una expresión imprimible\n");
      return NULL;
    }
    if (lp->type == _INT) {
      printf("%d\n", lp->value.ival);
    } else if (lp->type == _FLOAT) {
      printf("%f\n", lp->value.fval);
    } else if (lp->type == _CADENA || lp->type == _ALFABETO) {
      printf("%s\n", lp->value.sval);
    } else if (lp->type == _INT_ARR) {
      printf("[%d", lp->value.iarr.array[0]);
      for (int i = 1; i < lp->value.iarr.size; i++) {
        printf(",%d", lp->value.iarr.array[i]);
      }
      printf("]\n");
    } else if (lp->type == _FLOAT_ARR) {
      printf("[%f", lp->value.farr.array[0]);
      for (int i = 1; i < lp->value.farr.size; i++) {
        printf(",%f", lp->value.farr.array[i]);
      }
      printf("]\n");

    } else if (lp->type == _CADE_MULTI) {
      for (int i = 0; i < lp->value.cadena_m.size; i++) {
        printf("%c: %d\n", lp->value.cadena_m.cadena[i],
               lp->value.cadena_m.counts[i]);
      }
    } else {
      printf("ERROR: No es una expresión imprimible\n");
    }
    return NULL;
  }
  case _SVARR: {
    ASTNode *lp = executeAST(node->left);
    ASTNode *rp = executeAST(node->right);
    if (rp == NULL || lp == NULL) {
      printf("ERROR: _SVARR\n");
      return NULL;
    }
    if (rp->type != _INT) {
      printf("ERROR: El índice no es entero\n");
      return NULL;
    }
    if (lp->type == _INT_ARR) {
      return createIntNode(lp->value.iarr.array[rp->value.ival]);
    }
    if (lp->type == _FLOAT_ARR) {
      return createFloatNode(lp->value.farr.array[rp->value.ival]);
    }
    printf("ERROR: No es un arreglo entero o flotante\n");
    return NULL;
  }
  case _RELOC: {
    ASTNode *lp = executeAST(node->right);
    if (lp == NULL) {
      printf("ERROR: _RELOC\n");
      return NULL;
    }
    update(node->left->value.identifier, lp);
    return NULL;
  }
  case _RELOC_ARR: {
    ASTNode *lp = node->right->left;
    ASTNode *rp = node->right->right;
    if (node->left == NULL) {
      printf("ERROR: _RELOC_ARR\n");
      return NULL;
    }
    if (node->left->type != _IDENTIFIER) {
      printf("ERROR: Asignando sin nombre\n");
      return NULL;
    }
    if (lp == NULL || rp == NULL) {
      printf("ERROR: _RELOC_ARR\n");
      return NULL;
    }
    update_arr(node->left->value.identifier, executeAST(rp), executeAST(lp));
    return NULL;
  }
  case _SIZE: {
    ASTNode *lp = executeAST(node->left);
    if (lp == NULL) {
      printf("ERROR: _SIZE\n");
      return NULL;
    }
    if (lp->type == _CADENA || lp->type || _ALFABETO) {
      return createIntNode(strlen(lp->value.sval));
    }
    if (lp->type == _INT_ARR) {
      return createIntNode(lp->value.iarr.size);
    }
    if (lp->type == _FLOAT_ARR) {
      return createIntNode(lp->value.farr.size);
    }
    printf("ERROR: Size no esta definido para este tipo de dato\n");
    return NULL;
  }
  case _CAT: {
    ASTNode *lp = executeAST(node->left);
    if (lp == NULL) {
      printf("ERROR: _CAT\n");
      return NULL;
    }
    if (lp->type != _CADENA) {
      printf("ERROR: Categorizar no esta definido para este tipo de dato\n");
      return NULL;
    }
    int *counts = malloc(sizeof(int));
    char cadena[100] = "";
    int size = 1;
    char buff = lp->value.sval[0];
    int count = 1;
    for (char *str = lp->value.sval + 1; *str != '\0'; str++) {
      if (buff == *str) {
        count++;
      } else {
        cadena[size - 1] = buff;
        counts = realloc(counts, (sizeof(int) * size));
        counts[size - 1] = count;
        size++;
        count = 1;
        buff = *str;
      }
    }
    strcat(cadena, &buff);
    counts = realloc(counts, size * sizeof(int));
    counts[size - 1] = count;
    return createCadenaMultiNode(strdup(cadena), counts, size);
  }
  case _CADE_MULTI: {
    return node;
  }
  case _aCADE_MULTI: {
    ASTNode *cadena = executeAST(node->right->left);
    ASTNode *iarr = executeAST(node->right->right->left);
    ASTNode *size = executeAST(node->right->right->right);
    if (cadena == NULL || iarr == NULL || size == NULL) {
      printf("ERROR: _aALFABETO\n");
      return NULL;
    }
    if (cadena->type != _CADENA || iarr->type != _INT_ARR ||
        size->type != _INT) {
      printf("ERROR: Asignacion de tipo en CADE_MULTI\n");
    }
    ASTNode *new_node = createCadenaMultiNode(
        strdup(cadena->value.sval), iarr->value.iarr.array, size->value.ival);
    if (new_node == NULL) {
      return NULL;
    }
    insert(node->left->value.identifier, new_node);
    return NULL;
  }
  case _FLOAT_MAT:
    return node;
  case _MODELO:
    return node;
  case _aMODELO: {
    ASTNode *alpha = executeAST(node->right->left);
    if (alpha == NULL) {
      return NULL;
    }
    ASTNode *n = executeAST(node->right->right->left);
    if (n == NULL) {
      return NULL;
    }
    ASTNode *beta = executeAST(node->right->right->right->left);
    if (beta == NULL) {
      return NULL;
    }
    ASTNode *m = executeAST(node->right->right->right->right->left);
    if (m == NULL) {
      return NULL;
    }
    ASTNode *tau = executeAST(node->right->right->right->right->right->left);
    if (tau == NULL) {
      return NULL;
    }
    ASTNode *matriz =
        executeAST(node->right->right->right->right->right->right);
    if (matriz == NULL) {
      return NULL;
    }
    if (alpha->type != _FLOAT || n->type != _INT || beta->type != _FLOAT_ARR ||
        m->type != _INT || tau->type != _FLOAT_ARR ||
        matriz->type != _FLOAT_MAT) {
      printf("ERROR: Asignacion de tipo en CADE_MULTI\n");
    }
    ASTNode *new_node = createModeloNode(
        alpha->value.fval, n->value.ival, beta->value.farr.array, m->value.ival,
        tau->value.farr.array, matriz->value.fmat.array);
    if (new_node == NULL) {
      return NULL;
    }
    insert(node->left->value.identifier, new_node);
    return NULL;
  }
    return NULL;
  default:
    printf("ERROR: Nodo AST no reconocido %s\n", get_enum_name(node->type));
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
  case _ALFABETO:
    return "ALFABETO";
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
  case _aALFABETO:
    return "Asignacion alfabeto";
  case _PRINT:
    return "PRINT";
  case _SVARR:
    return "Elemento de un array";
  case _RELOC:
    return "Redeclaracion";
  case _RELOC_ARR:
    return "Redeclaracion elemnto array";
  case _RELOC_ARR_AUX:
    return "Auxiliar para redeclaracion elemnto array";
  case _MODELO:
    return "Modelo";
  case _aMODELO:
    return "Asignacion para modelos";
  case _SIZE:
    return "Tamaño";
  case _CAT:
    return "Categorias";
  case _CADE_MULTI:
    return "Cadena multi";
  case _aCADE_MULTI:
    return "Asignacion cadena multi";
  case _FLOAT_MAT:
    return "matriz float";
  case _aFLOAT_MAT:
    return "Asignar matriz float";
  default:
    return "enum_error";
  }
}
