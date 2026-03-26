/* 
This is the main file of the program
(library version 3) this program is
a library management system that lets you
add,remove and show books
*/


#include <stdio.h>
#define TRUE 1
#define FALSE 0
//header
#include "functions.h"

int main(void)
{
    int choice;

    printf("**************************\n");
    printf("Library Management System Menu\n");
    printf("**************************\n\n\n");

    while(TRUE)
    {
         printf("\n");
         printf("Press 1 to add abook to the library system\n");
         printf("Press 2 to remove abook from the library system\n");
         printf("Press 3 to show info of abook from the library system\n");
         printf("Press 4 to list all books of a chosen author\n");
         printf("Press 5 to count all the books in the library\n");
         printf("press 6 to show all the books in the library\n");
         printf("Press 7 to quit the program\n");
        

         while((scanf("%d", &choice) != 1))
         {
            printf("please enter a number\n");
            
            // Call the janitor to clear out the bad letters
            while(getchar() != '\n');
         }
         

         if(choice == 1)
         {
            insertBook();
         }
         else if (choice == 2)
         {
            removeBook();
         }
         else if (choice == 3)
         {
            findBook();
         }
         else if (choice == 4)
         {
            findByAuthor();
         }
         else if (choice == 5)
         {
            countBooks();
         }
         else if (choice == 6)
         {
            showAllBooks();
         }
         
         else if(choice == 7)
         {
            printf("\n");
            printf("Goodbye :) \n\n");
            freeLibrary();
            break;
         }
         else
         {
            printf("you have entered the number %d please choose a number from 1 to 7 \n\n", choice);
         }
         
        
    }

    return 0;
} 