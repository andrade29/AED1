#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int h, freq;
    struct no *esq, *dir;
} No;

No* novoNo(int h) {
    No* n = (No*)malloc(sizeof(No));
    n->h = h;
    n->freq = 1;
    n->esq = n->dir = NULL;
    return n;
}

No* insere(No* r, int h) {
    if (!r) return novoNo(h);
    if (h == r->h) {
        r->freq++;
    } else if (h < r->h) {
        r->esq = insere(r->esq, h);
    } else {
        r->dir = insere(r->dir, h);
    }
    return r;
}

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

void libera(No* r) {
    if (!r) return;
    libera(r->esq);
    libera(r->dir);
    free(r);
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N, x;
        scanf("%d", &N);

        No* raiz = NULL;

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
