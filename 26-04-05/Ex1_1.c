#include <stdlib.h>

int has_dup(unsigned n, int *arr) {
  unsigned m, i, j;
  int *tmp;
  if(!arr) return -1;
  if(!n) return 0;
  if(!(tmp = malloc(n * sizeof(*tmp)))) return -1;
  m = 0;
  for(i = 0; i < n; i++) {
    for(j = 0; j < m; j++) if(arr[i] == tmp[j]) {
      free(tmp);
      return 1;
    }
    tmp[m++] = arr[i];
  }
  free(tmp);
  return 0;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned n, i;
  int arr[256];
  printf("Enter the Size of the Array:");
  scanf("%u", &n);
  printf("Enter Contents:");
  for(i = 0; i < n; i++) scanf("%d", arr + i);
  printf("Array has%s duplicates.\n", has_dup(n, arr) ? "" : " no");
  return 0;
}

