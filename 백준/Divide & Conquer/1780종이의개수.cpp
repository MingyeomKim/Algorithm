#include <iostream>
using namespace std; 

int n;
int board[2188][2188]; 

int zero = 0, one = 0, mone = 0; 

bool check(int y, int x, int k) {
	int value = board[y][x];
	for(int i = y; i < y + k; i++)
		for (int j = x; j < x + k; j++) {
			if (board[i][j] != value)
				return false; 
		}
	return true; 
}

// (y, x)에서 시작해서 k만큼의 크기의 행렬을 검사하는 함수
void solve(int y, int x, int k) {
	if (k == 1 || check(y, x, k)) {
		if (board[y][x] == 0) zero++;
		else if (board[y][x] == 1) one++;
		else mone++; 
		return; 
	}
	int interval = k / 3; 
	for (int i = y; i <= y + k - interval; i += interval) {
		for (int j = x; j <= x + k - interval; j += interval) {
			// cout << "i : " << i << " j : " << j << " interval : " << interval << endl;
			solve(i, j, interval);
		}
	}
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j]; 
	solve(0, 0, n); 
	cout << mone << endl << zero << endl << one << endl;
	return 0; 
}