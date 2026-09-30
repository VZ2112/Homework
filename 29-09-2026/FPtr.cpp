#include <iostream>
#include <string>

int square(int n) {return n * n;}
int flipSign(int n) {return -n;}
int addTen(int n) {return n + 10;}

void applyAll(int *arr, int n, int (*f)(int)) {
	for(int i = 0; i < n; i++) arr[i] = f(arr[i]);
}

bool isPositive(int n) {return n > 0;}
bool divisibleByThree(int n) {return n % 3 == 0;}
bool isSingleDigit(int n) {return n >= 0 && n < 10;}

int countIf(const int *arr, int n, bool (*pred)(int)) {
	int count = 0;
	for(int i = 0; i < n; i++) if(pred(arr[i])) count++;
	return count;
}

int main() {
	int data[] = {-4, 0, 3, 12, 9, -6, 27, 8, 15};
	bool (*preds[])(int) = {isPositive, divisibleByThree, isSingleDigit};
	std::string names[] = {"Positive", "Divisible by Three", "Single Digit"};
	for(int i = 0; i < 3; i++) std::cout << names[i] << ": " << countIf(data, 9, preds[i]) << std::endl;
	for(int i = 0; i < 9; i++) std::cout << data[i] << ' ';
	std::cout << std::endl;
	applyAll(data, 9, square);
	for(int i = 0; i < 9; i++) std::cout << data[i] << ' ';
	std::cout << std::endl;
}
