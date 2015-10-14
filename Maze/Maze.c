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
 *      printOut() - prints out final solution to particular problem
 *
 *  Additional: in order to cleanly sent data through to other functions in the top level, top level functions will
 *  return structs for that data. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 300
#define MAX_COLUMNS 300
#define VAL_SIZE 2

//struct def
struct Maze
{
    char **maze_val;
    int *maze_meda_data;
};

//"Top-Level functions"-------------
struct Maze * input(struct Maze *pMaze);
void logic();
void output();
//----------------------------------

//related input type functions---------------------------------
int *get_ints(int arr[], int i);
char **get_maze(char **maze_ptr, int i, int i1);
char *strdup (const char *s);
void get_line(char **pString, char buff[], int counter);
//-------------------------------------------------------------

int main() {
    //struct initialization------------------------------------------
    struct Maze maze;
    maze.maze_meda_data = malloc(sizeof(int) * VAL_SIZE);
    maze.maze_val = malloc(sizeof(char) * MAX_ROWS * MAX_COLUMNS);
    //---------------------------------------------------------------
    struct Maze *maze_ptr = &maze;


    int test_cases = 0;

    scanf("%d", &test_cases);

    //for loop here for test cases
    maze_ptr = input(&maze);
    //----------------------------
    logic();
    output();

    return 0;
}

void output() {

}

void logic() {
    /*  logic functions go here.
     *  params: maze. At this point, Maze should be properly formatted and ready to be manipulated.
     *
     *  find_s() - finds s on the map and creates a marker
     *  check_right() - check to see if we can move right
     *  check_left() - check to see if we can go left
     *  check_up() - check to se if we can go up
     *  check_down() - check to see if we can go down
     *
     *  if any of these values are true, take that route.
     *  repeat until ~ is reached
     *  count the number of moves. */

}

struct Maze * input(struct Maze *pMaze) {
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
    maze = get_maze(maze, arr[0], arr[1]);

    //now we have maze and arr that represent our input values for the maze
    //send them to main

    pMaze->maze_val = maze;
    pMaze->maze_meda_data = arr;

    return pMaze;
}

char **get_maze(char **maze_ptr, int rows, int columns) {
    //function to get the values for the maze.
    int i = 0;
    char buff[300];

    //collect input using buff
    while(i < rows){
        get_line(maze_ptr, buff, i);
        i++;
    }
//    for(i = 0; i < rows; i++){
//        printf("%s", maze_ptr[i]);
//    }


    return maze_ptr;
}

int *get_ints(int arr[], int limit) {
    //accepts ints from scanf (with spaces!!!) and returns values.
    int i = 0;
    while (i < limit && scanf("%d", &arr[i]) == 1) {
        printf("arr[%d]: %d\n", i, arr[i]);
        i++;
    }
    return arr;
}

char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);   // Allocate memory
    if (d != NULL) strcpy (d,s);         // Copy string if okay
    return d;                            // Return new memory
}

void get_line(char **pString, char buff[], int counter) {
    char *temp;
    fgets(buff, 20, stdin);
    temp = strdup(buff);
    pString[counter] = temp;
}
