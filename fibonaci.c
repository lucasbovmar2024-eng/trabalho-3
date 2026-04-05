// ex01/fibonacci.c
#include <stdio.h>
#include <time.h>

// Versão recursiva ingênua – complexidade O(2^n)
long long fib_recursivo(int n) {
    if (n <= 1) return n;
    return fib_recursivo(n - 1) + fib_recursivo(n - 2);
}

// Versão iterativa – complexidade O(n)
long long fib_iterativo(int n) {
    long long a = 0, b = 1, c;
    if (n == 0) return a;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 40;
    clock_t start, end;

    // Iterativo
    start = clock();
    long long res_iter = fib_iterativo(n);
    end = clock();
    double tempo_iter = (double)(end - start) / CLOCKS_PER_SEC;

    // Recursivo (pode demorar muito – cuidado)
    start = clock();
    long long res_rec = fib_recursivo(n);
    end = clock();
    double tempo_rec = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Fibonacci(%d) = %lld\n", n, res_iter);
    printf("Iterativo: %.6f segundos\n", tempo_iter);
    printf("Recursivo: %.6f segundos\n", tempo_rec);

    // Análise exigida:
    // A versão recursiva ingênua recalcula os mesmos subproblemas milhares de vezes.
    // Cada chamada cria um novo stack frame na pilha. Para n=40, são ~2^40 chamadas.
    // Isso gera complexidade exponencial O(2^n) e pode causar estouro de pilha.
    // Já o iterativo mantém apenas 3 variáveis, O(n) tempo e O(1) espaço.
    return 0;
}