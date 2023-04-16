#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std; 

int n; 
char board[101][101];
bool check[101][101]; 

int dy[4] = { 1, -1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 };

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= n); 
}

bool isSame(int y, int x, int ny, int nx) {
	return board[y][x] == board[ny][nx]; 
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j]; 

	memset(check, false, sizeof(check)); 
	int ret = 0; 
	// 일반인 기준
	for(int i = 0; i < n;i++)
		for (int j = 0; j < n; j++) {
			if (check[i][j] == true) continue; 
			ret++;
			queue<pair<int, int>> q; 
			q.push(make_pair(i, j)); 
			check[i][j] = true; 
			while (!q.empty()) {
				int y, x;
				tie(y, x) = q.front(); q.pop();
				for (int direction = 0; direction < 4; direction++) {
					int ny = y + dy[direction], nx = x + dx[direction]; 
					if (isOut(ny, nx) || check[ny][nx]) continue;
					if (isSame(y, x, ny, nx)) {
						q.push(make_pair(ny, nx)); 
						check[ny][nx] = true; 
					}
				}
			}
		}
	cout << ret << " ";
	
	// 모든 G를 R로 바꿈. 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') board[i][j] = 'R'; 
		}

	memset(check, false, sizeof(check));
	ret = 0;
	// 적록색약 기준
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (check[i][j] == true) continue;
			ret++; 
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			check[i][j] = true;
			while (!q.empty()) {
				int y, x;
				tie(y, x) = q.front(); q.pop();
				for (int direction = 0; direction < 4; direction++) {
					int ny = y + dy[direction], nx = x + dx[direction];
					if (isOut(ny, nx) || check[ny][nx]) continue;
					if (isSame(y, x, ny, nx)) {
						q.push(make_pair(ny, nx));
						check[ny][nx] = true;
					}
				}
			}
		}
	cout << ret << endl;
	return 0;
}