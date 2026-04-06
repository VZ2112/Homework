#include <stdlib.h>

/**************************
 * Hashmap Implementation
 **************************/

typedef struct item {
  int key;
  int value;
  struct item *next;
} hash_item;

typedef struct {
  hash_item *data;
  unsigned capacity;
} hashmap;

hashmap *new_hashmap(unsigned cap) {
  hashmap *res;
  unsigned i;
  if(!(res = malloc(sizeof(*res)))) return NULL;
  res->capacity = cap;
  for(i = 0; i < 3; i++) if(res->data = calloc(cap, sizeof(*res->data))) break;
  if(i == 3) {
    free(res);
    return NULL;
  }
  return res;
}

void del_hashmap(hashmap *self) {
  free(self->data);
  free(self);
}

void insert(hashmap *self, int key, int value) {
  hash_item *prev, *item;
  unsigned i;
  for(item = &self->data[key % self->capacity]; item;
    prev = item, item = item->next)
    if(item->key == key) {
      item->value = value;
      return;
    }
  for(i = 0; i < 3; i++) if(item = malloc(sizeof(*item))) break;
  if(i == 3) return;
  prev->next = item;
  item->key = key;
  item->value = value;
  item->next = NULL;
}

int *find(hashmap *self, int key) {
  hash_item *item;
  for(item = &self->data[key % self->capacity]; item; item = item->next)
    if(item->key == key) return &item->value;
  return NULL;
}

/***********************
 * The Function itself
 ***********************/

int has_dup(unsigned n, int *arr) {
  hashmap *h;
  int *p;
  unsigned i;
  if(!arr) return -1;
  if(!n) return -1;
  h = new_hashmap(16);
  for(i = 0; i < n; i++)
    if(p = find(h, arr[i])) {
      del_hashmap(h);
      return 1;
    } else insert(h, arr[i], 1);
  del_hashmap(h);
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

