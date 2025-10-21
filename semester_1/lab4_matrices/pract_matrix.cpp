#include <iostream>
#include <iomanip>
#include <random>
void BubbleSortAs(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 1; j++) {
        for (int k = 0; k < m - j - 1; k++) {
            if (matrix[i][k] > matrix[i][k + 1]) {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[i][k + 1];
                matrix[i][k + 1] = temp;
            }
        }
      }
    }
}
void BubbleSortDes(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 1; j++) {
        for (int k = 0; k < m - j - 1; k++) {
            if (matrix[i][k] < matrix[i][k + 1]) {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[i][k + 1];
                matrix[i][k + 1] = temp;
            }
        }
      }
    }
}
void SelectionSortAs(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            int minIndex = j;
            for (int k = j + 1; k < m; k++) {
                if (matrix[i][k] < matrix[i][minIndex]) {
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
void SelectionSortDes(int** matrix, int n, int m) {
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            int maxIndex = j;
            for (int k = j + 1; k < m; k++) {
                if (matrix[i][k] > matrix[i][maxIndex]) {
                    maxIndex = k;
                }
            }
            if (maxIndex != j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][maxIndex];
                matrix[i][maxIndex] = temp;
            }
        }
    }
}
void InsertionSortAs(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int key = matrix[i][j];
            int k = j - 1;
            while (k >= 0 && matrix[i][k] > key) {
                matrix[i][k + 1] = matrix[i][k];
                k--;
            }
            matrix[i][k + 1] = key;
        }
    }
}
void InsertionSortDes(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int key = matrix[i][j];
            int k = j - 1;
            while (k >= 0 && matrix[i][k] < key) {
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
    
    if (t = 1) {
       switch (s) {
        case 1:
          BubbleSortAs(matrix, n, m);
           break;
        case 2: 
          SelectionSortAs(matrix, n, m);
           break;
        case 3:
          InsertionSortAs(matrix, n, m);
           break;
        default: 
          std::cout << "Error!!!";
           break;
       }
    }
    else if (t = 2) {
        switch (s) {
        case 1:
          BubbleSortDes(matrix, n, m);
           break;
        case 2: 
          SelectionSortDes(matrix, n, m);
           break;
        case 3:
          InsertionSortDes(matrix, n, m);
           break;
        default: 
          std::cout << "Error!!!";
           break;
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