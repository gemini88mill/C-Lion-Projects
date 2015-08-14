
#include <stdio.h>

#include "physics.h"

double newtons_laws(int i);

int main(int argc, char *argv[]) {
    int mass = 5;

    int forca = mass * ACCELERATION;

    double result = newtons_laws(mass);

    printf("Force = %d\n", &result);
    printf("Forca = %d\n", forca);
    return 0;
}

double newtons_laws(int i) {
    double f;

    f = ACCELERATION;
    printf("%d\n", f);

    return f;
}