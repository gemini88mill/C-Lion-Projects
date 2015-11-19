/*Created by:
 *
 * Raphael Miller
 * NID: ra677877
 * 11/15/2015
 *
 * i love samosas
 * boggle.c*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LETTERS 26
#define MAX_WORD_SIZE 10
#define DICTIONARY "/home/raphael/ClionProjects/boogle/dictonary.txt"
#define GRID "/home/raphael/ClionProjects/boogle/boogle.txt"
#define GRID_ROWS 4
#define GRID_COL 4
#define START 0


//data structure init
typedef struct trie{
    int is_word;
    struct trie* next_letter[LETTERS];
};

struct Coordinates{
    char letter;
    int coordinates[2];
    int bool;
};

void insert_word(char *word, struct trie *node, int i);

int check_word(char *word, struct trie *pTrie);
char *check_word_prefix(char *prefix, struct trie *pTrie, int i, struct Coordinates start, struct trie *root);
int search_word(char string[], struct trie *pTrie, int i);
struct trie * init();
char ** grid_init(char **grid);
int search_word_in_grid(char **grid, char *word, int word_index, int x_index, int y_index, int pInt[4][4]);
char *enter_grid(char *string, int i);

struct Coordinates search_grid(char letter, int x, int y, struct Coordinates coordinates);

char **get_grid();

int main() {


    //iteration variables
    int i, n, count = 0, input_case = 0;
    //buffer
    char *buff = malloc(sizeof(char) * MAX_WORD_SIZE);
    //init struct root
    struct trie *root = init();
    //end of struct root init, ready to use

    //scans the number of input cases
    scanf("%d", &input_case);

    //-----------------------pulls from dictionary file-------------------------------------------
    //collect information from dictionary file, houses all possible dictionary entries, additionally; dictionary values
    //should be between 3 and 10 characters, so thats nice
    FILE *fp = fopen(DICTIONARY, "r");
    //catch in case of failure.
    if(!fp){
        return 1;
    }

    //works now from fscanf, but not fgets, im not sure why :(
    fscanf(fp, "%d", &i);
    for(n = 0; n < i; n++) {
        char word[100];
        fscanf(fp, "%s", word);
        insert_word(word, root, count); //seg faults when implemented in while
    } //after this point, all values from dictionary minus the first entry (which is the number of values) is in a trie
    //named trie root in main()
    //--------------------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------------
    //block dealing with the grid to be played, idea here is that all test cases are loaded at once (from example) and
    //placed chopped up later in code. should be fixed later to separate before actual logic, this method is error
    //prone
   char **grid = malloc(sizeof(char*) * GRID_ROWS * GRID_COL);
//    FILE *grid_file = fopen(GRID, "r");
//    int grid_count = 0, k = 0;
//
//    //same as above, collect data using fscanf and drop in 2d char array.
//    fscanf(grid_file, "%d", &grid_count);
//    if(grid_count > 1){
//        grid = realloc(grid, (size_t) ((grid_count * GRID_ROWS) * (grid_count * GRID_COL)));
//    } //realloc in case there are more then one test case
//    for(k = 0; (grid_count * GRID_ROWS) > k; k++){
//        char buffer[5];
//        fscanf(grid_file, "%s", buffer);
//        grid[k] = strdup(buffer);
//        //printf("%s\n", grid[k]);
//
//    }

  // grid = get_grid();

    //---------------------------------------------------------------------------------------------

    //char **grid_ptr = grid;
    //printf("grid_ptr: %s", grid_ptr[0]);
    //printf("grid: %s", grid[2]);
//    int grid_marker[4][4] = {0}; //marker for grid, used to check if tracer has already been there
//    int word_found = search_word_in_grid(grid, "mopi", 0, 0, 0, grid_marker);
//    printf("%i", word_found);

    //char *store = malloc(sizeof(char) * 10);
    int check = search_word("case", root, count);
    printf("%d  ", check);


    struct Coordinates start;
    start.coordinates[0] = 0;
    start.coordinates[1] = 0;

    int is_in_dictionary = check_word(buff, root);
    char* check_prefix = check_word_prefix("c", root, count, start, root);
    printf("returned: %s", check_prefix);

    return 0;
}

char **get_grid() {
    char **grid = malloc(sizeof(char*) * GRID_ROWS * GRID_COL);
    FILE *grid_file = fopen(GRID, "r");
    int grid_count = 0, k = 0;

    //same as above, collect data using fscanf and drop in 2d char array.
    fscanf(grid_file, "%d", &grid_count);
    if(grid_count > 1){
        grid = realloc(grid, (size_t) ((grid_count * GRID_ROWS) * (grid_count * GRID_COL)));
    } //realloc in case there are more then one test case
    for(k = 0; (grid_count * GRID_ROWS) > k; k++){
        char buffer[5];
        fscanf(grid_file, "%s", buffer);
        grid[k] = strdup(buffer);
        //printf("%s\n", grid[k]);

    }
    return grid;
}


char *strdup (const char *s) { //my best friend
    char *d = malloc (strlen (s) + 1);   // Space for length plus nul
    if (d == NULL) return NULL;          // No memory
    strcpy (d,s);                        // Copy the characters
    return d;                            // Return the new string
}

char *enter_grid(char *string, int i) {
    return string;
}

//not working properly, i dont think my logic is right in this one, using new one. instant deprecation.
int search_word_in_grid(char **grid, char *word, int word_index, int x_index, int y_index, int pInt[4][4]) {
    //printf("word: %s\n", word);
    //printf("grid: %s\n", grid[1]);
    if(word_index == strlen(word)){
        printf("found");
        return 1;
    }
    //start at pos 0,0 (top left corner of grid)
    //if within bounds
    if(x_index > -1 && y_index > -1 && x_index < GRID_ROWS && y_index < GRID_COL){
        if(word[word_index] == grid[x_index][y_index] && pInt[x_index][y_index] != 1 ){
            printf("grid: %i,%i: %c\n",x_index, y_index, grid[x_index][y_index]);
            pInt[x_index][y_index] = 1;
            search_word_in_grid(grid, word, word_index + 1, x_index + 1, y_index, pInt);
            search_word_in_grid(grid, word, word_index + 1, x_index, y_index + 1, pInt);
            search_word_in_grid(grid, word, word_index + 1, x_index + 1, y_index + 1, pInt);
            search_word_in_grid(grid, word, word_index + 1, x_index - 1, y_index, pInt);
            search_word_in_grid(grid, word, word_index + 1, x_index, y_index - 1, pInt);
            search_word_in_grid(grid, word, word_index + 1, x_index - 1, y_index - 1, pInt);
            search_word_in_grid(grid, word, word_index + 1, x_index + 1, y_index - 1, pInt);
            search_word_in_grid(grid, word, word_index + 1, x_index - 1, y_index + 1, pInt);
        }
        else if (pInt[x_index][y_index] != 1){
            pInt[x_index][y_index] = 1;
            search_word_in_grid(grid, word, word_index, x_index + 1, y_index, pInt);
            search_word_in_grid(grid, word, word_index, x_index, y_index + 1, pInt);
            search_word_in_grid(grid, word, word_index, x_index + 1, y_index + 1, pInt);
            search_word_in_grid(grid, word, word_index, x_index - 1, y_index, pInt);
            search_word_in_grid(grid, word, word_index, x_index, y_index - 1, pInt);
            search_word_in_grid(grid, word, word_index, x_index - 1, y_index - 1, pInt);
            search_word_in_grid(grid, word, word_index, x_index + 1, y_index - 1, pInt);
            search_word_in_grid(grid, word, word_index, x_index - 1, y_index + 1, pInt);
        }

    }



}

char ** grid_init(char **grid) {

    return grid;
}


//returns 1 for entire word... can be used for final check...
int search_word(char string[], struct trie *pTrie, int i) {
    //returns one if word matches in trie struct
    if (i == strlen(string))
        return pTrie->is_word;

    //printf("string: %c\n", string[i]);
    int index = string[i] - 'a';
    if(pTrie->next_letter[index] == NULL) {

        return 0;
    }

    return search_word(string, pTrie->next_letter[index], i + 1);
}

//works do not touch ever!!!
struct trie * init(){
    //counter var
    int i;

    //create struct
    struct trie* tree = malloc(sizeof(struct trie));
    tree->is_word = 0;

    //set childrens to NULL
    for(i = 0; i < LETTERS; i++){
        tree->next_letter[i] = NULL;
    }

    return tree;
}

//not working correctly
char *check_word_prefix(char *prefix, struct trie *pTrie, int i, struct Coordinates start, struct trie *root) {
    int index = prefix[i] - 'a';
    char letter;
    char *prefix_arr = malloc(sizeof(char) * strlen(prefix + 1));
    int k, l;

    start.bool = 0;

    //load prefix_arr
    for (l = 0; l < strlen(prefix); l++){
        prefix_arr[l] = prefix[l];
        //printf("%c\n", prefix_arr[l]);
    }

    if(i < strlen(prefix)){
        return check_word_prefix(prefix, pTrie->next_letter[index], i + 1, (start), root);
    }
    for(k = 0; k < 26; k++){
        if(pTrie->next_letter[k] != NULL){
            //printf("node here[%d]\n", k);
            letter = (char) (k + 'a');
            start.letter = letter;
            printf("%c:%i\n", letter, i); //displays next letter and position from the prefix!!!
            prefix_arr[l] = letter;
            printf("prefix: %s\n", prefix_arr);
            //printf("send me to grid\n");
            printf("entering information: %i, %i\n", start.coordinates[0], start.coordinates[1]);
            start = search_grid(start.letter, start.coordinates[0], start.coordinates[1], start);
            printf("entering letter: %c\n", letter);
            if(start.bool == 1) {
                printf("found %c at %i, %i\n", letter, start.coordinates[0], start.coordinates[1]);

                check_word_prefix(prefix_arr, pTrie->next_letter[k], i + 1, (start), root);
                int win = search_word(prefix_arr, root, 0);
                printf("prefix_arr: %s", prefix_arr);
                printf("i am the winner %d\n\n", win);
            }
            //give all possible words from prefix
        }
    }

    return prefix_arr;

}

struct Coordinates search_grid(char letter, int x, int y, struct Coordinates coordinates) {
    //get grid from boggle game :)
    //printf("%c\t", letter);
    char **grid = get_grid(); //grid collected...
    //does grid[x][y] == letter?
    if(letter == grid[x][y + 1]) {
        coordinates.coordinates[1] = y + 1;
        coordinates.bool = 1;
        return coordinates;
    }
    if(letter == grid[x + 1][y + 1]){
        coordinates.coordinates[1] = y + 1;
        coordinates.coordinates[0] = x + 1;
        coordinates.bool = 1;
        return coordinates;
    }

    if(letter == grid[x + 1][y]){
        coordinates.coordinates[0] = x + 1;
        coordinates.bool = 1;
        return coordinates;
    }
    else{
        coordinates.bool = 0;
        return coordinates;
    }

    getchar();


}

int check_word(char *word, struct trie *pTrie) {
    return 0;
}

void insert_word(char *word, struct trie *node, int i) {

    //checks if complete word is inserted, if so return 1 and is_word = 1
    if(i == strlen(word)){

        node->is_word = 1;
        return;
    }

    //next letter create the word.
    int index = word[i] - 'a';
    if (node->next_letter[index] == NULL)
        node->next_letter[index] = init();

    //run for all words down the list.
    insert_word(word, node->next_letter[index], i + 1);

}