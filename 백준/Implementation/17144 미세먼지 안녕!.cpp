#include <iostream>
#include <cstring>
using namespace std; 

int board[51][51]; 
int temp[51][51]; 
int r, c, t;

int dy[4] = { 1, -1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 };

bool isOut(int y, int x) {
	return y < 0 || y >= r || x < 0 || x >= c; 
}

void diffuse(int y1, int y2) {
	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			temp[y][x] = board[y][x]; 

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (board[y][x] == 0) continue; 
			int cnt = 0; 
			for (int direction = 0; direction < 4; direction++) {
				int ny = y + dy[direction], nx = x + dx[direction]; 
				if (isOut(ny, nx) || board[ny][nx] == -1) continue;
				temp[ny][nx] += board[y][x] / 5; 
				cnt++; 
			}
			temp[y][x] -= (board[y][x] / 5) * cnt; 
		}
	}

	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			board[y][x] = temp[y][x];
}


void clear(int y1, int y2) {
	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++) 
			temp[y][x] = board[y][x];

	// 위쪽 공기청정기
	for (int j = 1; j < c; j++) {
		if (j == 1) temp[y1][j] = 0; 
		else temp[y1][j] = board[y1][j - 1];
	}
	for (int i = y1 - 1; i >= 0; i--) 
		temp[i][c - 1] = board[i + 1][c - 1]; 
	for (int j = c - 2; j >= 0; j--)
		temp[0][j] = board[0][j + 1]; 
	for (int i = 1; i < y1; i++) 
		temp[i][0] = board[i - 1][0];

	// 아래쪽 공기청정기
	for (int j = 1; j < c; j++) { 
		if (j == 1) temp[y2][j] = 0; 
		else temp[y2][j] = board[y2][j - 1];
	}
	for (int i = y2 + 1; i < r; i++)
		temp[i][c - 1] = board[i - 1][c - 1]; 
	for (int j = c - 2; j >= 0; j--)
		temp[r - 1][j] = board[r - 1][j + 1]; 
	for (int i = r - 2; i > y2; i--)
		temp[i][0] = board[i + 1][0]; 

	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			board[y][x] = temp[y][x];
}

int main() {
	
	int y1 = -1;
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (y1 == -1 &&  board[i][j] == -1)
				y1 = i;
		}
	int y2 = y1 + 1; 
	while (t--) {
		// 미세먼지 확산
		diffuse(y1, y2); 
		
		// 공기청정기 작동
		clear(y1, y2); 
	}
	int ret = 0; 
	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			if (board[y][x] != -1)
				ret += board[y][x]; 
	cout << ret << endl;

	return 0; 
}