#include <iostream>
#include "Mod-Lib.h"

int main() {
	int a = 7;
	std::cout << a << ' ' << (dbl(&a), a) << std::endl;
}
