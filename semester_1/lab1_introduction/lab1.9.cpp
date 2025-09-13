#include<iostream>

int main() {
	setlocale(0, "");
	int num;
	std::cout << "Enter a four digit number: ";
	if (!(std::cin >> num)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	if (num < 1000 || num > 9999) {
		std::cout << "This number is not four digits.!!!";
		std::exit(1);
	}
	int dig1 = num / 1000;
	int dig2 = (num / 100) % 10;
	int dig3 = (num / 10) % 10;
	int dig4 = num % 10;
	if (dig1 == dig4 && dig2 == dig3) {
		std::cout << "Number " << num << "- palindrome" << std::endl;
	}
	else {
		std::cout << "Number " << num << "- not palindrome" << std::endl;
	}
	return 0;
}