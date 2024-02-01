#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int dp[2001][2001];

int main() {
	int s; cin >> s;
	memset(dp, -1, sizeof(dp));
	queue<pair<int, int>> q; 
	q.push(make_pair(1, 0));
	dp[1][0] = 0;
	while (!q.empty()) {
		int now, clip; 
		tie(now, clip) = q.front(); 
		q.pop();
		if (now < 0 || now > 2 * s) continue;
		// 복사하는 경우
		if (dp[now][now] == -1) {
			q.push(make_pair(now, now));
			dp[now][now] = dp[now][clip] + 1;
		}

		// 붙여넣기 하는 경우
		if (now + clip < 2 * s && dp[now + clip][clip] == -1) {
			q.push(make_pair(now + clip, clip));
			dp[now + clip][clip] = dp[now][clip] + 1;
		}
		// 하나 지우는 경우
		if (now > 1 && dp[now - 1][clip] == -1) {
			q.push(make_pair(now - 1, clip));
			dp[now - 1][clip] = dp[now][clip] + 1;
		}
	}
	int ret = -1;
	for (int i = 0; i < 2001; i++) {
		if (ret == -1 ||( ret > dp[s][i] && dp[s][i] != -1)){
			ret = dp[s][i];
		}
	}
	cout << ret << endl;
}