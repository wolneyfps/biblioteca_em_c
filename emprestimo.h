#ifndef BIBLIOTECA_EM_C_EMPRESTIMO_H
#define BIBLIOTECA_EM_C_EMPRESTIMO_H
#include <time.h>

typedef struct {
    int id_livro;
    int id_usuario;
    time_t data_emprestimo;
} emprestimo;

void realizaremprestimo(void);

void devolverlivro(void);

void listaremprestimos(void);

#endif //BIBLIOTECA_EM_C_EMPRESTIMO_H
