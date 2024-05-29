#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int color[1001][3];
int dp[1001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
		}
	}

	int ret = -1;
	for (int start = 0; start < 3; start++) {
		for (int j = 0; j < 3; j++) {
			if (start == j) {
				dp[0][j] = color[0][j];
			}
			else {
				dp[0][j] = MAX;
			}
		}

		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
		}

		for (int j = 0; j < 3; j++) {
			if (j == start) {
				continue;
			}
			else {
				if (ret == -1 || ret > dp[n - 1][j]) {
					ret = dp[n - 1][j];
				}
			}
		}
	}
	cout << ret << endl;
	return 0;
}