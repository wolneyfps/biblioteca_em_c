#include <stdio.h>
#include "database.h"
#include "livro.h"

extern Livro acervoDeLivros[];
extern int totalDeLivros;

void salvarDados(void) {
    FILE *arquivo; // Declara um ponteiro de arquivo

    // Abre o arquivo "biblioteca.dat" em modo "write binary" (escrita binária)
    arquivo = fopen("biblioteca.dat", "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvamento!\n");
        return;
    }

    // 1º - Salva o NÚMERO de livros. Crucial para saber quantos ler depois.
    fwrite(&totalDeLivros, sizeof(int), 1, arquivo);

    // 2º - Salva o CONTEÚDO do acervo (o array inteiro)
    fwrite(acervoDeLivros, sizeof(Livro), totalDeLivros, arquivo);

    // Fecha o arquivo para garantir que tudo foi escrito no disco
    fclose(arquivo);
    printf("Dados salvos com sucesso!\n");
}

void carregarDados(void) {
    FILE *arquivo;

    // Abre o arquivo em modo "read binary" (leitura binária)
    arquivo = fopen("biblioteca.dat", "rb");

    // Se o arquivo não existe (primeira vez rodando), não faz nada.
    if (arquivo == NULL) {
        printf("Arquivo de dados nao encontrado. Iniciando com acervo vazio.\n");
        return;
    }

    // 1º - Lê o NÚMERO de livros do arquivo
    fread(&totalDeLivros, sizeof(int), 1, arquivo);

    // 2º - Lê o CONTEÚDO do acervo do arquivo
    fread(acervoDeLivros, sizeof(Livro), totalDeLivros, arquivo);

    fclose(arquivo);
    printf("-> %d livros carregados com sucesso!\n", totalDeLivros);
}