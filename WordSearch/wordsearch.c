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

typedef struct{
    size_t used;
    size_t size;
    char **words;
} Entries;

void initEntries(Entries *a, size_t initial_size);
void insertEntries(Entries *a, char *element);
void freeEntries(Entries *a);
char *strdup (const char *s);


char *get_puzzle_string();


int binary_search(char **pString, char *search_ptr, int low, int high, size_t length);

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

    //binary search variables ---------------------------------------------------
    char search_string[32]; //testing search string.
    char *search_ptr = search_string; //ptr to binary search string.



    int i = 0,result, x = 0;
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
    printf("element 0:%s\n", word.words[1]);
    printf("element 1:%s\n", word.words[34534]);
    printf("element 2:%s\n", word.words[114877]);
    //---------------------------------------------------------------

    //accept in file arguements----
    scanf("%d", &input_cases);
    scanf("%d", &rows);
    scanf("%d", &colomns);
    //-----------------------------

    //binary search ------------------------------------------------
    scanf("%s", search_ptr);

    if((result = binary_search(word.words, search_ptr, 0, (int) word.used - 1, sizeof(search_ptr))) != 0){
        printf("%d", result);

       printf("found %s at position %d", search_ptr, result);
    } else{
        printf("%d", result);
        printf("%s not found", search_ptr);
    }
    //--------------------------------------------------------------


    return 0;
}

int binary_search(char **pString, char *search_ptr, int low, int high, size_t length) {

    char key_string[16];
    char dictionary_string[16];



    if (high < low) {
        return 0;
    }
    int mid = (low + high) / 2;
    int result;

    strcpy(dictionary_string, pString[mid]);
    strcpy(key_string, search_ptr);

    dictionary_string[strcspn(dictionary_string, "\r\n")] = 0;

    printf("%s\n", dictionary_string);
    result = strncmp(dictionary_string, key_string, length);
    if (result > 0) {
        return binary_search(pString, key_string, low, mid - 1, length);
    } else if (result < 0) {
        return binary_search(pString, key_string, mid + 1, high, length);
    } else if (result == 0)  {
        return mid;
    }


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