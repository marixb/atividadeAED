#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char titulo[51];
    char autor[51];
    int ano;
} Livro;

void exibir_apos_ano(Livro livros[], int n, int ano) {
    int achou = 0;
    printf("\nLivros publicados após %d:\n", ano);
    for (int i = 0; i < n; i++) {
        if (livros[i].ano > ano) {
            printf("- \"%s\", de %s (%d)\n", livros[i].titulo, livros[i].autor, livros[i].ano);
            achou = 1;
        }
    }
    if (!achou) {
        printf("Nenhum livro encontrado.\n");
    }
}

int main() {
    int n, ano;
    printf("Quantos livros? ");
    scanf("%d", &n);

    Livro *livros = (Livro *) malloc(n * sizeof(Livro));
    if (livros == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nLivro %d\n", i + 1);
        printf("Título: ");
        scanf(" %50[^\n]", livros[i].titulo);
        printf("Autor: ");
        scanf(" %50[^\n]", livros[i].autor);
        printf("Ano de publicação: ");
        scanf("%d", &livros[i].ano);
    }

    printf("\nExibir livros publicados após qual ano? ");
    scanf("%d", &ano);
    exibir_apos_ano(livros, n, ano);

    free(livros);
    return 0;
}