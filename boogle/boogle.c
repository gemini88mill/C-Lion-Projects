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


char ** grid_init(char **pString);

int main() {


    int i, n, count = 0, input_case = 0;
    char *buff = malloc(sizeof(char) * MAX_WORD_SIZE);
    //init struct root
    struct trie *root = init();
    //end of struct root init, ready to use

    scanf("%d", &input_case);

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

//    char **grid = malloc(sizeof(char*) * GRID_ROWS * GRID_COL);
//    grid = grid_init(grid);
//    printf("%s\n", grid[0]);

    //char *store = malloc(sizeof(char) * 10);
    int check = search_word("yellow", root, count);
    printf("%d", check);

    int is_in_dictionary = check_word(buff, root);
    int check_prefix = check_word_prefix("yell", root, count);
    printf("%d", check_prefix);

    return 0;
}

char ** grid_init(char **pString) {
    FILE *grid = fopen(GRID, "r");
    int grid_count = 0, i = 0;

    fscanf(grid, "%d", &grid_count);
    if(grid_count > 1){
        pString = realloc(pString, (size_t) ((grid_count * GRID_ROWS) * (grid_count * GRID_COL)));
    }
    for(i = 0; (grid_count * GRID_ROWS) > i; i++){
        char buff[5];
        fscanf(grid, "%s", buff);
        pString[i] = buff;
        //printf("%s\n", pString[i]);
    }
    return pString;
}


//returns 1 for entire word...
int search_word(char string[], struct trie *pTrie, int i) {
    //returns one if word matches in trie struct
    if (i == strlen(string))
        return pTrie->is_word;

    printf("string: %c\n", string[i]);
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
            printf("node here[%d]\n", k);
            return check_word_prefix(prefix, pTrie->next_letter[k], i + 1);
        }
    }


    //return search_word(prefix, pTrie->next_letter[index], i + 1);
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