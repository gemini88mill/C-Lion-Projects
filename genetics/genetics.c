#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
        //printf("%d ", base_four_num[i]);
        if(base_four_num[i] == 0){
            printf("A");
        }
        if(base_four_num[i] == 1){
            printf("C");
        }
        if(base_four_num[i] == 2){
            printf("G");
        }
        if(base_four_num[i] == 3){
            printf("T");
        }
    }

}

void convert_to_base_ten(char buff[15]) {
    //convert to base ten number from char.
    //printf("hello 10");
    int i, index, to_int[15];
    double base10 = 0;
    for(i = 0; i < strlen(buff); i++){
        if(buff[i] == 'A'){
            to_int[i] = 0;
            printf("%d ", to_int[i]);
        }
        if(buff[i] == 'C'){
            to_int[i] = 1;
            printf("%d ", to_int[i]);
        }
        if(buff[i] == 'G'){
            to_int[i] = 2;
            printf("%d ", to_int[i]);
        }
        if(buff[i] == 'G'){
            to_int[i] = 3;
            printf("%d ", to_int[i]);
        }
    }
    printf("\n");

    for(index = i - 1; index >= 0; index--){
        if(to_int[index] != 0) {
            base10 = (base10 + (to_int[index] * pow(4, index)));
        } else{
            
        }
    }
    printf("%0.0lf", base10);
}