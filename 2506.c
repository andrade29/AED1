#include <stdio.h>

// struct paciente
typedef struct {
    int chegada; 
    int critico; //tempo toleravel
} Paciente;

// proximo multiplo de 30
int proximoMeiaHora(int t) {
    if (t % 30 == 0) return t;
    return (t / 30 + 1) * 30;
}

int main() {
    int N;
    // lê enquanto houver casos de teste
    while(scanf("%d", &N) != EOF) {
        Paciente fila[25];

        // leitura dos pacientes e depois converte o horario para minutos
        for(int i = 0; i < N; i++) {
            int H, M, C;
            scanf("%d %d %d", &H, &M, &C);
            fila[i].chegada = H * 60 + M;
            fila[i].critico = C;
        }

        int horaMedico = 7 * 60;
        int criticos = 0;  // pacientes criticos

        // for para ir de paciente em paciente
        for(int i = 0; i < N; i++) {

            //aqui o medico espera o paciente se ele chegou antes
            if(fila[i].chegada > horaMedico)
                horaMedico = fila[i].chegada;

            // ajusta para prox horario
            horaMedico = proximoMeiaHora(horaMedico);
            // tempo excedeu o limite critico?
            if(horaMedico - fila[i].chegada > fila[i].critico)
                criticos++;
                
            // avança 30 minutos para o prox atendimento
            horaMedico += 30;
        }
        printf("%d\n", criticos);
    }
    return 0; 
}
