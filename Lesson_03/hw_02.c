#include <stdio.h>

int main() {

    float a, b, P, S;
    printf("Enter a: "); scanf("%f", &a);
    printf("Enter b: "); scanf("%f", &b);
    P = 2 * (a + b);
    S = a * b;
    printf("The Rectangle: perimeter = %f, area = %f\n", P, S);

    return 0;
}