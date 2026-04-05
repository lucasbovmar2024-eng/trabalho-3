// ex02/escopo_saldo.c
#include <stdio.h>

// Passagem por valor (IN mode) – recebe cópia
void tentar_alterar_saldo(int saldo) {
    saldo = saldo + 100;
    printf("Dentro da funcao (por valor): saldo = %d\n", saldo);
}

// Passagem por referência (INOUT mode via ponteiro)
void alterar_saldo_real(int *saldo) {
    *saldo = *saldo + 100;
    printf("Dentro da funcao (por referencia): saldo = %d\n", *saldo);
}

int main() {
    int saldo_bancario = 500;

    printf("Saldo inicial: %d\n", saldo_bancario);

    tentar_alterar_saldo(saldo_bancario);
    printf("Depois da tentativa por valor: %d\n", saldo_bancario); // continua 500

    alterar_saldo_real(&saldo_bancario);
    printf("Depois da alteracao por referencia: %d\n", saldo_bancario); // agora 600

    // Análise:
    // Na passagem por valor, o parâmetro formal 'saldo' recebe uma cópia do valor
    // da variável original. Modificações afetam apenas a cópia local, que é destruída
    // ao final da função. Já a passagem por referência envia o endereço de memória;
    // o ponteiro permite acessar e modificar diretamente a variável original.
    return 0;
}