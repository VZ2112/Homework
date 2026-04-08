int is_valid(char *str) {
  char *stack;
  unsigned i, sp;
  for(i = 0; str[i]; i++);
  stack = malloc(i);
  if(!stack) return -1;
  sp = 0;
  for(i = 0; str[i]; i++)
    switch(str[i]) {
    case '(':
      stack[sp++] = ')'; break;
    case '[':
      stack[sp++] = ']'; break;
    case '{':
      stack[sp++] = '}'; break;
    case ')':
    case ']':
    case '}':
      if(!sp) {free(stack); return 0;}
      if(stack[--sp] != str[i]) {free(stack); return 0;}
    default:;
    }
  free(stack);
  if(sp) return 0;
  return 1;
}

/***************
 * Boilerplate
 ***************/

#include <stdio.h>

int main() {
  char str[256];
  printf("Enter a String:");
  gets(str);
  puts(is_valid(str) ? "The String is valid." : "The String is invalid.");
  return 0;
}

