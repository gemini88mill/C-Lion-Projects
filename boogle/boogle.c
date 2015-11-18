/*Created by:
 *
 * Raphael Miller
 * NID: ra677877
 * 11/15/2015
 *
 * boggle.c*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LETTERS 26
#define MAX_WORD_SIZE 10


//data structure init
typedef struct trie{
    int is_word;
    struct trie* next_letter[LETTERS];
};

void insert_word(char *word, struct trie *node, int i);

int check_word(char *word, struct trie *pTrie);
int check_word_prefix(char *word, struct trie *pTrie);
int search_word(char string[], struct trie *pTrie, int i);

struct trie * init();

int main() {
    

    int i;
    char *word = malloc(sizeof(char) * MAX_WORD_SIZE);
    //init struct root
    struct trie *root = init();
    //end of struct root init, ready to use

    word = "book";

    insert_word(word, root, 0);

    int check = search_word("book", root, 0);
    printf("%d", check);

    int is_in_dictionary = check_word(word, root);
    int check_prefix = check_word_prefix(word, root);

    return 0;
}

//returns 1 for entire word...
int search_word(char string[], struct trie *pTrie, int i) {
    if (i == strlen(string))
        return pTrie->is_word;

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

int check_word_prefix(char *word, struct trie *pTrie) {
    return 0;
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