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

int balanceada(char *expr) {
    Pilha p;
    iniciar_pilha(&p);
    int v;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            push(&p, '(');
        } else if (expr[i] == ')') {
            if (isEmpty(&p)) return 0;      // ")" sem "(" correspondente
            pop(&p, &v);
        }
    }
    return isEmpty(&p);                     // sobrou "(" => inválido
}

int main() {
    char expr[100];
    printf("Digite a expressão (apenas ( e )): ");
    scanf("%99s", expr);

    printf("%s\n", balanceada(expr) ? "Válido" : "Inválido");
    return 0;
}