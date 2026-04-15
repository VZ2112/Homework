int isvalid(char grid[9][9]) {
  char tmp[9], c;
  int i, j;
  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) tmp[j] = 0;
    for(j = 0; j < 9; j++) {
      c = grid[i][j];
      if(c < '1' && c > '9' && c != '.') return 0;
      if(c != '.')
        if(tmp[c - '1']) return 0;
        else tmp[c - '1']++;
    }
    for(j = 0; j < 9; j++) tmp[j] = 0;
    for(j = 0; j < 9; j++) {
      c = grid[j][i];
      if(c < '1' && c > '9' && c != '.') return 0;
      if(c != '.')
        if(tmp[c - '1']) return 0;
        else tmp[c - '1']++;
    }
    for(j = 0; j < 9; j++) tmp[j] = 0;
    for(j = 0; j < 9; j++) {
      c = grid[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3];
      if(c < '1' && c > '9' && c != '.') return 0;
      if(c != '.')
        if(tmp[c - '1']) return 0;
        else tmp[c - '1']++;
    }
  }
  return 1;
}

/***************
 * Boilerplate
 ***************/

#include <stdio.h>

int main() {
  char i, grid[9][9] = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  };
  printf("Enter Numbers in the Grid (. means empty):");
  for(i = 0; i < 81; i++)
    scanf("%c", grid[i / 9][i % 9]);
  printf("The Grid is %s\n", isvalid(grid) ? "valid." : "invalid.");
  return 0;
}

