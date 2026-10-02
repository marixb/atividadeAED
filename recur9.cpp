#include <stdio.h>

int soma_digitos_it(int n) {
    if (n < 0) n = -n;
    int soma = 0;
    while (n > 0) {
        soma += n % 10;     // pega o último dígito
        n /= 10;            // remove o último dígito
    }
    return soma;
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("Soma dos dígitos: %d\n", soma_digitos_it(n));
    return 0;
}