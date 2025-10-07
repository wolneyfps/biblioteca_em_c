#include <stdio.h>
#include "usuario.h"

#define MAX_USUARIOS 100

usuario ficharioDeUsuarios[MAX_USUARIOS];
int totalDeUsuarios = 0;


void adicionarusuario(void) {
    if (totalDeUsuarios >= MAX_USUARIOS) {
        printf("Erro: Numero maximo de usuarios atingido\n");
        return;
    }
    usuario novoUsuario;

    printf("\n--- Cadastro de Novo Livro ---\n");

    printf("Digite seu Nome: ");
    scanf(" %[^\n]", novoUsuario.nome);

    printf("Digite seu Email: ");
    scanf(" %[^\n]", novoUsuario.email);

    novoUsuario.id = totalDeUsuarios + 1;

    ficharioDeUsuarios[totalDeUsuarios] = novoUsuario;

    totalDeUsuarios++;
}

void listarusuarios(void) {
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
