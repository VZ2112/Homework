#include <stdio.h>

int main() {
  unsigned i, c;
  for(i = 1; i <= 50; i++) {
    c = 0;
    if(!(i % 3)) printf("Fizz"), c++;
    if(!(i % 5)) printf("Buzz"), c++;
    if(!c) printf("%u", i);
    printf("\n");
  }
  return 0;
}
