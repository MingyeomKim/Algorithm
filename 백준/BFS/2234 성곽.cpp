#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int board[51][51]; 
int group[51][51];
int group_size[2501]; 
bool canGo[51][51][4];
int n, m;
int max_size = 0; 
int dy[] = { 0, -1, 0, 1 };  // 서 북 동 남 순서
int dx[] = { -1, 0, 1, 0 }; 

int cnt = 1;

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m; 
}

void findGroup(int y, int x) {
	queue<pair<int, int>> q; 
	q.push(make_pair(y, x)); 
	group[y][x] = cnt; 
	int sum = 0; 
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();  sum++; 
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || group[ny][nx] != 0 || !canGo[y][x][direction]) continue; 
			q.push(make_pair(ny, nx)); 
			group[ny][nx] = cnt; 
		}
	}
	group_size[cnt] = sum;
	if (max_size < sum) max_size = sum; 
	cnt++; 
}

int main() {
	cin >> m >> n; 
	memset(canGo, true, sizeof(canGo)); 
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			cin >> board[y][x];

			for (int k = 0; k < 4; k++) {
				if (board[y][x] & (1 << k))
					canGo[y][x][k] = false;
			}
		}

	memset(group, 0, sizeof(group));
	for(int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			if (group[y][x] != 0) continue;
			findGroup(y, x);
		}

	cout << cnt - 1 << endl << max_size << endl;
	int max = 0; 
	for(int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			for (int direction = 0; direction < 4; direction++) {
				int ny = y + dy[direction], nx = x + dx[direction]; 
				if (group[y][x] == group[ny][nx] || isOut(ny, nx)) continue;
				int cand = group_size[group[y][x]] + group_size[group[ny][nx]];
				if (cand > max) max = cand; 
			}
		}
	cout << max << endl;
	return 0; 
}

// 남동북서 (1101 : 남, 동, 서에 벽에 있음)
