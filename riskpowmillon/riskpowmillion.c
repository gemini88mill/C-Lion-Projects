/*  Created by Raphael Miller
 *  NID: ra677877
 *  10/20/2015
 *
 *  riskpowmillion.c - risk battle emulator that accepts significantly more armies that, in theory, could wipe out all
 *  of human existance. 1 million armies on each side, of equal number go head to head on Siam, because everyone who
 *  has ever played risk knows that the only place where a massive battle like that happens is for Australia.
 *
 *  Difference from Risk(Original). armies can "roll" a die from one to one billion. Additionally, the defense has a
 *  higher advantage where they can see the atk beforehand and adjust to match the attacking position
 *
 *  Goal: To create an algorithm that finds the maximum number of armies that are defeated by the defender. */

#include <stdio.h>
#include <stdlib.h>

#define ARMY_MAX 1000000
#define ARMY_POW_MAX 1000000000


//struct def
struct Battle_data{
    int no_armies;          //max 1,000,000
    int *army_power_atk;   //max 1,000,000,000
    int *army_power_def;   //max 1,000,000,000
};

//top level functions-----------------
void input(struct Battle_data *data);
int logic(struct Battle_data *data);
void output(int i);
//------------------------------------

//input level functions-------------------------------------------------------------
void get_int(int *i);
void load_array(int arr[], int size);
void load_struct(int atk[], int def[], int size, struct Battle_data *data, int i);
//----------------------------------------------------------------------------------

//logic level functions--------------------------------------------------------------------------------
int *sort_arr(int *pInt, int first_index, int last_index);
int compare(int *atk, int *def, int top_atk, int top_def, int i);
int partition(int *pInt, int first_index, int last_index);
void swap(int *i, int *j);
//-----------------------------------------------------------------------------------------------------

int main() {

    //struct init
    struct Battle_data data;
    data.army_power_atk = malloc(sizeof(int) * ARMY_POW_MAX);
    data.army_power_def = malloc(sizeof(int) * ARMY_POW_MAX);
    data.no_armies = 0;

    //main variables
    int input_cases = 0;
    int i;
    int score;

    //scans in input cases (first value)
    scanf("%d", &input_cases);

    //loads input cases and proceeds with input.
    for (i = 0; i < input_cases; i++) {

        //to input
        input(&data);

        //collect score from logic
        score = logic(&data);

        //printf to screen
        output(score);


    }
    free(data.army_power_atk);
    free(data.army_power_def);
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------
void input(struct Battle_data *data) {
    /*input() - collect all input from *.in file. and organize according to program needs. */

    //init army size
    int army_size = 0;

    //gets army_size from stdin
    get_int(&army_size);

    //init army power values for attack and defense
    int army_pow_val_atk[army_size];
    int army_pow_val_def[army_size];

    //loads array with stdin
    load_array(army_pow_val_atk, army_size);
    load_array(army_pow_val_def, army_size);

    //loads struct with values collected from load_array()
    load_struct(army_pow_val_atk, army_pow_val_def, army_size, data, 0);
}

void load_struct(int atk[], int def[], int size, struct Battle_data *data, int i) {
    /*load_struct() - function load_struct() takes values from array and places them inside struct for better management
     * and readability*/
    if(i < size) {
        data->army_power_atk[i] = atk[i];
        data->army_power_def[i] = def[i];
        data->no_armies = size;
        load_struct(atk, def, size, data, i + 1);
    }
}

void load_array(int arr[], int size) {
    /*load_array() - loads array with values collected from scanf() [input] and placed into array specified*/

    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void get_int(int *i) {
    //get_int() - gets an integer value from scanf [input] and loads into value specified.
    scanf("%i", i);
}

//logic functions-------------------------------------------------------------------------------------------------------
int logic(struct Battle_data *data) {
    /*logic() - logic level functions deal with all logic functions in the program.
     *  1. set local variables: mainly to deal with sorting
     *  2. sort struct arrays(placed in local arrays)
     *  3. compare values inside arrays.
     *  4. return solution to main.*/

    //local variables
    int first_index = 0;
    int last_index = data->no_armies - 1;
    int iteration_count = 0;

    //collect data from struct
    int *atk = data->army_power_atk;
    int *def = data->army_power_def;


    //sorts the arrays inside arrays(taken from structs) for both atk and def
    sort_arr(atk, first_index, data->no_armies - 1);
    sort_arr(def, first_index, data->no_armies - 1);

    //compares the array values to each other
    iteration_count = compare(atk, def, last_index, last_index, iteration_count);

    //return result
    return iteration_count;
}

int compare(int *atk, int *def, int top_atk, int top_def, int i) {
    /*compare() - function compares two values from arrays. If value def is greater than or equal to value atk; return
     *            compare(with both indices of atk and def - 1. i is increased by 1). If value atk is greater then
     *            value def; return compare(atk - 1). this is all wrapped in a conditional clause stating that the
     *            index of either array cannot be less than 0
     *
     *            return i.(iteration counter)*/

    //condition: indices of both atk anbd def must be greater then 0
    if(top_atk >= 0 && top_def >= 0) {

        //if atk <= def
        if (atk[top_atk] <= def[top_def]) {
            return compare(atk, def, top_atk - 1, top_def - 1, i + 1);
        }
        //if atk > def
        else if (atk[top_atk] > def[top_def]) {
            return compare(atk, def, top_atk - 1, top_def, i);
        }
    }
    return i;
}

int *sort_arr(int *pInt, int first_index, int last_index) {
    /*sort_arr() - quick sort variant. This qsort was adapted from resources online and guha's examples.
     *  the function uses the pivot_locale variable to act as the partition and split through the sort. */
    int pivot_locale;

    if (first_index < last_index){
        //select partition.
        pivot_locale = partition(pInt, first_index, last_index);
        sort_arr(pInt, first_index, pivot_locale);
        sort_arr(pInt, pivot_locale + 1, last_index);
    }
}

int partition(int *pInt, int first_index, int last_index) {
    /*parition() function - function uses the perameters given and swaps all integers in order from least to greatest*/

    //local variables
    int pivot = pInt[first_index];
    int left = first_index;
    int i;

    //for loop that is ditated by how big the partition in question is
    for (i = first_index; i <= last_index; i++) {

        //if out of place in partition, swap with current(pointed to) index.
        if(pInt[i] < pivot){
            left = left + 1;

            //swap
            swap(&pInt[i], &pInt[left]);
        }
    }
    //else swap
    swap(&pInt[first_index], &pInt[left]);

    //return lower left bound for partition.
    return left;
}

void swap(int *i, int *j) {
    //swap() - swap function, swaps pointer locale
    int temp = *i;
    *i = *j;
    *j = temp;
}
//----------------------------------------------------------------------------------------------------------------------

void output(int i) {
    //output "level" - prints to screen.
    printf("%i\n", i);
}
