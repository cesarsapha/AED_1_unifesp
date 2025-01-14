#include <stdio.h>
 
int main() {
    double r;
    double a;

    scanf("%lf", &r);
  
    a = r*r*3.14159;
    printf("Area=%.4f\n",a);
    return 0;
}