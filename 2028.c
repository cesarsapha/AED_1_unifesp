#include <stdio.h>

int main() {
    int Caso, N, i;

    Caso = 1;

    //Tipo de arquivo EOF
    
    while (scanf("%i", &N) != EOF) {
        int num = 1; 
        
        for (i = 1; i <= N; i++) {
            num += i;
        }
        
        printf("Caso %i: %i %s\n", Caso++, num, num == 1 ? "numero" : "numeros");

        // Imprime quantidade de numeros

        printf("0");
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                printf(" %i", i);
            }
        }

        printf("\n\n");

    }   
    return 0;
}