#include <iostream>
#include <cstring>
using namespace std;

int dp[100001];
int card[100001];

int compute(int start, int end) {
	int result = card[start];
	for (int right = start + 1; right <= end; right++) {
		result = result ^ card[right];
	}

	int cnt = 0;
	while (result != 0) {
		if (result % 2 == 1) {
			cnt++;
		}
		result /= 2;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 2; i <= n; i++) {
		if (i == n - 1) {
			dp[i] = 0;
			continue;
		}
		if (dp[i - 2] != -1) {
			dp[i] = dp[i - 2] + compute(i - 1, i);
		}
		if (i >= 3 && dp[i - 3] != -1) {
			dp[i] = max(dp[i], dp[i - 3] + compute(i - 2, i));
		}
	}

	cout << dp[n] << endl;
	return 0;
}