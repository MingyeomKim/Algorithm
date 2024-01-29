#include <iostream>
#include <cstring>
using namespace std; 

char board[51][51];
int dy[4] = { -1, 1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 };

int n;
bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n;
}

void swap(int y, int x, int ny, int nx) {
	int temp = board[y][x]; 
	board[y][x] = board[ny][nx];
	board[ny][nx] = temp; 
}

int count() {
	int max = 0;
	for (int y = 0; y < n; y++) {
		char now = board[y][0];
		int cnt = 1;
		for (int x = 1; x < n; x++) {
			if (now != board[y][x]) {
				if (max < cnt) max = cnt;
				cnt = 1;
				now = board[y][x];
			}
			else {
				cnt++;
			}
		}
		if (max < cnt) max = cnt;
	}
	for (int x = 0; x < n; x++) {
		char now = board[0][x]; 
		int cnt = 1; 
		for (int y = 1; y < n; y++) {
			if (now != board[y][x]) {
				if (max < cnt) max = cnt; 
				cnt = 1; 
				now = board[y][x]; 
			}
			else {
				cnt++;
			}
		}
		if (max < cnt) max = cnt;
	}
	return max;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			board[i][j] = s[j];
		}
	}

	int ret = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k], nx = x + dx[k];
				if(isOut(ny, nx)) continue;
				swap(y, x, ny, nx);
				int cand = count();
				if (ret < cand) ret = cand;
				swap(y, x, ny, nx); 
			}
		}
	}
	cout << ret << endl;
	return 0;
}