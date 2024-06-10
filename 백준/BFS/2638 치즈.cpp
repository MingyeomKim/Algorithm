#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

bool board[101][101];
bool check[101][101];
bool temp[101][101];

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

	int ret = 0;
	while (true) {
		memset(check, false, sizeof(check));
		bool exists = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = board[i][j];
				if (board[i][j]) {
					exists = true;
				}
			}
		}
		if (!exists) {
			break;
		}
		ret++;

		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		check[0][0] = true;
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
				if (check[ny][nx]) {
					if (board[ny][nx]) {
						temp[ny][nx] = false;
					}
					continue;
				}
				if (board[ny][nx]) {
					check[ny][nx] = true;
					continue;
				}
				check[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = temp[i][j];
			}
		}
	}
	cout << ret << endl;
	return 0;
}