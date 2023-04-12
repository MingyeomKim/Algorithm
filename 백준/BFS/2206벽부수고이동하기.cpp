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

			// ���� �μ��� �ʰ� ��������.
			if (board[ny][nx] == 0 && dist[ny][nx][k] == 0) {
				dist[ny][nx][k] = dist[y][x][k] + 1; 
				q.push(make_tuple(ny, nx, k));
			}

			// �� ���� ���� �μ� ���� ����, ���� ��ġ�� ���̰�, ���� ĭ�� �μ��鼭 ������ ���� ���ٸ�
			if (k == 0 && board[ny][nx] == 1 && dist[ny][nx][k + 1] == 0) {
				dist[ny][nx][k + 1] = dist[y][x][k] + 1; 
				q.push(make_tuple(ny, nx, k + 1)); 
				// k + 1 queue�� �־��� ������, ���ķδ� k�� �׻� 1�̴�. ���� �� ������ ���� ��� �󿡼� �ٽ� ����� �� ����.
			}
		}
	}

	// ���� �μ��� �ʰ� �����ϴ� ��, �μ��� �����ϴ� �� ��� �湮�� �����ϸ�
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