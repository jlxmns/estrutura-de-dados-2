#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contato {
    char nome[101];
    char telefone[15];
};

int main() {
    int maxElements = 2;
    int currentElements = 0;

    struct Contato *listaTelefonica = (struct Contato *)malloc(maxElements * sizeof(struct Contato));

    if (listaTelefonica == NULL) {
        printf("Erro na alocacao de memoria\n");
        return 1;
    };

    void addContato(const char *nome, const char *telefone) {
        if (currentElements >= maxElements) {
            maxElements *= 2;
            listaTelefonica = (struct Contato *)realloc(listaTelefonica, maxElements * sizeof(struct Contato));
            if (listaTelefonica == NULL) {
                printf("Erro na realocacao de memoria\n");
                exit(1);
            }
        }

        strncpy(listaTelefonica[currentElements].nome, nome, 100);
        strncpy(listaTelefonica[currentElements].telefone, telefone, 14);

        currentElements++;
    };

    char nomeInput[101];
    char telefoneInput[15];
    char choice;

    do {
        printf("Digite o nome: ");
        scanf("%100s", nomeInput);
        printf("Digite o telefone: ");
        scanf("%14s", telefoneInput);

        addContato(nomeInput, telefoneInput);

        printf("Deseja adicionar outro contato? (S/n): ");
        scanf(" %c", &choice);

    } while (choice == 'S' || choice == 's');

    printf("\nLista Telefonica:\n");
    for (int i = 0; i < currentElements; i++) {
        printf("Nome: %s, Telefone: %s\n", listaTelefonica[i].nome, listaTelefonica[i].telefone);
    }

    free(listaTelefonica);

    return 0;
}