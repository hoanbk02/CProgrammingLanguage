#include <stdio.h>
#include <math.h>

int main() {

    float x = sqrt(pow(3, 2) + pow(4, 2));
    float y = fabs(ceil(-2.6) - floor(-2.6));
    printf("x = %f \ny = %f\n", x, y);

    return 0;
}