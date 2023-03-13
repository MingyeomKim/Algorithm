#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

char board[MAX][MAX] = { 0, };
char blackChess[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};
char whiteChess[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};


int cntDifferent(char board[MAX][MAX], char chess[8][8], int p, int q) {
	int cnt = 0;
	for (int i = p; i < p + 8; i++) {
		for (int j = q; j < q + 8; j++) {
			if (board[i][j] != chess[i - p][j - q]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int cntSquare(int p, int q) {
	int cnt = 0;
	// (p, q)가 검은색인 경우
	int a = cntDifferent(board, blackChess, p, q);

	// (p, q)가 흰색인 경우
	int b = cntDifferent(board, whiteChess, p, q);

	return a < b ? a : b; // 더 작은 값을 반환
}

int findMin(int ans[MAX][MAX], int n, int m) {
	int min = ans[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans[i][j] < min) {
				min = ans[i][j];
			}
		}
	}
	return min;
}

int main() {
	int m, n; // 보드 크기
	cin >> n >> m; // 행, 열

	for (int i = 0; i < n; i++) { // 행의 개수
		for (int j = 0; j < m; j++) { // 열의 개수
			cin >> board[i][j];
		}
	}

	int answer[MAX][MAX] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer[i][j] = cntSquare(i, j);
		}
	}

	cout << findMin(answer, n, m) << endl;

	return 0;
}

