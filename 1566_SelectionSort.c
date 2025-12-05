#include <stdio.h>
#include <stdlib.h>

void selectionSort(int array[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min_idx = i; // índice do menor elemento na sublista restante
        for(int j = i+1; j < n; j++) {
            if(array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        // troca o menor encontrado com o primeiro elemento da sublista
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

        int *array_pessoas = (int*) malloc(pessoas * sizeof(int));
        
        for(int i =0; i < pessoas; i++){
            scanf("%d", &array_pessoas[i]);
        }

        selectionSort(array_pessoas, pessoas);

        for(int i=0; i < pessoas; i++){
            printf("%d ", array_pessoas[i]);
            if(i < pessoas - 1) printf(" ");
        }
        printf("\n");

        free(array_pessoas);
    }




}