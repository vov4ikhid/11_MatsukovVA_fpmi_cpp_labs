#include <iostream>
int task_1(int** matrix, int n) {
	int sum = 0;
	for (int j = 0; j < n; j++) {
		bool hasZero = false;
		for (int i = 0; i < n; i++) {
			if (matrix[i][j] == 0) {
				hasZero = true;
				break;
			}
		}
		if (!hasZero) {
			for (int i = 0; i < n; i++) {
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}
int task_2(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = matrix[n - i][j];
			return matrix[i][j];
		}
	}
}
int main() {
	int n;
	std::cin >> n;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> matrix[i][j];
		}
	}
	std::cout << "Matrix:" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	int res1 = task_1(matrix, n), res2 = task_2(matrix, n);
	std::cout << "1. The sum of the elements in those columns that do not contain zeros: " << res1 << "\n";
	std::cout << "2. Swap the 1st and last lines, the 2nd and the second to last, etc." << res2 << "\n";
	return 0;
}