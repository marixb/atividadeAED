#include <stdio.h>

int maior_elemento(int vet[], int n) {
    if (n == 1) return vet[0];                      // caso base
    int maior_resto = maior_elemento(vet, n - 1);   // maior dos n-1 primeiros
    return (vet[n - 1] > maior_resto) ? vet[n - 1] : maior_resto;
}

int main() {
    int vet[100], n;
    printf("Tamanho do vetor (máx. 100): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    printf("Maior elemento: %d\n", maior_elemento(vet, n));
    return 0;
}