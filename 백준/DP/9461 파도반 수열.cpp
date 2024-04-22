#include <iostream>
using namespace std;

long long dp[101] = { 1, 1, 1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;

	for (int i = 3; i <= 100; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	while (t--) {
		int n; cin >> n;
		cout << dp[n - 1] << endl;
	}
	return 0;
}