#include <iostream>

using namespace std;

int main() {
    int n, m;
    setlocale(0, "");
    cout << "Введите натуральное число n: ";
    cin >> n;
    cout << "Введите натуральное число m: ";
    cin >> m;
    if (n <= 0 || m <= 0) {
        cout << "ЧИСЛА ДОЛЖНЫ БЫТЬ НАТУРАЛЬНЫМИ" << endl;
        return 1;
    }

    int min = n;
    if (m < n) {
        min = m;
    }

    cout << "Общие делители чисел " << n << " и " << m << ":" << endl;

    for (int i = 1; i <= min; i++) {
        if (n % i == 0 && m % i == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}