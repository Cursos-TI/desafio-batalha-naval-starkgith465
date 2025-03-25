#include <stdio.h>

// Constantes para tamanho do tabuleiro e habilidades
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro com valores padrão
int inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int linha, coluna;
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0; // Representa água
        }
    }
    return 1; // Sucesso
}

// Função para exibir o tabuleiro no console
int exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int linha, coluna;
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            switch (tabuleiro[linha][coluna]) {
                case 0:
                    printf("~ "); // Água
                    break;
                case 3:
                    printf("# "); // Navio
                    break;
                case 1:
                    printf("+ "); // Cruz
                    break;
                case 4:
                    printf("^ "); // Cone/Losango
                    break;
                default:
                    printf("? "); // Valores inesperados
                    break;
            }
        }
        printf("\n");
    }
    return 1; // Sucesso
}

// Função para aplicar uma habilidade ao tabuleiro
int aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna, int valor) {
    int linha, coluna;
    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            // Calcula a posição no tabuleiro
            int posicaoLinha = origemLinha - TAMANHO_HABILIDADE / 2 + linha;
            int posicaoColuna = origemColuna - TAMANHO_HABILIDADE / 2 + coluna;

            // Verifica os limites do tabuleiro
            if (posicaoLinha >= 0 && posicaoLinha < TAMANHO_TABULEIRO && posicaoColuna >= 0 && posicaoColuna < TAMANHO_TABULEIRO && habilidade[linha][coluna] == 1) {
                tabuleiro[posicaoLinha][posicaoColuna] = valor; // Marca como área de efeito
            }
        }
    }
    return 1; // Sucesso
}

// Função para verificar o fim do jogo
int verificarFimDeJogo(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int linha, coluna;
    int naviosRestantes = 0;

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            if (tabuleiro[linha][coluna] == 3) { // Verifica se há navios no tabuleiro
                naviosRestantes++;
            }
        }
    }

    if (naviosRestantes == 0) {
        return 1; // Fim de jogo: todos os navios foram destruídos
    } else {
        return 0; // Jogo continua: ainda existem navios
    }
}

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\n==== Menu de Comandos ====\n");
    printf("1 - Aplicar habilidade Cruz\n");
    printf("2 - Aplicar habilidade Cone (Losango)\n");
    printf("3 - Exibir tabuleiro\n");
    printf("0 - Sair\n");
    printf("==========================\n");
    printf("Escolha uma opção: ");
}

// Função principal
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    int opcao, origemLinha, origemColuna;

    inicializarTabuleiro(tabuleiro);

    // Define um exemplo de navio
    tabuleiro[4][5] = 3;

    // Loop do menu
    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Aplicar habilidade Cruz
                printf("Digite as coordenadas da origem (linha coluna): ");
                scanf("%d %d", &origemLinha, &origemColuna);

                // Verifica se a origem está dentro do tabuleiro
                if (origemLinha >= 0 && origemLinha < TAMANHO_TABULEIRO && origemColuna >= 0 && origemColuna < TAMANHO_TABULEIRO) {
                    aplicarHabilidade(tabuleiro, cruz, origemLinha, origemColuna, 1);
                } else {
                    printf("Coordenadas inválidas! Tente novamente.\n");
                }
                break;

            case 2: // Aplicar habilidade Cone (Losango)
                printf("Digite as coordenadas da origem (linha coluna): ");
                scanf("%d %d", &origemLinha, &origemColuna);

                // Verifica se a origem está dentro do tabuleiro
                if (origemLinha >= 0 && origemLinha < TAMANHO_TABULEIRO && origemColuna >= 0 && origemColuna < TAMANHO_TABULEIRO) {
                    aplicarHabilidade(tabuleiro, cone, origemLinha, origemColuna, 4);
                } else {
                    printf("Coordenadas inválidas! Tente novamente.\n");
                }
                break;

            case 3: // Exibir tabuleiro
                printf("\nTabuleiro atual:\n");
                exibirTabuleiro(tabuleiro);
                break;

            case 0: // Sair
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

        // Verifica se o jogo terminou
        if (verificarFimDeJogo(tabuleiro)) {
            printf("\nFim de jogo: todos os navios foram destruídos!\n");
            opcao = 0; // Força a saída do loop
        }

    } while (opcao != 0);

    return 0;
}
