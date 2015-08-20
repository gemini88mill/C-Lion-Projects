
#include <stdio.h>

#include "physics.h"

float find_force(int i);

int main(int argc, char *argv[]) {
    int mass = 5;

   // printf("%d", ACCELERATION);

    //int forca = mass * ACCELERATION;

    float result = find_force(mass);

    printf("Force = %0.2f m/s", result);
   // printf("Forca = %i\n", forca);
    return 0;
}

float find_force(int i) {
    float f;

    f = ACCELERATION * i;
    //printf("%f\n", f);

    return f;
}