int is_palin(unsigned n) {
  unsigned m, k;
  if(n < 10) return 1;
  m = n;
  k = 0;
  while(m > 0) {
    k = 10 * k + m % 10;
    m /= 10;
  }
  return n == k;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned n;
  printf("Enter a Number:");
  scanf("%u", &n);
  printf("Result: %d\n", is_palin(n));
  return 0;
}
