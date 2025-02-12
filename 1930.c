#include <stdio.h>

int main() {
    int T1, T2, T3, T4;

    //Le os 3 valores
    scanf("%d %d %d %d", &T1, &T2, &T3, &T4);
    int soma = T1 + T2 + T3 + T4;

    // Retorna um unico numero inteiro
    int resposta = soma - 3;

    printf("%d\n", resposta);

    return 0;
}