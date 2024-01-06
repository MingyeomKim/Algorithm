#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1000001]; // dp[i] : 1에서 i까지 연산하는 횟수의 최솟값

int n;
vector<int> ans;
int solve(int x) {
	if (x == n) {
		ans.push_back(x);
		return 1;
	}
	if (x > n) {
		return 0;
	}
	int& ret = dp[x];
	if (ret != -1) return ret;

	vector<int> candidates = {
		solve(x * 3),
		solve(x * 2),
		solve(x + 1)
	};
	sort(candidates.begin(), candidates.end());
	for (int candidate : candidates) {
		if (candidate != 0) {
			return candidate + 1;
		}
	}
	return 0;
}

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	solve(1);

	cout << ans.size() - 1 << endl;
	sort(ans.begin(), ans.end(), greater<int>());
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}