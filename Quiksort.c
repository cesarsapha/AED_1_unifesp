#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int troca(int v[], int baixo, int alto) {
    int primeiro = v[alto]; 
    int i = baixo - 1; 
    for (int j = baixo; j < alto; j++) {
        if (v[j] <= primeiro) {
            i++;
            int tempo = v[i];
            v[i] = v[j];
            v[j] = tempo;
        }
    }
    int tempo = v[i + 1];
    v[i + 1] = v[alto];
    v[alto] = tempo;
    return i + 1;
}
void QuickSort(int v[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = troca(v, baixo, alto);
        QuickSort(v, baixo, pi - 1);
        QuickSort(v, pi + 1, alto);
    }
}
int main() {
    clock_t t;
    int vetor[50000];

    srand((unsigned)time(NULL));
    for (int a = 0; a < 50000; a++) {
        vetor[a] = rand() % 50000;
    }
    t = clock();
    QuickSort(vetor, 0, 50000 - 1);
    t = clock() - t;

    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
    return 0;
}
