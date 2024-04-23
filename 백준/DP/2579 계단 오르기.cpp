#include <iostream>
#include <cstring>
using namespace std;

int height[301];
int dp[301][2];

int solve(int index, bool moveDown) {
	if (index == 0) {
		return 0;
	}
	else if (index == 1) {
		return height[1];
	}
	int& ret = dp[index][moveDown];
	if (ret != -1) return ret;

	ret = 0;
	if (!moveDown) {
		int cand = solve(index - 1, true) + height[index];
		if (ret < cand) {
			ret = cand;
		}
	}
	int cand = solve(index - 2, false) + height[index];
	if (ret < cand) {
		ret = cand;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(n, false) << endl;
	return 0;
}