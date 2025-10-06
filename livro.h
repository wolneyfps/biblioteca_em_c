#ifndef BIBLIOTECA_EM_C_LIVRO_H
#define BIBLIOTECA_EM_C_LIVRO_H

typedef struct {
    int id;
    char titulo[100];
    char autor[100];
    int anoPublicacao;
    int quantidade;
} Livro;

void adicionarLivro(void);

void listarLivros(void);
#endif //BIBLIOTECA_EM_C_LIVRO_H
