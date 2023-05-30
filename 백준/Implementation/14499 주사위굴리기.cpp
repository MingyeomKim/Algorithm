#include <iostream>
#include <cstring>
using namespace std; 

int n, m;
int x, y; 

int board[21][21]; 
int dice[4][3]; 

// 동 서 북 남
int dx[5] = { 0,0, 0,-1, 1 }; 
int dy[5] = { 0,1,-1, 0, 0 };

bool isOut(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m); 
}

// dice 배열을 direction 방향으로 돌렸을 때 조건에 맞게 주사위와 바닥면의 숫자를 수정, 윗면의 값을 반환
// 이동한 바닥면의 좌표 : (nx, ny)
int roll(int nx, int ny, int direction) {
	int temp[4][3];  
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			temp[i][j] = dice[i][j]; 

	if (direction == 1) { // 동쪽
		dice[1][2] = temp[1][1]; 
		dice[1][1] = temp[1][0]; 
		dice[1][0] = temp[3][1]; 
		dice[3][1] = temp[1][2]; 
	}
	else if (direction == 2) { // 서쪽
		dice[1][0] = temp[1][1]; 
		dice[1][1] = temp[1][2]; 
		dice[1][2] = temp[3][1]; 
		dice[3][1] = temp[1][0]; 
	}
	else if (direction == 3) { // 북쪽
		dice[0][1] = temp[1][1]; 
		dice[1][1] = temp[2][1]; 
		dice[2][1] = temp[3][1]; 
		dice[3][1] = temp[0][1]; 
	}
	else if (direction == 4) { // 남쪽
		dice[0][1] = temp[3][1]; 
		dice[1][1] = temp[0][1]; 
		dice[2][1] = temp[1][1]; 
		dice[3][1] = temp[2][1]; 
	}

	if (board[nx][ny] == 0) 
		board[nx][ny] = dice[3][1]; 
	else {
		dice[3][1] = board[nx][ny]; 
		board[nx][ny] = 0; 
	}
	return dice[1][1]; 
}

int main() {
	cin >> n >> m >> x >> y;  
	int k; cin >> k; 
	memset(dice, 0, sizeof(dice)); 
	for(int i =0 ;i < n; i ++) // x
		for (int j = 0; j < m; j++) // y
			cin >> board[i][j]; 

	int nx = x, ny = y; 
	for (int i = 0; i < k; i++) {
		int direction; cin >> direction; 
		if (isOut(nx + dx[direction], ny + dy[direction])) continue; 
		nx += dx[direction], ny += dy[direction];

		cout << roll(nx, ny, direction) << endl;
	}
	return 0; 
}