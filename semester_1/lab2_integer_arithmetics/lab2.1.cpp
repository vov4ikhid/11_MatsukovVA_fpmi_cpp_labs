#include<iostream>
int main() {
	int n;
	std::cout << "Enter natural integer: ";
	if (!(std::cin >> n)) {
		std::cout << "Error!!!" << std::endl;
		std::exit(1);
	}
	if (n <= 0) {
		std::cout << "n must be natural" << std::endl;
		std::exit(1);
	}
	int min_dig = 9; // находим минимальную цифру
	for (int i = n; i > 0; i /= 10) { 
		int dig1 = i % 10;
		if (dig1 < min_dig) { 
			min_dig = dig1; 
		}
	}
	int res = 0; // выводим новое число 
	int power = 1;
	for (int i = n; i > 0; i /= 10) { 
		int dig2 = i % 10; 
		if (dig2 != min_dig) { 
			res += dig2 * power; 
			power *= 10; 
		}
	}
	std::cout << res;
	return 0;
}