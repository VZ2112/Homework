#define NULL 0

typedef struct Node {
  int value;
  struct Node *next;
} *List;

int Insert(List *l, int index, int value) {
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
  next->next = *t2;
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
  List *t1, t2;
  t = l;
  for(i = 0; i < index && *t2; i++) {
    t1 = t2;
    t2 = &(*t2)->next;
  }
  if(i < index) return NULL;
  if(!t1) return NULL;
  return &(*t1)->value;
}
