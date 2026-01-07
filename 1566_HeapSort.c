#include <stdio.h>
#include <stdlib.h>

// max heap inicia em i
void heapify(int vetor[], int n, int i) {
    int maior = i;      // maior elemento
    int esq = 2*i + 1;     
    int dir = 2*i + 2;      

    // esq é maior?
    if (esq < n && vetor[esq] > vetor[maior])
        maior = esq;

    // dir é maior?
    if (dir < n && vetor[dir] > vetor[maior])
        maior = dir;

    // raiz != de maior, continua mudando
    if (maior != i) {
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;

        heapify(vetor, n, maior);
    }
}

// funcao heap
void heapSort(int vetor[], int n) {
    // for para o max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(vetor, n, i);

    // remove um a um
    for (int i = n-1; i > 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        heapify(vetor, i, 0);
    }
}

int main() {
    int casos;  // numero de casos testes
    scanf("%d", &casos);

    while (casos--) {
        int pessoas; 
        scanf("%d", &pessoas);

        // alocando
        int *alturas = (int*) malloc(pessoas * sizeof(int));
        for (int i = 0; i < pessoas; i++)
            scanf("%d", &alturas[i]);

        // heap ordena as alturas
        heapSort(alturas, pessoas);

        // for para imprimir de forma ordenada
        for (int i = 0; i < pessoas; i++) {
            printf("%d", alturas[i]);
            if (i < pessoas - 1) printf(" ");
        }
        printf("\n");
        free(alturas);  
    }

    return 0;  
}
