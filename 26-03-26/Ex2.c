#include <stdlib.h>

int cmp_ints(const void *a, const void *b) {
  return *(unsigned *)a - *(unsigned *)b;
}

unsigned *num_of_sticks(unsigned m, unsigned *arr) {
  if(!m) return NULL; // Cannot work with an empty Array
  unsigned *res = malloc(m * sizeof(*res));
  if(!res) return NULL; // malloc failed
  unsigned i, j, max;
  for(i = 0; i < m; i++) res[i] = 0; // Fill out with Zeroes
  qsort(arr, m, sizeof(*arr), cmp_ints); // Sort in ascending Order
  for(i = j = max = 0; i < m; i++)
    if(max < arr[i]) {
      max = arr[i];
      res[j++] = m - i;
    }
  return res;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned m, i;
  unsigned arr[256], *res;
  printf("Enter Size of Array:");
  scanf("%u", &m);
  printf("Enter Elements:");
  for(i = 0; i < m; i++) scanf("%u", &arr[i]);
  res = num_of_sticks(m, arr);
  printf("Number of Sticks before each Step:");
  for(i = 0; i < m; i++) printf(" %u", res[i]);
  return 0;
}
