#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 400000

void intercala(int p, int q, int r, int v[]){
    int *w, i=p, j=q, k=0;
    w = malloc((r-p)*sizeof(int));

    while (i < q && j < r){
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }

    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    
    for (i = p; i < r; i++) v[i] = w[i-p];
    
    free(w);
}

void mergeSort(int p, int r, int v[]){
    if (p < r - 1){
        int q = (p + r)/2;

        mergeSort(p, q, v);
        mergeSort(q, r, v);
        intercala(p, q, r, v);//Outra função que vai ordenar as duas metades do vetor v e as organiza
    }
}

int main(){
    int v[TAM];
    clock_t t;
    
    //aleatoriedade
    srand((unsigned)time(NULL));

    //adiciona valores no vetor
    for (int i = 0; i < TAM; i++){
        v[i] = rand()%TAM;
    }

    //armazena o 
    t = clock();
    mergeSort(0, TAM, v);
    t = clock() - t;

    printf("Tempo de execucao: %.6lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

}