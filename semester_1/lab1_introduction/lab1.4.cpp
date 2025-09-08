#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");
	int k;
	long long k1 = 1;
	long long k2 = 1;
	cout << "Введите число k: ";
	cin >> k;
	if (k < 1) {
		cout << "Число k должно быть >= 1" << endl;
		return 1;
	}
	if (k % 2 == 0) {
		
		for (int i = 2; i <= k; i += 2)
		{
			k1 *= i;
		}
		k = k1;
	}
	else {
		
		for (int i = 1; i <= k; i += 2)
		{
			k2 *= i;
		}
		k = k2;
	}
	cout << "Двойной факториал k = " << k << endl;

	return 0;
}
