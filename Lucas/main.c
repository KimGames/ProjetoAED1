#include "ll.c"

int main() {

  No *L1 = criaLista();
  No *L2 = criaLista();

  for (int i = 0; i < 3; i++) {
    L1 =  insereOrdenado(L1, i+1, i);
  }
  imprimeLista(L1);
  putchar('\n');

  L2 = derivaPolinomio(L1);
  imprimeLista(L2);
  imprimeLista(L1);
  putchar('\n');
  L2 = integraPolinomio(L1);
  imprimeLista(L1);
  imprimeLista(L2);
  putchar('\n');

  return 0;
}
