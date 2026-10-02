#include <stdio.h>

#define CAP 5       // capacidade pequena para facilitar o teste

typedef struct {
    int dados[CAP];
    int ini;        // índice do primeiro elemento
    int tam;        // quantidade de elementos
} FilaC;

void iniciar_fila(FilaC *f) { f->ini = 0; f->tam = 0; }
int isEmpty(FilaC *f)       { return f->tam == 0; }
int isFull(FilaC *f)        { return f->tam == CAP; }

int enqueue(FilaC *f, int v) {
    if (isFull(f)) {
        printf("Fila cheia!\n");
        return 0;
    }
    f->dados[(f->ini + f->tam) % CAP] = v;   // posição circular
    f->tam++;
    return 1;
}

int dequeue(FilaC *f, int *v) {
    if (isEmpty(f)) {
        printf("Fila vazia!\n");
        return 0;
    }
    *v = f->dados[f->ini];
    f->ini = (f->ini + 1) % CAP;             // avança circularmente
    f->tam--;
    return 1;
}

void exibir(FilaC *f) {
    printf("Fila: ");
    for (int i = 0; i < f->tam; i++) {
        printf("%d ", f->dados[(f->ini + i) % CAP]);
    }
    printf("\n");
}

int main() {
    FilaC f;
    iniciar_fila(&f);
    int opcao, v;

    do {
        printf("\n--- FILA CIRCULAR (capacidade %d) ---\n", CAP);
        printf("1. enqueue\n2. dequeue\n3. Exibir fila\n0. Sair\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor: ");
                scanf("%d", &v);
                enqueue(&f, v);
                break;
            case 2:
                if (dequeue(&f, &v)) printf("Removido: %d\n", v);
                break;
            case 3:
                exibir(&f);
                break;
        }
    } while (opcao != 0);

    return 0;
}