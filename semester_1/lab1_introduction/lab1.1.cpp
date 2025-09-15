#include <iostream>
int main() {
	int a, b, d;
	std::cout << "Enter a: ";
	if (!(std::cin >> a)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	std::cout << "Enter b: ";
	if (!(std::cin >> b)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	std::cout << "Enter d: ";
	if (!(std::cin >> d)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	if (a == b) {
		std::cout << "a and b must be different!!!";
		std::exit(1);
	}
	if (d == 0) {
		std::cout << "d must be integer!!!";
		std::exit(1);
	}
	if ((a < b && d < 0) || (a > b && d > 0)) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (a < b) {
		for (int i = a; i <= b; i += d) {
			if (i % 3 == 0) {
				std::cout << i << std::endl;
			}

		}
	}
	if (a > b) {
		for (int i = b; i <= a; i -= d) {
			if (i % 3 == 0) {
				std::cout << i << std::endl;
			}
		}
	}
}