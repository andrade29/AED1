#include <stdio.h>

int main() {
    int N;  // n representa o numero de vagoes

    // loop para ler n enquanto for diferente de zero
    while (scanf("%d", &N) && N != 0) {
        int permutacao[1000];
        int i;

        // loop para realizar as permutacoes
        while (1) {
            int primeiro;
            scanf("%d", &primeiro);
            if (primeiro == 0) break;

            permutacao[0] = primeiro;

            // se o primeiro nao for igual a zero, realiza as outras permutacoes
            for (i = 1; i < N; i++) {
                scanf("%d", &permutacao[i]);
            }
            // estrutura que simula um pilha estatica
            int pilha[1000];
            int top = -1;    
            int vagao = 1; 
            int possivel = 1;

            // verificacao de permutacao
            for (i = 0; i < N; i++) {
                int x = permutacao[i];
                // aqui o loop empilha ate achar o vagao desejado
                while (top == -1 || pilha[top] != x) {
                    if (vagao > N) {
                        possivel = 0;
                        break;
                    }
                    pilha[++top] = vagao++;
                }
                
                if (!possivel) break;
                //desempilha o vagao do top
                top--;
            }

            if (possivel) printf("Yes\n");
            else printf("No\n");
        }

        printf("\n");
    }

    return 0;
}
