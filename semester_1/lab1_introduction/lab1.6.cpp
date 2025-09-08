#include<iostream>
using namespace std;
int main() {
	setlocale(0, "");
	int n;
	cout << "Введите число n: ";
	cin >> n;
	if (n < 1) {
		cout << "Число n должно быть >= 1!!!" << endl;
		return 1;
	}
		int sum = 0;
		for (int i = 0; i <= n; i++) {
			if (i % 2 == 1) {
				sum += i;
			}
		}
		cout << "Сумма всех нечётных чисел: " << sum;
	return 0;
}
