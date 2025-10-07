#include <stdio.h>
#include "livro.h"
#include "usuario.h"
#include "database.h"
#include "emprestimo.h"

int main(void) {
    carregarDados(); // Carrega os dados na inicialização
    int opcao;

    do {
        printf("\n--- Biblioteca ---\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Adicionar Usuario\n");
        printf("4. Listar Usuario\n");
        printf("5. Emprestimo\n");
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
            case 3:
                adicionarUsuario();
                break;
            case 4:
                listarUsuarios();
                break;
            case 5:
                realizarEmprestimo();
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
