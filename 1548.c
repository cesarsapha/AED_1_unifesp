#include <stdio.h>
#include <stdlib.h>

int comparador(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N; 
    scanf("%d", &N);
    while (N--) {
        int M;
        scanf("%d", &M);
        int notas[1000];
        int ordena[1000];
        for (int i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
            ordena[i] = notas[i];
        }
        qsort(ordena, M, sizeof(int), comparador);
        int quantidade = 0;
        for (int i = 0; i < M; i++) {
            if (notas[i] == ordena[i]) {
                quantidade++;
            }
        }
        printf("%d\n", quantidade);
    }
}