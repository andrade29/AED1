#include <stdio.h>
#include <stdlib.h>

// merge de duas listas
void merge(int vetor[], int esq, int meio, int dir) {
    int tamEsq = meio - esq + 1;
    int tamDir = dir - meio;

    int *vetEsq = (int*) malloc(tamEsq * sizeof(int));
    int *vetDir = (int*) malloc(tamDir * sizeof(int));

    for (int i = 0; i < tamEsq; i++) vetEsq[i] = vetor[esq + i];
    for (int i = 0; i < tamDir; i++) vetDir[i] = vetor[meio + 1 + i];

    int i = 0, j = 0, k = esq;

    // loop que intercala mas mantem a ordem
    while (i < tamEsq && j < tamDir) {
        if (vetEsq[i] <= vetDir[j])
            vetor[k++] = vetEsq[i++];
        else
            vetor[k++] = vetDir[j++];
    }

    // copia os elementos restantes
    while (i < tamEsq) vetor[k++] = vetEsq[i++];
    while (j < tamDir) vetor[k++] = vetDir[j++];

    free(vetEsq);
    free(vetDir);
}

// funcao mergeSort
void mergeSort(int vetor[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort(vetor, esq, meio);
        mergeSort(vetor, meio + 1, dir);
        merge(vetor, esq, meio, dir);
    }
}

int main() {
    int casos;  // casos testes
    scanf("%d", &casos);

    // loop para cada caso
    while (casos--) {
        int pessoas;     
        scanf("%d", &pessoas);

        // aloca o vetor e depois le os valores de altura
        int *alturas = (int*) malloc(pessoas * sizeof(int));
        for (int i = 0; i < pessoas; i++) {
            scanf("%d", &alturas[i]);
        }
        // ordena usando mergesort
        mergeSort(alturas, 0, pessoas - 1);

        // imprime o vetor ordenado
        for (int i = 0; i < pessoas; i++) {
            printf("%d", alturas[i]);
            if (i < pessoas - 1) printf(" ");
        }
        printf("\n");
        free(alturas);
    }
    return 0;  
}
