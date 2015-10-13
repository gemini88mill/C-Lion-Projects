/*  Created by Raphael Miller
 *  October 13th, 2015
 *  NID: ra677877
 *
 *  Maze.c - this program allows the user to navigate through a maze of a given problem, we must first test to see if
 *  the maze is escape-able. then we must navigate through the maze in the least amount of time.
 *
 *  top layer: input, output, logic.
 *      input - deals with all input from *.in file
 *      logic - program logic, functions to make the program actually work
 *      output - prints desired information.
 *
 *  input layer- functions
 *      getints() - get ints for the perams listed
 *      getmaze() - gets the maze for the program, in full, might be seperated later
 *
 *
 *  logic layer - functions
 *     int queue_layer(maze)
 *
 *  output layer - functions
 *      printOut() - prints out final solution to particular problem */

#include <stdio.h>
#include <stdlib.h>

//"Top-Level functions"-------------
void input();
void logic();
void output();
//----------------------------------

int *get_ints(int arr[], int i);

char **get_maze(char **maze_ptr);

int main() {
    printf("hello");

    int test_cases = 0;

    scanf("%d", &test_cases);

    //for loop here for test cases
    input();
    //----------------------------
    logic();
    output();

    return 0;
}

void output() {

}

void logic() {

}

void input() {
    /*input function - accepts all incoming params and organizes them into the program.*/
    //values for meta val--------------------
    int limit = 2;
    int *arr = malloc(sizeof(int) * limit);
    //---------------------------------------
    //gets boundary values for maze.
    arr = get_ints(arr, limit);

   // printf("arr in input: %d", arr[0]);

    char **maze = malloc(sizeof(char) * arr[0] * arr[1]);
    //gets maze values
    get_maze(maze);

}

char **get_maze(char **maze_ptr) {
    //function to get the values for the maze.
    int i = 0;
    

    return 0;
}

int *get_ints(int arr[], int limit) {
    //accepts ints from scanf (with spaces!!!) and returns values.
    int i = 0;
    while (i < limit && scanf("%d", &arr[i]) == 1) {
        printf("arr[%d]: %d", i, arr[i]);
        i++;
    }
    return arr;
}