#include <stdio.h>
#include <string.h>

int main() {
    char palavra[105];

    while (scanf("%s", palavra) == 1) {
        int len = strlen(palavra);

        //láco para cada linha do triagulo
        for (int i = 0; i < len; i++) {
            // imprime i espaços iniciais
            for (int s = 0; s < i; s++) printf(" ");
            //imprime as letras restantes
            for (int j = 0; j < len - i; j++) {
                printf("%c", palavra[j]);
                if (j != len - i - 1) printf(" "); 
            }
            printf("\n");
        }



        printf("\n");
    }

    return 0;
}
