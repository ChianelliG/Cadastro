#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 1000
#define TAM_STRING 100

typedef struct {
    int id;
    char nome[TAM_STRING];
    char email[TAM_STRING];
    char sexo[TAM_STRING];
    char endereco[TAM_STRING];
    double altura;
    int vacina;
} Usuario;

int gerarId() {
    return rand() % 10000 + 1;
}

void adicionarUsuario(Usuario usuarios[], int *numUsuarios) {
    if (*numUsuarios < TAM) {
        Usuario novoUsuario;
        novoUsuario.id = gerarId();

        printf("Digite o nome comopleto: ");
        scanf(" %[^\n]", novoUsuario.nome);

        printf("Digite o email: ");
        scanf(" %s", novoUsuario.email);

        do {
            printf("Digite o sexo (Feminino, Masculino ou Indiferente): ");
            scanf(" %s", novoUsuario.sexo);
        } while (strcmp(novoUsuario.sexo, "Feminino") != 0 &&
                 strcmp(novoUsuario.sexo, "Masculino") != 0 &&
                 strcmp(novoUsuario.sexo, "Indiferente") != 0);

        printf("Digite o endereco: ");
        scanf(" %[^\n]", novoUsuario.endereco);

        do {
            printf("Digite a altura (entre 1 e 2 metros): ");
            scanf("%lf", &novoUsuario.altura);
        } while (novoUsuario.altura < 1.0 || novoUsuario.altura > 2.0);

        do {
            printf("Foi vacinado? (1 para sim, 0 para no): ");
            scanf("%d", &novoUsuario.vacina);
        } while (novoUsuario.vacina != 0 && novoUsuario.vacina != 1);

        usuarios[*numUsuarios] = novoUsuario;
        (*numUsuarios)++;
        printf("Usuario cadastrado com sucesso!\n");
    } else {
        printf("Limite de usuarios atingido.\n");
    }
}

void editarUsuario(Usuario usuarios[], int numUsuarios) {
    int id;
    printf("Digite o ID do usuario a ser editado: ");
    scanf("%d", &id);

    for (int i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == id) {
            printf("Digite o novo nome completo: ");
            scanf(" %[^\n]", usuarios[i].nome);

            printf("Digite o novo email: ");
            scanf(" %s", usuarios[i].email);

            do {
                printf("Digite o novo sexo (Feminino, Masculino ou Indiferente): ");
                scanf(" %s", usuarios[i].sexo);
            } while (strcmp(usuarios[i].sexo, "Feminino") != 0 &&
                     strcmp(usuarios[i].sexo, "Masculino") != 0 &&
                     strcmp(usuarios[i].sexo, "Indiferente") != 0);

            printf("Digite o novo endereco: ");
            scanf(" %[^\n]", usuarios[i].endereco);

            do {
                printf("Digite a nova altura (entre 1 e 2 metros): ");
                scanf("%lf", &usuarios[i].altura);
            } while (usuarios[i].altura < 1.0 || usuarios[i].altura > 2.0);

            do {
                printf("Foi vacinado? (1 para sim, 0 para nao): ");
                scanf("%d", &usuarios[i].vacina);
            } while (usuarios[i].vacina != 0 && usuarios[i].vacina != 1);

            printf("Usuario editado com sucesso!\n");
            return;
        }
    }

    printf("Usuario nao cadastrado.\n");
}

void excluirUsuario(Usuario usuarios[], int *numUsuarios) {
    int id;
    printf("Digite o ID do usuario a ser excluido: ");
    scanf("%d", &id);

    for (int i = 0; i < *numUsuarios; i++) {
        if (usuarios[i].id == id) {
            for (int j = i; j < *numUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            (*numUsuarios)--;
            printf("Usuario excluido com sucesso!\n");
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void buscarUsuarioPorEmail(Usuario usuarios[], int numUsuarios) {
    char email[TAM_STRING];
    printf("Digite o email do usuario a ser buscado: ");
    scanf(" %s", email);

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereco: %s\n", usuarios[i].endereco);
            printf("Altura: %.2f\n", usuarios[i].altura);
            printf("Vacina: %d\n", usuarios[i].vacina);
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void imprimirUsuarios(Usuario usuarios[], int numUsuarios) {
    for (int i = 0; i < numUsuarios; i++) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereco: %s\n", usuarios[i].endereco);
        printf("Altura: %.2f\n", usuarios[i].altura);
        printf("Vacina: %d\n", usuarios[i].vacina);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Usuario usuarios[TAM];
    int numUsuarios = 0;
    char opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Adicionar usuario\n");
        printf("2. Editar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario por email\n");
        printf("5. Imprimir todos usuarios\n");
        printf("0. Terminar\n");

        printf("Escolha a opcao desejada: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarUsuario(usuarios, &numUsuarios);
                break;
            case '2':
                editarUsuario(usuarios, numUsuarios);
                break;
            case '3':
                excluirUsuario(usuarios, &numUsuarios);
                break;
            case '4':
                buscarUsuarioPorEmail(usuarios, numUsuarios);
                break;
            case '5':
                imprimirUsuarios(usuarios, numUsuarios);
                break;
            case '0':
                printf("Terminando...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != '0');

    return 0;
}
