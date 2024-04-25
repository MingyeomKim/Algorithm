#include <iostream>
using namespace std;

long long dp[101][10];
#define MOD 1000000000
int n;

int main() {
	cin >> n;

	for (int number = 1; number <= 9; number++) {
		dp[1][number] = 1;
	}

	for (int index = 2; index <= n; index++) {
		for (int number = 0; number <= 9; number++) {
			if (number == 0) {
				dp[index][number] = dp[index - 1][number + 1] % MOD;
			}
			else if (number == 9) {
				dp[index][number] = dp[index - 1][number - 1] % MOD;
			}
			else {
				dp[index][number] = (dp[index - 1][number + 1] + dp[index - 1][number - 1]) % MOD;
			}
		}
	}

	long long ret = 0;
	for (int number = 0; number <= 9; number++) {
		ret += dp[n][number];
	}
	cout << ret % MOD << endl;
	return 0;
}
