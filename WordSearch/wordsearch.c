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

char *read_line(FILE *pFILE);

int main() {

    FILE *txt_file = fopen(TXT_FILE, "r");
    Entries word;
    int i, j = 0;
    char line[32];
    char buff[32][BUFSIZ];
    char *p = line;
    size_t len = 0;
    ssize_t read;

    initEntries(&word, 5);

    fgets(line, 32, txt_file);

    puts(line);

    i = atoi(line);
    printf("%d\n", i);

    while(j < sizeof(buff) && fgets(buff[j], sizeof(buff[0]), txt_file)) {
        p = strdup(buff);
        insertEntries(&word, p);
    }

    fclose(txt_file);

    printf("element 0:%s\n", word.words[0]);
    printf("element 1:%s\n", word.words[1]);
    printf("element 2:%s\n", word.words[2]);
    printf("element 3: %s\n", word.words[3]);
    printf("space used: %lu\n", word.used);



    return 0;
}

char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);   // Allocate memory
    if (d != NULL) strcpy (d,s);         // Copy string if okay
    return d;                            // Return new memory
}

char *read_line(FILE *pFILE) {
    char buff[32] = {};

    fgets(buff, sizeof(buff), pFILE);

    return buff;
}

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