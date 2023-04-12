#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std; 

int n, m; 
int board[1001][1001]; 
int dy[4] = { 0, 0, 1 ,-1 };
int dx[4] = { 1, -1, 0, 0 };
int dist[1001][1001][2];

bool isOut(int y, int x) {
	return (y <= 0 || y > n || x <= 0 || x > m); 
}

int bfs() {
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(1, 1, 0)); 
	dist[1][1][0] = 1; 
	while (!q.empty()) {
		int y, x, k; 
		tie(y, x, k) = q.front(); q.pop();
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx)) continue; 

			// 벽을 부수지 않고 지나간다.
			if (board[ny][nx] == 0 && dist[ny][nx][k] == 0) {
				dist[ny][nx][k] = dist[y][x][k] + 1; 
				q.push(make_tuple(ny, nx, k));
			}

			// 한 번도 벽을 부순 적이 없고, 다음 위치가 벽이고, 다음 칸을 부수면서 지나간 적이 없다면
			if (k == 0 && board[ny][nx] == 1 && dist[ny][nx][k + 1] == 0) {
				dist[ny][nx][k + 1] = dist[y][x][k] + 1; 
				q.push(make_tuple(ny, nx, k + 1)); 
				// k + 1 queue에 넣었기 때문에, 이후로는 k는 항상 1이다. 따라서 이 구문을 동일 경로 상에서 다시 통과할 수 없다.
			}
		}
	}

	// 벽을 부수지 않고 도착하는 것, 부수고 도착하는 것 모두 방문이 가능하면
	if (dist[n][m][0] != 0 && dist[n][m][1] != 0)
		return min(dist[n][m][0], dist[n][m][1]);
	else if (dist[n][m][0] != 0)
		return dist[n][m][0];
	else if (dist[n][m][1] != 0)
		return dist[n][m][1];
	else
		return -1; 
}

int main() {
	cin >> n >> m; 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &board[i][j]); 

	cout << bfs() << endl;
	return 0; 
}