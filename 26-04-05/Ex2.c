#include <stdlib.h>
#include <string.h>

typedef struct str_node {
  char *data;
  struct str_node *next;
} str_node;

typedef struct str_list_node {
  str_node *data;
  struct str_list_node *next;
} str_list_node;

int chrcmp(void *a, void *b) {
  return *(char *)a - *(char *)b;
}

int is_angr(char *a, char *b) {
  char tmp1[256], tmp2[256];
  strcpy(tmp1, a);
  strcpy(tmp2, b);
  qsort(tmp1, strlen(tmp1), sizeof(char), chrcmp);
  qsort(tmp2, strlen(tmp2), sizeof(char), chrcmp);
  return !strcmp(tmp1, tmp2);
}

str_list_node *ord_by_angr(unsigned n, char arr[][256]) {
  str_list_node *res, *item_l;
  str_node *item, *next;
  unsigned i;
  if(!n || !arr) return NULL;
  res = NULL;
  for(i = 0; i < n; i++) {
    for(item_l = res; item_l; item_l = item_l->next)
      for(item = item_l->data; item; item = item->next)
        if(is_angr(arr[i], item->data)) {
          next = malloc(sizeof(*next));
          next->next = item_l->data;
          item_l->data = next;
          item_l->data->data = arr[i];
          goto succ;
        }
    item_l = malloc(sizeof(*item_l));
    item_l->next = res;
    res = item_l;
    res->data = malloc(sizeof(*res->data));
    res->data->next = NULL;
    res->data->data = arr[i];
    succ:;
  }
  return res;
}

/***********************
 * Incipit Boilerplate
 * Not honed for Users
 ***********************/

#include <stdio.h>

int main() {
  char arr[256][256];
  unsigned n, i;
  str_list_node *res, *item_l;
  str_node *item;
  printf("Enter Size of Array:");
  scanf("%u", &n);
  printf("Enter Contents:");
  for(i = 0; i < n; i++) scanf("%s", arr[i]);
  res = ord_by_angr(n, arr);
  for(item_l = res; item_l; item_l = item_l->next) {
    printf("[");
    for(item = item_l->data; item; item = item->next)
      printf("%s ", item->data);
    printf("\b]\n");
  }
  return 0;
}

