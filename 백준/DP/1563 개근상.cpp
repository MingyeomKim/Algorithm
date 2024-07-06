#include <iostream>
using namespace std;
#define MOD 1000000

int dp[2][3][1001];  // 지각일 / 연속 결석일 / 총 출결일수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	dp[0][0][1] = 1;
	dp[1][0][1] = 1;
	dp[0][1][1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[0][0][i] = dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1];
		dp[0][1][i] = dp[0][0][i - 1];
		dp[0][2][i] = dp[0][1][i - 1];
		dp[1][0][i] = dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1] + dp[1][0][i - 1] + dp[1][1][i - 1] + dp[1][2][i - 1];
		dp[1][1][i] = dp[1][0][i - 1];
		dp[1][2][i] = dp[1][1][i - 1];

		for (int l = 0; l < 2; l++) {
			for (int a = 0; a < 3; a++) {
				dp[l][a][i] %= MOD;
			}
		}
	}

	cout << (dp[0][0][n] + dp[0][1][n] + dp[0][2][n] + dp[1][0][n] + dp[1][1][n] + dp[1][2][n]) % MOD << endl;
	return 0;
}