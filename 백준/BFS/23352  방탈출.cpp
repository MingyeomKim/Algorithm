#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int board[51][51];
int dist[51][51];

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
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int max_dist = 0; // 가장 긴 경로
	int ret = 0; // 숫자의 합
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (board[y][x] == 0) {
				continue;
			}
			memset(dist, 0, sizeof(dist));
			queue<pair<int, int>> q;
			q.push(make_pair(y, x));
			dist[y][x] = 1;
			while (!q.empty()) {
				int i = q.front().first;
				int j = q.front().second;
				q.pop();

				if (dist[i][j] > max_dist) {
					max_dist = dist[i][j];
					ret = board[y][x] + board[i][j];
				}
				else if (dist[i][j] == max_dist) {
					ret = max(ret, board[y][x] + board[i][j]);
				}

				for (int dir = 0; dir < 4; dir++) {
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					if (isOut(ny, nx) || board[ny][nx] == 0 || dist[ny][nx] != 0) {
						continue;
					}

					dist[ny][nx] = dist[i][j] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

	cout << ret << endl;
	return 0;
}