#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos das funções
void menuPrincipal();
void jogo_perguntas_respostas();
void jogoCobraCaixa();
void jogoGousmasWar();

int main() {
    srand(time(NULL)); // Inicializa a semente para números aleatórios
    menuPrincipal();
    return 0;
}

void menuPrincipal() {
    int escolha;
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Pergunta e Resposta\n");
        printf("2. Cobra na Caixa!\n");
        printf("3. Gousmas War\n");
        printf("4. Sair\n");
        printf("Escolha um jogo: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                jogo_perguntas_respostas();
                break;
            case 2:
                jogoCobraCaixa();
                break;
            case 3:
                jogoGousmasWar();
                break;
            case 4:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida! Escolha um número entre 1 e 4.\n");
        }
    } while (escolha != 4);
}

// Função do jogo de perguntas e respostas
void jogo_perguntas_respostas() {
    char resposta;
    int pontos = 0;

    struct Pergunta {
        char *pergunta;
        char *alternativas[4];
        char resposta_correta;
    };

    struct Pergunta perguntas[5] = {
        {
            "Qual é a linguagem de programação mais popular para desenvolvimento web?",
            {"A) Python", "B) JavaScript", "C) C++", "D) Ruby"},
            'B'
        },
        {
            "O que é SQL?",
            {"A) Uma linguagem de programação", "B) Um sistema operacional", "C) Uma linguagem de consulta", "D) Um tipo de banco de dados"},
            'C'
        },
        {
            "Qual dos seguintes é um sistema operacional?",
            {"A) HTML", "B) CSS", "C) Linux", "D) Java"},
            'C'
        },
        {
            "O que significa a sigla 'HTTP'?",
            {"A) HyperText Transfer Protocol", "B) HighText Transfer Protocol", "C) HyperText Transmission Protocol", "D) Hyper Transfer Text Protocol"},
            'A'
        },
        {
            "Qual é a principal função de um firewall?",
            {"A) Aumentar a velocidade da internet", "B) Proteger a rede de acessos não autorizados", "C) Acelerar o processamento de dados", "D) Monitorar o uso de memória"},
            'B'
        }
    };

    for (int i = 0; i < 5; i++) {
        printf("\n%s\n", perguntas[i].pergunta);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", perguntas[i].alternativas[j]);
        }
        
        printf("Escolha a alternativa (A/B/C/D): ");
        scanf(" %c", &resposta);
        
        if (resposta == perguntas[i].resposta_correta) {
            printf("Resposta Correta!\n");
            pontos++;
        } else {
            printf("Resposta Incorreta! A resposta correta é %c\n", perguntas[i].resposta_correta);
        }
    }

    printf("\nVocê acertou %d de 5 perguntas.\n", pontos);

    char jogar_novamente;
    printf("Deseja jogar novamente? (s/n): ");
    scanf(" %c", &jogar_novamente);
    if (jogar_novamente == 's' || jogar_novamente == 'S') {
        jogo_perguntas_respostas();
    }
}

// Jogo "Cobra na Caixa!"
void jogoCobraCaixa() {
    char nomes[2][20] = {"Jogador 1", "Jogador 2"};
    int jogadorAtual, caixaEscolhida;
    int botao, cobra;
    char jogarNovamente;

    do {
        jogadorAtual = rand() % 2;
        botao = rand() % 5;
        cobra = rand() % 5;

        while (cobra == botao) {
            cobra = rand() % 5;
        }

        printf("Jogador 1: %s\n", nomes[0]);
        printf("Jogador 2: %s\n", nomes[1]);

        while (1) {
            printf("\nÉ a vez de %s. Escolha uma caixa (1 a 5): ", nomes[jogadorAtual]);
            scanf("%d", &caixaEscolhida);
            caixaEscolhida--; 

            if (caixaEscolhida < 0 || caixaEscolhida >= 5) {
                printf("Escolha inválida! Tente novamente.\n");
                continue;
            }

            if (caixaEscolhida == botao) {
                printf("Você encontrou o botão! %s venceu!\n", nomes[jogadorAtual]);
                break;
            } else if (caixaEscolhida == cobra) {
                printf("Você encontrou a cobra! %s perdeu!\n", nomes[jogadorAtual]);
                break;
            } else {
                printf("A caixa está vazia. Tente novamente.\n");
            }

            jogadorAtual = (jogadorAtual + 1) % 2;
        }

        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);
    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("Obrigado por jogar!\n");
}

// Jogo "Gousmas War"
void jogoGousmasWar() {
    printf("Este modo ainda está em desenvolvimento.\n");
}