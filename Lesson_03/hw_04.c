#include <math.h>
#include <stdio.h>

int main() {
    float x, y, z, A, B, C, f, e, r;
    printf("Enter x = "); scanf("%f", &x);
    printf("Enter y = "); scanf("%f", &y);
    printf("Enter z = "); scanf("%f", &z);

    A = pow(x + y + z, 2);
    B = pow(x, 2) + pow(y, 2) + pow(z, 2);
    C = x*y + y*z + z*x;
    f = A - B - 2*C;

    printf("(x+y+z)^2 = %f \nx^2+y^2+z^2 = %f\nxy+yz+zx = %f\n", A, B, C);
    printf("(x+y+z)^2 - (x^2+y^2+z^2 + 2*(xy+yz+zx)) = %f\n", f);

    return 0;
}