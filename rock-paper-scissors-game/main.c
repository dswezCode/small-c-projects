/* 
this is the main file of the program
*/

#include "game.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   // Required for time()


int main(void)
{
    // SEED THE GENERATOR (Do this exactly ONCE at the start of main)
    srand(time(NULL)); 

    int want_play = 1;

    while (want_play)
    {
        game();
        printf("if you want to stop press 0 if you wish to continue press 1: \n");

        //input senetize 
        while (scanf("%d", &want_play) != 1) 
        {
            // If it failed (because they typed a letter):
            printf("Invalid input! Please enter a number.\n");
            
            // Call the janitor to clear out the bad letters
            while (getchar() != '\n'); 
        }    
    }
    

    return 0;
}