#include <stdio.h>

int main() {
    /* escreva um programa em C que permita um jogo simples, onde uma matriz de inteiros seja preenchida randomicamente com números positivos inteiros,
    informe os números na tela e o usuário informe qual número acredita que será escolhido. Seu sistema deve escolher randomicamente uma posição da matriz
    e informar se o usuário ganhou! São três níveis fácil (9 números), médio (25 números) e difícil (100 números). Usar alocação dinâmica.
    
    Dicas:
    x = rand() % 10 - dará números aleatórios entre 0 e 10
    use arimética de pontieros para ler e escrever na matriz
    rand faz parte da biblioteca time.h */
    
    int matriz[2][3];

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            matriz[i][j] = 1 + i + j;
        }
    }

    for(int i = 0; i < 2; i++) {
        printf("Linha #%d: ", i+1);
        for(int j = 0; j < 3; j++) {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}