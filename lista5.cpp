#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;               // -1 indica pilha vazia
} Pilha;

void iniciar_pilha(Pilha *p) { p->topo = -1; }
int isEmpty(Pilha *p)        { return p->topo == -1; }
int isFull(Pilha *p)         { return p->topo == MAX - 1; }

int push(Pilha *p, int v) {
    if (isFull(p)) {
        printf("Pilha cheia!\n");
        return 0;
    }
    p->dados[++p->topo] = v;
    return 1;
}

int pop(Pilha *p, int *v) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return 0;
    }
    *v = p->dados[p->topo--];
    return 1;
}

int top(Pilha *p, int *v) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return 0;
    }
    *v = p->dados[p->topo];
    return 1;
}

int main() {
    Pilha p;
    iniciar_pilha(&p);
    int opcao, v;

    do {
        printf("\n--- PILHA (VETOR) ---\n");
        printf("1. push\n2. pop\n3. top\n4. isEmpty\n0. Sair\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor: ");
                scanf("%d", &v);
                push(&p, v);
                break;
            case 2:
                if (pop(&p, &v)) printf("Removido: %d\n", v);
                break;
            case 3:
                if (top(&p, &v)) printf("Topo: %d\n", v);
                break;
            case 4:
                printf(isEmpty(&p) ? "A pilha está vazia.\n" : "A pilha NÃO está vazia.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}