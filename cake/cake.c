#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double find_perimeter(double area);

int main() {
    //printf("hello world this is cake");
    int input_cases, i;
    double input;
    double result;

    scanf("%d", &input_cases);

    for(i = 0; i < input_cases; i++) {
        scanf("%lf", &input);
        result = find_perimeter(input);
        printf("%f\n", result);
    }

    return 0;
}

double find_perimeter(double area){
    double perim = 0;
    double side = 0;

    /*logic: given AREA, find minimum perimeter
     *  minimum perimeter = square
     *  square = AREA = x^2
     *  side = root(AREA)
     *  2(side + 2(side) = Perimeter*/

    side = sqrt(area);
    //printf("side: %0.0f", side);
    perim = (2*side + 2*side);

    return perim;
}