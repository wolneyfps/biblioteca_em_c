#include <stdio.h>
#include "livro.h"

// --- Banco de Dados em Memória (Temporário) ---
#define MAX_LIVROS 100

Livro acervoDeLivros[MAX_LIVROS]; // O "fichário" que guarda todos os livros
int totalDeLivros = 0; // Um contador para saber quantos livros já temos

// --- Implementação das Funções ---
void adicionarLivro(void){
    // 1. Verifica se ainda há espaço no acervo
    if (totalDeLivros >= MAX_LIVROS) {
        printf("Erro: Acervo de livros esta cheio!\n");
        return; // Sai da função imediatamente
    }

// 2. Cria uma struct temporária para guardar os novos dados
Livro novoLivro;

printf("\n--- Cadastro de Novo Livro ---\n");

// 3. Pede e lê cada informação do usuário
printf("Digite o titulo: ");
scanf(" %[^\n]", novoLivro.titulo);

printf("Digite o autor: ");
scanf(" %[^\n]", novoLivro.autor);

printf("Digite o ano de publicacao: ");
scanf("%d", &novoLivro.anoPublicacao);

printf("Digite a quantidade de copias: ");
scanf("%d", &novoLivro.quantidade);

// 4. Gera um ID simples e sequencial
novoLivro.id = totalDeLivros + 1;

// 5. Adiciona o livro preenchido ao nosso "fichário"
acervoDeLivros[totalDeLivros] = novoLivro;

// 6. Incrementa o contador de livros
totalDeLivros++;

// 7. Informa ao usuário que a operação foi um sucesso
printf("\nLivro '%s' cadastrado com sucesso!\n", novoLivro.titulo);
}

void listarLivros(void) {
    printf("\n--- Acervo de Livros ---\n");

    // 1. Verifica se o acervo está vazio
    if (totalDeLivros == 0) {
        printf("Nenhum livro cadastrado no momento.\n");
        return; // Sai da função se não há livros para listar
    }

    // 2. Percorre o array e imprime os dados de cada livro
    for (int i = 0; i < totalDeLivros; i++) {
        printf("ID: %d | Titulo: %s | Autor: %s | Ano: %d | Qtd: %d\n",
               acervoDeLivros[i].id,
               acervoDeLivros[i].titulo,
               acervoDeLivros[i].autor,
               acervoDeLivros[i].anoPublicacao,
               acervoDeLivros[i].quantidade);
    }
}
