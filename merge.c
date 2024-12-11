#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funcaointer(int p, int q, int r, int v[]){
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
void MergeSort(int p, int r, int v[]){
    if (p < r - 1){
        int q = (p + r)/2;

        MergeSort(p, q, v);
        MergeSort(q, r, v);
        funcaointer(p, q, r, v);
    }
}

int main(){
    int v[TAM];
    clock_t t;
    
    srand((unsigned)time(NULL));
    for (int i = 0; i < 400000; i++){
        v[i] = rand()%400000;
    }
    t = clock();
    MergeSort(0, 400000, v);
    t = clock() - t;

    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

}
