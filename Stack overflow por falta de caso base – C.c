// ex07/contagem_regressiva.c
#include <stdio.h>

// Versão errada (sem caso base) - NÃO EXECUTAR EM PRODUÇÃO!
// void regressao_infinita(int n) {
//     printf("%d\n", n);
//     regressao_infinita(n - 1);  // nunca para -> stack overflow
// }

// Versão correta com caso base
void contagem_regressiva(int n) {
    if (n < 0) {   // CASO BASE: condição de parada
        return;
    }
    printf("%d ", n);
    contagem_regressiva(n - 1);  // PASSO RECURSIVO
}

int main() {
    printf("Contagem correta: ");
    contagem_regressiva(5);
    printf("\n");

    // Descomente abaixo para ver o crash (cuidado, pode travar o terminal)
    // printf("Tentando recursao infinita...\n");
    // regressao_infinita(5);

    // Análise:
    // Sem o caso base, a função chama a si mesma infinitamente. Cada chamada
    // aloca um novo stack frame (endereço de retorno, parâmetros, variáveis locais).
    // A pilha de execução cresce até esgotar a memória reservada, causando
    // Segmentation Fault (estouro de pilha). O sistema operacional mata o processo.
    return 0;
}