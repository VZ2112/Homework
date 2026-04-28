#include <stdio.h>

int board[8][8] = {0};

int kght_path(int i, int j) {
  int x, y, f=1;
  if(i < 0 || i >= 8) return 0;
  if(j < 0 || j >= 8) return 0;
  if(board[i][j]) {
    for(x = 0; x < 8; x++)
      for(y = 0; y < 8; y++)
        if(!board[x][y]) f = 0;
    if(f) {
      printf("%c%c\n", "ABCDEFGH"[i], "12345678"[j]);
      return 1;
    }
    return 0;
  }
  board[i][j] = 1;
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
    printf("%c%c\n", "ABCDEFGH"[i], "12345678"[j]);
    return 1;
  }
  else {
    for(x = 0; x < 8; x++)
      for(y = 0; y < 8; y++)
        if(!board[x][y]) f = 0;
    if(f) {
      printf("%c%c\n", "ABCDEFGH"[i], "12345678"[j]);
      return 1;
    }
    board[i][j] = 0;
    return 0;
  }
}

int main() {
  kght_path(0, 0);
  return 0;
}
