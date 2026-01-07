#include <stdio.h>
#include <stdlib.h>

// struct de uma arvore
typedef struct no {
    int h;                 
    int freq;              
    struct no *esq, *dir; 
} No;

// nó armazenado dinamicamente 
No* novoNo(int h) {
    No* n = (No*)malloc(sizeof(No));
    n->h = h;
    n->freq = 1;
    n->esq = n->dir = NULL;
    return n;
}

// funcao insere valor na arvore
No* insere(No* r, int h) {
    if (!r) return novoNo(h);

    if (h == r->h) {
        r->freq++;                 // aqui se o valor existe ele incrementa
    } else if (h < r->h) {
        r->esq = insere(r->esq, h);
    } else {
        r->dir = insere(r->dir, h);
    }
    return r;
}

// funcao imprime
void imprime(No* r, int *primeiro) {
    if (!r) return;
    imprime(r->esq, primeiro);

    for (int i = 0; i < r->freq; i++) {
        if (*primeiro) {
            printf("%d", r->h);
            *primeiro = 0;
        } else {
            printf(" %d", r->h);
        }
    }

    imprime(r->dir, primeiro);
}

// funcao libera
void libera(No* r) {
    if (!r) return;
    libera(r->esq);
    libera(r->dir);
    free(r);
}

int main() {
    int NC;  // nc representa os casos testes
    scanf("%d", &NC);

    while (NC--) {
        int N, x;
        scanf("%d", &N);
        No* raiz = NULL;  // raiz == null

        // for para inserir os valores
        for (int i = 0; i < N; i++) {
            scanf("%d", &x);
            raiz = insere(raiz, x);
        }

        int primeiro = 1;  
        imprime(raiz, &primeiro);
        printf("\n");
        libera(raiz);      
    }

    return 0;
}
