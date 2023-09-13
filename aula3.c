#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int * arraydin = NULL;
    int ** matrizdin = NULL;

    arraydin = (int *)malloc(10 * sizeof(int));
    *(arraydin + 0) = 10;
    *(arraydin + 1) = 20;

    matrizdin = (int **)malloc(10 * sizeof(int *));
    
    for(int i = 0; i < 10; i++) {
        *(matrizdin + i) = (int *)malloc(10 * sizeof(int));
        if(*(matrizdin + i) == NULL) {
            printf("ERRO!\n");
            return 0;
        }
    }

    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            *(*(matrizdin + i) + j) = rand() % 10;
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%d | ", *(*(matrizdin + i) + j));
        }
        printf("\n");
    }

    return 0;
}