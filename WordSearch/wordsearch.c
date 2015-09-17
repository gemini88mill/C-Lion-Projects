/*Created by Raphael Miller and a dangerous amount of coffee
 *
 * 09/14/15
 * NID: ra677877
 * COP3502 - guha
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//need to change to directory independent directory.
#define TXT_FILE "/home/raphael/ClionProjects/C-Lion-Projects/WordSearch/dictionary.txt"
#define TEST_FILE "/home/raphael/ClionProjects/WordSearch/hello.txt"

typedef struct{
    size_t used;
    size_t length; //to get length of string
    size_t size;
    char **words;
} Entries;

void initEntries(Entries *a, size_t initial_size);
void insertEntries(Entries *a, char *element);
void freeEntries(Entries *a);
char *strdup (const char *s);


char *get_puzzle_string();

unsigned int get_larger_val_for_grid(unsigned int i, unsigned int i1);


Entries parse_dictionary_word_length(int length, Entries word);

int main() {

    //dictionary level variables ------------------------------------------------
    FILE *txt_file = fopen(TXT_FILE, "r");
    Entries word;
    int j = 0;
    char buff[32][BUFSIZ];
    char *p;
    //---------------------------------------------------------------------------

    //*.in read variables -------------------------------------------------------
    unsigned int input_cases;
    unsigned int rows;
    unsigned int colomns;

    char **puzzle_block;
    char *puzzle_values;

    int k, l;
    //---------------------------------------------------------------------------

    //parse and binary search variable-------------------------------------------
    int max_size_word_length;
    //---------------------------------------------------------------------------


    initEntries(&word, 5); //initialize char array for dictionary

    //block dealing with dictionary value allocation-------------------------------------------
    while(j < sizeof(buff) && fgets(buff[j], sizeof(buff[0]), txt_file)) {
        p = strdup(buff);
        insertEntries(&word, p);
    }
    fclose(txt_file);
    //-----------------------------------------------------------------------------------------

    //check if values are there (debug)------------------------------
    printf("element 0:%s\n", word.words[10]);
    printf("element 1:%s\n", word.words[34534]);
    printf("element 2:%s\n", word.words[114877]);
    //---------------------------------------------------------------

    //accept in file arguements----
    scanf("%d", &input_cases);
    scanf("%d", &rows);
    scanf("%d", &colomns);
    //-----------------------------

    max_size_word_length = get_larger_val_for_grid(rows, colomns);

    //debug
    //printf("%d", max_size_word_length);

    parse_dictionary_word_length(max_size_word_length, word);

    //exit code 139 here-------------------------------
    //puzzle_block = malloc(rows * colomns);
    //puzzle_values = malloc(rows);

    //puzzle_values = get_puzzle_string();
    //-------------------------------------------------

    return 0;
}

Entries parse_dictionary_word_length(int length, Entries word) {
    /*checks each array for the length of the array.
     * then takes those elements from that array and stores them in new struct Entries
     * then sends the struct back with all the words...*/
    Entries results;
    initEntries(&results, 5); //initialize string array for words.

    //first find the number of elements of an array


    return results; //return Entries
}


unsigned int get_larger_val_for_grid(unsigned int i, unsigned int i1) {
    unsigned int larger_val;
    if(i > i1){
        larger_val = i;
    }else{
        larger_val = i1;
    }

    return larger_val;
}

char *get_puzzle_string(){
    char *pStr = NULL;
    pStr = fgets(pStr, 64, stdin);

    return pStr;
}


char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);   // Allocate memory
    if (d != NULL) strcpy (d,s);         // Copy string if okay
    return d;                            // Return new memory
}

//------------functions pertaining to dictionary mem block-------------------------------------------
void initEntries(Entries *a, size_t initial_size){
    a->words = malloc(initial_size * sizeof(char*));
    a->used = 0;
    a->size = initial_size;
}

void insertEntries(Entries *a, char *element){

    if(a->used == a->size ){
        a->size *= 2;
        a->words = (char **)realloc(a->words, a->size * sizeof(char*));
    }

    a->words[a->used++] = element;
}

void freeEntries(Entries *a){
    free(a->words);
    a->words = NULL;
    a->used = a->size = 0;
}
//---------------------------------------------------------------------------------------------------