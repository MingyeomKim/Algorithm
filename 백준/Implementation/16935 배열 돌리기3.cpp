#include <iostream> 
#include <algorithm>
using namespace std;

int board[101][101];
int temp[101][101];
int n, m;

void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = temp[i][j];
		}
	}
}

void flipUpsideDown() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[n - i - 1][j] = board[i][j];
		}
	}
}

void flipLeftRight() {
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			temp[i][m - j - 1] = board[i][j];
		}
	}
}

void clockwise() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[j][n - i - 1] = board[i][j];
		}
	}
	swap(n, m);
}

void counterClockwise() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[m - j - 1][i] = board[i][j];
		}
	}
	swap(n, m);
}

void quarterClockwise() {
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			temp[i][j + m / 2] = board[i][j];
		}
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = m / 2; j < m; j++) {
			temp[i + n / 2][j] = board[i][j];
		}
	}
	for (int i = n / 2; i < n; i++) {
		for (int j = m / 2; j < m; j++) {
			temp[i][j - m / 2] = board[i][j];
		}
	}
	for (int i = n / 2; i < n; i++) {
		for (int j = 0; j < m / 2; j++) {
			temp[i - n / 2][j] = board[i][j];
		}
	}
}

void quarterCounterClockwise() {
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			temp[i + n / 2][j] = board[i][j];
		}
	}
	for (int i = n / 2; i < n; i++) {
		for (int j = 0; j < m / 2; j++) {
			temp[i][j + m / 2] = board[i][j];
		}
	}
	for (int i = n / 2; i < n; i++) {
		for (int j = m / 2; j < m; j++) {
			temp[i - n / 2][j] = board[i][j];
		}
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = m / 2; j < m; j++) {
			temp[i][j - m / 2] = board[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int r; cin >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		int num; cin >> num;
		switch (num) {
		case 1:
			flipUpsideDown();
			break;
		case 2:
			flipLeftRight();
			break;
		case 3:
			clockwise();
			break;
		case 4:
			counterClockwise();
			break;
		case 5:
			quarterClockwise();
			break;
		case 6:
			quarterCounterClockwise();
		}
		copy();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}