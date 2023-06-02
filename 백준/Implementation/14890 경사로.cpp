#include <iostream>
#include <cstring>
using namespace std; 

int board[101][101]; 
int n, length;
int temp[101][101];

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n; 
}

int main() {
	memset(temp, 0, sizeof(temp)); 
	cin >> n >> length; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j]; 

	int ret = 0; 
	// 가로로 된 길
	for (int i = 0; i < n; i++) {
		pair<int, int> same = {board[i][0], 0};
		bool flag = true; // 아래 두 방향 중 하나만 되어도 OK
		for (int j = 0; j < n; j++) { // --> 
			if (board[i][j] == same.first) {
				same.second++;
			}
			else if (board[i][j] ==  same.first + 1) {
				if (same.second >= length) {
					for (int k = 1; k <= length; k++) {
						if (temp[i][j - k] == 1) {
							flag = false; 
							break;
						}
					}
					if (!flag)  break; 
					same.first = board[i][j]; 
					same.second = 1; 
					// for (int k = 1; k <= length; k++) 
					// 	temp[i][j - k] = 1; // 경사로 표시
				}
				else {
					flag = false;
					break;
				}
			}
			else if (board[i][j] + 1 == same.first) { 
				for (int k = 1; k < length; k++) {
					if (isOut(i, j + k)) {
						flag = false; 
						break;
					}
					if (board[i][j + k] != board[i][j]) {
						flag = false; 
						break;
					}
					temp[i][j] = 1; 
					for (int k = 1; k < length; k++) {
						temp[i][j + k] = 1; 
					}
				}
				j = j + length - 1; 
				if (!flag) break;

				same.first = board[i][j]; 
				same.second = length; 
				if (j != n - 1 && board[i][j + 1] > same.first) {
					flag = false;
					break;
				}
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag) {
			// cout << "가로로 된 길 : " << i << endl;
			ret++;
		}
	}
	memset(temp, 0, sizeof(temp)); 
	// 세로로 된 길 
	for (int j = 0; j < n; j++) {
		pair<int, int> same = { board[0][j], 0 }; 
		bool flag = true; 
		for (int i = 0; i < n; i++) { // 위에서 아래
			if (board[i][j] == same.first)
				same.second++; 
			else if (board[i][j] == same.first + 1) {
				if (same.second >= length) {
					for (int k = 1; k <= length; k++) {
						if (temp[i - k][j] == 1) {
							flag = false;
							break;
						}
					}
					if (!flag)  break;
					same.first = board[i][j];
					same.second = 1; 
				}
				else {
					flag = false; 
					break;
				}
			}
			else if (board[i][j] + 1 == same.first) {
				for (int k = 1; k < length; k++) {
					if (isOut(i + k, j)) {
						flag = false;
						break;
					}
					if (board[i + k][j] != board[i][j]) {
						flag = false;
						break;
					}
				}
				temp[i][j] = 1;
				for (int k = 1; k < length; k++) {
					temp[i + k][j] = 1;
				}
				i = i + length - 1; 
				if (!flag) break;
				same.first = board[i][j];
				same.second = length;
				if (i != n - 1 && board[i + 1][j] > same.first) {
					flag = false;
					break;
				}
			}
			else {
				flag = false; 
				break;
			}
		}
		if (flag) {
			// cout << "세로로 된 길 : " << j << endl;
			ret++;
		}
	}

	cout << ret << endl;
	return 0; 
}