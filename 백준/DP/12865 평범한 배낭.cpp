#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k; 
int dp[101][100001];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	cin >> n >> k; 
	vector<pair<int, int>> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i].first >> v[i].second; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j]; 
			if (j - v[i].first >= 0)
				dp[i][j] = max(dp[i - 1][j - v[i].first] + v[i].second, dp[i][j]);
		}
	}
	cout << dp[n][k] << endl;
	return 0; 
}