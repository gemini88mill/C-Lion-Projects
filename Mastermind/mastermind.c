/*Created ny Raphael Miller on 09.22.2015
 * NID:ra677877
 * COP 3502 - guha*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define METADATA_ELEMS 3

struct input_collection{
    int test_case;
    int meta_data[3];
}Meta;

typedef struct {
    size_t used;
    size_t size;
    int **moves;
}Game_Data;

struct feedback{
    int pos_b;
    int pos_w;
}Feedback;

void collect_values(int *cases, int pInt[], Game_Data val);
void init_Game_Data(Game_Data *a, size_t initial_size);
void insert_Game_Data(Game_Data *a, int *element);
void free_Game_Data(Game_Data *a);
int * intdup(int const * src, size_t len);

int main (){



    int test_cases = 0; //collects the number of test cases, first val
    int mastermind_meta_data[3]; //second input values 3 space separated values
    int **mastermind_val = malloc(sizeof(int) * 10 * 10); //to store the rest of the values collected by the input

    int *test_case_ptr = &test_cases;
    int *meta_ptr = mastermind_meta_data;
    Game_Data data;

    init_Game_Data(&data, 5);

    collect_values(test_case_ptr, meta_ptr, data);

    //debug variables go here-----------------------------
    int i;
    //----------------------------------------------------


    //8:44pm completed storage of the first two values
    //printf("%d", *data.moves[0]);


    return 0; //end of main
}

void collect_values(int *cases, int pInt[], Game_Data val) {
    //collect the values from the *.in file
    int i = 0;
    int j = 0, k = 0, l = 0, m = 4;
    int test[3] = {8,4,3};
    int hold[sizeof(pInt[2])];
    int *hold_ptr = hold;



    scanf("%d\n", cases); //collect input cases
    //collect second input from 3 space separated values-----
    while(i < METADATA_ELEMS && scanf("%d", &pInt[i]) == 1)
        i++;
    //-------------------------------------------------------

    int *element = malloc(sizeof(int) * pInt[2]);

    //printf("%d\t", pInt[0]);
    //printf("%d\t", pInt[2]);


    for(k = 0; k < pInt[0]; k++) {
        j = 0;
        while (j < pInt[2] && scanf("%d", &element[j]) == 1) {
            j++;
        }
        hold_ptr = intdup(element, sizeof(pInt[2]));
        insert_Game_Data(&val, hold_ptr);


    }




//    printf("%d\t", element[0]);
//    printf("%d\t", element[1]);
//    printf("%d\t", element[2]);


    printf("%d\t", val.moves[0][0]);
    printf("%d\t", val.moves[0][1]);
    printf("%d\n", val.moves[0][2]);
    printf("%d\t", val.moves[1][0]);
    printf("%d\t", val.moves[1][1]);
    printf("%d\n", val.moves[1][2]);
    printf("%d\t", val.moves[2][0]);
    printf("%d\t", val.moves[2][1]);
    printf("%d\t", val.moves[2][2]);





    //collect past gameplay data-----------------------------
    /*  first value: number of slots to fill in
     *  second val: number of possible colors
     *  third val: number of moves that have been played*/

    //number of moves "rows" 3rd val
    //number of slots "columns" 1st val

    //printf("%d\t", pInt[0]);
    //printf("%d\t", pInt[2]);



}

int * intdup(int const * src, size_t len) {
    int * p = malloc(len * sizeof(int));
    memcpy(p, src, len * sizeof(int));
    return p;
}

void init_Game_Data(Game_Data *a, size_t initial_size){
    a->moves = malloc(initial_size * sizeof(int *));
    a->used = 0;
    a->size = initial_size;
}

void insert_Game_Data(Game_Data *a, int *element){

    if(a->used == a->size ){
        a->size *= 2;
        a->moves = (int **)realloc(a->moves, a->size * sizeof(int *));
    }

    a->moves[a->used++] = element;
}

void free_Game_Data(Game_Data *a){
    free(a->moves);
    a->moves = NULL;
    a->used = a->size = 0;
}