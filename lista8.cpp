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
    int n, bit;

    printf("Número decimal: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Digite um número não negativo.\n");
        return 1;
    }
    if (n == 0) push(&p, 0);

    while (n > 0) {
        push(&p, n % 2);    // empilha o resto da divisão
        n /= 2;
    }

    printf("Binário: ");
    while (!isEmpty(&p)) {   // desempilha: ordem inversa dos restos
        pop(&p, &bit);
        printf("%d", bit);
    }
    printf("\n");
    return 0;
}