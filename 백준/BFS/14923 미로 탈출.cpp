#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int dist[1001][1001][2];
bool board[1001][1001];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	int hy, hx; cin >> hy >> hx;
	int ey, ex; cin >> ey >> ex;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(hy, hx, 0));
	dist[hy][hx][0] = 0;
	while (!q.empty()) {
		int y, x, cnt;
		tie(y, x, cnt) = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny <= 0 || ny > n || nx <= 0 || nx > m) {
				continue;
			}
			if (cnt == 0) {
				if (board[ny][nx] && dist[ny][nx][1] == -1) {
					q.push(make_tuple(ny, nx, 1));
					dist[ny][nx][1] = dist[y][x][0] + 1;
				}
				else if (!board[ny][nx] && dist[ny][nx][0] == -1) {
					q.push(make_tuple(ny, nx, 0));
					dist[ny][nx][0] = dist[y][x][0] + 1;
				}
			}
			else { // 이미 사용한 경우 
				if (board[ny][nx] || dist[ny][nx][1] != -1 || dist[ny][nx][0] != -1) {
					continue;
				}
				q.push(make_tuple(ny, nx, 1));
				dist[ny][nx][1] = dist[y][x][1] + 1;
			}
		}
	}

	if (dist[ey][ex][0] != -1 && dist[ey][ex][1] != -1) {
		cout << min(dist[ey][ex][0], dist[ey][ex][1]) << endl;
	}
	else if (dist[ey][ex][0] != -1) {
		cout << dist[ey][ex][0] << endl;
	}
	else {
		cout << dist[ey][ex][1] << endl;
	}
	return 0;
}