#include<stdio.h>
#include<stdlib.h>

struct no{
    int coef,exp;
    struct no* prox;
};typedef struct no No;

No* criaLista();
void imprimeLista(No*L);
No* insereInicio(No*L,int coef,int exp);
No* insereOrdenado(No*L,int coef, int exp);
No* removeLista(No*L,int coef,int exp);
No* buscaLista(No*L,int coef,int exp);
void destroiLista(No*L);
No* somaPolinomio(No*L1,No*L2,No*L3);
No* insereSomando(No*L,int coef,int exp);
