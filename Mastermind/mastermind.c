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

int mastermind_engine(Game_Data data, int *pInt);

int genetic_algo(Game_Data *data_ptr);

void permute(int *data, int first, int last);

void swap(int *pInt, int *pInt1);

int main (){



    int test_cases = 0; //collects the number of test cases, first val
    int mastermind_meta_data[3]; //second input values 3 space separated values
    //int **mastermind_val = malloc(sizeof(int) * 10 * 10); //to store the rest of the values collected by the input

    int *test_case_ptr = &test_cases;
    int *meta_ptr = mastermind_meta_data;
    int output;
    Game_Data data;

    init_Game_Data(&data, 5);

    collect_values(test_case_ptr, meta_ptr, data);

    //debug variables go here-----------------------------
    int i, m, l;
    //----------------------------------------------------

//    for(m = 0; m < meta_ptr[0]; m++) {
//        for (l = 0; l < (meta_ptr[2] + 2); l++) {
//            printf("%d\t", data.moves[m][l]);
//        }
//        printf("\n");
//    }
    //debug

    //8:44pm completed storage of the first two values
    //printf("%d", *data.moves[0]);


    /*  value key: mastermind_meta_data[0] = "columns" for 2d array, the number of slots to fill in.
     *             mastermind_meta_data[1] = number of possible "colors"
     *             mastermind_meta_data[2] = "rows" for 2d array, the number of moves that have been played
     *             Game_Data data = stores the moves that were played.*/

    //sample case 4 6 4
    output = mastermind_engine(data, meta_ptr);

    //printf("%d", output);

    return 0; //end of main
}

int mastermind_engine(Game_Data data, int *pInt) {
    //debug vars---------------------------
    int x,y,z;
    //-------------------------------------

    Game_Data *data_ptr = &data;

    for(x = 0; x < pInt[0]; x++){
        for(y = 0; y < pInt[2] + 2; y++){
            printf("%d\t", data.moves[x][y]);
        }
        printf("\n");
    }

    int *c_and_w_correct = malloc(sizeof(int) * pInt[2]);
    int *color_correct = malloc(sizeof(int) * pInt[2]);
    int *acc_row = malloc(sizeof(int) * pInt[0]);
    int no_of_colors = pInt[1];
    int value[4];

    for(x = 0; x < pInt[0]; x++){
        c_and_w_correct[x] = data.moves[x][pInt[2]];
        //printf("%d\t", c_and_w_correct[x]);
    }

    printf("\n");

    for(x = 0; x < pInt[0]; x++){
        color_correct[x] = data.moves[x][pInt[2] + 1];
        //printf("%d\t", color_correct[x]);
    }

    for(z = 0; z < pInt[2]; z++){
        acc_row[z] = data.moves[0][z];
        //printf("%d ", acc_row[z]);
    }

    for(x = 0; x < pInt[2]; x++){
        value[x] = pInt[1];
    }

    int *int_ptr = acc_row;
    int n = pInt[2];

    permute(acc_row, 0, 3);


    return 0;
}

void permute(int *data, int first, int last) {
    int i;
    if (first == last){
        int x;
        for (x = 0; x < 4; x++) {
            printf("%d ", data[x]);
        }
        printf("\n");
    } else {
        for(i = first; i <= last; i++){
            swap((data + first), (data + i));
            permute(data, first + 1, last);
            swap( (data + first), (data + i));
        }
    }

}

void swap(int *pInt, int *pInt1) {
    int temp;
    temp = *pInt;
    *pInt = *pInt1;
    *pInt1 = temp;
}


void collect_values(int *cases, int pInt[], Game_Data val) {
    //collect the values from the *.in file
    int i = 0;
    int j = 0, k = 0, l = 0, m = 4;
    int test[3] = {8,4,3};
    int hold[sizeof(pInt[2] + 2)];
    int *hold_ptr = hold;



    scanf("%d\n", cases); //collect input cases
    //collect second input from 3 space separated values-----
    while(i < METADATA_ELEMS && scanf("%d", &pInt[i]) == 1)
        i++;
    //-------------------------------------------------------

    int *element = malloc(sizeof(int) * (pInt[2] + 2));

    for(k = 0; k < pInt[0]; k++) {
        j = 0;
        while (j < (pInt[2] + 2) && scanf("%d", &element[j]) == 1) {
            hold_ptr = intdup(element, sizeof(element));
            j++;
        }



        insert_Game_Data(&val, hold_ptr);
    }

//    for(m = 0; m < pInt[0]; m++) {
//        for (l = 0; l < (pInt[2] + 2); l++) {
//            printf("%d\t", val.moves[m][l]);
//        }
//        printf("\n");
//    } for debug

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