#include <stdio.h>
#include <stdbool.h>

bool verify(int matriz[9][9]) {
    
    for (int i = 0; i < 9; i++) {
        
        bool linha[9] = {false};
        for (int j = 0; j < 9; j++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || linha[num - 1]) {
                return false;
            }
            linha[num - 1] = true;
        }

        bool col[9] = {false};
        for (int j = 0; j < 9; j++) {
            int num = matriz[j][i];
            if (col[num - 1]) {
                return false;
            }
            col[num - 1] = true;
        }
    }

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            bool mat[9] = {false};
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    int num = matriz[k][l];
                    if (mat[num - 1]) {
                        return false;
                    }
                    mat[num - 1] = true;
                }
            }
        }
    }

    return true; 
}

int main() {
    int n;
    scanf("%d", &n);

    for (int inst = 1; inst <= n; inst++) {
        int matriz[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        bool correto = verify(matriz);

        printf("Instancia %d\n", inst);
        printf("%s\n\n", correto ? "SIM" : "NAO");
    }

    return 0;
}
