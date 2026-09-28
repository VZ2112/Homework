#include "SwpRef-Lib.h"

void swap(int& a, int& b) {
	a += b;
	b = a - b;
	a -= b;
}
