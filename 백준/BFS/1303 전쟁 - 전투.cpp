#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

bool check[101][101];
char board[101][101];

int dy[4] = { -1, 1, 0,0 };
int dx[4] = { 0, 0, 1, -1 };
int m, n;

int bfs(int sy, int sx) {
	int sameColor = 0;

	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	check[sy][sx] = true;
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		sameColor++;
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || check[ny][nx] || board[ny][nx] != board[sy][sx]) {
				continue;
			}
			q.push(make_pair(ny, nx));
			check[ny][nx] = true;
		}
	}
	return sameColor;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
		}
	}

	int blue = 0;
	int white = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j]) {
				continue;
			}
			int count = bfs(i, j);
			if (board[i][j] == 'B') {
				blue += (count * count);
			}
			else {
				white += (count * count);
			}
		}
	}

	cout << white << " " << blue << endl;
	return 0;
}