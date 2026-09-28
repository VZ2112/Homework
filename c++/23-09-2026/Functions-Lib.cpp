#include "Functions-Lib.h"

bool is_prime(unsigned n) {
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++)
		if(!(n % i)) return 0;
	return 1;
}

int power(int a, unsigned b) {
	if(!b) return 1;
	return a * power(a, b - 1);
}

int fibonacci(unsigned n) {
	if(n < 2) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
