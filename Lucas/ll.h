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
No* concatenaLista(No *L1, No *L2);
No* buscaLista(No*L,float coef,int exp);
No* buscaListaCoef(No *L, int coef);
No* buscaListaExp(No *L, int exp);
int contaOcorrenciasGrau(No *P1, int exp);
void destroiLista(No*L);
void simplificaPolinomio(No *P1);
//No* somaPolinomio(No*L1,No*L2,No*L3);
//No* insereSomando(No*L,float coef,int exp);
No* somaPolinomio(No *P1, No *P2);
No* subtraiPolinomio(No *P1, No *P2);
No* dividePolinomio(No *P1, No *P2);
No* derivaPolinomio(No *L1);
No* integraPolinomio(No *L1);
float calculaValor(No *P1, float x);


