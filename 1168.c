//Contador LED BCD de 7 segmentos

#include <stdio.h>
#include <string.h>

int main() {
    int N, i, j;
    int led;
    char V[103];
    int config_leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

//Le o inteiro N

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%s", V);
        int tamanho = strlen(V);
        led = 0;
        for(j = 0; j < tamanho; j++) {
            led += config_leds[V[j] - '0'];
        }
        printf("%d led\n", led);
    }
    return 0;
}