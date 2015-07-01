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

No* concatenaLista(No *L1, No *L2) {
  No *aux1 = L1;
  No *aux2 = L2;
  No *L3 = criaLista();

  while(aux1 != NULL) {
    L3 = insereOrdenado(L3, aux1->coef, aux1->exp);
    aux1 = aux1->prox;
  }

  while(aux2 != NULL) {
    L3 = insereOrdenado(L3, aux2->coef, aux2->exp);
    aux2 = aux2->prox;
  }
  return L3;
}

No* buscaLista(No*L,float coef, int exp){
  No* p=L;

  while((p!=NULL)&&((p->coef!=coef)||p->exp!=exp)){
    p=p->prox;
  }
  return p;
}

No* buscaListaCoef(No *L, int coef) {
  No* p=L;

  while(p!=NULL && p->coef!=coef) {
    p=p->prox;
  }
  return p;
}

No* buscaListaExp(No *L, int exp) {
  No* p=L;

  while(p!=NULL && p->exp!=exp) {
    p=p->prox;
  }
  return p;
}

int contaOcorrenciasGrau(No *P1, int exp) {
  No *aux = P1;
  int ocorrencias = 0;

  while (aux != NULL) {
    if(aux->exp == exp) {
      ocorrencias++;
    }
    aux = aux->prox;
  }
  return ocorrencias;
}

void destroiLista(No*L){
  No* t,*p=L;

  while(p!=NULL){
    t=p->prox;
    free(p);
    p=t;
  }
}

void simplificaPolinomio(No *P1) {
  No *aux = P1;

  while (aux != NULL) {
    //remove o elemento se encontra o valor zero em seu coeficiente
    if(aux->coef == 0) {
      aux = removeLista(aux, aux->exp, aux->coef);
    }

    //soma os coeficientes dos elementos com o mesmo expoente
    //e os remove até que exista apenas um elemento para cada expoente
    else if(contaOcorrenciasGrau(aux, aux->exp) > 1) {
      //incompleta
    }

    //pula para a próxima posição se nada foi removido
    else {
      aux = aux->prox;
    }
  }
}


/* No* insereSomando(No*L,float coef,int exp){ */
/*   No*ant=NULL,*post=L,*novo; */

/*   //acha a posição de inserção */
/*   while((post!=NULL)&&((post->exp > exp)&&(post->exp!=exp))) { */
/*     ant = post; */
/*     post=post->prox; */
/*   } */
/*   if((L!=NULL)&&(post!=NULL)){//se as listas nao chegaram ao fim */
/*     if (post->exp == exp){//ja existe o grau a ser inserido */
/*       post->coef = post->coef+coef; */
/*       return L; */
/*     } */
/*   } */

/*   //nao existe o grau a ser inserido */
/*   novo = (No*)malloc(sizeof(No)); */
/*   novo->coef=coef; */
/*   novo->exp=exp; */
/*   if (novo==NULL){ */
/*     printf("Erro de alocacao"); */
/*     exit(1); */
/*   } */
/*   if (ant==NULL){ */
/*     novo->prox = post; */
/*     L=novo; */
/*   }else{ */
/*     ant->prox=novo; */
/*     novo->prox=post; */
/*   } */

/*   return L; */
/* } */

/* No* somaPolinomio(No*P1,No*P2,No*P3){ */
/*   No* aux1=P1,*aux2=P2; */

/*   while((aux1!=NULL)||(aux2!=NULL)){ */
/*     if(aux1!=NULL){ */
/*       P3=insereSomando(P3,aux1->coef,aux1->exp); */
/*       aux1=aux1->prox; */
/*     } */
/*     if(aux2!=NULL){ */
/*       P3=insereSomando(P3,aux2->coef,aux2->exp); */
/*       aux2=aux2->prox; */
/*     } */
/*   } */
/*   return P3; */
/* } */

float calculaValor(No *P1, float x) {
  No *aux = P1;
  float valor = 0;

  while (aux!=NULL) {
    valor = valor + (pow(x, aux->exp) * aux->coef);
  }
  return valor;
}

No* somaPolinomio(No *P1, No *P2) {
  No *P3 = criaLista();

  //a "soma" é feita ao simplificar o polinômio proveniente da concatenação de P1 e P2
  P3 = concatenaLista(P1, P2);
  simplificaPolinomio(P3);

  return P3;
}

No* subtraiPolinomio(No *P1, No *P2) {
  No *aux = P2;
  No* P2negativa = criaLista();
  No* P3 = criaLista();

  while(aux != NULL) {//loop que nega o polinômio P2
    P2negativa = insereOrdenado(P2negativa, aux->coef, aux->exp);
    aux = aux->prox;
  }
  //analálogo ao soma polinômio
  P3 = concatenaLista(P1, P2negativa);
  simplificaPolinomio(P3);
  destroiLista(P2negativa);

  return P3;
}

No* dividePolinomio(No *P1, No *P2) {

  simplificaPolinomio(P2);
  //não pode haver divisão por zero, então devemos checar
  //se P2 é nulo após feita a simplificação
  if(P2 != NULL) {
    No *P3 = criaLista();
    //incompleta
    return P3;
  }
  else {
    return NULL;
  }
}

No* derivaPolinomio(No *P1) {
  No *aux = P1;
  No *P2 = criaLista();

  //loop que realiza a multiplicação do coeficiente de P1
  //por seu expoente e subtrai 1 de seu expoente
  //para todos os seus elementos
  while(aux!=NULL) {
    P2=insereOrdenado(P2, (aux->coef * aux->exp), (aux->exp - 1));
    aux=aux->prox;
  }
  return P2;
}

No* integraPolinomio(No *P1) {
  No *aux = P1;
  No *P2 = criaLista();

  //loop que realiza a divisão do coeficiente de P1
  //por seu expoente somado com 1 e soma 1 ao seu expoente
  //para todos os seus elementos
  while(aux!=NULL){
    P2=insereOrdenado(P2, (aux->coef / (aux->exp + 1)), (aux->exp + 1));
    aux=aux->prox;
  }

  //Faltando: inserir constante de integração
  return P2;
}
