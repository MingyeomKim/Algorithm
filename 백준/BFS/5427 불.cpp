#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int board[1001][1001];
int dist[1001][1001];

int w, h;
bool isOut(int y, int x) {
	return y < 0 || y >= h || x < 0 || x >= w;
}

int main() {
	int t; cin >> t;
	while (t--) {
		memset(dist, -1, sizeof(dist));
		memset(board, -1, sizeof(board));
		cin >> w >> h;
		int sy, sx;
		queue<tuple<int, int, int>> fire;
		for (int i = 0; i < h; i++) {
			string s; cin >> s;
			for (int j = 0; j < w; j++) {
				if (s[j] == '@') {
					sy = i;
					sx = j;
				}
				else if (s[j] == '*') {
					fire.push(make_tuple(i, j, 0));
				}
				board[i][j] = 0;
			}
		}

		while (!fire.empty()) {
			int y, x, count;
			tie(y, x, count) = fire.front();
			fire.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (isOut(ny, nx) || board[ny][nx] == -1 || board[ny][nx] == '*') {
					continue;
				}
				board[ny][nx] = '*';
				fire.push(make_tuple(ny, nx, count + 1));
			}
		}

		queue<tuple<int, int, int>> q;
		q.push(make_tuple(sy, sx, 0));
		dist[sy][sx] = 0;
		bool flag = false;
		while (!q.empty()) {
			int y, x, count;
			tie(y, x, count) = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir], nx = x + dx[dir];
				if (dist[ny][nx] != -1 || board[ny][nx] == '#') {
					continue;
				}
				if (board[ny][nx] == '*'&&)
					if (isOut(ny, nx)) {
						cout << dist[y][x] + 1 << endl;
						break;
					}
				q.push(make_tuple(ny, nx, count + 1));
				dist[ny][nx] = dist[y][x] + 1;
			}

			if (flag) {
				break;
			}
		}
		if (!flag) {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}