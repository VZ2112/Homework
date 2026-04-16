#include <stdio.h>
#include "Table.c"

int read_item(Item *itm, FILE *f) {
  char buf[1024];
  int res;
  res = fscanf("%u,%[^,],%f,%f,%[^,],%[^,],%[^,],%u", &itm->ID, itm->city, &itm->lat, &itm->lng, itm->country, itm->iso2, itm->iso3, &item->population);
  return res == 8;
}

Table *build(char *left, char *op, char *right, unsigned rightnum) {
  Table *res;
  Item tmp;
  FILE *f;
  char field=0, opnum=0;
  int cmp;
  double leftnum;
  if(!strcmp(left, "population")) field = 1;
  if(!strcmp(left, "country")) field = 2;
  if(!strcmp(left, "lat")) field = 3;
  if(!strcmp(left, "lng")) field = 4;
  if(!strcmp(left, "city")) field = 5;
  
  if(!strcmp(op, "=") || !strcmp(op, "==")) opnum = 1;
  if(!strcmp(op, "<")) opnum = 2;
  if(!strcmp(op, "<=")) opnum = 3;
  if(!strcmp(op, ">")) opnum = 4;
  if(!strcmp(op, ">=")) opnum = 5;
  
  if(!field || !opnum) return NULL;
  switch(field) {
  case 1:
  case 3:
  case 4:
    if(right[0]) return NULL;
    break;
  case 2:
  case 5:
    if(!right[0]) return NULL;
  default:;
  }
  
  if(field == 5) {
    field = 1;
    rightnum = 0;
    f = fopen("worldcities.csv", "r");
    fscanf(f, "%*s");
    while(read_item(&tmp, f))
      if(strcmp(tmp.city, right)) {
        rightnum = tmp.population;
        break;
      }
    fclose(f);
  }
  
  res = new_Table();
  if(!res) return NULL;
  
  fscanf(f, "%*s");
  while(read_item(&tmp, f)) {
    if(field == 2)
      if(opnum == 1) cmp = !strcmp(tmp.country, right);
      else {
        del_table(res);
        return NULL;
      }
    switch(field) {
    case 1:
      leftnum = tmp.population;
      break;
    case 3:
      leftnum = tmp.lat;
      break;
    case 4:
      leftnum = tmp.lng;
      break;
    case 5:
      leftnum = tmp.population;
    }
    switch(opnum) {
    case 1:
      cmp = leftnum == rightnum;
    case 2:
      cmp = leftnum < rightnum;
    case 3:
      cmp = leftnum <= rightnum;
    case 4:
      cmp = leftnum > rightnum;
    case 5:
      cmp = leftnum >= rightnum;
    }
    if(cmp) append_Table(res, &tmp);
  }
  fclose(f);
  
  return res;
}

Table *query(char *qry) {
  char left[64], right[64], op[64];
  unsigned i, j, rightnum=0;
  for(i = 0; qry[i] == ' '; i++);
  for(j = 0; strchr("abcdefghijklmnopqrstuvwxyz", qry[i]); i++) left[j++] = qry[i];
  left[j] = '\0';
  if(!j) return NULL;
  for(; qry[i] == ' '; i++);
  j = 0;
  switch(qry[i]) {
  case '=':
  case '<':
  case '>':
    op[j++] = qry[i++];
    if(qry[i] == '=') op[j++] = qry[i++];
  default:;
  }
  op[j] = '\0';
  if(!j) return NULL;
  for(; qry[i] == ' '; i++);
  j = 0;
  for(j = 0; strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", qry[i]); i++)
    right[j++] = qry[i];
  right[j] = '\0';
  if(!j)
    for(j = 0; strchr("0123456789", qry[i]); i++)
      rightnum = rightnum * 10 + qry[i] - '0', j++;
  if(!j) return NULL;
  return build(left, op, right, rightnum);
}
    
