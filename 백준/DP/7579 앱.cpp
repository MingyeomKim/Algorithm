#include <iostream>
using namespace std;

int weight[101];
int cost[101];

int dp[101][10001]; // i��° ���� Ȯ������ �� j ������� ���� �� �ִ� �ִ� �޸�

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