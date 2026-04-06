unsigned n;
int ver[256];

int isbad(unsigned k) {
  if(!k || k > n) return -1;
  if(ver[k - 1]) return 1;
  return 0;
}

int find_1st_bad(unsigned begin, unsigned end) {
  if(!begin || end > n || begin > end) return -1;
  while(begin != end)
    if(isbad((begin + end) / 2)) end = (begin + end) / 2;
    else begin = (begin + end) / 2 + 1;
  return begin;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned k, i;
  int res;
  printf("Enter Number of Versions:");
  scanf("%u", &n);
  printf("Enter First Bad Version:");
  scanf("%u", &k);
  for(i = 1; i < k; i++) ver[i - 1] = 0;
  for(; i <= n; i++) ver[i - 1] = 1;
  res = find_1st_bad(1, n);
  if(res < 0) printf("Bounds Error.\n");
  else if(!res) printf("All good.\n");
  else printf("Version %d bad.\n", res);
  return 0;
}
