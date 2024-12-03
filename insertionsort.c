#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertion_sort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

double measure_time(void (*sort_function)(int[], int), int arr[], int n) {
    clock_t start, end;
    start = clock();
    sort_function(arr, n);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
}

int main() {
    FILE *file = fopen("dados_comparacao.csv", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(file, "n,InsertionSort,MergeSort\n");

    for (int n = 50000; n <= 400000; n += 50000) {
        int *arr_insertion = (int *)malloc(n * sizeof(int));
        int *arr_merge = (int *)malloc(n * sizeof(int));

        generate_random_array(arr_insertion, n);
        for (int i = 0; i < n; i++) arr_merge[i] = arr_insertion[i];

        double insertion_time = measure_time(insertion_sort, arr_insertion, n);

        double merge_time = measure_time(merge_sort, arr_merge, n);

        fprintf(file, "%d,%f,%f\n", n, insertion_time, merge_time);

        free(arr_insertion);
        free(arr_merge);
    }

    fclose(file);

    printf("Dados salvos em 'dados_comparacao.csv'.\n");
    return 0;
}
