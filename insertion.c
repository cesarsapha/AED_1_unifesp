#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 400000

int main(){
    int i, j, x, v[TAM];
    clock_t t;

    //aleatoriedade
    srand((unsigned)time(NULL));

    //adiciona valores no vetor
    for (int i = 0; i < TAM; i++){
        v[i] = rand()%TAM;
    }
    
    t = clock();
    //ordena o vetor por meio do insertionSort
    for (i = 1; i < TAM; i++){
        x = v[i];

        for (j = i-1; j >= 0 && v[j] > x; j--){
            v[j+1] = v[j];
        }

    v[j+1] = x;
        
    }

    t = clock() - t;

    printf("Tempo de execucao: %.6lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
}