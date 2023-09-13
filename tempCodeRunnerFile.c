for(int i = 0; i < 10; i++) {
        for(int j = 0; i < 10; i++) {
            printf("%d | ", *(*(matrizdin + i) + j));
        }
        printf("\n");
    }