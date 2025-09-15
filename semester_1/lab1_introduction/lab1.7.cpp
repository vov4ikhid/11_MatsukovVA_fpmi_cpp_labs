#include <iostream>

int main() {
	setlocale(0, "");
	int n;
	std::cout << "Enter number n: ";
	if (!(std::cin >> n)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	if (n < 1) {
		std::cout << "Number n must be >= 1" << std::endl;
		std::exit(1);
	}
	double num;
	double min, max;
	double sum = 0;
	bool num1 = true;

	for (int i = 1; i <= n; i++) {
		std::cout << "Enter number: " << i << ": ";
		if (!(std::cin >> num)) {
			std::cout << "Error!!!";
			std::exit(1);
		}
		sum += num;
		if (num1) {
			min = num;
			max = num;
			num1 = false;
		}
		else {
			if (num < min) min = num;
			if (num > max) max = num;
		}
	}
	double ave = sum / n;
	std::cout << "Arithmetic mean = " << ave << std::endl;
	std::cout << "Minimum value = " << min << std::endl;
	std::cout << "Maximum value = " << max << std::endl;
	return 0;
}