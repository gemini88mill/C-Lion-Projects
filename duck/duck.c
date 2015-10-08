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
 *              get_ints() - gets all ints from *.in file using scanf()
 *              get_names_of_friends() - gets the friends name
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

#define NO_INPUT 1
#define OK 0
#define TOO_LONG 2

//linked list def
typedef struct node{
    char *name;
    struct node * next;
}node_t;



void gather_input(int *games, int *friends, char **friend_names, int *rounds, int *ducks);
node_t * manipulate_input(int *friends_length, int *ducks, char **friend_names, int i);
void output(node_t *pNode, int i);
void get_games(int **pInt);
int get_ints(int **pInt, int limit);
char *strdup (const char *s);
void get_name(char **pString, int counter, char buff[]);

node_t * game_logic(char **friends_list, int *ducks, int list_length, int i);

void list_append(char *string, node_t *head);

void print_list(node_t *head);

char * pop_list(node_t **pNode);

char *remove_by_index(node_t **pNode, int index);

int main() {
    //----------------------------------------------
    int no_of_games = 0;
    int no_of_friends = 0;
    char **friend_names = malloc(sizeof(char)* 25 * 2000);
    int rounds = 0;
    int ducks = 0;
    //----------------------------------------------

    //----------------------------------------------
    int i, j;
    //----------------------------------------------
    node_t *winners = NULL;

    scanf("%d", &no_of_games);

    for(j = 0; j < no_of_games; j++) {
        gather_input(&no_of_games, &no_of_friends, friend_names, &rounds, &ducks);
    }
//    printf("%d\n", no_of_games);
//    printf("%d\n", no_of_friends);
//
//    for(i = 0; i < no_of_friends; i++)
//        printf("%s", friend_names[i]);
//
//    printf("%d\n", rounds);
//    printf("%d\n", ducks);


//    for (i = 0; i < no_of_games; i++) {
//        winners = manipulate_input(&no_of_friends, &ducks, friend_names, rounds);
//        output(winners, i);
//    }
    return 0;
}

void output(node_t *pNode, int i) {
    printf("Game %d\n", i + 1);
    print_list(pNode);
}

node_t * manipulate_input(int *friends_length, int *ducks, char **friend_names, int rounds) {
    /*  manipulate input() - in this scenario the idea is that jimmy will have a number of friends once he starts
     *  playing the game, and then, depending on how many rounds the game is played, loses friends systematically,
     *
     *  code flow - jimmy will start at pos 0
     *              jimmy will then move through the list for (duck) moves until he has reached his target
     *              once jimmy reaches his target, that person is out of the game. the game is played until
     *              a. there are no more friends left or
     *              b. the game is over
     *
     *  functions in logic:
     *      game_logic() - the primary function of the game.
     *          game logic is set up in two parts:
     *              first if number of rounds is less then number of friends
     *                if friends_length > ducks
     *              -if this is the case then we can kick out friend_names[ducks + 1]
     *              -delete friend from game
     *              -next round
     *
     *          if friends_length < ducks
     *              -person kicked = (friends_length % ducks) + 1
     *              -next round
     *     Note: friends_names should be copied to another function as to not ruin the original data just in case...*/
    int no_of_friends = *friends_length;
    char **friends_list = malloc(sizeof(char) * no_of_friends * 20);
    node_t *winners = NULL;

    int i;

    for (i = 0; i < no_of_friends; i++){
        friends_list[i] = friend_names[i];
    }

    winners = game_logic(friends_list, ducks, no_of_friends, rounds);

    return winners;

}

node_t * game_logic(char **friends_list, int *ducks, int list_length, int rounds) {
    int pos = 0;
    int i, j = 0;
    node_t *head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL){
        return (node_t *) 1;
    }

    head->name = "1";

    for(i = 0; i < list_length; i++) {
        list_append(friends_list[i], head);
    }
    pop_list(&head);

    while (j < rounds) {
        if (list_length > *ducks) {
            pos = *ducks;
            //printf("friend: %d, %s", pos + 1, friends_list[pos]);
            //remove and restructure
        } else if (list_length < *ducks) {
            pos = *ducks % list_length;
            //printf("friend: %d, %s", pos + 1, friends_list[pos]);
            //remove and restructure
        }
        //friends_list = remove_from_list(friends_list, friends_list[pos], pos, list_length);
        remove_by_index(&head, pos);
        //print_list(head);
        rounds++;
        //supposed to go around in a circle, always starts from beginning
    }

    return head;
}

char *remove_by_index(node_t **pNode, int index) {
    int i = 0;
    char *retval;
    node_t *current = *pNode;
    node_t *temp_node = NULL;

    if (index == 0){
        return pop_list(pNode);
    }

    for(i = 0; i < index - 1; i++){
        if(current->next == NULL){
            return (char *) -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->name;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

char *pop_list(node_t **pNode) {
    char *retval;
    node_t *next_node = NULL;
    if(*pNode == NULL){
        return NULL;
    }
    next_node = (*pNode)->next;
    retval = (*pNode)->name;
    free(*pNode);
    *pNode = next_node;

    return retval;
}

void print_list(node_t *head) {
    node_t *current = head;

    while(current != NULL){
        printf("%s\n", current->name);
        current = current->next;
    }
}

void list_append(char *string, node_t *head) {
    node_t *current = head;
    while (current->next != NULL){
        current = current->next;
    }

    current->next = malloc(sizeof(node_t));
    current->next->name = string;
    current->next->next = NULL;
}

void gather_input(int *games, int *friends, char **friend_names, int *rounds, int *ducks) {
    int counter;
    int rounds_and_ducks[2] = {0,0};
    int *rd_ptr = rounds_and_ducks;
    char buff[BUFSIZ];
    int ch;

    //scans in the number of games
    /*  gets the amount of games for jimmy the sadist to play. Put into a for loop so we can gather the information
     *  for the rest of the *.in file*/
    //get_ints(&games, 1);
    get_ints(&friends, 1); //scans in the number of friends.

    printf("%d", *games);
    printf("%d\n", *friends);

    //clearing input buffer... took me forever to figure this out...
    while ((ch = getchar()) != '\n' && ch != EOF);

    for (counter = 0; counter < *friends; counter++){
        /*  for loop for the input data from the game. everything points outside for the loop because we need to bring
            the data to other parts of the program*/
        get_name(friend_names, counter, buff);
    }
    //get_int_arr(rd_ptr, 1);

    get_ints(&rounds, 1);
    get_ints(&ducks, 1);

    int i;

    node_t *winners = NULL;

    for (i = 0; i < *rounds; i++) {
        winners = manipulate_input(friends, ducks, friend_names, *rounds);
        output(winners, i);
    }
//    *rounds = rounds_and_ducks[0];
//    *ducks = rounds_and_ducks[1];
//
//    printf("%d", rounds_and_ducks[0]);
//    printf("%d", rounds_and_ducks[1]);

}

void get_name(char **pString, int counter, char buff[]) {
    char *temp;
    fgets(buff, 20, stdin);
    temp = strdup(buff);
    pString[counter] = temp;
}

char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);   // Allocate memory
    if (d != NULL) strcpy (d,s);         // Copy string if okay
    return d;                            // Return new memory
}

//function to pull ints from data
int get_ints(int **pInt, int limit) {

    int i = 1;
    int result;
    while (i <= limit && (result = scanf("%d*[^\n]", *pInt) == 1))
        i++;

    return result;
    return 0;
}

