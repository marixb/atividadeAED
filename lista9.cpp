#include <stdio.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int ini;        // posição do primeiro elemento
    int fim;        // próxima posição livre
} Fila;

void iniciar_fila(Fila *f) { f->ini = f->fim = 0; }
int isEmpty(Fila *f)       { return f->ini == f->fim; }
int isFull(Fila *f)        { return f->fim == MAX; }

int enqueue(Fila *f, int v) {
    if (isFull(f)) {
        printf("Fila cheia!\n");
        return 0;
    }
    f->dados[f->fim++] = v;
    return 1;
}

int dequeue(Fila *f, int *v) {
    if (isEmpty(f)) {
        printf("Fila vazia!\n");
        return 0;
    }
    *v = f->dados[f->ini++];
    return 1;
}

int front(Fila *f, int *v) {
    if (isEmpty(f)) {
        printf("Fila vazia!\n");
        return 0;
    }
    *v = f->dados[f->ini];
    return 1;
}

int main() {
    Fila f;
    iniciar_fila(&f);
    int opcao, v;

    do {
        printf("\n--- FILA (VETOR) ---\n");
        printf("1. enqueue\n2. dequeue\n3. front\n4. isEmpty\n0. Sair\nOpção: ");
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
                if (front(&f, &v)) printf("Primeiro: %d\n", v);
                break;
            case 4:
                printf(isEmpty(&f) ? "A fila está vazia.\n" : "A fila NÃO está vazia.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}