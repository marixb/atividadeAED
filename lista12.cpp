#include <stdio.h>

#define MAXP 100

typedef struct {
    int dados[MAXP];
    int topo;               // -1 indica pilha vazia
} Pilha;

void iniciar_pilha(Pilha *p) { p->topo = -1; }
int pilha_vazia(Pilha *p)        { return p->topo == -1; }
int pilha_cheia(Pilha *p)         { return p->topo == MAXP - 1; }

int push(Pilha *p, int v) {
    if (pilha_cheia(p)) {
        printf("Pilha cheia!\n");
        return 0;
    }
    p->dados[++p->topo] = v;
    return 1;
}

int pop(Pilha *p, int *v) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia!\n");
        return 0;
    }
    *v = p->dados[p->topo--];
    return 1;
}

int top(Pilha *p, int *v) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia!\n");
        return 0;
    }
    *v = p->dados[p->topo];
    return 1;
}

#define CAP 5       // capacidade pequena para facilitar o teste

typedef struct {
    int dados[CAP];
    int ini;        // índice do primeiro elemento
    int tam;        // quantidade de elementos
} FilaC;

void iniciar_fila(FilaC *f) { f->ini = 0; f->tam = 0; }
int fila_vazia(FilaC *f)       { return f->tam == 0; }
int fila_cheia(FilaC *f)        { return f->tam == CAP; }

int enqueue(FilaC *f, int v) {
    if (fila_cheia(f)) {
        printf("Fila cheia!\n");
        return 0;
    }
    f->dados[(f->ini + f->tam) % CAP] = v;   // posição circular
    f->tam++;
    return 1;
}

int dequeue(FilaC *f, int *v) {
    if (fila_vazia(f)) {
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

void inverter_fila(FilaC *f) {
    Pilha p;
    iniciar_pilha(&p);
    int v;

    while (!fila_vazia(f)) {        // fila -> pilha
        dequeue(f, &v);
        push(&p, v);
    }
    while (!pilha_vazia(&p)) {      // pilha -> fila (ordem invertida)
        pop(&p, &v);
        enqueue(f, v);
    }
}

int main() {
    FilaC f;
    iniciar_fila(&f);
    int n, v;

    printf("Quantos elementos (máx. %d)? ", CAP);
    scanf("%d", &n);
    for (int i = 0; i < n && i < CAP; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &v);
        enqueue(&f, v);
    }

    printf("Antes:  ");
    exibir(&f);
    inverter_fila(&f);
    printf("Depois: ");
    exibir(&f);
    return 0;
}