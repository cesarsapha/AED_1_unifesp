#include <stdio.h>

int main(){
    int N, fatorial, i;

    scanf("%d", &N);

    fatorial = 1;

    for (i = 1; i<=N; i++){
        fatorial *= i;
    }
    printf("%d\n", fatorial);
    return 0;
}