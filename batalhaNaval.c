// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>

// ----- defines de valores -----
#define Linha     10     // linhas do tabuleiro
#define Coluna    10     // colunas do tabuleiro
#define Navio      3     // valor que marca parte do navio no tabuleiro
#define NavioTam   3     // tamanho fixo dos navios

int main() {
    int i, j;

    printf("\n ***********************\n");
    printf(" **** Batalha Naval ****\n");
    printf(" ***********************\n\n");
    printf(" ------ TABULEIRO ------\n\n");

    // 1) tabuleiro 10x10 zerado (água = 0)
    int tabuleiro[Linha][Coluna];
    for (i = 0; i < Linha; i++)
        for (j = 0; j < Coluna; j++)
            tabuleiro[i][j] = 0;

    // 2) vetores dos navios
    int navioH[NavioTam] = {Navio, Navio, Navio}; // horizontal
    int NavioV[NavioTam] = {Navio, Navio, Navio}; // vertical
    int navioD[NavioTam] = {Navio, Navio, Navio}; // diagonais

    // 3) coordenadas (0..9) – escolhidas sem sobreposição
    int linH = 1, colH = 1;       // horizontal
    int linV = 4, colV = 7;       // vertical

    // Diagonal Baixo-Direita (diagBD): (lin+i, col+i)
    int linDiagBD = 0, colDiagBD = 5; // -> (0,5) (1,6) (2,7)

    // Diagonal Baixo-Esquerda (diagBE): (lin+i, col-i)
    int linDiagBE = 6, colDiagBE = 9; // -> (6,9) (7,8) (8,7)

    // 4) validação + posicionamento
    int casas, ok;

    // --- Navio Horizontal ---
    ok = 1;
    if (linH < 0 || linH >= Linha) ok = 0;
    if (colH < 0 || colH > Coluna - NavioTam) ok = 0;       // precisa col, col+1, col+2
    if (ok) for (casas = 0; casas < NavioTam; casas++)
        if (tabuleiro[linH][colH + casas] != 0) ok = 0;     // sem sobreposição
    if (ok) for (casas = 0; casas < NavioTam; casas++)
        tabuleiro[linH][colH + casas] = navioH[casas];
    else printf("ERRO: H nao cabe/sobrepoe em [%d,%d]\n", linH, colH);

    // --- Navio Vertical ---
    ok = 1;
    if (colV < 0 || colV >= Coluna) ok = 0;
    if (linV < 0 || linV > Linha - NavioTam) ok = 0;        // precisa lin, lin+1, lin+2
    if (ok) for (casas = 0; casas < NavioTam; casas++)
        if (tabuleiro[linV + casas][colV] != 0) ok = 0;
    if (ok) for (casas = 0; casas < NavioTam; casas++)
        tabuleiro[linV + casas][colV] = NavioV[casas];
    else printf("ERRO: V nao cabe/sobrepoe em [%d,%d]\n", linV, colV);

    // --- Navio Diagonal Baixo-Direita (diagBD): (lin+i, col+i) ---
    ok = 1;
    if (linDiagBD < 0 || linDiagBD > Linha - NavioTam) ok = 0;
    if (colDiagBD < 0 || colDiagBD > Coluna - NavioTam) ok = 0;
    if (ok) for (casas = 0; casas < NavioTam; casas++)
        if (tabuleiro[linDiagBD + casas][colDiagBD + casas] != 0) ok = 0;
    if (ok) for (casas = 0; casas < NavioTam; casas++)
        tabuleiro[linDiagBD + casas][colDiagBD + casas] = navioD[casas];
    else printf("ERRO: diagBD nao cabe/sobrepoe em [%d,%d]\n", linDiagBD, colDiagBD);

    // --- Navio Diagonal Baixo-Esquerda (diagBE): (lin+i, col-i) ---
    ok = 1;
    if (linDiagBE < 0 || linDiagBE > Linha - NavioTam) ok = 0;
    if (colDiagBE < NavioTam - 1 || colDiagBE >= Coluna) ok = 0; // precisa col, col-1, col-2
    if (ok) for (casas = 0; casas < NavioTam; casas++)
        if (tabuleiro[linDiagBE + casas][colDiagBE - casas] != 0) ok = 0;
    if (ok) for (casas = 0; casas < NavioTam; casas++)
        tabuleiro[linDiagBE + casas][colDiagBE - casas] = navioD[casas];
    else printf("ERRO: diagBE nao cabe/sobrepoe em [%d,%d]\n", linDiagBE, colDiagBE);

    // 5) impressão A a J, e 1 a 10 do tabuleiro
    printf("\n    ");
    for (j = 0; j < Coluna; j++) printf("%c ", 'A' + j);
    printf("\n");
    for (i = 0; i < Linha; i++) {
        printf("%2d  ", i + 1);
        for (j = 0; j < Coluna; j++) printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }
    printf("\n***** Fim do jogo! *****\n\n");
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
