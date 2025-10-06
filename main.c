#include <stdio.h>
#include "livro.h"
#include "database.h"

int main(void) {
    carregarDados(); // <-- ADICIONAR: Carrega os dados na inicialização
    int opcao;

    do {
        printf("\n--- Biblioteca ---\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro();
                break;
            case 2:
                listarLivros();
                break;
            case 0:
                printf("Saindo...\n");
                salvarDados();
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
