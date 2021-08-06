#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista {
  int codigo;
  char origem[20];
  float peso;
  int tirado;
  int tam;
  struct lista* prox;
  struct lista* ant;
};

typedef struct lista Lista;

void menu();
Lista* push(Lista* l, int ori);

void imprimir(Lista* l);

Lista* pop(Lista *l, int valor);

