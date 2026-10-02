#include <stdio.h>

int maior_elemento_it(int vet[], int n) {
    int maior = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }
    return maior;
}

int main() {
    int vet[100], n;
    printf("Tamanho do vetor (máx. 100): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    printf("Maior elemento: %d\n", maior_elemento_it(vet, n));
    return 0;
}