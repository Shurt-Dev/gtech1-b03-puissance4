#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NBC 7
#define NBL 6

int player = 0;
char playerChip[2] = {'o','x'};
char board[NBL][NBC] = {};
int chipPos;
int test;
int victoryVar;
int redChipAlign;
int yellowChipAlign;

int initboard(void){
  for (int i = 0 ; i < NBL ; i++){
    for (int j = 0 ; j < NBC ; j++){
      board[i][j] = '.';
    }
  }
}
  
int printboard (void){
  for (int i = 0 ; i < NBL ; i++){
    printf("|");
    for (int j = 0 ; j < NBC ; j++){
      printf("%c|", board[i][j]);
    }
    printf("\n");
  }
  printf("|1|2|3|4|5|6|7|\n");
}

int main (void){
  initboard();
  
  while (strpbrk(board,".") != NULL && redChipAlign != 4 && yellowChipAlign != 4){
    printboard();
    printf("Enter the column in which you want to place your chip\n");
    scanf("%d", &chipPos);
    
    for (int line=5; line>-1;line--){
      if (board[line][chipPos-1] == '.'){
	board[line][chipPos-1] = playerChip[player];
	player = !player;
	break;
      }
    }
  }
  printboard();
}
