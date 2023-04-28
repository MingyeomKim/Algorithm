#include <iostream>
#include <cstring>
using namespace std; 

char board[9000][9000]; 

// 삼각형의 윗 꼭짓점 (y, x)에서 size (삼각형의 높이) 크기의 삼각형
void solve(int y, int x, int size) {
	if (size == 1) return; 
	if (size == 3) {
		board[y + 1][x] = ' '; 
		return;
	}
	int m = size / 2;
	for (int i = m; i < size; i++){
		int k = (size - i) * 2 - 1; // i번째 줄에서 없애야하는 별의 개수
		for (int j = x - k / 2; j <= x + k / 2; j++)
			board[y + i][j] = ' ';
	}
	solve(y, x, size / 2);
	solve(y + m, x - m, size / 2);
	solve(y + m, x + m, size / 2);
}

int main() {
	memset(board, ' ', sizeof(board));
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x = 2 * i - 1;
		for (int j = n - x / 2; j <= n + x / 2; j++)
			board[i][j] = '*';
	}

	solve(1, n, n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < 2 *  n; j++)
			cout << board[i][j]; 
		cout << endl;
	}
	return 0; 
}