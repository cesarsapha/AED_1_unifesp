#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n, i, j;
    scanf("%d", &n);
    getchar();

    for (i =0; i<n; i++){
        int diamantes = 0;
        int retirado = 0;
        char teste[1001];  
        fgets(teste, 1001, stdin);  

        for (j = 0; teste[j] != '\n'; j++) {
            if (teste[j] == '<') {
                retirado++;
            } else if (teste[j] == '>') {
                if (retirado > 0) {
                    diamantes++;
                    retirado--;
                }
            }
        }
        printf("%d\n", diamantes);
    }
}