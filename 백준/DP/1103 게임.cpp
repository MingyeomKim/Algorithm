#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int board[51][51];
int dp[51][51]; 
bool visited[51][51];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int n, m;


bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m || board[y][x] == 0;
}

int dfs(int y, int x) {
	if (isOut(y, x)) {
		return 0;
	}
	if (visited[y][x]) {
		cout << -1 << endl;
		exit(0);
	}
	int& ret = dp[y][x]; 
	if (ret != -1) return ret;

	visited[y][x] = true;
	ret = 0;
	int move = board[y][x];
	for (int direction = 0; direction < 4; direction++) {
		int ny = y + (dy[direction] * board[y][x]);
		int nx = x + (dx[direction] * board[y][x]);
		ret = max(ret, dfs(ny, nx) + 1);
	}
	visited[y][x] = false;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 

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
	cout << dfs(0, 0) << endl;

	return 0;
}