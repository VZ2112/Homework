#include <stdlib.h>
#include <string.h>

char *RLE(char *str) {
  char c = str[0], *res;
  int i, j, count = 0;
  i = strlen(str);
  res = malloc(i + 1);
  if(!res) return NULL; // Malloc failed
  for(i = j = 0; str[i]; i++) {
    if(c >= '0' && c <= '9') {
      free(res);
      return NULL;
    }
    if(count == 9) {
      res[j++] = count + '0';
      res[j++] = c;
      count = 0;
    }
    if(str[i] == c) count++;
    else {
      if(count != 1) res[j++] = count + '0';
      res[j++] = c;
      count = 1;
      c = str[i];
    }
  }
  if(count != 1) res[j++] = count + '0';
  res[j++] = c;
  res[j] = '\0';
  return res;
}

/***************
 * Boilerplate
 ***************/

#include <stdio.h>

int main() {
  char str[256], *res;
  printf("Enter a String:");
  gets(str);
  res = RLE(str);
  printf("RLE: %s\n", res ? res : "NULL");
  return 0;
}

