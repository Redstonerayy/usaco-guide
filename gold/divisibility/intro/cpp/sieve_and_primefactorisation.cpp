#include <iostream>

using namespace std;

// sieve of erasthones to find prime factors
// this array will contain a prime number which divides
// the index i of the array position
const int MAX_N = 1e6;
// max_div[i] contains the largest prime that goes into i
int max_div[MAX_N + 1];

int main() {
	for (int i = 2; i <= MAX_N; i++) {
		if (max_div[i] == 0) {
			for (int j = i; j <= MAX_N; j += i) { max_div[j] = i; }
		}
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int div_num = 1;
		while (x != 1) {
			/*
			 * get the largest prime that can divide x and see
			 * how many times it goes into x (stored in count)
			 */
			int prime = max_div[x];
			int count = 0;
			while (x % prime == 0) {
				count++;
				x /= prime;
			}
			div_num *= count + 1;
		}
		cout << div_num << '\n';
	}
}
