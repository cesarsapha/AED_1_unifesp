#include <stdio.h>
#include <stdlib.h>

int main (){
    int v, u, j, k;
    int cont, aux;
    int vagoes[50];
    scanf("%d",&v);
    for(int i = 0; i < v; i++){
        scanf("%d", &u);
        cont = 0;
        for(j = 0; j < u; j++){
            scanf("%d", &vagoes[j]);
          }
          for(j = 0; j < u; j++){
                for(k = j+1; k < u; k++){
                      if ( vagoes[j] > vagoes[k] ){
                           aux = vagoes[j];
                           vagoes[j] = vagoes[k];
                           vagoes[k] = aux;
                           cont++;
                      }
                }
          }
          printf("Optimal train swapping takes %d swaps.\n", cont);
    }
    return 0;
}