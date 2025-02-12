#include <stdio.h>

int main() {
    int hi, mi, hf, mf;

    //Le os 4 numeros inteiros
    scanf("%d %d %d %d", &hi, &mi, &hf, &mf);

    int duracao_min = (hf * 60 + mf) - (hi * 60 + mi);

    if (duracao_min < 0) {
        duracao_min += 24 * 60;
    }
    if (duracao_min == 0) {
        duracao_min = 24 * 60;
    }

    //faz a conversao de tempo
    int duracao_hrs = duracao_min / 60;
    int duracao_restante = duracao_min % 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao_hrs, duracao_restante);

    return 0;
}