#include <stdio.h>

void contagem_regressiva(int n) {
    if (n < 0) return;                  // caso base
    printf("%d", n);
    if (n > 0) {
        printf(", ");
        contagem_regressiva(n - 1);
    }
}

int main() {
    int n;
    printf("Digite n: ");
    scanf("%d", &n);
    contagem_regressiva(n);
    printf("\n");
    return 0;
}