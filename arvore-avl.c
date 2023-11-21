#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Júlio César Toscano Ximenes Júnior

struct node {
    int dado;
    struct node* esq;
    struct node* dir;
    int ht;
};

struct node* raiz = NULL;

//funções
struct node* criar(int);
struct node* inserir(struct node*, int);
struct node* girar_esq(struct node*);
struct node* girar_dir(struct node*);
int fator_balanceamento(struct node*);
int altura(struct node*);
void inordem(struct node*);
void preordem(struct node*);
void posordem(struct node*);

int main() {
    setlocale( LC_ALL, "portuguese" );
    int escolha, dado;
    char continuar = 's';
    struct node* resultado = NULL;

    while(continuar == 's' || continuar == 'S') {
        printf("\n\n----- Árvore AVL -----");
        printf("\n1. Inserir");
        printf("\n2. In-ordem");
        printf("\n3. Pre-ordem");
        printf("\n4. Pos-ordem");
        printf("\n5. Sair");

        printf("\nEscolha uma opção:");
        scanf(" %d", &escolha);

        switch(escolha) {
            case 1:
                printf("\nInforme um número:");
                scanf(" %d", &dado);
                raiz = inserir(raiz, dado);
                break;

            case 2:
                inordem(raiz);
                break;

            case 3:
                preordem(raiz);
                break;

            case 4:
                posordem(raiz);
                break;

            case 5:
                printf("\nPrograma encerrado");
                return 1;

            default:
                printf("\nEscolha inválida.");
        }

        printf("\n\nGostaria de realizar outra operação?");
        scanf(" %c", &continuar);
    }
}

struct node* criar(int dado) {
    struct node* novo_no = (struct node*)malloc(sizeof(struct node));
    if(novo_no == NULL) {
        printf("Memória não pôde ser alocada.");
        return NULL;
    }

    novo_no->dado = dado;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}

struct node* girar_esq(struct node* raiz) {
    struct node* filho_dir = raiz->dir;
    raiz->dir = filho_dir->esq;
    filho_dir->esq = raiz;

    raiz->ht = altura(raiz);
    filho_dir->ht = altura(filho_dir);

    return filho_dir;
}

struct node* girar_dir(struct node* raiz) {
    struct node* filho_esq = raiz->esq;
    raiz->esq = filho_esq->dir;
    filho_esq->dir = raiz;

    raiz->ht = altura(raiz);
    filho_esq->ht = altura(filho_esq);

    return filho_esq;
}

int fator_balanceamento(struct node* raiz) {
    int lht, rht;
    if(raiz == NULL)
        return 0;
    if(raiz->esq == NULL)
        lht = 0;
    else
        lht = 1 + raiz->esq->ht;
    if(raiz->dir == NULL)
        rht = 0;
    else
        rht = 1 + raiz->dir->ht;

    return lht - rht;
}

int altura(struct node* raiz) {
    int lht, rht;
    if(raiz == NULL) {
        return 0;
    }
    if(raiz->esq == NULL)
        lht = 0;
    else
        lht = 1 + raiz->esq->ht;
    if(raiz->dir == NULL)
        rht = 0;
    else
        rht = 1 + raiz->dir->ht;

    if(lht > rht)
        return lht;
    return rht;
}

struct node* inserir(struct node* raiz, int dado) {
    if(raiz == NULL) {
        struct node* novo_no = criar(dado);
        if(novo_no == NULL) {
            return NULL;
        }
        raiz = novo_no;
    } else if (dado > raiz->dado) {
        //inserindo na direita
        raiz->dir = inserir(raiz->dir, dado);

        //balanceando
        if(fator_balanceamento(raiz) == -2) {
            if(dado > raiz->dir->dado) {
                raiz = girar_esq(raiz);
            }
            else {
                raiz->dir = girar_dir(raiz->dir);
                raiz = girar_esq(raiz);
            }
        }
    } else {
        //inserindo na esquerda
        raiz->esq = inserir(raiz->esq, dado);

        //balanceando
        if(fator_balanceamento(raiz) == 2) {
            if(dado < raiz->esq->dado) {
                raiz = girar_dir(raiz);
            } else {
                raiz->esq = girar_esq(raiz->esq);
                raiz = girar_dir(raiz);
            }
        }
    }

    //atualizar altura dos nós
    raiz->ht = altura(raiz);
    return raiz;
}

void inordem(struct node* raiz) {
    if(raiz == NULL) {
        return;
    }

    inordem(raiz->esq);
    printf("%d - ", raiz->dado);
    inordem(raiz->dir);
}

void preordem(struct node* raiz) {
    if(raiz == NULL) {
        return;
    }

    printf("%d - ", raiz->dado);
    preordem(raiz->esq);
    preordem(raiz->dir);
}

void posordem(struct node* raiz) {
    if(raiz == NULL) {
        return;
    }

    posordem(raiz->esq);
    posordem(raiz->dir);
    printf("%d - ", raiz->dado);
}