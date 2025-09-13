#include<iostream>

int main() {
	setlocale(0, "");
	int n1[] = { 5, 6, 10, 100, 200, 500, 1000 };
	long long s = 0;
	std::cout << "s = 1^1 + 2^2 + ... + n^n" << std::endl;
	for (int k = 0; k < 7; k++) {
		int n = n1[k];
		for (int i = 1; i <= n; i++) {
			long long power = 1;
			for (int j = 1; j <= i; j++) {
				power *= i;
			}
			s += power;
		}
		std::cout << "s = " << s << ", if n = " << n << std::endl;
	}
	// такие ответы для большик чисел получаютя, потому что даже диапазон long long не выдерживает такие больжи значения
	return 0;
}