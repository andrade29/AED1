#include <stdio.h>

int main() {
    int vetor[10];
    int variavel_vetor;

    
    
    for (variavel_vetor = 0; variavel_vetor < 10; variavel_vetor++) {
        scanf("%d", &vetor[variavel_vetor]);
    }

    
    for (variavel_vetor = 0; variavel_vetor < 10; variavel_vetor++) {
        if (vetor[variavel_vetor] <= 0) {
            vetor[variavel_vetor] = 1;
        }
    }

    
    for (variavel_vetor = 0; variavel_vetor < 10; variavel_vetor++) {
        printf("X[%d] = %d\n", variavel_vetor, vetor[variavel_vetor]);
    

    }
    return 0;
}