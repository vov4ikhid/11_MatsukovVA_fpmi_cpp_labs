#include <iostream>
#include <iomanip>
#include <random>
int task_1(int** matrix, int n, int m) {
    int sum = 0;
    for (int j = 0; j < m; ++j) {
        bool hasZero = false;
        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if(hasZero) {
            for (int i = 0; i < n; ++i) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}
void task_2(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
          for (int j = 0; j < m; ++j) {
            for (int k = 0; k < m - j - 1; k++) {
             if (matrix[i][k] > matrix[i][k + 1]) {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[i][k + 1];
                matrix[i][k + 1] = temp;
             }
            }
          }
        }
        else {
          for (int j = 0; j < m; ++j) {
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
}
void keyboard_method(int** matrix, int n, int m) {
   std::cout << "Enter matrix: " << "\n";
		for (int i = 0; i < n; ++i) {
		   for (int j = 0; j < m; ++j) {
             if (!(std::cin >> matrix[i][j])) {
              std::cout << "Error entering a number";
              std::exit(1);
             }
		   }
	    }
}
void random_method(int** matrix, int n, int m) {
	int a, b;
         std::cout << "Enter the interval boundaries[a, b]: ";
         if (!(std::cin >> a >> b)) {
         std::cout << "Error entering a number";
         std::exit(1);
         }
         if (a > b) {
            int temp = a;
            a = b;
            b = temp;
         }
        std::mt19937 gen(128731);
        std::uniform_int_distribution<int> dist(a, b);
        for (int i = 0; i < n; ++i) {
		   for (int j = 0; j < m; ++j) {
          matrix[i][j] = dist(gen);
		   }
	    }
}
void PrintMatrix(int** matrix, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << std::setw(4) << matrix[i][j];
		}
		std::cout << "\n";
	}
}
int main() {
   int n, m;
    std::cout << "Enter the dimensions of the N x M matrix: ";
  if (!(std::cin >> n >> m)) {
		std::cout << "Enter numbers!!!";
		std::exit(1);
	}
	if (n <= 0 || m <= 0) {
		std::cout << "n and m must be > 0";
		std::exit(1);
	}
   int** matrix = new int*[n];
   for (int i = 0; i < n; ++i) {
    matrix[i] = new int[m];
   } 
   int t;
       std::cout << "Choose the method for filling the array:" << "\n" << "1.from the keyboard" << "\n" << "2.random numbers" << "\n";
         std::cin >> t;
    switch (t) {
        case 1: {
         keyboard_method(matrix, n, m);
           break;
		}
         case 2: {
         random_method(matrix, n, m);
        break; 
	}
      default:
	  std::cout << "Error of method selection!!!\n";
	  for (int i = 0; i < n; ++i) {
      delete[] matrix[i];
    }
    delete[] matrix;
    std::exit(1);
	  break;
    }
   
std::cout << "Original matrix: " << "\n";
    PrintMatrix(matrix, n, m);
   std::cout << "1. The sum of the elements in the columns containing at least one zero: " << task_1(matrix, n, m) << "\n";
    task_2(matrix, n, m);

std::cout << "2. Sorted matrix: " << "\n";
PrintMatrix(matrix, n, m);
    for (int i = 0; i < n; ++i) {
    delete[] matrix[i];
   }
   delete[] matrix;
    return 0;
}