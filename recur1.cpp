#include <stdio.h>

int contar_digitos(int n) {
    if (n < 0) n = -n;               // trata números negativos
    if (n < 10) return 1;            // caso base: um único dígito
    return 1 + contar_digitos(n / 10);
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("Quantidade de dígitos: %d\n", contar_digitos(n));
    return 0;
}