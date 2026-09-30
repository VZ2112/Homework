#include <iostream>
#include <string>

std::string letterGrade(int score) {
	switch(score / 10) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		return "F";
	case 6:
		return "D";
	case 7:
		return "C";
	case 8:
		return "B";
	case 9:
	case 10:
		return "A";
	default:
		return "";
	}
}

int main() {
	std::cout << 100 << ' ' << letterGrade(100) << std::endl;
	std::cout << 95 << ' ' << letterGrade(95) << std::endl;
	std::cout << 83 << ' ' << letterGrade(83) << std::endl;
	std::cout << 55 << ' ' << letterGrade(55) << std::endl;
}
