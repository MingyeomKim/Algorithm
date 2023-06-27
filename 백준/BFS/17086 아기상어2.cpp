#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std; 

int n, m; 
int board[51][51]; 
int check[51][51]; 

int dy[] = { 0, 0, 1, -1, -1, -1, 1, 1 }; 
int dx[] = { 1, -1, 0, 0, -1, 1, -1, 1 }; 

int isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m; 
}

int bfs(int y, int x) {
	memset(check, -1, sizeof(check)); 
	queue<pair<int, int>> q; 
	check[y][x] = 0; 
	q.push(make_pair(y, x)); 

	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		for (int direction = 0; direction < 8; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			if (isOut(ny, nx) || check[ny][nx] != -1) continue; 
			check[ny][nx] = check[y][x] + 1; 
			if (board[ny][nx] == 1)
				return check[ny][nx]; 
			else
				q.push(make_pair(ny, nx)); 
		}
	}
}

int main() {
	cin >> n >> m; 
	vector<pair<int, int>> v; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				v.emplace_back(i, j); 
		}
	int max = 0; 
	for (auto p : v) {
		int y = p.first, x = p.second; 
		int cand = bfs(y, x); 
		if (cand > max) max = cand; 
	}
	cout << max << endl;
	return 0; 
}