/*Created by:
 *
 * Raphael Miller
 * NID: ra677877
 * 11/15/2015
 *
 * i love samosas
 *
 * 11.22.2015 - doesn't work correctly. does the first list fine but after that it just re-prints all over again
 * I decided to get as many words as a could in a feeble attempt to get more points, hopefully it works...
 *
 * please have mercy on my soul
 *
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


//data structure init
typedef struct trie{
    int is_word;
    struct trie* next_letter[LETTERS];
};

struct Coordinates{
    char letter;
    int coordinates[2];
    int grid_map[4][4];
    int bool;
};

//prototypes-----------------------------------------------------------
void insert_word(char *word, struct trie *node, int i);

int search_word(char string[], struct trie *pTrie, int i);

char *check_word_prefix(char *prefix, struct trie *pTrie, int i, struct Coordinates start, struct trie *root,
                        char **grid);
char **get_grids(int *grid_count);

struct Coordinates search_adjacent(char letter, char **grid, int y, int x, struct Coordinates coordinates);
struct trie * init();
//-----------------------------------------------------------------------
//----
int main() {


    //iteration variables
    int i, n, count = 0, input_case = 0;
    //buffer
    char *buff = malloc(sizeof(char) * MAX_WORD_SIZE);
    //init struct root
    struct trie *root = init();
    //end of struct root init, ready to use

    //scans the number of input cases


    //-----------------------pulls from dictionary file-------------------------------------------
    //collect information from dictionary file, houses all possible dictionary entries, additionally; dictionary values
    //should be between 3 and 10 characters, so thats nice
    FILE *fp = fopen(DICTIONARY, "r");
    //catch in case of failure.
    if (!fp) {
        return 1;
    }

    //works now from fscanf, but not fgets, im not sure why :(
    fscanf(fp, "%d", &i);
    for (n = 0; n < i; n++) {
        char word[100];
        fscanf(fp, "%s", word);
        insert_word(word, root, count); //seg faults when implemented in while
    }
    fclose(fp);

    //after this point, all values from dictionary minus the first entry (which is the number of values) is in a trie
    //named trie root in main()
    //--------------------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------------
    //block dealing with the grid to be played, idea here is that all test cases are loaded at once (from example) and
    //placed chopped up later in code. should be fixed later to separate before actual logic, this method is error
    //prone
    char **grid;

    //---------------------------------------------------------------------------------------------

    //char *store = malloc(sizeof(char) * 10);
    //int check = search_word("case", root, count);
    //printf("%d  ", check);


    struct Coordinates start;
    start.coordinates[0] = 0;
    start.coordinates[1] = 0;

    int game = 0;
    int iter = 0;
    int grid_map = GRID_ROWS;

    grid = get_grids(&game);


    //logic area ----------------------------------------

    //will print out all values found, it might even wrap all grids together. should be interesting.
    for(iter = 0; iter < game; iter++) {
        printf("Words for Game #%i\n", iter + 1);
        int j, k;
        for (j = 0; j < (GRID_ROWS * game); j++) {
            for (k = 0; k < GRID_ROWS; k++) {
                char c = grid[j][k];
                char str[2] = "\0";
                str[0] = c;
                start.coordinates[0] = j;
                start.coordinates[1] = k;
                int index = c - 'a';
                //printf("%c: %i\n", c, index);

                //enter logic
                check_word_prefix(str, root->next_letter[index], count, start, root, grid);

            }
        }
    }
    //int index = 2;
    //check_word_prefix("c", root->next_letter[index], count, start, root, grid);

    //free the mallocs
    free(buff);
    free(grid);
    free(root);
    return 0;
}

/*get_grids() - takes information from boggle.txt and places information in 2d char array.*/
char **get_grids(int *grid_count) {
    char **grid = malloc(sizeof(char*) * GRID_ROWS * GRID_COL);
    FILE *grid_file = fopen(GRID, "r");
    int k = 0;

    //same as above, collect data using fscanf and drop in 2d char array.

    //collects number of grids for particular test case.
    fscanf(grid_file, "%d", grid_count);
    if(*grid_count > 1){
        grid = realloc(grid, (size_t) ((*grid_count * GRID_ROWS) * (*grid_count * GRID_COL)));
    } //realloc in case there are more then one test case
    for(k = 0; (*grid_count * GRID_ROWS) > k; k++){
        char buffer[5];
        fscanf(grid_file, "%s", buffer);
        grid[k] = strdup(buffer);
        //printf("%s\n", grid[k]);

    }

    fclose(grid_file);
    //returns all grids, must be separated to individual games
    return grid;
}

//taken from POSIX standard lib.
char *strdup (const char *s) { //my best friend
    char *d = malloc (strlen (s) + 1);   // Space for length plus nul
    if (d == NULL) return NULL;          // No memory
    strcpy (d,s);                        // Copy the characters
    return d;                            // Return the new string
}

