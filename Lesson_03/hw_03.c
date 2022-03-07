#include <math.h>
#include <stdio.h>

int main() {

    float X, Y, A, B, C, D;
    printf("Enter X = "); scanf("%f", &X);
    printf("Enter Y = "); scanf("%f", &Y);
    
    A = pow(X+Y, 2);
    B = pow(X-Y, 2);
    C = X * Y;
    D = A - B - 4*C;
    printf("(X+Y)^2 = %f \n(X-Y)^2 = %f \nXY = %f\n", A, B, C);
    printf("(X+Y)^2 - (X-Y)^2 - 4XY = %f\n", D);

    return 0;
}