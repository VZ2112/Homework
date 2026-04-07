#include <stdlib.h>

int num_of_sub(unsigned n, int *arr, int k) {
  int *tmp;
  unsigned i, count;
  if(!n) return 0;
  if(n == 1 && arr[0] == k) return 1;
  for(i = count = 0; i < n; i++) if(arr[i] == k) count++;
  tmp = malloc((n - 1) * sizeof(*tmp));
  for(i = 0; i < n - 1; i++) tmp[i] = arr[i] + arr[i + 1];
  count += num_of_sub(n - 1, tmp, k);
  free(tmp);
  return count;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned n, i;
  int arr[256], k;
  printf("Enter the Size of the Array:");
  scanf("%u", &n);
  printf("Enter the Contents:");
  for(i = 0; i < n; i++) scanf("%d", arr + i);
  printf("Enter k:");
  scanf("%d", &k);
  printf("Number of Subarrays Summing to k: %d\n", num_of_sub(n, arr, k));
  return 0;
}

