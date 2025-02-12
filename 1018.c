#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    //valor lido
    printf("%d\n", N);
    
    char notas[] = {100, 50, 20, 10, 5, 2, 1};
    int i;

    for (i = 0; i < 7; i++) {
        int qntd = N / notas[i];  
        N %= notas[i];  
        
        printf("%d nota(s) de R$ %s,00\n", qntd, notas[i]);
    }
    
    return 0;
}