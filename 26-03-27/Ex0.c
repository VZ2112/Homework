/*****************************
 * Continuation of Classwork
 *****************************/

#include <stdlib.h>

int cmp_ints(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int find_pairs(unsigned k, unsigned n, int *arr) {
  int *val_arr, *quan_arr;
  int i, j, m, max, count=0;
  if(!(val_arr = malloc(n * sizeof(*val_arr)))) return -1; // malloc failed
  if(!(quan_arr = malloc(n * sizeof(*quan_arr)))) return -1; // malloc failed
  qsort(arr, n, sizeof(*arr), cmp_ints); // Sort in ascending Order
  for(i = 0; i < n; i++) quan_arr[i] = 0; // Initialize Quantity Array
  max = arr[0];
  j = 1;
  val_arr[0] = max;
  for(i = 0; i < n; i++) {
    if(max < arr[i])
      val_arr[j++] = max = arr[i];
    quan_arr[j - 1]++;
  }
  for(i = 0; i < j; i++)
    for(m = 0; m < j; m++) {
      if(i == m && !k) count += quan_arr[i] * (quan_arr[i] - 1) / 2;
      else if(val_arr[i] - val_arr[m] == k) count += quan_arr[i] * quan_arr[m];
    }
  return count;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned m, i, k;
  int arr[256];
  printf("Enter Size of Array:");
  scanf("%u", &m);
  printf("Enter Elements:");
  for(i = 0; i < m; i++) scanf("%d", &arr[i]);
  printf("Enter K:");
  scanf("%u", &k);
  printf("Result: %d\n", find_pairs(k, m, arr));
  return 0;
}
