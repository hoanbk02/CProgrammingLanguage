#include <stdio.h>

int main() {
    int dad, mom, bro, me;
    printf("Enter age of dad: "); scanf("%d", &dad);
    printf("Enter age of mom: "); scanf("%d", &mom);
    printf("Enter age of bro: "); scanf("%d", &bro);
    printf("Enter age of me: "); scanf("%d", &me);

    int sum_age = dad + mom + bro + me;
    printf("Sum of age: %d\n", sum_age);

    int time_age = dad * mom * bro * me;
    printf("Time of age: %d\n", time_age);

    float avg_age = sum_age / 4.0;
    printf("Avg of age: %f\n", avg_age);

    return 0;
}