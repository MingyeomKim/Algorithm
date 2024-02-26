#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

bool board[301][301];
bool visited[301][301];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int n, m;

bool isOut(int y, int x) {
	return y < 1 || y > n || x< 1 || x> m;
}

void bfs(int sy, int sx) {
	memset(visited, false, sizeof(visited));

	visited[sy][sx] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d], nx = x + dx[d];
			if (isOut(ny, nx) || visited[ny][nx]) continue;
			visited[ny][nx] = true;
			if (board[ny][nx] == 1) {
				board[ny][nx] = 0;
			}
			else {
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int sy, sx; cin >> sy >> sx;
	int ey, ex; cin >> ey >> ex;

	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '*') {
				board[i][j + 1] = 0;
			}
			else if (s[j] == '#') {
				board[i][j + 1] = 1;
			}
			else {
				board[i][j + 1] = s[j] - '0';
			}
		}
	}

	int cnt = 0;
	while (true) {
		if (board[ey][ex] == 0) {
			break;
		}
		bfs(sy, sx);
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}