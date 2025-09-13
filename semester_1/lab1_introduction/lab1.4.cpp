#include <iostream>

int main() {
	setlocale(0, "");
	int k;
	long long k1 = 1;
	long long k2 = 1;
	std::cout << "Enter number k: ";
	if (!(std::cin >> k)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	if (k < 1) {
		std::cout << "Number k must be >= 1" << std::endl;
		std::exit(1);
	}
	if (k % 2 == 0) {

		for (int i = 2; i <= k; i += 2)
		{
			k1 *= i;
		}
		k = k1;
	}
	else {

		for (int i = 1; i <= k; i += 2)
		{
			k2 *= i;
		}
		k = k2;
	}
	std::cout << "Double factorial k = " << k << std::endl;

	return 0;
}