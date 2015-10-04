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


void allLexicographic(char charlist[]);

int compare (const void * a, const void * b);

void allLexicographicRecur(char charlist[], char *data, int last, int index);

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
    int *color_list = malloc(sizeof(int) * pInt[1]);
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
//    for(x = 0; x < pInt[2]; x++){
//        value[x] = pInt[1];
//    }

    int *int_ptr = acc_row;


    for (z = 0; z < pInt[1]; z++){ //number of colors in the array.
        color_list[z] = z;
        printf("%d", color_list[z]);
    }

    int pos = 0;
    int r = pInt[1]; //max size
    int n = sizeof(color_list)/ sizeof(color_list); // sample 6
    int length_of_val = pInt[2];
    char charlist[] = "012345";

    allLexicographic(charlist);


    return 0;
}

void allLexicographic(char charlist[]) {
    int len = strlen (charlist) ;

    // Create a temp array that will be used by allLexicographicRecur()
    char *data = (char *) malloc (sizeof(char) * (len + 1)) ;
    data[len] = '\0';

    // Sort the input string so that we get all output strings in
    // lexicographically sorted order
    qsort(charlist, len, sizeof(char), compare);

    // Now print all permutaions
    allLexicographicRecur (charlist, data, len-1, 0);

    // Free data to avoid memory leak
    free(data);
}

void allLexicographicRecur(char charlist[], char *data, int last, int index) {
    int i, len = strlen(charlist);

    // One by one fix all characters at the given index and recur for the
    // subsequent indexes
    for ( i=0; i<len; i++ )
    {
        // Fix the ith character at index and if this is not the last index
        // then recursively call for higher indexes
        data[index] = charlist[i] ;

        // If this is the last index then print the string stored in data[]
        if (index == last)
            printf("%s\n", data);
        else // Recur for higher indexes
            allLexicographicRecur (charlist, data, last, index+1);
    }
}

int compare (const void * a, const void * b)
{
    return ( *(char *)a - *(char *)b );
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