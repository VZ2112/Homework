#include <string.h>
#include <stdlib.h>
#define greater(a, b) ((a) > (b) ? (a) : (b))

char *sum(char *a, char *b) {
  char s, digit1, digit2, carry = 0, *res;
  int i, j, n;
  i = strlen(a);
  j = strlen(b);
  n = greater(i, j);
  res = malloc(n + 2);
  if(!n) {
    return NULL;
  }
  res[n + 1] = '\0';
  for(--i, --j; n >= 0; --i, --j) {
    digit1 = i >= 0 ? a[i] - '0' : 0;
    digit2 = j >= 0 ? b[j] - '0' : 0;
    if(digit1 < 0 || digit1 > 9 || digit2 < 0 || digit2 > 9) {
      free(res);
      return NULL;
    }
    s = digit1 + digit2 + carry;
    carry = s / 10;
    res[n--] = s % 10 + '0';
  }
  if(res[0] == '0') strcpy(res, res + 1);
  return res;
}

char *dif(char *a, char *b) {
  char s, digit1, digit2, carry = 0, *res;
  int i, j, n;
  i = strlen(a);
  j = strlen(b);
  n = greater(i, j);
  res = malloc(n + 2);
  if(!n) {
    return NULL;
  }
  res[n + 1] = '\0';
  for(--i, --j; n >= 0; --i, --j) {
    digit1 = i >= 0 ? a[i] - '0' : 0;
    digit2 = j >= 0 ? b[j] - '0' : 0;
    if(digit1 < 0 || digit1 > 9 || digit2 < 0 || digit2 > 9) {
      free(res);
      return NULL;
    }
    s = digit1 - digit2 - carry;
    carry = s < 0;
    res[n--] = s + carry * 10 + '0';
  }
  if(res[0] - '0') {
    res[0] = '-';
    carry = 0;
    for(n = strlen(res) - 1; n; n--) {
      s = '0' - res[n] - carry;
      carry = s < 0;
      res[n] = s + carry * 10 + '0';
    }
  }
  n = res[0] == '-';
  for(i = n; res[i] == '0'; i++);
  if(!res[i]) i--;
  strcpy(res + n, res + i);
  return res;
}

#include <stdio.h>

int main() {
  char a[256], b[256], *res;
  scanf("%s %s", a, b);
  res = sum(a, b);
  printf("%s\n", res ? res : "NULL");
  res = dif(a, b);
  printf("%s\n", res ? res : "NULL");
  return 0;
}
    
