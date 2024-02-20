#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dp[5001][10001];

int main() {
	while (true) {
		memset(dp, -1, sizeof(dp));
		int n; double fm;
		cin >> n >> fm;
		int m = fm * 100;
		if (n == 0 && m == 0) {
			break;
		}

		vector<pair<int, int>> candy;
		for (int i = 0; i < n; i++) {
			int calory;
			double price;
			cin >> calory >> price;
			candy.push_back(make_pair(calory, price * 100));
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int now_c = candy[i - 1].first;  // curval
				int now_p = candy[i - 1].second; // curweight
				if (now_c <= j) {
					dp[i][j] = max(
						dp[i - 1][j - now_p] + now_c, dp[i - 1][j]
					);
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;

}