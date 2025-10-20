#include <iostream>
#include <iomanip>
#include <random>
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
void task_2(int** matrix, int n) {
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[n - i - 1][j];
			matrix[n - i - 1][j] = temp;
		}
	}
}
int main() {
	int n;
	std::mt19937 gen(128731);
	std::uniform_int_distribution<int> dist(-10, 10);
	std::cout << "Enter the matrix size: ";
	if (!(std::cin >> n)) {
		std::cout << "Enter a number!!!";
		std::exit(1);
	}
	if (n <= 0) {
		std::cout << "n must be > 0";
		std::exit(1);
	}
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	std::cout << "Enter the matrix elements: " << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
          matrix[i][j] = dist(gen);
		}
	}
	std::cout << "Matrix:" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(4) << matrix[i][j];
		}
		std::cout << "\n";
	}
	int res1 = task_1(matrix, n);
	std::cout << "1. The sum of the elements in those columns that do not contain zeros: " << res1 << "\n";
	task_2(matrix, n);
	std::cout << "2. Swap the 1st and last lines, the 2nd and the second to last, etc.:" << "\n";
    for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
       std::cout << std::setw(4) << matrix[i][j];
	   }
	   std::cout << "\n";
	}
	for (int i = 0; i < n; i++) {
      delete[] matrix[i];
	}
        delete[] matrix;
	return 0;
}