#include <stdio.h>
#include <stdlib.h>

#define TXT_FILE "/home/raphael/ClionProjects/WordSearch/dictionary.txt"

int dictionary();

void fill_array_dictionary();

int main() {
    //printf("hello, world");

    /*
     * Word Search - allows the user to input test cases for a word search and outputs solutions to the terminal.
     *  Patent Pending TM 2015
     *
     *  Uses dictionary file that has every word in the english dictionary, gathered from a pre-web2.0 website
     *  Source: http://www.angelfire.com/extreme4/safer_sephiroth/EVERY_WORD_EVER.htm
     *
     *  first input line: int - for number of test cases
     *  second input line: int x 2 - for number of rows and columns
     *  next input lines: chars(rows)(columns) - for the actual letters for the word search
     *  rinse and repeat
     *
     *  ...*/

    //initialize dictionary function.
    int dictionary_valid;


    dictionary_valid = dictionary();
    return dictionary_valid;
}

int dictionary() {
    /*
     * Dictionary function:
     * initializes the dictionary to be used in the program.
     * */
    FILE *txt_file = fopen ( TXT_FILE, "r");
    char *word = malloc(sizeof(char));
    char **hold = malloc(sizeof(char)*sizeof(char));
    int index = 0;

    //char ch = getc (txt_file);

        if (word == NULL) {
            perror("Error opening file");
            return (-1);
        }
    while(txt_file != NULL) {
        if (fgets(word, 100, txt_file) != NULL) {
            puts(word);

        }
        hold[index] = word;
        index++;
    }



    fclose (txt_file);
    free(word);

    //---prints out file contents for debug------------------------


    //-------------------------------------------------------------


    fill_array_dictionary();

    return 0;

}

void fill_array_dictionary() {
    //fills array with dictionary.txt file to terminal...


}