#include <stdio.h>

#define MAX 100

typedef struct {
    char nomes[MAX][51];
    int ini;        // primeiro da fila
    int tam;        // quantidade de clientes
} FilaBanco;

int main() {
    FilaBanco f;
    f.ini = 0;
    f.tam = 0;
    int opcao;

    do {
        printf("\n--- ATENDIMENTO BANCÁRIO ---\n");
        printf("1. Cliente chega\n");
        printf("2. Atender próximo cliente\n");
        printf("3. Ver fila de espera\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (f.tam == MAX) {
                printf("Fila cheia!\n");
            } else {
                int pos = (f.ini + f.tam) % MAX;
                printf("Nome do cliente: ");
                scanf(" %50[^\n]", f.nomes[pos]);
                f.tam++;
                printf("%s entrou na fila (posição %d).\n", f.nomes[pos], f.tam);
            }
        } else if (opcao == 2) {
            if (f.tam == 0) {
                printf("Nenhum cliente na fila.\n");
            } else {
                printf("Atendendo: %s\n", f.nomes[f.ini]);
                f.ini = (f.ini + 1) % MAX;
                f.tam--;
            }
        } else if (opcao == 3) {
            if (f.tam == 0) printf("Fila vazia.\n");
            for (int i = 0; i < f.tam; i++) {
                printf("%d. %s\n", i + 1, f.nomes[(f.ini + i) % MAX]);
            }
        }
    } while (opcao != 0);

    return 0;
}