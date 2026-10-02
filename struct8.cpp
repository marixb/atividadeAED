#include <stdio.h>

typedef struct {
    float base;
    float altura;
} Retangulo;

float calcular_area(Retangulo r) {
    return r.base * r.altura;
}

float calcular_perimetro(Retangulo r) {
    return 2 * (r.base + r.altura);
}

int main() {
    Retangulo r;

    printf("Base: ");
    scanf("%f", &r.base);
    printf("Altura: ");
    scanf("%f", &r.altura);

    printf("Área: %.2f\n", calcular_area(r));
    printf("Perímetro: %.2f\n", calcular_perimetro(r));
    return 0;
}