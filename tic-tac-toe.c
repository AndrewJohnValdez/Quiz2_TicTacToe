//Tic Tac Toe game between 2 players or player vs computer
//everything must work in one file

/*Things to try/do: 
    Randomizer to imitate computer 
    have a loop back and forth from p1 to p2
    create board (2d array?)
    must check if last choice is a winning choice
*/

//problem with outputting a tie message
#include <stdio.h>
#include <stdlib.h>

char board[3][3];  /* the tic tac toe board */

void initializeBoard(void);
void displayBoard(void);

int main(void)
{
    int userStartChoice;

    //prompt user for game they wish to play
    printf("================\n");
    printf("WELCOME TO TIC TAC TOE!\n");
    printf("1 - person vs. person\n");
    printf("2 - person vs. random computer\n");
    printf("Enter your choice (1 or 2)\n");
    printf("================\n");
    
    //read information from console, reading player commands, determine type of game
    scanf("%d", &userStartChoice);
    printf("You have entered choice %d\n", &userStartChoice);

    initializeBoard();

    //put in if statement to start game based on player choice
    if(userStartChoice == 1) {
        printf("this is 1 choice\n");
    } else if(userStartChoice == 2) {
        printf("this is 2 choice\n");
    } else {
        printf("Invalid choice\n");
        return 0;
    }

    displayBoard();

    return 0;
}

/* Initialize the board. */
void initializeBoard(void)
{
    int i, j;

    for(i=0; i<3; i++)
        for(j=0; j<3; j++) board[i][j] =  ' ';
}


/* Display the board on the screen. */
void displayBoard(void)
{
    int t;

    printf("\n+-----------+\n");
    for(t=0; t<3; t++) {
        printf("| %c | %c | %c |", board[t][0], board[t][1], board [t][2]);
        if(t!=2) { 
            printf("\n+-----------+\n");
        }
    }
    printf("\n+-----------+\n");
    printf("\n");
}
