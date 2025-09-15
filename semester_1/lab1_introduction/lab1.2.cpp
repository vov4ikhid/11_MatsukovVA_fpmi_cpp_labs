#include <iostream>

int main() {
	setlocale(0, "");
	int n;
	std::cout << "Enter number n: ";
	if (!(std::cin >> n)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	int sum = 0;
	long long work = 1;
	if (n < 1) {
		std::cout << "n must be >= 1" << std::endl;
		std::exit(1);
	}
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			work *= i;
		}
		else {
			sum += i;
		}
	}
	std::cout << "The sum of all odd numbers is: " << sum << std::endl;
	std::cout << "The product of all even numbers is equal to: " << work << std::endl;

	return 0;

}
