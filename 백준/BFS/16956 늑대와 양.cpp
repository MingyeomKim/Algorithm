#include <iostream>
#include <queue>
#include <vector>
using namespace std; 

char board[501][501]; 
int r, c; 

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool isOut(int y, int x) {
	return (y < 0 || y >= r || x < 0 || x >= c);
}

int main() {
	cin >> r >> c;
	vector<pair<int, int>> wolfs;
	for (int i = 0; i < r; i++)
		cin >> board[i];
	// S와 W가 붙어있는 경우 제외
	for(int i = 0; i < r; i++)
		for (int j = 0; j < c ; j++) {
			if (board[i][j] == 'S') {
				for (int direction = 0; direction < 4; direction++) {
					int ny = i + dy[direction], nx = j + dx[direction];
					if (isOut(ny, nx)) continue; 
					if (board[ny][nx] == 'W') {
						cout << 0 << endl;
						return 0;
					}
				}
			}
			else if (board[i][j] == 'W') {
				for (int direction = 0; direction < 4; direction++) {
					int ny = i + dy[direction], nx = j + dx[direction];
					if (isOut(ny, nx)) continue; 
					if (board[ny][nx] == 'S') {
						cout << 0 << endl;
						return 0;
					}
				}
			}
		}

	// 모든 빈칸을 D로 채운다. 
	cout << 1 << endl;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			if (board[i][j] == '.')
				cout << 'D';
			else
				cout << board[i][j]; 
		cout << endl;
	}
	return 0;
}
	