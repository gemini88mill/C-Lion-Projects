#include <stdlib.h>
#include <stdio.h>

#define SIZE 9
#define SUBGRID_SIZE 3


bool check_row(int pInt[]);

void check_coloumn();

void check_subgrid();


int *take_element();

int main() {

    int line1[SIZE][SIZE] = {{3,5,7,6,4,8,9,1,2},
                             {2,1,6,5,3,9,7,4,8},
                             {9,4,8,7,1,2,5,3,6},
                             {5,2,1,4,8,6,3,9,7},
                             {4,6,3,1,9,7,2,8,5},
                             {7,8,9,3,2,5,1,6,4},
                             {6,3,2,9,7,4,8,5,1},
                             {1,7,4,8,5,3,6,2,9},
                             {8,9,5,2,6,1,4,7,3}};


    //function to put line in sudoku
    bool first_check;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            first_check = check_row(&line1[i][j]);
            if(first_check == true){
                break;
            }


        }
        printf("%d", line1[1][i]);

    }
    printf("%s", first_check ? "true\n" : "false\n");

    return 0;
}

int *take_element() {
    int result[SIZE];

    return result;
}


void check_subgrid() {

}

void check_coloumn() {

}

bool check_row(int pInt[]) {
    //check to see if any numbers in the "row" array are equal to each other
    bool result = true;
    int i, j;
    int checked_val = 0;
    int count = 0;

    for (i = 0; i < SIZE; i++){
        checked_val = pInt[i]; //stores array in checked_val
        for (j = 0; j < SIZE; j++){
            //runs array again to check against checked_val
            if(pInt[j] == checked_val){
                //printf("yes\n");
                count++;
            } else {
                //printf("no\n");
            }
        }
        //printf("\n\n");
        if (count > 1){
            result = false;
            break;
        }
        count = 0;
    }
    return result;
}

