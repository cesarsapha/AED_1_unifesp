#include <stdio.h>
#include <stdlib.h>

//Utilizando o Mergesort

void merge(int array[], int temp[], int meio, int direita, int esquerda, int *contador) {
    int a, b, c;
    a = esquerda; 
    b = meio;  
    c = esquerda; 

    while ((a <= meio - 1) && (b <= direita)) {
        if (array[a] <= array[b]) {
            temp[c++] = array[a++];
        } 
        else {
            temp[c++] = array[b++];
            *contador += (meio - a); 
        }
    }

    while (a <= meio - 1) {
        temp[c++] = array[a++];
    }
    while (b <= direita) {
        temp[c++] = array[b++];
    }
    for (a = esquerda; a <= direita; a++) {
        array[a] = temp[a];
    }
}

// Separa entre direita e esquerda para definir o meio

void mergeSort(int array[], int temp[], int esquerda, int direita, int *contador) {
    int meio;
    if (direita > esquerda) {
        meio = (direita + esquerda) / 2;
        mergeSort(array, temp, esquerda, meio, contador);
        mergeSort(array, temp, meio + 1, direita, contador);
        merge(array, temp, esquerda, meio + 1, direita, contador);
    }
}

int main() {
    int N;
    
    while (scanf("%d", &N) && N != 0) {
        int *array = (int *)malloc(N * sizeof(int));
        int *temp = (int *)malloc(N * sizeof(int));

        // contador iniciado como 0

        int contador = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }

        mergeSort(array, temp, 0, N - 1, &contador);

        //Obtém a resposta 
        
        if (contador % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }

        //Limpa a memória
        free(array);
        free(temp);
    }

    return 0;
}