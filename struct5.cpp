#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[51];
    char cargo[31];
    float salario;
} Funcionario;

int main() {
    int n;
    printf("Quantos funcionários? ");
    scanf("%d", &n);

    Funcionario *func = (Funcionario *) malloc(n * sizeof(Funcionario));
    if (func == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nFuncionário %d\n", i + 1);
        printf("Nome: ");
        scanf(" %50[^\n]", func[i].nome);
        printf("Cargo: ");
        scanf(" %30[^\n]", func[i].cargo);
        printf("Salário: ");
        scanf("%f", &func[i].salario);
    }

    printf("\n--- Funcionários cadastrados ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s | %s | R$ %.2f\n", i + 1, func[i].nome, func[i].cargo, func[i].salario);
    }

    free(func);
    return 0;
}