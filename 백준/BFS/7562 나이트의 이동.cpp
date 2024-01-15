#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int dy[8] = { -2, 2, -2, 2, -1, 1, 1, -1 };
int dx[8] = { -1, -1, 1, 1, -2, -2, 2, 2 };

int dist[301][301];
int length;

bool isOut(int y, int x) {
	return y < 0 || y >= length || x < 0 || x >= length;
}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	dist[y][x] = 0;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		for (int direction = 0; direction < 8; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || dist[ny][nx] != -1)
				continue;
			q.push(make_pair(ny, nx));
			dist[ny][nx] = dist[y][x] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		cin >> length;
		int sy, sx; cin >> sy >> sx;
		int ey, ex; cin >> ey >> ex;
		memset(dist, -1, sizeof(dist));
		bfs(sy, sx);
		cout << dist[ey][ex] << endl;
	}
	return 0;
}