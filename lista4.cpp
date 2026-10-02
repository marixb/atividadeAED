#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

No *novo_no(int v) {
    No *n = (No *) malloc(sizeof(No));
    n->valor = v;
    n->prox = NULL;
    return n;
}

No *inserir_inicio(No *lista, int v) {
    No *n = novo_no(v);
    n->prox = lista;
    return n;
}

No *inserir_final(No *lista, int v) {
    No *n = novo_no(v);
    if (lista == NULL) return n;
    No *p = lista;
    while (p->prox != NULL) p = p->prox;
    p->prox = n;
    return lista;
}

void exibir(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    for (No *p = lista; p != NULL; p = p->prox) {
        printf("%d -> ", p->valor);
    }
    printf("NULL\n");
}

No *reverter(No *lista) {
    No *ant = NULL, *prox;
    while (lista != NULL) {
        prox = lista->prox;     // guarda o próximo
        lista->prox = ant;      // inverte o ponteiro
        ant = lista;
        lista = prox;
    }
    return ant;                 // novo início da lista
}

void liberar(No *lista) {
    while (lista != NULL) {
        No *t = lista;
        lista = lista->prox;
        free(t);
    }
}

int main() {
    No *lista = NULL;
    int opcao, v;

    do {
        printf("\n--- LISTA ENCADEADA ---\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Exibir lista\n");
        printf("4. Reverter lista\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: printf("Valor: "); scanf("%d", &v); lista = inserir_inicio(lista, v); break;
            case 2: printf("Valor: "); scanf("%d", &v); lista = inserir_final(lista, v); break;
            case 3: exibir(lista); break;
            case 4: lista = reverter(lista); printf("Lista revertida!\n"); break;
        }
    } while (opcao != 0);

    liberar(lista);
    return 0;
}