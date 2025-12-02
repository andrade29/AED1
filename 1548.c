#include <stdio.h>
#include <stdlib.h>


int comparar(const void *a, const void *b) { //função comparar para usar no qsort
    int x = *(int*)a;
    int y = *(int*)b;

    return y - x;
}

int main(){

    int M, casos;
    scanf("%d", &casos);

    for(int i=0; i<casos; i++){ //loop com o total de casos

        scanf("%d", &M);
        int cont = 0;
        int original[M];
        int ordenada[M];

        for(int i=0; i<M; i++){ //alocando as notas
            scanf("%d", &original[i]);
    }
        for(int i=0; i<M; i++){ //copiando a lista para comparar
            ordenada[i] = original[i];
        }
       
        qsort(ordenada, M, sizeof(int), comparar);

        for(int i=0; i<M; i++){ //comparando as listas
            if(ordenada[i] == original[i]){
            cont += 1;
        }
    }
    printf("%d\n", cont);
}
   
}