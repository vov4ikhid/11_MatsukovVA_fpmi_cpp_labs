#include<iostream>
using namespace std;
int main() {
	setlocale(0, "");
	int num;
	cout << "������� ������������� �����: ";
	cin >> num;
		if (num < 1000 || num > 9999) {
			cout << "��� ����� �� �������������!!!";
				return 1;
		}
		int dig1 = num / 1000;
		int dig2 = (num / 100) % 10;
		int dig3 = (num / 10) % 10;
		int dig4 = num % 10;
		if (dig1 == dig4 && dig2 == dig3) {
			cout << "����� " << num << "- ���������" << endl;
		}
		else {
			cout << "����� " << num << "- �� ���������" << endl;
		}
	return 0;
}