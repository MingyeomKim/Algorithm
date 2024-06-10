#include <iostream>
#include <cstring>
using namespace std;

#define MAX 123456
bool isPrime[MAX * 2 + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= MAX * 2; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= MAX * 2; j += i) {
				isPrime[j] = false;
			}
		}
	}
	while (true) {
		int n; cin >> n;
		if (n == 0) {
			break;
		}
		int ret = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isPrime[i]) {
				ret++;
			}
		}
		cout << ret << endl;
	}
	return 0;

}