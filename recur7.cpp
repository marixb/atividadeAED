#include <stdio.h>

void contagem_regressiva_it(int n) {
    for (int i = n; i >= 0; i--) {
        printf("%d", i);
        if (i > 0) printf(", ");
    }
}

int main() {
    int n;
    printf("Digite n: ");
    scanf("%d", &n);
    contagem_regressiva_it(n);
    printf("\n");
    return 0;
}