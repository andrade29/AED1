#include <stdio.h>
#include <string.h>

int main() {
    int N; // número de casos de teste
    scanf("%d", &N);

    for(int caso=0; caso<N; caso++) {
        int L; // número de linhas do caso
        scanf("%d", &L);
        getchar(); 

        int hash = 0;

        for(int i=0; i<L; i++) {
            char linha[55];
            fgets(linha, sizeof(linha), stdin);
            linha[strcspn(linha, "\n")] = 0;

            for(int j=0; linha[j]; j++) {
                int posAlfabeto = linha[j] - 'A';
                hash += posAlfabeto + i + j;
            }
        }

        printf("%d\n", hash);
    }

    return 0;
}
