unsigned num_of_dcd(char *str) {
  unsigned res;
  if(!str[0]) return 1;
  if(str[0] == '0') return 0;
  if(!str[1]) return 1;
  res = num_of_dcd(str + 1);
  switch(str[0]) {
  case '1':
    res += num_of_dcd(str + 2);
    break;
  case '2':
    switch(str[1]) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
      res += num_of_dcd(str + 2);
    }
  }
  return res;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  char str[256];
  printf("Enter encrypted Message:");
  scanf("%s", str);
  printf("The String can be decrypted in %u Way(s).\n", num_of_dcd(str));
  return 0;
}

