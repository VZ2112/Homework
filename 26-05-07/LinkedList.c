#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} *List;

int Insert(List *l, int value, int index) {
  int i;
  List next, *t1=NULL, *t2=NULL;
  t2 = l;
  if(!t2) return 0;
  for(i = 0; i < index && *t2; i++) {
    t1 = t2;
    t2 = &(*t2)->next;
  }
  if(i < index) return 0;
  if(!t1) t1 = t2;
  next = malloc(sizeof(*next));
  next->value = value;
  next->next = *t1;
  *t1 = next;
  return 1;
}

int Delete(List *l, int index) {
  int i;
  List next, *t1=NULL, *t2=NULL;
  t2 = l;
  if(!t2) return 0;
  for(i = 0; i < index && *t2; i++) {
    t1 = t2;
    t2 = &(*t2)->next;
  }
  if(i < index) return 0;
  if(!t1) return 0;
  next = *t2;
  free(*t1);
  *t1 = next;
  return 1;
}

int *Index(List *l, int index) {
  int i;
  List *t1=NULL;
  t1 = l;
  if(!t1 || !*t1) return NULL;
  for(i = 0; i < index && (*t1)->next; i++) {
    t1 = &(*t1)->next;
  }
  if(i < index) return NULL;
  if(!t1) return NULL;
  return &(*t1)->value;
}

int *Middle(List *l) {
  int i;
  List *t1;
  t1 = l;
  if(!t1 || !*t1) return NULL;
  for(i = 0; *t1; i++) t1 = &(*t1)->next;
  return Index(l, i / 2);
}

List Merge(List *l1, List *l2) {
  List res, t1, t2, *t3;
  t1 = *l1, t2 = *l2;
  *l1 = *l2 = NULL;
  t3 = &res;
  while(t1 && t2) {
    if(t1->value < t2->value) {
      *t3 = t1;
      t1 = t1->next;
    } else {
      *t3 = t2;
      t2 = t2->next;
    }
    t3 = &(*t3)->next;
  }
  if(t1) *t3 = t1;
  else *t3 = t2;
  return res;
}

#include <stdio.h>

int main() {
  List l1=NULL, l2=NULL, res;
  int i, *pa;
  Insert(&l1, 8, 0);
  Insert(&l1, 6, 0);
  Insert(&l1, 4, 0);
  Insert(&l1, 2, 0);
  Insert(&l2, 7, 0);
  Insert(&l2, 5, 0);
  Insert(&l2, 3, 0);
  Insert(&l2, 1, 0);
  for(i = 0; pa = Index(&l1, i); i++) printf("%d ", *pa); printf("\n");
  for(i = 0; pa = Index(&l2, i); i++) printf("%d ", *pa); printf("\n");
  res = Merge(&l1, &l2);
  for(i = 0; pa = Index(&res, i); i++) printf("%d ", *pa); printf("\n");
  printf("%d\n", *Middle(&res));
  return 0;
}
