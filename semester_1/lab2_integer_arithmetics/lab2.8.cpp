#include <iostream>
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
		std::cout << "a and b must be natural!!!";
		std::exit(1);
	}
	if (a > b) {
		std::cout << "a muust be <= b";
		std::exit(1);
	}
	if (a == 1) {
		a = 2;
	}
	std::cout << "Prime numbers on the segment [" << a << "; " << b << "]:" << std::endl;

	for (int i = a; i <= b; i++) {
		bool pr = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				pr = false;
				break;
			}
		}
		if (pr) {
			std::cout << i << std::endl;
		}
	}
	return 0;
}