#include <iostream>
#include <queue>
using namespace std;

int number[100001];
vector<int> sub[100001];
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int start;
	for (int i = 1; i <= n; i++) {
		int sup; cin >> sup;
		if (sup == -1) {
			start = i;
			continue;
		}
		sub[sup].push_back(i);
	}

	for (int i = 1; i <= m; i++) {
		int who, num; cin >> who >> num;
		number[who] += num;
	}

	queue<int> q;
	q.push(start);
	dp[start] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : sub[now]) {
			q.push(next);
			dp[next] = dp[now] + number[next];
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;

	return 0;
}