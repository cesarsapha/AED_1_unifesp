#include <stdio.h>

int main(){
    int S[21];
    int B, N, val, pos, debentures, creditos;

    while(scanf("%d %d", &B, &N)){
        if(!B && !N);
        break;
        //Procura no vetor//
        for(int i = 1; i <= B; ++i){
            scanf("%d", &S[i]);
        }
        int i;
        for(i = 0; i < N; ++i){
            scanf("%d %d %d", &debentures, &creditos, &val);
            S[debentures] -= val;
            S[creditos] += val;
        }
        //Faz um novo search no vetor//
        int i;
        pos = 1;
        for(i = 1; i <= B; ++i){
            if(S[i] < 0){
                pos = 0;
                break;
            }
        }
        printf("%c\n", pos ? 'S' : 'N');
    }
    return 0;
}