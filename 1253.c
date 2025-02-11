// Cifra De César

#include <string.h>
#include <stdio.h>

int main(){

    int N, operacao, i;
    char cifra[51];

    scanf("%d\n", &N);

    for(i = 0; i < N; ++i){
        scanf("%[^\n]\n", &cifra);
        scanf("%d\n", &operacao);

        //le o numero de caracteres e verifica com as letras do alfabeto
        for(int j = 0; j < strlen(cifra); ++j){
            cifra[j] = ((cifra[j] - 'A' - operacao + 26) % 26) + 'A';
        }
        //imprime a cifra
        printf("%s\n", cifra);
    }
    return 0;
}