#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char carta[100005];
    scanf("%s", carta);

    int tamanho = strlen(carta);
    int encontrou = 0;

    // percorre a string
    for (int i = 0; i <= tamanho - 5; i++) {
        // checa se carta é o zelda
        if (tolower(carta[i])=='z' && tolower(carta[i+1])=='e' &&
            tolower(carta[i+2])=='l' && tolower(carta[i+3])=='d' &&
            tolower(carta[i+4])=='a') {
            encontrou = 1;
            break;
        }
    }

    if (encontrou){
        printf("Link Bolado\n");
    }else {
        printf("Link Tranquilo\n");
    }
    return 0;
}
