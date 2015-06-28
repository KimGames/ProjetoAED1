#include "ll.h"


No* criaLista(){
    return NULL;
}

void imprimeLista(No*L){
    No* p=L;

    while(p!=NULL){
        printf("%dx^%d  ",p->coef,p->exp);
        p=p->prox;
    }
    printf("\n");
}

No* insereInicio(No*L,int coef,int exp){
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

No* insereOrdenado(No*L,int coef, int exp){
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

No* removeLista(No*L,int coef, int exp){
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

No* buscaLista(No*L,int coef, int exp){
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

No* somaPolinomio(No*L1,No*L2,No*L3){
    No* aux1=L1,*aux2=L2;

    while((aux1!=NULL)||(aux2!=NULL)){
        if(aux1!=NULL){
            L3=insereSomando(L3,aux1->coef,aux1->exp);
            aux1=aux1->prox;
        }
        if(aux2!=NULL){
            L3=insereSomando(L3,aux2->coef,aux2->exp);
            aux2=aux2->prox;
        }
    }
    return L3;
}
No* insereSomando(No*L,int coef,int exp){
    No*ant=NULL,*post=L,*novo;

    while((post!=NULL)&&((post->exp > exp)&&(post->exp!=exp))){
        ant = post;
        post=post->prox;
    }
    if((L!=NULL)&&(post!=NULL)){
        if (post->exp == exp){
            post->coef = post->coef+coef;
            return L;
        }
    }

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
