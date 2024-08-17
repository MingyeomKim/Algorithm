#include <iostream>
#define endl '\n'
using namespace std;

int dp[5005]; // 자신의 앞에 번호까지 봤을 때 출석 안된 사람의 수
int receive[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, q, m;
	cin >> n >> k >> q >> m;

	for (int i = 0; i < k; i++) { // 조는 학생
		int x; cin >> x;
		receive[x] = -1;
	}

	for (int i = 0; i < q; i++) { // 번호 받을 학생
		int x; cin >> x;
		if (receive[x] == -1) { // 조는 학생이면
			continue;
		}
		receive[x] = 1;
		for (int j = 2; ; j++) {
			int next = x * j;
			if (next > n + 2) {
				break;
			}
			if (receive[next] == -1) { // 조는 학생이면
				continue;
			}
			receive[next] = 1;
		}
	}

	// receive가 -1이거나 0이면 출석 안된 학생
	dp[3] = 0;
	for (int i = 4; i <= n + 3; i++) {
		if (receive[i - 1] == -1 || receive[i - 1] == 0) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int s, e; cin >> s >> e;
		cout << dp[e + 1] - dp[s] << endl;
	}
	return 0;
}