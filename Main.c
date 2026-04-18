#include <stdio.h>
#include <string.h>

typedef struct {
  unsigned ID;
  char name[64];
  unsigned pop;
} City;

City said[1024];
unsigned len;
char buf[1024];
char last[64] = "";

int help(char *str) {
  City tmp, tmp2;
  FILE *f;
  unsigned i, n;
  int maxpop = -1;
  if(last[0]) {
    last[0] = last[strlen(last) - 1];
    last[0] = last[0] & 0x40 && last[0] & 0x20 ? last[0] - 0x20 : last[0];
    strcpy(tmp.name, last);
  }
  n = strlen(str);
  f = fopen("worldcities.csv", "r");
  fgets(buf, 1024, f);
  while(fgets(buf, 1024, f) && buf[0] && buf[0] != '\n') {
    sscanf(buf, "%u,%[^,]", &tmp2.ID, tmp2.name);
    for(n = strlen(buf); buf[n - 1] == '\n' || buf[n - 1] >= '0' && buf[n - 1] <= '9'; n--);
    sscanf(buf + n, "%u", &tmp2.pop);
    if(!tmp.name[0] || tmp.name[0] == tmp2.name[0] && (long)tmp2.pop > maxpop) {
      for(i = 0; i < len; i++) if(!strcmp(tmp2.name, said[i].name)) goto sd;
      maxpop = tmp2.pop;
      tmp = tmp2;
    sd:;
    }
  }
  if(maxpop < 0) puts("Ran out of Cities.");
  else {
    printf("What about %s.\n", tmp.name);
    said[len++] = tmp;
    if(len == 1024) {
      puts("Cannot remember any more Cities.");
      goto fail;
    }
    strcpy(last, tmp.name);
  }
fail:
  fclose(f);
}

int test(char *str) {
  City tmp, tmp2;
  FILE *f;
  unsigned i, n;
  int maxpop = -1;
  if(last[0]) {
    last[0] = last[strlen(last) - 1];
    last[0] = last[0] & 0x40 && last[0] & 0x20 ? last[0] - 0x20 : last[0];
    if(last[0] != str[0]) {
      puts("Letters mismatch!");
      return 0;
    }
  }
  n = strlen(str);
  f = fopen("worldcities.csv", "r");
  fgets(buf, 1024, f);
  while(fgets(buf, 1024, f) && buf[0] && buf[0] != '\n') {
    sscanf(buf, "%u,%[^,]", &tmp.ID, tmp.name);
    if(strcmp(tmp.name, str)) continue;
    for(i = 0; i < len; i++)
      if(said[i].ID == tmp.ID) {
        puts("That City is already named!");
        goto fail;
      }
    said[len++] = tmp;
    if(len == 1024) {
      puts("Cannot remember any more Cities.");
      goto fail;
    }
    fseek(f, 0, SEEK_SET);
    tmp.name[0] = tmp.name[n - 1];
    tmp.name[0] = tmp.name[0] & 0x40 && tmp.name[0] & 0x20 ? tmp.name[0] - 0x20 : tmp.name[0];
    fgets(buf, 1024, f);
    while(fgets(buf, 1024, f) && buf[0] && buf[0] != '\n') {
      sscanf(buf, "%u,%[^,]", &tmp2.ID, tmp2.name);
      for(n = strlen(buf); buf[n - 1] == '\n' || buf[n - 1] >= '0' && buf[n - 1] <= '9'; n--);
      sscanf(buf + n, "%u", &tmp2.pop);
      if(tmp.name[0] == tmp2.name[0] && (long)tmp2.pop > maxpop) {
        for(i = 0; i < len; i++) if(!strcmp(tmp2.name, said[i].name)) goto sd;
        maxpop = tmp2.pop;
        tmp = tmp2;
      sd:;
      }
    }
    if(maxpop < 0) puts("Ran out of Cities.");
    else {
      printf("I say %s.\n", tmp.name);
      said[len++] = tmp;
      if(len == 1024) {
        puts("Cannot remember any more Cities.");
        goto fail;
      }
      strcpy(last, tmp.name);
    }
    goto fail;
  }
  puts("That City does not exist!");
fail:
  fclose(f);
}

int main() {
  char str[256];
  while(1) {
    printf("Enter a City Name:");
    gets(str);
    if(!strcmp(str, "help")) help(str);
    test(str);
  }
  return 0;
}
