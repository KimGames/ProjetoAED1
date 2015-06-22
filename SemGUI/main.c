#include <stdio.h>
#include <stdlib.h>

int main() {
    char op[1];

    do{
        printf("Escolha uma operação ou digite H para ajuda\n");
        scanf("%s", op);

        switch(op[0]) {
        case 'a':
            printf("Opcao A escolhida.\n");
            break;
        case 'b':
            printf("Opcao B escolhida.\n");
            break;
        case 'c':
            printf("Opcao C escolhida.\n");
            break;
        case 'H':
            printf("\na) Somar ou subtrair polinômios\n");
            printf("b) Multiplicar ou dividir polinômios\n");
            printf("c) Refazer última operação\n");
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
