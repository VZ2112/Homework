#include <stdio.h>

int board[8][8]={0};
int steps=0;

int kght_path(int i, int j) {
  int x, y, f=1;
  if(i < 0 || i >= 8) return 0;
  if(j < 0 || j >= 8) return 0;
  if(board[i][j]) {
    for(x = 0; x < 8; x++)
      for(y = 0; y < 8; y++)
        if(!board[x][y]) f = 0;
    if(f) return 1;
    return 0;
  }
  board[i][j] = ++steps;
  if(
    kght_path(i + 1, j + 2)
    || kght_path(i + 2, j + 1)
    || kght_path(i + 2, j - 1)
    || kght_path(i + 1, j - 2)
    || kght_path(i - 1, j - 2)
    || kght_path(i - 2, j - 1)
    || kght_path(i - 2, j + 1)
    || kght_path(i - 1, j + 2)
  ) {
    return 1;
  }
  else {
    for(x = 0; x < 8; x++)
      for(y = 0; y < 8; y++)
        if(!board[x][y]) f = 0;
    if(f) {
      return 1;
    }
    board[i][j] = 0;
    steps--;
    return 0;
  }
}

int main() {
  int i, j;
  if(kght_path(0, 0))
    for(i = 0; i < 8; i++) {
      for(j = 0; j < 8; j++)
        printf("%2d ", board[i][j]);
      puts("");
    }
  else puts("No Road found.");
  return 0;
}
