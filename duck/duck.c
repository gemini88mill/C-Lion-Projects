/*  Created by Raphael Miller
 *  NID: ra677877
 *  October 16th, 2015
 *
 *  Duck.c - a program to see how many friends jimmy is left with after he has mercilessly kicked his closest
 *  friends and therefore alienating himself from society. After his Vacation, it is quite understandable that Jimmy
 *  should probably be psychologically evaluated and perhaps be put on some kind of sociopath watch list.
 *
 *  Program function:
 *      the program will be formatted in "Layers". These layers will represent the order of the function and therefore
 *      be a little more organized then from the last submissions that I did.
 *
 *      Top Layer: Main flow - orders the time line of the program. the program will have three functions.
 *          gather_input() - gathers the input from the *.in file
 *          manipulate_input() - orders, organizes, and creates functions for the data
 *          output() - sends new information, or results to *.out file.
 *
 *          Top Layer serves as the skeleton for the program. If I have time, it can also serve for useful error
 *          handlers in order to make sure the the data was collected effectively, or output was manipulated correctly
 *          without having seg faults in my program. (which I seem to get a lot of :/).
 *
 *     Body Layer: Functional tools - Mostly directed at the manipulate_input() function, this layer is used to
 *     modify the input data, for whatever reason, but this isn't directed at only this function. The body prepares
 *     the result for output.
 *
 *          In gather_input() -
 *              get_no_of_games() - gets the number of games jimmy's mom wants me to watch
 *              get_no_of_friends() - gets the number of friends that jimmy has before he starts playing
 *              get_names_of_friends() - gets the friends name
 *              get_rounds() - the number of the rounds for the games
 *              get_ducks() - the number of ducks
 *
 *         In manipulate_input() -
 *              move_jimmy() - moves jimmy for every "duck" being called
 *              reshuffle_friends() - creates a new round where a friend that got the boot is missing
 *              set_up() - sets up the game for jimmy to play
 *
 *         In output() -
 *              print_to_screen() - prints output to screen.
 *
 *    Bottom Layer: Clean up - anything pertaining to cleaning the code and creating a safe exit code 0*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void gather_input(int *games, int *friends, char **friend_names, int *rounds, int *ducks);

void manipulate_input();

void output();

void get_games(int **pInt);

int get_ints(int **pInt);

int main() {
    //----------------------------------------------
    int no_of_games = 0;
    int no_of_friends = 0;
    char **friend_names = malloc((sizeof(char*) * 2000) * (sizeof(char) * 20));
    int rounds = 0;
    int ducks = 0;
    //----------------------------------------------
    gather_input(&no_of_games, &no_of_friends, friend_names, &rounds, &ducks);

//    printf("%d", no_of_games);
//    printf("%d", no_of_friends);
    manipulate_input();
    output();
    return 0;
}

void output() {

}

void manipulate_input() {

}

void gather_input(int *games, int *friends, char **friend_names, int *rounds, int *ducks) {
    int counter;

    //scans in the number of games
    /*  gets the amount of games for jimmy the sadist to play. Put into a for loop so we can gather the information
     *  for the rest of the *.in file*/
    get_ints(&games);
    get_ints(&friends); //scans in the number of friends.


    for (counter = 0; counter < *games; counter++){
        /*  for loop for the input data from the game. everything points outside for the loop because we need to bring
            the data to other parts of the program*/



    }
}

//function to pull ints from data
int get_ints(int **pInt) {
    return scanf("%d", *pInt);
}

