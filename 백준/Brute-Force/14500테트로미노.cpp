#include <iostream>
using namespace std; 

int n, m; 
int dx[4] = { 0, 0, 1, -1 }; 
int dy[4] = { 1, -1, 0, 0 }; 
int visited[501][501] = { 0, }; 
int board[501][501]; 

int ret = 0; 
void calc(int y, int x, int sum, int cnt){
	if (cnt == 4){
		if (ret < sum) ret = sum; 
		return;
	}

	if (y < 0 || y >= n || x < 0 || x >= m) return;
	if (visited[y][x]) return;

	visited[y][x] = true; 
	for (int direction = 0; direction < 4; direction++) {
		calc(y + dy[direction], x + dx[direction], sum + board[y][x], cnt + 1); 
	}
	visited[y][x] = false;
}

int main() {
	cin >> n >> m; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j]; 
	// shape5 직접 처리
	/*   |
	* -------- 이 형태인 경우
	*/
	for (int i = 0; i < n - 1; i++) 
		for (int j = 1; j < m - 1; j++) {
			int sum = board[i][j] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1]; 
			if (ret < sum) ret = sum;
		}

	/*  |
	*   |---- 이 형태인 경우
	    |
	*/
	for(int i = 1; i < n-1; i++)
		for (int j = 1; j < m; j++) {
			int sum = board[i][j] + board[i - 1][j - 1] + board[i][j - 1] + board[i + 1][j - 1]; 
			if (ret < sum) ret = sum;
		}

	/*
	* ----------- 인 경우
	*      |
	*/
	for(int i = 1; i < n; i++)
		for (int j = 1; j < m - 1; j++) {
			int sum = board[i][j] + board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1]; 
			if (ret < sum) ret = sum;
		}

	/*	 |
	* ---|
	*	 | 인 경우
	*/ 
	for(int i = 1; i < n-1; i++)
		for (int j = 0; j < m - 1; j++) {
			int sum = board[i][j] + board[i - 1][j + 1] + board[i][j + 1] + board[i + 1][j + 1]; 
			if (ret < sum) ret = sum; 
		}
	for(int i = 0; i< n;i++)
		for(int j = 0; j< m;j++)
			calc(i, j, 0, 0); 

	cout << ret << endl;
	return 0; 
}