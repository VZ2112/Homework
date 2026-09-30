#include <iostream>

int daysInMonth(int month, bool leap=false) {
	switch(month) {
	case 2:
		return 28 + leap;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	default:
		return 0;
	}
}

int main() {
	std::cout << daysInMonth(2) << std::endl;
	std::cout << daysInMonth(2, true) << std::endl;
	std::cout << daysInMonth(12) << std::endl;
}
