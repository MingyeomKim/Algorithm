#include <iostream> 
#include <vector>
#include <cstring>
using namespace std;

int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		int m; cin >> m;

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = v[i]; j <= m; j++) {
				dp[j] += dp[j - v[i]];
			}
		}
		cout << dp[m] << endl;
	}
	return 0;
}