#include <stdio.h>

int main (){

  int N, i, y;
  scanf("%d", &N);

  for (i = 1; i <= 10000; i++){
    if (i % N == 2){

      N = i;  
      printf("%d\n", N);

    }
  }
}