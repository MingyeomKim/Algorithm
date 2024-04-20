#include <iostream>
#include <cstring>
using namespace std;

int dp[101][101][101];

int solve(int a, int b, int c) {
	int& ret = dp[a + 50][b + 50][c + 50];
	if (ret != -1) return ret;

	if (a <= 0 || b <= 0 || c <= 0) {
		return ret = 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		return ret = solve(20, 20, 20);
	}

	if (a < b && b < c) {
		return ret = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
	}
	return ret = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	// 이거를 한번에할 수 있나?
	for (int i = 50; i >= -50; i--) {
		for (int j = 50; j >= -50; j--) {
			for (int k = 50; k >= -50; k--) {
				solve(i, j, k);
			}
		}
	}

	while (true) {
		int a, b, c; cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[a + 50][b + 50][c + 50] << endl;
	}
	return 0;
}