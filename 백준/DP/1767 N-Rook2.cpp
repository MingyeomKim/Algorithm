#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000001;
long long dp[101][101][101];
int N, M, K;

long long solve(int n, int m, int k) {
	if (k == 0) return 1;
	if (n <= 0 || m <= 0 || k < 0) return 0;

	long long& ret = dp[n][m][k];
	if (ret != -1) return ret;

	ret = solve(n - 1, m, k)
		+ solve(n - 1, m - 1, k - 1) * m
		+ solve(n - 1, m - 2, k - 2) * m * (m - 1) / 2
		+ solve(n - 2, m - 1, k - 2) * m * (n - 1);
	ret %= MOD;
	return ret;
}

int main() {
	cin >> N >> M >> K;
	memset(dp, -1, sizeof(dp));
	cout << solve(N, M, K) << endl;
	return 0;
}