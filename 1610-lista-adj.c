#include <stdio.h>
#include <stdlib.h>

// struct de uma lista adj
typedef struct {
    int *adj;   // vetor de adjacentes
    int qtd, cap; 
} Lista;

// adiciona aresta na lista
void addAresta(Lista *L, int x) {
    if (L->qtd == L->cap) {
        L->cap = (L->cap == 0 ? 2 : L->cap * 2);
        L->adj = (int*)realloc(L->adj, L->cap * sizeof(int));
    }
    L->adj[L->qtd++] = x;
}

int acheiCiclo;  
int *cor; // 0 = não visitei, 1 = visitando, 2 = terminei

// funcao DFS para detectar ciclo em grafo direcionado
void dfs(Lista *g, int atual) {
    cor[atual] = 1; // marca como visitando

    for (int i = 0; i < g[atual].qtd; i++) {
        int prox = g[atual].adj[i];

        if (cor[prox] == 0) {
            dfs(g, prox);
            if (acheiCiclo) return;
        }
        else if (cor[prox] == 1) {
            // encontrou um ciclo
            acheiCiclo = 1;
            return;
        }
    }

    cor[atual] = 2; // marca como finalizado
}

int main() {
    int T;  // t representa número de casos de teste
    scanf("%d", &T);

    while (T--) {
        int N, M;  // n vértices e m arestas
        scanf("%d %d", &N, &M);

        // aloca o grafo e o vetor de cores e depois faz leitura das arestas
        Lista *g = (Lista*)calloc(N + 1, sizeof(Lista));
        cor = (int*)calloc(N + 1, sizeof(int));
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            addAresta(&g[A], B);
        }
        acheiCiclo = 0;
        // executa DFS para cada vértice não visitado
        for (int i = 1; i <= N && !acheiCiclo; i++) {
            if (cor[i] == 0) {
                dfs(g, i);
            }
        }
        if (acheiCiclo)
            printf("SIM\n");
        else
            printf("NAO\n");

        //libera
        for (int i = 1; i <= N; i++) free(g[i].adj);
        free(g);
        free(cor);
    }

    return 0;  
}
