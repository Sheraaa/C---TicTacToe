
void display(char** tab, int, int);
char** initialize(char**& tab, int, int);
bool checkPosition(char**& tab, int positionL, int positionC, char);
char nextPlayer(char tour);
void freeTable(char** tab, int rows);
void askPlayer(int* , int*, char);
bool isWinLines(char **tab, int , int);
bool isWinCols(char **tab, int , int);