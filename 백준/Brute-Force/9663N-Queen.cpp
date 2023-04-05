#include <iostream>
#include <vector>
using namespace std; 

int n; // Queen의 개수
// int board[16][16] = {0, };

bool check_col[15]; 
bool check_dig[40]; 
bool check_dig2[40]; 

// 이 row와 col에 queen이 존재하는 지 검사
bool check(int row, int col) {
	if (check_col[col])
		return false;
	if (check_dig[row + col])
		return false; 
	if (check_dig2[row - col + n])
		return false;
	return true; 
}

int calc(int row) {
	if (row == n) return 1; 
	int cnt = 0; 
	for (int col = 0; col < n; col++) {
		if (check(row, col)) {
			// board[row][col] = true;
			check_col[col] = true; 
			check_dig[row + col] = true;
			check_dig2[row - col + n] = true; 

			cnt += calc(row + 1);
			
			// board[row][col] = false;
			check_col[col] = false;
			check_dig[row + col] = false;
			check_dig2[row - col + n] = false;
		}
	}
	return cnt; 
}

int main() {
	cin >> n; 
	cout << calc(0) << endl;	
	return 0; 
}