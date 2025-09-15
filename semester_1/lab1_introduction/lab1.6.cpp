}#include<iostream>

int main() {
	setlocale(0, "");
	int n;
	std::cout << "Enter number n: ";
	if (!(std::cin >> n)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	if (n < 1) {
		std::cout << "Number n must be >= 1!!!" << std::endl;
		std::exit(1);
	}
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		if (i % 2 == 1) {
			sum += i;
		}
	}
	std::cout << "The sum of all odd numbers: " << sum;
	return 0;
}