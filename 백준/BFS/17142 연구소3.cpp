#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int board[51][51];
int dist[51][51];
int n, m;
vector<pair<int, int>> v;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int ret = -1;

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n;
}

void bfs() {
	memset(dist, -1, sizeof(dist)); 
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] == 3) { // 활성 상태인 바이러스
				q.push(make_pair(i, j)); 
				dist[i][j] = 0;
			}
	
	while (!q.empty()) {
		int y, x;  tie(y, x) = q.front(); q.pop();
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || board[ny][nx] == 1 || dist[ny][nx] != -1) continue;
			dist[ny][nx] = dist[y][x] + 1; 
			q.push(make_pair(ny, nx)); 
		}
	}

	int cand = 0; 
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				if (dist[i][j] == -1) return; 
				if (cand < dist[i][j]) cand = dist[i][j]; 
			}
		}
	if (ret == -1 || ret > cand) ret = cand;
}

void recursive(int cnt, int index) {
	if (index == v.size()) {
		if(cnt == m) bfs(); 
	}
	else {
		int y, x; tie(y, x) = v[index]; 
		board[y][x] = 3; 
		recursive(cnt + 1, index + 1); 
		board[y][x] = 2; 
		recursive(cnt, index + 1); 
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				v.emplace_back(i, j);
		}

	recursive(0, 0);
	cout << ret << endl;
	return 0;
}