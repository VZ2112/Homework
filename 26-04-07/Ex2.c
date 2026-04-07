#include <stdlib.h>

struct pair {
  int key;
  unsigned freq;
};

int cmppair(void *a, void *b) {
  return ((struct pair *)b)->freq - ((struct pair *)a)->freq;
}

unsigned most_freq(int *dest, unsigned n, int *src, unsigned k) {
  struct pair ht[n];
  unsigned i, j, l;
  if(!dest || !n || !src || !k) return 0;
  l = 0;
  for(i = 0; i < n; i++) {
    for(j = 0; j < l; j++)
      if(ht[j].key == src[i]) {
        ht[j].freq++;
        goto exist;
      }
    ht[l++].key = src[i];
    ht[l].freq = 1;
  exist:;
  }
  qsort(ht, l, sizeof(struct pair), cmppair);
  if(k > l) k = l;
  for(i = 0; i < k; i++) dest[i] = ht[i].key;
  return k;
}
  

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  int src[256], dest[256];
  unsigned i, k, m, n;
  printf("Enter the Size of the Array:");
  scanf("%u", &n);
  printf("Enter Contents of the Array:");
  for(i = 0; i < n; i++) scanf("%i", src + i);
  printf("Enter k:");
  scanf("%u", &k);
  m = most_freq(dest, n, src, k);
  printf("Result: [");
  for(i = 0; i < m; i++) printf("%d ", dest[i]);
  printf("\b]\n");
  return 0;
}

