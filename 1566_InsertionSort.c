#include <stdio.h>
#include <stdlib.h>

void insertion(int array[], int n){
    for(int i = 1; i < n; i++){
        int chave = array[i];
        int j = i - 1;

    while(j >= 0 && array[j] > chave){
        array[j+1] = array[j];
        j--;
    }
    array[j+1] = chave;
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

        insertion(array_pessoas, pessoas);

        for(int i=0; i < pessoas; i++){
            printf("%d ", array_pessoas[i]);
            if(i < pessoas - 1) printf(" ");
        }
        printf("\n");

        free(array_pessoas);
    }




}