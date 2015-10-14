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



char **fill_test_maze(char **pString);

int *find_s(char **pString);

int move_cursor(char **pString, int *pos, int *cursor, int i, int i1);

int *queue_init(int **pInt, char **pString);

int main() {
    //struct initialization------------------------------------------
    struct Maze maze;
    maze.maze_meda_data = malloc(sizeof(int) * VAL_SIZE);
    maze.maze_val = malloc(sizeof(char) * MAX_ROWS * MAX_COLUMNS);
    //---------------------------------------------------------------
    struct Maze *maze_ptr = &maze;

    int i;

    int test_cases = 0;

    //scanf("%d", &test_cases);

    //for loop here for test cases
    //maze_ptr = input(&maze);
    //temp comment out

//    printf("%d", maze_ptr->maze_meda_data[0]);
//    //----------------------------
//    for(i = 0; i < 4; i++){
//        printf("%s", maze_ptr->maze_val[i]);
//    }

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

    //test case: meta data - 5, 7
    int i, j, x, y;
    int *pos;
    int *cursor = malloc(sizeof(int) * 2);
    char **test_maze_ptr = malloc(sizeof(char) * 6 * 8);

    int **arr = (int **)malloc(300 * sizeof(int *));
    for (i=0; i<300; i++)
        arr[i] = (int *)malloc(300 * sizeof(int));
    fill_test_maze(test_maze_ptr);

    for(i = 0; i < 5; i++){
        printf("%s\n", test_maze_ptr[i]);
    }

    



    queue_init(arr, test_maze_ptr);

    pos = find_s(test_maze_ptr);

    printf("found S at: %d, %d\n", pos[0], pos[1]);

    //now that we found the starting position we can check for adjacent blocks

    //pos x = 0, pos y = 1
    //the quickest way out of a maze, they say, is to go right. so lets start with right.

    //moving right
    x = pos[0] + 1;
    y = pos[1];

    cursor[0] = pos[0];
    cursor[1] = pos[1];
    //cursor = pos start

    //move_cursor(test_maze_ptr, pos, cursor, x, y);


}

int *queue_init(int **pInt, char **pString) {
    //queue_init, queue initialization. renames all of the values of the maze and applies numerical values to them.
    int i,j;



    for(i = 0; i < 5; i++){
        for(j = 0; j < 7; j++) {
            printf("%c", pString[i][j]);
            if (pString[i][j] != 'S') {
                pInt[i][j] = -1;
            } else {
                pInt = 0;
            }
        }

        printf("\n");
    }

    return 0;
}

int move_cursor(char **pString, int *pos, int *cursor, int x, int y) {
    //move_cursor() - moves the marker left to find a - char, if - is found, true value is returned, if any other value
    //false value is returned.
    int i;
    printf("pos x: %i\n", pos[0]);
    printf("pos y: %i\n", pos[1]);
    printf("\tx: %i\n", x);
    printf("\ty: %i\n", y);

//    for(i = 0; i < 5; i++){
//        printf("%s\n", pString[i]);
//    }


    if(pString[y - 1][x - 1] == '-'){
        printf("pstring at %c: %i, %i\n", pString[y][x], x, y);
        return move_cursor(pString, pos, cursor, x + 1, y);
    }else if(pString[y-1][y-1] == 'X'){
        printf("pstring at %c: %i, %i\n", pString[y-1][x-1], x, y);
        return move_cursor(pString, pos, cursor, x, y + 1);
    } else if (pString[y-1][x-1] == '~'){
        printf("pstring at %c: %i, %i\n", pString[y][x], x, y);
    }

    return 0;
}

int *find_s(char **pString) {
    //find_s() - searches through the string and finds the starting location of s. returns the array location of
    //said S
    int i, j;
    int *pos = malloc(sizeof(int) * VAL_SIZE);

    /*go through the chars */
    for(i = 0; i < 5; i++){
        for(j = 0; j < 7; j++){
            if (pString[i][j] == 'S'){
                printf("found S at: %d, %d", j, i);
                pos[0] = j;
                pos[1] = i;
            }
        }
    } //do this recursively!!!


    return pos;
}

char **fill_test_maze(char **pString) {
    pString[0] = "~~~~~~~";
    pString[1] = "~XXXXX~";
    pString[2] = "~X-S-X~";
    pString[3] = "~--X-X~";
    pString[4] = "~~~~~~~";

    return pString;
}


//input functions-------------------------------------------------------------------------------------
struct Maze * input(struct Maze *pMaze) {
    /*input function - accepts all incoming params and organizes them into the program.*/
    //values for meta val--------------------
    int limit = 2;
    int *arr = malloc(sizeof(int) * limit);
    //---------------------------------------
    //gets boundary values for maze.
    arr = get_ints(arr, limit);

   // printf("arr in input: %d", arr[0]);

    char **maze = malloc(sizeof(char) * (arr[0]+1) * (arr[1]+1));
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
//end of input functions-----------------------------------------------------------------------------