#include <stdio.h>
#include <string.h>

int main() {
    int N; // n representa o numero de casos testes
    scanf("%d", &N);

    // for para cada caso teste
    for(int caso = 0; caso < N; caso++) {
        int L;
        scanf("%d", &L);
        getchar();
        int hash = 0; 

        // for para ler as
        for(int i = 0; i < L; i++) {
            char linha[55];
            fgets(linha, sizeof(linha), stdin);

            // remove os quebras de linhas
            linha[strcspn(linha, "\n")] = 0;

            for(int j = 0; linha[j]; j++) {
                int posAlfabeto = linha[j] - 'A'; 
                hash += posAlfabeto + i + j;    
            }
        }
        printf("%d\n", hash);
    }

    return 0; 
}
