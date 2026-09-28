#include <iostream>
#include "Reverse-Lib.h"

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	for(int i = 0; i < 7; i++) std::cout << arr[i] << ' ';
	std::cout << std::endl;
	reverse(arr, 7);
	for(int i = 0; i < 7; i++) std::cout << arr[i] << ' ';
	std::cout << std::endl;
}
