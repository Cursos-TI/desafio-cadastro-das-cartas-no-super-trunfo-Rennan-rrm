#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TOTAL_CARTAS 3

typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

void mostrarCarta(Carta c) {
    printf("Nome: %s\n", c.nome);
    printf("Força: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligência: %d\n", c.inteligencia);
}

int main() {
    srand(time(NULL));

    Carta cartas[TOTAL_CARTAS] = {
        {"Dragão Flamejante", 90, 60, 40},
        {"Cavaleiro Negro", 70, 80, 60},
        {"Mago Ancião", 50, 40, 95}
    };

    // Sorteia carta do jogador e do computador
    int jogadorIndex = rand() % TOTAL_CARTAS;
    int pcIndex;
    do {
        pcIndex = rand() % TOTAL_CARTAS;
    } while (pcIndex == jogadorIndex); // evita pegar a mesma carta

    Carta jogador = cartas[jogadorIndex];
    Carta computador = cartas[pcIndex];

    printf("=== SUA CARTA ===\n");
    mostrarCarta(jogador);

    // Jogador escolhe atributo
    int escolha;
    printf("\nEscolha um atributo para batalhar:\n");
    printf("1 - Força\n");
    printf("2 - Velocidade\n");
    printf("3 - Inteligência\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    int valorJogador = 0, valorPC = 0;
    switch (escolha) {
        case 1:
            valorJogador = jogador.forca;
            valorPC = computador.forca;
            break;
        case 2:
            valorJogador = jogador.velocidade;
            valorPC = computador.velocidade;
            break;
        case 3:
            valorJogador = jogador.inteligencia;
            valorPC = computador.inteligencia;
            break;
        default:
            printf("Escolha inválida!\n");
            return 1;
    }

    printf("\n=== CARTA DO COMPUTADOR ===\n");
    mostrarCarta(computador);

    printf("\nSeu valor: %d x %d :Computador\n", valorJogador, valorPC);

    if (valorJogador > valorPC) {
        printf("🎉 Você venceu!\n");
    } else if (valorJogador < valorPC) {
        printf("💀 Você perdeu!\n");
    } else {
        printf("🤝 Empate!\n");
    }

    return 0;
}
