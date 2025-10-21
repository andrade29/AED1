#include <stdio.h>
#include <string.h>

#define N 1000

char expressao[N]; 
char pilha[N];     
int topo;          

//função para empilhar o elemento ( no vetor estático
void empilha(char x){
    pilha[++topo] = x;
}

//função para desempilhar o elemento '(' quando encontrar um ')'
//também verifica se o vetor é vazio
char desempilha(void){
    if(topo >= 0)
        return pilha[topo--];
    else
        return '\0';
}

int main(){
    while(fgets(expressao, N, stdin) != NULL){
        topo = -1;

        //remove o '\0' que o fgets recebe
        size_t len = strlen(expressao);
        if(len > 0 && expressao[len-1] == '\n')
            expressao[len-1] = '\0';

        int incorreto = 0;

        //looping para percorrer o vetor e empilhar e desempilhar
        for(int i = 0; expressao[i] != '\0'; i++){
            if(expressao[i] == '(')
                empilha('(');
            else if(expressao[i] == ')'){
                if(topo == -1){
                    incorreto = 1;
                    break;
                }
                desempilha();
            }
        }

        //verifica se sobrou algum parenteses ou houve algum erro
        if(incorreto || topo != -1)
            printf("incorrect\n");
        else
            printf("correct\n");
    }

    return 0;
}
