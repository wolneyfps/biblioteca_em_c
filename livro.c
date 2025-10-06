#include <stdio.h>
#include "livro.h"

// --- Banco de Dados em Memória (Temporário) ---
#define MAX_LIVROS 100

Livro acervoDeLivros[MAX_LIVROS]; // O "fichário" que guarda todos os livros
int totalDeLivros = 0;           // Um contador para saber quantos livros já temos

// --- Implementação das Funções ---
void adicionarLivro(void) {
    // Lógica para adicionar um livro virá aqui
    printf("\nFuncao 'adicionarLivro' foi chamada!\n");
}