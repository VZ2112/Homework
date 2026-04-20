#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int *data;
  unsigned capacity;
  unsigned length;
} int_List;

typedef struct {
  char **data;
  unsigned capacity;
  unsigned length;
} string_List;

void push_int(int_List *l, int n) {
  if(!l->capacity) {
    l->data = malloc(sizeof(int));
    l->capacity = 1;
  }
  else if(l->length == l->capacity) l->data = realloc(l->data, (l->capacity = 2 * l->capacity) * sizeof(int));
  l->data[l->length++] = n;
}

int *pop_int(int_List *l) {
  if(!l->length) return NULL;
  return l->data + --l->length;
}

void push_string(string_List *l, char *s) {
  if(!l->capacity) {
    l->data = malloc(sizeof(char *));
    l->capacity = 1;
  }
  else if(l->length == l->capacity) l->data = realloc(l->data, (l->capacity = 2 * l->capacity) * sizeof(char *));
  l->data[l->length] = malloc(strlen(s) + 1);
  strcpy(l->data[l->length++], s);
}

char *pop_string(string_List *l) {
  if(!l->length) return NULL;
  return l->data[--l->length];
}

enum {COM_TYPE=1, COM_DELETE};

int_List commands={0}, added={0};
string_List deleted={0};
char *edited=NULL;

void type(char *arg, int v) {
  if(!edited) edited = calloc(1, 1);
  edited = realloc(edited, strlen(edited) + strlen(arg) + 1);
  strcat(edited, arg);
  if(v) {
    push_int(&commands, COM_TYPE);
    push_int(&added, strlen(arg));
    printf("Typed %u Characters.\n", (unsigned)strlen(arg));
  }
}

void delete(unsigned n, int v) {
  unsigned l = strlen(edited);
  if(n > l) n = l;
  if(v) {
    push_int(&commands, COM_DELETE);
    push_string(&deleted, edited + l - n);
    printf("Deleted %u Characters.\n", n);
  }
  edited[l - n] = '\0';
}

void undo() {
  int *p, *n;
  char *s;
  p = pop_int(&commands);
  if(!p) {
    puts("No Action to undo.");
    return;
  }
  if(*p == COM_TYPE) {
    p = pop_int(&added);
    delete(*p, 0);
  }
  if(*p == COM_DELETE) {
    s = pop_string(&deleted);
    type(s, 0);
    free(s);
  }
  puts("Action undone.");
}

void prt() {
  puts(edited);
}

int main() {
  char entered[1024], command[16], arg[1024];
  unsigned n, i;
  while(1) {
    printf("$>");
    gets(entered);
    if(feof(stdin)) break;
    sscanf(entered, "%s %s", command, arg);
    if(!strcmp(command, "type")) type(arg, 1);
    else if(!strcmp(command, "delete") && sscanf(arg, "%u", &n)) delete(n, 1);
    else if(!strcmp(command, "print")) prt();
    else if(!strcmp(command, "undo")) undo();
    else puts("Bad Command or Argument.");
  }
  return 0;
}
    
