#include<iostream>
#include<cmath>
int main() {
	int a, b;
	std::cout << "Enter number a: ";
	if (!(std::cin >> a)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	std::cout << "Enter number b: ";
	if (!(std::cin >> b)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	if ((a < 0) || (b < 0)) {
		std::cout << "a and b must be >= 0";
		std::exit(1);
	}
	if (a >= b) {
		std::cout << "a must be < b!!!";
		std::exit(1);
	}
	for (int i = a; i <= b; i++) {
		int count = 0;
		for (int j = i; j > 0; j /= 10) {
			count++;
		}
		long sum = 0;
		for (int j = i; j > 0; j /= 10) {
			int dig = j % 10;
			sum += pow(dig, count);


		}
		if ((i == sum) && (i >= 10)) {
			std::cout << i << std::endl;
		}
	}
	return 0;
}