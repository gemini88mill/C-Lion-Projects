#include <stdio.h>
#include <stdlib.h>

#define TXT_FILE "/home/raphael/ClionProjects/WordSearch/dictionary.txt"
#define CHUNK 1024

int dictionary();

void fill_array_dictionary();

int main() {
    //printf("hello, world");

    /*
     * Word Search - allows the user to input test cases for a word_str search and outputs solutions to the terminal.
     *  Patent Pending TM 2015
     *
     *  Uses dictionary file that has every word_str in the english dictionary, gathered from a pre-web2.0 website
     *  Source: http://www.angelfire.com/extreme4/safer_sephiroth/EVERY_WORD_EVER.htm
     *
     *  first input line: int - for number of test cases
     *  second input line: int x 2 - for number of rows and columns
     *  next input lines: chars(rows)(columns) - for the actual letters for the word_str search
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

    //------------------variable declaration-----------------------------
    FILE *txt_file;                                                 //file

    char *word_str = malloc(sizeof(char *) * sizeof(char));
    char tester[1024];
    int index = 0, rows = 0 ;
    int buff_size = 64;
    int txt_file_length;
    size_t nread;
    //-------------------------------------------------------------------



    txt_file = fopen(TXT_FILE, "r");
    if (txt_file == NULL){
        return 1;
    }

    if (txt_file) {
        while ((nread = fread(word_str, 1, sizeof buff_size, txt_file)) > 0) {
            //fwrite(word_str, 1, nread, stdout);
            fgets(word_str, sizeof nread, txt_file);
        }
        if (ferror(txt_file)) {
            /* deal with error */
        }
        fclose(txt_file);
    }
}

void fill_array_dictionary() {
    //fills array with dictionary.txt file to terminal...


}