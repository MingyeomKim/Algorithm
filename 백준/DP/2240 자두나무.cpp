#include <iostream>
#include <cstring>
using namespace std;

int dp[1001][31];
int t, w;
int ret = 0;
int drop[1001];

int solve(int time, int moved) {
	if (time == t) {
		if (moved % 2 == 1) { // 현재 2번 나무
			return 2 == drop[time];
		}
		else { // 현재 1번 나무
			return 1 == drop[time];
		}
	}
	int& ret = dp[time][moved];
	if (ret != -1) return ret;

	int move = 0, notMove = 0;
	if (moved < w) { // 움직일 힘이 남았다면
		move = solve(time + 1, moved + 1);
	}
	notMove = solve(time + 1, moved);
	ret = max(move, notMove);
	if (moved % 2 == 1 && 2 == drop[time]) {
		ret++;
	}
	else if (moved % 2 == 0 && 1 == drop[time]) {
		ret++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> t >> w;
	for (int i = 1; i <= t; i++) {
		cin >> drop[i];
	}
	cout << solve(0, 0) << endl;
	return 0;
}