#include <iostream>
#include <iomanip>
void CauchyMatrix(double** matrix, double* x, double* y, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 1.0 / (x[i] + y[j]);
        }
    }
}
double SumCol(double** matrix, int n, int m) {
 double sum = 0.0;
 for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        sum += matrix[i][j];
    }
 }
 return sum;
}
int main() {
   int n, m;
   std::cout << "Enter sizes of vectors X and Y: ";
   std::cin >> n >> m;
   double* x = new double[n];
   double* y = new double[m];
   std::cout << "Enter vector X elements: " << "\n";
   for (int i = 1; i <= n; i++) {
    std::cout << "x" << i << " = ";
    std::cin >> x[i];
   }
   std::cout << "Enter vector Y elements: " << "\n";
   for (int i = 1; i <= m; i++) {
    std::cout << "y" << i << " = ";
    std::cin >> y[i];
   }
   double** matrix = new double*[n];
   for (int i = 0; i < n; i++) {
    matrix[i] = new double[m]; 
   }
   CauchyMatrix(matrix, x, y, n, m);
   for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        std::cout << std::setw(10) << std::setprecision(4) << matrix[i][j];
    }
    std::cout << "\n";
   }
   std::cout << "Sum of the elements of the columns of a matrix: " << std::setprecision(6) << SumCol(matrix, n, m) << "\n";
   for (int i = 0; i < n; i++) {
    delete[] matrix[i];
   }
   delete[] matrix;
   delete[] x;
   delete[] y;
    return 0;
}