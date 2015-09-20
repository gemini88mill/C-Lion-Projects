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


#define TXT_FILE "/home/raphael/ClionProjects/WordSearch/dictionary.txt"
#define TEST_FILE "/home/raphael/ClionProjects/WordSearch/hello.txt"
#define TRUE 1
#define FALSE 0

typedef struct{
    size_t used;
    size_t size;
    char **words;
} Entries;

void init_Entries(Entries *a, size_t initial_size);
void insertEntries(Entries *a, char *element);
void freeEntries(Entries *a);
char *strdup (const char *s);


char *get_puzzle_string();


int binary_search(char **pString, char *search_ptr, int low, int high, size_t length);

int find_horizontal(char **dictionary, char **grid, unsigned int rows, unsigned int colomns, size_t i, Entries solutions);

int main() {

    //dictionary level variables ------------------------------------------------
    FILE *txt_file = fopen(TXT_FILE, "r");
    Entries dictionary;
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


    //---------------------------------------------------------------------------

    //binary search variables ---------------------------------------------------
    char search_string[32]; //testing search string.
    char *search_ptr = search_string; //ptr to binary search string.

    int result;
    //---------------------------------------------------------------------------

    //grid values----------------------------------------------------------------

    //---------------------------------------------------------------------------


    init_Entries(&dictionary, 5); //initialize char array for dictionary

    //block dealing with dictionary value allocation-------------------------------------------
    while(j < sizeof(buff) && fgets(buff[j], sizeof(buff[0]), txt_file)) {
        p = strdup(buff);
        insertEntries(&dictionary, p);
    }
    fclose(txt_file);
    //-----------------------------------------------------------------------------------------

    //check if values are there (debug)------------------------------
    //printf("element 0:%s\n", dictionary.words[1]);
    //printf("element 1:%s\n", dictionary.words[34534]);
    //printf("element 2:%s\n", dictionary.words[114877]);
    //---------------------------------------------------------------

    //accept in file arguements----
    scanf("%d", &input_cases);
    scanf("%d", &rows);
    scanf("%d", &colomns);
    //-----------------------------

    //binary search ------------------------------------------------
    scanf("%s", search_ptr);

    if((result = binary_search(dictionary.words, search_ptr, 0, (int) dictionary.used - 1, sizeof(search_ptr))) != 0){
        //printf("%d", result);

       printf("found %s at position %d\n", search_ptr, result);
    } else{
        printf("%d", result);
        printf("%s not found", search_ptr);
    }
    //--------------------------------------------------------------

    //grid level----------------------------------------------------
    Entries grid;
    Entries solutions;
    char grid_buff[32];
    char *pp;
    int k, l;

    init_Entries(&grid, 5);
    init_Entries(&solutions, 5);

    for(k = 0; k < rows; k++){
        scanf("%s", grid_buff);
        pp = strdup(grid_buff);
        insertEntries(&grid, pp);
        //printf("%s\n", grid.words[k]);
    }

    int check;

    //function find_horizontally
    /*start position*/
    check = find_horizontal(dictionary.words, grid.words, rows, colomns, dictionary.used - 1, solutions);
    printf("check val: %i\n", check);

    for(l = 0; l < solutions.size; l++) {
        printf("solutions: %s\n", solutions.words[l]);
    }
    //--------------------------------------------------------------

    return 0;
}

int find_horizontal(char **dictionary, char **grid, unsigned int rows, unsigned int colomns, size_t i,
                    Entries solutions) {
    //finds all horizontal values in grid.
    char grid_section[32];
    char section_test[32];
    size_t t;
    int k;
    int check = 0;
    size_t high = i;
    int count = 0;

    memset(section_test, '\0', sizeof(section_test));
    strcpy(grid_section, *grid);

    for(t = 3; t < sizeof(grid_section); t++) {
        strncpy(section_test, grid_section, t);
        printf("%s\n", section_test);
        check = binary_search(dictionary, section_test, 0, (int) (high - 1), sizeof(section_test));
        if (check != 0){
            insertEntries(&solutions, section_test);
            check = TRUE;
            count++;
            return check;
        }
        for(k = 1; k < sizeof(section_test); k++) {
            memmove(section_test, section_test + 1, strlen(section_test) );
            printf("%s\n", section_test);
            check = binary_search(dictionary, section_test, 0, (int) (high - 1), sizeof(section_test));
            if (check != 0){
                insertEntries(&solutions, section_test);
                check = TRUE;
                count++;
                return check;
            }
        }

    }

    printf("count: %d\n", count);
    return check;
}

int binary_search(char **pString, char *search_ptr, int low, int high, size_t length) {

    /*local store chars*/
    char key_string[16];
    char dictionary_string[16];

    //test for end of recurse loop
    if (high < low) {
        return 0;
    }

    int mid = (low + high) / 2;
    int result;

    //copy values into locals
    strcpy(dictionary_string, pString[mid]);
    strcpy(key_string, search_ptr);

    //remove \r\n from dictionary_string
    dictionary_string[strcspn(dictionary_string, "\r\n")] = 0;

    //print (for debug)
    //printf("%s\n", dictionary_string);


    //recursed binary search ------------------------------------------------
    result = strncmp(dictionary_string, key_string, length);
    if (result > 0) {
        return binary_search(pString, key_string, low, mid - 1, length);
    } else if (result < 0) {
        return binary_search(pString, key_string, mid + 1, high, length);
    } else if (result == 0)  {
        return mid;
    }
    //-----------------------------------------------------------------------
    return 0; //will never get here but compiler is yelling at me and I don't like it to yell :)
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
void init_Entries(Entries *a, size_t initial_size){
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