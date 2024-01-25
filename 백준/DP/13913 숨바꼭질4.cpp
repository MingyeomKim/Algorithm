#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int dp[100001];
int n, k;

void compare(int& next, int current) {
	if (next == -1 || next > current + 1) {
		next = current + 1;
	}
}

int main() {
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	dp[n] = 0;
	for (int i = 0; i <= abs(n - k); i++) {
		int current = i + n;
		compare(dp[current + 1], dp[current]);
		compare(dp[current - 1], dp[current]);
		compare(dp[2 * current], dp[current]);
	}

	cout << dp[k] << endl;
	return 0;
}