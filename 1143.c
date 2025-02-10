#include <stdio.h>
 
int main() {
    //Recebe um inteiro N//
    int N;
    scanf("%d", &N);
    //for realiza a multiplicação//
    for(int i = 1; i <= N; i++){
        printf("%d %d %d\n", i, i*i, i*i*i);
    }
    return 0;
}