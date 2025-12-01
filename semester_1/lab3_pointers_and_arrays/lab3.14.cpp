#include <iostream>
#include <cmath>
#include <random>
int task_1(double* arr, int n, double P) {
    int count_after_P = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > P) {
            count_after_P++;
        }
    }
    return count_after_P;
}
double task_2(double* arr, int n) {
   int index_max = 0;
    double max_abs = std::abs(arr[0]);

    for (int i = 1; i < n; ++i) {
        if (std::abs(arr[i]) > max_abs) {
            max_abs = std::abs(arr[i]);
            index_max = i;
        }
    }

    if (index_max == n - 1) {
        throw "There are no elements after the maximum element by modulus!";
    }
    else {
        double product = 1.0;
        for (int i = index_max + 1; i < n; ++i) {
            product *= arr[i];
        }
        return product;
    }
}
void task_3(double* arr, int n) {
  int index_of_negatives = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            if (i != index_of_negatives) {
                double negative_value = arr[i];
                for (int j = i; j > index_of_negatives; --j) {
                    arr[j] = arr[j - 1];
                }
                arr[index_of_negatives] = negative_value;
            }
            index_of_negatives++;
        }
    }
}
int main() {
    const int MAX_SIZE = 1000;
    double arr[MAX_SIZE];
    int n;

    std::cout << "Enter the number of array elements(max = 1000): ";
    if (!(std::cin >> n) || n <= 0 || n > MAX_SIZE) {
        std::cout << "Error entering a number";
        std::exit(1);
    }
    int t;
    std::cout << "Choose the method for filling the array:" << "\n" << "1.from the keyboard" << "\n" << "2.random numbers" << "\n";
    std::cin >> t;
    switch (t) {
        case 1: 
         std::cout << "Enter " << n << " real numbers: " << "\n";
           for (int i = 0; i < n; ++i) {
             if (!(std::cin >> arr[i])) {
              std::cout << "Error entering a number";
              std::exit(1);
             }
           }
           break;
         case 2:
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
        arr[i] = dist(gen);     
        }
        break;
    }
       std::cout << "Original array: " << "\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    double P;
    std::cout << "\nEnter P: ";
    if (!(std::cin >> P)) {
        std::cout << "Error entering a number";
        std::exit(1);
    }
    std::cout << "Count of elements larger than " << P << ": " << task_1(arr, n, P) << "\n";
      try {
         std::cout << "Product of elements after the maximum in absolute value: " << task_2(arr, n) << "\n";
      }
      catch (const char* error_msg) {
        std::cout << error_msg << "\n";
      }
     task_3(arr, n);

    std::cout << "New array: " << "\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}