#include <iostream>
#include <cstring>
using namespace std;

int dy[2] = { 1, 0 };
int dx[2] = { 0, 1 };

int dp[16][16];
int n, m;
int ey, ex;

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m;
}

int dfs(int y, int x) {
	if (y == ey && x == ex) {
		return 1;
	}
	int& ret = dp[y][x];
	if (ret != -1) return ret;

	ret = 0;
	for (int dir = 0; dir < 2; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (isOut(ny, nx)) {
			continue;
		}
		ret += dfs(ny, nx);
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;

	int k;  cin >> k;
	if (k == 0) {
		ey = n - 1;
		ex = m - 1;
		cout << dfs(0, 0) << endl;
	}
	else {
		k--;
		ey = k / m;
		ex = k % m;
		int first = dfs(0, 0);

		ey = n - 1;
		ex = m - 1;
		memset(dp, -1, sizeof(dp));
		int second = dfs(k / m, k % m);

		cout << first * second << endl;
	}
	return 0;
}