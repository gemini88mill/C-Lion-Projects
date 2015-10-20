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
void input(struct Battle_data data);
void logic();
void output();
//------------------------------------

void get_int(int *i);

void load_array(int arr[], int size);

void load_struct(int atk[], int def[], int size, struct Battle_data data, int i);

int main() {

    //struct init
    struct Battle_data data;
    data.army_power_atk = malloc(sizeof(int) * ARMY_POW_MAX);
    data.army_power_def = malloc(sizeof(int) * ARMY_POW_MAX);

    int input_cases = 0;
    int i;

    //for loop here for test_cases
    input(data);
    logic();
    output();
    return 0;
}

void input(struct Battle_data data) {
    /*input() - collect all input from *.in file. and organize according to program needs. */

    int army_size = 0;

    int i;

    get_int(&army_size);

    int army_pow_val_atk[army_size];
    int army_pow_val_def[army_size];

    load_array(army_pow_val_atk, army_size);
    load_array(army_pow_val_def, army_size);

    printf("army_size: %d", army_size); //good

    for(i = 0; i < army_size; i++){
        printf("arr atk %d: %d\n", i, army_pow_val_atk[i]); //good
        printf("arr def %d: %d\n", i, army_pow_val_def[i]); //good
    }

    load_struct(army_pow_val_atk, army_pow_val_def, army_size, data, 0);

}

void load_struct(int atk[], int def[], int size, struct Battle_data data, int i) {

    if(i < size) {
        data.army_power_atk[i] = atk[i];
        data.army_power_def[i] = def[i];
        data.no_armies = size;
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

//----------------------------------------------------------------------------------------------------------------------
void logic() {

}

void output() {

}
