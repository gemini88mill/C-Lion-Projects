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

//"Top-Level" functions-------------
struct Maze * input(struct Maze *pMaze);
int logic(struct Maze *pMaze);
void output(int i);
//----------------------------------

//related input type functions---------------------------------
int *get_ints(int arr[], int i);
char **get_maze(char **maze_ptr, int i, int i1);
char *strdup (const char *s);
void get_line(char **pString, char buff[], int counter);
//-------------------------------------------------------------

//related logic type functions-------------------------------------------------------
int *find_s(char **pString, int *pInt);
int ** queue_init(int **pInt, int *pMaze_val, int i, int i1);
void print_queue_val(int **pInt, struct Maze *pMaze);
int find_path(char **pString, int **pInt, int x, int y, int count, int *grab);
void print_input_maze(struct Maze *pMaze);
int find_lowest_grab(int *pInt);
//----------------------------------------------------------------------------------


int main() {
    //struct initialization------------------------------------------
    struct Maze maze;
    maze.maze_meda_data = malloc(sizeof(int) * VAL_SIZE);
    maze.maze_val = malloc(sizeof(char) * MAX_ROWS * MAX_COLUMNS);
    //---------------------------------------------------------------
    struct Maze *maze_ptr = &maze;
    int i;
    int test_cases = 0;

    scanf("%d", &test_cases);

    //for loop here for test cases
    for(i = 0; i < test_cases; i++) {
        maze_ptr = input(&maze);
        int value = logic(maze_ptr);
        output(value);
    }
    return 0;
}


//output---------------------------------------------------------------------------------------------------------------
void output(int i) {
    /*  output - "top-level" function - provides the desired output for the entire program. Differentiates between what
     *  type of value is required, if value is less then 0, maze is unsolvable and therefore -1 is the result. If the
     *  result is more then zero output the number received (total number of steps taken) and add one. The logic
     *  does not provide for an addition to the value as far as steps. the ~ step is not counted, therefore it is added
     *  here*/
    if(i < 0) {
        i = -1;
        printf("%d", i);
    } else {
        printf("%d", i + 1);
    }
}
//end of output--------------------------------------------------------------------------------------------------------

//logic functions------------------------------------------------------------------------------------------------------
int logic(struct Maze *pMaze) {
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
    int i, j, x = 0, y = 0;
    int *pos;
    char **test_maze_ptr = malloc(sizeof(char) * 6 * 8);

    int **arr = malloc(300 * sizeof(int *));
    for (i=0; i<300; i++)
        arr[i] = malloc(300 * sizeof(int));
    int count = 0;
    int grab_last_index = 0;

    //debug----------------------------
    //fill_test_maze(test_maze_ptr);
    //print_maze(test_maze_ptr);
    //---------------------------------

    //printf("arr: %i", arr[0][0]);

    //--------------------------------------------------------
    //initialize queue grid
    while(x < pMaze->maze_meda_data[0]) {
        arr = queue_init(arr, pMaze->maze_meda_data, x, y);
        x++;
    }
    //--------------------------------------------------------

    //print_input_maze(pMaze);
    //queue is now initialized proceed with dequeue logic

    pos = find_s(pMaze->maze_val, pMaze->maze_meda_data);

    //print_queue_val(arr, pMaze);
    y = pos[0];
    x = pos[1];

    //test_maze_ptr = **char
    find_path(pMaze->maze_val, arr, x, y, count, &grab_last_index);
    //printf("grab: %d", grab_last_index);

    return grab_last_index;

}

int find_path(char **pString, int **pInt, int x, int y, int count, int *grab) {
    //find_path function, uses the data collected and tries to find a path out
    //printf("%i, %i\n", x, y);
    //print_maze(pString);
    //print_queue_val(pInt);
    //printf("%c\n", pString[x][y]);
    if(pString[x][y] == 'S'){
        pInt[x][y] = count;
        find_path(pString, pInt, x + 1, y, count, grab);
        find_path(pString, pInt, x - 1, y, count, grab);
        find_path(pString, pInt, x, y + 1, count, grab);
        find_path(pString, pInt, x, y - 1, count, grab);

    } else if(pString[x][y] == '-' && pInt[x][y] == -1 && pInt[x][y] != 0){
        pInt[x][y] = count + 1;
        find_path(pString, pInt, x + 1, y, count + 1, grab);
        find_path(pString, pInt, x - 1, y, count + 1, grab);
        find_path(pString, pInt, x, y + 1, count + 1, grab);
        find_path(pString, pInt, x, y - 1, count + 1, grab);

    } else if(pString[x][y] == '~'){
        pInt[x][y] = count + 1;
        //printf("count: %d\n", count);
        *grab = count; //get smallest grab here! return to grab...
        //printf("grab: %d\n", *grab);
        find_lowest_grab(grab);
        return count;
    } else if(pString[x][y] == 'X'){
        pInt[x][y] = -1;
        *grab = -1;
        return count;
    }

    return pInt[x][y];
}

int find_lowest_grab(int *pInt) {
    //finds lowest grab and sends it back.
    int temp = 100;

    if(temp > *pInt){
        return *pInt;
    } else{
        return temp;
    }


}

void print_queue_val(int **pInt, struct Maze *pMaze) {
    int i, j;
    for(i = 0; i < pMaze->maze_meda_data[0]; i++) {
        for (j = 0; j < pMaze->maze_meda_data[1]; j++) {
            printf("%i ", pInt[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int **queue_init(int **pInt, int *pMaze_val, int x, int y) {
    //queue_init, queue initialization. renames all of the values of the maze and applies numerical values to them.
    int i,j;

//    while (y <= pMaze_val[y]) {
//        pInt[x][y] = -1;
//        y++;
//        return queue_init(pInt, pMaze_val, x, y + 1);
//    }
    pInt[x][y] = -1;

    if(x < pMaze_val[0]){
        queue_init(pInt, pMaze_val, x + 1, y);
    }
    if(y < pMaze_val[1]){
        queue_init(pInt, pMaze_val, x, y + 1);
    }

    return pInt;
}

int *find_s(char **pString, int *pInt) {
    //find_s() - searches through the string and finds the starting location of s. returns the array location of
    //said S
    int i, j;
    int *pos = malloc(sizeof(int) * VAL_SIZE);

    /*go through the chars */
    for(i = 0; i < pInt[0]; i++){
        for(j = 0; j < pInt[1]; j++){
            if (pString[i][j] == 'S'){
                printf("found S at: %d, %d\n", j, i);
                pos[0] = j;
                pos[1] = i;
            }
        }
    } //do this recursively!!!


    return pos;
}
//---------------------------------------------------------------------------------------------------------------------

//input functions------------------------------------------------------------------------------------------------------
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

    //print_input_maze(pMaze);
    return pMaze;
}

void print_input_maze(struct Maze *pMaze) {
    int i;
    for(i = 0; i < pMaze->maze_meda_data[0]; i++){
        printf("%s", pMaze->maze_val[i]);
    }
}

char **get_maze(char **maze_ptr, int rows, int columns) {
    //function to get the values for the maze.
    int i = 0;
    char buff[300];

    //collect input using buff
    while(i <= rows){
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
    //taken from POSIX libs
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
//end of input functions-----------------------------------------------------------------------------------------------