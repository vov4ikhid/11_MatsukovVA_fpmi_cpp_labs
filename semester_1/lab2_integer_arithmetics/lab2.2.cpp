#include<iostream>
int main() {
	long long n;
	std::cout << "Enter natural integer n: ";
	if (!(std::cin >> n)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	if (n <= 0) {
		std::cout << "n must be natural!!!";
			std::exit(1);
	}
	int res = 0;
	int power = 1;
	for (int i = n; i > 0; i /= 10) { // берём каждую цифру и считаем её количество 
		int dig1 = i % 10;

		int count = 0;
		for (int j = n; j > 0; j /= 10) {
			int dig2 = j % 10;
			if (dig2 == dig1) {
				count++;
			}
		}
		if (count % 2 != 0) { // выводим новое число
			res += dig1 * power;
			power *= 10;
		}
	}
	std::cout << res;
	return 0;
}