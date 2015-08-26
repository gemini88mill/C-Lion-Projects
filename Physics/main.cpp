
#include <stdio.h>

#include "physics.h"

float find_force(int i);

void impact();

void motion();

int main(int argc, char *argv[]) {
    int mass = 5;

    float result = find_force(mass);
    printf("Force = %0.2f m/s", result);

    //impact equations
    impact();

    //one dimensional rocket problems
    motion();

    return 0;
}

void motion() {
    //
}

void impact() {
    //mass of object to be hit...
    int mass_wall = 5;
    int mass_object = 10;

    //Ft = m*deltaV

    //find force of object
    /**/

}

float find_force(int i) {
    float f;

    f = ACCELERATION * i;
    //printf("%f\n", f);

    return f;
}