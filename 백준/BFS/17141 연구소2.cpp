#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std; 

int board[51][51]; 
int dist[51][51]; 
int n, m;

int dy[] = { -1, 1, 0, 0 }; 
int dx[] = { 0, 0, 1, -1 }; 

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n; 
}

void bfs(int y, int x) {
	queue<pair<int, int>> q; 
	dist[y][x] = 0; 
	q.push(make_pair(y, x)); 
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop(); 
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			if (isOut(ny, nx) || board[ny][nx] == 1) continue;
			if (dist[ny][nx] == -1 || dist[ny][nx] > dist[y][x] + 1) {
				dist[ny][nx] = dist[y][x] + 1; 
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int ret = -1;
void recursive(vector<pair<int, int>> v, vector<pair<int,int>> &selected, int index) {
	if (selected.size() == m) {
		memset(dist, -1, sizeof(dist)); 
		for (auto p : selected)
			bfs(p.first, p.second); 

		bool flag = true; int cand = 0; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// 빈 칸인데 바이러스가 퍼지지 않은 곳이 있다면
				if (board[i][j] != 1 && dist[i][j] == -1)
					flag = false;
				if (cand < dist[i][j]) cand = dist[i][j]; 
			}
		}
		if (flag && (ret == -1 || cand < ret)) ret = cand; 
		return; 
	} else if (index == v.size())
		return; 

	selected.push_back(v[index]); 
	recursive(v, selected, index + 1); 
	selected.pop_back(); 
	recursive(v, selected, index + 1); 
}

int main() {
	cin >> n >> m; 
	vector<pair<int, int>> v; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				v.emplace_back(i, j);
		}

	vector<pair<int, int>> selected; 
	recursive(v, selected, 0); 
	cout << ret << endl;
	return 0; 
}