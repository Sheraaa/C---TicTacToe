#include <iostream>

using namespace std;

void display(char** tab, int rows, int cols){
  cout << "Board: \n";
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cout << tab[i][j] << " ";
    }
    cout << "\n";
  }
}

void initialize(char**& tab, int rows, int cols){
  tab = new char*[rows];
  for(int i = 0; i < rows; i++){
    tab[i] = new char[cols];
  }
  
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      tab[i][j] = '.';
    }
  }
}

bool checkPosition(char**& tab, int positionL, int positionC, char tour){
    if (positionL <= 0 || positionL > 3 || positionC <= 0 || positionC > 3){
      cout << "Incorrect position\n";
      return false;
    } 

    if(tab[positionL-1][positionC-1] != '.'){
      cout << "Occupied position!\n";
    }else{
      tab[positionL-1][positionC-1] = tour;
    }
    return true;
}

char nextPlayer(char tour){
  if(tour == 'X'){
      tour = 'O';
    }else{
      tour = 'X';
    }
    return tour;
}

void askPlayer(int* positionL, int* positionC, char tour){
  cout<< "Player " << tour << " turn, give position l and c: ";
  cin>>*positionL>>*positionC;
  cout << "\n";
}

void freeTable(char** tab, int rows){
  for(int i = 0 ; i < rows; i++){
    delete[] tab[i];
  }
   delete[] tab;
}

bool isWinLines(char **tab, int rows, int positionC){
  int i = 1 , cpt = 1;
  char player = tab[0][positionC-1];
  
  while(i < rows && cpt < 3 && player != '.'){
    if(tab[i][positionC-1] == player){
      cpt++;
    }else{
      cpt = 1;
      player = tab[i][positionC-1];
    }
    i++;
  }
  return cpt == 3;
}

bool isWinCols(char **tab, int cols, int positionL){
  int i = 1 , cpt = 1;
  char player = tab[positionL-1][0];
  
  while(i < cols && cpt < 3  && player != '.'){
    if(tab[positionL-1][i] == player){
      cpt++;
    }else{
      cpt = 1;
      player = tab[positionL-1][i];
    }
    i++;
  }
  return cpt == 3;
}