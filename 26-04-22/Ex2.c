#include <stdlib.h>
#include <stdio.h>

int bin_search(int *arr, unsigned begin, unsigned end, int n) {
  unsigned middle;
  if(end <= begin) return -1;
  if(end - begin == 1) return arr[begin] == n ? begin : -1;
  middle = (begin + end) / 2;
  if(arr[middle] > n) return bin_search(arr, begin, middle, n);
  return bin_search(arr, middle, end, n);
}

int cmp(void *a, void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
  unsigned i, n;
  int k, arr[256];
  printf("Enter the Length of Array:");
  scanf("%u", &n);
  printf("Enter Contents:");
  for(i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  qsort(arr, sizeof(int), n, cmp);
  printf("Enter a Number:");
  scanf("%d", &k);
  printf("Result: %d", bin_search(arr, 0, n, k));
}
