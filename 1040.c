#include <stdio.h>

int main() {
    double N1, N2, N3, N4, media, exame, final;

    scanf("%lf %lf %lf %lf", &N1, &N2, &N3, &N4);

    media = ((N1 * 2) + (N2 * 3) + (N3 * 4) + (N4 * 1)) / 10;
    printf("Media: %.1lf\n", media);

    if (media >= 7.0) {
        printf("Aluno aprovado.\n");
    } 
    else if (media < 5.0) {
        printf("Aluno reprovado.\n");
    } 
    else {
        printf("Aluno em exame.\n");
        scanf("%lf", &exame);
        printf("Nota do exame: %.1lf\n", exame);

        final = (media + exame) / 2.0;

        if (final >= 5.0) {
            printf("Aluno aprovado.\n");
        } else {
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1lf\n", final);
    }
    return 0;
}