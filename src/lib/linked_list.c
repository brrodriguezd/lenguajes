#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
  struct Nodo *next;
  int dato;
}nodo;

void create_nodo(nodo *nodo, int dato) {
  nodo->dato = dato;
  nodo->next = NULL;
}

typedef struct LinkedList{
  nodo *head;
  nodo *tail;
}linked_list;

void create_list(linked_list *lista) {
  lista->head = NULL;
  lista->tail = NULL;
}

void PushFront(linked_list *lista, int dato) {
  nodo *nodo_nuevo;
  nodo_nuevo = malloc(sizeof(nodo));
  create_nodo(nodo_nuevo, dato);
  lista->head = nodo_nuevo;
  if (lista->tail == NULL) {
    lista->tail = lista->head;
  }
}
int TopFront(linked_list *lista) {
  if (lista->head == NULL) {
    printf("ERROR: Está vacio");
    return -1;
  }
  return lista->head->dato;
}
int PopFront(linked_list *lista) {
  if (lista->head == NULL) {
    printf("ERROR: Está vacio");
    return -1;
  }
  nodo *delete = lista->head;
  int dato = delete->dato;
  lista->head = lista->head->next;
  free(delete);
  if (lista->head == NULL) {
    lista->tail = NULL;
  }
  return dato;
}
void PushBack(linked_list *lista, int dato) {
  nodo *nodo_nuevo;
  nodo_nuevo = malloc(sizeof(nodo));
  create_nodo(nodo_nuevo, dato);
  if (lista->head == NULL) {
    lista->head = nodo_nuevo;
    lista->tail = nodo_nuevo;
    return;
  }
  lista->tail->next = nodo_nuevo;
  lista->tail = nodo_nuevo;
}
int TopBack(linked_list *lista) {
  if (lista->tail == NULL) {
    printf("ERROR: Está vacio");
    return -1;
  }
  return lista->tail->dato;
}
int PopBack(linked_list *lista) {
  if (lista->head == NULL) {
    printf("ERROR: Está vacio");
    return -1;
  }
  if (lista->tail == lista->head) {
    lista->tail = lista->head = NULL;
    return -1;
  }
  nodo *recorrer = lista->head;
  while (recorrer->next->next != NULL) {
    recorrer = recorrer->next;
  }
  nodo *delete = recorrer->next;
  int dato = delete->dato;
  recorrer->next = NULL;
  free(delete);
  lista->tail = recorrer;
  return dato;
}
nodo *Find(linked_list *lista, int dato) {
  nodo *recorrer = lista->head;
  while (recorrer != NULL) {
    if (recorrer->dato == dato) {
      return recorrer;
    }
    recorrer = recorrer->next;
  }
  printf("ERROR: Está vacio");
  return recorrer;
}
void Erase(linked_list *lista, int dato) {
  if (lista->head == NULL) {
    printf("ERROR: Está vacio");
    return;
  }
  nodo *recorrer = lista->head;
  if (lista->head->dato == dato) {
    PopFront(lista);
    return;
  }
  while (recorrer->next != NULL) {
    if (recorrer->next->dato == dato) {
      if (recorrer->next == lista->tail) {
        nodo *delete = recorrer->next;
        recorrer->next = NULL;
        free(delete);
        lista->tail = recorrer;
        return;
      }
      recorrer->next = recorrer->next->next;
      return;
    }
    recorrer = recorrer->next;
  }
  printf("no se encontro el dato");
  return;
}
int Empty(linked_list *lista) { return lista->head == NULL; }

void AddBefore(linked_list *lista, nodo *nodo_base, int dato) {
  nodo *nodo_nuevo;
  create_nodo(nodo_nuevo, dato);
  nodo_nuevo = malloc(sizeof(nodo));
  nodo_nuevo->next = nodo_base;
  if (nodo_base == lista->head) {
    lista->head = nodo_nuevo;
    return;
  }
  nodo *recorrer = lista->head;
  while (recorrer != NULL) {
    if (recorrer->next == nodo_base) {
      recorrer->next = nodo_nuevo;
      return;
    }
    recorrer = recorrer->next;
  }
  printf("No existe el dato");
  return;
}
void AddAfter(linked_list *list, nodo *nodo_base, int dato) {
  nodo *nodo_nuevo;
  nodo_nuevo = malloc(sizeof(nodo));
  create_nodo(nodo_nuevo, dato);
  nodo_base->next = nodo_nuevo;
  if (list->tail == nodo_base) {
    list->tail = nodo_nuevo;
  }
}
void Display(linked_list *list) {
  if (list->head != NULL) {
    nodo *recorrer = list->head;
    while (recorrer != NULL) {
      printf("%d ", recorrer->dato);
      recorrer = recorrer->next;
    }
  }
  printf("\n");
}
void DisplayBackwards(linked_list *list) {
  linked_list *listainv;
  nodo *recorrer = list->head;
  while (recorrer != NULL) {
    PushFront(list, recorrer->dato);
    recorrer = recorrer->next;
  }
  Display(list);
};