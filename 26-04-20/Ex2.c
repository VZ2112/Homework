#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int *data;
  unsigned capacity;
  unsigned length;
} int_List;

void push_int(int_List *l, int n) {
  if(!l->capacity) {
    l->data = malloc(sizeof(int));
    l->capacity = 1;
  }
  else if(l->length == l->capacity) l->data = realloc(l->data, (l->capacity = 2 * l->capacity) * sizeof(int));
  l->data[l->length++] = n;
}

enum {COM_DEPOSIT=1, COM_WITHDRAW};

int_List commands={0}, amounts={0};
unsigned balance=0;

void deposit(unsigned n) {
  balance += n;
  push_int(&commands, COM_DEPOSIT);
  push_int(&amounts, n);
  printf("Successfully deposited $%u.\n", n);
}

void withdraw(unsigned n) {
  if(balance < n) {
    puts("Not enough Money.");
    return;
  }
  balance -= n;
  push_int(&commands, COM_WITHDRAW);
  push_int(&amounts, n);
  printf("Successfully withdrawn $%u.\n", n);
}

void prt() {
  printf("The current Balance is $%u.\n", balance);
}

void history() {
  unsigned i;
  puts("Transaction History.");
  puts("Action   Amount");
  for(i = 0; i < commands.length; i++) {
    if(commands.data[i] == COM_DEPOSIT) printf("Deposit  ");
    if(commands.data[i] == COM_WITHDRAW) printf("Withdraw ");
    printf("%u\n", amounts.data[i]);
  }
  prt();
}

int main() {
  char entered[1024], command[16];
  unsigned n, r;
  while(1) {
    printf("$>");
    gets(entered);
    if(feof(stdin)) break;
    if(!(r = sscanf(entered, "%s %u", command, &n))) {
      puts("Bad Command or Argument.");
      continue;
    }
    if(!strcmp(command, "deposit") && r > 1) deposit(n);
    else if(!strcmp(command, "withdraw") && r > 1) withdraw(n);
    else if(!strcmp(command, "balance")) prt();
    else if(!strcmp(command, "history")) history();
    else puts("Bad Command or Argument.");
  }
  return 0;
}
    
