#include <string.h>
#include <stdio.h>
#include <ctype.h>

//Utilizando a tabela ASCII

int main(){
    int N, num, i;
    char aux, M[1001];

    scanf("%d\n", &N);

    for(i = 0; i < N; i++){
        scanf("%[^\n]\n", &M);

        num = strlen(M);
        for(int j = 0; j < num; j++){
            if(isalpha(M[j])){
                M[j] += 3;
            }
        }
        for(int j = 0; j < num/2; j++){
            aux = M[j];
            M[j] = M[num - 1 - j];
            M[num - 1 - j] = aux;
        }
        for(int j = num/2; j < num; j++){
            --M[j];
        }

        printf("%s\n", M);
    }

    return 0;
}