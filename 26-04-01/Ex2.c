int where_to_start(unsigned n, unsigned *stat, unsigned *cost) {
  unsigned i, j;
  int gas;
  if(!n || !stat || !cost) return -1;
  for(i = 0; i < n; i++) {
    gas = 0;
    for(j = 0; j < n; j++) {
      gas += stat[(i + j) % n] - cost[(i + j) % n];
      if(gas < 0) break;
    }
    if(gas >= 0) return i;
  }
  return -1;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned i, n, stat[256], cost[256];
  int res;
  printf("Enter Number of Stations:");
  scanf("%u", &n);
  printf("Enter Gas Amounts:");
  for(i = 0; i < n; i++) scanf("%u", stat + i);
  printf("Enter Road Costs:");
  for(i = 0; i < n; i++) scanf("%u", cost + i);
  res = where_to_start(n, stat, cost);
  if(n < 0) printf("Impossible to traverse the Cycle.\n");
  else printf("Begin at Station %u.\n", res);
  return 0;
}
