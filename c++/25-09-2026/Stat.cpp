#include <iostream>

int main() {
	int arr[10];
	std::cout << "Enter 10 Numbers:";
	for(int i = 0; i < 10; i++) std::cin >> arr[i];
	int min, max, sum;
	double avg;
	min = max = arr[0];
	sum = 0;
	for(int i = 0; i < 10; i++) {
		if(arr[i] < min) min = arr[i];
		if(arr[i] > max) max = arr[i];
		sum += arr[i];
	}
	avg = (double)sum / 10;
	std::cout << "Minimum: " << min << ", Maximum: " << max << ", Sum: " << sum << ", Average: " << avg << std::endl;
}
