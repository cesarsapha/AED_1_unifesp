#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i, j, x, v[400000];
    clock_t t;

    srand((unsigned)time(NULL));

    for (int i = 0; i < 400000; i++){
        v[i] = rand()%400000;
    }
    
    t = clock();
    for (i = 1; i < 400000; i++){
        x = v[i];
        for (j = i-1; j >= 0 && v[j] > x; j--){
            v[j+1] = v[j];
        }

    v[j+1] = x;
    }
    t = clock() - t;
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
}
