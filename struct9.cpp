#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[51];
    int idade;
    char diagnostico[101];
} Paciente;

void exibir_acima_60(Paciente pacientes[], int n) {
    int achou = 0;
    printf("\nPacientes acima de 60 anos:\n");
    for (int i = 0; i < n; i++) {
        if (pacientes[i].idade > 60) {
            printf("- %s, %d anos | Diagnóstico: %s\n",
                   pacientes[i].nome, pacientes[i].idade, pacientes[i].diagnostico);
            achou = 1;
        }
    }
    if (!achou) {
        printf("Nenhum paciente encontrado.\n");
    }
}

int main() {
    int n;
    printf("Quantos pacientes? ");
    scanf("%d", &n);

    Paciente *pacientes = (Paciente *) malloc(n * sizeof(Paciente));
    if (pacientes == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nPaciente %d\n", i + 1);
        printf("Nome: ");
        scanf(" %50[^\n]", pacientes[i].nome);
        printf("Idade: ");
        scanf("%d", &pacientes[i].idade);
        printf("Diagnóstico: ");
        scanf(" %100[^\n]", pacientes[i].diagnostico);
    }

    exibir_acima_60(pacientes, n);

    free(pacientes);
    return 0;
}