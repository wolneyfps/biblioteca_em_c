#ifndef BIBLIOTECA_EM_C_USUARIO_H
#define BIBLIOTECA_EM_C_USUARIO_H

typedef struct {
    int id;
    char nome[20];
    char email[50];
} usuario;

void adicionarusuario(void);

void listarusuarios(void);
#endif //BIBLIOTECA_EM_C_USUARIO_H
