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
		// �������� �ʰ� �Ѿ�� ���
		// �����ϰ� �� �������� �ǳʶٴ� ���
		ret = max(solve(index + 1, false), solve(index + 2, false) + drink[index]);
	}
	else {
		// �����ϰ� �ٷ� �������� �Ѿ�� ���
		// �������� �ʰ� �ǳʶٴ� ���
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