#include <stdio.h>

void move(char arr[12][12], char where, int *i, int *j) {
  int k, l;
  getchar();
  switch(where) {
  case '>':
    if(arr[*i][*j + 1] == ' ') arr[*i][(*j)++] = ' ';
    break;
  case '<':
    if(arr[*i][*j - 1] == ' ') arr[*i][(*j)--] = ' ';
    break;
  case '^':
    if(arr[*i - 1][*j] == ' ') arr[(*i)--][*j] = ' ';
    break;
  case 'v':
    if(arr[*i + 1][*j] == ' ') arr[(*i)++][*j] = ' ';
    break;
  }
  arr[*i][*j] = 'o';
  printf("\nDirection:%c\n\n", where);
  for(k = 0; k < 12; k++) {
    for(l = 0; l < 12; l++) printf("%c", arr[k][l]);
    puts("");
  }
  if(*i == 0 || *i == 11 || *j == 11) {
    puts("\nFound!");
    return;
  }
  if(*j == 0) {
    puts("\nNo Way!");
    return;
  }
  switch(where) {
  case '>':
  right:
    if(arr[*i + 1][*j] == ' ') move(arr, 'v', i, j);
    else goto up;
    break;
  case '<':
  left:
    if(arr[*i - 1][*j] == ' ') move(arr, '^', i, j);
    else goto down;
    break;
  case '^':
  up:
    if(arr[*i][*j + 1] == ' ') move(arr, '>', i, j);
    else goto left;
    break;
  case 'v':
  down:
    if(arr[*i][*j - 1] == ' ') move(arr, '<', i, j);
    else goto right;
    break;
  }
}

int main()
{
  int i;
  int j;
  char direction = '>';
  i = 2;
  j = 0;
  printf("\nPress ENTER to see the object's next steps");
  char arr[12][12] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    'o', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#',
    '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#',
    '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', ' ',
    '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
    '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
    '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#',
    '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
  };
  move(arr, direction, &i, &j);
  return 0;
}


