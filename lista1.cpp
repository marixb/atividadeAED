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

No *remover(No *lista, int v) {
    No *ant = NULL, *p = lista;
    while (p != NULL && p->valor != v) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) {
        printf("Valor %d não encontrado.\n", v);
        return lista;
    }
    if (ant == NULL) lista = p->prox;   // removendo o primeiro
    else ant->prox = p->prox;
    free(p);
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
        printf("3. Remover elemento\n");
        printf("4. Exibir lista\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: printf("Valor: "); scanf("%d", &v); lista = inserir_inicio(lista, v); break;
            case 2: printf("Valor: "); scanf("%d", &v); lista = inserir_final(lista, v); break;
            case 3: printf("Valor a remover: "); scanf("%d", &v); lista = remover(lista, v); break;
            case 4: exibir(lista); break;
        }
    } while (opcao != 0);

    liberar(lista);
    return 0;
}