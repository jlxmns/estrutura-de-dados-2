#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato {
    char nome[101];
    char telefone[15];
} Contato;

void addContato(struct Contato **listaTelefonica, int *currentElements, int *maxElements, const char *nome, const char *telefone) {
    if (*currentElements >= *maxElements) {
        *maxElements *= 2;
        *listaTelefonica = (struct Contato *)realloc(*listaTelefonica, *maxElements * sizeof(struct Contato));
        if (*listaTelefonica == NULL) {
            printf("Erro na realocacao de memoria\n");
            exit(1);
        }
    }

    strncpy((*listaTelefonica)[*currentElements].nome, nome, 100);
    strncpy((*listaTelefonica)[*currentElements].telefone, telefone, 14);

    (*currentElements)++;
}

int main() {
    int maxElements = 2;
    int currentElements = 0;

    Contato *listaTelefonica = (struct Contato *)malloc(maxElements * sizeof(struct Contato));

    if (!listaTelefonica) {
        printf("Erro na alocacao de memoria\n");
        return 1;
    };

    char nomeInput[101];
    char telefoneInput[15];
    char choice;

    FILE *arquivo = fopen("lista_telefonica.txt", "w");

    if(arquivo == NULL) {
        printf("Erro: arquivo não encontrado.\n");
        return 1;
    }

    do {
        printf("Digite o nome: ");
        fflush(stdin);
        scanf(" %100s", nomeInput);
        printf("Digite o telefone: ");
        fflush(stdin);
        scanf(" %14s", telefoneInput);

        addContato(&listaTelefonica, &currentElements, &maxElements, nomeInput, telefoneInput);

        fprintf(arquivo, "Nome: %s, Telefone: %s\n", nomeInput, telefoneInput);

        printf("Deseja adicionar outro contato? (S/n): ");
        scanf(" %c", &choice);

    } while (choice == 'S' || choice == 's');

    printf("\nLista Telefonica:\n");
    for (int i = 0; i < currentElements; i++) {
        printf("Nome: %s, Telefone: %s\n", listaTelefonica[i].nome, listaTelefonica[i].telefone);
    }

    fclose(arquivo);

    free(listaTelefonica);

    return 0;
}