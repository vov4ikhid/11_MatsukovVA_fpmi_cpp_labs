#include<iostream>

int main() {
	int n;
	std::cout << "Enter natural integer n: ";
	if (!(std::cin >> n)) {
		std::cout << "Error!!!";
		std::exit(1);
	}
	if (n <= 0) {
		std::cout << "n must be natural!!!";
		std::exit(1);
	}
	for (int i = 1; i <= n; i++) {
		int rev_i = 0;
		for (int j = i; j > 0; j /= 10) {
			rev_i = rev_i * 10 + j % 10;
		}
		if (i == rev_i) {
			long sq = i * i;
			long rev_sq = 0;
			for (long j_sq = sq; j_sq > 0; j_sq /= 10) {
				rev_sq = rev_sq * 10 + j_sq % 10;
			}
			if (sq == rev_sq) {
				std::cout << i << " - (" << i << "^2 = " << sq << ")" << std::endl;
			}
		}
	}
	return 0;
}