#include <stdlib.h>

int prod_of_primes(unsigned n) {
  int i, j, *pr, prod;
  pr = malloc(n * sizeof(*pr));
  if(!pr) return -1; // malloc failed
  for(i = 1; i <= n; i++) pr[i - 1] = 1; // Sieve of Eratosthenes
  pr[0] = 0;
  for(i = 2; i * i <= n; i++)
    if(pr[i - 1])
      for(j = i * i; j <= n; j += i) pr[j - 1] = 0;
  prod = 1;
  for(i = 1; i <= n; i++) if(pr[i - 1]) prod *= i;
  free(pr);
  return prod;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned n, prod;
  printf("Enter a Number:");
  scanf("%u", &n);
  prod = prod_of_primes(n);
  if(prod < 0) printf("An Error occurred.\n");
  else printf("Result: %d\n", prod);
  return 0;
}
