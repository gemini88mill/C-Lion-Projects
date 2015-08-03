#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*Linked Lists in C
 *
 * Linked Lists are a way to store data with structures so that the programmer can automatically create a new place to
 * store data whenever necessary. Specifically, the programmer writes a struct definition that contains variables
 * holding information about something and that has a pointer to a struct of its same type (must be a pointer, other-
 * wise it would create an infinite loop). Each of these individual structs or classes in the list is commonly known as
 * a node or element of the list.
 *
 * source: http://www.cprogramming.com/tutorial/c/lesson15.html*/

struct Book{
    char title[50];
    char author[50];
    char subject[50];
    int book_id;
};

int main(){
    printf("hello, world");

    struct Book book1;
    struct Book book2;

    strcpy(book1.author, "C Programming");
    strcpy(book2.author, "the book");

    

    return 0;
}