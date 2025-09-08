#include <iostream>

using namespace std;

int main() {
    int n, m;
    setlocale(0, "");
    cout << "������� ����������� ����� n: ";
    cin >> n;
    cout << "������� ����������� ����� m: ";
    cin >> m;
    if (n <= 0 || m <= 0) {
        cout << "����� ������ ���� ������������" << endl;
        return 1;
    }

    int min = n;
    if (m < n) {
        min = m;
    }

    cout << "����� �������� ����� " << n << " � " << m << ":" << endl;

    for (int i = 1; i <= min; i++) {
        if (n % i == 0 && m % i == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}