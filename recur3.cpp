#include <stdio.h>

int soma_digitos(int n) {
    if (n < 0) n = -n;
    if (n == 0) return 0;                       // caso base
    return (n % 10) + soma_digitos(n / 10);     // último dígito + soma do resto
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("Soma dos dígitos: %d\n", soma_digitos(n));
    return 0;
}