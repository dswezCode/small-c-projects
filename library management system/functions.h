
/* 
This file is a header file
for the functions.c file
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* functions */

//function to insert a book
void insertBook(void);

//function to remove book by name
void removeBook(void);

//function to show book info
void findBook(void);

//find books by author name
void findByAuthor(void);    

//count all the books in the library
void countBooks(void);

//show all the books in the library
void showAllBooks(void);

//function to prevent memory leak
void freeLibrary(void);

#endif