#include <stdio.h>
#include <string.h>

int verifica(char *s, int ini, int fim) {
    if (ini >= fim) return 1;                   // chegou ao meio: é palíndromo
    if (s[ini] != s[fim]) return 0;             // letras diferentes
    return verifica(s, ini + 1, fim - 1);
}

int palindromo(char *s) {
    return verifica(s, 0, (int) strlen(s) - 1);
}

int main() {
    char s[100];
    printf("Digite uma palavra: ");
    scanf("%99s", s);
    printf("palindromo(\"%s\") = %d\n", s, palindromo(s));
    return 0;
}