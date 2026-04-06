int is_ugly(unsigned n) {
  while(!(n % 2)) n /= 2;
  while(!(n % 3)) n /= 3;
  while(!(n % 5)) n /= 5;
  return n == 1;
}

unsigned ugly(unsigned n) {
  int i, j;
  for(i = j = 0; i < n; i++) {
    for(j++; !is_ugly(j); j++);
  }
  return j;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned i;
  for(i = 0; i < 256; i++) printf("%u ", ugly(i));
  return 0;
}

