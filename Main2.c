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
  if(!res) {
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
  if(res[0] == '0') {
    strcpy(res, res + 1);
  }
  return res;
}

char *dif(char *a, char *b) {
  char s, digit1, digit2, carry = 0, *res;
  int i, j, n;
  i = strlen(a);
  j = strlen(b);
  n = greater(i, j);
  res = malloc(n + 2);
  if(!res) {
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

int lt(char *a, char *b) {
  char *tmp;
  int res;
  tmp = dif(a, b);
  res = tmp[0] == '-';
  free(tmp);
  return res;
}

unsigned long long fib(char *str) {
  unsigned long long i;
  char *a, *b, *c;
  a = malloc(2);
  b = malloc(2);
  a[0] = '1';
  b[0] = '0';
  a[1] = 0;
  b[1] = 0;
  for(i = 0; lt(b, str); i++) {
    c = sum(a, b);
    free(a);
    a = b;
    b = c;
  }
  free(a);
  free(b);
  return !strcmp(b, str) ? i : 0;
}

#include <stdio.h>

int main() {
  char str[256];
  scanf("%s", str);
  printf("%llu\n", fib(str));
  return 0;
}
