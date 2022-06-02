#include <math.h>
#include <stdio.h>

int main() {
    float x, y, z;
    printf("Enter the value of x: "); scanf("%f", &x);
    printf("Enter the value of y: "); scanf("%f", &y);
    printf("Enter the value of z: "); scanf("%f", &z);

    float F = (x+y+z) / (pow(x,2)+pow(y,2)+1) - (x-z*y);
    printf("Value of F = %f\n", F);

    return 0;
}
