#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1001][3];
int n;
int cost[1001][3];

int solve(int index, int color) {
	int& ret = dp[index][color];
	if (ret != -1) return ret;

	if (index == n) {
		return ret = 0;
	}

	for (int next_color = 0; next_color < 3; next_color++) {
		if (next_color != color) {
			int cand = solve(index + 1, next_color) + cost[index + 1][next_color];
			if (ret == -1 || ret > cand) {
				ret = cand;
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
	cout << min(solve(0, 0) + cost[0][0], min(solve(0, 1) + cost[0][1], solve(0, 2) + cost[0][2])) << endl;
	return 0;
}