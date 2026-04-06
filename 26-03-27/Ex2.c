unsigned find_conned(unsigned n, unsigned m, unsigned s) {
  int res;
  if(!n || !m || !s || s > n) return 0; // Fail Condition
  res = (m + s - 1) % n;
  if(!res) res += n;
  return res;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned n, m, s;
  printf("Enter Number of Seats, Cakes and first Seat:");
  scanf("%u %u %u", &n, &m, &s);
  printf("Prisoner No. %u will get the bad Cake.\n", find_conned(n, m, s));
  return 0;
}
