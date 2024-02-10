#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

bool board[101][101];
int dist[101][101];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int n, m;

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist[0][0] = 1;
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || dist[ny][nx] != -1 || board[ny][nx] == 0) continue;
			dist[ny][nx] = dist[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
	cout << dist[n - 1][m - 1] << endl;
	return 0;
}