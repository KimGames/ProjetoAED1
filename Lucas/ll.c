#include "ll.h"

No* criaLista(){
  return NULL;
}

void imprimeLista(No*L){
  No* p=L;

  while(p!=NULL){
    printf("%.1fx^%d  ",p->coef,p->exp);
    p=p->prox;
  }
  printf("\n");
}
No* insereInicio(No*L,float coef,int exp){
  No* p=L,*novo;
  novo = (No*)malloc(sizeof(No));
  if (novo == NULL){
    printf("Erro de alocacao!");
    exit(1);
  }
  novo->coef = coef;
  novo->exp = exp;
  novo->prox = p;
  return novo;
}

No* insereOrdenado(No*L,float coef, int exp){
  No*ant,*prox=L,*novo;
  ant=NULL;
  novo = (No*)malloc(sizeof(No));
  if (novo == NULL){
    printf("Erro de alocacao!");
    exit(1);
  }
  novo->coef = coef;
  novo->exp = exp;
  while((prox!=NULL)&&(prox->exp > exp)){
    ant=prox;
    prox=prox->prox;
  }

  if (ant==NULL){
    novo->prox=prox;
    L=novo;
  }else{
    novo->prox=ant->prox;
    ant->prox = novo;
  }
  return L;
}

No* removeLista(No*L,float coef, int exp){
  No* ant,*atual=L;
  ant=NULL;
  while((atual!=NULL)&&((atual->coef!=coef)||(atual->exp!=exp))){
    ant = atual;
    atual = atual->prox;
  }
  if (atual == NULL){
    return L;
  }
  if (ant == NULL){
    L = atual->prox;
  }else{
    ant->prox = atual->prox;
  }
  free(atual);
  return L;
}

No* buscaLista(No*L,float coef, int exp){
  No* p=L;

  while((p!=NULL)&&((p->coef!=coef)||p->exp!=exp)){
    p=p->prox;
  }
  return p;
}

void destroiLista(No*L){
  No* t,*p=L;

  while(p!=NULL){
    t=p->prox;
    free(p);
    p=t;
  }
}

No* insereSomando(No*L,float coef,int exp){
  No*ant=NULL,*post=L,*novo;

  while((post!=NULL)&&((post->exp > exp)&&(post->exp!=exp))){//acha a posição de inserção
    ant = post;
    post=post->prox;
  }
  if((L!=NULL)&&(post!=NULL)){//se as listas nao chegaram ao fim
    if (post->exp == exp){//ja existe o grau a ser inserido
      post->coef = post->coef+coef;
      return L;
    }
  }

  //nao existe o grau a ser inserido
  novo = (No*)malloc(sizeof(No));
  novo->coef=coef;
  novo->exp=exp;
  if (novo==NULL){
    printf("Erro de alocacao");
    exit(1);
  }
  if (ant==NULL){
    novo->prox = post;
    L=novo;
  }else{
    ant->prox=novo;
    novo->prox=post;
  }

  return L;
}

No* somaPolinomio(No*P1,No*P2,No*P3){
  No* aux1=P1,*aux2=P2;

  while((aux1!=NULL)||(aux2!=NULL)){
    if(aux1!=NULL){
      P3=insereSomando(P3,aux1->coef,aux1->exp);
      aux1=aux1->prox;
    }
    if(aux2!=NULL){
      P3=insereSomando(P3,aux2->coef,aux2->exp);
      aux2=aux2->prox;
    }
  }
  return P3;
}

No* derivaPolinomio(No *P1) {
  No *aux = P1;
  No *P2 = criaLista();

  while(aux!=NULL) {
    P2=insereOrdenado(P2, (aux->coef * aux->exp), (aux->exp - 1));
    aux=aux->prox;
  }
  return P2;
}

No* integraPolinomio(No *P1) {
  No *aux = P1;
  No *P2 = criaLista();

  while(aux!=NULL){
    P2=insereOrdenado(P2, (aux->coef / (aux->exp + 1)), (aux->exp + 1));
    aux=aux->prox;
  }
  //Inserir Constante de Integração
  return P2;
}

float calculaValor(No *P1, float x) {
  No *aux = P1;
  float valor = 0;

  while (aux!=NULL) {
    valor = valor + (pow(x, aux->exp) * aux->coef);
  }
  return valor;
}

