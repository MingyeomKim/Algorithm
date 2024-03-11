#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int board[51][51];
int dp[51][51];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H') {
				board[i][j] = 0;
			}
			else {
				board[i][j] = s[j] - '0';
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dp[0][0] = 0;
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		int move = board[y][x];
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			for (int k = 1; k < move; k++) {
				ny = ny + dy[direction];
				nx = nx + dx[direction];
			}
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (board[ny][nx] == 0) continue;
			if (dp[ny][nx] != -1) {
				// �̹� �湮�� ���̴�. �ݺ��� �����ϹǷ� ������ ������ �� �ִ� �����
				if (dp[ny][nx] + 1 == dp[y][x]) { // �����Ǵ� ���
					cout << -1 << endl;
					return 0;
				}
				dp[ny][nx] = max(dp[ny][nx], dp[y][x] + 1);
				// cout << "ny : " << ny << ", nx : " << nx << " dp[ny][nx] : " << dp[ny][nx] << endl;
				q.push(make_pair(ny, nx));
				continue;
			}
			dp[ny][nx] = dp[y][x] + 1;
			q.push(make_pair(ny, nx));
			// cout << "ny : " << ny << ", nx : " << nx << " dp[ny][nx] : "  << dp[ny][nx] << endl;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ret < dp[i][j]) {
				ret = dp[i][j];
			}
		}
	}
	cout << ret + 1 << endl;
	return 0;
}