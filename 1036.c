#include <stdio.h>
//Calcular formula de bhaskara sem usar math.h//
int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = b * b - 4 * a * c;
    if (delta < 0 || a == 0) {
        printf("Impossivel calcular\n");
        return 0;
    }
    double n1 = (-b + sqrt(delta)) / (2 * a);
    double n2 = (-b - sqrt(delta)) / (2 * a);
    printf("R1 = %.5lf\nR2 = %.5lf\n", n1, n2);
    return 0;
}