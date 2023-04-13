#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#pragma warning (disable:4996)
using namespace std; 

int n, m, k;
int board[1001][1001]; 
int dist[1001][1001][11];

int dy[4] = { 1,-1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 };

const int INF = 987654321;

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= m); 
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &board[i][j]); 
	
	memset(dist, 0, sizeof(dist)); 
	// 좌표(Y, X)와 부순 벽의 개수 K를 저장한다
	queue<tuple<int, int, int>> q; 
	q.push(make_tuple(0, 0, 0)); 
	dist[0][0][0] = 1; 
	
	while (!q.empty()) {
		int y, x, broken;
		tie(y, x, broken) = q.front(); q.pop(); 
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			if (isOut(ny, nx)) continue;
			// 벽을 부수지 않고 이동하는 경우
			if (board[ny][nx] == 0 && dist[ny][nx][broken] == 0) {
				dist[ny][nx][broken] = dist[y][x][broken] + 1; 
				q.push(make_tuple(ny, nx, broken)); 
			}

			// 벽을 부수고 이동하는 경우
			if (broken < k && board[ny][nx] == 1 && dist[ny][nx][broken + 1] == 0) {
				dist[ny][nx][broken + 1] = dist[y][x][broken] + 1; 
				q.push(make_tuple(ny, nx, broken + 1)); 
			}
		}
	}
	int ret = INF; 
	for (int i = 0; i <= k; i++)
		if (dist[n - 1][m - 1][i] != 0)
			if(ret > dist[n-1][m-1][i]) 
				ret = dist[n - 1][m - 1][i]; 
	if (ret == INF)
		cout << -1 << endl;
	else
		cout << ret << endl;
	return 0; 
}