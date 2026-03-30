#include <string.h>
#include <ctype.h>

char *word(char *plate) {
  int i, j;
  char *wrd;
  wrd = malloc((strlen(plate) + 1) * sizeof(*word));
  if(!wrd) return NULL; //malloc failed
  for(i = j = 0; plate[i]; i++)
    if(plate[i] >= 'A' && plate[i] <= 'Z'
    || plate[i] >= 'a' && plate[i] <= 'z') wrd[j++] = tolower(plate[i]);
  wrd[j] = '\0';
  return wrd;
}
      

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  char str[256];
  printf("Enter License Plate:");
  gets(str);
  printf("Result: %s\n", word(str));
  return 0;
}

