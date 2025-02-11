#include <stdio.h>

int main() {

    int N, K;
    scanf("%d", &N);

    if (N == 1){
        K = 1;
    }else if (N > 1 && N <= 3){
        K = 3;
    }else if (N > 3 && N <= 5){
        K = 5;
    }else if (N > 5 && N <= 10){
        K = 10;
    }else if (N > 10 && N <= 25){
        K = 25;
    }else if (N > 25 && N <= 50){
        K = 50;
    }else K = 100;

    printf("Top %i\n", K);

    return 0;
}