#include <iostream>
#include <vector>
using namespace std;

int board[11][11]; 
int ret = 987654321;
int paper[6] = { 0, };

bool isOut(int y, int x) {
	return y < 0 || y > 10 || x < 0 || x > 10;
}

bool possible(int r, int c, int k) {
	for (int i = r; i < r + k; i++) {
		for (int j = c; j < c + k; j++) {
			if (board[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void solve(int r, int c, int cnt) {
	while (board[r][c] == 0) {
		c++;
		if (c >= 10) {
			r++; 
			if (r >= 10) {
				if (ret == -1 || ret > cnt) {
					ret = cnt;
				}
				return;
			}
			c = 0;
		}
	}

	if (cnt >= ret) {
		return;
	}

	for (int k = 5; k >= 1; k--) {
		if (isOut(r + k , c + k )) {
			continue;
		}
		if (paper[k] >= 5) {
			continue;
		}

		if (possible(r, c, k)) {
			paper[k]++;
			for (int i = r; i < r + k; i++) {
				for (int j = c; j < c + k; j++) {
					board[i][j] = 0;
				}
			}
			solve(r, c, cnt + 1);
			paper[k]--; 
			for (int i = r; i < r + k; i++) {
				for (int j = c; j < c + k; j++) {
					board[i][j] = 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
		}
	}

	solve(0, 0, 0); 
	if (ret == 987654321) {
		ret = -1; 
	}
	cout << ret << endl;
	return 0;
}