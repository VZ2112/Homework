#include <stdlib.h>

int cmp_ints(const void *a, const void *b) {
  return *(int *)b - *(int *)a;
}

int nth_largest(unsigned m, unsigned n, int *arr) {
  qsort(arr, m, sizeof(*arr), cmp_ints); // Sort in descending Order
  unsigned i;
  int min=arr[0];
  n--;
  for(i = 0; i < m; i++) {
    if(min > arr[i]) {
      min = arr[i];
      n--;
    }
    if(!n) return min;
  }
  return 0;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned m, i;
  int arr[256];
  printf("Enter Size of Array:");
  scanf("%u", &m);
  printf("Enter Elements:");
  for(i = 0; i < m; i++) scanf("%d", &arr[i]);
  for(i = 0; i < m; i++) printf("%u %d\n",i + 1, nth_largest(m, i + 1, arr));
  return 0;
}
