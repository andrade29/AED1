#include <stdio.h>
#include <stdlib.h>
#define N 1000
//cria um vetor auxiliar para receber a expressão
char expressao[N];
//estrutura da pilha
typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

typedef struct PILHA{
    NO *topo;
}PILHA;

void incializarPilha(PILHA *p){
    p->topo = NULL;
}
//função empilhar
void empilha(int dado, PILHA *p){
    NO *novo = (NO*) malloc(sizeof(NO));
    if(novo == NULL){
        return;
    }
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
    
}
//função desempilhar
void desempilha(PILHA *p){
    NO *remove = p->topo;
    if(p->topo == NULL){
        return;
    }
    p->topo = remove->prox;
    free(remove);
}

int main(){

    //aloca dinamicamente e inicializa a pilha
    PILHA *p1 = (PILHA*) malloc(sizeof(PILHA));
    incializarPilha(p1);
    //recebe as expressões do enunciado
    while(fgets(expressao, N, stdin) != NULL){
        int incorreto = 0;
        //verifica cada expressão e verifica se pode empilhar e desempilhar, caso esteja incorreto, da break
        for(int i = 0; expressao[i] != '\0'; i++){
            if(expressao[i] == '('){
                empilha(expressao[i], p1);
            }
            else if(expressao[i] == ')'){
                if(p1->topo == NULL){
                    incorreto = 1;
                    break;
                }
                desempilha(p1);
            }
        }
        //verifica se está tudo correto
        if(incorreto == 1 || p1->topo != NULL){
            printf("incorrect\n");
        }else{
            printf("correct\n");
        }

        while (p1->topo != NULL) {
            desempilha(p1);
}

    }
    //libera
    free(p1);
}
