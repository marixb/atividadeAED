#include <stdio.h>

int produto(int a, int b) {
    if (b == 0) return 0;                   // caso base
    if (b < 0) return -produto(a, -b);      // trata b negativo
    return a + produto(a, b - 1);           // a + a + ... (b vezes)
}

int main() {
    int a, b;
    printf("Digite a e b: ");
    scanf("%d %d", &a, &b);
    printf("%d x %d = %d\n", a, b, produto(a, b));
    return 0;
}