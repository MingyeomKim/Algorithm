#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int board[101][101];
int n, m;
bool check[101][101];
int temp[101][101];

int dy[4] = { -1,1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m;
}

// (y, x)가 공기 중에 맞닿아있다면 true, 아니면 false
bool bfs(int y, int x) {
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx)) return true;
			if ((board[ny][nx] == 0 || board[ny][nx] == 2) && !check[ny][nx]) {
				q.push(make_pair(ny, nx));
				check[ny][nx] = true;
			}
		}
	}
	return false;
}

bool bfs2(int y, int x) {
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || check[ny][nx]) continue;
			if (board[ny][nx] == 2) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			temp[i][j] = board[i][j];
		}

	int ret = 0; // 치즈가 모두 녹는 것에 걸리는 시간
	int last = 0; // 치즈가 녹기 직전 남아있는 치즈조각의 수를 계산
	while (true) {
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				if (board[y][x] == 0 && bfs(y, x))
					board[y][x] = 2;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				if (board[y][x] == 1 && bfs2(y, x))
					board[y][x] = 0;

		int cheese = 0;
		for (int y = 0; y < n; y++)
			for (int x = 0; x < m; x++)
				if (board[y][x] == 1) cheese++;
		if (ret == 0 && cheese == 0) {
			int cnt = 0;
			for (int y = 0; y < n; y++)
				for (int x = 0; x < m; x++)
					if (temp[y][x] == 1) cnt++;
			cout << 1 << endl << cnt << endl;
			return 0;
		}
		if (cheese == 0)
			break;
		last = cheese;
		ret++;
	}
	cout << ret + 1 << endl << last << endl;
	return 0;
}
