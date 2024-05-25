#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int dp[100001];

int solve(int x) {
	int& ret = dp[x];
	if (ret != -1) return ret;

	int down = sqrt(x);
	if (down * down == x) {
		return ret = 1;
	}

	for (int next = down; next >= 1; next--) {
		int cand = solve(x - next * next) + 1;
		if (ret == -1 || ret > cand) {
			ret = cand;
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 1;

	cout << solve(n) << endl;
	return 0;
}