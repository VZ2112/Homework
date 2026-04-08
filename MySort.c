unsigned long long mem_copy(unsigned long long size, void *dest, void *src) {
  unsigned long long i;
  for(i = 0; i < size; i++) ((char *)dest)[i] = ((char *)src)[i];
  return i;
}

void sort(unsigned long long count, unsigned long long size, void *mem, int (*cmp)(void *, void *)) {
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
