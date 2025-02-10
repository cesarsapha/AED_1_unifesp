#include <stdio.h>

int main () {
    int tempo_s, hrs, min, seg;

    scanf("%d", &tempo_s);

    hrs = tempo_s / 3600;
    min = (tempo_s % 3600) / 60;
    seg = (tempo_s % 3600) % 60;
    
    printf("%d:%d:%d\n", hrs, min, seg);
}