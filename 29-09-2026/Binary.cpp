#include <iostream>
#include <string>

std::string toBinary(unsigned n) {
	switch(n) {
	case 0:
		return "0";
	case 1:
		return "1";
	default:
		return toBinary(n / 2) + (n % 2 ? "1" : "0");
	}
}

int main() {
	std::cout << toBinary(10) << std::endl;
	std::cout << toBinary(0) << std::endl;
}
