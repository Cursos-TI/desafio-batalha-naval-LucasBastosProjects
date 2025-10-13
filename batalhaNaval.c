#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    printf("**Batalha Naval**\n\n");
    // rótulos do tabuleiro
    char letras[10]  = {'A','B','C','D','E','F','G','H','I','J'};
    int  numeros[10] = {1,2,3,4,5,6,7,8,9,10};

    // tabuleiro 10x10 com 0 (água)
    int tab[10][10];
    int linha, coluna;
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tab[linha][coluna] = 0;
        }
    }

    // navios (tamanho 3, valor 3)
    int navioH[3] = {3, 3, 3}; // horizontal
    int navioV[3] = {3, 3, 3}; // vertical

    // coordenadas iniciais (base 0) — ajuste para treinar
    int hLinha = 2; int hCol = 1; // horizontal -> (2,1) (2,2) (2,3)
    int vLinha = 5; int vCol = 7; // vertical   -> (5,7) (6,7) (7,7)

    // posicionar navio horizontal (assumindo válido e sem sobreposição)
    int i;
    for (i = 0; i < 3; i++) {
        tab[hLinha][hCol + i] = navioH[i];
    }

    // posicionar navio vertical (assumindo válido e sem sobreposição)
    for (i = 0; i < 3; i++) {
        tab[vLinha + i][vCol] = navioV[i];
    }

    // imprimir onde estão os 3s de cada navio
    printf("Posicoes do navio horizontal (3):\n");
    for (i = 0; i < 3; i++) {
        printf(" - %c%d\n", letras[hLinha], numeros[hCol + i]);
    }

    printf("\nPosicoes do navio vertical (3):\n");
    for (i = 0; i < 3; i++) {
        printf(" - %c%d\n", letras[vLinha + i], numeros[vCol]);
    }

    // imprimir tabuleiro com rótulos (0 = água, 3 = navio)
    printf("\n   ");
    for (coluna = 0; coluna < 10; coluna++) printf("%2d ", numeros[coluna]);
    printf("\n");
    for (linha = 0; linha < 10; linha++) {
        printf("%c  ", letras[linha]);
        for (coluna = 0; coluna < 10; coluna++) {
            printf("%2d ", tab[linha][coluna]);
        }
        printf("\n");
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
