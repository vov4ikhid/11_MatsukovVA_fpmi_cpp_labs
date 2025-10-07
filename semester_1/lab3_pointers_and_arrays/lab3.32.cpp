#include <iostream>

int main() {
    int n;

    
    std::cout << "Enter the number of array elements: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Error!";
        std::exit(1);
    }
  
    int* a = new int[n];

    std::cout << "Enter " << n << " real numbers: " << "\n";
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> a[i])) {
            std::cout << "Error!";
            std::exit(1);
        }
    }

    int change_of_sign = 0;
    for (int i = 0; i < n - 1; i++) {
        bool current = (a[i] >= 0);
        bool next = (a[i + 1] >= 0);
        if (current!= next) {
            change_of_sign++;
        }
    }
    std::cout << "Amount of changes signes: " << change_of_sign << "\n";

    int first_0 = -1, second_0 = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            first_0 = i;
            break;
        }
    }

    if (first_0 != -1) {
        for (int i = first_0 + 1; i < n; i++) {
            if (a[i] == 0) {
                second_0 = i;
                break;
            }
        }
    }

    if (first_0 != -1 && second_0 != -1 && second_0 - first_0 > 1) {
        long product = 1;
        for (int i = first_0 + 1; i < second_0; i++) {
            product *= a[i];
        }
        std::cout << "Product between zeros: " << product << "\n";
    }
    else {
        std::cout << "No two null elements were found, or there were no elements between them." << "\n";
    }

    int N;
    std::cout << "Enter number N: ";
    if (!(std::cin >> N)) {
        std::cout << "Error!";
        std::exit(1);
    }

    int cur_pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % N == 0) {
            if (i != cur_pos) {
                int temp = a[i];
                for (int j = i; j > cur_pos; j--) {
                    a[j] = a[j - 1];
                }
                a[cur_pos] = temp;
            }
            cur_pos++;
        }
    }

    
    std::cout << "New array: ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

  
    delete[] a;

    return 0;
}