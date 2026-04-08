unsigned long long mem_copy(unsigned long long size, void *dest, void *src) {
  unsigned long long i;
  for(i = 0; i < size; i++) ((char *)dest)[i] = ((char *)src)[i];
  return i;
}

void sort(unsigned long long count, unsigned long long size, void *mem,
    int (*cmp)(void *, void *)) {
  unsigned long long i, j;
  char tmp[size];
  if(count < 2) return;
  for(i = j = 0; i < count - 1; i++)
    if(cmp((char *)mem + size * i, (char *)mem + (count - 1) * size) < 0) {
      mem_copy(size, tmp, (char *)mem + j * size);
      mem_copy(size, (char *)mem + j++ * size, (char *)mem + i * size);
      mem_copy(size, (char *)mem + i * size, tmp);
    }
  mem_copy(size, tmp, (char *)mem + j * size);
  mem_copy(size, (char *)mem + j * size, (char *)mem + i * size);
  mem_copy(size, (char *)mem + i * size, tmp);
  sort(j, size, mem, cmp);
  sort(count - j - 1, size, (char *)mem + (j + 1) * size, cmp);
}

//The Code itself

struct interval {
  int starti;
  int endi;
};

int itvl_cmp(void *a, void *b) {
  return ((struct interval *)a)->starti - ((struct interval *)b)->starti;
}

unsigned merge_itvl(unsigned n, struct interval *dest, struct interval *src) {
  unsigned i, j;
  if(!n || !dest || !src) return 0;
  sort(n, sizeof(struct interval), src, itvl_cmp);
  dest[0] = src[0];
  j = 1;
  for(i = 0; i < n; i++)
    if(dest[j - 1].endi >= src[i].starti) {
      if(dest[j - 1].endi <= src[i].endi)
        dest[j - 1].endi = src[i].endi;
    } else dest[j++] = src[i];
  return j;
}

unsigned add_itvl(struct interval new,
    unsigned *n, struct interval *dest, struct interval *src) {
  src[(*n)++] = new;
  return merge_itvl(*n, dest, src);
}

#include <stdio.h>

int main() {
  unsigned i, m, n;
  struct interval dest[256], src[256], new;
  printf("Enter Number of Intervals:");
  scanf("%u", &n);
  printf("Enter Starts and Ends of Intervals:");
  for(i = 0; i < n; i++) {
    scanf("%d", &src[i].starti);
    scanf("%d", &src[i].endi);
    if(src[i].starti > src[i].endi) {
      int tmp;
      tmp = src[i].starti;
      src[i].starti = src[i].endi;
      src[i].endi = tmp;
    }
  } // Assumed to not contain intersecting Intervals
  printf("Enter the Bounds of the Interval to add:");
  scanf("%d", &new.starti);
  scanf("%d", &new.endi);
  if(new.starti > new.endi) {
    int tmp;
    tmp = new.starti;
    new.starti = new.endi;
    new.endi = tmp;
  }
  m = add_itvl(new, &n, dest, src);
  printf("Result:");
  for(i = 0; i < m; i++)
    printf("[%d, %d] ", dest[i].starti, dest[i].endi);
  printf("\n");
  return 0;
}
