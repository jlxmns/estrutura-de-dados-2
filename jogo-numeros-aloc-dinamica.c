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
    int ** matriz = NULL;
    int tamanho;
    int escolhaLinhas, escolhaColunas;

    //Escolhendo a dificuldade
    do {
        printf("Escolha o nivel de dificuldade (1 - facil, 2 - medio, 3 - dificil)\n");
        scanf(" %d", &escolha);
    } while (escolha != 1 && escolha != 2 && escolha != 3);

    //Definindo o tamanho de acordo com a dificuldade escolhida
    if(escolha == 1) {
        tamanho = 3;
    } else if (escolha == 2) {
        tamanho = 5;
    } else {
        tamanho = 10;
    }

    //Alocando o espaço na memória dinamicamente
    matriz = (int **)malloc(tamanho * sizeof(int *));

    for(int i = 0; i < tamanho; i++) {
        *(matriz + i) = (int *)malloc(tamanho * sizeof(int));
        if(*(matriz + i) == NULL) {
            printf("ERRO!\n");
            return 0;
        }
    }

    //Ajeitando a função rand() para ela não mostrar resultados repetidos em execuções diferentes
    srand(time(NULL));

    //Iterando pela matriz para atribuir os valores
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            *(*(matriz + i) + j) = rand() % 10;
        }
    }

    //Imprimindo a array
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            printf("%d | ", *(*(matriz + i) + j));
        }
        printf("\n");
    }

    //Perguntando ao usuário qual a posição que ele vai apostar
    printf("\nQual linha voce acha que sera escolhida?\n");
    scanf(" %d", &escolhaLinhas);
    printf("\nQual coluna voce acha que sera escolhida?\n");
    scanf(" %d", &escolhaColunas);

    //Escolhendo uma posição aleatória da array e apresentando resultado
    int linhaEscolhida = rand() % tamanho;
    int colunaEscolhida = rand() % tamanho;

    if(escolhaLinhas == linhaEscolhida && escolhaLinhas == colunaEscolhida) {
        printf("Parabens, voce acertou!\n");
    } else {
        printf("Poxa, mais sorte na proxima.\n");
    }

    printf("O numero escolhido foi: %d, na linha %d e coluna %d.", *(*(matriz + linhaEscolhida) + colunaEscolhida), 
    linhaEscolhida, colunaEscolhida);

    free(matriz);
}