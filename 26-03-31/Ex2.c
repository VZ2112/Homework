#include <stdlib.h>

int longest_run(unsigned *m, int **res, unsigned n, int *arr) {
  unsigned i, j, k, l;
  if(!n || !arr) return 0;
  i = k = 0;
  j = 1;
  for(l = 1; l < n; l++)
    if(arr[l] == arr[l - 1]) return -1;
    else if(arr[l] < arr[l - 1]) {
      if(l - k > j - i) {
        i = k;
        j = l;
      }
      k = l;
    }
  if(l - k > j - i) {
      i = k;
      j = l;
    }
  if(!(*res = malloc((j - i) * sizeof(**res)))) return 0;
  *m = j - i;
  for(k = 0; k < *m; k++) (*res)[k] = arr[i + k];
  return 1;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  unsigned i, m, n;
  int arr[256], *res, chk;
  printf("Enter Size of Array:");
  scanf("%u", &n);
  printf("Enter Elements:");
  for(i = 0; i < n; i++) scanf("%d", arr + i);
  chk = longest_run(&m, &res, n, arr);
  if(chk < 0) printf("Repetition found.\n");
  else if(!chk) printf("Allocation Error.\n");
  else if(res) {
    printf("Longest Run is: ");
    for(i = 0; i < m; i++) printf("%d ", res[i]);
    printf("\n");
  }
  return 0;
}
