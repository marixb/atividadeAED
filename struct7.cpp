#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[51];
    char telefone[16];
} Contato;

void adicionar(Contato agenda[], int *total) {
    if (*total >= MAX) {
        printf("Agenda cheia!\n");
        return;
    }
    printf("Nome: ");
    scanf(" %50[^\n]", agenda[*total].nome);
    printf("Telefone: ");
    scanf(" %15[^\n]", agenda[*total].telefone);
    (*total)++;
    printf("Contato adicionado!\n");
}

void buscar(Contato agenda[], int total) {
    char busca[51];
    int achou = 0;
    printf("Nome a buscar: ");
    scanf(" %50[^\n]", busca);

    for (int i = 0; i < total; i++) {
        if (strcmp(agenda[i].nome, busca) == 0) {
            printf("Encontrado: %s - %s\n", agenda[i].nome, agenda[i].telefone);
            achou = 1;
        }
    }
    if (!achou) {
        printf("Contato não encontrado.\n");
    }
}

int main() {
    Contato agenda[MAX];
    int total = 0, opcao;

    do {
        printf("\n--- AGENDA ---\n");
        printf("1. Adicionar contato\n");
        printf("2. Buscar contato pelo nome\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) adicionar(agenda, &total);
        else if (opcao == 2) buscar(agenda, total);
    } while (opcao != 0);

    return 0;
}