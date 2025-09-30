#include <iostream>
#include <vector>
#include <cmath>
int main() {
	int n;
	std::cout << "Enter the number of array elements: ";
	if (!(std::cin >> n)) {
		std::cout << "Error entering a number";
		std::exit(1);
	}
	std::vector <double> a(n);
	std::cout << "Enter " << n << " real numbers: " << "\n";
	for (int i = 0; i < n; i++) {
		if (!(std::cin >> a[i])) {
			std::cout << "Error entering a number";
			std::exit(1);
		}
	}
	double P;
	std::cout << "Enter P: ";
	if (!(std::cin >> P)) {
		std::cout << "Error entering a number";
		std::exit(1);
	}
	int count_after_P = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > P) {
			count_after_P++;
		}
	}
	std::cout << "Count of elements larger than " << P << ": " << count_after_P << "\n";
	int index_max = 0;
	double max_abs = abs(a[0]), product = 1.0;
	for (int i = 1; i < n; i++) {
		if (abs(a[i]) >= max_abs) {
			max_abs = abs(a[i]);
			index_max = i;
		}
	}
	if (index_max == n - 1) {
		std::cout << "There are no elements after the maximum element by modulus!" << "\n";
	}
	else {
		for (int i = index_max + 1; i < n; i++) {
			product *= a[i];
		}
		std::cout << "Product of elements after the maximum in absolute value: " << product << "\n";
	}
	std::vector <double> new_a;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			new_a.push_back(a[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			new_a.push_back(a[i]);
		}
	}
	std::cout << "New array: " << "\n";
	for (int i = 0; i < n; i++) {
		std::cout << new_a[i] << "\n";
	}
	return 0;
}