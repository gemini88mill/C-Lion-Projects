#include <stdio.h>
#include <stdlib.h>



int main() {
    char buff[15]; //buffer for input read
    int sequence, i;

    scanf("%i", &sequence); //reads the number of sequences to be collected
    for(i = 0; i < sequence; i++){
        scanf("%s", buff); //reads buff as string
        printf("%s\n", buff);
    }

    return 0;
}