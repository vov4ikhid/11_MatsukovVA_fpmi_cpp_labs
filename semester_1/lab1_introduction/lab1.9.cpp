#include<iostream>
using namespace std;
int main() {
	setlocale(0, "");
	int num;
	cout << "Введите четырёхзначное число: ";
	cin >> num;
		if (num < 1000 || num > 9999) {
			cout << "Это число не четырёхзначное!!!";
				return 1;
		}
		int dig1 = num / 1000;
		int dig2 = (num / 100) % 10;
		int dig3 = (num / 10) % 10;
		int dig4 = num % 10;
		if (dig1 == dig4 && dig2 == dig3) {
			cout << "Число " << num << "- палиндром" << endl;
		}
		else {
			cout << "Число " << num << "- не палиндром" << endl;
		}
	return 0;
}
