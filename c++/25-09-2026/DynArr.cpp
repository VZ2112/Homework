#include <iostream>
#include "DynArr-Lib.h"

int main() {
	int size = 7;
	int *arr = new int[7];
	for(int i = 0; i < size; i++) arr[i] = i;
	for(int i = 0; i < size; i++) std::cout << arr[i] << ' ';
	std::cout << std::endl;
	size = dblSize(&arr, size);
	for(int i = 0; i < size; i++) std::cout << arr[i] << ' ';
	std::cout << std::endl;
}