//search_word() - searched trie to verify if word is in trie.
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

/*trie* init() - initalizes the trie*/
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
//tries each starting letter, breaks down somewhere in here.
char *check_word_prefix(char *prefix, struct trie *pTrie, int i, struct Coordinates start, struct trie *root,
                        char **grid) {


    int index = prefix[i] - 'a'; //c - a = 2 ca - a
    char letter;
    char *prefix_arr = malloc(sizeof(char) * strlen(prefix + 1));
    int k = 0, l, win = 0;

    start.bool = 0;

    //load prefix_arr
    for (l = 0; l < strlen(prefix); l++){
        prefix_arr[l] = prefix[l];
        //printf("%c\n", prefix_arr[l]);
    }



    for(k = 0; k < 26; k++){
        if(pTrie != NULL && pTrie->next_letter[k] != NULL){
            letter = (char) (k + 'a');
            start.letter = letter;
            prefix_arr[l] = letter;
            start.grid_map[4][4] = 0;

            start = search_adjacent(start.letter, grid, start.coordinates[0], start.coordinates[1], start);
            //find if these letters are adjacent to corresponding letter.
            //printf("%i\n", start.bool);

            if(start.bool == 1){
                win = search_word(prefix_arr, root, 0);
                if (win == 1)
                    printf("%s\n", prefix_arr);
                if(pTrie->next_letter[k] != NULL) {
                    check_word_prefix(prefix_arr, pTrie->next_letter[k], i + 1, (start), root, grid);
                }
            }
        }
    }
    return prefix;

}

struct Coordinates search_adjacent(char letter, char **grid, int y, int x, struct Coordinates coordinates) {
     //
    //check adjacent squares

    //set starting y and x to one...
    coordinates.grid_map[y][x] = 1;

    if(x < GRID_ROWS && y < 7) {
        if (letter == grid[y][x + 1]) { //right one
            coordinates.grid_map[y][x + 1] = 1;
            coordinates.bool = 1;
            coordinates.coordinates[0] = y;
            coordinates.coordinates[1] = x + 1;
            //printf("%c found", grid[y][x + 1]);
            return coordinates;
        }
        if (letter == grid[y + 1][x]) {
            coordinates.grid_map[y + 1][x] = 1;
            coordinates.bool = 1;
            coordinates.coordinates[0] = y + 1;
            coordinates.coordinates[1] = x;
            //printf("%c found", grid[y + 1][x]);
            return coordinates;
        } //down one
        if (letter == grid[y + 1][x + 1]) {
            coordinates.grid_map[y + 1][x + 1] = 1;
            coordinates.bool = 1;
            coordinates.coordinates[0] = y + 1;
            coordinates.coordinates[1] = x + 1;
            //printf("%c found", grid[y + 1][x + 1]);
            return coordinates;
        } //diagonal one

        if (x > 0 && y > 0) {
            if (letter == grid[y - 1][x]){
                coordinates.grid_map[y - 1][x] = 1;
                coordinates.bool = 1;
                coordinates.coordinates[0] = y - 1;
                coordinates.coordinates[1] = x;
                //printf("%c found", grid[y - 1][x]);
                return coordinates;
            }
            if (letter == grid[y][x - 1]){
                coordinates.grid_map[y][x - 1] = 1;
                coordinates.bool = 1;
                coordinates.coordinates[0] = y;
                coordinates.coordinates[1] = x - 1;
                //printf("%c found", grid[y][x - 1]);
                return coordinates;
            }
            if (letter == grid[y - 1][x - 1]){
                coordinates.grid_map[y - 1][x - 1] = 1;
                coordinates.bool = 1;
                coordinates.coordinates[0] = y - 1;
                coordinates.coordinates[1] = x - 1;
                //printf("%c found", grid[y - 1][x - 1]);
                return coordinates;
            }
            if (letter == grid[y - 1][x + 1]){
                coordinates.grid_map[y - 1][x + 1] = 1;
                coordinates.bool = 1;
                coordinates.coordinates[0] = y - 1;
                coordinates.coordinates[1] = x + 1;
                //printf("%c found", grid[y - 1][x + 1]);
                return coordinates;
            }
            if (letter == grid[y + 1][x - 1]){
                coordinates.grid_map[y + 1][x - 1] = 1;
                coordinates.bool = 1;
                coordinates.coordinates[0] = y + 1;
                coordinates.coordinates[1] = x - 1;
                //printf("%c found", grid[y + 1][x - 1]);
                return coordinates;
            }
        }
    }

    coordinates.bool = 0;
    return coordinates;

}


/*insert_word() - inserts word for trie. accepts 1 word and places into trie.
 * recursion happens to find next letter in word. */
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