#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int valor;
    struct NO *prox;
}NO;

int main() {
    int N, i;
    scanf("%d", &N);

    NO *inicio = NULL;
    NO *atual = NULL;

    for (i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        NO *novo = (NO*)malloc(sizeof(NO));
        novo->valor = num;
        novo->prox = NULL;

        if (inicio == NULL) {
            inicio = novo;
            atual = novo;
        } else {
            atual->prox = novo;
            atual = novo;
        }
    }

    
    int menor, posicao; // Encontra o menor valor e sua posição
    menor = inicio->valor;
    posicao = 0;

    int indice = 0;
    for (NO *p = inicio; p != NULL; p = p->prox) {
        if (p->valor < menor) {
            menor = p->valor;
            posicao = indice;
        }
        indice++;
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    
    NO *p = inicio; // Libera a memória
    while (p != NULL) {
        NO *temp = p;
        p = p->prox;
        free(temp);
    }

    return 0;
}
