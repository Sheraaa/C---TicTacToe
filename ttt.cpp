#include <iostream>
#include <vector>
#include "ttt.hpp"

using namespace std;

int main(){
  char playerX = 'X', playerO = 'O';
  char** tab;
  bool win = false;
  char tour = playerX;
  int positionL, positionC, rows = 3, cols = 3, cpt = 0;

  initialize(tab, rows, cols);

  while(!win){
    display(tab, rows, cols);
    askPlayer(&positionL,&positionC, tour);

    while(!checkPosition(tab, positionL, positionC, tour)){
      cout<< "Try again \n";
      askPlayer(&positionL,&positionC, tour);
      cout << "\n";
    }
    if(cpt >=2)
      win = isWinLines(tab, rows, positionC) || isWinCols(tab, cols, positionL);
    cpt++;
    if(!win)
      tour = nextPlayer(tour);
    else
      display(tab, rows, cols);
  }
  if(win){
    cout << tour<< " has won !!!\n";
  }else{
    cout << "GAME OVER\n";
  }
  freeTable(tab, 3);
  return 0;
}