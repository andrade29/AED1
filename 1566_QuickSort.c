#include <stdio.h>
#include <stdlib.h>

// funcao particao -> aonde usa o ultimo elemento como pivo
int particao(int v[], int inicio, int fim) {
    int pivo = v[fim]; 
    int i = inicio - 1; // índice do menor elemento

    // percorre o vetor e reorganiza em relação ao pivo
    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }

    // ajusta o pivo no lugar certo
    int aux = v[i+1];
    v[i+1] = v[fim];
    v[fim] = aux;
    return i + 1;     
}

// funcao quickSorte
void quicksort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particao(v, inicio, fim);
        quicksort(v, inicio, p - 1);
        quicksort(v, p + 1, fim);
    }
}

int main() {
    int casos;                  
    scanf("%d", &casos);

    while (casos--) {
        int M;    // m representa a quantidade de elementos
        scanf("%d", &M);

        // vetor original e vetor ordenado
        int *original = (int*) malloc(M * sizeof(int));
        int *ordenado = (int*) malloc(M * sizeof(int));

        // faz a leitura no vetor original e depois passa para o vetor ordenado
        for (int i = 0; i < M; i++)
            scanf("%d", &original[i]);
        for (int i = 0; i < M; i++)
            ordenado[i] = original[i];

        // ordena o vetor copiado
        quicksort(ordenado, 0, M - 1);
        int cont = 0;           

        // for para comparar os dois vetores
        for (int i = 0; i < M; i++)
            if (ordenado[i] == original[i])
                cont++;

        printf("%d\n", cont);
        free(original);
        free(ordenado);
    }

    return 0;
}
