#include <stdio.h>

typedef struct {
    char nome[31];
    int codigo;
    float preco;
} Produto;

void exibir_produto(Produto p) {
    printf("\n--- Produto ---\n");
    printf("Nome:   %s\n", p.nome);
    printf("Código: %d\n", p.codigo);
    printf("Preço:  R$ %.2f\n", p.preco);
}

int main() {
    Produto p;

    printf("Nome do produto: ");
    scanf(" %30[^\n]", p.nome);
    printf("Código: ");
    scanf("%d", &p.codigo);
    printf("Preço: ");
    scanf("%f", &p.preco);

    exibir_produto(p);
    return 0;
}