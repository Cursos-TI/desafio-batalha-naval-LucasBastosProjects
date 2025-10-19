#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>

int main() {

    printf("\n");
    printf(" ***********************\n");
    printf(" **** Batalha Naval ****\n");
    printf(" ***********************\n\n");

    printf(" ------ TABULEIRO ------\n\n");

    // Tabuleiro 10x10 com água com o valor = 0 no tabuleiro
    int tabuleiro[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    // Dois navios com tamanho 3 e valor = 3 no tabuleiro
    int navioHorizontal[3] = {3,3,3};
    int navioVertical[3]   = {3,3,3};

    // Coordenadas iniciais (índices 0..9)
    int linhaHorizontal = 1;    // linha do navio horizontal (mostra 2 para o jogador)
    int colunaHorizontal = 1;   // coluna do navio horizontal (mostra B para o jogador)
    int linhaVertical = 4;      // linha do navio vertical   (mostra 5 para o jogador)
    int colunaVertical = 7;     // coluna do navio vertical  (mostra H para o jogador)

    // Posicionamento COM LOOPS (usa 'casas' como contador de partes 0,1,2)
    int casas;

    // Horizontal: mesma linha, avança as colunas
    for (casas = 0; casas < 3; casas++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + casas] = navioHorizontal[casas];
    }

    // Vertical: mesma coluna, avança as linhas
    for (casas = 0; casas < 3; casas++) {
        tabuleiro[linhaVertical + casas][colunaVertical] = navioVertical[casas];
    }

    // Impressão do tabuleiro: cabeçalho de A a J e colunas de 1 a 10
    int linha, coluna;
    printf("    ");
    for (coluna = 0; coluna < 10; coluna++) {
        printf("%c ", 'A' + coluna);
    }
    printf("\n");

    for (linha = 0; linha < 10; linha++) {
        printf("%2d  ", linha + 1);
        for (coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    printf("\n");
    printf("***** Fim do jogo! *****\n\n");

    return 0;
}


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
