#pragma once

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int dvd(int a, int b);
int mod(int a, int b);

int (*ops[])(int, int) = {add, sub, mul, dvd, mod};
