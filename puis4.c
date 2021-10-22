#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NBC 7
#define NBL 6

int player = 0;
char playerChip[2] = {'o','x'};
char board[NBL][NBC] = {};
int chipPos;
int victory = 0;
int freePlace = 0;
char test = 0;

int initboard(void){
  for (int i = 0 ; i < NBL ; i++){
    for (int j = 0 ; j < NBC ; j++){
      board[i][j] = '.';
    }
  }
}
  
int printboard (void){
  for (int i = 0 ; i < NBL ; i++){
    printf("\033[0;37m");
    printf("|");
    for (int j = 0 ; j < NBC ; j++){
      if (board[i][j] == 'x'){
	printf("\033[0;31m");
      }
      else if (board[i][j] == 'o'){
	printf("\033[0;33m");
      }
      printf("%c", board[i][j]);
      printf("\033[0;37m");
      printf("|");
    }
    printf("\n");
  }
  printf("|1|2|3|4|5|6|7|\n");
}

int winVer(){
  for (int i=0; i<NBL-3; i++){
    for (int j=0; j<NBC; j++){
      if (board[i][j] == playerChip[player] && board[i+1][j] == playerChip[player] && board[i+2][j] == playerChip[player] && board[i+3][j] == playerChip[player]){
	victory = 1;
      }
    }
  }
}

int winHor(){
  for (int i=0; i<NBL; i++){
    for (int j=0; j<NBC-3; j++){
      if (board[i][j] == playerChip[player] && board[i][j+1] == playerChip[player] && board[i][j+2] == playerChip[player] && board[i][j+3] == playerChip[player]){
	victory = 1;
      }
    }
  }
}

int winDiag1(){
  for (int i=0; i<NBL; i++){
    for (int j=0; j<NBC; j++){
      if (board[i][j] == playerChip[player] && board[i+1][j+1] == playerChip[player] && board[i+2][j+2] == playerChip[player] && board[i+3][j+3] == playerChip[player]){
	victory = 1;
      }
    }
  }
}

int winDiag2(){
  for (int i=0; i<NBL; i++){
    for (int j=0; j<NBC; j++){
      if (board[i][j] == playerChip[player] && board[i+1][j-1] == playerChip[player] && board[i+2][j-2] == playerChip[player] && board[i+3][j-3] == playerChip[player]){
	victory = 1;
      }
    }
  }
}

void clear(){
  while(getchar() != '\n');
}

int main (void){
  initboard();

  printf("Welcome to a game of Connect 4!\n");
  
  while (victory == 0 && freePlace != 42){
    printboard();
    test = 0;
    
    while(test == 0){
      printf("Player %d, choose the column in wich you want to put your chip\n", player+1);
      
      int ret = scanf("%d", &chipPos);
      if (ret != 1 || chipPos<0 || chipPos >7){
	printf("Wait, that's illegal!\n");
	clear();
	continue;
      }
      else{
	test = 1;
      }
    }
    
    for (int line=5; line>-1;line--){
      if (board[line][chipPos-1] == '.'){
	board[line][chipPos-1] = playerChip[player];
	break;
      }
    }
    
    winHor();
    winVer();
    winDiag1();
    winDiag2();
    freePlace += freePlace;
    player = !player;
    
  }
  printboard();
  
  if (victory == 1 && freePlace != 42){
    printf("Congratulation, victory of player %d\n",player+1);
  }
  else{
    printf("Congratulation't, victory of the game!\n");
  }
}
