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

    int input_cases = 0;
    int i;
    int score;

    scanf("%d", &input_cases);

    for (i = 0; i < input_cases; i++) {
        input(&data);
        //struct filled, send to logic.
        //collect score from logic
        score = logic(&data);

        //printf to screen
        output(score);
    }
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

    if(i < size) {
        data->army_power_atk[i] = atk[i];
        data->army_power_def[i] = def[i];
        data->no_armies = size;
        load_struct(atk, def, size, data, i + 1);
    }
}

void load_array(int arr[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void get_int(int *i) {
    scanf("%i", i);
}

//logic functions-------------------------------------------------------------------------------------------------------
int logic(struct Battle_data *data) {
    int first_index = 0;
    int last_index = data->no_armies - 1;
    int iteration_count = 0;

    //collect data from struct
    int *atk;
    int *def;


    atk = data->army_power_atk;
    def = data->army_power_def;

    //sorts the arrays inside structs for both atk and def
    sort_arr(atk, first_index, data->no_armies - 1);
    sort_arr(def, first_index, data->no_armies - 1);

    //compares the array values to each other
    iteration_count = compare(atk, def, last_index, last_index, iteration_count);

    //return result
    return iteration_count;
}

int compare(int *atk, int *def, int top_atk, int top_def, int i) {

    if(top_atk >= 0 && top_def >= 0) {
        if (atk[top_atk] <= def[top_def]) {
            return compare(atk, def, top_atk - 1, top_def - 1, i + 1);
        } else if (atk[top_atk] > def[top_def]) {
            return compare(atk, def, top_atk - 1, top_def, i);
        }
    }
    return i;
}

int *sort_arr(int *pInt, int first_index, int last_index) {
    int pivot_locale;

    if (first_index < last_index){
        //select partition.
        pivot_locale = partition(pInt, first_index, last_index);
        sort_arr(pInt, first_index, pivot_locale);
        sort_arr(pInt, pivot_locale + 1, last_index);
    }
}

int partition(int *pInt, int first_index, int last_index) {
    int pivot = pInt[first_index];
    int left = first_index;
    int i;

    for (i = first_index; i <= last_index; i++) {
        if(pInt[i] < pivot){
            left = left + 1;
            swap(&pInt[i], &pInt[left]);
        }
    }
    swap(&pInt[first_index], &pInt[left]);

    return left;
}

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}
//----------------------------------------------------------------------------------------------------------------------

void output(int i) {
    printf("%i\n", i);
}
