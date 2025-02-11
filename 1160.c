#include <stdio.h>

int main() {
    int T, i;
    scanf("%d", &T);

    for (   i = 0; i < T; i++) {
        int PA, PB, idade = 0;
        double G1, G2;
        scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);

        while (PA <= PB && idade <= 100) {
            PA += (int)(PA * (G1 / 100.0));
            PB += (int)(PB * (G2 / 100.0));
            idade++;
        }

        if (idade > 100) {
            printf("Mais de 1 século.\n");
        } else {
            printf("%d anos.\n", idade);
        }
    }
    return 0;
}