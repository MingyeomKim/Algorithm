#include <iostream>
using namespace std;

int weight[101];
int cost[101];

int dp[101][10001]; // i번째 앱을 확인헀을 때 j 비용으로 얻을 수 있는 최대 메모리

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + weight[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[n][i] >= m) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}