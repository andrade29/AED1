#include <stdio.h>
#include <stdlib.h>

//ajusta o max heap
void heapify(int arr[], int n, int i) {
    int largest = i;      // raiz
    int l = 2*i + 1;      // filho esquerdo
    int r = 2*i + 2;      // filho direito

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

//função heapSort
void heapSort(int arr[], int n) {
    //max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrair elementos do heap um por um
    for (int i = n-1; i > 0; i--) {
    
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int pessoas;
        scanf("%d", &pessoas);

        int *alturas = (int*) malloc(pessoas * sizeof(int));
        for (int i = 0; i < pessoas; i++)
            scanf("%d", &alturas[i]);

        heapSort(alturas, pessoas);

        for (int i = 0; i < pessoas; i++) {
            printf("%d", alturas[i]);
            if (i < pessoas - 1) printf(" ");
        }
        printf("\n");

        free(alturas);
    }

    return 0;
}
