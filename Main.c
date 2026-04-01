#include <stdlib.h>

int is_armstrong(unsigned long long n, unsigned short k) {
	unsigned long long m, i, l;
	unsigned short j;
	m = n;
	l = 0;
	while(m > 0) {
		i = 1;
		for(j = 0; j < k; j++) i *= m % 10;
		l += i;
		m /= 10;
	}
	return l == n;
}

unsigned long long pow_of_10(unsigned short k) {
	unsigned short i;
	unsigned long long res=1;
	for(i = 0; i < k; i++) res *= 10;
	return res;
}

int armstrong_numbers(unsigned short *n, unsigned long long **res, unsigned short k) {
	unsigned long long i, j;
	*n = 0;
	*res = NULL;
	j = pow_of_10(k);
	for(i = pow_of_10(k - 1); i < j; i++)
		if(is_armstrong(i, k)) {
			if(!(*res = realloc(*res, ++*n * sizeof(**res)))) return 0; // malloc failed
			(*res)[*n - 1] = i;
		}
	return 1;
}

#include <stdio.h>

int main() {
	unsigned short n, k, i;
	unsigned long long *res;
	scanf("%hu", &k);
	if(armstrong_numbers(&n, &res, k)) {
		for(i = 0; i < n; i++) printf("%llu ", res[i]);
		printf("\n");
	}
	if(res) free(res);
	return 0;
}
