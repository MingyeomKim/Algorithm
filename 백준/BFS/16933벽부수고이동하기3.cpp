#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#pragma warning (disable:4996)
using namespace std; 

int n, m, k;
int dist[1001][1001][11][2];
int board[1001][1001]; 
const int INF = 987654321; 

int dy[5] = {0, -1,1, 0, 0 };
int dx[5] = {0,  0, 0,1, -1 }; 

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= m); 
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &board[i][j]); 
	memset(dist, 0, sizeof(dist)); 

	queue<tuple<int,int,int, int>> q; 
	q.push(make_tuple(0, 0, 0, 0)); 
	dist[0][0][0][0] = 1;
	while (!q.empty()) {
		int y, x, broken, night;
		tie(y, x, broken, night) = q.front(); q.pop(); 
		for (int direction = 0; direction < 5; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx)) continue;

			if (ny == y && nx == x && dist[ny][nx][broken][1 - night] == 0) {
				dist[ny][nx][broken][1 - night] = dist[y][x][broken][night] + 1;
				q.push(make_tuple(ny, nx, broken, 1 - night));
				continue; 
			}

			// 이동하지 않거나 다음 빈칸으로 이동한다.
			if (board[ny][nx] == 0 && dist[ny][nx][broken][1 - night] == 0) {
				dist[ny][nx][broken][1 - night] = dist[y][x][broken][night] + 1;
				q.push(make_tuple(ny, nx, broken, 1 - night)); 
				continue; 
			}

			// 낮이고, 부순 횟수가 k보다 작고, 벽이고, 아직 부수지 않았다면 부순다.
			if (night == 0 && broken < k && board[ny][nx] == 1 && dist[ny][nx][broken + 1][1 - night] == 0) {
				dist[ny][nx][broken + 1][1 - night] = dist[y][x][broken][night] + 1;
				q.push(make_tuple(ny, nx, broken + 1, 1 - night)); 
			}
		}
	}

	int ret = -1; 
	for (int i = 0; i <= k; i++) {
		for(int j= 0; j < 2; j++){
			int cand = dist[n - 1][m - 1][i][j];
			if(cand != 0){
				if (ret == -1) ret = cand;
				else if (ret > cand) ret = cand; 
			}
		}
	}
	if (ret == INF) cout << -1 << endl;
	else cout << ret << endl;

	return 0; 
}