#include<iostream>

int main() {
	int n;
	std::cout << "Enter natural integer n: ";
	if (!(std::cin >> n)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	if (n <= 0) {
		std::cout << "n must be natural!!!";
		std::exit(1);
	}
	for (int num = 2; num <= n; num++) { // проверяем каждое число на совершенность, начиная с 2 (т.к. 1 не может быть совершенным) и не привосходя n
		int sum = 0;
		for (int d = 1; d <= num/2; d++) { // находим делители числа (половина числа это максимальный делитель, не считая его самого)
			if (num % d == 0) {
				sum += d;
			}
		}
		if (num == sum) { // проверяем равно ли число сумме своих делителей
			std::cout << num << std::endl;
		}
	}
	return 0;
}