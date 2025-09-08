#include<iostream>
using namespace std;
int main() {
	setlocale(0, "");
	const int n = 10;
		double num[n]; 
		int q = 0; // переменная количества
		
		
		for (int i = 1; i <= n; i++) {
			cout << "Введите число " << i << " : ";
			cin >> num[i];
		}
		// проверка первого числа 
		if (num[0] < num[1]) {
			q++; 
		}
		// проверка остальных чисел
		for (int i = 2; i <= n - 1; i++) {
			if (num[i] < num[i + 1] && num[i] < num[i - 1]) {
				q++;
			}
		}
		// проверка последнего числа
		if (num[n - 2] > num[n - 1]) {
			q++; 
		}
		cout << "Количесво чисел, которые меньше своих соседей: " << q << endl;
	return 0;
}