#include <stdlib.h>

typedef struct {
  unsigned ID;
  char city[64];
  float lat;
  float lng;
  char country[64];
  char iso2[2];
  char iso3[3];
  unsigned population;
} Item;

typedef struct {
  Item *data;
  unsigned capacity;
  unsigned length;
} Table;

Table *new_Table() {
  Table *res = malloc(sizeof(*res));
  if(!res) return NULL;
  res->capacity = 16;
  res->length = 0;
  res->data = malloc(res->capacity * sizeof(*res->data));
  if(!res->data) {
    free(res);
    return NULL;
  }
  return res;
}

void del_Table(Table *t) {
  free(t->data);
  free(t);
}

void append_Table(Table *t, Item *item) {
  if(t->length == t_>capacity) {
    t->capacity *= 2;
    t->data = realloc(t->data, res->capacity * sizeof(*res->data));
  }
  t->data[t->length++] = *item;
}

Item *index_Table(Table *t, unsigned index) {
  if(index >= t->length) return NULL;
  return &t->data[index];
}
