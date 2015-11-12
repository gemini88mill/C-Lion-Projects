#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int find_perimeter(int area);

int main() {
    printf("hello world this is cake");

    find_perimeter(169);

    return 0;
}

int find_perimeter(int area){
    int perim = 0;
    double side = 0;

    /*logic: given AREA, find minimum perimeter
     *  minimum perimeter = square
     *  square = AREA = x^2
     *  side = root(AREA)
     *  2(side + 2(side) = Perimeter*/

    side = sqrt(area);
    printf("side: %0.0f", side);

    return perim;
}