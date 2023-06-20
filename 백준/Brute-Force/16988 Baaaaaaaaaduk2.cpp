#include <iostream> 
#include <queue>
#include <tuple>
#include <cstring>
using namespace std; 

bool check[21][21];
int board[21][21];

int dy[4] = { 1, -1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 };

int n, m;

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m;
}

// (둘러싸여져 있는가?, 둘러싸여져 있는 흑돌의 개수는?)
pair<bool, int> bfs(int y, int x) {
	bool flag = true; 
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d], nx = x + dx[d]; 
		if (isOut(ny, nx) || board[ny][nx] != 0) continue;
		flag = false; 
	}
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	check[y][x] = true;
	int black = 1;
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || check[ny][nx] || board[ny][nx] != 2) continue;

			for (int d = 0; d < 4; d++) {
				int nny = ny + dy[d], nnx = nx + dx[d];
				if (isOut(nny, nnx) || board[nny][nnx] != 0) continue;
				flag = false;
			}

			q.push(make_pair(ny, nx)); 
			check[ny][nx] = true;
			black++;
		}
	}
	return make_pair(flag, black); 
}

int count() { 
	memset(check, false, sizeof(check));

	int result = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 2 || check[i][j]) continue;
			auto p = bfs(i, j);
			if (p.first) {
				result += p.second;
			}
		}
	return result;
}

int main() {
	memset(check, false, sizeof(check));
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int max = 0;
	for(int y1 = 0; y1 < n ;y1 ++)
		for (int x1 = 0; x1 < m; x1++) {
			if (board[y1][x1] != 0) continue;
			for (int y2 = 0; y2 < n; y2++)
				for (int x2 = 0; x2 < m; x2++) {
					if (y1 == y2 && x1 == x2 || board[y2][x2] != 0) continue;
					board[y1][x1] = 1;
					board[y2][x2] = 1; 
					int cand = count(); 
					if (cand > max) max = cand;
					board[y1][x1] = 0;
					board[y2][x2] = 0;
				}
		}
	cout << max << endl;
	return 0; 
}