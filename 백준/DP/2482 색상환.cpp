#include <iostream>
using namespace std;

#define MOD 1000000003

int dp[1001][1001];

int main() {
	int n, k; cin >> n >> k;

	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int index = 2; index <= n; index++) {
		for (int selected = 2; selected <= k; selected++) {
			dp[index][selected] = (dp[index - 1][selected] + dp[index - 2][selected - 1]) % MOD;
		}
	}
	cout << (dp[n - 1][k] + dp[n - 3][k - 1]) % MOD << endl;
	return 0;
}