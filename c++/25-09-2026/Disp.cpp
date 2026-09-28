#include <iostream>
#include "Disp-Lib.h"

int main() {
	int a = 7, b = 8, op;
	std::cin >> op;
	if(op < 0 || op >= 5) {
		std::cout << "Invalid Option." << std::endl;
		return 1;
	}
	std::cout << ops[op](a, b) << std::endl;
}
