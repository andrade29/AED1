#include <stdio.h>
#include <stdlib.h>

int g[105][105]; // matriz de adjacência
int cor[105];    // 0 = não visitei, 1 = visitando, 2 = terminei
int acheiCiclo;
int N;

void dfs(int u) {
    cor[u] = 1;

    for (int v = 1; v <= N; v++) {
        if (g[u][v]) {
            if (cor[v] == 0) {
                dfs(v);
                if (acheiCiclo) return;
            } else if (cor[v] == 1) {
                acheiCiclo = 1;
                return;
            }
        }
    }

    cor[u] = 2;
}

int main() {
    int T, M;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++) {
            cor[i] = 0;
            for (int j = 1; j <= N; j++)
                g[i][j] = 0;
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            g[A][B] = 1;
        }

        acheiCiclo = 0;

        for (int i = 1; i <= N && !acheiCiclo; i++) {
            if (cor[i] == 0)
                dfs(i);
        }

        if (acheiCiclo)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
