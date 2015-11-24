#include <stdio.h>
#include <stdlib.h>

#define A 0
#define C 1
#define G 2
#define T 3


void convert_to_base_ten(char buff[15]);

void convert_to_gen_code(char buff[15]);

int main() {
    char buff[15]; //buffer for input read
    int sequence, i;

    scanf("%i", &sequence); //reads the number of sequences to be collected
    for(i = 0; i < sequence; i++){
        scanf("%s", buff); //reads buff as string
        printf("Sequence #%d: ", i + 1);
        if(atoi(buff) == 0){
            convert_to_base_ten(buff);
        } else{
            convert_to_gen_code(buff);
        }
        printf("\n");
    }

    return 0;
}

void convert_to_gen_code(char buff[15]) {
    //converts string received into GATTACA genetic code
    
}

void convert_to_base_ten(char buff[15]) {
    //convert to base ten number.
    printf("hello 10");
}