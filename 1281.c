#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[55];
    double preco;
} Produto;

int main() {
    int N;  
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);
        Produto produtos[1050];

        for (int i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i].nome, &produtos[i].preco);
        }

        int P;
        scanf("%d", &P);

        double total = 0.0;

        for (int i = 0; i < P; i++) {
            char nome_busca[55];
            int quantidade;
            scanf("%s %d", nome_busca, &quantidade);

            for (int j = 0; j < M; j++) {
                if (strcmp(nome_busca, produtos[j].nome) == 0) {
                    total += produtos[j].preco * quantidade;
                    break;
                }
            }
        }

        printf("R$ %.2lf\n", total);
    }

    return 0;
}
