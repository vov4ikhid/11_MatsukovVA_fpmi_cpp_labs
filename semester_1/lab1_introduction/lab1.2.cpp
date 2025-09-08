#include <iostream>
#include <locale> // Добавляем заголовочный файл для setlocale

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); // Правильное использование setlocale
    int n;
    cout << "Введите число n: ";
    cin >> n;
    int sum = 0;
    long long work = 1;
    
    if (n < 1) {
        cout << "n должно быть >= 1" << endl;
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            work *= i;
        }
        else {
            sum += i;
        }
    }

    cout << "Сумма всех нечетных чисел равна: " << sum << endl;
    cout << "Произведение всех четных чисел равно: " << work << endl;

    return 0;
}
