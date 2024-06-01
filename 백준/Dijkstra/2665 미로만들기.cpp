#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

bool board[51][51];
int dist[51][51];
int n;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			board[i][j] = s[j] - '0';
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist[0][0] = 0;
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (isOut(ny, nx)) {
				continue;
			}

			if (board[ny][nx] == true) {
				if (dist[ny][nx] == -1 || dist[ny][nx] > dist[y][x]) {
					dist[ny][nx] = dist[y][x];
					q.push(make_pair(ny, nx));
				}
			}
			else {
				if (dist[ny][nx] == -1 || dist[ny][nx] > dist[y][x] + 1) {
					dist[ny][nx] = dist[y][x] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	cout << dist[n - 1][n - 1] << endl;
	return 0;
}