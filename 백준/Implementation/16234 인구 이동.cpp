#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;

int board[51][51];
bool check[51][51];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int n, l, r;
bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n;
}

void bfs(int y, int x, vector<pair<int,int>> &group) {
	group.emplace_back(y, x); 

	queue<pair<int,int>> q; 
	q.push(make_pair(y, x)); 
	check[y][x] = true;
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop(); 
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || check[ny][nx]) continue;
			int gap = abs(board[y][x] - board[ny][nx]); 
			if (gap >= l && gap <= r) {
				q.push(make_pair(ny, nx)); 
				check[ny][nx] = true; 
				group.emplace_back(ny, nx); 
			}
		}
	}
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	int ret = 0; 
	while (true) {
		vector<vector<pair<int, int>>> groups;
		memset(check, false, sizeof(check));
		for(int y = 0; y < n; y++)
			for (int x = 0; x < n; x++) {
				if (check[y][x]) continue; 
				vector<pair<int, int>> group; // 현재 시작점과 연합한 나라
				bfs(y, x, group); 
				if (group.size() == 1) continue;  
				groups.push_back(group); 
			}
		if (groups.size() == 0) {
			cout << ret << endl;
			break;
		}

		// 인구 수 갱신
		for (auto group : groups) {
			int sum = 0; 
			for (auto p : group) 
				sum += board[p.first][p.second]; 
			int renew = sum / group.size(); 
			for (auto p : group)
				board[p.first][p.second] = renew; 
		}
		ret++; 
	}
	return 0;
}

