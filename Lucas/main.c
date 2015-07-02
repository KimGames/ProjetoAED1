#include "ll.h"

int main() {
  char op[1];
  char op2[1];
  float x;
  //char **log;

  do{
    printf("Escolha uma operação ou digite H para ajuda\n");
    scanf("%s", op);

    switch(op[0]) {
    case 'a':
      printf("\n");
      break;
    case 'b':
      printf("\n");
      break;
    case 'c':
      printf("\n");
      break;
    case 'd':
      printf("\n");
      break;
    case 'e':
      printf("\n");
      break;
    case 'f':
      printf("\n");
      break;
    case 'g':
      //simplificaPolinomio();
      printf("Polinômio simplificado!\n");
      break;
    case 'h':
      printf("\n");
      break;
    case 'i':
      do {
        printf("1-Inserir novo polinômio\n2-Inserir valor de x\n");
        scanf("%s", op2);
        if(op2[0] == '1') {
          //aloca polinomios em uma lista de listas
        }
        else {
          printf("Valor de x: ");
          scanf("%f", &x);
          //calcula valor composto
        }
      }while(op2[0] != 0);
      printf("\n");
      break;
    case 'j':
      printf("\n");
      break;

    case 'H':
      printf("a) Somar polinômios");
      printf("b) Subtrair polinômios\n");
      printf("c) Multiplicar polinômios\n");
      printf("d) Dividir polinômios\n");
      printf("e) Derivar um polinômio\n");
      printf("f) Integrar um polinômio\n");
      printf("g) Simplificar um polinômio\n");
      printf("h) Calcular o resultado de um polinômio\n");
      printf("i) Calcular o resultado de um polinômio composto\n");
      printf("j) Salvar o log de operações em texto\n");
      printf("\nS) Sair\n\n");
      break;
    case 'S':
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida.\n");
    }
  }while(op[0] != 'S');

  return 0;
}
