int num_of_stat(unsigned radius, unsigned n, int *country) {
  int i=0, j, stat=0;
  while(i < n) {
    i += radius - 1;
    if(i >= n) i = n - 1;
    for(j = 0; j < radius; j++)
      if(country[i - j]) goto found;
    return -1;
    found: stat++;
    i += radius;
  }
  return stat;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned radius, n, i;
  int stat, country[256];
  printf("Enter the Radius:");
  scanf("%u", &radius);
  printf("Enter Size of Country:");
  scanf("%u", &n);
  printf("Enter which Towns can have a Station (1 means can, 0 means cannot):");
  for(i = 0; i < n; i++) scanf("%d", &country[i]);
  stat = num_of_stat(radius, n, country);
  printf("Number of Stations required to fully cover the Country: %d\n", stat);
  return 0;
}
