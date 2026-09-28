#include <iostream>

int main() {
	double a, b;
	char op;
	std::cout << "Enter an Expression: ";
	std::cin >> a >> op >> b;
	switch(op) {
	case '+':
		std::cout << a + b << std::endl;
		break;
	case '-':
		std::cout << a - b << std::endl;
		break;
	case '*':
		std::cout << a * b << std::endl;
		break;
	case '/':
		if(b) std::cout << a / b << std::endl;
		else std::cout << "Cannot divide by Zero.\n";
		break;
	default:
		std::cout << "Invalid Operation.\n";
	}
}
