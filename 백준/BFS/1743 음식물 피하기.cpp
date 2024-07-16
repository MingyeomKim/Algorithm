#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

bool check[101][101];
bool board[101][101];
int n, m, k;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int bfs(int sy, int sx) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	check[sy][sx] = true;
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 1 || ny > n || nx < 1 || nx > m || !board[ny][nx] || check[ny][nx]) {
				continue;
			}
			q.push(make_pair(ny, nx));
			check[ny][nx] = true;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int r, c; cin >> r >> c;
		board[r][c] = true;
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j] || !board[i][j]) {
				continue;
			}
			int cand = bfs(i, j);
			if (ret < cand) {
				ret = cand;
			}
		}
	}

	cout << ret << endl;
	return 0;
}