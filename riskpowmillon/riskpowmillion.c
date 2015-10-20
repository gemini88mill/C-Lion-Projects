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


//struct def
struct Battle_data{
    int no_armies;          //max 1,000,000
    int army_power_atk[1];   //max 1,000,000,000
    int army_power_def[1];   //max 1,000,000,000
};

//top level functions-----------------
void input();
void logic();
void output();
//------------------------------------

void get_int(int *i);

int main() {


    int input_cases = 0;
    int i;

    //for loop here for test_cases
    input();
    logic();
    output();
    return 0;
}

void input() {
    /*input() - collect all input from *.in file. and organize according to program needs. */

    int army_size = 0;
    int army_pow_val = 0;

    get_int(&army_size);

    printf("army_size: %d", army_size); //good
}

void get_int(int *i) {
    scanf("%i", i);
}

//----------------------------------------------------------------------------------------------------------------------
void logic() {

}

void output() {

}
