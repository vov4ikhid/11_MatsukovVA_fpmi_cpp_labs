#include<iostream>
using namespace std;
int main() {
	setlocale(0, "");
	const int n = 10;
		double num[n]; 
		int q = 0; // ���������� ����������
		
		
		for (int i = 1; i <= n; i++) {
			cout << "������� ����� " << i << " : ";
			cin >> num[i];
		}
		// �������� ������� ����� 
		if (num[0] < num[1]) {
			q++; 
		}
		// �������� ��������� �����
		for (int i = 2; i <= n - 1; i++) {
			if (num[i] < num[i + 1] && num[i] < num[i - 1]) {
				q++;
			}
		}
		// �������� ���������� �����
		if (num[n - 2] > num[n - 1]) {
			q++; 
		}
		cout << "��������� �����, ������� ������ ����� �������: " << q << endl;
	return 0;
}