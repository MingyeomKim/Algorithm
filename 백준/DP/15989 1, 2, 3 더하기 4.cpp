#include <iostream>
#include <cstring>
using namespace std;

int nums[3] = { 1, 2, 3 };
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		int n; cin >> n;
		dp[0] = 1;
		for (int j = 0; j < 3; j++) {
			for (int i = 1; i <= n; i++)
				if (i - nums[j] >= 0)
					dp[i] += dp[i - nums[j]];
		}
		cout << dp[n] << endl;
	}
	return 0;
}