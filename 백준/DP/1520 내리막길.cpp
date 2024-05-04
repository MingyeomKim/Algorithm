#include <iostream>
#include <cstring>
using namespace std;

int map[501][501];
int dp[501][501];  // (i, j)까지 내리막길로만 도달할 수 있는 경로의 개수
bool check[501][501];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int n, m;
bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m;
}

int solve(int y, int x) {
	if (y == n - 1 && x == m - 1) return 1;

	int& ret = dp[y][x];
	if (ret != -1) return ret;

	ret = 0;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (isOut(ny, nx) || check[ny][nx] || map[y][x] <= map[ny][nx]) continue;
		check[ny][nx] = true;
		ret += solve(ny, nx);
		check[ny][nx] = false;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cout << solve(0, 0) << endl;
	return 0;
}