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
    char s[100];
    Pilha p;
    iniciar_pilha(&p);
    int c;

    printf("Digite uma string: ");
    scanf(" %99[^\n]", s);

    for (int i = 0; s[i] != '\0'; i++) {
        push(&p, s[i]);
    }

    printf("String invertida: ");
    while (!isEmpty(&p)) {
        pop(&p, &c);
        putchar(c);
    }
    printf("\n");
    return 0;
}