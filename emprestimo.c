#include <stdio.h>
#include "emprestimo.h"
#include "livro.h"
#include "usuario.h"
#include <stddef.h>
#include <time.h>

Livro *buscarLivroPorId(int id);

Usuario *buscarUsuarioPorId(int id);

#define MAX_EMPRESTIMOS 200

emprestimo ficharioDeEmprestimos[MAX_EMPRESTIMOS];
int totalDeEmprestimos = 0;

void realizarEmprestimo(void) {
    if (totalDeEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Erro: Limite de emprestimos simultaneos atingido.\n");
        return;
    }

    int id_livro, id_usuario;

    // --- 1. Coletar Dados ---
    printf("\n--- Realizar Emprestimo ---\n");
    printf("Digite o ID do livro a ser emprestado: ");
    scanf("%d", &id_livro);
    printf("Digite o ID do usuario: ");
    scanf("%d", &id_usuario);

    // --- 2. Validações ---
    Livro *livro = buscarLivroPorId(id_livro);
    Usuario *user = buscarUsuarioPorId(id_usuario);

    // Validação 2.1: O livro existe?
    if (livro == NULL) {
        printf("Erro: Livro com ID %d nao encontrado.\n", id_livro);
        return;
    }

    // Validação 2.2: O usuário existe?
    if (user == NULL) {
        printf("Erro: Usuario com ID %d nao encontrado.\n", id_usuario);
        return;
    }

    // Validação 2.3: O livro tem cópias disponíveis?
    if (livro->quantidade <= 0) {
        printf("Erro: Nao ha copias disponiveis do livro '%s'.\n", livro->titulo);
        return;
    }


    // --- 3. Executar a Ação ---

    // Diminui a quantidade de cópias do livro
    livro->quantidade--;

    // Cria o registro do empréstimo
    emprestimo novoEmprestimo;
    novoEmprestimo.id_livro = id_livro;
    novoEmprestimo.id_usuario = id_usuario;
    novoEmprestimo.data_emprestimo = time(NULL); // Pega a data/hora atual

    // Adiciona ao fichário de empréstimos
    ficharioDeEmprestimos[totalDeEmprestimos] = novoEmprestimo;
    totalDeEmprestimos++;

    // --- 4. Feedback ao Usuário ---
    printf("\nEmprestimo realizado com sucesso!\n");
    printf("Livro: '%s' | Usuario: '%s'\n", livro->titulo, user->nome);
}


void devolverLivro(void) {
    printf("Funcao Devolver Livro a ser implementada.\n");
}

void listarEmprestimos(void) {
    printf("Funcao Listar Emprestimos a ser implementada.\n");
}
