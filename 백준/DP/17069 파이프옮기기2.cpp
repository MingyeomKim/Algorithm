#include <iostream>
#include <cstring>
#include <vector>
using namespace std; 

int n; 
int board[33][33]; 
long long cache[33][33][4]; 

int dy[] = { 0, 1, 1 };
int dx[] = { 1, 1, 0 };

vector<pair<vector<int>, int>> a[3] = {
	{{{0}, 0}, {{0, 2, 1}, 2}},
	{{{2}, 1}, {{0, 2, 1}, 2}},
	{{{0}, 0}, {{2}, 1}, {{0, 2, 1}, 2}}
}; 

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n;
}

long long solve(int y, int x, int dir) {
	if (y == n - 1 && x == n - 1) return 1;
	long long & ret = cache[y][x][dir];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < a[dir].size(); i++) {
		auto p = a[dir][i]; 
		// 이동 가능한지 확인
		bool isOk = true; 
		for (int direction : p.first) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			if (isOut(ny, nx) || board[ny][nx] == 1)
				isOk = false; 
		}
		if (isOk) {
			int direction = p.first.back(); 
			int ny = y + dy[direction], nx = x + dx[direction]; 
			ret += solve(ny, nx, p.second); 
		}
	}
	return ret; 
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j]; 
	cout << solve(0, 1, 0) << endl;
	return 0; 
}