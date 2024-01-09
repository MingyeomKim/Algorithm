#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int board[101][101];
bool sink[101][101];
bool check[101][101];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int n;
void checkSink(int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] <= k) {
				sink[i][j] = true;
			}
		}
	}
}

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n;
}

void bfs(int sy, int sx) {
	check[sy][sx] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || check[ny][nx] || sink[ny][nx] == 1) continue;
			q.push(make_pair(ny, nx));
			check[ny][nx] = true;
		}
	}
}

int calculate() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] || sink[i][j] == 1) continue;
			bfs(i, j);
			cnt++;
		}
	}
	memset(check, false, sizeof(check));
	return cnt;
}

int main() {
	cin >> n;
	int max = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] > max) {
				max = board[i][j];
			}
		}
	}

	int ret = -1;
	for (int k = 0; k <= max; k++) {
		memset(sink, false, sizeof(sink));
		checkSink(k);
		int areas = calculate();
		if (ret == -1 || ret < areas) {
			ret = areas;
		}
	}
	cout << ret << endl;
	return 0;
}