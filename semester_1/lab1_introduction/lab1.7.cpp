#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");
	int n;
	cout << "Введите число n: ";
	cin >> n;
	if (n < 1) {
		cout << "Число n должно быть >= 1" << endl;
		return 1;
	}
	double num;
	double min, max;
	double sum = 0;
	bool num1 = true;
	
	for (int i = 1; i <= n; i++) {
		cout << "Введите число " << i << ": ";
	cin >> num;
	sum += num;
	if (num1) {
		min = num;
		max = num;
		num1 = false;
	}
	else {
		if (num < min) min = num;
		if (num > max) max = num;
	}
}
	double ave = sum/n;
	cout << "Среднее арифмитическое = " << ave << endl;
	cout << "Минимальное значение = " << min << endl;
	cout << "Максимальное значение = " << max << endl;
	return 0;
}
