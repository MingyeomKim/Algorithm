#include <iostream>
#include <cstring>
using namespace std;

long long dp[31][31]; // w개의 한 조각 알약, h개의 반 조각 알약이 남은 시점에서 가능한 서로 다른 문자열의 개수

long long solve(int w, int h) {
	if (w == 0 && h == 0) return 1;
	long long& ret = dp[w][h];
	if (ret > -1) return ret;

	ret = 0;
	if (w > 0) {
		ret += solve(w - 1, h + 1); // 한 조각 알약을 반 개 먹었다
	}
	if (h > 0) {
		ret += solve(w, h - 1); // 반 조각 알약을 먹었다
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		memset(dp, -1, sizeof(dp));
		int n; cin >> n;
		if (n == 0) {
			break;
		}
		cout << solve(n - 1, 1) << endl;
	}
	return 0;
}