#include <iostream>
#include <queue>
#include <tuple>
using namespace std; 

char board[8][8]; 
int dy[9] = { 0, -1, -1, -1, 0, 0, 1, 1, 1 }; 
int dx[9] = { 0, -1, 0, 1, -1, 1, -1, 0, 1 }; 

bool check[9][9][9];

bool isOut(int y, int x) {
	return (y < 0 || y >= 8 || x < 0 || x >= 8); 
}

int main() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> board[i][j]; 
	queue<tuple<int, int, int>> q; 
	q.push(make_tuple(7, 0, 0));  // Ω√¿€¡°
	check[7][0][0] = true;
	while (!q.empty()) {
		int y, x, t; 
		tie(y, x, t) = q.front(); q.pop(); 
		
		for (int direction = 0; direction < 9; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			int nt = min(t + 1, 8); 
			if (isOut(ny, nx)) continue;
			if (ny - t >= 0 && board[ny - t][nx] == '#') continue; 
			if (ny - t - 1 >= 0 && board[ny - t - 1][nx] == '#') continue; 
			if (check[ny][nx][nt] == false) {
				check[ny][nx][nt] = true; 
				q.push(make_tuple(ny, nx, nt)); 
			}
		}
	}	

	for (int i = 0; i <= 8; i++) {
		if (check[0][7][i] != 0) {
			cout << 1 << endl;
			return 0; 
		}
	}
	cout << 0 << endl;
	return 0; 
}