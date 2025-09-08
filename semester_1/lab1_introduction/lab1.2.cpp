#include <iostream>

using namespace std;

int main() {
	setlocale(0, "");
	int n;
	cout << "Введите число n: ";
	cin >> n;
	int sum = 0;
	long long work = 1;
	if (n < 1) {
		cout << "n должно быть >= 1" << endl;
		return 1;
	}
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			work *= i;
		}
		else {
			sum += i;
		}
	}
	cout << "Сумма всех нечётных чисел равна: " << sum << endl;
	cout << "Произведение всех чётных чисел равно: " << work << endl;

	return 0;
}

