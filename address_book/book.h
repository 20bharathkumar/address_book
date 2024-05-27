#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct _Book
{
    char name[100];

}AddBook;*/
//structure to store data
typedef struct _book
{
    char name[100];
    char mob_num[11];
    char mail[100];
    char address[100];
    
    FILE *fptr;
    char *fname;

    int count;

}AddBook;


typedef enum 
{
    failure,
    success,
}Status;
//FILE *fptr;
//opening the file
Status open_file(char *file[]);

//validating the file
Status valid_file(char *argv,AddBook *adBook);

//adding contact to file
Status add_contact(AddBook *adBook);

//searching contact from the file
Status search_contact(AddBook *adBook);

//displaying all data from file
Status display_contact(AddBook *adBook);

//editing contact from file
Status edit_contact(AddBook *adBook);

//deleteing contact from file
Status delete_contact(AddBook *adBook);

#endif
