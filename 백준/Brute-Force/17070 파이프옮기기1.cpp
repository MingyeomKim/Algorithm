#include <iostream>
#include <vector>
using namespace std; 

int board[17][17]; 
int n;

int dy[] = { 0, 1, 1 }; 
int dx[] = { 1, 1, 0 }; 

// 파이프의 오른쪽 끝이 (y, x)에 있을 때, 빈칸이어야 하는 곳
vector<pair<vector<int>,int> > a[3] = { 
	{ {{0}, 0}, {{0, 2, 1}, 2}}, // 가로 , 대각선
	{ {{2}, 1}, {{0, 2, 1}, 2}}, // 세로, 대각선
	{ {{0}, 0}, {{2}, 1}, {{0, 2, 1}, 2} }  //가로, 세로, 대각선
};  

int ret = 0; 

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n; 
}

// flag : 0 (가로), 1 (세로), 2 (대각선)
void solve(int y, int x, int flag) {
	if (y == n - 1 && x == n - 1) {
		ret++; 
		return; 
	}
	if (isOut(y, x)) return;
	for (int i = 0; i < a[flag].size(); i++) {
		bool isOk = true; 
		for (int direction : a[flag][i].first) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || board[ny][nx] == 1)
				isOk = false; 
		}
		if (isOk) {
			int direction = a[flag][i].first.back();
			int ny = y + dy[direction], nx = x + dx[direction]; 
			solve(ny, nx, a[flag][i].second);
		}
	}
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	solve(0, 1, 0); 
	cout << ret << endl;
	return 0;
}
