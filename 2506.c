#include <stdio.h>

typedef struct {
    int chegada; 
    int critico; 
} Paciente;

int proximoMeiaHora(int t) {
    if (t % 30 == 0) return t;
    return (t / 30 + 1) * 30;
}

int main() {
    int N;
    while(scanf("%d", &N) != EOF) {
        Paciente fila[25];
        for(int i=0;i<N;i++) {
            int H, M, C;
            scanf("%d %d %d", &H, &M, &C);
            fila[i].chegada = H*60 + M;
            fila[i].critico = C;
        }

        int horaMedico = 7*60;
        int criticos = 0;

        for(int i=0;i<N;i++) {
            //medico está livre ou não
            if(fila[i].chegada > horaMedico)
                horaMedico = fila[i].chegada;

            horaMedico = proximoMeiaHora(horaMedico);
            if(horaMedico - fila[i].chegada > fila[i].critico)
                criticos++;

            horaMedico += 30; //proxatendimento
        }

        printf("%d\n", criticos);
    }
    return 0;
}
