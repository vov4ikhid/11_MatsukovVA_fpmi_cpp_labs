#include<iostream>

int main() {
	setlocale(0, "");
	int num;
	std::cout << "Enter a six digit number: ";
	if (!(std::cin >> num)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	if (num < 100000 || num > 999999) {
		std::cout << "The number is not six digits!!!";
		std::exit(1);
	}
	int dig1 = num / 100000;
	int dig2 = (num / 10000) % 10;
	int dig3 = (num / 1000) % 10;
	int dig4 = (num / 100) % 10;
	int dig5 = (num / 10) % 10;
	int dig6 = num % 10;
	if (dig1 + dig2 + dig3 == dig4 + dig5 + dig6) {
		std::cout << "Number " << num << "- happy" << std::endl;
	}
	else {
		std::cout << "Number " << num << "- not happy" << std::endl;
	}
	return 0;
}