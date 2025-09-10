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
	for (int num = 2; num <= n; num++) { // ��������� ������ ����� �� �������������, ������� � 2 (�.�. 1 �� ����� ���� �����������) � �� ���������� n
		int sum = 0;
		for (int d = 1; d <= num/2; d++) { // ������� �������� ����� (�������� ����� ��� ������������ ��������, �� ������ ��� ������)
			if (num % d == 0) {
				sum += d;
			}
		}
		if (num == sum) { // ��������� ����� �� ����� ����� ����� ���������
			std::cout << num << std::endl;
		}
	}
	return 0;
}