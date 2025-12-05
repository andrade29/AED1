#include <stdio.h>
#include <stdlib.h>

int partition(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }

    int aux = v[i+1];
    v[i+1] = v[fim];
    v[fim] = aux;

    return i + 1; 
}

void quicksort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = partition(v, inicio, fim);
        quicksort(v, inicio, p - 1);
        quicksort(v, p + 1, fim);
    }
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int M;
        scanf("%d", &M);

        int *original =(int*) malloc(M * sizeof(int));
        int *ordenado =(int*) malloc(M * sizeof(int));

        for (int i = 0; i < M; i++)
            scanf("%d", &original[i]);

        for (int i = 0; i < M; i++)
            ordenado[i] = original[i];

        quicksort(ordenado, 0, M - 1);

        int cont = 0;
        for (int i = 0; i < M; i++)
            if (ordenado[i] == original[i])
                cont++;

        printf("%d\n", cont);

        free(original);
        free(ordenado);
    }

    return 0;
}
