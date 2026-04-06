#include <string.h>
#include <stdlib.h>

int strrow(char *str, char *cmp) {
  unsigned i;
  if(!str || !cmp) return 0;
  for(i = 0; str[i]; i++)
    if(!strchr(cmp, str[i])) return 0;
  return 1;
}

int one_row(unsigned *m, char ***res, unsigned n, char *strs[]) {
  unsigned i;
  if(!(*res = malloc(n * sizeof(**res)))) return 0;
  *m = 0;
  for(i = 0; i < n; i++) {
    if(strrow(strs[i], "QWERTYUIOPqwertyuiop")) (*res)[(*m)++] = strs[i];
    if(strrow(strs[i], "ASDFGHJKLasdfghjkl")) (*res)[(*m)++] = strs[i];
    if(strrow(strs[i], "ZXCVBNMzxcvbnm")) (*res)[(*m)++] = strs[i];
  }
  return 1;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  char strs[256][256], **res;
  unsigned n, m, i;
  int chk;
  printf("Enter Number of Strings:");
  scanf("%u", &n);
  printf("Enter Words:");
  for(i = 0; i < n; i++) scanf("%s", strs[i]);
  chk = one_row(&m, &res, n, strs);
  if(!chk) printf("Allocation Error.\n");
  else {
    printf("Result:\n");
    for(i = 0; i < m; i++) printf("\t%s\n", res[i]);
  }
  return 0;
}
