#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *adj;
    int qtd, cap;
} Lista;

void addAresta(Lista *L, int x) {
    if (L->qtd == L->cap) {
        L->cap = (L->cap == 0 ? 2 : L->cap * 2);
        L->adj = (int*)realloc(L->adj, L->cap * sizeof(int));
    }
    L->adj[L->qtd++] = x;
}

int acheiCiclo;
int *cor; // 0 = não visitei, 1 = visitando, 2 = terminei

void dfs(Lista *g, int atual) {
    cor[atual] = 1;

    for (int i = 0; i < g[atual].qtd; i++) {
        int prox = g[atual].adj[i];

        if (cor[prox] == 0) {
            dfs(g, prox);
            if (acheiCiclo) return;
        }
        else if (cor[prox] == 1) {
            acheiCiclo = 1;
            return;
        }
    }
    cor[atual] = 2;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        Lista *g = (Lista*)calloc(N + 1, sizeof(Lista));
        cor = (int*)calloc(N + 1, sizeof(int));

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            addAresta(&g[A], B);
        }

        acheiCiclo = 0;

        for (int i = 1; i <= N && !acheiCiclo; i++) {
            if (cor[i] == 0) {
                dfs(g, i);
            }
        }

        if (acheiCiclo)
            printf("SIM\n");
        else
            printf("NAO\n");

        for (int i = 1; i <= N; i++) free(g[i].adj);
        free(g);
        free(cor);
    }

    return 0;
}
