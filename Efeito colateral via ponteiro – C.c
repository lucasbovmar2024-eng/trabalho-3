// ex04/altitude.c
#include <stdio.h>

// Função pura: retorna nova altitude sem alterar estado original
int calcular_nova_altitude(int altitude_atual, int delta) {
    int nova = altitude_atual + delta;
    if (nova < 0) nova = 0;
    return nova;
}

// Procedimento com efeito colateral: modifica diretamente via ponteiro
void alterar_altitude(int *altitude, int delta) {
    int nova = *altitude + delta;
    if (nova < 0) nova = 0;
    *altitude = nova;
    printf("Altitude alterada via efeito colateral para %d\n", *altitude);
}

int main() {
    int altitude = 1000;  // estado local no main

    printf("Altitude inicial: %d\n", altitude);

    // Chamada segura (sem efeito colateral)
    int nova = calcular_nova_altitude(altitude, -300);
    printf("Calculo seguro: %d (altitude original continua %d)\n", nova, altitude);

    // Efeito colateral via ponteiro
    alterar_altitude(&altitude, -300);
    printf("Apos procedimento: altitude = %d\n", altitude);

    return 0;
}