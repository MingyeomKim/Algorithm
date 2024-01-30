#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[2001][2001];
int s;

int solve(int now, int clip) {
	if (now > s * 2) return 0;
	if (now == s) return 1;
	int& ret = dp[now][clip];
	if (ret != -1) return ret;

	int cand1 = solve(now + now, now);
	int cand2 = solve(now + clip, clip);
	int cand3 = solve(now - 1, clip);
	return ret = min(cand1 + 2, min(cand2, cand3) + 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	int s; cin >> s;
	dp[1][0] = 0;
	dp[2][1] = 2;
	int ret = min(solve(4, 3), min(solve(3, 1), solve(1, 1)));
	cout << ret << endl;
	return 0;
}

/*
int main() {
	memset(dp, -1, sizeof(dp));
	int s; cin >> s;
	dp[1] = 0;
	dp[2] = 2;
	int clip = 1;
	for (int i = 2; i <= s; i++) {
		if (dp[i + clip] == -1 || dp[i + clip] > dp[i] + 1) {
			dp[i + clip] = dp[i] + 1;
		}
		if (dp[i + i] == -1 || dp[i + i] > dp[i] + 1) {
			dp[i + i] = dp[i] + 2;
			clip = i;
		}
		if (dp[i - 1] == -1 || dp[i - 1] > dp[i] + 1){
			dp[i - 1] = dp[i] + 1;
		}

		for (int j = 1; j <= s; j++) {
			cout << dp[j] << " ";
		} cout << endl;
	}
	cout << dp[s] << endl;
	return 0;

}*/

/*
* dp[i] = i개의 이모티콘을 만드는 데 걸리는 시간의 최솟값
* 1. 복사하는 연산
* 2. 현재 클립보드를 붙여넣기 하는 연산
* 3. 이모티콘 하나를 삭제하는 연산
*
* 현재에서 꼭 최소가 아니어도 목표하는 위치에서 최소일 수 있다.
* dp[i + i] = dp[i] + 2;
* 클립보드를 바로 붙여넣기 하는 경우
* dp[i - 1] = d[i] + 1;
*
* 1 2 3 6 9 18
* 0 2 3 5 6 8
*
* 1 2 4
* 0 2 4
*
* s의 두 배를 넘어가면 1을 계속 붙여넣기 하는 것과 다른 게 없으니, s의 두 배를 탐색의 제한으로 한다.
*/