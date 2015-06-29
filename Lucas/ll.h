#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct no{
  float coef;
  int exp;
  struct no* prox;
};typedef struct no No;

No* criaLista();
void imprimeLista(No*L);
No* insereInicio(No*L,float coef,int exp);
No* insereOrdenado(No*L,float coef, int exp);
No* removeLista(No*L,float coef,int exp);
No* buscaLista(No*L,float coef,int exp);
void destroiLista(No*L);
No* somaPolinomio(No*L1,No*L2,No*L3);
No* insereSomando(No*L,float coef,int exp);
No* derivaPolinomio(No *L1);
No* integraPolinomio(No *L1);
float calculaValor(No *P1, float x);
