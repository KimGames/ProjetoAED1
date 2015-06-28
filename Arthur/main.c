#include "ll.h"
int main(){
    No* L1,*L2,*L3;

    L1=criaLista();
    L2=criaLista();
    L3=criaLista();

    L1=insereOrdenado(L1,2,2);
    L1=insereOrdenado(L1,1,1);
    L1=insereOrdenado(L1,3,3);

    L2=insereOrdenado(L2,1,1);
    L2=insereOrdenado(L2,1,2);
    L2=insereOrdenado(L2,1,3);

    imprimeLista(L1);
    printf("\n");
    imprimeLista(L2);



    L3=somaPolinomio(L1,L2,L3);
    printf("\n");
    imprimeLista(L3);


    return 0;



}
