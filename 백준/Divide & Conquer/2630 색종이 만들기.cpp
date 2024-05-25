#include <iostream>
using namespace std;

int board[129][129];

int color[2];

void solve(int sy, int sx, int size) {
	if (size == 1) {
		color[board[sy][sx]]++;
		return;
	}

	bool isSame = true;
	for (int i = sy; i < sy + size; i++) {
		for (int j = sx; j < sx + size; j++) {
			if (board[sy][sx] != board[i][j]) {
				isSame = false;
			}
		}
	}
	if (isSame) {
		color[board[sy][sx]]++;
		return;
	}

	solve(sy, sx, size / 2);
	solve(sy + size / 2, sx, size / 2);
	solve(sy, sx + size / 2, size / 2);
	solve(sy + size / 2, sx + size / 2, size / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	solve(0, 0, n);
	cout << color[0] << endl << color[1] << endl;
	return 0;
}