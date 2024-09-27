#include <iostream>
using namespace std;

bool isPrime[10001];

void prime(int n) {
	for (int i = 0; i <= n; i++) {
		isPrime[i] = true;
	}

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	prime(10000);

	int t; cin >> t;
	while (t--) {
		int x; cin >> x;

		for (int i = x / 2; i >= 2; i--) {
			if (isPrime[i] && isPrime[x - i]) {
				cout << i << " " << x - i << endl;
				break;
			}
		}
	}
	return 0;
}