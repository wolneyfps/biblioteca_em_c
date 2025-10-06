#include <stdio.h>
#include "livro.h"

int main(void) {
    int opcao;

    do {
        printf("\n--- Biblioteca ---\n");
        printf("1. Adicionar Livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}