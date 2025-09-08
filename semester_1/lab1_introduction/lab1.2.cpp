#include <iostream>

using namespace std;

int main() {
	setlocale(0, "");
	int n;
	cout << "Ââåäèòå ÷èñëî n: ";
	cin >> n;
	int sum = 0;
	long long work = 1;
	if (n < 1) {
		cout << "n äîëæíî áûòü >= 1" << endl;
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
	cout << "Ñóììà âñåõ íå÷¸òíûõ ÷èñåë ðàâíà: " << sum << endl;
	cout << "Ïðîèçâåäåíèå âñåõ ÷¸òíûõ ÷èñåë ðàâíî: " << work << endl;

	return 0;

}
