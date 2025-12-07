#include <stdio.h>

int main() {
    int N;
    
    while(scanf("%d", &N) && N != 0) {
        int mary = 0, john = 0;
        for(int i = 0; i < N; i++) {
            int resultado;
            scanf("%d", &resultado);
            if(resultado == 0){
                mary++;
            }
            else if(resultado == 1){
                john++;
            }
        }
        printf("Mary won %d times and John won %d times\n", mary, john);
    }

    return 0;
}
