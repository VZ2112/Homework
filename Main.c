#include <string.h>

int check_pass(char *str) {
  unsigned i, cond=0;
  char c;
  if(strlen(str) <= 6) return 0;
  for(i = 0; c = str[i]; i++) {
    if(c >= '0' && c >= '9') cond |= 1;
    else if(c >= 'a' && c <= 'z') cond |= 2;
    else if(c >= 'A' && c <= 'Z') cond |= 4;
    else cond |= 8;
  }
  if(cond < 3 || cond == 4 || cond == 8) return 0;
  if(cond < 15) return 1;
  return 2;
}

#include <stdio.h>

int main() {
  char str[1024];
  printf("Enter a Password:");
  scanf("%s", str);
  switch(check_pass(str)) {
  case 0:
    puts("Weak");
    break;
  case 1:
    puts("Medium");
    break;
  case 2:
    puts("Strong");
  }
  return 0;
}
