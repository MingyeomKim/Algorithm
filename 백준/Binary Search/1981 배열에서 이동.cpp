#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n;
int board[101][101];
bool visited[101][101];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool isOut(int y, int x) {
	return (y <= 0 || y > n || x <= 0 || x > n);
}

// 방문하는 수의 크기가 mn보다 크거나 같고, mx보다 작거나 같은 방법으로 (1, 1)에서 (n, n)으로 이동할 수 있는가 ? 
bool bfs(int mn, int mx) {
	if (mn > board[1][1] || mx < board[1][1]) return false; 
	
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		int y, x;  tie(y, x) = q.front(); q.pop();
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || visited[ny][nx]) continue;

			if (board[ny][nx] >= mn && board[ny][nx] <= mx) {
				visited[ny][nx] = true; 
				q.push(make_pair(ny, nx)); 
			}
		}
	}
	return visited[n][n]; 
}

bool go(int k) {
	for (int min = 0; min <= 200; min++) {
		int max = k + min; 
		if (bfs(min, max)) return true; 
	}
	return false; 
}


int main() {
	cin >> n;
	int left = 0;
	int right = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (right < board[i][j]) right = board[i][j];
		}
	int ret = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		bool flag = false; 
		if(go(mid)) {
			ret = mid; 
			right = mid - 1; 
		}
		else
			left = mid + 1; 
	}
	cout << ret << endl;
	return 0;
}