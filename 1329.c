#include <stdio.h>

int main() {
    int N;  // n representa o numero de partidas
    
    // loop que roda enquanto e difrente de zero
    while(scanf("%d", &N) && N != 0) {
        int mary = 0, john = 0; 
        
        // for para os resultados da partida
        for(int i = 0; i < N; i++) {
            int resultado;
            scanf("%d", &resultado);
            
            if(resultado == 0){ //-> mary ganhou
                mary++;
            }
            else if(resultado == 1){ //-> john ganhou
                john++;
            }
        }
        printf("Mary won %d times and John won %d times\n", mary, john);
    }

    return 0;
}
