#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
#define INF 987654321

int board[126][126];
int dist[126][126];
bool visited[126][126];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int n;
int solve(int y, int x) {
	if (y == n - 1 && x == n - 1) {
		return board[y][x];
	}
	int& ret = dist[y][x];
	if (ret != -1) return ret;

	visited[y][x] = true;
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		int cand = solve(ny, nx) + board[y][x];
		if (ret == -1 || ret > cand) {
			ret = cand;
		}
	}
	visited[y][x] = false;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int count = 0;
	while (true) {
		count++;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				dist[i][j] = INF;
			}
		}

		cout << "Problem " << count << ": ";
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		dist[0][0] = board[0][0];
		while (!q.empty()) {
			int y, x; tie(y, x) = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (dist[ny][nx] > dist[y][x] + board[ny][nx]) {
					dist[ny][nx] = dist[y][x] + board[ny][nx];
					q.push(make_pair(ny, nx));
				}
			}
		}

		cout << dist[n - 1][n - 1] << endl;
	}

}