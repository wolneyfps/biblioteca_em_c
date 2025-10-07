#ifndef BIBLIOTECA_EM_C_USUARIO_H
#define BIBLIOTECA_EM_C_USUARIO_H

typedef struct {
    int id;
    char nome[20];
    char email[50];
} Usuario;

void adicionarUsuario(void);
void listarUsuarios(void);
Usuario* buscarUsuarioPorId(int id);
#endif //BIBLIOTECA_EM_C_USUARIO_H
