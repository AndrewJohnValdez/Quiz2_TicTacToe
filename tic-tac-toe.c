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
char done = ' ';
int counter; //count number of loops to end game in a draw

char check(void);
void initializeBoard(void);
void player1Move(void);
void player2Move(void);
void computerMove(void);
void displayBoard(void);
void playerVScomputer(void);
void playerVSplayer(void);

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
    printf("You have entered choice %d \n", &userStartChoice);

    initializeBoard();

    //put in if statement to start game based on player choice
    if(userStartChoice == 1) {
        playerVSplayer();
    } else if(userStartChoice == 2) {
        playerVScomputer();
    } else {
        printf("Invalid choice\n");
        return 0;
    }

    return 0;
}

//pvp version of game, read console for commands from players
void playerVSplayer(void)
{
    do {
        printf("The current status is: \n");
        displayBoard();
        printf("\n");
        player1Move();
        counter++;
        done = check(); /* see if winner */
        if(done!= ' ') break; /* winner */
        displayBoard();
        player2Move();
        counter++;
        done = check(); /* see if winner */
        printf("\n");
    } while(done == ' ');

    if(done=='X') { //must make resdesign check statement to account for draws
        printf("Player 1 won!\n");
    } else {
        printf("Player 2 won!\n");
    }
    
    displayBoard(); /* show final positions */

}

//player vs computer function to be called
void playerVScomputer(void)
{
    do {
        printf("The current status is: ");
        displayBoard();
        printf("\n");
        player1Move();
        counter++;
        done = check(); /* see if winner */
        if(done!= ' ') break; /* winner*/
        computerMove();
        counter++;
        done = check(); /* see if winner */
    } while(done== ' ');

    if(done=='X') {
        printf("You won!\n");
    } else {
        printf("Computer won!\n");
    }

    displayBoard(); /* show final positions */
}

/* Initialize the board. */
void initializeBoard(void)
{
    int i, j;

    for(i=0; i<3; i++)
        for(j=0; j<3; j++) board[i][j] =  ' ';
}

/* Get a player1's moves. */
void player1Move(void)
{
    int x, y;

    printf("player1: make your move\n ");
    printf("\n");
    scanf("%d%*c%d", &x, &y);

    x--; y--;

    if(board[x][y]!= ' ') {
        printf("Invalid move, try again.\n");
        player1Move();
    } else {
        printf("Good!\n");
        board[x][y] = 'X';
    }
}

/* Get player2's moves*/
void player2Move(void) 
{
    int x, y;

    printf("player2: make your move\n ");
    printf("\n");
    scanf("%d%*c%d", &x, &y);

    x--; y--;

    if(board[x][y]!= ' ') {
        printf("Invalid move, try again.\n");
        player2Move();
    } else {
        printf("Good!\n");
        board[x][y] = 'O';
    }
}

/* Get a move from the computer. */
void computerMove(void)
{
  int i, j;
  for(i=0; i<3; i++){
    for(j=0; j<3; j++)
      if(board[i][j]==' ') {
        break;
      }
    if(board[i][j]==' ') {
        break;
    }
  }

  if(i*j==9)  {
    printf("draw\n");
    exit(0);
  }
  else
    board[i][j] = 'O';
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
}

/* See if there is a winner. */
char check(void)
{
    int i;

    /* check rows */
    for(i=0; i<3; i++) {  
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2]) {
            return board[i][0];
        }
    }

    /* check columns */
    for(i=0; i<3; i++) {  
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i]) {
            return board[0][i];
        }
    }

    /* test diagonals */
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
        return board[0][0];
    }

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
        return board[0][2];
    }

    if(counter >= 9) {
        printf("Draw!");
        exit(0);
    }

    return ' ';
}
