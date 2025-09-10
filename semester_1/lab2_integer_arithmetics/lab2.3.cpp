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
	int min_dig = 9;
	for (int i = n; i > 0; i /= 10) { // ���� ����������� ����� �������� �� 0
		int dig = i % 10;
		if ((dig != 0) && (dig < min_dig)) {
			min_dig = dig;
		}
	}
	int res_r = n * 10 + min_dig; // ��������� ����� ������ 
	
	
	int power_l = 1;

	for (int i = res_r; i > 0; i /= 10) { // ��������� ����� �����
		power_l *= 10;
	}
	int res = 0; // ������� ����� �����
	res = power_l * min_dig + res_r;
	std::cout << res;
			return 0;
	}