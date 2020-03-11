/** 
 *  This program implements the SquarO game. The game consists of a grid of N x N squares. At the corners of each square
 *  there are circles which can be colored black(X) or white(o). There is a number between 0-4 indicated in each square. 
 *  The goal is to color in black a subset of circles so that the number of black circles at the corners of each square
 *  matches the number written in the square.
 *  
 *  @author Giorgos Argyrides
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5 // Grid size

/* Function prototypes */
void readGridFile(short int[][N], char *filePath);

void displaySquarO(short int[][N], char[][N + 1]);

void squareSolved(int, int, short int[][N], char[][N + 1], short int[][N]);

int gameSolved(short int[][N]);

void play(short int[][N], char[][N + 1], short int[][N]);


/** 
 *  Reads a SquarO grid configuration (N x N integers between 0-4) from a text file.
**/
void readGridFile(short int puzzle[][N], char *filePath){
   int num, i, j;
   FILE *fp = NULL;
   if ((fp = fopen(filePath, "r")) == NULL){
      printf("\nError: Unable to open %s\n", filePath);
      exit(EXIT_FAILURE);
   }
   for (i = 0; i < N; i++){
      for (j = 0; j < N; j++){
         if (fscanf(fp, "%d", &num) == 1){
            if (num > 4 || num < 0){
               printf("\nError: numbers must be [0..4]\n");
               exit(EXIT_FAILURE);
            }
            puzzle[i][j] = num;
         }
         else{
            printf("\nError: invalid input in the file\n");
            exit(EXIT_FAILURE);
         }
      }
   }
   fclose(fp);
}

/** 
 * Displays the SquarO game grid.
**/
void displaySquarO(short int puzzle[][N], char circles[][N + 1]){
   int i, j;
   printf("\n");
   for (i = 0; i < N; i++){
      for (j = 0; j < N; j++){
         printf("%c---", circles[i][j]);
      }
      printf("%c\n", circles[i][j]);
      for (j = 0; j < N; j++){
         printf("| %d ", puzzle[i][j]);
      }
      printf("|\n");
   }
   for (j = 0; j < N; j++){
      printf("%c---", circles[N][j]);
   }
   printf("%c\n", circles[N][N]);
}

/** 
 *  Checks if the black circles around a square matches the number in it.
**/
void squareSolved(int x, int y, short int puzzle[][N], char circles[][N + 1], short int solved[][N]){
   int i, j, blacks = 0;
   for (i = x; i <= x + 1; i++){
      for (j = y; j <= y + 1; j++){
         if (circles[i][j] == 'X'){
            blacks++;
         }
      }
   }
   if (blacks == puzzle[x][y]){
      solved[x][y] = 1;
   }
   else{
      solved[x][y] = 0;
      if (blacks > puzzle[x][y]){
         printf("\nAttention..Conflicting move\nIncoherence in square (%d,%d) : it must have %d black(s). It has %d "
         "blacks(s), %d white(s)\n", x + 1, y + 1, puzzle[x][y], blacks, 4 - blacks);
      }
   }
}

/** 
 * Checks if the game is completed. Returns 1 if the game is completed (if all squares are solved).
**/
int gameSolved(short int solved[][N]){
   int i, j;
   for (i = 0; i < N; i++){
      for (j = 0; j < N; j++){
         if (solved[i][j] == 0)
            return 0;
      }
   }
   return 1;
}

/**
 *  Prompts the user to play the game until it is solved or until the user chooses to quit the game. It prints the
 *  appropriate error messages if the user gives invalid input.
**/
void play(short int puzzle[][N], char circles[][N + 1], short int solved[][N]){
   int i, j, x, y;
   printf("\nWelcome to the SquarO Game!\n\nEnter your commands in the following format:\n i,j: for changing the color "
         "of the circle at (i,j).\n -1,-1 for ending the game.\n Notice: i,j numbering is from the range [0, %d].\n\n", N);
   while (!gameSolved(solved)){
      displaySquarO(puzzle, circles);
      printf(">");
      if (scanf("%d,%d", &i, &j) != 2){
         printf("\ninvalid input, please try again!\n");
         while (getchar() != '\n');
         continue;
      }
      if (i == -1 && j == -1){
         printf("\nThank you for playing SquarO!\nBye!\n");
         break;
      }
      if (i < 0 || i > N || j < 0 || j > N){
         printf("\nError: i or j are outside the allowed range [0, %d]!\n", N);
         continue;
      }
      x = i;
      y = j;
      if (circles[x][y] == 'o'){
         circles[x][y] = 'X';
      }
      else{
         circles[x][y] = 'o';
      }
      if (x == 0 && y == 0){
         squareSolved(0, 0, puzzle, circles, solved);
      }
      else if (x == 0 && y == N){
         squareSolved(0, N - 1, puzzle, circles, solved);
      }
      else if (x == N && y == 0){
         squareSolved(N - 1, 0, puzzle, circles, solved);
      }
      else if (x == N && y == N){
         squareSolved(N - 1, N - 1, puzzle, circles, solved);
      }
      else if (x == 0){
         squareSolved(0, y, puzzle, circles, solved);
         squareSolved(0, y - 1, puzzle, circles, solved);
      }
      else if (y == 0){
         squareSolved(x, 0, puzzle, circles, solved);
         squareSolved(x - 1, 0, puzzle, circles, solved);
      }
      else if (x == N){
         squareSolved(N - 1, y, puzzle, circles, solved);
         squareSolved(N - 1, y - 1, puzzle, circles, solved);
      }
      else if (y == N){
         squareSolved(x, N - 1, puzzle, circles, solved);
         squareSolved(x - 1, N - 1, puzzle, circles, solved);
      }
      else{
         squareSolved(x, y, puzzle, circles, solved);
         squareSolved(x - 1, y, puzzle, circles, solved);
         squareSolved(x, y - 1, puzzle, circles, solved);
         squareSolved(x - 1, y - 1, puzzle, circles, solved);
      }
   }
   if (gameSolved(solved)){
      displaySquarO(puzzle, circles);
      printf("\nCongratulations!!! Game completed!\n");
   }
}

int main(int argc, char **argv){
   /* Variable declaration */
   short int solved[N][N];
   short int puzzle[N][N];
   char circles[N + 1][N + 1];
   int i, j;
   readGridFile(puzzle, argv[1]);
   // initialize circles (all circles are initialized as white)
   for (i = 0; i < N + 1; i++){
      for (j = 0; j < N + 1; j++){
         circles[i][j] = 'o';
      }
   }
   // initialize solved (if the number within a square is 0 then the square is marked as solved)
   for (i = 0; i < N; i++){
      for (j = 0; j < N; j++){
         if (puzzle[i][j] == 0){
            solved[i][j] = 1;
         }
         else{
            solved[i][j] = 0;
         }
      }
   }
   play(puzzle, circles, solved);
   return 0;
}
