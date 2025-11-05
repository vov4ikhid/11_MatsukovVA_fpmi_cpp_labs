#include <iostream>
#include <cmath>
int task_1(double* a, int n, double P) {
    int count_after_P = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > P) {
            count_after_P++;
        }
    }
    return count_after_P;
}
double task_2(double* a, int n) {
   int index_max = 0;
    double max_abs = std::abs(a[0]);

    for (int i = 1; i < n; i++) {
        if (std::abs(a[i]) > max_abs) {
            max_abs = std::abs(a[i]);
            index_max = i;
        }
    }

    if (index_max == n - 1) {
        
        return 0.0;
    }
    else {
        double product = 1.0;
        for (int i = index_max + 1; i < n; i++) {
            product *= a[i];
        }
        return product;
    }
}
void task_3(double* a, int n) {
  int index_of_negatives = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            double temp = a[i];
            a[i] = a[index_of_negatives];
            a[index_of_negatives] = temp;
            index_of_negatives++;
        }
    }
}
int main() {
    const int MAX_SIZE = 1000;
    double a[MAX_SIZE];
    int n;

    std::cout << "Enter the number of array elements(max = 1000): ";
    if (!(std::cin >> n) || n <= 0 || n > MAX_SIZE) {
        std::cout << "Error entering a number";
        std::exit(1);
    }

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
    std::cout << "Count of elements larger than " << P << ": " << task_1(a, n, P) << "\n";
      if (task_2(a, n) != 0.0) {
         std::cout << "Product of elements after the maximum in absolute value: " << task_2(a, n) << "\n";
      }
      else {
        std::cout << "There are no elements after the maximum element by modulus!" << "\n";
      }
     task_3(a, n);
     
    std::cout << "New array: " << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << "\n";
    }

    return 0;
}