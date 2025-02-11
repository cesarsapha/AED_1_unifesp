#include <stdio.h>

//Funcao para ler o numero de regioes
int crise(int n) {
    int m = 1, i;
    while (1) {
        int corrente = 0;
        for (i = 1; i < n; i++)
            corrente = (corrente + m) % i;
        if (corrente == 11)
            return m;
        m++;
    }
}

int main() {
    int N;
    while (scanf("%d", &N) && N != 0)
        printf("%d\n", crise(N));
    return 0;
}