#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[61];
    char color[10];
    char size;
} Camiseta;

//Funcao para comparar

int compare(const void *k, const void *j) {
    Camiseta *c1 = (Camiseta *)k;
    Camiseta *c2 = (Camiseta *)j;

    int compara = strcmp(c1->color, c2->color);
    if (compara == 0) {
        if (c1->size == c2->size) {
            return strcmp(c1->name, c2->name);
        }
        return c2->size - c1->size;
    }
    return compara;
}

int main() {
    int N;
    int primeiro = 1;

    while (scanf("%d", &N) && N != 0) {
        if (!primeiro) {
            printf("\n");
        }
        primeiro = 0;

        Camiseta camisetas[N];
        for (int i = 0; i < N; i++) {
            scanf(" %[^\n]s", camisetas[i].name); 
            scanf("%s %c", camisetas[i].color, &camisetas[i].size); 
        }

        qsort(camisetas, N, sizeof(Camiseta), compare);

        for (int i = 0; i < N; i++) {
            printf("%s %c %s\n", camisetas[i].color, camisetas[i].size, camisetas[i].name);
        }
    }
    return 0;
}