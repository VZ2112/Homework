#include <string.h>
#include <stdlib.h>

unsigned digits(unsigned char base1, unsigned char base2) {
  unsigned i=0;
  if(base1 < 2 || base2 < 2) return 0;
  while(base1) {
    base1 /= base2;
    i++;
  }
  return i;
}

char *convert(char str[20], unsigned char base1, unsigned char base2) {
  unsigned long long n=0;
  unsigned d, i, l;
  char *res;
  if(base1 < 2 || base2 < 2) return NULL;
  if(base1 > 10 || base2 > 10) return NULL;
  for(i = 0; str[i]; i++) {
    if(str[i] < '0') return NULL;
    d = str[i] - '0';
    if(d >= base1) return NULL;
    n = n * base1 + d;
  }
  l = digits(base1, base2) * (i + 1);
  res = malloc(l);
  if(!res) return NULL;
  res[l - 1] = '\0';
  i = l - 1;
  while(n) {
    res[--i] = n % base2 + '0';
    n /= base2;
  }
  strcpy(res, res + i);
  if(!res[0]) {
    res[0] = '0';
    res[1] = '\0';
  }
  return res;
}

/***************
 * Boilerplate
 ***************/

#include <stdio.h>

int main() {
  char str[20], *res;
  unsigned b1, b2;
  printf("Enter Bases to convert from and to:");
  scanf("%u", &b1);
  scanf("%u", &b2);
  printf("Enter the Number:");
  scanf("%19s", str);
  str[19] = '\0';
  res = convert(str, (unsigned char)b1, (unsigned char)b2);
  printf("Result: %s\n", res ? res : "NULL");
  return 0;
}

