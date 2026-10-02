#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char modelo[31];
    int ano;
    float preco;
} Carro;

int main() {
    Carro *c = (Carro *) malloc(sizeof(Carro));
    if (c == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Modelo: ");
    scanf(" %30[^\n]", c->modelo);
    printf("Ano: ");
    scanf("%d", &c->ano);
    printf("Preço: ");
    scanf("%f", &c->preco);

    printf("\n--- Carro ---\n");
    printf("Modelo: %s\n", c->modelo);
    printf("Ano: %d\n", c->ano);
    printf("Preço: R$ %.2f\n", c->preco);

    free(c);
    return 0;
}