#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[10001][2];
int drink[10001];
int n;

int solve(int index, bool isContinued) {
	if (index > n) {
		return 0;
	}
	int& ret = dp[index][isContinued];
	if (ret != -1) return ret;

	if (isContinued) {
		// 선택하지 않고 넘어가는 경우
		// 선택하고 그 다음으로 건너뛰는 경우
		ret = max(solve(index + 1, false), solve(index + 2, false) + drink[index]);
	}
	else {
		// 선택하고 바로 다음으로 넘어가는 경우
		// 선택하지 않고 건너뛰는 경우
		ret = max(solve(index + 1, true) + drink[index], solve(index + 1, false));
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> drink[i];
	}

	cout << solve(0, false) << endl;
	return 0;
}