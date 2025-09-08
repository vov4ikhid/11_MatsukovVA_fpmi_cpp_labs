#include<iostream>
using namespace std;
int main() {
	setlocale(0, "");
	int num;
	cout << "Введите шестизначное число: ";
	cin >> num;
	if (num < 100000 || num > 999999) {
		cout << "Число не является шестизначным!!!";
		return 1;
	}
	int dig1 = num / 100000;
	int dig2 = (num / 10000) % 10;
	int dig3 = (num / 1000) % 10;
	int dig4 = (num / 100) % 10;
	int dig5 = (num / 10) % 10;
	int dig6 = num % 10;
	if (dig1 + dig2 + dig3 == dig4 + dig5 + dig6) {
		cout << "Число " << num << "- счастливое" << endl;
	}
	else {
		cout << "Число " << num << "- не счастливое" << endl;
	}
	return 0;
}
