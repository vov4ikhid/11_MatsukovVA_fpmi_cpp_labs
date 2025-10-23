#include <iostream>
#include <iomanip>
#include <random>
bool asc(int a, int b) {
    return a < b;
}
bool desc(int a, int b) {
    return a > b;
}
void BubbleSort(int** matrix, int n, int m, bool (*comp)(int, int)) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 1; j++) {
        for (int k = 0; k < m - j - 1; k++) {
            if (comp(matrix[i][k + 1], matrix[i][k])) {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[i][k + 1];
                matrix[i][k + 1] = temp;
            }
        }
      }
    }
}
void SelectionSort(int** matrix, int n, int m, bool (*comp)(int, int)) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            int minIndex = j;
            for (int k = j + 1; k < m; k++) {
                if (comp(matrix[i][k], matrix[i][minIndex])) {
                    minIndex = k;
                }
            }
            if (minIndex != j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][minIndex];
                matrix[i][minIndex] = temp;
            }
        }
    }
}
void InsertionSort(int** matrix, int n, int m, bool (*comp)(int, int)) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int key = matrix[i][j];
            int k = j - 1;
            while (k >= 0 && comp(key, matrix[i][k])) {
                matrix[i][k + 1] = matrix[i][k];
                k--;
            }
            matrix[i][k + 1] = key;
        }
    }
}

int main() {
    int n, m;
    std::mt19937 gen(128731);
	std::uniform_int_distribution<int> dist(-10, 30);
    std::cout << "Enter the dimensions of the N x M matrix: ";
    std::cin >> n >> m;
    int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = dist(gen);
        }
    }
    std::cout << "Original matrix:" << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "How do you want to sort the matrix?" << "\n";
    std::cout << "1. Bubble sort" << "\n" << "2. Selection sort" << "\n" << "3. Insertion sort" << "\n";
    int s;
    std::cout << "Select sorting method(enter number of sort): ";
    std::cin >> s;
    std::cout << "1. Sort in ascending order" << "\n" << "2. Sort in descending order" << "\n";
    int t;
    std::cout << "Select sorting type(enter number of type): ";
    std::cin >> t;
    
    if (t == 1) {
       if (s == 1) {
          BubbleSort(matrix, n, m, asc);
       }
       else if (s == 2) {
          SelectionSort(matrix, n, m, asc);
       }
       else if (s == 3) {
          InsertionSort(matrix, n, m, asc);
       }
        else { 
          std::cout << "Error!!!";
        std::exit(1);
       }
    }
    else if (t == 2) {
        if (s == 1) {
          BubbleSort(matrix, n, m, desc);
       }
       else if (s == 2) {
          SelectionSort(matrix, n, m, desc);
       }
       else if (s == 3) {
          InsertionSort(matrix, n, m, desc);
       }
        else { 
          std::cout << "Error!!!";
        std::exit(1);
       }
    }
    else {
        std::cout << "Error!!!";
        std::exit(1);
    }
    std::cout << "Sorted matrix:" << "\n";
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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