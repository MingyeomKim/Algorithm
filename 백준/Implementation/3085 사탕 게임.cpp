#include <iostream>
#include <cstring>
using namespace std;

char board[51][51];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int count(int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		char x = board[i][0];
		int count = 1;
		for (int j = 0; j < n; j++) {
			if (board[i][j] != x) {
				x = board[i][j];
				if (count > max) {
					max = count;
				}
				count = 1;
			}
			else {
				count++;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		char x = board[0][j];
		int count = 1;
		for (int i = 0; i < n; i++) {
			if (board[i][j] != x) {
				x = board[i][j];
				if (count > max) {
					max = count;
				}
				count = 1;
			}
			else {
				count++;
			}
		}
	}
	return max;
}

bool isOut(int y, int x, int n) {
	return y < 0 || y >= n || x < 0 || x >= n;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			board[i][j] = s[j];
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char here = board[i][j];
			for (int k = 0; k < 4; k++) {
				if (isOut(i + dy[k], j + dx[k], n)) continue;
				char next = board[i + dy[k]][j + dx[k]];
				board[i][j] = next;
				board[i + dy[k]][j + dx[k]] = here;
				int cand = count(n);
				if (cand > ret) ret = cand;
				board[i][j] = here;
				board[i + dy[k]][j + dx[k]] = next;
			}
		}
	}
	cout << ret << endl;
	return 0;
}