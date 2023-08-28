#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* escreva um programa em C que permita um jogo simples, onde uma matriz de inteiros seja preenchida randomicamente com números positivos inteiros,
    informe os números na tela e o usuário informe qual número acredita que será escolhido. Seu sistema deve escolher randomicamente uma posição da matriz
    e informar se o usuário ganhou! São três níveis fácil (9 números), médio (25 números) e difícil (100 números). Usar alocação dinâmica.
    
    Dicas:
    x = rand() % 10 - dará números aleatórios entre 0 e 10
    use arimética de pontieros para ler e escrever na matriz
    rand faz parte da biblioteca time.h */

    int escolha;
    int * matriz;
    int ** ponteiroDaMatriz = &matriz;
    int tamanho;

    do {
        printf("Escolha o nivel de dificuldade (1 - facil, 2 - medio, 3 - dificil)\n");
        scanf(" %d", &escolha);
    } while (escolha != 1 && escolha != 2 && escolha != 3);

    if(escolha == 1) {
        tamanho = 9;
    } else if (escolha == 2) {
        tamanho = 25;
    } else {
        tamanho = 100;
    }

    matriz = malloc(tamanho * sizeof(int));

    for(int i = 0; i < tamanho; i++) {
        ponteiroDaMatriz = 
    }

    printf("%d", ponteiroDaMatriz);
}