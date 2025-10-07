#include <stdio.h>
#include "usuario.h"

#define MAX_USUARIOS 100

Usuario ficharioDeUsuarios[MAX_USUARIOS];
int totalDeUsuarios = 0;


void adicionarUsuario(void) {
    if (totalDeUsuarios >= MAX_USUARIOS) {
        printf("Erro: Numero maximo de usuarios atingido\n");
        return;
    }
    Usuario novoUsuario;

    printf("\n--- Cadastro de Novo Livro ---\n");

    printf("Digite seu Nome: ");
    scanf(" %[^\n]", novoUsuario.nome);

    printf("Digite seu Email: ");
    scanf(" %[^\n]", novoUsuario.email);

    novoUsuario.id = totalDeUsuarios + 1;

    ficharioDeUsuarios[totalDeUsuarios] = novoUsuario;

    totalDeUsuarios++;
}

void listarUsuarios(void) {
    printf("\n--- Lista De Usuarios ---\n");

    if (totalDeUsuarios == 0) {
        printf("Nenhum Usuario cadastrado no momento.\n");
    } else {
        for (int i = 0; i < totalDeUsuarios; i++) {
            printf("ID: %d | Nome: %s | Email: %s\n",
                   ficharioDeUsuarios[i].id,
                   ficharioDeUsuarios[i].nome,
                   ficharioDeUsuarios[i].email);
        }
    }
}
Usuario* buscarUsuarioPorId(int id){

    for (int i = 0; i < totalDeUsuarios; i++) {

        if (ficharioDeUsuarios[i].id == id) {

            return &ficharioDeUsuarios[i];
        }
    }

    return NULL;
}