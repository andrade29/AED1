#include <stdio.h>
#include <stdlib.h>

// funcao selectionSort
void selectionSort(int array[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min_idx = i; // menor elemento na lista

        // for para procurar o menor elemento
        for(int j = i+1; j < n; j++) {
            if(array[j] < array[min_idx]) {
                min_idx = j;
            }
        }

        // faz a troca do menor encontrado com o atual
        int temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }
}

int main(){
    int casos;                
    scanf("%d", &casos);

    while(casos--){
        int pessoas;          
        scanf("%d", &pessoas);

        // aloca o vetor e faz a leitura dos valores
        int *array_pessoas = (int*) malloc(pessoas * sizeof(int));
        for(int i = 0; i < pessoas; i++){
            scanf("%d", &array_pessoas[i]);
        }
        // ordena usando selection sort
        selectionSort(array_pessoas, pessoas);

        // imprime o vetor ordenado
        for(int i = 0; i < pessoas; i++){
            printf("%d", array_pessoas[i]);
            if(i < pessoas - 1) printf(" ");
        }
        printf("\n");
        free(array_pessoas);  
    }
}
