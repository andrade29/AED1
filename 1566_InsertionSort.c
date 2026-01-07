#include <stdio.h>
#include <stdlib.h>

// funcao insertionSort
void insertion(int array[], int n){
    for(int i = 1; i < n; i++){
        int chave = array[i];  
        int j = i - 1;

        // elementos maiores a direita
        while(j >= 0 && array[j] > chave){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = chave;
    }
}

int main(){
    int casos; // casos testes
    scanf("%d", &casos);

    while(casos--){
        int pessoas;
        scanf("%d", &pessoas);

        // aloca o vetor e depois faz a leitura dos valores
        int *array_pessoas = (int*) malloc(pessoas * sizeof(int));
        for(int i = 0; i < pessoas; i++){
            scanf("%d", &array_pessoas[i]);
        }

        // ordena
        insertion(array_pessoas, pessoas);

        // for para mostrar os valores ordenados
        for(int i = 0; i < pessoas; i++){
            printf("%d", array_pessoas[i]);
            if(i < pessoas - 1) printf(" ");
        }
        printf("\n");
        free(array_pessoas); 
    }
}
