#include <stdio.h>

int main() {
    int pedras, M;
    int i = 2, j = 1, k = 0;
    
    while (scanf("%i %i", &pedras, &M) == 2) {
        if (pedras == 0 && M == 0) {
            break;
        }

        if (M > 34) {
            printf("Let me try!\n");
        } else {
            while (j > 0 && j <= pedras) {
                if (j == M) { 
                    k++;
                    break;
                }
                else if (j < M) {
                    if (j + (2 * i - 1) <= pedras) {
                        j += 2 * i - 1;
                    } else {
                        j -= 2 * i - 1;
                    }
                    i++;
                }
                else {
                    if (j - (2 * i - 1) > 0) {
                        j -= 2 * i - 1;
                    } else {
                        j += 2 * i - 1;
                    }
                    i++;
                }
            }
            if (k != 0) {
                printf("Let me try!\n");
            } else {
                printf("Don't make fun of me!\n");
            }
        }
    }
    return 0;
}