#include <stdio.h>
#include <string.h>

#define NUM_PERGUNTAS 5

typedef struct {
    char pergunta[256];
    char alternativas[4][256];
    int resposta_correta; // índice da resposta correta (0 a 3)
} Pergunta;

void jogar(Pergunta perguntas[], int num_perguntas) {
    int acertos = 0;
    int resposta_usuario;

    for (int i = 0; i < num_perguntas; i++) {
        printf("Pergunta %d: %s\n", i + 1, perguntas[i].pergunta);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, perguntas[i].alternativas[j]);
        }
        printf("Escolha a resposta (1-4): ");
        scanf("%d", &resposta_usuario);
        resposta_usuario--; // Ajusta para índice 0

        if (resposta_usuario == perguntas[i].resposta_correta) {
            printf("Correto!\n\n");
            acertos++;
        } else {
            printf("Incorreto! A resposta correta é: %s\n\n", perguntas[i].alternativas[perguntas[i].resposta_correta]);
        }
    }

    printf("Você acertou %d de %d perguntas.\n", acertos, num_perguntas);
}

int main() {
    Pergunta perguntas[NUM_PERGUNTAS] = {
        {"Qual é a capital da França?", {"Paris", "Londres", "Berlim", "Madri"}, 0},
        {"Qual é 2 + 2?", {"3", "4", "5", "6"}, 1},
        {"Qual é a cor do céu em um dia claro?", {"azul", "verde", "vermelho", "amarelo"}, 0},
        {"Qual é o maior planeta do sistema solar?", {"Terra", "Marte", "Júpiter", "Saturno"}, 2},
        {"Qual é a fórmula da água?", {"H2O", "CO2", "O2", "N2"}, 0}
    };

    char jogar_novamente;

    do {
        printf("Bem-vindo ao jogo de perguntas e respostas!\n");
        jogar(perguntas, NUM_PERGUNTAS);
        
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogar_novamente); // O espaço antes de %c ignora qualquer espaço em branco

    } while (jogar_novamente == 's' || jogar_novamente == 'S');

    printf("Obrigado por jogar!\n");
    return 0;
}