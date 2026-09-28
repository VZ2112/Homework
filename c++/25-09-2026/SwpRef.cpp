#include <iostream>
#include "SwpRef-Lib.h"

int main() {
	int a=4, b=3;
	std::cout << a << ' ' << b << std::endl;
	swap(a, b);
	std::cout << a << ' ' << b << std::endl;
}
