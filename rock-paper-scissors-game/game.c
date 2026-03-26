/* 
    this file includes the core gameplay function
*/

#include "game.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   // Required for time()

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

void game(void)
{
    // USE RAND() to get a random number
    int computer_turn = rand();

    // modulo of 3 for one of the options :rock/paper/scissors
    computer_turn = computer_turn % 3;

    //player turn
    int player_turn;
    printf("please choose a turn to play:\n 0 for rock \n 1 for paper \n 2 for scissors \n");
    while(scanf("%d", &player_turn) != 1)
    {
        // If it failed (because they typed a letter):
        printf("Invalid input! Please enter a number.\n");
            
        // Call the janitor to clear out the bad letters
        while (getchar() != '\n'); 
    }
    
    
    if (player_turn == ROCK)
    {
        printf("you chose rock \n\n");

        if (computer_turn == ROCK)
            printf("rock vs rock a DRAW  \n");
        else if (computer_turn == PAPER)
        {
            printf("rock vs paper you LOSE  \n");
        }
        else
            printf("rock vs scissors you WIN  \n"); 
        return;       
    }
    else if(player_turn == PAPER)
    {

        printf("you chose paper \n\n");

        if (computer_turn == ROCK)
            printf("paper vs rock you WIN  \n");
        else if (computer_turn == PAPER)
        {
            printf("paper vs paper a DRAW \n");
        }
        else
            printf("paper vs scissors you LOSE  \n");
        return;    
    }
    else
    {
        printf("you chose scissors \n\n");

        if (computer_turn == ROCK)
            printf("scissors vs rock you LOSE  \n");
        else if (computer_turn == PAPER)
        {
            printf("scissors vs paper you WIN  \n");
        }
        else
            printf("scissors vs scissors a DRAW \n ");
        return;    
    }
}