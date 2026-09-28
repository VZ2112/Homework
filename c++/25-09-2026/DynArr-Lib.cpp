#include "DynArr-Lib.h"

int dblSize(int **arr, int size) {
	int *res = new int[size * 2];
	for(int i = 0; i < size; i++) res[i] = (*arr)[i];
	for(int i = 0; i < size; i++) res[size + i] = (*arr)[i] * (*arr)[i];
	*arr = res;
	return size * 2;
}
