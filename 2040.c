#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[50];
    int pontos;
    struct No *prox;
} No;

// Insere time no fim
No* inserirFim(No *lista, char nome[], int pontos) {
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->pontos = pontos;
    novo->prox = NULL;

    if (lista == NULL) return novo;

    No *aux = lista;
    while (aux->prox != NULL)
        aux = aux->prox;

    aux->prox = novo;
    return lista;
}

//função buscar
No* buscar(No *lista, char nome[]) {
    while (lista != NULL) {
        if (strcmp(lista->nome, nome) == 0)
            return lista;
        lista = lista->prox;
    }
    return NULL;
}

// Libera alista
void liberar(No *lista) {
    while (lista != NULL) {
        No *tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
}

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {

        No *lista = NULL;
        char nome[50];
        int pontos;

        //times
        for (int i = 0; i < N; i++) {
            scanf("%s %d", nome, &pontos);
            lista = inserirFim(lista, nome, pontos);
        }

        //jogos
        for (int i = 0; i < N/2; i++) {
            char timeA[50], timeB[50];
            int golsA, golsB;

            scanf("%s %d-%d %s", timeA, &golsA, &golsB, timeB);

            No *A = buscar(lista, timeA);
            No *B = buscar(lista, timeB);

            
            A->pontos += golsA * 3;
            B->pontos += golsB * 3;

            if (golsA == golsB) {
                A->pontos += 1;
                B->pontos += 1;
            } else if (golsA > golsB) {
                A->pontos += 5;
            } else {
                B->pontos += 5;
            }
        }

        // Descobre o ccampeão
        No *aux = lista;
        No *campeao = aux;

        while (aux != NULL) {
            if (aux->pontos > campeao->pontos)
                campeao = aux;
            aux = aux->prox;
        }

        // verfica o sport
        No *sport = buscar(lista, "Sport");

        if (strcmp(campeao->nome, "Sport") == 0)
            printf("O Sport foi o campeao com %d pontos :D\n\n", campeao->pontos);
        else
            printf("O Sport nao foi o campeao. O time campeao foi o %s com %d pontos :(\n\n",
                   campeao->nome, campeao->pontos);

        liberar(lista);
    }

    return 0;
}
