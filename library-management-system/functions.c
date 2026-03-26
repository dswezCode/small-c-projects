/* 
This file contains all the functions of
the program (library v3)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
//header
#include "functions.h"

typedef struct BookNode
{
    char book_name[100];
    char author_name[100];
    int pages;
    float price;
    struct BookNode *next;
} Book;

//the head of the linked list
Book *head = NULL;

/* functions */

//function to insert a book
void insertBook(void)
{
    //allocating memory
    Book *new_book = (Book*)malloc(sizeof(Book));
    
    //check if malloc failed
    if (new_book == NULL)
    {
        printf("memory allocation failed\n");
        return;
    }

    printf("\n");

    printf("enter book name \n");
    scanf(" %99[^\n]", new_book->book_name);

    printf("enter author name: \n");
    scanf(" %99[^\n]", new_book->author_name);

    printf("enter page number: \n");
    while(scanf(" %d", &new_book->pages) != 1)
    {
        printf("please enter a number\n");
            
        // Call the janitor to clear out the bad letters
        while(getchar() != '\n');
    }
            
    printf("enter price:\n");
    while(scanf(" %f", &new_book->price) != 1)
    {
        printf("please enter a number\n");
        // Call the janitor to clear out the bad letters
        while(getchar() != '\n');
    }
        
    //linking the new book to the linked list
    new_book->next = head;
    head = new_book;    
    
}

//function to remove book by name
void removeBook(void)
{
    char book_to_remove[100];
    Book *current = head;
    Book *previous = NULL;

    printf("please enter the name of the book you wish to remove:\n");
    scanf(" %99[^\n]", book_to_remove);
    printf("\n");
    
    if(current == NULL)
    {
        printf("there are no books in the library\n");
        return;
    }

    //looping thru the linked list
    while (current != NULL)
    {
        //if we found the book to remove
        if(strcmp(book_to_remove, current->book_name) == 0)
        {   
            
            //the book is the first book in the linked list
            if(previous == NULL)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            //release memory
            free(current);
            printf("removed the book\n");
            return;
        }
        
        previous = current;
        current = current->next;
        
    }
    printf("no such book in the library\n");


    
}

//function to show book info
void findBook(void)
{
    char book_to_find[100];
    int found = 0;
    Book *current = head;

    printf("please enter the books name: \n");
    scanf(" %99[^\n]", book_to_find);
    printf("\n");

    if (current == NULL)
    {
        printf("no books in the library\n");
        return;
    }

    //loop thru the library
    while (current != NULL)
    {
        //if we found at least one such book
        if ((strcmp(book_to_find, current->book_name) == 0))
        {   
            found = 1;

            printf("Book: %s \n", current->book_name);
    
            printf("Author: %s \n", current->author_name);
    
            printf("Pages: %d \n", current->pages);
    
            printf("Price: %.2f \n", current->price);

        }

        current = current->next;
    }
    
    if(found == 0)
    {
        printf("no such book exists please try again\n\n");
    }
}

//find books by author name
void findByAuthor(void)
{
    char author_find[100];
    //bool flag for finding a book
    int found = 0;
    Book *current = head;


    printf("please enter the author name: \n");
    scanf(" %99[^\n]", author_find);
    printf("\n");

    if(current == NULL)
    {
        printf("no books in the library\n");
        return;
    }

    //loop thru the library
    while (current != NULL)
    {
         
        //if we found the author
        if ((strcmp(author_find, current->author_name) == 0))
        {
            //mark as found
            found = 1;

            printf("Book: %s \n", current->book_name);
    
            printf("Author: %s \n", current->author_name);
    
            printf("Pages: %d \n", current->pages);
    
            printf("Price: %.2f \n", current->price);

            printf("\n");

        }

        current = current->next;
        
    }
    
    //if no books are found
    if(found == 0)
    {
        printf("author was not found \n");
    }
}    

//count all the books in the library
void countBooks(void)
{
    int count = 0;
    Book *current = head;
    printf("\n");

    while(current != NULL)
    {   
        //count the books
        count ++;

        current = current->next;
    }

    printf("the number of books in the library is: %d\n\n", count);
}

//show all the books in the library
void showAllBooks(void)
{
    int counter = 0;
    Book *current = head;
    printf("\n");

    if(current == NULL)
    {
        printf("no books in the library\n");
        return;
    }

    while (current != NULL)
    { 
            counter ++;

            printf("Book: %s \n", current->book_name);
    
            printf("Author: %s \n", current->author_name);
    
            printf("Pages: %d \n", current->pages);
    
            printf("Price: %.2f \n", current->price);

            printf("book id is: %d \n", counter);

            printf("\n");

            current = current->next;
    }


}

//function to prevent memory leak
void freeLibrary(void)
{
    Book *current = head;
    Book *temp_book;

    while(current != NULL)
    {
        temp_book = current->next;
        free(current);
        current = temp_book;
    }

    head = NULL;
}