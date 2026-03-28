int is_prime(unsigned n) {
  int i;
  if(n < 2) return 0;
  for(i = 2; i < n / 2; i++) if(!(n % i)) return 0;
  return 1;
}

unsigned prime(unsigned n) {
  unsigned i, p;
  for(i = p = 0; i < n; i++)
    for(p++; !is_prime(p); p++);
  return p;
}

unsigned pow_of_two(unsigned n) {
  unsigned p=1, i;
  for(i = 0; i < n; i++) p *= 2;
  return p;
}

unsigned perfect(unsigned n) {
  unsigned i, j, p;
  // Find n-th Mersenne Prime
  for(i = j = p = 0; i < n; i++)
    for(j++; !is_prime(p = pow_of_two(prime(j)) - 1); j++);
  return p * (p + 1) / 2;
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
  printf("Result: %u\n", perfect(n));
  return 0;
}
