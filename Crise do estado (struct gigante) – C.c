// ex10/hospital.c
/*
 * ANÁLISE EXIGIDA – Por que separar dados e funções se torna insustentável:
 * 
 * Neste exercício, temos uma struct SistemaHospitalar que agrupa vários arrays
 * (pacientes, médicos, leitos, caixa). Para cada operação como 'realizar_internacao',
 * precisamos passar essa struct por ponteiro (para evitar cópia pesada) e garantir
 * que todos os campos relacionados sejam atualizados consistentemente.
 * 
 * Conforme o sistema cresce (adicionar, remover, transferir, dar alta, pagar contas),
 * cada função precisa conhecer a estrutura interna e manipular ponteiros com cuidado.
 * Isso gata:
 *   - Alto acoplamento: qualquer mudança na struct quebra dezenas de funções.
 *   - Dificuldade de rastrear quem modificou o quê (efeitos colaterais espalhados).
 *   - Risco de corrupção de estado (ex: atualiza leitos mas esquece de atualizar caixa).
 * 
 * O encapsulamento da Orientação a Objetos resolve isso: dados e comportamentos
 * ficam juntos em classes, com acesso controlado (private/protected), garantindo
 * invariantes e reduzindo o impacto de mudanças.
 */

#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 100
#define MAX_MEDICOS 20

typedef struct {
    char nome[50];
    int internado;   // 1 = sim, 0 = não
} Paciente;

typedef struct {
    char nome[50];
    int especialidade;
} Medico;

typedef struct {
    Paciente pacientes[MAX_PACIENTES];
    int num_pacientes;
    Medico medicos[MAX_MEDICOS];
    int num_medicos;
    int leitos_disponiveis;
    float caixa;
} SistemaHospitalar;

// Procedimento que precisa receber a estrutura gigante e atualizá-la
void realizar_internacao(SistemaHospitalar *sistema, int id_paciente, int id_medico) {
    if (sistema->leitos_disponiveis <= 0) {
        printf("Sem leitos!\n");
        return;
    }
    if (sistema->pacientes[id_paciente].internado) {
        printf("Paciente já internado.\n");
        return;
    }
    // Atualiza múltiplos campos de estado
    sistema->pacientes[id_paciente].internado = 1;
    sistema->leitos_disponiveis--;
    sistema->caixa -= 500.0;  // custo de internação
    printf("Paciente %s internado com Dr(a). %s. Leitos restantes: %d, Caixa: %.2f\n",
           sistema->pacientes[id_paciente].nome,
           sistema->medicos[id_medico].nome,
           sistema->leitos_disponiveis,
           sistema->caixa);
}

int main() {
    SistemaHospitalar hospital = { .num_pacientes = 2, .num_medicos = 2,
                                   .leitos_disponiveis = 10, .caixa = 10000 };
    strcpy(hospital.pacientes[0].nome, "João");
    hospital.pacientes[0].internado = 0;
    strcpy(hospital.pacientes[1].nome, "Maria");
    hospital.pacientes[1].internado = 0;
    strcpy(hospital.medicos[0].nome, "Dr. House");
    strcpy(hospital.medicos[1].nome, "Dra. Grey");

    realizar_internacao(&hospital, 0, 0);
    realizar_internacao(&hospital, 1, 1);

    // Observe quantos ponteiros e cuidado são necessários. Se houvesse 20 funções
    // diferentes (alta, pagamento, transferência), todas precisariam manipular
    // a struct diretamente – o que é frágil e propenso a erros.
    return 0;
}