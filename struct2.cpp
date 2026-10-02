#include <stdio.h>

typedef struct {
    char nome[51];
    int matricula;
    float nota;
} Aluno;

int main() {
    Aluno alunos[5];
    float soma = 0;

    for (int i = 0; i < 5; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Nome: ");
        scanf(" %50[^\n]", alunos[i].nome);
        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        soma += alunos[i].nota;
    }

    printf("\nMédia das notas: %.2f\n", soma / 5);
    return 0;
}