#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A 0
#define C 1
#define G 2
#define T 3
#define BASE 4


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
    int i, index = 0; //looper
    int base_four_num[16] = {0};  //converted number

    //convert to int
    int base_10_num = atoi(buff); //number to convert
    //convert to base 4

    while (base_10_num != 0) {
        base_four_num[index] = base_10_num % BASE;
        base_10_num = base_10_num / 4;
        index++;
    }

    for(i = index; i >= 0; i--){
        printf("%d ", base_four_num[i]);

    }

}

void convert_to_base_ten(char buff[15]) {
    //convert to base ten number.
    printf("hello 10");
}