#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int board[101][101][101];
int dist[101][101][101];

int dz[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, 0, -1, 0 };
int dx[6] = { 0, 0, 0, 1, 0, -1 };

int m, n, h;

bool isOut(int z, int y, int x) {
	return z < 0 || z >= h || y < 0 || y >= n || x < 0 || x >= m;
}

queue<tuple<int, int, int, int>> q;

void bfs() {
	while (!q.empty()) {
		int z, y, x, times;
		tie(z, y, x, times) = q.front();
		q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nz = z + dz[dir];
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (isOut(nz, ny, nx) || dist[nz][ny][nx] != -1 || board[nz][ny][nx] == -1) {
				continue;
			}
			q.push(make_tuple(nz, ny, nx, times + 1));
			dist[nz][ny][nx] = times + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dist, -1, sizeof(dist));
	cin >> m >> n >> h;
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cin >> board[z][y][x];
			}
		}
	}

	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (board[z][y][x] == 1) {
					q.push(make_tuple(z, y, x, 0));
					dist[z][y][x] = 0;
				}
			}
		}
	}

	bfs();

	int ret = 0;
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (dist[z][y][x] == -1 && board[z][y][x] != -1) {
					cout << -1 << endl;
					return 0;
				}
				else {
					if (ret < dist[z][y][x]) {
						ret = dist[z][y][x];
					}
				}
			}
		}
	}
	cout << ret << endl;
	return 0;
}