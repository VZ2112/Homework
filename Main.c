unsigned fib(unsigned n) {
  unsigned a = 1, b = 0, i;
  for(i = 0; b < n; i++) {
    b += a;
    a = b - a;
  }
  return b == n ? i : 0;
}

#include <stdio.h>

int main() {
  unsigned n;
  scanf("%u", &n);
  printf("%u\n", fib(n));
  for(n = 0; n < 256; n++) {
    printf("%u ", fib(n));
    if(n % 16 == 15) printf("\n");
  }
  return 0;
}
