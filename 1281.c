#include <stdio.h>
#include <string.h>

// struct que armazena nome e preco
typedef struct {
    char nome[55];
    double preco;
} Produto;

int main() {
    int N;  // n representa o numero de casos testes
    scanf("%d", &N);

    // loop para os caasos
    while (N--) {
        int M; 
        scanf("%d", &M);
        Produto produtos[1050];

        // for para ler os produtos e o precos
        for (int i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i].nome, &produtos[i].preco);
        }

        int P;  // produtos comprados
        scanf("%d", &P);
        double total = 0.0;  

        // for para os produtos comprados
        for (int i = 0; i < P; i++) {
            char nome_busca[55];
            int quantidade;
            scanf("%s %d", nome_busca, &quantidade);

            // for para buscar o produto e ter o preco
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
