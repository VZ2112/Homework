int until_warm(unsigned n, unsigned *dest, int *tmps) {
  unsigned i, j;
  if(!n || !dest || !tmps) return 0;
  for(i = 0; i < n; i++) {
    for(j = i + 1; j < n; j++)
      if(tmps[j] > tmps[i]) {
        dest[i] = j - i;
        goto wait;
      }
    dest[i] = 0;
    wait:;
  }
  return 1;
}

#include <stdio.h>

int main() {
  unsigned n, i, wait[256];
  int tmps[256];
  printf("Enter Number of Days:");
  scanf("%u", &n);
  printf("Enter Temperatures:");
  for(i = 0; i < n; i++) scanf("%d", tmps + i);
  until_warm(n, wait, tmps);
  printf("Days to wait until warmer than Today:");
  for(i = 0; i < n; i++) printf("%u ", wait[i]);
  printf("\n");
  return 0;
}
