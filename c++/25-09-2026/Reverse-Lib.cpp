#include "Reverse-Lib.h"

void reverse(int *arr, int size) {
	int tmp;
	for(int i = 0; i < size / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
	}
}
