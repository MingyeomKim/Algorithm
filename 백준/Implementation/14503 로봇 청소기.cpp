#include <iostream>
using namespace std; 

int dy[4] = { -1, 0, 1, 0 }; 
int dx[4] = { 0, 1, 0, -1 }; 

int board[51][51]; 

void rotate(int& direction) { // 반시계 방향으로 회전
	if (direction == 0) direction = 3;
	else direction--; 
}

int main() {
	int n, m; cin >> n >> m;
	int r, c, d; cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j]; 

	int ret = 0; 
	while (true) {
		if (board[r][c] == 0) {
			ret++; 
			board[r][c] = 2; 
		}

		bool isOk = false; // 청소할 칸이 있는가? 
		for (int direction = 0; direction < 4; direction++) {
			int ny = r + dy[direction], nx = c + dx[direction]; 
			if (board[ny][nx] == 0) isOk = true; 
		}
		if (isOk) {
			rotate(d);
			if (board[r + dy[d]][c + dx[d]] == 0) 
				r = r + dy[d], c = c + dx[d]; 
		}
		else {
			int back_direction = (d <= 1) ? (d + 2) : (d - 2); 
			int ny = r + dy[back_direction], nx = c + dx[back_direction]; 
			if (board[ny][nx] == 1) break;
			else r = ny, c = nx; 
		}
	}
	cout << ret << endl;
	return 0; 
}