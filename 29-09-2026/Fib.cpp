#include <iostream>

int fib(unsigned n) {
	if(n < 2) return n;
	return fib(n - 2) + fib(n - 1);
}

int main() {
	std::cout << fib(10) << std::endl;
}
