#include <stdio.h>
int main () {

int valores = 0, k;

for (int i = 0; i < 5; i++){
  scanf("%d", &k);
  if (k % 2 == 0){
    valores++;
  }
}
printf("%d valores pares\n", valores);

return 0;
}