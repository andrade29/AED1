#include <stdio.h>

int main() {
    int R;
    while(scanf("%d", &R) && R != 0) {
        int mark[10], leti[10];
        for(int i=0;i<R;i++) scanf("%d", &mark[i]);
        for(int i=0;i<R;i++) scanf("%d", &leti[i]);

        int pontosMark = 0, pontosLeti = 0;
        int bonusAplicado = 0;

        for(int i=0;i<R;i++) {
            pontosMark += mark[i];
            pontosLeti += leti[i];
        //aplica a regra do bônus
            if(!bonusAplicado && i >= 2) {
                int mark3 = (mark[i]==mark[i-1] && mark[i]==mark[i-2]);
                int leti3 = (leti[i]==leti[i-1] && leti[i]==leti[i-2]);

                if(mark3 && !leti3) {
                    pontosMark += 30;
                    bonusAplicado = 1;
                } else if(!mark3 && leti3) {
                    pontosLeti += 30;
                    bonusAplicado = 1;
                } else if(mark3 && leti3) {
                    //se ambos repetirem na mesma rodada, ninguém ganha
                    bonusAplicado = 1;
                }
            }
        }

        if(pontosMark > pontosLeti) printf("M\n");
        else if(pontosLeti > pontosMark) printf("L\n");
        else printf("T\n");
    }
    return 0;
}
