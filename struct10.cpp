#include <stdio.h>

typedef struct {
    char titular[51];
    int numero;
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria *c, float valor) {
    if (valor <= 0) {
        printf("Valor inválido!\n");
        return;
    }
    c->saldo += valor;
    printf("Depósito realizado com sucesso!\n");
}

void sacar(ContaBancaria *c, float valor) {
    if (valor <= 0) {
        printf("Valor inválido!\n");
    } else if (valor > c->saldo) {
        printf("Saldo insuficiente!\n");
    } else {
        c->saldo -= valor;
        printf("Saque realizado com sucesso!\n");
    }
}

void exibir_saldo(ContaBancaria c) {
    printf("Titular: %s | Conta: %d | Saldo: R$ %.2f\n", c.titular, c.numero, c.saldo);
}

int main() {
    ContaBancaria conta;
    int opcao;
    float valor;

    printf("Titular: ");
    scanf(" %50[^\n]", conta.titular);
    printf("Número da conta: ");
    scanf("%d", &conta.numero);
    conta.saldo = 0;

    do {
        printf("\n1. Depositar\n2. Sacar\n3. Exibir saldo\n0. Sair\nOpção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Valor do depósito: ");
            scanf("%f", &valor);
            depositar(&conta, valor);
        } else if (opcao == 2) {
            printf("Valor do saque: ");
            scanf("%f", &valor);
            sacar(&conta, valor);
        } else if (opcao == 3) {
            exibir_saldo(conta);
        }
    } while (opcao != 0);

    return 0;
}