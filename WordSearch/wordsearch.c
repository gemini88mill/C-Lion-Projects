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

void initDictionary(Entries *a, size_t initial_size);
void insertEntries(Entries *a, char *element);
void freeEntries(Entries *a);

int main() {

    FILE *txt_file = fopen(TXT_FILE, "r");
    Entries word;
    int i;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    initDictionary(&word, 5);

    insertEntries(&word, "the book");

    while ((read = getline(&line, &len, txt_file)) != -1) {
        char str[sizeof(line)];
        //printf("Retrieved line of length %zu :\n", read);
        //printf("%s", line);
        //strncpy(str, line, sizeof(line));
        //printf("%s\n", str);
        insertEntries(&word, line);
    }

    printf("%s\n", word.words[1]);
    printf("%lu\n", word.used);

    return 0;
}

void initDictionary(Entries *a, size_t initial_size){
    a->words = malloc(initial_size * sizeof(char*));
    a->used = 0;
    a->size = initial_size;
}

void insertEntries(Entries *a, char *element){
    char *str = NULL;
    if(a->used == a->size ){
        a->size *= 2;
        a->words = (char **)realloc(a->words, a->size * sizeof(char*));
    }
    printf("%s", element);
    str = memcpy(str, element, (size_t) 255);
    a->words[a->used++] = str;
}

void freeEntries(Entries *a){
    free(a->words);
    a->words = NULL;
    a->used = a->size = 0;
}