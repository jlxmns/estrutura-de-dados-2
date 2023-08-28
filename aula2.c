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
    int tamanho;

    //Escolhendo a dificuldade
    do {
        printf("Escolha o nivel de dificuldade (1 - facil, 2 - medio, 3 - dificil)\n");
        scanf(" %d", &escolha);
    } while (escolha != 1 && escolha != 2 && escolha != 3);

    //Definindo o tamanho de acordo com a dificuldade escolhida
    if(escolha == 1) {
        tamanho = 9;
    } else if (escolha == 2) {
        tamanho = 25;
    } else {
        tamanho = 100;
    }

    //Alocando o espaço na memória dinamicamente
    matriz = malloc(tamanho * sizeof(int));

    //Ajeitando a função rand() para ela não mostrar resultados repetidos em execuções diferentes
    srand(time(NULL));

    //Iterando pela matriz para atribuir os valores
    for(int i = 0; i < tamanho; i++) {
        *(matriz + i) = rand() % 10;
    }

    //Imprimindo a matriz
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(matriz + i));
    }

    //Perguntando ao usuário qual a posição que ele vai apostar
    printf("\nQual posicao voce acha que sera escolhida?\n");
    scanf(" %d", &escolha);

    //Escolhendo uma posição aleatória da matriz e apresentando resultado
    int posicaoEscolhida = rand() % tamanho;

    if(escolha == (posicaoEscolhida + 1)) {
        printf("Parabens, voce acertou!\n");
    } else {
        printf("Poxa, mais sorte na proxima.\n");
    }

    printf("O numero escolhido foi: %d, na posicao %d.", *(matriz + posicaoEscolhida), (posicaoEscolhida + 1));
}