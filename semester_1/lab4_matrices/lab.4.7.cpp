#include <iostream>
#include <iomanip>
void SpiralMatrix(int matrix[][100], int n) {
  int i = 0, j = -1, c = 0;
    while (c < n*n) {
        while (j < n - 1 && !matrix[i][j+1])
            matrix[i][++j] = ++c;    
        while (i < n - 1 && !matrix[i+1][j])
            matrix[++i][j] = ++c;    
        while (j > 0 && !matrix[i][j-1])
            matrix[i][--j] = ++c;    
        while (i > 0 && !matrix[i-1][j])
            matrix[--i][j] = ++c;    
    }
}
int SumNum(int matrix[][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            if (i + j == n - 1) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}
void PrintMatrix(int matrix[][100], int n) {
     for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++){
            std::cout << std::setw(4) << matrix[i][j]; 
        }
        std::cout << "\n";
    }  
}
int main() {
  int n;
  int matrix[100][100] = {0};
  std::cout << "Enter size of matrix: ";
  std::cin >> n;
  
    SpiralMatrix(matrix, n);
    std::cout << "Matrix: " << "\n";
   PrintMatrix(matrix, n);
   std::cout << "Sum of the elements of the secondary diagonal: " << SumNum(matrix, n);
    return 0;
}