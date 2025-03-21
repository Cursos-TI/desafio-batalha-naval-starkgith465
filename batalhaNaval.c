#include <stdio.h>

    
#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

// Inicializa o tabuleiro preenchendo todas as posições com 0
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Posiciona um navio no tabuleiro com base nas entradas do usuário
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < NAVIO; i++) {
        int x = linha + (direcao == 1 ? i : (direcao == 3 ? -i : 0));
        int y = coluna + (direcao == 0 ? i : (direcao == 2 ? -i : 0));

        // Verifica os limites do tabuleiro
        if (x < 0 || x >= TAMANHO || y < 0 || y >= TAMANHO || tabuleiro[x][y] != 0) {
            return 0; // Posicionamento inválido
        }
    }

    // Posiciona o navio após a validação
    for (int i = 0; i < NAVIO; i++) {
        int x = linha + (direcao == 1 ? i : (direcao == 3 ? -i : 0));
        int y = coluna + (direcao == 0 ? i : (direcao == 2 ? -i : 0));
        tabuleiro[x][y] = NAVIO;
    }
    return 1; // Posicionamento válido
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    printf("Bem-vindo ao jogo de Batalha Naval!\n");

    for (int i = 1; i <= 4; i++) {
        int linha, coluna, direcao;
        printf("\nPosicione o navio %d (tamanho %d):\n", i, NAVIO);
        printf("Digite a linha inicial (0 a %d): ", TAMANHO - 1);
        scanf("%d", &linha);
        printf("Digite a coluna inicial (0 a %d): ", TAMANHO - 1);
        scanf("%d", &coluna);
        printf("Escolha a direção (0=Horizontal direita, 1=Vertical para baixo, 2=Horizontal esquerda, 3=Diagonal para cima): ");
        scanf("%d", &direcao);

        if (!posicionarNavio(tabuleiro, linha, coluna, direcao)) {
            printf("Posicionamento inválido! Tente novamente.\n");
            i--; // Repetir o mesmo navio
        } else {
            printf("Navio %d posicionado com sucesso!\n", i);
        }
    }

    printf("\nTabuleiro final:\n");
    exibirTabuleiro(tabuleiro);

    

    

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
