unsigned count_divisors(unsigned n) {
  unsigned res = 2, i;
  if(n < 2) return n;
  for(i = 2; i < n; i++) if(!(n % i)) res++;
  return res;
}

unsigned count_lit(unsigned n) {
  unsigned res = 0, i;
  for(i = 1; i <= n; i++) if(count_divisors(i) % 2) res++;
  return res;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned n;
  printf("Enter the Number of Lights:");
  scanf("%u", &n);
  printf("%u Light(s) will be left lit.\n", count_lit(n));
  return 0;
}
