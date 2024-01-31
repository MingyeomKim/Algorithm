#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2001][2001];
int s;

int solve(int now, int clip) {
	if (now == s || now < 1 || now > 2 * s) return 0;
	
	int& ret = dp[now][clip];
	if (ret != -1) return ret;

	ret = 0;
	vector<int> candidates = {
		solve(now + now, now) + 2,
		solve(now + clip, clip) + 1,
		solve(now - 1, clip) + 1
	};
	sort(candidates.begin(), candidates.end());
	return ret = candidates[0];
}

int main() {
	int s; cin >> s;
	memset(dp, -1, sizeof(dp));
	solve(1, 0);
	cout << dp[s] << endl;
	return 0;
}