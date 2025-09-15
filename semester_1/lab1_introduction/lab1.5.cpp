#include <iostream>

int main() {
    int n, m;
    setlocale(0, "");
    std::cout << "Enter natural number n: ";
    if (!(std::cin >> n)) {
        std::cout << "Error!!!";
        std::exit(1);
    }
    std::cout << "Enter natural number m: ";
    if (!(std::cin >> m)) {
        std::cout << "Error!!!";
        std::exit(1);
    }
<<<<<<< HEAD
=======
    if (n <= 0 || m <= 0) {
        std::cout << "NUMBERS MUST BE NATURAL!!!" << std::endl;
        std::exit(1);
    }

    int min = n;
    if (m < n) {
        min = m;
    }

    std::cout << "Common divisors of numbers " << n << " and " << m << ":" << std::endl;

    for (int i = 1; i <= min; i++) {
        if (n % i == 0 && m % i == 0) {
            std::cout << i << std::endl;
        }
    }

    std::cout << std::endl;

    return 0;
}
    cout << "Введите натуральное число n: ";
    cin >> n;
    cout << "Введите натуральное число m: ";
    cin >> m;
>>>>>>> b6eaac0f0e25e39c6c4405a4eae582a9979a6217
    if (n <= 0 || m <= 0) {
        std::cout << "NUMBERS MUST BE NATURAL!!!" << std::endl;
        std::exit(1);
    }

    int min = n;
    if (m < n) {
        min = m;
    }

    std::cout << "Common divisors of numbers " << n << " and " << m << ":" << std::endl;

    for (int i = 1; i <= min; i++) {
        if (n % i == 0 && m % i == 0) {
            std::cout << i << std::endl;
        }
    }

    std::cout << std::endl;

    return 0;
<<<<<<< HEAD
}
=======
}

>>>>>>> b6eaac0f0e25e39c6c4405a4eae582a9979a6217
