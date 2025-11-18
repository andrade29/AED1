#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int i;

        // verificação para saber se é possível ser uma das trêsw
        int possivel_stack = 1;
        int possivel_queue = 1;
        int possivel_pq = 1;

        // pilha simples
        int pilha[1000];
        int top = -1;

        // fila simples
        int fila[1000];
        int inicio = 0, fim = 0;

        // simulação de fila de prioridade
        int pq[1000];
        int tamanho_pq = 0;

        for (i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) {
                // inserir elemento
                if (possivel_stack) pilha[++top] = x;
                if (possivel_queue) fila[fim++] = x;
                if (possivel_pq) pq[tamanho_pq++] = x;
            } else if (op == 2) {
                // remover elemento
                if (possivel_stack) {
                    if (top >= 0 && pilha[top] == x) {
                        top--;
                    } else {
                        possivel_stack = 0;
                    }
                }

                if (possivel_queue) {
                    if (inicio < fim && fila[inicio] == x) {
                        inicio++;
                    } else {
                        possivel_queue = 0;
                    }
                }

                if (possivel_pq) {
                    if (tamanho_pq > 0) {
                        // encontra o maior elemento
                        int max = 0, indice = 0;
                        for (int j = 0; j < tamanho_pq; j++) {
                            if (pq[j] > max) {
                                max = pq[j];
                                indice = j;
                            }
                        }
                        if (max == x) {
                            // remove o max
                            for (int j = indice; j < tamanho_pq - 1; j++) {
                                pq[j] = pq[j + 1];
                            }
                            tamanho_pq--;
                        } else {
                            possivel_pq = 0;
                        }
                    } else {
                        possivel_pq = 0;
                    }
                }
            }
        }

        int soma = possivel_stack + possivel_queue + possivel_pq;
        if (soma == 0) {
            printf("impossible\n");
        } else if (soma > 1) {
            printf("not sure\n");
        } else {
            if (possivel_stack) printf("stack\n");
            else if (possivel_queue) printf("queue\n");
            else if (possivel_pq) printf("priority queue\n");
        }
    }

    return 0;
}
