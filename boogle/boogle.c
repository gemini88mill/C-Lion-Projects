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

void insert_word(char *word, struct trie *node, int i);

int check_word(char *word, struct trie *pTrie);
int check_word_prefix(char *prefix, struct trie *pTrie, int i);
int search_word(char string[], struct trie *pTrie, int i);

struct trie * init();


char ** grid_init(char **grid);

int search_word_in_grid(char **grid, char *word, int word_index, int x_index, int y_index);

char *enter_grid(char *string, int i);

int main() {


    int i, n, count = 0, input_case = 0;
    char *buff = malloc(sizeof(char) * MAX_WORD_SIZE);
    //init struct root
    struct trie *root = init();
    //end of struct root init, ready to use

    scanf("%d", &input_case);

    //-----------------------pulls from dictionary file-------------------------------------------
    FILE *fp = fopen(DICTIONARY, "r");
    if(!fp){
        return 1;
    }

    //works now from fscanf, but not fgets, im not sure why :(
    fscanf(fp, "%d", &i);
    for(n = 0; n < i; n++) {
        char word[100];
        fscanf(fp, "%s", word);
        insert_word(word, root, count); //seg faults when implemented in while
    }
    //--------------------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------------
    char **grid = malloc(sizeof(char*) * GRID_ROWS * GRID_COL);
    FILE *grid_file = fopen(GRID, "r");
    int grid_count = 0, k = 0;

    fscanf(grid_file, "%d", &grid_count);
    if(grid_count > 1){
        grid = realloc(grid, (size_t) ((grid_count * GRID_ROWS) * (grid_count * GRID_COL)));
    }
    for(k = 0; (grid_count * GRID_ROWS) > k; k++){
        char buffer[5];
        fscanf(grid_file, "%s", buffer);
        grid[k] = strdup(buffer);
        //printf("%s\n", grid[k]);

    }
    //---------------------------------------------------------------------------------------------

    //char **grid_ptr = grid;
    //printf("grid_ptr: %s", grid_ptr[0]);
    //printf("grid: %s", grid[2]);
    int word_found = search_word_in_grid(grid, "mopi", 0, 0, 0);
    printf("%i", word_found);

    //char *store = malloc(sizeof(char) * 10);
    int check = search_word("yellow", root, count);
    //printf("%d", check);

    int is_in_dictionary = check_word(buff, root);
    int check_prefix = check_word_prefix("a", root, count);
    //printf("%d", check_prefix);

    return 0;
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

int search_word_in_grid(char **grid, char *word, int word_index, int x_index, int y_index) {
    //printf("word: %s\n", word);
    //printf("grid: %s\n", grid[1]);

    if(word_index == strlen(word)){
        printf("found");
        return 1;
    }
    //start at pos 0,0 (top left corner of grid)
    if(word[word_index] == grid[x_index][y_index]) {
        printf("grid: %i,%i: %c\n",x_index, y_index, grid[x_index][y_index]);


        if(x_index > -1 && y_index > -1 && x_index < GRID_ROWS && y_index < GRID_COL) {
            //check right
            search_word_in_grid(grid, word, word_index + 1, x_index + 1, y_index);
            //check diagonal
            search_word_in_grid(grid, word, word_index + 1, x_index + 1, y_index + 1);
            //check down
            search_word_in_grid(grid, word, word_index + 1, x_index, y_index + 1);
        }else {
            return 2;
        }
    }
    //if statement for failed cases
    else{
        if(x_index > -1 && y_index > -1 && x_index < GRID_ROWS && y_index < GRID_COL) {
            //check right
            search_word_in_grid(grid, word, word_index, x_index + 1, y_index);
            //check diagonal
            search_word_in_grid(grid, word, word_index, x_index + 1, y_index + 1);
            //check down
            search_word_in_grid(grid, word, word_index, x_index, y_index + 1);
        }else {
            return 2;
        }
    }



}

char ** grid_init(char **grid) {

    return grid;
}


//returns 1 for entire word...
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
int check_word_prefix(char *prefix, struct trie *pTrie, int i) {
    int index = prefix[i] - 'a';
    int k;

    if(i < strlen(prefix)){
        return check_word_prefix(prefix, pTrie->next_letter[index], i + 1);
    }
    for(k = 0; k < 26; k++){
        if(pTrie->next_letter[k] != NULL){
            //printf("node here[%d]\n", k);
            check_word_prefix(prefix, pTrie->next_letter[k], i + 1);
        }
    }



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