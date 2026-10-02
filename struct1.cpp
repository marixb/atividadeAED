#include <stdio.h>

typedef struct {
    char nome[51];
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa p;

    printf("Nome: ");
    scanf(" %50[^\n]", p.nome);
    printf("Idade: ");
    scanf("%d", &p.idade);
    printf("Altura: ");
    scanf("%f", &p.altura);

    printf("\n--- Dados da pessoa ---\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d anos\n", p.idade);
    printf("Altura: %.2f m\n", p.altura);
    return 0;
}