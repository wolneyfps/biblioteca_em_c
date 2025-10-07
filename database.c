
#include <stdio.h>
#include "database.h"
#include "livro.h"
#include "usuario.h"


//  variáveis de ambos os módulos existem externamente
extern Livro acervoDeLivros[];
extern int totalDeLivros;
extern usuario ficharioDeUsuarios[];
extern int totalDeUsuarios;

void salvarDados(void) {
    FILE *arquivo = fopen("biblioteca.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvamento!\n");
        return;
    }

    // Salva os dados dos LIVROS
    fwrite(&totalDeLivros, sizeof(int), 1, arquivo);
    fwrite(acervoDeLivros, sizeof(Livro), totalDeLivros, arquivo);

    // Salva os dados dos USUÁRIOS
    fwrite(&totalDeUsuarios, sizeof(int), 1, arquivo);
    fwrite(ficharioDeUsuarios, sizeof(usuario), totalDeUsuarios, arquivo);

    fclose(arquivo);
    printf("Dados de livros e usuarios salvos com sucesso!\n");
}

void carregarDados(void) {
    FILE *arquivo = fopen("biblioteca.dat", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de dados nao encontrado. Iniciando com acervo vazio.\n");
        return;
    }

    // Carrega os dados dos LIVROS
    fread(&totalDeLivros, sizeof(int), 1, arquivo);
    fread(acervoDeLivros, sizeof(Livro), totalDeLivros, arquivo);

    // Carrega os dados dos USUÁRIOS
    fread(&totalDeUsuarios, sizeof(int), 1, arquivo);
    fread(ficharioDeUsuarios, sizeof(usuario), totalDeUsuarios, arquivo);

    fclose(arquivo);
    printf("-> %d livros e %d usuarios carregados com sucesso!\n", totalDeLivros, totalDeUsuarios);
}

