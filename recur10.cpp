#include <stdio.h>

int produto_it(int a, int b) {
    int negativo = 0, resultado = 0;
    if (b < 0) {
        b = -b;
        negativo = 1;
    }
    for (int i = 0; i < b; i++) {
        resultado += a;
    }
    return negativo ? -resultado : resultado;
}

int main() {
    int a, b;
    printf("Digite a e b: ");
    scanf("%d %d", &a, &b);
    printf("%d x %d = %d\n", a, b, produto_it(a, b));
    return 0;
}