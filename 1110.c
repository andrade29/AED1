#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        int fila[100];       // fila de cartas
        int descartadas[50]; // cartas descartadas
        int inicio = 0, fim = n; 
        int desc_count = 0;

        // inicializa a fila
        for (int i = 0; i < n; i++) {
            fila[i] = i + 1;
        }

        // simula o processo
        while (fim - inicio > 1) {
            descartadas[desc_count++] = fila[inicio++];
            fila[fim++] = fila[inicio++];
        }

        // imprime cartas descartadas
        printf("Discarded cards:");
        if (desc_count == 0) {
            printf("\n");
        } else {
            for (int i = 0; i < desc_count; i++) {
                if (i == 0)
                    printf(" %d", descartadas[i]);
                else
                    printf(", %d", descartadas[i]);
            }
            printf("\n");
        }

        // imprime carta remanescente
        printf("Remaining card: %d\n", fila[inicio]);
    }

    return 0;
}
